// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_HowlerLocation.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTService_HowlerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_HowlerLocation();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
