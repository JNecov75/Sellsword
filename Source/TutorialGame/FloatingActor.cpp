// Fill out your copyright notice in the Description page of Project Settings.

#include "TutorialGame.h"
#include "FloatingActor.h"
#include "RandomStream.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector NewLocation = GetActorLocation();
	fRandomStream.GenerateNewSeed();
	float fRange = fRandomStream.FRandRange(0.6, 1.4);
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * fRange) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight *sinMagnitude;	//Scale our height by a factor of sinMagnitude
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}
