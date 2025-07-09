#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Roll.generated.h"

UCLASS()
class HW06_API ARoll : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARoll();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Roll|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Roll|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Roll|Properies")
	float RotationSpeed;
	
	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaTime) override;

};
