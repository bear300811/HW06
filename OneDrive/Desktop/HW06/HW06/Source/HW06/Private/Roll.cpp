#include "Roll.h"


ARoll::ARoll()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void ARoll::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	
}

void ARoll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
	}

}

