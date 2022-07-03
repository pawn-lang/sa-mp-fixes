#define IS_FILTERSCRIPT // Remove it.

static
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

