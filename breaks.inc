static
	BREAKS_gPlayerColour[MAX_PLAYERS] = { 0, ... };

stock BREAKS_SetPlayerColor(playerid, colour)
{
	BREAKS_gPlayerColour[playerid] = colour;
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

