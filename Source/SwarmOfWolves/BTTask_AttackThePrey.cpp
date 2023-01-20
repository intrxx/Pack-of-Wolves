// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackThePrey.h"
#include "EngineUtils.h"
#include "PreyBase.h"
#include "WolfAIController.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AttackThePrey::UBTTask_AttackThePrey()
{
	NodeName = TEXT("Stop the bahavior tree");	
}

EBTNodeResult::Type UBTTask_AttackThePrey::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AWolfAIController* AIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	
	AIController->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}


