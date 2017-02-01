// Copy Right Adam Hummel 2017

#include "BuildingEscape.h"
#include "Door.h"


// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Owner = GetOwner();
		// ...
}


// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	ClosedRotation = Owner->GetActorRotation().Yaw;
	OpenRotation = ClosedRotation + OpenRotation;
		
}


// Called every frame
void UDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(OpenRotation);
	}
	else
	{
		CloseDoor();
	}
	// ...
}

void UDoor::OpenDoor(float Rotation)
{
	if (!IsLocked && Owner->GetActorRotation().Yaw != Rotation)
	{
		
		FRotator ActorRotation = Owner->GetActorRotation();
		ActorRotation.Yaw = Rotation;
		Owner->SetActorRotation(ActorRotation);
	}
}
void UDoor::CloseDoor()
{
	if (!IsLocked && Owner->GetActorRotation().Yaw != ClosedRotation)
	{
		FRotator ActorRotation = Owner->GetActorRotation();
		ActorRotation.Yaw = ClosedRotation;
		Owner->SetActorRotation(ActorRotation);
	}
}
