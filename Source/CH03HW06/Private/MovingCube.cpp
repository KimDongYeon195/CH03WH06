// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"


AMovingCube::AMovingCube()
{

	PrimaryActorTick.bCanEverTick = true;

	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	///Script/Engine.StaticMesh'/Game/Resources/Shapes/Shape_Cube.Shape_Cube'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	//Script/Engine.Material'/Game/Resources/Materials/M_Barrel.M_Barrel'
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Barrel.M_Barrel"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	MoveSpeed = 200.f;
	MaxRange = 300.f;

}


//StartLocation 시작위치 
//MoveSpeed 이동속도
//MaxRange

void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Start MovingCube")); //이상없이 시작하는지 로그 찍어보기
	StartLocation = GetActorLocation();

	SetActorScale3D(FVector(2.0f));
}

void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.f));
	UE_LOG(LogTemp, Warning, TEXT("Move at Tick")); //Tick에서 움직이기 시작

	FVector LastLocation = GetActorLocation();
	float Distance = FVector::Dist(StartLocation, LastLocation);
	
	if(Distance >= MaxRange)
		{
			MoveSpeed *=  - 1.f;
		}
	UE_LOG(LogTemp, Warning, TEXT("return at Tick"));  //Tick에서 왕복하는지 확인
}


