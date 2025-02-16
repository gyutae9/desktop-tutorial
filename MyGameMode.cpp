// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "SpartaGameState.h"


AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();

	GameStateClass = ASpartaGameState::StaticClass();
}