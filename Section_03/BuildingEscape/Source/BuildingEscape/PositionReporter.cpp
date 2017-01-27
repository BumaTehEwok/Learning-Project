// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "PositionReporter.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{

	Super::BeginPlay();
	//AActor* actor = GetOwner();
	FString ownerName = GetOwner()->GetName();
	FVector ownerVector = GetOwner()->GetActorLocation();
	FString message = "Location of " + ownerName +" X: " + FString::SanitizeFloat(ownerVector.X) + " Y: " + FString::SanitizeFloat(ownerVector.Y) + " : " + FString::SanitizeFloat(ownerVector.Y);
	UE_LOG(LogTemp, Warning, TEXT("%s"),*message);
}


// Called every frame
void UPositionReporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	//FMath::VInterpTo();
	// ...
}

