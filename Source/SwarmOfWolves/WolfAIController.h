// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "WolfAIController.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API AWolfAIController : public AAIController
{
	GENERATED_BODY()

public:
	AWolfAIController();
	
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UFUNCTION()
	void OnTargetPerceptionUpdate_Delegate(AActor* Actor, FAIStimulus Stimulus);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent = nullptr;
	TObjectPtr<class UAISenseConfig_Sight> SightConfig = nullptr;
		
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* WolfBehaviorTree;

protected:
	virtual void BeginPlay() override;
	
};
