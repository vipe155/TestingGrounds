// Copyright N.Shepard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
 * Route card to help AI choose next waypoint
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*>GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Routes")
		TArray<AActor*> PatrolPoints;

};