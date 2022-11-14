// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfAIController.h"

AWolfAIController::AWolfAIController()
{
	
}

void AWolfAIController::BeginPlay()
{
	Super::BeginPlay();

	if(WolfBehaviorTree)
	{
		RunBehaviorTree(WolfBehaviorTree);
	}
}

void AWolfAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}



