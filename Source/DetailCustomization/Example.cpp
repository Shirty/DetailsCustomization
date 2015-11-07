// Fill out your copyright notice in the Description page of Project Settings.

#include "DetailCustomization.h"
#include "RandomStream.h"
#include "Example.h"

UExample::UExample()
{
	FString BaseName(TEXT("Example"));
	FRandomStream Rand;

	for (int i = 0; i < 10; i++)
	{
		FString StructName = BaseName + FString::FromInt(i);
		ExampleMap.Add(*StructName);
		ExampleMap[*StructName].Var1 = Rand.FRand();
		ExampleMap[*StructName].Var2 = Rand.FRand();
		ExampleMap[*StructName].Var3 = Rand.FRand();
		ExampleMap[*StructName].Var4 = Rand.FRand();
	}
}




