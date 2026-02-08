// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gambling/PlayerHand.h"
#include "BlackjackHand.generated.h"

class UArrowComponent;

/**
 * 
 */
UCLASS()
class GOBLINGAME_API ABlackjackHand : public APlayerHand
{
	GENERATED_BODY()

    ABlackjackHand();
	
public:

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UArrowComponent* DirectionToPlayer;
};
