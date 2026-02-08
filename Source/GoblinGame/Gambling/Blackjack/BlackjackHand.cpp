// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackjackHand.h"
#include "GoblinWalletComponent.h"
#include "Components/ArrowComponent.h"

ABlackjackHand::ABlackjackHand()
{
    DirectionToPlayer = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionToPlayer"));
    RootComponent = DirectionToPlayer;
}
