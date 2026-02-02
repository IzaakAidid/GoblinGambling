// Fill out your copyright notice in the Description page of Project Settings.


#include "../Gambling/PlayerSeat.h"
#include "Components/ArrowComponent.h"
#include "../Player/GoblinGambline_PlayerBase.h"
#include "../Player/GoblinController.h"

// Sets default values
APlayerSeat::APlayerSeat()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
    RootComponent = StaticMesh;

    ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow Component"));
    ArrowComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerSeat::BeginPlay()
{
    Super::BeginPlay();

}

void APlayerSeat::Interact_Implementation(AGoblinGambline_PlayerBase* Player)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Player Seat Interacted With"));

    Player->SetActorLocation(ArrowComponent->GetComponentLocation());
    Player->Controller->SetControlRotation(ArrowComponent->GetComponentRotation());
    Player->ForceFirstPerson();

    if (AGoblinController* Controller = Cast<AGoblinController>(Player->Controller))
    {
        Controller->SwapToTableInput();
    }
}
