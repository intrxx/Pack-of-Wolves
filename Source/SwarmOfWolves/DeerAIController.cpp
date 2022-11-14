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

void ADeerAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

