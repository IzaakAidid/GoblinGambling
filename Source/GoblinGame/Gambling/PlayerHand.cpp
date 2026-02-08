// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHand.h"
#include "GoblinWalletComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Net/UnrealNetwork.h"

// Sets default values
APlayerHand::APlayerHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    BetPlacerComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("BetPlacerComp"));
    BetPlacerComponent->SetVisibility(false);
    BetPlacerComponent->SetupAttachment(RootComponent);

    SetReplicates(true);
}

// Called when the game starts or when spawned
void APlayerHand::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerHand::SetActivePlayerWallet(AActor* playerActor)
{
	if (playerActor)
	{
		WalletComponent = playerActor->FindComponentByClass<UGoblinWalletComponent>();

        SetOwner(playerActor);

        if(bCanBet)
            Client_ShowBetPlacer();
    }
}

void APlayerHand::ClearActivePlayerWallet()
{
    BetPlacerComponent->SetVisibility(false);

    SetOwner(nullptr);
}

void APlayerHand::Server_PlaceBet_Implementation(int value)
{
    if (WalletComponent->GetHeldGoblinBucks() >= value)
    {
        WalletComponent->RemoveGoblinBucks(value);

        bCanBet = false;

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

void APlayerHand::Client_ShowBetPlacer_Implementation()
{
    BetPlacerComponent->SetVisibility(true);
}


void APlayerHand::Client_HideBetPlacer_Implementation()
{
    BetPlacerComponent->SetVisibility(false);
}

void APlayerHand::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APlayerHand, WalletComponent);
}