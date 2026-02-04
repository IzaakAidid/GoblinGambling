// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackjackTable.h"
#include "PlayingCard.h"
#include "DeckOfCards.h"
#include "PlayerHand.h"

void ABlackjackTable::SpawnCard()
{
    if (APlayingCard* Card = GetWorld()->SpawnActor<APlayingCard>(PlayingCardBP))
    {
        Card->SetCardData(DeckOfCards->DrawTopCard());
        Card->SetActorLocationAndRotation(PlayerHandActor->GetActorLocation(), PlayerHandActor->GetActorRotation());
    }
}
