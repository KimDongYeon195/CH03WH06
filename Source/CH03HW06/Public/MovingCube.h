// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"
//이동 장애물
UCLASS()
class CH03HW06_API AMovingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMovingCube();

protected:
	
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube|MoveSpeed")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube|MoveRange")
	float MaxRange;
	
	FVector StartLocation;
public:	
	
	virtual void Tick(float DeltaTime) override;

};
