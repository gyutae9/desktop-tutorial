

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class JUMPMAP_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMoveActor();

protected:

	virtual void Tick(float DeltaTime) override;
	USceneComponent* SceneRootM;
	UStaticMeshComponent* StaticMeshCompM;
	
	virtual void BeginPlay() override;
	// 이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MovementSpeed;

	// 이동 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementRange;

	UFUNCTION()
	void TimerFunction();


private:	
	
	
	FVector StartLocation;
	float RunningTime;

	 FTimerHandle TimerHandle;

    UPROPERTY(EditAnywhere, Category = "Timer")
    float TimeLimit = 5.0f;

};
