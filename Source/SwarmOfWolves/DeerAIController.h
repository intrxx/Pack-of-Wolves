// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DeerAIController.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API ADeerAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ADeerAIController();

	FGenericTeamId TeamId = FGenericTeamId(4);
	virtual FGenericTeamId GetGenericTeamId() const override;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* DeerBehaviorTree;
		
	
};
