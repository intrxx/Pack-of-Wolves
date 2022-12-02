// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PrepareForScouting.h"
#include "WolfAIController.h"
#include "WolfBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_PrepareForScouting::UBTTask_PrepareForScouting()
{
	NodeName = TEXT("Prepare for Scouting");
}

EBTNodeResult::Type UBTTask_PrepareForScouting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AWolfAIController* AIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	
	AIController->GetBlackboardComponent()->GetLocationFromEntry("ScoutBeginningLocation",ScoutBeginningLocation);
	Iterator = AIController->GetBlackboardComponent()->GetValueAsInt("ScoutingPreparationIterator");
	
	if(Iterator == 0)
	{
		ScoutBeginningLocation.Y += 700;
		AIController->GetBlackboardComponent()->SetValueAsInt("ScoutingPreparationIterator", 1);
	}
	else if(Iterator == 1)
	{
		ScoutBeginningLocation.Y -= 700;
		AIController->GetBlackboardComponent()->SetValueAsInt("ScoutingPreparationIterator", 2);
	}
	else if(Iterator == 2)
	{
		ScoutBeginningLocation.X -= 700;
		AIController->GetBlackboardComponent()->SetValueAsInt("ScoutingPreparationIterator", 3);
	}
	else if(Iterator == 3)
	{
		ScoutBeginningLocation.X += 700;
		AIController->GetBlackboardComponent()->SetValueAsBool("bPreparedForScouting", true);
	}
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Move to Location: %s"), *ScoutBeginningLocation.ToString()));
	
	AIController->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), ScoutBeginningLocation);
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}