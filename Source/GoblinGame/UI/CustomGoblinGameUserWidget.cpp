// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGoblinGameUserWidget.h"
#include "../Player/GoblinGambline_PlayerBase.h"
#include "../Currency/GoblinWalletComponent.h"
#include "../Player/GoblinPlayerHUD.h"

int UCustomGoblinGameUserWidget::GetGoblinBucksForUI()
{
	AGoblinGambline_PlayerBase* tempPlayerPointer = nullptr;

	tempPlayerPointer = Cast<AGoblinGambline_PlayerBase>(GetOwningPlayer()->GetPawn());
	if (tempPlayerPointer)
	{
		return tempPlayerPointer->PlayerWallet->GetHeldGoblinBucks();
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino1ForUI()
{
	AGoblinGambline_PlayerBase* tempPlayerPointer = nullptr;

	tempPlayerPointer = Cast<AGoblinGambline_PlayerBase>(GetOwningPlayer()->GetPawn());
	if (tempPlayerPointer)
	{
		return tempPlayerPointer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO1);
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino2ForUI()
{
	AGoblinGambline_PlayerBase* tempPlayerPointer = nullptr;

	tempPlayerPointer = Cast<AGoblinGambline_PlayerBase>(GetOwningPlayer()->GetPawn());
	if (tempPlayerPointer)
	{
		return tempPlayerPointer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO2);
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino3ForUI()
{
	AGoblinGambline_PlayerBase* tempPlayerPointer = nullptr;

	tempPlayerPointer = Cast<AGoblinGambline_PlayerBase>(GetOwningPlayer()->GetPawn());
	if (tempPlayerPointer)
	{
		return tempPlayerPointer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO3);
	}
	else
	{
		return 0;
	}
}
