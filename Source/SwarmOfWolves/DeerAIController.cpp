// Fill out your copyright notice in the Description page of Project Settings.


#include "DeerAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PreyBase.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Sight.h"

ADeerAIController::ADeerAIController()
{
	//Setup the perception component
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->SightRadius = 600;
	SightConfig->LoseSightRadius = 1200;
	SightConfig->PeripheralVisionAngleDegrees = 360.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;
	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	
}

void ADeerAIController::BeginPlay()
{
	Super::BeginPlay();

	if(DeerBehaviorTree)
	{
		RunBehaviorTree(DeerBehaviorTree);
	}

	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ADeerAIController::OnTargetPerceptionUpdate_Delegate);
}

ETeamAttitude::Type ADeerAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (APawn const* OtherPawn = Cast<APawn>(&Other))
	{
		if (auto const TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			if (TeamAgent->GetGenericTeamId() == FGenericTeamId(4))
			{
				return ETeamAttitude::Friendly;
			}
			else if(TeamAgent->GetGenericTeamId() == FGenericTeamId(1))
			{
				return ETeamAttitude::Hostile;
			}
		}
	}
	return ETeamAttitude::Neutral;
}

void ADeerAIController::OnTargetPerceptionUpdate_Delegate(AActor* Actor, FAIStimulus Stimulus)
{
	switch (Stimulus.Type)
	{
	case 0:
		if(GetBlackboardComponent()->GetValueAsBool("bIsInDanger") == false || GetBlackboardComponent()->GetValueAsBool("bIsInDanger") == NULL)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "Spotted the wolf!");
			APreyBase* Deer = Cast<APreyBase>(GetPawn());
			if(Deer == nullptr)
			{
				return;
			}
			
			GetBlackboardComponent()->SetValueAsBool("bIsInDanger",true);
		}
	default:
		return;
	}
	
}

FGenericTeamId ADeerAIController::GetGenericTeamId() const
{
	return TeamId;
}


