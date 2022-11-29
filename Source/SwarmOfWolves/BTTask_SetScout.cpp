// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetScout.h"

#include "WolfAIController.h"
#include "EngineUtils.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_SetScout::UBTTask_SetScout()
{
	NodeName = TEXT("Set the Scout Wolf");
}

EBTNodeResult::Type UBTTask_SetScout::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AWolfAIController* AIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	TArray<AWolfBase*> PotentialScouts;
	
	for(TActorIterator<AWolfBase> ActorITr(GetWorld()); ActorITr; ++ActorITr)
	{
		PotentialScouts.Push(*ActorITr);
	}

	TempScout = PotentialScouts.Last();
	for(AWolfBase* Wolf : PotentialScouts)
	{
		if(Wolf->ScoutingStrength > TempScout->ScoutingStrength)
		{
			TempScout = Wolf;
		}
	}
	
	AIController->GetBlackboardComponent()->SetValueAsObject(BlackboardKey.SelectedKeyName, TempScout);
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
