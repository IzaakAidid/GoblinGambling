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

	if(HasAuthority())
		verify(Controller);

    NPCController = Cast<AStreetNPC_Controller>(GetController());
}

// Called every frame
void AStreetNPC_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStreetNPC_Base::GetBeggedAt_Implementation(UGoblinWalletComponent* playerWallet)
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

//This should always be supplied with the despawn point at minimum, so i dont think a pop safety check is needed.
void AStreetNPC_Base::SetPath(TArray<FVector> path)
{
	NPCPath = path;

	FVector Next = NPCPath.Pop();

	UAIBlueprintHelperLibrary::GetBlackboard(this)->SetValueAsVector(FName("PathLocation"), Next);
}

void AStreetNPC_Base::UpdatePathLocation()
{
	if (NPCPath.Num() != 0)
	{
		FVector Next = NPCPath.Pop();

		UAIBlueprintHelperLibrary::GetBlackboard(this)->SetValueAsVector(FName("PathLocation"), Next);
	}
}

void AStreetNPC_Base::ActivateFromPool()
{
	if(UBlackboardComponent* BB = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{ 
		BB->ClearValue("PathLocation");
	}

	NPCController->StartBehaviorTree();
}

void AStreetNPC_Base::ReturnToPool()
{
	UAIBlueprintHelperLibrary::GetBlackboard(this)->ClearValue("PathLocation");

	NPCController->PauseBehaviorTree();
}
