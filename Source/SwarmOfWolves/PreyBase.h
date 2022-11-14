// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PreyBase.generated.h"

class APreyBase;

USTRUCT()
struct FPreyData
{
	GENERATED_BODY()

	//Saving PreyData
	UPROPERTY()
	FTransform Transform;

	TSubclassOf<APreyBase> PreyClass;
};

UCLASS()
class SWARMOFWOLVES_API APreyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APreyBase();

	UPROPERTY(BlueprintReadOnly)
	FTransform OriginTransform;

	UPROPERTY()
	FPreyData PreyData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

private:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float CurrentHealth;
	

};
