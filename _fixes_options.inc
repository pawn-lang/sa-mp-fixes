#if !_FIXES_NEW_COMPILER
	// This is the old compiler.  We have to use `#endinput` to hide warnings.
	// This is why the warnings are in a separate (optional) file - just
	// enclosing them in `#if` doesn't work properly (with good reason, the
	// compiler needs to know when to end the `#if`, and if it sees a pre-
	// processor directive it doesn't know, it can't know if it should now end
	// the block or not).  So we have to ensure that the compiler never reaches
	// that line.
	//
	// I considered putting these warnings at the very bottom of the main file
	// and having it recursively include itself.  It would work (probably), but
	// would cause havok with pawndoc comments (which are already a mess) and
	// `#emit` (which also doesn't like being put in `#if`, as the whole file
	// would need to be to make this work).  Plus, having a 20,000+ line file
	// repeatedly include another 20,000+ line file for just five lines of code
	// is truly awful, and I suspect will bring the compiler to a crawl.
	//
	// Do this check before the `_inc__fixes_settings` check so that we utilise
	// the old compiler's in-built compiler guards to avoid including this file
	// multiple times when not needed.
	#endinput
#endif

#if !FIXES_ExplicitOptions
	// Warning about unused settings is disabled.  Do this check before the
	// `_inc__fixes_settings` check so that we utilise the old compiler's
	// in-built compiler guards to avoid including this file multiple times when
	// not needed.
	#endinput
#endif

#if defined _inc__fixes_options
	// Allow this file to be included multiple times.  This line is only hit on
	// the new compiler in compatibility mode.
	#undef _inc__fixes_options
#endif

#if defined _FIXES_OPTION
	// Hide the warning variable so there aren't two.
	#undef _FIXES_OPTION
	#define _FIXES_OPTION stock
#endif

#if !defined _FIXES_WARNING
	#error `_fixes_options.inc` included, but `_FIXES_WARNING` is not defined to select a warning message.
#endif

// Actually show the warnings.
#pragma warning push
#pragma warning enable 237

// The caller always undefines `_FIXES_WARNING` after trying to include this
// file, as it needs to be undefined whether the include worked or not.  Thus we
// can't also undefine it in here, as the sensible option would seem to be, as
// then it will be undefined twice in some situations.
#if _FIXES_WARNING == 1
	#warning Option `FIX_API` must now be explicit.
#elseif _FIXES_WARNING == 2
	#warning Option `FIX_Natives` must now be explicit.
#elseif _FIXES_WARNING == 3
	#warning Option `FIX_GetPlayerColour` must now be explicit.
#elseif _FIXES_WARNING == 4
	#warning Option `FIX_FILTERSCRIPT` must now be explicit.
#elseif _FIXES_WARNING == 5
	#warning Option `FIX_SpawnPlayer` must now be explicit.
#elseif _FIXES_WARNING == 6
	#warning Option `FIX_SetPlayerName` must now be explicit.
#elseif _FIXES_WARNING == 7
	#warning Option `FIX_GetPlayerSkin` must now be explicit.
#elseif _FIXES_WARNING == 8
	#warning Option `FIX_GetWeaponName` must now be explicit.
#elseif _FIXES_WARNING == 9
	#warning Option `FIX_SetPlayerWorldBounds` must now be explicit.
#elseif _FIXES_WARNING == 10
	#warning Option `FIX_TogglePlayerControllable` must now be explicit.
#elseif _FIXES_WARNING == 11
	#warning Option `FIX_HydraSniper` must now be explicit.
#elseif _FIXES_WARNING == 12
	#warning Option `FIX_IsPlayerInCheckpoint` must now be explicit.
#elseif _FIXES_WARNING == 13
	#warning Option `FIX_IsPlayerInRaceCheckpoint` must now be explicit.
#elseif _FIXES_WARNING == 14
	#warning Option `FIX_GetPlayerWeapon` must now be explicit.
#elseif _FIXES_WARNING == 15
	#warning Option `FIX_PutPlayerInVehicle` must now be explicit.
#elseif _FIXES_WARNING == 16
	#warning Option `FIX_KEY_AIM` must now be explicit.
#elseif _FIXES_WARNING == 17
	#warning Option `FIX_SPECIAL_ACTION_PISSING` must now be explicit.
#elseif _FIXES_WARNING == 18
	#warning Option `FIX_IsValidVehicle` must now be explicit.
#elseif _FIXES_WARNING == 19
	#warning Option `FIX_GetGravity` must now be explicit.
#elseif _FIXES_WARNING == 20
	#warning Option `FIX_gpci` must now be explicit.
#elseif _FIXES_WARNING == 21
	#warning Option `FIX_WEAPONS` must now be explicit.
