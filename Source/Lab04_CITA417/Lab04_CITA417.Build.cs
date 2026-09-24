// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lab04_CITA417 : ModuleRules
{
	public Lab04_CITA417(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Lab04_CITA417",
			"Lab04_CITA417/Variant_Platforming",
			"Lab04_CITA417/Variant_Platforming/Animation",
			"Lab04_CITA417/Variant_Combat",
			"Lab04_CITA417/Variant_Combat/AI",
			"Lab04_CITA417/Variant_Combat/Animation",
			"Lab04_CITA417/Variant_Combat/Gameplay",
			"Lab04_CITA417/Variant_Combat/Interfaces",
			"Lab04_CITA417/Variant_Combat/UI",
			"Lab04_CITA417/Variant_SideScrolling",
			"Lab04_CITA417/Variant_SideScrolling/AI",
			"Lab04_CITA417/Variant_SideScrolling/Gameplay",
			"Lab04_CITA417/Variant_SideScrolling/Interfaces",
			"Lab04_CITA417/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
