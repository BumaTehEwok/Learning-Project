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
	//OpenDoorForward();
	// ...
	
}


// Called every frame
void UDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoorForward();
	}
	else
	{
		CloseDoor();
	}
	// ...
}

void UDoor::OpenDoorForward()
{
	FRotator ActorRotation = Owner->GetActorRotation();
	
	ActorRotation.Yaw = OpenRotation;
	Owner->SetActorRotation(ActorRotation);
}
void UDoor::CloseDoor()
{
	FRotator ActorRotation = Owner->GetActorRotation();
	ActorRotation.Yaw = 0;
	Owner->SetActorRotation(ActorRotation);
}
void UDoor::OpenDoorBackward()
{
	FRotator ActorRotation = Owner->GetActorRotation();
	ActorRotation.Yaw = -90;
	Owner->SetActorRotation(ActorRotation);
}
