// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinGamblingGameState.h"

#include "Kismet/GameplayStatics.h"
#include "PlayerInventorySave.h"
#include "../Player/GoblinGambline_PlayerBase.h"
#include "../Currency/GoblinWalletComponent.h"

void AGoblinGamblingGameState::SavePlayerData(AGoblinGambline_PlayerBase* pPlayer)
{
	if (UPlayerInventorySave* SaveGameInstance = Cast<UPlayerInventorySave>(UGameplayStatics::CreateSaveGameObject(UPlayerInventorySave::StaticClass())))
	{
		// Set up the (optional) delegate.
		FAsyncSaveGameToSlotDelegate SavedDelegate;
		// USomeUObjectClass::SaveGameDelegateFunction is a void function that takes the following parameters: const FString& SlotName, const int32 UserIndex, bool bSuccess
		//SavedDelegate.BindUObject(SomeUObjectPointer, &USomeUObjectClass::SaveGameDelegateFunction);

		// Set data on the savegame object.
		SaveGameInstance->SavePlayerInventory(pPlayer);

		// Start async save process.
		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, TEXT("Testslot"), 0);
	}
}
