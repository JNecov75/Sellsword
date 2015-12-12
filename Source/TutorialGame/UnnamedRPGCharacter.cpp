// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "UnnamedRPG.h"
#include "UnnamedRPGCharacter.h"
#include "UnnamedRPGGameInstance.h"
#include "GameEventSystem/GameEvent.h"
#include "GameEventSystem/GameEventManager.h"

//==================================================================================
AUnnamedRPGCharacter::AUnnamedRPGCharacter() : _GameEventManager(nullptr)
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->bGenerateOverlapEvents = true;
	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AUnnamedRPGCharacter::OnOverlapBegin);
	//GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AUnnamedRPGCharacter::OnOverlapEnd);


	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Overlap event
	OnActorBeginOverlap.AddDynamic(this, &AUnnamedRPGCharacter::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AUnnamedRPGCharacter::OnEndOverlap);
}

//==================================================================================
void AUnnamedRPGCharacter::OnBeginOverlap(class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		// send event
		CGameEvent event(TEXT("PlayerBeginOverlap"), (void*)OtherActor);
		_GameEventManager->SendEvent(event);
	}
}

//==================================================================================
void AUnnamedRPGCharacter::OnEndOverlap(class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		// send event
		CGameEvent event(TEXT("PlayerEndOverlap"), (void*)OtherActor);
		_GameEventManager->SendEvent(event);
	}
}

//==================================================================================
void AUnnamedRPGCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!_GameEventManager)
	{
		// Get the event manager for faster and more convenient access
		UUnnamedRPGGameInstance* pGameInstance = Cast<UUnnamedRPGGameInstance>(GetGameInstance());
		check(pGameInstance);
		_GameEventManager = pGameInstance->GetGameEventManager();
		check(_GameEventManager);
	}
}

//==================================================================================
