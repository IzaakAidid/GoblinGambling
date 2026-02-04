// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckOfCards.h"
#include "PlayingCardDataAsset.h"

void UDeckOfCards::ShuffleDeck()
{
    // Implementing Fisher-Yates shuffle algorithm
    for (int i = Cards.Num() - 1; i > 0; i--)
    {
        int SwapIndex = FMath::RandRange(0, i);
        UPlayingCardDataAsset* Temp = Cards[i];
        Cards[i] = Cards[SwapIndex];
        Cards[SwapIndex] = Temp;
    }

    TopCardIndex = 0;
}

UPlayingCardDataAsset* UDeckOfCards::DrawTopCard()
{
    if (TopCardIndex < Cards.Num() - 1)
    {
        return Cards[TopCardIndex++];
    }
    else
    {
        ShuffleDeck();
        return Cards[TopCardIndex];
    }
}

void UDeckOfCards::Debug_ListCards()
{
    for (const auto& card : Cards)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, card->CardName);
    }
}
