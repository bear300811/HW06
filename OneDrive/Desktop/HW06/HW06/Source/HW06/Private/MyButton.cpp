#include "MyButton.h"


AMyButton::AMyButton()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox -> SetupAttachment(SceneComp);
	TriggerBox -> SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox -> SetCollisionObjectType(ECC_WorldDynamic);
	TriggerBox -> SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}


void AMyButton::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AMyButton::OnOverlapBegin);
	
}
void AMyButton::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// 플레이어인지 확인
	if (OtherActor && OtherActor->IsA(APawn::StaticClass()))
	{
		// 2초 후에 사라짐
		GetWorld()->GetTimerManager().SetTimer(
			DisappearTimerHandle,
			this,
			&AMyButton::DisappearButton,
			1.0f,
			false
		);
	}
}

void AMyButton :: DisappearButton()
{
	SetActorEnableCollision(false);           // 충돌 비활성화
	SetActorHiddenInGame(true);				  // 화면에서 숨김
	GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &AMyButton::AppearButton, 5.0f, false);
}

void AMyButton::AppearButton()
{
	SetActorHiddenInGame(false);              // 다시 보이기
	SetActorEnableCollision(true);			//충돌 활성화
}

