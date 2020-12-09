// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SIMPLESHOOTERWORKING_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// the basic collision
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Collision")
	class USphereComponent* CollisionVolume;

	// The mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Mesh")
		class UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//overlap end
	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
