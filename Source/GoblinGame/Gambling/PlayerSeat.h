// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../GeneralGame/InteractableObject.h"
#include "PlayerSeat.generated.h"

class UStaticMeshComponent;
class UArrowComponent;
class APlayerHand;

UCLASS()
class GOBLINGAME_API APlayerSeat : public AActor, public IInteractableObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerSeat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	UArrowComponent* ArrowComponent;

	UPROPERTY(Replicated)
	bool bIsOccupied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerHand* PlayerHandActor;

public:	

    virtual void Interact_Implementation(AGoblinGambline_PlayerBase* Player) override;

	void EmptySeat();

};
