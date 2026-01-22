// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GoblinGameObjectPool.generated.h"


/**
 * TODO: 
 * 
 */
UCLASS()
class GOBLINGAME_API UGoblinGameObjectPool : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

    void AddCollectionToPool(UClass* ObjectClass, int AmountToPool);

    AActor* GetPooledObject(UClass* ObjectClass);

    void ReturnObjectToPool(AActor* PooledObject);

private:

    TMap<UClass*, TArray<AActor*>> PooledObjects; //It defaulted to UObject* but i cant see a reason to not be AActor*
};
