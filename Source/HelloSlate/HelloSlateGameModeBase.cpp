// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloSlateGameModeBase.h"

#include "StandardHUD.h"

AHelloSlateGameModeBase::AHelloSlateGameModeBase() : Super()
{
	HUDClass = AStandardHUD::StaticClass();
}