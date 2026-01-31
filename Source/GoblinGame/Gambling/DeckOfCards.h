// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DeckOfCards.generated.h"

class UPlayingCardDataAsset;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GOBLINGAME_API UDeckOfCards : public UObject
{
	GENERATED_BODY()
	
public:

    void ShuffleDeck();

    UPlayingCardDataAsset* DrawTopCard();

    void Debug_ListCards();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UPlayingCardDataAsset*> Cards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int TopCardIndex = 0;
};
