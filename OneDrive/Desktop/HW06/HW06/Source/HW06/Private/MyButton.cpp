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
	// �÷��̾����� Ȯ��
	if (OtherActor && OtherActor->IsA(APawn::StaticClass()))
	{
		// 2�� �Ŀ� �����
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
	SetActorEnableCollision(false);           // �浹 ��Ȱ��ȭ
	SetActorHiddenInGame(true);				  // ȭ�鿡�� ����
	GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &AMyButton::AppearButton, 5.0f, false);
}

void AMyButton::AppearButton()
{
	SetActorHiddenInGame(false);              // �ٽ� ���̱�
	SetActorEnableCollision(true);			//�浹 Ȱ��ȭ
}

