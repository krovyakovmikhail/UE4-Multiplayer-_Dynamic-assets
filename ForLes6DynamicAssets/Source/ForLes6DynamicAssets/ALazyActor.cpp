// Fill out your copyright notice in the Description page of Project Settings.


#include "ALazyActor.h"

#include "MyCharacter.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"


// Sets default values
AALazyActor::AALazyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Body Mesh"));
	BodyMesh->SetupAttachment(RootComponent);
	
	BodyLoadRadius = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger to load mesh"));

}

// Called when the game starts or when spawned
void AALazyActor::BeginPlay()
{
	Super::BeginPlay();
	BodyLoadRadius->OnComponentBeginOverlap.AddDynamic(this, &AALazyActor::BeginOverlap);
}

void AALazyActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (Cast<ACharacter>(OtherActor))
		{
		GEngine->AddOnScreenDebugMessage(10, 2, FColor::Yellow, " BEGIN OVERLAP ");
		
		BodyMesh->SetStaticMesh(LoadBodyMesh());
		
		}
	else
	{
		GEngine->AddOnScreenDebugMessage(10, 10, FColor::Red, " Cast Failed ");
	}
	
	
	
}

// Called every frame
void AALazyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMesh* AALazyActor::LoadBodyMesh()
{

	if (BodyMeshRef.IsPending())
    {
    const FSoftObjectPath& AssetRef = BodyMeshRef.ToStringReference();
    FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
    BodyMeshRef = Cast<UStaticMesh>(StreamableManager.LoadSynchronous(AssetRef));
    }
    return BodyMeshRef.Get();
}

