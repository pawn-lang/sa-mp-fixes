#define IS_FILTERSCRIPT // Remove it.

static stock
	bool:BREAKS_gFilterscript = false,
	BREAKS_gRCPSize[MAX_PLAYERS] = { 0, ... },
	BREAKS_gCPSize[MAX_PLAYERS] = { 0, ... },
	bool:BREAKS_gRCPInitialised[MAX_PLAYERS] = { false, ... },
	bool:BREAKS_gCPInitialised[MAX_PLAYERS] = { false, ... },
	BREAKS_gPlayerColour[MAX_PLAYERS] = { 0, ... },
	BREAKS_gPlayerSkin[MAX_PLAYERS] = { 0, ... },
	bool:BREAKS_gExtraOPC[MAX_PLAYERS] = { false, ... },
	BREAKS_gLibraryInitialised[MAX_PLAYERS][5];

static stock const
	BREAKS_gscAnimLib[135][] =
		{
			"AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
			"BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
			"BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
			"BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
			"BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
			"CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
			"COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
			"DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
			"DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
			"FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
			"FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
			"GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
			"GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
			"INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
			"KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
			"MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
			"MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
			"PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
			"POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
			"QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
			"ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SAMP",
			"SCRATCHING",   "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",
			"SILENCED",     "SKATE",        "SMOKING",      "SNIPER",       "SNM",
			"SPRAYCAN",     "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",
			"SWIM",         "SWORD",        "TANK",         "TATTOOS",      "TEC",
			"TRAIN",        "TRUCK",        "UZI",          "VAN",          "VENDING",
			"VORTEX",       "WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
		};

stock BREAKS_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	BREAKS_gPlayerSkin[playerid] = skin;
	return SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#endif
#define SetSpawnInfo BREAKS_SetSpawnInfo
#define _ALS_SetSpawnInfo

stock BREAKS_SetPlayerSkin(playerid, skin)
{
	BREAKS_gPlayerSkin[playerid] = skin;
	return SetPlayerSkin(playerid, skin);
}

#if defined _ALS_SetPlayerSkin
	#undef SetPlayerSkin
#endif
#define SetPlayerSkin BREAKS_SetPlayerSkin
#define _ALS_SetPlayerSkin

stock BREAKS_GetPlayerSkin(playerid)
{
	return BREAKS_gPlayerSkin[playerid];
}

#if defined _ALS_GetPlayerSkin
	#undef GetPlayerSkin
#endif
#define GetPlayerSkin BREAKS_GetPlayerSkin
#define _ALS_GetPlayerSkin

stock BREAKS_SetPlayerColor(playerid, colour)
{
	BREAKS_gPlayerColour[playerid] = colour;
	return SetPlayerColor(playerid, colour);
}

#if defined _ALS_SetPlayerColor
	#undef SetPlayerColor
#endif
#define SetPlayerColor BREAKS_SetPlayerColor
#define _ALS_SetPlayerColor

stock BREAKS_GetPlayerColor(playerid)
{
	return BREAKS_gPlayerColour[playerid];
}

#if defined _ALS_GetPlayerColor
	#undef GetPlayerColor
#endif
#define GetPlayerColor BREAKS_GetPlayerColor
#define _ALS_GetPlayerColor

