// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "StreetNPC_Controller.generated.h"

/**
 * 
 */
UCLASS()
class GOBLINGAME_API AStreetNPC_Controller : public AAIController
{
	GENERATED_BODY()

public:

	void PauseBehaviorTree();

	void StartBehaviorTree();
	
};
