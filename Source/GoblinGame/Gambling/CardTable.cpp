// Fill out your copyright notice in the Description page of Project Settings.


#include "CardTable.h"
#include "PlayerSeat.h"
#include "DeckOfCards.h"
#include "PlayingCard.h"
#include "PlayerHand.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ACardTable::ACardTable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

    BetsClosingWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("BetsClosingWidget"));
    BetsClosingWidget->SetupAttachment(RootComponent);
    BetsClosingWidget->SetVisibility(false);

    SetReplicates(true);
}

// Called when the game starts or when spawned
void ACardTable::BeginPlay()
{
	Super::BeginPlay();

	DeckOfCards = NewObject<UDeckOfCards>(this, DeckBP);

    for (const auto& playerHand : PlayerHandActors)
    {
        playerHand->MyBetPlacedDelegate.BindUObject(this, &ACardTable::NMC_BetPlaced);
    }
}

void ACardTable::BetsClosed()
{
    bAreBetsClosed = true;
    BetsClosingWidget->SetVisibility(false);

    for (const auto& playerHand : PlayerHandActors)
    {
        playerHand->bCanBet = false;
        playerHand->Client_HideBetPlacer();
    }
}

void ACardTable::NMC_BetPlaced_Implementation()
{
    if (bAreBetsClosed)
        return;

    int activeCount = 0; //count of how many players are sitting at the table
    int betterCount = 0; //count of how many players have placed a bet

    for (const auto& playerHand : PlayerHandActors)
    {
        //checks if the wallet at given hand is valid pointer
        if (playerHand->IsHandActive())
            activeCount++;

        //after player places bet, they self flag as unable to bet. therefore we can conclude that if flagged as such, theyve placed a bet.
        if (!playerHand->bCanBet) 
            betterCount++;
    }

    //if only one player, insta start game. if all players have bet, insta start game.
    if (activeCount == 1 || activeCount == betterCount)
    {
        BetsClosed();
        return;
    }

    BP_BetPlaced();
}