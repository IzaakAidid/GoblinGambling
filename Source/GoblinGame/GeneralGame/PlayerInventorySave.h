// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerInventorySave.generated.h"

/**
 *
 */
UCLASS()
class GOBLINGAME_API UPlayerInventorySave : public USaveGame
{
	GENERATED_BODY()

public:

	UPlayerInventorySave();

	//TArray<PrizeBase> GetFullPlayerInventory() {return m_PlayerPrizeInventory; };
	void SavePlayerInventory(class AGoblinGambline_PlayerBase* pPlayer);




	//TArray<PrizeBase> m_PlayerPrizeInventory;
	//TArray<PrizeBase> m_EquippedItems;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int SavedHeldGoblinBucks;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int SavedHeldGoblinChips_C1;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int SavedHeldGoblinChips_C2;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int SavedHeldGoblinChips_C3;

private:
	int m_UserIndex;


};