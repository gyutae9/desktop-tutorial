

#include "RotateActor.h"

ARotateActor::ARotateActor()
{
	SceneRootR = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRootR);

	StaticMeshCompR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshCompR->SetupAttachment(SceneRootR);

	// '/Game/Resources/Props/SM_Star_B.SM_Star_B'
	// '/Game/Resources/Materials/M_Gem_A.M_Gem_A'

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshCompR->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Gem_A.M_Gem_A"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshCompR->SetMaterial(0, MaterialAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f; // 기본 회전 속도 설정


}

void ARotateActor::BeginPlay()
{
	Super::BeginPlay();

	
	

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));

	//FVector NewLocation(300.0f, 200.0f, 100.0f);
	//FRotator NewRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f);

	//FTransform NewTrnasform( NewRotation, NewScale, NewLocation);   다른방법

	//SetActorTransform(NweTrnasform);

}

// Called every frame
void ARotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)) {

		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));

	}


}

