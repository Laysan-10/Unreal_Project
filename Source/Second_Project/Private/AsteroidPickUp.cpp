// Fill out your copyright notice in the Description page of Project Settings.


//#include "AsteroidPickUp.h"
#include "Second_Project/Public/AsteroidPickUp.h"

AsteroidPickUp::AsteroidPickUp()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AsteroidPickUp::BeginPlay()
{
	Super::BeginPlay();
	PickUpMeshComponent->SetSimulatePhysics(false);
}
void AsteroidPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
