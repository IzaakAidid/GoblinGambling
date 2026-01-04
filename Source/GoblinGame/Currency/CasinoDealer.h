// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CasinoDealer.generated.h"

UCLASS()
class GOBLINGAME_API ACasinoDealer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACasinoDealer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	USkeletalMeshComponent DealerMesh;
	//TEMP - REMOVE LATER WHEN A SKELETAL MESH IS CREATED
	UStaticMeshComponent TEMP_DealerMesh;
	class UBoxComponent InteractionCollisionBox;

#pragma region Functions

	void ConvertBucksToChips(int BucksToConvert);
	void ConvertChipsToBucks(int BucksToConvert);

#pragma endregion

#pragma region Member Variables
private:
	int m_CasinoGoblinBucks;
	int m_CasinoGoblinChips;

#pragma endregion
};
