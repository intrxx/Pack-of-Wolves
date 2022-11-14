// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindRandomLocation.generated.h"

class UEnvQuery;
struct FEnvQueryResult;
/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API UBTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_FindRandomLocation();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual FString GetStaticDescription() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "AI Beahviour", meta = (AllowPrivateAccess = true))
	float Radius = 500.f;

	UPROPERTY()
	FVector NewLocation;
};
