// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WolfBase.h"
#include "PlayableWolf.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API APlayableWolf : public AWolfBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayableWolf();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void MoveForward(float AxisValue);
	void MoveSide(float AxisValue);

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

};
