// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardTable.h"
#include "BlackjackTable.generated.h"

class APlayingCard;

/**
 * 
 */
UCLASS()
class GOBLINGAME_API ABlackjackTable : public ACardTable
{
	GENERATED_BODY()
	
public:

	void SpawnCard();

protected:

	UPROPERTY()
	TSubclassOf<APlayingCard> PlayingCardBP;
};
