#define FIXES_Single 0

#include "fixes.inc"

forward TestCompiles();

// This function just checks that calling every single hooked function in fixes.inc is possible.
// That at least the compilation completes.
public TestCompiles()
{
	new str[2];
	new c1, c2;
	new VEHICLE_PARAMS:v0;
	new Float:f1, Float:f2, Float:f3, Float:f4;
	IsPlayerConnected(0);
	SetVehiclePos(0, 0.0, 0.0, 0.0);
	SpawnPlayer(0);
	SetPlayerName(0, "");
	SetPlayerSkin(0, 0);
	GetPlayerSkin(0);
	GetWeaponName(0, str, 0);
	SetPlayerWorldBounds(0, 0.0, 0.0, 0.0, 0.0);
	GetPlayerWorldBounds(0, f1, f2, f3, f4);
	ClearPlayerWorldBounds(0);
	TogglePlayerControllable(0, false);
	SetTimer("", 0, 0);
	SetTimerEx("", 0, 0, "");
	DestroyMenu(Menu:0);
	AddMenuItem(Menu:0, 0, "");
	SetMenuColumnHeader(Menu:0, 0, "");
	ShowMenuForPlayer(Menu:0, 0);
	HideMenuForPlayer(Menu:0, 0);
	DisableMenu(Menu:0);
	DisableMenuRow(Menu:0, 0);
	GivePlayerWeapon(0, 0, 0);
	ResetPlayerWeapons(0);
	SetPlayerArmedWeapon(0, 0);
	GetPlayerWeapon(0);
	PutPlayerInVehicle(0, 0, 0);
	SetPlayerCheckpoint(0, 0.0, 0.0, 0.0, 0.0);
	DisablePlayerCheckpoint(0);
	SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	DisablePlayerRaceCheckpoint(0);
	GameTextForAll("", 0, 0);
	GameTextForPlayer(0, "", 0, 0);
	HideGameTextForAll(0);
	HideGameTextForPlayer(0, 0);
	PlayerTextDrawSetString(0, PlayerText:0, "");
	TextDrawSetString(Text:0, "");
	AllowInteriorWeapons(0);
	GetPlayerInterior(0);
	SetPlayerInterior(0, 0);
	AllowPlayerTeleport(0, 0);
	AllowAdminTeleport(0);
	SetPlayerSpecialAction(0, 0);
	ClearAnimations(0, 0);
	GangZoneCreate(0.0, 0.0, 0.0, 0.0);
	ShowPlayerDialog(0, 0, 0, "", "", "", "");
	GetPlayerDialog(0);
	Kick(0);
	ApplyAnimation(0, "", "", 0.0, 0, 0, 0, 0, 0, 0);
	ApplyActorAnimation(0, "", "", 0.0, 0, 0, 0, 0, 0);
	CreateActor(0, 0.0, 0.0, 0.0, 0.0);
	DestroyActor(0);
	SetVehicleParamsEx(0, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON);
	GetVehicleParamsEx(0, v0, v0, v0, v0, v0, v0, v0);
	SetPlayerCameraPos(0, 0.0, 0.0, 0.0);
	SetPlayerCameraLookAt(0, 0.0, 0.0, 0.0);
	TogglePlayerSpectating(0, 0);
	SetPlayerTime(0, 0, 0);
	SetPlayerColor(0, 0);
	GetPlayerWeaponData(0, 0, c1, c2);
	GetPVarString(0, "", str, 0);
	GetSVarString("", str, 0);
	GetPlayerPoolSize();
	SetPlayerPos(0, 0.0, 0.0, 0.0);
	SetPlayerPosFindZ(0, 0.0, 0.0, 0.0);
	GetPlayerWeather(0);
	SetPlayerWeather(0, 0);
	TogglePlayerClock(0, 0);
	GetWeather();
	SetWeather(0);
	GetServerVarAsInt("");
	GetDefaultPlayerColour(0);
	GetVehicleSeats(0);
	VehicleCanHaveComponent(0, 0);
	if (IsValidAnimationLibrary("0"))
	{
	}
	GetRandomCarColPair(0, c1, c2);
	SetPlayerAmmo(0, 0, 0);
	SetWorldTime(0);
	HideGameTextForPlayer(0, 0);
	HideGameTextForAll(0);
	valstr(str, 0);
	fwrite(File:0, "");
	fread(File:0, str);
	fgetchar(File:0, 0);
	fblockwrite(File:0, "");
	fblockread(File:0, str);
	fseek(File:0);
	flength(File:0);
	strins(str, "", 0);
	random(0);
	sleep(0);
	strcmp("", "");
	toupper(0);
	tolower(0);
	if (ispacked(str))
	{
	}
	if (PlayerHasClockEnabled(0))
	{
	}
	if (IsMenuValid(Menu:0))
	{
	}
	CarColIndexToColour(55);
}

main()
{
}

