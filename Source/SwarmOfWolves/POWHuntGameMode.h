// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "POWHuntGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SWARMOFWOLVES_API APOWHuntGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APOWHuntGameMode();

	UPROPERTY(VisibleAnywhere)
	bool bIsHuntActive = false;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HuntButtonWidgetClass;
	
	UPROPERTY()
	UUserWidget* HuntButtonWidget;
};
