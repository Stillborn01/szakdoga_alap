// Copyright by Nagy Dávid 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EAimingStatus : uint8 {
	Reloading,
	Aiming,
	Locked
};


// Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds Barrel parameters
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EAimingStatus AimingState = EAimingStatus::Reloading;

	FVector AimDirection;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



private:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> Projectile_BP;

	double LastFireTime = 0;
};
