// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackThePrey.h"

#include "PreyBase.h"
#include "WolfAIController.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AttackThePrey::UBTTask_AttackThePrey()
{
	NodeName = TEXT("Get Prey Location");	
}

EBTNodeResult::Type UBTTask_AttackThePrey::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AWolfAIController* AIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	APreyBase* Prey = Cast<APreyBase>(AIController->GetBlackboardComponent()->GetValueAsObject("Prey"));

	AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Prey->GetActorLocation());
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}


