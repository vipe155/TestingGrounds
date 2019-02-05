// Copyright N.Shepard

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BoundsPool")
		void PopulateBoundsVolumePool();
private:
	void AddtoPool(class ANavMeshBoundsVolume *VolumeToAdd);
	
	
};
