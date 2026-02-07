// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gambling/CardTable.h"
#include "BlackjackTable.generated.h"

/**
 * 
 */
UCLASS()
class GOBLINGAME_API ABlackjackTable : public ACardTable
{
	GENERATED_BODY()

	ABlackjackTable();

protected:

    virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UArrowComponent* DealerHandLocation;

public:

	UFUNCTION(NetMulticast, Reliable)
	void NMC_DealCards();
	
};
