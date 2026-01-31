// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayingCardDataAsset.generated.h"

/**
 * 
 */
UENUM()
enum class ECardSuit
{
    Spades, 
	Hearts, 
	Diamonds, 
	Clubs
};

UENUM()
enum class ECardRank
{
	Ace = 1,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};

UCLASS()
class GOBLINGAME_API UPlayingCardDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Playing Card")
	UTexture2D* CardFaceTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Playing Card")
    UTexture2D* CardBackTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Playing Card")
    FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Playing Card")
	ECardRank CardRank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Playing Card")
	ECardSuit CardSuit;

};
