#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bridge1.generated.h"

UCLASS()
class HW06_API ABridge1 : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABridge1();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bridge1|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge1|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bridge1|Properies")
	
	float RotationSpeed;


protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
