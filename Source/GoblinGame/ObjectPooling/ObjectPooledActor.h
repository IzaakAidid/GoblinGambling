// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectPooledActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UObjectPooledActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GOBLINGAME_API IObjectPooledActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

    virtual void ActivateFromPool() = 0;

    virtual void ReturnToPool() = 0;
};
