// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WolfBase.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_AttackThePrey.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTTask_AttackThePrey : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_AttackThePrey();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	AWolfBase* TempAttacker;
};
