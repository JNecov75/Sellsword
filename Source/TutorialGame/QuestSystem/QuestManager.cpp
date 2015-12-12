#include "UnnamedRPG.h"
#include "QuestManager.h"
#include "../GameEventSystem/GameEventManager.h"

static bool ListAllBlueprintsInPath(FName Path, TArray<UClass*>& Result, UClass* Class)
{
	auto Library = UObjectLibrary::CreateLibrary(Class, true, GIsEditor);
	Library->LoadBlueprintAssetDataFromPath(Path.ToString());

	TArray<FAssetData> Assets;
	Library->GetAssetDataList(Assets);

	for (auto& Asset : Assets)
	{
		UBlueprint* bp = Cast<UBlueprint>(Asset.GetAsset());
		if (bp)
		{
			auto gc = bp->GeneratedClass;
			if (gc)
			{
				Result.Add(gc);
			}
		}
		else
		{
			auto GeneratedClassName = (Asset.AssetName.ToString() + "_C");

			UClass* Clazz = FindObject<UClass>(Asset.GetPackage(), *GeneratedClassName);
			if (Clazz)
			{
				Result.Add(Clazz);
			}
			else
			{
				UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(Asset.GetPackage(), *GeneratedClassName);
				if (RenamedClassRedirector)
				{
					Result.Add(CastChecked<UClass>(RenamedClassRedirector->DestinationObject));
				}
			}

		}
	}

	return true;
}
//============================================================
CQuestManager::CQuestManager(CGameEventManager* inGameEventManager) : _ActiveQuest(nullptr), _GameEventManager(inGameEventManager)
{
	_GameEventManager->Register(this, TEXT("PlayerBeginOverlap"));
	_GameEventManager->Register(this, TEXT("PlayerEndOverlap"));
}

CQuestManager::~CQuestManager()
{
	//for (size_t i = 0, count = _QuestsList.size(); i < count; i++)
	//{
	//	delete _QuestsList[i];
	//}
	//_QuestsList.clear();
}

void CQuestManager::OnGameEvent(CGameEvent& event)
{
	if (_ActiveQuest)
	{
		_ActiveQuest->RecieveGameEvent(event);
		if (_ActiveQuest->GetStatus() == EQuestStatus::Finished)
		{
			// quest finished
			_ActiveQuest = nullptr;
		}
		return;
	}

	/*else*/
	// no active quest, so try to trigger one
	for (size_t i = 0, count = _QuestsList.size(); i < count; i++)
	{
		if (_QuestsList[i]->Accept(event))
		{
			// quest started
			_ActiveQuest = _QuestsList[i];
			return;
		}
	}
}

void CQuestManager::GrabAllQuests()
{
	FName directoryToSearch = TEXT("/Game/Quests");
	UClass* Class = UQuest::StaticClass();
	TArray<UClass*> Result;
	ListAllBlueprintsInPath(directoryToSearch, Result, Class);
	check(Result.Num() != 0 && "No quests!");
	for (UClass* QuestClass : Result)
	{
		UQuest* QuestObject = ConstructObject<UQuest>(QuestClass);
		check(QuestObject);
		_QuestsList.push_back(QuestObject);
		QuestObject->AddToRoot();
	}
}

