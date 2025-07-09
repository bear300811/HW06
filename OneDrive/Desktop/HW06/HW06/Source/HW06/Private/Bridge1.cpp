#include "Bridge1.h"


ABridge1::ABridge1()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 40.0f;
}


void ABridge1::BeginPlay()
{
	Super::BeginPlay();
		
}


void ABridge1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!FMath::IsNearlyZero(RotationSpeed))
	{
		FRotator RotationDelta(0.0f, RotationSpeed * DeltaTime, 0.0f);
		AddActorLocalRotation(RotationDelta);
	}

}

