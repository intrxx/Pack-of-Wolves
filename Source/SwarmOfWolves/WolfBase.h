// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "WolfBase.generated.h"

UCLASS()
class SWARMOFWOLVES_API AWolfBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWolfBase();

	UPROPERTY(VisibleAnywhere)
	float ScoutingStrength = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
