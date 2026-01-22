// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreetNPCSpawner.generated.h"

/*
* TODO:
* - Pooling for the npcs
* - Look into making timer deviation more unique on the low vs. high end rather than the same number
* - Proper randomization that accounts for cumulative non-100% chance across all npc types
*/

class UBoxComponent;
class AStreetNPC_Base;

UCLASS(Blueprintable)
class GOBLINGAME_API AStreetNPCSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStreetNPCSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn Area")
    UBoxComponent* SpawnArea;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn Area")
    UBoxComponent* DespawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TSubclassOf<AStreetNPC_Base> NPCToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	int NPCsToPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float SpawnChance;

	float SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Timing")
	float SpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Timing")
	float SpawnDeviation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnStreetNPC();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
