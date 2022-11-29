// Fill out your copyright notice in the Description page of Project Settings.


#include "DeerAIController.h"

ADeerAIController::ADeerAIController()
{
	
}

void ADeerAIController::BeginPlay()
{
	Super::BeginPlay();

	if(DeerBehaviorTree)
	{
		RunBehaviorTree(DeerBehaviorTree);
	}
}

FGenericTeamId ADeerAIController::GetGenericTeamId() const
{
	return TeamId;
}


