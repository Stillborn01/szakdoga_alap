// Copyright by Nagy Dávid 2021

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank; 

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

private:
    ATank* GetControlledTank() const;

    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector& HitLocation) const;

    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation = 0.5f;

    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation = 0.33333f;

    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000.f;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
