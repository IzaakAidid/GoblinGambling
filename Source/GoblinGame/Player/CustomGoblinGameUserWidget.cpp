// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGoblinGameUserWidget.h"
#include "GoblinGambline_PlayerBase.h"
#include "../Currency/GoblinWalletComponent.h"
#include "GoblinPlayerHUD.h"


//UCustomGoblinGameUserWidget::UCustomGoblinGameUserWidget()
//{
//
//}
//
//void UCustomGoblinGameUserWidget::BeginPlay()
//{
//	Super::BeginPlay();
//
//}

int UCustomGoblinGameUserWidget::GetGoblinBucksForUI()
{
	if (pOwningPlayer)
	{
		return pOwningPlayer->PlayerWallet->GetHeldGoblinBucks();
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino1ForUI()
{
	if (pOwningPlayer)
	{
		return pOwningPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO1);
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino2ForUI()
{
	if (pOwningPlayer)
	{
		return pOwningPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO2);
	}
	else
	{
		return 0;
	}
}

int UCustomGoblinGameUserWidget::GetGoblinChipsCasino3ForUI()
{
	if (pOwningPlayer)
	{
		return pOwningPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO3);
	}
	else
	{
		return 0;
	}
}
