// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_PlayAnimationMontage.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTT_PlayAnimationMontage : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTT_PlayAnimationMontage();

	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> MyOwnerComp;

	void OnAnimMontageTimerDone();
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(Category = Node, EditAnywhere)
	UAnimMontage* AMToPlay;

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerHandle;
	
};
