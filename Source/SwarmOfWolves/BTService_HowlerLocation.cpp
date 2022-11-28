// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_HowlerLocation.h"

#include "WolfAIController.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_HowlerLocation::UBTService_HowlerLocation()
{
	NodeName = TEXT("Set Howler Location");
}

void UBTService_HowlerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AWolfAIController* WAC = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	if(WAC)
	{
		APawn* Wolf = Cast<AWolfBase>(WAC->GetOwner());
		if(Wolf)
		{
			//TODO if statment to check if the wolf has howled
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Wolf->GetActorLocation());
		}
	}
}

