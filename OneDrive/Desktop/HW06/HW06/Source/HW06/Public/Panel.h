#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Panel.generated.h"

UCLASS()
class HW06_API APanel : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APanel();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Panel|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Panel|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Panel|Properies")
	float RotationSpeed;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
