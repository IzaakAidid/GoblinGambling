// Fill out your copyright notice in the Description page of Project Settings.


#include "../ObjectPooling/GoblinGameObjectPool.h"
#include "ObjectPooledActor.h"

void UGoblinGameObjectPool::AddCollectionToPool(UClass* ObjectClass, int AmountToPool)
{
    if (!ObjectClass) return;

    if (PooledObjects.Contains(ObjectClass))
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Object Pool already contains this class type!: ") + ObjectClass->GetAuthoredName()); //who knows if this GetAuthoredName works
        }
        return;
    }

    //reserving here cause it technically could prevent the array from resizing/finding a new spot in memory multiple times
    TArray<AActor*> NewPoolArray;
    NewPoolArray.Reserve(AmountToPool);

    UWorld* World = GetWorld();
    if (!World) return;
    for (int i = 0; i < AmountToPool; i++)
    {
        AActor* NewActor = World->SpawnActor<AActor>(ObjectClass, FVector::ZeroVector, FRotator::ZeroRotator);
        if (NewActor)
        {
            NewActor->SetActorHiddenInGame(true);
            NewActor->SetActorEnableCollision(false);
            NewPoolArray.Add(NewActor);
        }
    }

    PooledObjects.Add(ObjectClass, NewPoolArray);
}

AActor* UGoblinGameObjectPool::GetPooledObject(UClass* ObjectClass)
{
    if (!PooledObjects.Contains(ObjectClass))
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Object Pool does not contain this class type!: ") + ObjectClass->GetAuthoredName()); //who knows if this GetAuthoredName works
        }
        return nullptr;
    }

    TArray<AActor*>& PoolArray = PooledObjects[ObjectClass];

    AActor* Object = PoolArray.Pop(EAllowShrinking::No); //No shrinking to avoid reallocations upon returning to pool

    if(Object->Implements<UObjectPooledActor>())
    {
        Cast<IObjectPooledActor>(Object)->ActivateFromPool();

        Object->SetActorHiddenInGame(false);
        Object->SetActorEnableCollision(true);

        return Object;
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Object should inherit from IObjectPooledActor!"));
        }

        PoolArray.Push(Object); //Return it to the pool since we cant use it

        return nullptr;
    }
}

void UGoblinGameObjectPool::ReturnObjectToPool(AActor* PooledObject)
{
    if (!PooledObject)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Returned Pooled Object is null!"));
        }
        return;
    }

    UClass* ObjectClass = PooledObject->GetClass();
    if (!PooledObjects.Contains(ObjectClass))
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Object Pool does not contain this class type!: ") + ObjectClass->GetAuthoredName());
        }
        return;
    }

    if(PooledObject->Implements<UObjectPooledActor>())
    {
        Cast<IObjectPooledActor>(PooledObject)->ReturnToPool();
    }

    TArray<AActor*>& PoolArray = PooledObjects[ObjectClass];

    PooledObject->SetActorHiddenInGame(true);
    PooledObject->SetActorEnableCollision(false);

    PoolArray.Push(PooledObject);
}
