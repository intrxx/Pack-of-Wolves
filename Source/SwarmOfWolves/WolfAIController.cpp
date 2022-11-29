// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Sight.h"

AWolfAIController::AWolfAIController()
{
	//Setup the perception component
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->SightRadius = 1000;
	SightConfig->LoseSightRadius = 1200;
	SightConfig->PeripheralVisionAngleDegrees = 360.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;
	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	AAIController::SetGenericTeamId(FGenericTeamId(1));
}

void AWolfAIController::BeginPlay()
{
	Super::BeginPlay();

	if(WolfBehaviorTree)
	{
		RunBehaviorTree(WolfBehaviorTree);
	}

	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AWolfAIController::OnTargetPerceptionUpdate_Delegate);
}

ETeamAttitude::Type AWolfAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (APawn const* OtherPawn = Cast<APawn>(&Other))
	{
		if (auto const TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			if (TeamAgent->GetGenericTeamId() == FGenericTeamId(1))
			{
				return ETeamAttitude::Friendly;
			}
			else if(TeamAgent->GetGenericTeamId() == FGenericTeamId(4))
			{
				return ETeamAttitude::Hostile;
			}
		}
	}
	return ETeamAttitude::Neutral;
}

void AWolfAIController::OnTargetPerceptionUpdate_Delegate(AActor* Actor, FAIStimulus Stimulus)
{
	switch (Stimulus.Type)
	{
	case 0:
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "Spotted the prey!");
			GetBlackboardComponent()->SetValueAsBool("bFoundPrey",true);
	default:
		return;
	}
	
}



