// Copyright N.Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UE4ASP_Character.generated.h"

UCLASS()
class TESTINGGROUNDS_API AUE4ASP_Character : public ACharacter
{
	GENERATED_BODY()

UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
class USkeletalMeshComponent* Mesh_1P;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
class UCameraComponent* FP_Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AUE4ASP_Character();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<class AGun> GunBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PullTrigger();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	AGun* Gun;
};
