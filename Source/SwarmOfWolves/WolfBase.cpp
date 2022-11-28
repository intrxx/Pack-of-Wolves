// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfBase.h"

// Sets default values
AWolfBase::AWolfBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWolfBase::BeginPlay()
{
	Super::BeginPlay();

	ScoutingStrength = FMath::Rand();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("Scouting Strength: %f"), ScoutingStrength));
}

// Called every frame
void AWolfBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AWolfBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}






