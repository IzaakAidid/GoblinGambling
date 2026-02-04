// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayingCard.generated.h"

class UTextRenderComponent;
class UPlayingCardDataAsset;

UCLASS()
class GOBLINGAME_API APlayingCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayingCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* TextComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetCardData(UPlayingCardDataAsset* playingCardData);

};
