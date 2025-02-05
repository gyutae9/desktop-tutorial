
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"


UCLASS()
class JUMPMAP_API ARotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotateActor();

protected:
	USceneComponent* SceneRootR;
	UStaticMeshComponent* StaticMeshCompR;
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 90.0f;



};
