// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetNPC_Base.h"
#include "../Currency/GoblinWalletComponent.h"

// Sets default values
AStreetNPC_Base::AStreetNPC_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStreetNPC_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

float timer; //remove this later, just need basic movement to test
// Called every frame
void AStreetNPC_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timer += DeltaTime;

	if (timer < 5.0f)
	{
		AddActorWorldOffset(GetActorForwardVector() * 2.0f);
	}
	else
	{
		timer = 0.0f;
		AddActorWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}

void AStreetNPC_Base::GetBeggedAt(UGoblinWalletComponent* playerWallet)
{
	float random = FMath::FRandRange(0.0f, 1.0f);

	if (random <= ChanceToGive)
	{
		playerWallet->AddGoblinBucks(AmountToGive);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(555, 3.0f, FColor::Green, FString::Printf(TEXT("heres some dosh")));
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(555, 3.0f, FColor::Red, FString::Printf(TEXT("fuck off")));
		}
	}
}
