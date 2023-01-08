#define STRONG_TAGS
#pragma warning disable 234

#define FIXES_Single 0

#tryinclude <samp-stdlib\a_npc>
#tryinclude <a_npc>

#undef MAX_PLAYERS
#define MAX_PLAYERS (100)

#include "fixes"

forward CompileTest();

main()
{
	print("fixes.inc compile test");
}

public CompileTest()
{
	new output[32];
	new ivar;
	//new Float:fvar;

	// Using defaults.
	Print__("STRING");
	PrintF__("STRING");
	Format__(output, _, "STRING");
	SetTimer("STRING", 0, false);
	SetTimerEx("STRING", 0, false, "");
	KillTimer(0);
	GetTickCount();
	ivar = GetMaxPlayers();
	CallRemoteFunction("STRING", "");
	CallLocalFunction("STRING", "");
	VectorSize(0, 0, 0);
	ASin__(0);
	ACos__(0);
	ATan__(0);
	ATan2__(0, 0);
	ivar = GetPlayerPoolSize();
	ivar = GetVehiclePoolSize();
	ivar = GetActorPoolSize();
	GetWeaponName(WEAPON_FIST, output, _);
	SendRconCommand("STRING");
	GetPlayerNetworkStats(0, output, sizeof (output));
	GetNetworkStats(output, sizeof (output));
	GetServerVarAsString("STRING", output, sizeof (output));
	GetServerVarAsInt("STRING");
	GetServerVarAsBool("STRING");
	GetConsoleVarAsString("STRING", output, sizeof (output));
	GetConsoleVarAsInt("STRING");
	GetConsoleVarAsBool("STRING");
	NetStats_GetIpPort(0, output, sizeof (output));
	/*IsVehicleStreamedIn(0);
	GetVehiclePos(0, fvar, fvar, fvar);
	GetVehicleZAngle(0, fvar);
	GetVehicleRotationQuat(0, fvar, fvar, fvar, fvar);
	GetVehicleDistanceFromPoint(0, 0, 0, 0);
	GetVehicleParamsEx(0, vparams, vparams, vparams, vparams, vparams, vparams, vparams);
	GetVehicleParamsSirenState(0);
	GetVehicleParamsCarDoors(0, ivar, ivar, ivar, ivar);
	GetVehicleParamsCarWindows(0, ivar, ivar, ivar, ivar);
	GetVehicleHealth(0, fvar);
	IsTrailerAttachedToVehicle(0);
	GetVehicleTrailer(0);
	GetVehicleModel(0);
	GetVehicleComponentInSlot(0, CARMODTYPE_SPOILER);
	GetVehicleComponentType(0);
	GetVehicleVelocity(0, fvar, fvar, fvar);
	GetVehicleDamageStatus(0, ivar, ivar, ivar, ivar);
	GetVehicleModelInfo(0, 0, fvar, fvar, fvar);
	GetPlayerPos(0, fvar, fvar, fvar);
	GetPlayerFacingAngle(0, fvar);
	IsPlayerInRangeOfPoint(0, 0, 0, 0, 0);
	GetPlayerDistanceFromPoint(0, 0, 0, 0);
	IsPlayerStreamedIn(0);
	GetPlayerInterior(0);*/
	GetPlayerHealth(0);
	GetPlayerArmour(0);
	/*GetPlayerAmmo(0);
	GetPlayerWeaponState(0);
	GetPlayerTargetPlayer(0);
	GetPlayerTargetActor(0);
	GetPlayerTeam(0);
	GetPlayerScore(0);
	GetPlayerDrunkLevel(0);
	GetPlayerColor(0);
	GetPlayerSkin(0);
	GetPlayerCustomSkin__(0);
	GetPlayerWeaponData(0, WEAPON_SLOT_UNARMED, ivar, ivar);
	GetPlayerMoney(0);
	GetPlayerState(0);
	GetPlayerIp(0, output, sizeof (output));
	GetPlayerPing(0);
	GetPlayerWeapon(0);
	GetPlayerKeys(0, ivar, ivar, ivar);
	GetPlayerName(0, output, sizeof (output));
	GetPlayerTime(0, ivar, ivar);
	GetPlayerWantedLevel(0);
	GetPlayerFightingStyle(0);
	GetPlayerVelocity(0, fvar, fvar, fvar);
	GetPlayerSurfingVehicleID(0);
	GetPlayerSurfingObjectID(0);
	GetPlayerLastShotVectors(0, fvar, fvar, fvar, fvar, fvar, fvar);
	IsPlayerAttachedObjectSlotUsed(0, 0);
	GetPlayerVehicleID(0);
	GetPlayerVehicleSeat(0);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0, output, sizeof (output), output, sizeof (output));
	GetPlayerSpecialAction(0);
	IsPlayerConnected(0);
	IsPlayerInVehicle(0, 0);
	IsPlayerInAnyVehicle(0);
	IsPlayerInCheckpoint(0);
	IsPlayerInRaceCheckpoint(0);
	GetObjectPos(0, fvar, fvar, fvar);
	GetObjectRot(0, fvar, fvar, fvar);
	GetObjectModel(0);
	IsValidObject(0);
	IsObjectMoving(0);
	HTTP(0, 0, "STRING", "STRING", "STRING");
	IsActorStreamedIn(0, 0);
	GetActorVirtualWorld(0);
	GetActorPos(0, fvar, fvar, fvar);
	GetActorFacingAngle(0, fvar);
	GetActorHealth(0, fvar);
	IsActorInvulnerable(0);
	IsValidActor(0);*/




	// Using explicits.
	print("STRING");
	printf("STRING");
	format(output, _, "STRING");
	SetTimer("STRING", 0, false);
	SetTimerEx("STRING", 0, false, "");
	KillTimer(0);
	GetTickCount();
	ivar = GetMaxPlayers();
	CallRemoteFunction("STRING", "");
	CallLocalFunction("STRING", "");
	VectorSize(0, 0, 0);
	asin(0);
	acos(0);
	atan(0);
	atan2(0, 0);
	ivar = GetPlayerPoolSize();
	ivar = GetVehiclePoolSize();
	ivar = GetActorPoolSize();
	GetWeaponName(WEAPON_FIST, output, _);
	/*GetGravity();
	IsPlayerNPC(0);
	IsPlayerAdmin(0);
	SendRconCommand("STRING");
	GetPlayerNetworkStats(0, output, _);
	GetNetworkStats(output, _);
	GetPlayerVersion(0, output, _);*/
	GetServerVarAsString("STRING", output, _);
	GetServerVarAsInt("STRING");
	GetServerVarAsBool("STRING");
	GetConsoleVarAsString("STRING", output, _);
	GetConsoleVarAsInt("STRING");
	GetConsoleVarAsBool("STRING");
	//GetServerTickRate();
	NetStats_GetIpPort(0, output, _);
	IsVehicleStreamedIn(0);
	/*GetVehiclePos(0, fvar, fvar, fvar);
	GetVehicleZAngle(0, fvar);
	GetVehicleRotationQuat(0, fvar, fvar, fvar, fvar);
	GetVehicleDistanceFromPoint(0, 0, 0, 0);
	GetVehicleParamsEx(0, vparams, vparams, vparams, vparams, vparams, vparams, vparams);
	GetVehicleParamsSirenState(0);
	GetVehicleParamsCarDoors(0, ivar, ivar, ivar, ivar);
	GetVehicleParamsCarWindows(0, ivar, ivar, ivar, ivar);
	GetVehicleHealth(0, fvar);
	IsTrailerAttachedToVehicle(0);
	GetVehicleTrailer(0);
	GetVehicleModel(0);
	GetVehicleComponentInSlot(0, CARMODTYPE_SPOILER);
	GetVehicleComponentType(0);
	GetVehicleVelocity(0, fvar, fvar, fvar);
	GetVehicleDamageStatus(0, ivar, ivar, ivar, ivar);
	GetVehicleModelInfo(0, ivar, fvar, fvar, fvar);
	GetVehicleVirtualWorld(0);
	IsValidVehicle(0);
	GetPlayerPos(0, fvar, fvar, fvar);
	GetPlayerFacingAngle(0, fvar);
	IsPlayerInRangeOfPoint(0, 0, 0, 0, 0);
	GetPlayerDistanceFromPoint(0, 0, 0, 0);
	IsPlayerStreamedIn(0);
	GetPlayerInterior(0);
	GetPlayerHealth(0, fvar);
	GetPlayerArmour(0, fvar);
	GetPlayerAmmo(0);
	GetPlayerWeaponState(0);
	GetPlayerTargetPlayer(0);
	GetPlayerTargetActor(0);
	GetPlayerTeam(0);
	GetPlayerScore(0);
	GetPlayerDrunkLevel(0);
	GetPlayerColor(0);
	GetPlayerSkin(0);
	GetPlayerCustomSkin(0);
	GetPlayerWeaponData(0, WEAPON_SLOT_UNARMED, ivar, ivar);
	GetPlayerMoney(0);
	GetPlayerState(0);
	GetPlayerIp(0, output, _);
	GetPlayerPing(0);
	GetPlayerWeapon(0);
	GetPlayerKeys(0, ivar, ivar, ivar);
	GetPlayerName(0, output, _);
	GetPlayerTime(0, ivar, ivar);
	GetPlayerWantedLevel(0);
	GetPlayerFightingStyle(0);
	GetPlayerVelocity(0, fvar, fvar, fvar);
	GetPlayerSurfingVehicleID(0);
	GetPlayerSurfingObjectID(0);
	GetPlayerLastShotVectors(0, fvar, fvar, fvar, fvar, fvar, fvar);
	GetPVarInt(0, "STRING");
	GetPVarString(0, "STRING", output, _);
	GetPVarFloat(0, "STRING");
	GetPVarsUpperIndex(0);
	GetPVarNameAtIndex(0, 0, output, _);
	GetPVarType(0, "STRING");
	GetPlayerVehicleID(0);
	GetPlayerVehicleSeat(0);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0, output, _, output, _);
	GetPlayerSpecialAction(0);
	GetPlayerCameraPos(0, fvar, fvar, fvar);
	GetPlayerCameraFrontVector(0, fvar, fvar, fvar);
	GetPlayerCameraMode(0);
	GetPlayerCameraTargetObject(0);
	GetPlayerCameraTargetVehicle(0);
	GetPlayerCameraTargetPlayer(0);
	GetPlayerCameraTargetActor(0);
	GetPlayerCameraAspectRatio(0);
	GetPlayerCameraZoom(0);
	IsPlayerConnected(0);
	IsPlayerInVehicle(0, 0);
	IsPlayerInAnyVehicle(0);
	IsPlayerInCheckpoint(0);
	IsPlayerInRaceCheckpoint(0);
	GetObjectPos(0, fvar, fvar, fvar);
	GetObjectRot(0, fvar, fvar, fvar);
	GetObjectModel(0);
	IsValidObject(0);
	IsObjectMoving(0);
	GetPlayerObjectPos(0, 0, fvar, fvar, fvar);
	GetPlayerObjectRot(0, 0, fvar, fvar, fvar);
	GetPlayerObjectModel(0, 0);
	IsValidPlayerObject(0, 0);
	MovePlayerObject(0, 0, 0, 0, 0, 0, -1000.0, -1000.0, -1000.0);
	IsPlayerObjectMoving(0, 0);
	HTTP(0, 0, "STRING", "STRING", "STRING");
	IsActorStreamedIn(0);
	GetActorVirtualWorld(0);
	GetActorPos(0, fvar, fvar, fvar);
	GetActorFacingAngle(0, fvar);
	GetActorHealth(0, fvar);
	IsActorInvulnerable(0);
	IsValidActor(0);*/


	// API
	GetDefaultPlayerColour(0);
	GetVehicleSeats(0);
	VehicleCanHaveComponent(0, 0);
	ivar = IsValidAnimationLibrary("STRING");
	GetRandomCarColPair(0, ivar, ivar);
	CarColIndexToColour(0);
}


