// Copyright N.Shepard

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
public: //TODO remove or create getter

	UPROPERTY(EditInstanceOnly, Category = "Patrol Routes")
		TArray<AActor*> PatrolPointsCPP;
};
