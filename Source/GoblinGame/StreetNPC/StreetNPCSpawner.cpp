// Fill out your copyright notice in the Description page of Project Settings.


#include "../StreetNPC/StreetNPCSpawner.h"
#include "Components/BoxComponent.h"
#include "../StreetNPC/StreetNPC_Base.h"
#include "../ObjectPooling/GoblinGameObjectPool.h"

// Sets default values
AStreetNPCSpawner::AStreetNPCSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    bNetLoadOnClient = false; // keeps this server only

    SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
    SpawnArea->SetupAttachment(RootComponent);

    DespawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("DespawnArea"));
    DespawnArea->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AStreetNPCSpawner::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetSubsystem<UGoblinGameObjectPool>()->AddCollectionToPool(NPCToSpawn, NPCsToPool);
	
    SpawnTimer = SpawnDelay + FMath::RandRange(-SpawnDeviation, SpawnDeviation);

    DespawnArea->OnComponentBeginOverlap.AddDynamic(this, &AStreetNPCSpawner::OnOverlapBegin);
}

// Called every frame
void AStreetNPCSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    SpawnTimer -= DeltaTime;

    if (SpawnTimer <= 0.0f)
    {
        SpawnStreetNPC();
        SpawnTimer = SpawnDelay + FMath::RandRange(-SpawnDeviation, SpawnDeviation);
    }
}

void AStreetNPCSpawner::SpawnStreetNPC()
{
    AActor* NPC = GetWorld()->GetSubsystem<UGoblinGameObjectPool>()->GetPooledObject(NPCToSpawn);

    if (!NPC)
        return;

    NPC->SetActorLocationAndRotation(
        SpawnArea->GetComponentLocation() + FVector(
            FMath::RandRange(-SpawnArea->GetScaledBoxExtent().X, SpawnArea->GetScaledBoxExtent().X),
            FMath::RandRange(-SpawnArea->GetScaledBoxExtent().Y, SpawnArea->GetScaledBoxExtent().Y),
            0.0f),
        SpawnArea->GetComponentRotation()
    );

    if (AStreetNPC_Base* NPCBase = Cast<AStreetNPC_Base>(NPC))
        NPCBase->SetDespawnPoint(DespawnArea->GetComponentLocation());
}

void AStreetNPCSpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (Cast<AStreetNPC_Base>(OtherActor))
    {
        GetWorld()->GetSubsystem<UGoblinGameObjectPool>()->ReturnObjectToPool(OtherActor);
    }
}