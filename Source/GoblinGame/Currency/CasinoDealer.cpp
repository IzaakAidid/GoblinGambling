// Fill out your copyright notice in the Description page of Project Settings.


#include "CasinoDealer.h"
#include "GoblinWalletComponent.h"
#include "Components/BoxComponent.h"
#include "../Player/GoblinGambline_PlayerBase.h"

// Sets default values
ACasinoDealer::ACasinoDealer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractionCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DealerInteractionCollisionBox"));
	DealerWallet = CreateDefaultSubobject<UGoblinWalletComponent>(TEXT("DealerWallet"));

	TEMP_DealerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PROTOTYPE_DealerMesh"));
	DealerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DealerSkeletalMesh"));

	SetRootComponent(DealerMesh);
	TEMP_DealerMesh->SetupAttachment(RootComponent);
	InteractionCollisionBox->SetupAttachment(RootComponent);
	CasinoChipsType = ECasinoChipsType::CASINO1;
}

// Called when the game starts or when spawned
void ACasinoDealer::BeginPlay()
{
	Super::BeginPlay();
	InteractionCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACasinoDealer::OnOverlapBegin);
	InteractionCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ACasinoDealer::OnOverlapEnd);
}

// Called every frame
void ACasinoDealer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACasinoDealer::ConvertBucksToChips(int BucksToConvert, UGoblinWalletComponent* pPlayerWallet)
{
	// remove bucks from wallet
	pPlayerWallet->RemoveGoblinBucks(BucksToConvert);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(555, 15.0f, FColor::Blue, FString::Printf(TEXT("CONVERTING BUCKS TO CHIPS: Removed bucks from wallet for conversion: %i"), BucksToConvert));
		GEngine->AddOnScreenDebugMessage(556, 15.0f, FColor::Blue, FString::Printf(TEXT("New bucks wallet balance: %i"), pPlayerWallet->GetHeldGoblinBucks()));
	}
	// add that number back to the wallet as chips
	pPlayerWallet->AddGoblinChips(BucksToConvert, CasinoChipsType);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(557, 15.0f, FColor::Yellow, FString::Printf(TEXT("Added chips to wallet: %i"), BucksToConvert));
		GEngine->AddOnScreenDebugMessage(558, 15.0f, FColor::Yellow, FString::Printf(TEXT("New chips wallet balance: % i"), pPlayerWallet->GetHeldGoblinChips(CasinoChipsType)));
	}
}

void ACasinoDealer::ConvertChipsToBucks(int ChipsToConvert, UGoblinWalletComponent* pPlayerWallet)
{
	// remove chips from wallet
	pPlayerWallet->RemoveGoblinChips(ChipsToConvert, CasinoChipsType);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(559, 15.0f, FColor::Emerald, FString::Printf(TEXT("CONVERTING CHIPS TO BUCKS: Removed chips from wallet for conversion: %i"), ChipsToConvert));
		GEngine->AddOnScreenDebugMessage(560, 15.0f, FColor::Emerald, FString::Printf(TEXT("New chips wallet balance: %i"), pPlayerWallet->GetHeldGoblinChips(CasinoChipsType)));
	}
	// add that number back to the wallet as bucks
	pPlayerWallet->AddGoblinBucks(ChipsToConvert);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(561, 15.0f, FColor::Cyan, FString::Printf(TEXT("Added bucks to wallet: %i"), ChipsToConvert));
		GEngine->AddOnScreenDebugMessage(562, 15.0f, FColor::Cyan, FString::Printf(TEXT("New bucks wallet balance: %i"), pPlayerWallet->GetHeldGoblinBucks()));
	}
}

void ACasinoDealer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//player is close enough to interact
	int x = 2; //debug
	if (AGoblinGambline_PlayerBase* temp = Cast<AGoblinGambline_PlayerBase>(OtherActor))
	{
		//temp->PlayerWallet->AddGoblinBucks(10);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(0, 15.0f, FColor::Green, FString::Printf(TEXT("----------------------------------------------------------------------")));
			GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Green, FString::Printf(TEXT("ADDING TEST: Added goblin bucks to player wallet, new gobbo bucks: %i"), temp->PlayerWallet->GetHeldGoblinBucks()));
		}

		ConvertBucksToChips(5,temp->PlayerWallet);
	}
	//if ();
}

void ACasinoDealer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//player has left the interaction zone
	int x = 2; //debug
	if (AGoblinGambline_PlayerBase* temp = Cast<AGoblinGambline_PlayerBase>(OtherActor))
	{
		//temp->PlayerWallet->AddGoblinChips(10,ECasinoChipsType::CASINO1);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(2, 15.0f, FColor::Magenta, FString::Printf(TEXT("----------------------------------------------------------------------")));
			GEngine->AddOnScreenDebugMessage(3, 15.0f, FColor::Magenta, FString::Printf(TEXT("Added goblin chips to player wallet, new gobbo chips: %i"), temp->PlayerWallet->GetHeldGoblinChips(ECasinoChipsType::CASINO1)));
		}
		ConvertChipsToBucks(5, temp->PlayerWallet);
	}
}