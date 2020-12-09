// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterWorkingGameModeBase.h"
// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationRate = 500.f;
	MaxHealth = 100.f;
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
	// Yo world get me something
	CurrentGun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	CurrentGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	CurrentGun->SetOwner(this);
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0;
}

float AShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);

	// Actions
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Shoot);

	PlayerInputComponent->BindAction(TEXT("Reload"), EInputEvent::IE_Pressed, this, &AShooterCharacter::CharacterReload);
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageApplied = FMath::Min(Health, DamageApplied);
	Health -= DamageApplied;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	if (IsDead())
	{
		ASimpleShooterWorkingGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterWorkingGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	return DamageApplied;
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}


void AShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShooterCharacter::LookUpRate(float AxisRate)
{
	AddControllerPitchInput(AxisRate * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookRightRate(float AxisRate)
{
	AddControllerYawInput(AxisRate * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::Shoot()
{
	CurrentGun->PullTrigger();
}

void AShooterCharacter::CharacterReload()
{
	CurrentGun->Reload();
}



void AShooterCharacter::IncrementHealth(float Amount)
{
	if (Health + Amount >= MaxHealth)
	{
		Health = MaxHealth;
	}
	else
	{
		Health += Amount;
	}
}