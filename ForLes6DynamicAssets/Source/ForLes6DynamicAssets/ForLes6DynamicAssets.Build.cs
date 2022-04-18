// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ForLes6DynamicAssets : ModuleRules
{
	public ForLes6DynamicAssets(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
