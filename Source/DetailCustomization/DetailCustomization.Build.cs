// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DetailCustomization : ModuleRules
{
	public DetailCustomization(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(
            new string[] {
				"Core",
				"CoreUObject",
				"EditorStyle",
				"Engine",
				"PropertyEditor",
                "AssetRegistry",
                "SlateCore",
                "Slate"
            }
        );
	}
}
