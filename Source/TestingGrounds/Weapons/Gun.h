// Copyright N.Shepard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TESTINGGROUNDS_API AGun : public AActor
{
	GENERATED_BODY()

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* VR_MuzzleLocation;
	
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	AGun();

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** AnimMontages to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation3P;

	class UAnimInstance* AnimInstance1P;

	class UAnimInstance* AnimInstance3P;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		uint32 bUsingMotionControllers : 1;

	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void OnFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};