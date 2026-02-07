// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackjackHand.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "GoblinWalletComponent.h"
#include "Components/ArrowComponent.h"

ABlackjackHand::ABlackjackHand()
{
    DirectionToPlayer = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionToPlayer"));
    RootComponent = DirectionToPlayer;

    BetPlacerComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("BetPlacerComp"));
    BetPlacerComponent->SetVisibility(false);
    BetPlacerComponent->SetupAttachment(RootComponent);
}

void ABlackjackHand::SetActivePlayerWallet(AActor* playerActor)
{
    Super::SetActivePlayerWallet(playerActor);

    SetOwner(playerActor);

    Client_ShowBetPlacer();
}

void ABlackjackHand::ClearActivePlayerWallet()
{
    Super::ClearActivePlayerWallet();

    BetPlacerComponent->SetVisibility(false);

    SetOwner(nullptr);
}

void ABlackjackHand::Server_PlaceBet_Implementation(int value)
{
    if (WalletComponent->GetHeldGoblinBucks() >= value)
    { 
        WalletComponent->RemoveGoblinBucks(value);

        MyBetPlacedDelegate.ExecuteIfBound();

        Client_HideBetPlacer();

        return;
    }

    //if i continue in an else if, id have to divide twice which is the most facepalm optimization but whatever
    float moneyDivided = (float)WalletComponent->GetHeldGoblinBucks() / value;

    if (moneyDivided > 1.0f)
    {
        int maxBet = (int)moneyDivided * value; //use this to clamp bet
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("youre poor"));
    }
}

void ABlackjackHand::Client_ShowBetPlacer_Implementation()
{
    BetPlacerComponent->SetVisibility(true);
}


void ABlackjackHand::Client_HideBetPlacer_Implementation()
{
    BetPlacerComponent->SetVisibility(false);
}