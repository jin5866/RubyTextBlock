// Fill out your copyright notice in the Description page of Project Settings.


#include "SRubyTextSlate.h"
#include "SlateOptMacros.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Runtime/Engine/Classes/Engine/Engine.h" 


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SRubyTextSlate"

void SRubyTextSlate::Construct(const FArguments& InArgs, const FTextRunInfo& RunInfo, const FText RubyText, const FText BodyText, FRubyTextFontData RubyFontInfo, FRubyTextFontData BodyFontInfo)
{
	/*
	if (RubyFontT) 
	{
		RubyFont = RubyFontT;
	}
	else
	{
		RubyFont = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Game/RubyTextFont")));
	}*/

	//FRubyTextFontData* RubyFontRow = RubyFont;
	//FRubyTextFontData * BodyFontRow = BodyFont;

	


	FMargin rubyPadding = RubyFontInfo.textPadding;
	FMargin bodyPadding = BodyFontInfo.textPadding;

	FSlateFontInfo rubyFont = RubyFontInfo.font;
	FSlateFontInfo bodyFont = BodyFontInfo.font;

	FSlateColor rubyColor = RubyFontInfo.color;
	FSlateColor bodyColor = BodyFontInfo.color;

	//font style

	if (const FString* rubystyle = RunInfo.MetaData.Find(TEXT("ruby_style")))
	{
		rubyFont.TypefaceFontName = FName(**rubystyle);
	}

	if (const FString * bodystyle = RunInfo.MetaData.Find(TEXT("body_style")))
	{
		bodyFont.TypefaceFontName = FName(**bodystyle);
	}

	//color

	if (const FString * rubycolor = RunInfo.MetaData.Find(TEXT("ruby_color")))
	{
		rubyColor = FSlateColor(FColor::FromHex(*rubycolor));
	}

	if (const FString * bodycolor = RunInfo.MetaData.Find(TEXT("body_color")))
	{
		bodyColor = FSlateColor(FColor::FromHex(*bodycolor));
	}

	//size

	if (const FString * rubysize = RunInfo.MetaData.Find(TEXT("ruby_size")))
	{
		rubyFont.Size = FCString::Atoi(**rubysize);
	}

	if (const FString * bodysize = RunInfo.MetaData.Find(TEXT("body_size")))
	{
		bodyFont.Size = FCString::Atoi(**bodysize);
	}

	// padding

	if (const FString * rubytop = RunInfo.MetaData.Find(TEXT("ruby_top")))
	{
		rubyPadding.Top = FCString::Atof(**rubytop);
	}

	if (const FString * rubybottom = RunInfo.MetaData.Find(TEXT("ruby_bottom")))
	{
		rubyPadding.Bottom = FCString::Atof(**rubybottom);
	}

	if (const FString * rubyright = RunInfo.MetaData.Find(TEXT("ruby_right")))
	{
		rubyPadding.Right = FCString::Atof(**rubyright);
	}

	if (const FString * rubyleft = RunInfo.MetaData.Find(TEXT("ruby_left")))
	{
		rubyPadding.Left = FCString::Atof(**rubyleft);
	}

	if (const FString * bodytop = RunInfo.MetaData.Find(TEXT("body_top")))
	{
		bodyPadding.Top = FCString::Atof(**bodytop);
	}

	if (const FString * bodybottom = RunInfo.MetaData.Find(TEXT("body_bottom")))
	{
		bodyPadding.Bottom = FCString::Atof(**bodybottom);
	}

	if (const FString * bodyright = RunInfo.MetaData.Find(TEXT("body_right")))
	{
		bodyPadding.Right = FCString::Atof(**bodyright);
	}

	if (const FString * bodyleft = RunInfo.MetaData.Find(TEXT("body_left")))
	{
		bodyPadding.Left = FCString::Atof(**bodyleft);
	}

	//FLinearColor rubyShadowColor = RubyFontInfo.shadowColor;
	//FLinearColor bodyShadowColor = BodyFontInfo.shadowColor;

	//Supported formats are: RGB, RRGGBB, RRGGBBAA, RGB, #RRGGBB, #RRGGBBAA
	FSlateColor a = FSlateColor(FColor::FromHex("#aaaaaa"));

	//FVector2D 


	ChildSlot
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(rubyPadding)
			[
				// Ruby Text Block
				SNew(STextBlock)
				//.Font(tmp)
				.Font(rubyFont)
				.Text(RubyText)
				.ColorAndOpacity(rubyColor)
				.ShadowColorAndOpacity(RubyFontInfo.shadowColor)
				.ShadowOffset(RubyFontInfo.shadowOffset)
				//.StrikeBrush(&(RubyFont.brush))
				
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(bodyPadding)
			[
				// body text block
				SNew(STextBlock)
				.Font(bodyFont)
				.Text(BodyText)
				.ColorAndOpacity(bodyColor)
				.ShadowColorAndOpacity(BodyFontInfo.shadowColor)
				.ShadowOffset(BodyFontInfo.shadowOffset)
				//.StrikeBrush(&(BodyFont.brush))
			]
		];
}



#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
