// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForLes6DynamicAssetsGameMode.h"
#include "ForLes6DynamicAssetsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AForLes6DynamicAssetsGameMode::AForLes6DynamicAssetsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
