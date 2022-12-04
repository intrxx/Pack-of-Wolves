// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "DeerAIController.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API ADeerAIController : public AAIController
{
	GENERATED_BODY()

public:
	ADeerAIController();

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UFUNCTION()
	void OnTargetPerceptionUpdate_Delegate(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent = nullptr;
	TObjectPtr<class UAISenseConfig_Sight> SightConfig = nullptr;

	FGenericTeamId TeamId = FGenericTeamId(4);
	virtual FGenericTeamId GetGenericTeamId() const override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* DeerBehaviorTree;
};
