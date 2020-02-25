// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "CustomDataTables.h"
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
	void Construct(const FArguments& InArgs, const FTextRunInfo& RunInfo,const FText Ruby,const FText Body, FRubyTextFontData RubyFont, FRubyTextFontData BodyFont);
private:
	class UDataTable* RubyFont;
};
