// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../GeneralGame/GoblinGamblingEnums.h"
#include "CasinoDealer.generated.h"

class UBoxComponent;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* DealerMesh;

	//TEMP - REMOVE LATER WHEN A SKELETAL MESH IS CREATED
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMeshComponent* TEMP_DealerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UBoxComponent* InteractionCollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wallet)
	class UGoblinWalletComponent* DealerWallet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wallet)
	ECasinoChipsType CasinoChipsType;

#pragma region Functions

	void ConvertBucksToChips(int BucksToConvert, UGoblinWalletComponent* pPlayerWallet);
	void ConvertChipsToBucks(int ChipsToConvert, UGoblinWalletComponent* pPlayerWallet);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

#pragma endregion

#pragma region Member Variables	

#pragma endregion
};