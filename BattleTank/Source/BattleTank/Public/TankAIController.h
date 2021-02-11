// Copyright by Nagy Dávid 2021

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
    virtual void Tick(float DeltaTime) override;

    virtual void BeginPlay() override;

	float AcceptanceRadius = 3000;
};