#elseif _FIXES_WARNING == 22
	#warning Option `FIX_BODYPARTS` must now be explicit.
#elseif _FIXES_WARNING == 23
	#warning Option `FIX_CAMERAMODES` must now be explicit.
#elseif _FIXES_WARNING == 24
	#warning Option `FIX_DriveBy` must now be explicit.
#elseif _FIXES_WARNING == 25
	#warning Option `FIX_SilentTeleport` must now be explicit.
#elseif _FIXES_WARNING == 26
	#warning Option `FIX_SetPlayerCheckpoint` must now be explicit.
#elseif _FIXES_WARNING == 27
	#warning Option `FIX_SetPlayerRaceCheckpoint` must now be explicit.
#elseif _FIXES_WARNING == 28
	#warning Option `FIX_TextDrawCreate` must now be explicit.
#elseif _FIXES_WARNING == 29
	#warning Option `FIX_AttachTrailerToVehicle` must now be explicit.
#elseif _FIXES_WARNING == 30
	#warning Option `FIX_GetVehicleComponentInSlot` must now be explicit.
#elseif _FIXES_WARNING == 31
	#warning Option `FIX_TextDrawCreate_2` must now be explicit.
#elseif _FIXES_WARNING == 32
	#warning Option `FIX_TextDrawSetString` must now be explicit.
#elseif _FIXES_WARNING == 33
	#warning Option `FIX_TextDrawSetString_2` must now be explicit.
#elseif _FIXES_WARNING == 34
	#warning Option `FIX_AllowInteriorWeapons` must now be explicit.
#elseif _FIXES_WARNING == 35
	#warning Option `FIX_OnPlayerEnterVehicle` must now be explicit.
#elseif _FIXES_WARNING == 36
	#warning Option `FIX_OnPlayerEnterVehicle_2` must now be explicit.
#elseif _FIXES_WARNING == 37
	#warning Option `FIX_OnPlayerEnterVehicle_3` must now be explicit.
#elseif _FIXES_WARNING == 38
	#warning Option `FIX_AllowTeleport` must now be explicit.
#elseif _FIXES_WARNING == 39
	#warning Option `FIX_SetPlayerSpecialAction` must now be explicit.
#elseif _FIXES_WARNING == 40
	#warning Option `FIX_ClearAnimations` must now be explicit.
#elseif _FIXES_WARNING == 41
	#warning Option `FIX_ClearAnimations_2` must now be explicit.
#elseif _FIXES_WARNING == 42
	#warning Option `FIX_GangZoneCreate` must now be explicit.
#elseif _FIXES_WARNING == 43
	#warning Option `FIX_OnDialogResponse` must now be explicit.
#elseif _FIXES_WARNING == 44
	#warning Option `FIX_GetPlayerDialog` must now be explicit.
#elseif _FIXES_WARNING == 45
	#warning Option `FIX_PlayerDialogResponse` must now be explicit.
#elseif _FIXES_WARNING == 46
	#warning Option `FIX_SetSpawnInfo` must now be explicit.
#elseif _FIXES_WARNING == 47
	#warning Option `FIX_SetSpawnInfo_2` must now be explicit.
#elseif _FIXES_WARNING == 48
	#warning Option `FIX_SetPlayerSkin` must now be explicit.
#elseif _FIXES_WARNING == 49
	#warning Option `FIX_valstr` must now be explicit.
#elseif _FIXES_WARNING == 50
	#warning Option `FIX_file_inc` must now be explicit.
#elseif _FIXES_WARNING == 51
	#warning Option `FIX_SetPlayerAttachedObject` must now be explicit.
#elseif _FIXES_WARNING == 52
	#warning Option `FIX_OnPlayerDeath` must now be explicit.
#elseif _FIXES_WARNING == 53
	#warning Option `FIX_strins` must now be explicit.
#elseif _FIXES_WARNING == 54
	#warning Option `FIX_IsPlayerConnected` must now be explicit.
#elseif _FIXES_WARNING == 55
	#warning Option `FIX_TrainExit` must now be explicit.
#elseif _FIXES_WARNING == 56
	#warning Option `FIX_Kick` must now be explicit.
#elseif _FIXES_WARNING == 57
	#warning Option `FIX_OnVehicleMod` must now be explicit.
#elseif _FIXES_WARNING == 58
	#warning Option `FIX_random` must now be explicit.
#elseif _FIXES_WARNING == 59
	#warning Option `FIX_sleep` must now be explicit.
#elseif _FIXES_WARNING == 60
	#warning Option `FIX_Menus` must now be explicit.
#elseif _FIXES_WARNING == 61
	#warning Option `FIX_AddMenuItem` must now be explicit.
#elseif _FIXES_WARNING == 62
	#warning Option `FIX_SetMenuColumnHeader` must now be explicit.
