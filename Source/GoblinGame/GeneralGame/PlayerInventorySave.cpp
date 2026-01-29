// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerInventorySave.h"


// Includes for save data
#include "../Player/GoblinGambline_PlayerBase.h"
#include "../Currency/GoblinWalletComponent.h"





UPlayerInventorySave::UPlayerInventorySave()
{
	PlayerName = "EmptyName";

	SavedHeldGoblinBucks = 0;

	SavedHeldGoblinChips_C1 = 0;

	SavedHeldGoblinChips_C2 = 0;

	SavedHeldGoblinChips_C3 = 0;

}

void UPlayerInventorySave::SavePlayerInventory(AGoblinGambline_PlayerBase* pPlayer)
{
	// Save player data here
	PlayerName = "PlayerName";



	SavedHeldGoblinBucks = pPlayer->PlayerWallet->GetHeldGoblinBucks();

	SavedHeldGoblinChips_C1 = pPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO1);

	SavedHeldGoblinChips_C2 = pPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO2);

	SavedHeldGoblinChips_C3 = pPlayer->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO3);

	//SaveSlotName
}