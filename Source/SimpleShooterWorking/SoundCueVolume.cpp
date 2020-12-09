// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundCueVolume.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "ShooterCharacter.h"

// Sets default values
ASoundCueVolume::ASoundCueVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SoundTriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SoundCueVolume"));
	RootComponent = SoundTriggerVolume;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ASoundCueVolume::BeginPlay()
{
	Super::BeginPlay();
	
	SoundTriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ASoundCueVolume::OnOverlapBegin);
}

// Called every frame
void ASoundCueVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoundCueVolume::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		AShooterCharacter* PlayerCharacter = Cast<AShooterCharacter>(OtherActor);
		if (PlayerCharacter)
		{
			if (SoundToPlay)
			{
				UGameplayStatics::PlaySound2D(this, SoundToPlay);
			}

			Destroy();
		}
	}
}

