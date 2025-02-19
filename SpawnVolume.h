// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"
#include "SpawnVolume.generated.h"


class UBoxComponent;

UCLASS()
class JUMPMAP_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:
    ASpawnVolume();
   
    

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    USceneComponent* Scene;
    // 스폰 영역을 담당할 박스 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    UDataTable* ItemDataTable;

    // 스폰 볼륨 내부에서 무작위 좌표를 얻어오는 함수
    UFUNCTION(BlueprintCallable, Category = "Spawning")
    FVector GetRandomPointInVolume() const;
    FItemSpawnRow* GetRandomItem() const;
    AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
    AActor* SpawnRandomItem(); // 리턴 형식을 AActor* 로 변경
    
};