#elseif _FIXES_WARNING == 63
	#warning Option `FIX_ShowMenuForPlayer` must now be explicit.
#elseif _FIXES_WARNING == 64
	#warning Option `FIX_HideMenuForPlayer` must now be explicit.
#elseif _FIXES_WARNING == 65
	#warning Option `FIX_GetPlayerMenu` must now be explicit.
#elseif _FIXES_WARNING == 66
	#warning Option `FIX_HideMenuForPlayer_2` must now be explicit.
#elseif _FIXES_WARNING == 67
	#warning Option `FIX_DisableMenu` must now be explicit.
#elseif _FIXES_WARNING == 68
	#warning Option `FIX_DisableMenuRow` must now be explicit.
#elseif _FIXES_WARNING == 69
	#warning Option `FIX_GetPlayerInterior` must now be explicit.
#elseif _FIXES_WARNING == 70
	#warning Option `FIX_ApplyAnimation` must now be explicit.
#elseif _FIXES_WARNING == 71
	#warning Option `FIX_ApplyAnimation_2` must now be explicit.
#elseif _FIXES_WARNING == 72
	#warning Option `FIX_ApplyActorAnimation` must now be explicit.
#elseif _FIXES_WARNING == 73
	#warning Option `FIX_ApplyActorAnimation_2` must now be explicit.
#elseif _FIXES_WARNING == 74
	#warning Option `FIX_OnPlayerSpawn` must now be explicit.
#elseif _FIXES_WARNING == 75
	#warning Option `FIX_GameText` must now be explicit.
#elseif _FIXES_WARNING == 76
	#warning Option `FIX_HideGameText` must now be explicit.
#elseif _FIXES_WARNING == 77
	#warning Option `FIX_GetPlayerWorldBounds` must now be explicit.
#elseif _FIXES_WARNING == 78
	#warning Option `FIX_ClearPlayerWorldBounds` must now be explicit.
#elseif _FIXES_WARNING == 79
	#warning Option `FIX_GameTextStyles` must now be explicit.
#elseif _FIXES_WARNING == 80
	#warning Option `FIX_OnPlayerConnect` must now be explicit.
#elseif _FIXES_WARNING == 81
	#warning Option `FIX_OnPlayerDisconnect` must now be explicit.
#elseif _FIXES_WARNING == 82
	#warning Option `FIX_CreatePlayerTextDraw` must now be explicit.
#elseif _FIXES_WARNING == 83
	#warning Option `FIX_CreatePlayerTextDraw_2` must now be explicit.
#elseif _FIXES_WARNING == 84
	#warning Option `FIX_PlayerTextDrawSetString` must now be explicit.
#elseif _FIXES_WARNING == 85
	#warning Option `FIX_PlayerTextDrawSetString_2` must now be explicit.
#elseif _FIXES_WARNING == 86
	#warning Option `FIX_SetPlayerCamera` must now be explicit.
#elseif _FIXES_WARNING == 87
	#warning Option `FIX_SetPlayerTime` must now be explicit.
#elseif _FIXES_WARNING == 88
	#warning Option `FIX_OnPlayerRequestClass` must now be explicit.
#elseif _FIXES_WARNING == 89
	#warning Option `FIX_SetPlayerColour` must now be explicit.
#elseif _FIXES_WARNING == 90
	#warning Option `FIX_FileMaths` must now be explicit.
#elseif _FIXES_WARNING == 91
	#warning Option `FIX_GetPlayerWeaponData` must now be explicit.
#elseif _FIXES_WARNING == 92
	#warning Option `FIX_strcmp` must now be explicit.
#elseif _FIXES_WARNING == 93
	#warning Option `FIX_GetPVarString` must now be explicit.
#elseif _FIXES_WARNING == 94
	#warning Option `FIX_GetSVarString` must now be explicit.
#elseif _FIXES_WARNING == 95
	#warning Option `FIX_toupper` must now be explicit.
#elseif _FIXES_WARNING == 96
	#warning Option `FIX_tolower` must now be explicit.
#elseif _FIXES_WARNING == 97
	#warning Option `FIX_ispacked` must now be explicit.
#elseif _FIXES_WARNING == 98
	#warning Option `FIX_PassengerSeating` must now be explicit.
#elseif _FIXES_WARNING == 99
	#warning Option `FIX_GogglesSync` must now be explicit.
#elseif _FIXES_WARNING == 100
	#warning Option `FIX_GetPlayerPoolSize` must now be explicit.
#elseif _FIXES_WARNING == 101
	#warning Option `FIX_SetPlayerPos` must now be explicit.
#elseif _FIXES_WARNING == 102
	#warning Option `FIX_GetPlayerAmmo` must now be explicit.
