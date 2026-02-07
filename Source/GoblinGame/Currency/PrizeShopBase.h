// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../GeneralGame/GoblinGamblingEnums.h"
#include "../GeneralGame/InteractableObject.h"
#include "PrizeShopBase.generated.h"

UCLASS()
class GOBLINGAME_API APrizeShopBase : public AActor, public IInteractableObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APrizeShopBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* PrizeShopAttendantMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMeshComponent* PrizeShopWallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wallet)
	ECasinoChipsType CasinoChipsType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wallet)
	TArray<class UPrizeBaseComponent*> PrizeArray;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


#pragma region Functions

	virtual void Interact_Implementation(AGoblinGambline_PlayerBase* Player) override;

#pragma endregion
};
