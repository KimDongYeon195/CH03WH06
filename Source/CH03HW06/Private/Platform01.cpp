// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform01.h"


APlatform01::APlatform01()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	///Script/Engine.StaticMesh'/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	/// Script / Engine.Material'/Game/Resources/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	RotationSpeed = 90.f; // 0.016s 언저리 * 90 == 1s 언저리
}


void APlatform01::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Start RotateFlatform ")); //회전플랫폼 시작 확인
	SetActorLocation(StartLocation);
	
	
	SetActorScale3D(FVector(1.5f));
}

void APlatform01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, RotationSpeed * DeltaTime));
		UE_LOG(LogTemp, Warning, TEXT("Rotaion at Tick")); //Tick에서 회전하는지 확인
	}
}

