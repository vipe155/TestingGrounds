// Copyright N.Shepard

#include "InfiniteTerrainGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddtoPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddtoPool(ANavMeshBoundsVolume * VolumeToAdd)
{
	UE_LOG(LogTemp, Warning, TEXT("Found Volume %s"), *VolumeToAdd->GetName());
}
