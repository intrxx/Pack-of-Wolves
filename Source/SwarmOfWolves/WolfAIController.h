// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WolfAIController.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API AWolfAIController : public AAIController
{
	GENERATED_BODY()

public:
	AWolfAIController();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* WolfBehaviorTree;

protected:
	virtual void BeginPlay() override;
	

	
	
};
