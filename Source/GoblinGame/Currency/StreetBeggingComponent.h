// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StreetBeggingComponent.generated.h"

class USphereComponent;
class UGoblinWalletComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOBLINGAME_API UStreetBeggingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStreetBeggingComponent();

protected:

    USphereComponent* BeggingRadiusComponent;

	UGoblinWalletComponent* PlayerWallet;

public:	

	void InitBeggingComponent(USphereComponent* StreetBeggingRadius, UGoblinWalletComponent* wallet);

    void ActivateBegging();
    void DeactivateBegging();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
