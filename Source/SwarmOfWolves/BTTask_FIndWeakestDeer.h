// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PreyBase.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FIndWeakestDeer.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTTask_FIndWeakestDeer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTTask_FIndWeakestDeer();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:

	UPROPERTY()
	APreyBase* TempWeakestDeer;
};
