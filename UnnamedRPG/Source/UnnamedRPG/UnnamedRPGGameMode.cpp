// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "UnnamedRPG.h"
#include "UnnamedRPGGameMode.h"
#include "UnnamedRPGPlayerController.h"
#include "UnnamedRPGCharacter.h"

AUnnamedRPGGameMode::AUnnamedRPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUnnamedRPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}