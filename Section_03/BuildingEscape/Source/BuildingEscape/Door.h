// Copy Right Adam Hummel 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Door.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this component's properties
	UDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
private:
	AActor *Owner;
	void OpenDoorForward();
	void CloseDoor();
	void OpenDoorBackward();
	
};
