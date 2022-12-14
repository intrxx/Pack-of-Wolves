// Fill out your copyright notice in the Description page of Project Settings.

#include "PreyBase.h"

#include "Components/CapsuleComponent.h"


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
	bIsWeakest = false;

	DeerAIController = Cast<ADeerAIController>(GetController());
	if(!DeerAIController)
	{
		return;
	}

	LifeStrength = FMath::Rand();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Prey Life Strength: %f"), LifeStrength));
}

// Called every frame
void APreyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APreyBase::ApplyDamage(float Damage)
{
	CurrentHealth -= Damage;

	if(IsDead())
	{
		APreyBase* Prey = Cast<APreyBase>(DeerAIController->GetPawn());
		if(Prey)
		{
			if(DeathMontage)
			{
				Prey->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				Prey->PlayAnimMontage(DeathMontage);
			}
		}
	}
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



