// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_AttackAndPlayAM.h"

// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_PlayAnimationMontage.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "WolfAIController.h"
#include "WolfBase.h"

UBTT_AttackAndPlayAM::UBTT_AttackAndPlayAM()
{
	NodeName = TEXT("Attack and Play AM");
	bCreateNodeInstance = true;

	TimerDelegate = FTimerDelegate::CreateUObject(this, &UBTT_AttackAndPlayAM::OnAnimMontageTimerDone);
}

EBTNodeResult::Type UBTT_AttackAndPlayAM::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	EBTNodeResult::Type Result = EBTNodeResult::Failed;
	
	TimerHandle.Invalidate();
	MyOwnerComp = &OwnerComp;
	
	AWolfAIController* WAIController = Cast<AWolfAIController>(OwnerComp.GetAIOwner());
	AWolfBase* Wolf = Cast<AWolfBase>(WAIController->GetPawn());
	if(AMToPlay)
	{
		const float FinishDelay = AMToPlay->GetPlayLength();
		if(Wolf && FinishDelay > 0)
		{
			Wolf->PlayAnimMontage(AMToPlay);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, FinishDelay, false);
			Result = EBTNodeResult::InProgress;
		}
		else
		{
			Result = EBTNodeResult::Succeeded;
		}
	}
	
	return Result;
}

void UBTT_AttackAndPlayAM::OnAnimMontageTimerDone()
{
	FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
}
