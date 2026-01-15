// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetBeggingComponent.h"
#include "Components/SphereComponent.h"
#include "GoblinWalletComponent.h"
#include "../StreetNPC/StreetNPC_Base.h"

// Sets default values for this component's properties
UStreetBeggingComponent::UStreetBeggingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStreetBeggingComponent::InitBeggingComponent(USphereComponent* StreetBeggingRadius, UGoblinWalletComponent* wallet)
{
    PlayerWallet = wallet;

	BeggingRadiusComponent = StreetBeggingRadius;

	BeggingRadiusComponent->OnComponentBeginOverlap.AddDynamic(this, &UStreetBeggingComponent::OnOverlapBegin);
	BeggingRadiusComponent->OnComponentEndOverlap.AddDynamic(this, &UStreetBeggingComponent::OnOverlapEnd);
}

void UStreetBeggingComponent::ActivateBegging()
{
    BeggingRadiusComponent->SetGenerateOverlapEvents(true);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(555, 3.0f, FColor::Green, FString::Printf(TEXT("OOOH IM BEGGING")));
	}
}

void UStreetBeggingComponent::DeactivateBegging()
{
	BeggingRadiusComponent->SetGenerateOverlapEvents(false);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(555, 3.0f, FColor::Red, FString::Printf(TEXT("OOOH IM NOT BEGGING")));
	}
}

void UStreetBeggingComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AStreetNPC_Base* npc = Cast<AStreetNPC_Base>(OtherActor))
	{
        npc->GetBeggedAt(PlayerWallet);
	}
}

void UStreetBeggingComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}