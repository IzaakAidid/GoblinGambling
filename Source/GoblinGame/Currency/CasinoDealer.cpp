// Fill out your copyright notice in the Description page of Project Settings.


#include "CasinoDealer.h"
#include "GoblinWalletComponent.h"
#include "Components/BoxComponent.h"
#include "../Player/GoblinGambline_PlayerBase.h"
#include "Blueprint/UserWidget.h"
#include "../UI/CasinoDealerMenuWidget.h"

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
	if (pPlayerWallet->GetHeldGoblinBucks() >= BucksToConvert)
	{
		// remove bucks from wallet
		pPlayerWallet->RemoveGoblinBucks(BucksToConvert);
		// add that number back to the wallet as chips
		pPlayerWallet->AddGoblinChips(BucksToConvert, CasinoChipsType);
	}
	else
	{
		int tempVal = pPlayerWallet->GetHeldGoblinBucks();
		// remove bucks from wallet
		pPlayerWallet->RemoveGoblinBucks(tempVal);
		// add that number back to the wallet as chips
		pPlayerWallet->AddGoblinChips(tempVal, CasinoChipsType);
	}

}

void ACasinoDealer::ConvertChipsToBucks(int ChipsToConvert, UGoblinWalletComponent* pPlayerWallet)
{
	if (pPlayerWallet->GetHeldGoblinChips(CasinoChipsType) >= ChipsToConvert)
	{
		// remove chips from wallet
		pPlayerWallet->RemoveGoblinChips(ChipsToConvert, CasinoChipsType);
		// add that number back to the wallet as bucks
		pPlayerWallet->AddGoblinBucks(ChipsToConvert);
	}
	else
	{
		int tempVal = pPlayerWallet->GetHeldGoblinChips(CasinoChipsType);
		// remove chips from wallet
		pPlayerWallet->RemoveGoblinChips(tempVal, CasinoChipsType);
		// add that number back to the wallet as bucks
		pPlayerWallet->AddGoblinBucks(tempVal);
	}

}

void ACasinoDealer::ConvertALLChipsToBucks(UGoblinWalletComponent* pPlayerWallet)
{
	int temp = pPlayerWallet->GetHeldGoblinChips(CasinoChipsType);
	pPlayerWallet->RemoveGoblinChips(temp, CasinoChipsType);
	pPlayerWallet->AddGoblinBucks(temp);

}

void ACasinoDealer::ConvertALLBucksToChips(UGoblinWalletComponent* pPlayerWallet)
{
	int temp = pPlayerWallet->GetHeldGoblinBucks();
	pPlayerWallet->RemoveGoblinBucks(temp);
	pPlayerWallet->AddGoblinChips(temp, CasinoChipsType);
}

void ACasinoDealer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ACasinoDealer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ACasinoDealer::Interact_Implementation(AGoblinGambline_PlayerBase* Player)
{
	if (pMenuWidget)
	{
		pMenuWidget->pOwningDealer = this;
		if (APlayerController* tempController = Cast<APlayerController>(Player->Controller))
		{
			if (tempController->IsLocalPlayerController())
			{
				pMenuWidget->pPlayerController = tempController;
				pMenuWidget->pPlayerWallet = Player->PlayerWallet;

				pMenuWidget->AddToViewport();
			}
		}
	}

}
