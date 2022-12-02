// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_PrepareForScouting.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTTask_PrepareForScouting : public UBTTask_MoveTo
{
	GENERATED_BODY()

	UBTTask_PrepareForScouting();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	

protected:

	// Iterator for adding different locations for scout preparation
	int8 Iterator;
	FVector ScoutBeginningLocation;
	
};
