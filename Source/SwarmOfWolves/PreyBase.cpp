// Fill out your copyright notice in the Description page of Project Settings.


#include "PreyBase.h"

// Sets default values
APreyBase::APreyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APreyBase::BeginPlay()
{
	Super::BeginPlay();

	//Getting transform for the FindRandomLocation task
	OriginTransform = GetTransform();

	CurrentHealth = MaxHealth;

	DeerAIController = Cast<ADeerAIController>(GetController());
	if(!DeerAIController)
	{
		return;
	}
}

// Called every frame
void APreyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APreyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool APreyBase::IsDead() const
{
	if(CurrentHealth <= 0)
	{
		return true;
	}
	return false;
}

ADeerAIController* APreyBase::GetDeerAIController()
{
	return DeerAIController;
}



