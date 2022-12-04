// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FIndWeakestDeer.h"
#include "EngineUtils.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_FIndWeakestDeer::UBTTask_FIndWeakestDeer()
{
	NodeName = TEXT("Find the weakest Deer");
}

EBTNodeResult::Type UBTTask_FIndWeakestDeer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ADeerAIController* AIController = Cast<ADeerAIController>(OwnerComp.GetAIOwner());
	TArray<APreyBase*> PotentialWeakestPrey;
	
	for(TActorIterator<APreyBase> ActorITr(GetWorld()); ActorITr; ++ActorITr)
	{
		PotentialWeakestPrey.Push(*ActorITr);
	}

	TempWeakestDeer = PotentialWeakestPrey.Last();
	for(APreyBase* Deer : PotentialWeakestPrey)
	{
		
		if(Deer->LifeStrength < TempWeakestDeer->LifeStrength)
		{
			TempWeakestDeer = Deer;
		}
	}
	
	TempWeakestDeer->bIsWeakest = true;
	AIController->GetBlackboardComponent()->SetValueAsBool(BlackboardKey.SelectedKeyName, true);
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
