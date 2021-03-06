// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Example.generated.h"

USTRUCT()
struct FExampleStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	float Var1;

	UPROPERTY(EditDefaultsOnly)
	float Var2;

	UPROPERTY(EditDefaultsOnly)
	float Var3;

	UPROPERTY(EditDefaultsOnly)
	float Var4;
};

UCLASS(Blueprintable)
class DETAILCUSTOMIZATION_API UExample : public UObject
{
	GENERATED_BODY()

public:
	UExample();

	// We will try and display this in a nice readable way
	// If we mark this as a uproperty it will come out ugly
	TMap<FName, FExampleStruct> ExampleMap;
};
