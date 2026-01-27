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

	//TArray<PrizeBase> GetFullPlayerInventory() {return m_PlayerPrizeInventory; };
	void SavePlayerInventory(class AGoblinGambline_PlayerBase* pPlayer);


private:
	//TArray<PrizeBase> m_PlayerPrizeInventory;
	//TArray<PrizeBase> m_EquippedItems;
	int m_UserIndex;


};