#elseif _FIXES_WARNING == 103
	#warning Option `FIX_JIT` must now be explicit.
#elseif _FIXES_WARNING == 104
	#warning Option `FIX_OS` must now be explicit.
#elseif _FIXES_WARNING == 105
	#warning Option `FIX_const` must now be explicit.
#elseif _FIXES_WARNING == 106
	#warning Option `FIX_VEHICLES` must now be explicit.
#elseif _FIXES_WARNING == 107
	#warning Option `FIX_GetPlayerWeather` must now be explicit.
#elseif _FIXES_WARNING == 108
	#warning Option `FIX_GetWeather` must now be explicit.
#elseif _FIXES_WARNING == 109
	#warning Option `FIX_GetWorldTime` must now be explicit.
#elseif _FIXES_WARNING == 110
	#warning Option `FIX_GetConsoleVarAsString` must now be explicit.
#elseif _FIXES_WARNING == 111
	#warning Option `FIX_GetConsoleVarAsInt` must now be explicit.
#elseif _FIXES_WARNING == 112
	#warning Option `FIX_GetConsoleVarAsBool` must now be explicit.
#elseif _FIXES_WARNING == 113
	#warning Option `FIX_GetConsoleVarAsFloat` must now be explicit.
#elseif _FIXES_WARNING == 114
	#warning Option `FIX_tabsize` must now be explicit.
#elseif _FIXES_WARNING == 115
	#warning Option `FIX_Callbacks` must now be explicit.
#elseif _FIXES_WARNING == 116
	#warning Option `FIX_OnRconCommand` must now be explicit.
#elseif _FIXES_WARNING == 117
	#warning Option `FIX_OnClientCheckResponse` must now be explicit.
#elseif _FIXES_WARNING == 118
	#warning Option `FIX_GetMaxPlayers` must now be explicit.
#elseif _FIXES_WARNING == 119
	#warning Option `FIX_BypassDialog` must now be explicit.
#elseif _FIXES_WARNING == 120
	#warning Option `FIX_SetTimer` must now be explicit.
#elseif _FIXES_WARNING == 121
	#warning Option `FIX_main` must now be explicit.
#elseif _FIXES_WARNING == 122
	#warning Option `FIX_Pawndoc` must now be explicit.
#elseif _FIXES_WARNING == 123
	#warning Option `FIX_OnVehicleSpawn` must now be explicit.
#elseif _FIXES_WARNING == 124
	#warning Option `FIX_floatfract` must now be explicit.
#elseif _FIXES_WARNING == 125
	#warning Option `FIX_strfind` must now be explicit.
#elseif _FIXES_WARNING == 126
	#warning Option `FIX_strdel` must now be explicit.
#elseif _FIXES_WARNING == 127
	#warning Option `FIX_LocalNPCNatives` must now be explicit.
#elseif _FIXES_WARNING == 128
	#warning Option `FIX_RemoteNPCNatives` must now be explicit.
#elseif _FIXES_WARNING == 129
	#warning Option `FIX_deconst` must now be explicit.
#elseif _FIXES_WARNING == 130
	#warning Option `FIX_Streamer_HasIntData` must now be explicit.
#elseif _FIXES_WARNING == 131
	#warning Option `FIX_Streamer_RemoveIntData` must now be explicit.
#elseif _FIXES_WARNING == 132
	#warning Option `FIX_defaults` must now be explicit.
#elseif _FIXES_WARNING == 133
	#warning Option `FIX_limit_tags` must now be explicit.
#elseif _FIXES_WARNING == 134
	#warning Option `FIX_bool_tags` must now be explicit.
#elseif _FIXES_WARNING == 135
	#warning Option `FIX_TEXT_DRAW_ALIGN` must now be explicit.
#elseif _FIXES_WARNING == 136
	#warning Option `FIX_TEXT_DRAW_FONT` must now be explicit.
#elseif _FIXES_WARNING == 137
	#warning Option `FIX_GetPlayerKeys` must now be explicit.
#elseif _FIXES_WARNING == 138
	#warning Option `FIX_FORCE_SYNC` must now be explicit.
#elseif _FIXES_WARNING == 139
	#warning Option `FIX_address_naught` must now be explicit.
#elseif _FIXES_WARNING == 140
	#warning Option `FIX_main2` must now be explicit.
#elseif _FIXES_WARNING == 141
	#warning Option `FIX_npcmodes` must now be explicit.
#elseif _FIXES_WARNING == 142
	#warning Option `FIX_fgetchar2` must now be explicit.
#elseif _FIXES_WARNING == 143
	#warning Option `FIX_memcpy` must now be explicit.
#else
	#error `_fixes_options.inc` included, but `_FIXES_WARNING` is not set to a valid warning message.
#endif

#pragma warning pop

