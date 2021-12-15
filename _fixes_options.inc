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

// The caller always undefines `_FIXES_WARNING` after trying to include this
// file, as it needs to be undefined whether the include worked or not.  Thus we
// can't also undefine it in here, as the sensible option would seem to be, as
// then it will be undefined twice in some situations.
#if _FIXES_WARNING == 1
	#warning The `FIX_API` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 2
	#warning The `FIX_Natives` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 3
	#warning The `FIX_GetPlayerColour` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 4
	#warning The `FIX_FILTERSCRIPT` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 5
	#warning The `FIX_SpawnPlayer` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 6
	#warning The `FIX_SetPlayerName` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 7
	#warning The `FIX_GetPlayerSkin` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 8
	#warning The `FIX_GetWeaponName` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 9
	#warning The `FIX_SetPlayerWorldBounds` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 10
	#warning The `FIX_TogglePlayerControllable` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 11
	#warning The `FIX_HydraSniper` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 12
	#warning The `FIX_IsPlayerInCheckpoint` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 13
	#warning The `FIX_IsPlayerInRaceCheckpoint` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 14
	#warning The `FIX_GetPlayerWeapon` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 15
	#warning The `FIX_PutPlayerInVehicle` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 16
	#warning The `FIX_KEY_AIM` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 17
	#warning The `FIX_SPECIAL_ACTION_PISSING` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 18
	#warning The `FIX_IsValidVehicle` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 19
	#warning The `FIX_GetGravity` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 20
	#warning The `FIX_gpci` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 21
	#warning The `FIX_WEAPONS` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 22
	#warning The `FIX_BODYPARTS` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 23
	#warning The `FIX_CAMERAMODES` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 24
	#warning The `FIX_DriveBy` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 25
	#warning The `FIX_SilentTeleport` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 26
	#warning The `FIX_SetPlayerCheckpoint` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 27
	#warning The `FIX_SetPlayerRaceCheckpoint` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 28
	#warning The `FIX_TextDrawCreate` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 29
	#warning The `FIX_AttachTrailerToVehicle` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 30
	#warning The `FIX_GetVehicleComponentInSlot` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 31
	#warning The `FIX_TextDrawCreate_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 32
	#warning The `FIX_TextDrawSetString` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 33
	#warning The `FIX_TextDrawSetString_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 34
	#warning The `FIX_AllowInteriorWeapons` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 35
	#warning The `FIX_OnPlayerEnterVehicle` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 36
	#warning The `FIX_OnPlayerEnterVehicle_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 37
	#warning The `FIX_OnPlayerEnterVehicle_3` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 38
	#warning The `FIX_AllowTeleport` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 39
	#warning The `FIX_SetPlayerSpecialAction` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 40
	#warning The `FIX_ClearAnimations` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 41
	#warning The `FIX_ClearAnimations_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 42
	#warning The `FIX_GangZoneCreate` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 43
	#warning The `FIX_OnDialogResponse` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 44
	#warning The `FIX_GetPlayerDialog` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 45
	#warning The `FIX_PlayerDialogResponse` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 46
	#warning The `FIX_SetSpawnInfo` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 47
	#warning The `FIX_SetSpawnInfo_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 48
	#warning The `FIX_SetPlayerSkin` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 49
	#warning The `FIX_valstr` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 50
	#warning The `FIX_file_inc` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 51
	#warning The `FIX_SetPlayerAttachedObject` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 52
	#warning The `FIX_OnPlayerDeath` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 53
	#warning The `FIX_strins` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 54
	#warning The `FIX_IsPlayerConnected` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 55
	#warning The `FIX_TrainExit` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 56
	#warning The `FIX_Kick` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 57
	#warning The `FIX_OnVehicleMod` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 58
	#warning The `FIX_random` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 59
	#warning The `FIX_sleep` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 60
	#warning The `FIX_Menus` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 61
	#warning The `FIX_AddMenuItem` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 62
	#warning The `FIX_SetMenuColumnHeader` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 63
	#warning The `FIX_ShowMenuForPlayer` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 64
	#warning The `FIX_HideMenuForPlayer` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 65
	#warning The `FIX_GetPlayerMenu` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 66
	#warning The `FIX_HideMenuForPlayer_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 67
	#warning The `FIX_DisableMenu` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 68
	#warning The `FIX_DisableMenuRow` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 69
	#warning The `FIX_GetPlayerInterior` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 70
	#warning The `FIX_ApplyAnimation` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 71
	#warning The `FIX_ApplyAnimation_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 72
	#warning The `FIX_ApplyActorAnimation` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 73
	#warning The `FIX_ApplyActorAnimation_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 74
	#warning The `FIX_OnPlayerSpawn` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 75
	#warning The `FIX_GameText` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 76
	#warning The `FIX_HideGameText` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 77
	#warning The `FIX_GetPlayerWorldBounds` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 78
	#warning The `FIX_ClearPlayerWorldBounds` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 79
	#warning The `FIX_GameTextStyles` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 80
	#warning The `FIX_OnPlayerConnect` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 81
	#warning The `FIX_OnPlayerDisconnect` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 82
	#warning The `FIX_CreatePlayerTextDraw` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 83
	#warning The `FIX_CreatePlayerTextDraw_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 84
	#warning The `FIX_PlayerTextDrawSetString` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 85
	#warning The `FIX_PlayerTextDrawSetString_2` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 86
	#warning The `FIX_SetPlayerCamera` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 87
	#warning The `FIX_SetPlayerTime` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 88
	#warning The `FIX_OnPlayerRequestClass` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 89
	#warning The `FIX_SetPlayerColour` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 90
	#warning The `FIX_FileMaths` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 91
	#warning The `FIX_GetPlayerWeaponData` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 92
	#warning The `FIX_strcmp` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 93
	#warning The `FIX_GetPVarString` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 94
	#warning The `FIX_GetSVarString` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 95
	#warning The `FIX_toupper` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 96
	#warning The `FIX_tolower` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 97
	#warning The `FIX_ispacked` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 98
	#warning The `FIX_PassengerSeating` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 99
	#warning The `FIX_GogglesSync` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 100
	#warning The `FIX_GetPlayerPoolSize` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 101
	#warning The `FIX_SetPlayerPos` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 102
	#warning The `FIX_GetPlayerAmmo` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 103
	#warning The `FIX_JIT` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 104
	#warning The `FIX_OS` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 105
	#warning The `FIX_const` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 106
	#warning The `FIX_VEHICLES` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 107
	#warning The `FIX_GetPlayerWeather` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 108
	#warning The `FIX_GetWeather` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 109
	#warning The `FIX_GetWorldTime` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 110
	#warning The `FIX_GetConsoleVarAsString` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 111
	#warning The `FIX_GetConsoleVarAsInt` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 112
	#warning The `FIX_GetConsoleVarAsBool` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 113
	#warning The `FIX_GetConsoleVarAsFloat` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 114
	#warning The `FIX_tabsize` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 115
	#warning The `FIX_Callbacks` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 116
	#warning The `FIX_OnRconCommand` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 117
	#warning The `FIX_OnClientCheckResponse` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 118
	#warning The `FIX_GetMaxPlayers` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 119
	#warning The `FIX_BypassDialog` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 120
	#warning The `FIX_SetTimer` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 121
	#warning The `FIX_main` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 122
	#warning The `FIX_Pawndoc` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 123
	#warning The `FIX_OnVehicleSpawn` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 124
	#warning The `FIX_floatfract` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 125
	#warning The `FIX_strfind` option must now be explicit.
	#endinput
#endif
#if _FIXES_WARNING == 126
	#warning The `FIX_strdel` option must now be explicit.
	#endinput
#endif

#error `_fixes_options.inc` included, but `_FIXES_WARNING` is not set to a valid warning message.

