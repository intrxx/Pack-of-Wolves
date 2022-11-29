// Fill out your copyright notice in the Description page of Project Settings.


#include "POWHuntGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

APOWHuntGameMode::APOWHuntGameMode()
{
	
}

void APOWHuntGameMode::BeginPlay()
{
	if(HuntButtonWidgetClass)
	{
		UGameInstance* GI = UGameplayStatics::GetGameInstance(GetWorld());
		if(GI)
		{
			HuntButtonWidget = CreateWidget(GI, HuntButtonWidgetClass);
			HuntButtonWidget->AddToViewport();
		}
	}
}



