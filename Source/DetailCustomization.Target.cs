using UnrealBuildTool;
using System.Collections.Generic;

class DetailCustomizationTarget : TargetRules
{
	public DetailCustomizationTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.Add("DetailCustomization");
	}

}