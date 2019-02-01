// Copyright N.Shepard

#include "UE4ASP_Character.h"
#include "../Weapons/Gun.h"
#include "Classes/Components/SkeletalMeshComponent.h"
#include "Classes/Components/CapsuleComponent.h"
#include "Classes/Camera/CameraComponent.h"

// Sets default values
AUE4ASP_Character::AUE4ASP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera component
	FP_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FP_Camera->SetupAttachment(GetCapsuleComponent());
	FP_Camera->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);  // position camera
	FP_Camera->bUsePawnControlRotation = true;

	// Create arm mesh component for 1st person view
	Mesh_1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh_1P"));
	Mesh_1P->SetOnlyOwnerSee(true);
	Mesh_1P->SetupAttachment(FP_Camera);
	Mesh_1P->bCastDynamicShadow = false;
	Mesh_1P->CastShadow = false;
	Mesh_1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh_1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
}

// Called when the game starts or when spawned
void AUE4ASP_Character::BeginPlay()
{
	Super::BeginPlay();

	if (GunBlueprint == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing"));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	Gun->AttachToComponent(Mesh_1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance = GetMesh()->GetAnimInstance();

	if (InputComponent != NULL) {
		InputComponent->BindAction("Fire", IE_Pressed, this, &AUE4ASP_Character::PullTrigger);
	}
}

// Called every frame
void AUE4ASP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUE4ASP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void AUE4ASP_Character::PullTrigger()
{
	Gun->OnFire();
}

