// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardTable.generated.h"

class UArrowComponent;
class APlayerHand;
class UDeckOfCards;
class APlayingCard;

UCLASS(Blueprintable)
class GOBLINGAME_API ACardTable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACardTable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APlayerHand* PlayerHandActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDeckOfCards> DeckBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDeckOfCards* DeckOfCards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APlayingCard> CardBP;

public:	

};
