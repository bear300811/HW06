#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyButton.generated.h"

UCLASS()
class HW06_API AMyButton : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMyButton();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Button|Components")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category ="Button|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Button|Collision")
	UBoxComponent* TriggerBox;

protected:
	
	virtual void BeginPlay() override;


	FTimerHandle DisappearTimerHandle;
	FTimerHandle RespawnTimer;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	void DisappearButton();

	UFUNCTION()
	void AppearButton();
	

};
