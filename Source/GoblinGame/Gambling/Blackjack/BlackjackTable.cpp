// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackjackTable.h"
#include "BlackjackHand.h"
#include "DeckOfCards.h"
#include "PlayingCard.h"
#include "Components/ArrowComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"


ABlackjackTable::ABlackjackTable()
{
    DealerHandLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("DealerHandLocation"));
    DealerHandLocation->SetupAttachment(RootComponent);
}

void ABlackjackTable::BeginPlay()
{
    Super::BeginPlay();

}

//This will need to be updated to account for multiple players.
void ABlackjackTable::NMC_DealCards_Implementation()
{
   /* DeckOfCards->ShuffleDeck();

    APlayingCard* Card1 = GetWorld()->SpawnActor<APlayingCard>(CardBP);
    APlayingCard* Card2 = GetWorld()->SpawnActor<APlayingCard>(CardBP);
    APlayingCard* Card3 = GetWorld()->SpawnActor<APlayingCard>(CardBP);
    APlayingCard* Card4 = GetWorld()->SpawnActor<APlayingCard>(CardBP);

    Card1->SetActorLocationAndRotation(PlayerHandActor->GetActorLocation(), PlayerHandActor->GetActorRotation());
    Card2->SetActorLocationAndRotation(DealerHandLocation->GetComponentLocation(), FRotator(0.0f, 0.0f, 180.0f));
    Card3->SetActorLocationAndRotation(PlayerHandActor->GetActorLocation() - PlayerHandActor->GetActorRightVector() * 15, PlayerHandActor->GetActorRotation());
    Card4->SetActorLocation(DealerHandLocation->GetComponentLocation() - DealerHandLocation->GetRightVector() * 15);

    Card1->SetCardData(DeckOfCards->DrawTopCard());
    Card2->SetCardData(DeckOfCards->DrawTopCard());
    Card3->SetCardData(DeckOfCards->DrawTopCard());
    Card4->SetCardData(DeckOfCards->DrawTopCard());*/
}
