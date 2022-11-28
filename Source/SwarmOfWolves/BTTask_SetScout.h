// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WolfBase.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SetScout.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTTask_SetScout : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTTask_SetScout();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:
	UPROPERTY()
	AWolfBase* TempScout;

	FGameplayTag Scout;
};
