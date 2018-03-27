// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class StrikeVR_17EditorTarget : TargetRules
{
	public StrikeVR_17EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "StrikeVR_17" } );
	}
}
