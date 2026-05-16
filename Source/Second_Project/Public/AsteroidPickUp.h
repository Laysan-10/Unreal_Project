// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpBase.h"
#include "GameFramework/Actor.h"
#include "AsteroidPickUp.generated.h"
/**
 * 
 */
UCLASS()
class SECOND_PROJECT_API AsteroidPickUp : public APickUpBase
{
	GENERATED_BODY()
public:
	AsteroidPickUp();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
};
