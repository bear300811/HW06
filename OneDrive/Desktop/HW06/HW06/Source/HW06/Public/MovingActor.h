#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()

public:

	AMovingActor();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovingActor|Properies")
	float MoveSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MovingActor|Properies")
	FVector MaxRange{ 1450.0f, 0.0f, 0.0f };
	
	FVector StartLocation;
	bool MovingForward = true;

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
