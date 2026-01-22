// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetNPC_Base.h"
#include "../Currency/GoblinWalletComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../StreetNPC/StreetNPC_Controller.h"

/*
* TODO:
* - move the actual adding of funds to player wallet to the behavior tree
*/

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

    SpawnDefaultController();

	verify(Controller);

    NPCController = Cast<AStreetNPC_Controller>(GetController());
}

// Called every frame
void AStreetNPC_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStreetNPC_Base::GetBeggedAt(UGoblinWalletComponent* playerWallet)
{
	float random = FMath::FRandRange(0.0f, 1.0f);

	if (random <= ChanceToGive)
	{
		playerWallet->AddGoblinBucks(AmountToGive);

		UAIBlueprintHelperLibrary::GetBlackboard(this)->SetValueAsObject(FName("PlayerLocation"), playerWallet->GetOwner());

		GetComponentByClass<UCharacterMovementComponent>()->StopActiveMovement();

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

void AStreetNPC_Base::SetDespawnPoint(FVector location)
{
	UAIBlueprintHelperLibrary::GetBlackboard(this)->SetValueAsVector(FName("DespawnPoint"), location);
}

//this could be handled in the object pool, but i dont currently have any other use for these functions.
void AStreetNPC_Base::ActivateFromPool()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	if(UBlackboardComponent* BB = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{ 
		BB->ClearValue("DespawnPoint");
	}

	NPCController->StartBehaviorTree();
}

void AStreetNPC_Base::ReturnToPool()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	UAIBlueprintHelperLibrary::GetBlackboard(this)->ClearValue("DespawnPoint");

	NPCController->PauseBehaviorTree();
}
