#include "Panel.h"


APanel::APanel()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 360.0f;
}


void APanel::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
}

void APanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, 0.0f, RotationSpeed * DeltaTime));
	}
}

