// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoblingGambling_MinigameBase.generated.h"

class AGoblinGambline_PlayerBase;
class UBoxComponent;

UCLASS()

class GOBLINGAME_API AGoblingGambling_MinigameBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGoblingGambling_MinigameBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	bool m_isInUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int m_buyInCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int m_maxNumOfPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfor")
	TArray<AGoblinGambline_PlayerBase*>ListOfPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* m_MinigameMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitBox")
	UBoxComponent* m_PlayAreaHitBox;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	// Tell Player they can join the game
	virtual void PlayerEnteredPlayArea();

	UFUNCTION()
	//Player leaves minigame and gets payed
	virtual void LeaveMinigame();

	UFUNCTION()
	//check if player's wallet is fat enough to join
	virtual bool CheckBuyIn();

	UFUNCTION()
	//give player winnings 
	virtual void PayOutPlayer();

	UFUNCTION()
	//custom code per machine, the actual game
	virtual void PlayMinigame();
};
