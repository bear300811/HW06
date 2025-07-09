#include "MovingActor.h"


AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 40.0f;
	
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	if (MovingForward)
	{
		if (CurrentLocation.X <= MaxRange.X)
		{
			FVector NewLocation = CurrentLocation + FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f);
			SetActorLocation(NewLocation);
		}
		else
		{
			MovingForward = false;
		}
	}
	else 
	{
		if (CurrentLocation.X >= StartLocation.X)
		{
			FVector NewLocation = CurrentLocation - FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f);
			SetActorLocation(NewLocation);
		}
		else
		{
			MovingForward = true;
		}
	}
}

