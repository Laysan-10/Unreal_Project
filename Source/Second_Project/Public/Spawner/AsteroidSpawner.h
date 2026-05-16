// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Second_Project/Public/PickUpBase.h"
#include "Components/BoxComponent.h"

#include "AsteroidSpawner.generated.h"


UCLASS()
class SECOND_PROJECT_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsteroidSpawner();
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawner")
	UBoxComponent* SpawnArea;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<APickUpBase> ActorToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float MinSpawnDelay;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float MaxSpawnDelay;
	
	FTimerHandle SpawnTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintPure, Category = "Spawner")
	FVector GetRandomSpawnPrint();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	void SpawnActor();
	
	void StartSpawnTimer();
	
	float RandomSpawnDelay;
	

};
