// Fill out your copyright notice in the Description page of Project Settings.


#include "Second_Project/Public/Spawner/AsteroidSpawner.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Second_Project/Public/PickUpBase.h"



// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Area"));
	
	MinSpawnDelay = 0.5f;
	MaxSpawnDelay = 2.5f;
}

// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();
	StartSpawnTimer();
	
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AAsteroidSpawner::GetRandomSpawnPrint()
{
	const FVector SpawnOrigin = SpawnArea->Bounds.Origin;
	const FVector SpawnLimits = SpawnArea->Bounds.BoxExtent;
	
	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimits);
}

void AAsteroidSpawner::SpawnActor()
{
	if (!ActorToSpawn || !GetWorld())
	{
		return;
	}
	
	FActorSpawnParameters Parameters;
	Parameters.Owner = this;
	Parameters.Instigator = GetInstigator();
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	APickUpBase* SpawnedActor = GetWorld()->SpawnActor<APickUpBase>(ActorToSpawn, GetRandomSpawnPrint(), UKismetMathLibrary::RandomRotator(), Parameters);
	StartSpawnTimer();
}

void AAsteroidSpawner::StartSpawnTimer()
{
	RandomSpawnDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this,&AAsteroidSpawner::SpawnActor,RandomSpawnDelay,false);
}
