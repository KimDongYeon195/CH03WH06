// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform01.generated.h"
//회전 플랫폼
UCLASS()
class CH03HW06_API APlatform01 : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APlatform01();

protected:
	
	virtual void BeginPlay() override;

	
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform01|RotationSpeed")
	float RotationSpeed;

	FVector StartLocation;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
