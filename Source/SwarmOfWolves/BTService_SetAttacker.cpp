// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetAttacker.h"

#include "WolfAIController.h"
#include "EngineUtils.h"
#include "PreyBase.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_SetAttacker::UBTService_SetAttacker()
{
	NodeName = TEXT("Set the Attacker");
}

void UBTService_SetAttacker::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AWolfAIController* AIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	
	bool isAttacking = AIController->GetBlackboardComponent()->GetValueAsBool("bAttacking");
	AWolfBase* CurrentAttacker = Cast<AWolfBase>(AIController->GetBlackboardComponent()->GetValueAsObject("Attacker"));

	if(isAttacking == true)
	{
		AIController->GetBlackboardComponent()->SetValueAsObject("Attacker", CurrentAttacker);
	}
	else
	{
		do
		{
			TArray<AWolfBase*> PotentialScouts;
	
			for(TActorIterator<AWolfBase> ActorITr(GetWorld()); ActorITr; ++ActorITr)
			{
				PotentialScouts.Push(*ActorITr);
			}
	
			float RandNumber = FMath::RandRange(0,3);
			TempAttacker = PotentialScouts[RandNumber];
		}
		while (TempAttacker != CurrentAttacker);

		AIController->GetBlackboardComponent()->SetValueAsBool("bAttacking", true);
		AIController->GetBlackboardComponent()->SetValueAsObject("Attacker", TempAttacker);
	}
	APreyBase* Prey = Cast<APreyBase>(AIController->GetBlackboardComponent()->GetValueAsObject("Prey"));
	AIController->GetBlackboardComponent()->SetValueAsVector("PreyLocation",Prey->GetActorLocation());
}

