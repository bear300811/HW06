#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bridge.generated.h"

UCLASS()
class HW06_API ABridge : public AActor
{
	GENERATED_BODY()
	
public:	

	ABridge();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bridge|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bridge|Properies")
	float RotationSpeed;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
