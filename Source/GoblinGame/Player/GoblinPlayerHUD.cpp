// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinPlayerHUD.h"
#include "GoblinGambline_PlayerBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../Currency/GoblinWalletComponent.h"
#include "../UI/CustomGoblinGameUserWidget.h"

AGoblinPlayerHUD::AGoblinPlayerHUD()
{
	//pOwningPlayer = nullptr;
}

void AGoblinPlayerHUD::TogglePause()
{
	if (pPauseScreen)
	{
		if (pPauseScreen->IsVisible())
		{
			// Unpause the game
			//UGameplayStatics::SetGamePaused(GetWorld(), false);
			pPauseScreen->RemoveFromParent();
		}
		else
		{
			// Pause the game
			//UGameplayStatics::SetGamePaused(GetWorld(), true);
			pPauseScreen->AddToViewport();
		}
	}
}

void AGoblinPlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (pGameUI)
	{
		AGoblinGambline_PlayerBase* tempPlayerPointer = nullptr;
		//TEMPORARY FIX | NON-NETWORKED
		tempPlayerPointer = Cast<AGoblinGambline_PlayerBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (tempPlayerPointer != nullptr)
		{
			pGameUI->SetOwningPlayer(tempPlayerPointer->GetPlayerController());
			pPauseScreen->SetOwningPlayer(tempPlayerPointer->GetPlayerController());
			tempPlayerPointer->SetupPlayerHUD(this);
		}
		pGameUI->AddToViewport();
	}
}