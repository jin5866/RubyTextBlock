// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "Slate.h"
/**
 * 
 */
class HELLOSLATE_API SRubyTextSlate : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRubyTextSlate)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs,const FString* Ruby,FText Body);
};
