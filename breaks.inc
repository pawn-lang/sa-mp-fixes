#define IS_FILTERSCRIPT // Remove it.

static
	BREAKS_gRCPSize[MAX_PLAYERS] = { 0, ... },
	BREAKS_gCPSize[MAX_PLAYERS] = { 0, ... },
	bool:BREAKS_gRCPInitialised[MAX_PLAYERS] = { false, ... },
	bool:BREAKS_gCPInitialised[MAX_PLAYERS] = { false, ... },
	BREAKS_gPlayerColour[MAX_PLAYERS] = { 0, ... },
	BREAKS_gPlayerSkin[MAX_PLAYERS] = { 0, ... };

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

public OnPlayerConnect(playerid)
{
	BREAKS_gPlayerColour[playerid] = 0;
	BREAKS_gPlayerSkin[playerid] = 0;
	BREAKS_gCPInitialised[playerid] = false;
	BREAKS_gRCPInitialised[playerid] = false;
	BREAKS_gCPSize[playerid] = 0;
	BREAKS_gRCPSize[playerid] = 0;
	#if defined BREAKS_OnPlayerConnect
		BREAKS_OnPlayerConnect(playerid);
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

forward BREAKS_IsValidVehicle(allow);

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

#endinput

stock BREAKS_$(weaponid, const weapon[], len)
{
	switch (weaponid)
	{
	case 18, 44, 45:
		weapon[0] = '\0';
		return 0;
	}
	return $(weaponid, weapon, len);
}

#if defined _ALS_$
	#undef $
#endif
#define $ BREAKS_$
#define _ALS_$

