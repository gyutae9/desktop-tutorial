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
    // ���� ������ ����� �ڽ� ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    UDataTable* ItemDataTable;

    // ���� ���� ���ο��� ������ ��ǥ�� ������ �Լ�
    UFUNCTION(BlueprintCallable, Category = "Spawning")
    FVector GetRandomPointInVolume() const;
    FItemSpawnRow* GetRandomItem() const;
    AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
    AActor* SpawnRandomItem(); // ���� ������ AActor* �� ����
    
};
