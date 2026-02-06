// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GoblinGame : ModuleRules
{
	public GoblinGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "AIModule" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] { "GoblinGame", "GoblinGame/Currency", "GoblinGame/Gambling", "GoblinGame/GeneralGame", "GoblinGame/ObjectPooling", "GoblinGame/Player",
            "GoblinGame/StreetNPC", "GoblinGame/UI", "GoblinGame/Gambling/Blackjack"
            });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
