

#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{    

	SceneRootM = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRootM);

	StaticMeshCompM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshCompM->SetupAttachment(SceneRootM);


    //'/Game/Resources/Shapes/Shape_Pipe_90.Shape_Pipe_90'

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe_90.Shape_Pipe_90"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshCompM->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Basic_Floor.M_Basic_Floor"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshCompM->SetMaterial(0, MaterialAsset.Object);
	}
	
	PrimaryActorTick.bCanEverTick = true;
	StartLocation = FVector(1400.0f, -10.0f, 202.0f);
	MovementSpeed = FVector(10.0f, 0.0f, 0.0f);
	MovementRange = 10.0f;
	
}


void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMoveActor::TimerFunction, TimeLimit, false);
	

}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!HasActorBegunPlay()) return;

	// 위치 계산
	RunningTime += DeltaTime;
	FVector NewLocation = StartLocation + MovementSpeed * FMath::Sin(RunningTime * PI) * MovementRange;
	SetActorLocation(NewLocation);


}

void AMoveActor::TimerFunction()
{
	Destroy(); // 타이머가 끝나면 액터 제거
}