public OnFilterScriptInit()
{
	BREAKS_gFilterscript = true;
	for (new i = 0; i != MAX_PLAYERS; ++i)
	{
		if (IsPlayerConnected(i))
		{
			BREAKS_gExtraOPC[i] = true;
		}
	}
	#if defined BREAKS_OnFilterScriptInit
		BREAKS_OnFilterScriptInit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#endif
#define OnFilterScriptInit BREAKS_OnFilterScriptInit
#define _ALS_OnFilterScriptInit

#if defined BREAKS_OnFilterScriptInit
	forward BREAKS_OnFilterScriptInit();
#endif

public OnGameModeInit()
{
	if (!BREAKS_gFilterscript)
	{
		for (new i = 0; i != MAX_PLAYERS; ++i)
		{
			if (IsPlayerConnected(i))
			{
				BREAKS_gExtraOPC[i] = true;
			}
		}
	}
	#if defined BREAKS_OnGameModeInit
		BREAKS_OnGameModeInit();
	#endif
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#endif
#define OnGameModeInit BREAKS_OnGameModeInit
#define _ALS_OnGameModeInit

#if defined BREAKS_OnGameModeInit
	forward BREAKS_OnGameModeInit();
#endif

public OnPlayerConnect(playerid)
{
	BREAKS_gPlayerColour[playerid] = 0;
	BREAKS_gPlayerSkin[playerid] = 0;
	BREAKS_gCPInitialised[playerid] = false;
	BREAKS_gRCPInitialised[playerid] = false;
	BREAKS_gCPSize[playerid] = 0;
	BREAKS_gRCPSize[playerid] = 0;
	if (BREAKS_gExtraOPC[playerid])
	{
		BREAKS_gExtraOPC[playerid] = false;
	}
	#if defined BREAKS_OnPlayerConnect
		else
		{
			BREAKS_OnPlayerConnect(playerid);
		}
	#endif
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#endif
#define OnPlayerConnect BREAKS_OnPlayerConnect
#define _ALS_OnPlayerConnect

#if defined BREAKS_OnPlayerConnect
	forward BREAKS_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	#if defined BREAKS_OnPlayerDisconnect
		if (reason != 4)
		{
			BREAKS_OnPlayerDisconnect(playerid, reason);
		}
	#endif
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#endif
#define OnPlayerDisconnect BREAKS_OnPlayerDisconnect
#define _ALS_OnPlayerDisconnect

#if defined BREAKS_OnPlayerDisconnect
	forward BREAKS_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{
	new money = GetPlayerMoney(playerid);
	if (money > 0)
	{
		ResetPlayerMoney(playerid);
		if (money > 100)
		{
			GivePlayerMoney(playerid, money - 100);
		}
	}
	#if defined BREAKS_OnPlayerDeath
		BREAKS_OnPlayerDeath(playerid, killerid, reason);
	#endif
	return 1;
}

#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#endif
#define OnPlayerDeath BREAKS_OnPlayerDeath
#define _ALS_OnPlayerDeath

#if defined BREAKS_OnPlayerDeath
	forward BREAKS_OnPlayerDeath(playerid, killerid, reason);
#endif

stock BREAKS_SpawnPlayer(playerid)
{
	if (IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerHealth(playerid, 0.0);
	}
	return SpawnPlayer(playerid);
}

#if defined _ALS_SpawnPlayer
	#undef SpawnPlayer
#endif
#define SpawnPlayer BREAKS_SpawnPlayer
#define _ALS_SpawnPlayer

stock BREAKS_SetPlayerName(playerid, name[])
{
	new old[MAX_PLAYER_NAME + 1];
	if (GetPlayerName(playerid, old, sizeof (old)))
	{
		if (strcmp(name, old, true) == 0)
		{
			return 1;
		}
		return SetPlayerName(playerid, name);
	}
	return 0;
}

#if defined _ALS_SetPlayerName
	#undef SetPlayerName
#endif
#define SetPlayerName BREAKS_SetPlayerName
#define _ALS_SetPlayerName

stock BREAKS_GetWeaponName(weaponid, const weapon[], len)
{
	switch (weaponid)
	{
	case 18, 44, 45:
		weapon[0] = '\0';
		return 0;
	}
	return GetWeaponName(weaponid, weapon, len);
}

#if defined _ALS_GetWeaponName
	#undef GetWeaponName
#endif
#define GetWeaponName BREAKS_GetWeaponName
#define _ALS_GetWeaponName

stock BREAKS_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
{
	BREAKS_gCPInitialised = true;
	if (BREAKS_gCPSize[playerid] == 0)
	{
		BREAKS_gCPSize[playerid] size;
	}
	return SetPlayerCheckpoint(playerid, x, y, z, BREAKS_gCPSize[playerid]);
}

#if defined _ALS_SetPlayerCheckpoint
	#undef SetPlayerCheckpoint
#endif
#define SetPlayerCheckpoint BREAKS_SetPlayerCheckpoint
#define _ALS_SetPlayerCheckpoint

stock BREAKS_DisablePlayerCheckpoint(playerid)
{
	BREAKS_gCPInitialised = true;
	BREAKS_gCPSize[playerid] = 0;
	return DisablePlayerCheckpoint(playerid);
}

#if defined _ALS_DisablePlayerCheckpoint
	#undef DisablePlayerCheckpoint
#endif
#define DisablePlayerCheckpoint BREAKS_DisablePlayerCheckpoint
#define _ALS_DisablePlayerCheckpoint

stock BREAKS_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
{
	BREAKS_gRCPInitialised = true;
	if (BREAKS_gRCPSize[playerid] == 0)
	{
		BREAKS_gRCPSize[playerid] size;
	}
	return SetPlayerRaceCheckpoint(playerid, type, x, y, z, nextx, nexty, nextz, BREAKS_gRCPSize[playerid]);
}

#if defined _ALS_SetPlayerRaceCheckpoint
	#undef SetPlayerRaceCheckpoint
#endif
#define SetPlayerRaceCheckpoint BREAKS_SetPlayerRaceCheckpoint
#define _ALS_SetPlayerRaceCheckpoint

stock BREAKS_DisablePlayerRaceCheckpoint(playerid)
{
	BREAKS_gRCPInitialised = true;
	BREAKS_gRCPSize[playerid] = 0;
	return DisablePlayerRaceCheckpoint(playerid);
}

#if defined _ALS_DisablePlayerRaceCheckpoint
	#undef DisablePlayerRaceCheckpoint
#endif
#define DisablePlayerRaceCheckpoint BREAKS_DisablePlayerRaceCheckpoint
#define _ALS_DisablePlayerRaceCheckpoint

stock BREAKS_IsPlayerInCheckpoint(playerid)
{
	return BREAKS_gCPInitialised[playerid] ? IsPlayerInCheckpoint(playerid) : random(cellmax);
}

#if defined _ALS_IsPlayerInCheckpoint
	#undef IsPlayerInCheckpoint
#endif
#define IsPlayerInCheckpoint BREAKS_IsPlayerInCheckpoint
#define _ALS_IsPlayerInCheckpoint

stock BREAKS_IsPlayerInRaceCheckpoint(playerid)
{
	return BREAKS_gRCPInitialised[playerid] ? IsPlayerInRaceCheckpoint(playerid) : random(cellmax);
}

#if defined _ALS_IsPlayerInRaceCheckpoint
	#undef IsPlayerInRaceCheckpoint
#endif
#define IsPlayerInRaceCheckpoint BREAKS_IsPlayerInRaceCheckpoint
#define _ALS_IsPlayerInRaceCheckpoint

stock Text:BREAKS_TextDrawCreate(Float:x, Float:y, text[])
{
	new len = strlen(text);
	if (len == 0 || len > 1024)
	{
		#emit HALT 100
	}
	if (text[len - 1] == ' ')
	{
		return TextDrawCreate(x, y, " ");
	}
	return TextDrawCreate(x, y, text);
}

#if defined _ALS_TextDrawCreate
	#undef TextDrawCreate
#endif
#define TextDrawCreate BREAKS_TextDrawCreate
#define _ALS_TextDrawCreate

stock PlayerText:BREAKS_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[])
{
	new len = strlen(text);
	if (len == 0 || len > 1024)
	{
		#emit HALT 100
	}
	if (text[len - 1] == ' ')
	{
		return CreatePlayerTextDraw(playerid, x, y, " ");
	}
	return CreatePlayerTextDraw(playerid, x, y, text);
}

#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#endif
#define CreatePlayerTextDraw BREAKS_CreatePlayerTextDraw
#define _ALS_CreatePlayerTextDraw

stock BREAKS_TextDrawSetString(Text:text, string[])
{
	new len = strlen(string);
	if (len == 0 || len > 1024)
	{
		#emit HALT 100
	}
	if (string[len - 1] == ' ')
	{
		return TextDrawSetString(text, " ");
	}
	return TextDrawSetString(text, string);
}

#if defined _ALS_TextDrawSetString
	#undef TextDrawSetString
#endif
#define TextDrawSetString BREAKS_TextDrawSetString
#define _ALS_TextDrawSetString

stock BREAKS_PlayerTextDrawSetString(playerid, PlayerText:text, string[])
{
	new len = strlen(string);
	if (len == 0 || len > 1024)
	{
		#emit HALT 100
	}
	if (string[len - 1] == ' ')
	{
		return PlayerTextDrawSetString(playerid, text, " ");
	}
	return PlayerTextDrawSetString(playerid, text, string);
}

#if defined _ALS_PlayerTextDrawSetString
	#undef PlayerTextDrawSetString
#endif
#define PlayerTextDrawSetString BREAKS_PlayerTextDrawSetString
#define _ALS_PlayerTextDrawSetString

forward BREAKS_AllowInteriorWeapons(allow);

#if defined _ALS_AllowInteriorWeapons
	#undef AllowInteriorWeapons
#endif
#define AllowInteriorWeapons BREAKS_AllowInteriorWeapons
#define _ALS_AllowInteriorWeapons

forward Float:BREAKS_GetGravity();

#if defined _ALS_GetGravity
	#undef GetGravity
#endif
#define GetGravity BREAKS_GetGravity
#define _ALS_GetGravity

forward BREAKS_gpci(playerid, serial[], len = sizeof (serial));

#if defined _ALS_gpci
	#undef gpci
#endif
#define gpci BREAKS_gpci
#define _ALS_gpci

forward BREAKS_HideGameTextForPlayer(playerid, style);

#if defined _ALS_HideGameTextForPlayer
	#undef HideGameTextForPlayer
#endif
#define HideGameTextForPlayer BREAKS_HideGameTextForPlayer
#define _ALS_HideGameTextForPlayer

forward BREAKS_HideGameTextForAll(style);

#if defined _ALS_HideGameTextForAll
	#undef HideGameTextForAll
#endif
#define HideGameTextForAll BREAKS_HideGameTextForAll
#define _ALS_HideGameTextForAll

forward bool:BREAKS_IsValidVehicle(vehicleid);

#if defined _ALS_IsValidVehicle
	#undef IsValidVehicle
#endif
#define IsValidVehicle BREAKS_IsValidVehicle
#define _ALS_IsValidVehicle

stock BREAKS_random(max)
{
	if (max < 0)
	{
		return 0;
	}
	return random(max);
}

#if defined _ALS_random
	#undef random
#endif
#define random BREAKS_random
#define _ALS_random

stock BREAKS_IsPlayerConnected(playerid)
{
	return IsPlayerConnected(playerid & 0xFFFF);
}

#if defined _ALS_IsPlayerConnected
	#undef IsPlayerConnected
#endif
#define IsPlayerConnected BREAKS_IsPlayerConnected
#define _ALS_IsPlayerConnected

stock BREAKS_ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0)
{
	for (new i = 0; i != sizeof (BREAKS_gscAnimLib); ++i)
	{
		if (strcmp(animlib, BREAKS_gscAnimLib[i], true) == 0)
		{
			if (BREAKS_gLibraryInitialised[playerid][i / 32] & (1 << (i % 32)))
			{
				return ApplyAnimation(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
			}
			else
			{
				BREAKS_gLibraryInitialised[playerid][i / 32] |= (1 << (i % 32));
			}
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_ApplyAnimation
	#undef ApplyAnimation
#endif
#define ApplyAnimation BREAKS_ApplyAnimation
#define _ALS_ApplyAnimation

//stock BREAKS_ApplyActorAnimation(actorid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time)
//{
//	for (new i = 0; i != sizeof (BREAKS_gscAnimLib); ++i)
//	{
//		if (strcmp(animlib, BREAKS_gscAnimLib[i], true) == 0)
//		{
//			// TODO: Per-player actor animations.
//			for (new playerid = 0; playerid != MAX_PLAYERS; ++playerid)
//			{
//				if (BREAKS_gLibraryInitialised[playerid][i / 32] & (1 << (i % 32)))
//				{
//					return ApplyActorAnimation(actorid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time);
//				}
//				else
//				{
//					BREAKS_gLibraryInitialised[playerid][i / 32] |= (1 << (i % 32));
//				}
//			}
//			return 1;
//		}
//	}
//	return 0;
//}
//
//#if defined _ALS_ApplyActorAnimation
//	#undef ApplyActorAnimation
//#endif
//#define ApplyActorAnimation BREAKS_ApplyActorAnimation
//#define _ALS_ApplyActorAnimation

#endinput

stock BREAKS_$()
{
	return $();
}

#if defined _ALS_$
	#undef $
#endif
#define $ BREAKS_$
#define _ALS_$

