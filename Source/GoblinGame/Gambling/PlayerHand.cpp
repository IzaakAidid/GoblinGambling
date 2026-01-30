// Fill out your copyright notice in the Description page of Project Settings.


#include "../Gambling/PlayerHand.h"
#include "../Currency/GoblinWalletComponent.h"

// Sets default values
APlayerHand::APlayerHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("I have the wallet"));
    }
}
