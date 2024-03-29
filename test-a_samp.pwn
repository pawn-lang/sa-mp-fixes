//#define STRONG_TAGS
//#pragma warning disable 234
//#define FIXES_Single 0
//#define FIX_const 0
//#define FIX_bool_tags 0

#tryinclude <samp-stdlib\a_samp>
#tryinclude <a_samp>
#if !defined _http_included
	#include <a_http>
#endif

#undef MAX_PLAYERS
#define MAX_PLAYERS (100)

#if !defined SendClientCheck
	native SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount);
#endif

#if !defined GetPlayerCustomSkin
	native GetPlayerCustomSkin(playerid);
#endif

#if !defined AddCharModel
	native AddCharModel(baseid, newid, const dff[], const textureLibrary[]);
#endif

#if !defined AddSimpleModel
	native AddSimpleModel(virtualWorld, baseid, newid, const dff[], const textureLibrary[]);
#endif

#if !defined AddSimpleModelTimed
	native AddSimpleModelTimed(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff);
#endif

#if !defined FindModelFileNameFromCRC
	native FindModelFileNameFromCRC(crc, output[], retstr_size = sizeof (output));
#endif

#if !defined FindTextureFileNameFromCRC
	native FindTextureFileNameFromCRC(crc, output[], retstr_size = sizeof (output));
#endif

#if !defined RedirectDownload
	native RedirectDownload(playerid, const url[]);
#endif

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
	new Float:fvar;
	new VEHICLE_PARAMS:vparams;
	new WEAPON:wvar;
	new KEY:kvar;
	new ACTION:avar;

	// Gives a warning.
	fgetchar(File:0, 0, false);
	// Doesn't give a warning.
	fgetchar(File:0, false);

	// Using defaults.
	Print__("STRING");
	PrintF__("STRING");
	Format__(output, _, "STRING");
	SendClientMessage(0, 0, "STRING");
	SendClientMessageToAll(0, "STRING");
	SendPlayerMessageToPlayer(0, 0, "STRING");
	SendPlayerMessageToAll(0, "STRING");
	SendDeathMessage(0, 0, 0);
	SendDeathMessageToPlayer(0, 0, 0, 0);
	GameTextForAll("STRING", 0, 0);
	GameTextForPlayer(0, "STRING", 0, 0);
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
	SHA256_PassHash("STRING", "STRING", output, _);
	SetSVarInt("STRING", 0);
	GetSVarInt("STRING");
	SetSVarString("STRING", "STRING");
	GetSVarString("STRING", output, _);
	SetSVarFloat("STRING", 0);
	GetSVarFloat("STRING");
	DeleteSVar("STRING");
	GetSVarsUpperIndex();
	GetSVarNameAtIndex(0, output, sizeof (output));
	GetSVarType("STRING");
	SetGameModeText("STRING");
	SetTeamCount(0);
	AddPlayerClass(0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	AddPlayerClassEx(0, 0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	AddStaticVehicle(0, 0, 0, 0, 0, 0, 0);
	AddStaticVehicleEx(0, 0, 0, 0, 0, 0, 0, 0);
	AddStaticPickup(0, 0, 0, 0, 0);
	CreatePickup(0, 0, 0, 0, 0);
	DestroyPickup(0);
	ShowNameTags(false);
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);
	GameModeExit();
	SetWorldTime(0);
	GetWeaponName(WEAPON_FIST, output, _);
	EnableTirePopping(true);
	EnableVehicleFriendlyFire();
	AllowInteriorWeapons(false);
	SetWeather(0);
	GetGravity();
	SetGravity(0);
	AllowAdminTeleport(false);
	SetDeathDropAmount(0);
	CreateExplosion(0, 0, 0, 0, 0);
	EnableZoneNames(false);
	UsePlayerPedAnims();
	DisableInteriorEnterExits();
	SetNameTagDrawDistance(0);
	DisableNameTagLOS();
	LimitGlobalChatRadius(0);
	LimitPlayerMarkerRadius(0);
	ConnectNPC("STRING", "STRING");
	IsPlayerNPC(0);
	AddCharModel(0, 0, "STRING", "STRING");
	AddSimpleModel(0, 0, 0, "STRING", "STRING");
	AddSimpleModelTimed(0, 0, 0, "STRING", "STRING", 0, 0);
	FindModelFileNameFromCRC(0, output, _);
	FindTextureFileNameFromCRC(0, output, _);
	RedirectDownload(0, "STRING");
	IsPlayerAdmin(0);
	Kick(0);
	Ban(0);
	BanEx(0, "STRING");
	SendRconCommand("STRING");
	GetPlayerNetworkStats(0, output, sizeof (output));
	GetNetworkStats(output, sizeof (output));
	GetPlayerVersion(0, output, sizeof (output));
	BlockIpAddress("STRING", 0);
	UnBlockIpAddress("STRING");
	GetServerVarAsString("STRING", output, sizeof (output));
	GetServerVarAsInt("STRING");
	GetServerVarAsBool("STRING");
	GetConsoleVarAsString("STRING", output, sizeof (output));
	GetConsoleVarAsInt("STRING");
	GetConsoleVarAsBool("STRING");
	GetServerTickRate();
	NetStats_GetConnectedTime(0);
	NetStats_MessagesReceived(0);
	NetStats_BytesReceived(0);
	NetStats_MessagesSent(0);
	NetStats_BytesSent(0);
	NetStats_MessagesRecvPerSecond(0);
	NetStats_PacketLossPercent(0);
	NetStats_ConnectionStatus(0);
	NetStats_GetIpPort(0, output, sizeof (output));
	CreateMenu("STRING", 0, 0, 0, 0.0);
	DestroyMenu(INVALID_MENU);
	AddMenuItem(INVALID_MENU, 0, "STRING");
	SetMenuColumnHeader(INVALID_MENU, 0, "STRING");
	ShowMenuForPlayer(INVALID_MENU, 0);
	HideMenuForPlayer(INVALID_MENU, 0);
	IsValidMenu(INVALID_MENU);
	DisableMenu(INVALID_MENU);
	DisableMenuRow(INVALID_MENU, 0);
	GetPlayerMenu(0);
	TextDrawCreate(0, 0, "STRING");
	TextDrawDestroy(INVALID_TEXT_DRAW);
	TextDrawLetterSize(INVALID_TEXT_DRAW, 0, 0);
	TextDrawTextSize(INVALID_TEXT_DRAW, 0, 0);
	TextDrawAlignment(INVALID_TEXT_DRAW, TEXT_DRAW_ALIGN_LEFT);
	TextDrawColor(INVALID_TEXT_DRAW, 0);
	TextDrawUseBox(INVALID_TEXT_DRAW, false);
	TextDrawBoxColor(INVALID_TEXT_DRAW, 0);
	TextDrawSetShadow(INVALID_TEXT_DRAW, 0);
	TextDrawSetOutline(INVALID_TEXT_DRAW, 0);
	TextDrawBackgroundColor(INVALID_TEXT_DRAW, 0);
	TextDrawFont(INVALID_TEXT_DRAW, TEXT_DRAW_FONT_0);
	TextDrawSetProportional(INVALID_TEXT_DRAW, false);
	TextDrawSetSelectable(INVALID_TEXT_DRAW, false);
	TextDrawShowForPlayer(0, INVALID_TEXT_DRAW);
	TextDrawHideForPlayer(0, INVALID_TEXT_DRAW);
	TextDrawShowForAll(INVALID_TEXT_DRAW);
	TextDrawHideForAll(INVALID_TEXT_DRAW);
	TextDrawSetString(INVALID_TEXT_DRAW, "STRING");
	TextDrawSetPreviewModel(INVALID_TEXT_DRAW, 0);
	TextDrawSetPreviewRot(INVALID_TEXT_DRAW, 0, 0, 0.0);
	TextDrawSetPreviewVehCol(INVALID_TEXT_DRAW, 0, 0);
	GangZoneCreate(0, 0, 0, 0);
	GangZoneDestroy(0);
	GangZoneShowForPlayer(0, 0, 0);
	GangZoneShowForAll(0, 0);
	GangZoneHideForPlayer(0, 0);
	GangZoneHideForAll(0);
	GangZoneFlashForPlayer(0, 0, 0);
	GangZoneFlashForAll(0, 0);
	GangZoneStopFlashForPlayer(0, 0);
	GangZoneStopFlashForAll(0);
	Create3DTextLabel("STRING", 0, 0, 0, 0, 0, 0);
	Delete3DTextLabel(INVALID_3DTEXT_ID);
	Attach3DTextLabelToPlayer(INVALID_3DTEXT_ID, 0, 0, 0, 0);
	Attach3DTextLabelToVehicle(INVALID_3DTEXT_ID, 0, 0, 0, 0);
	Update3DTextLabelText(INVALID_3DTEXT_ID, 0, "STRING");
	CreatePlayer3DTextLabel(0, "STRING", 0, 0, 0, 0, 0);
	DeletePlayer3DTextLabel(0, INVALID_PLAYER_3DTEXT_ID);
	UpdatePlayer3DTextLabelText(0, INVALID_PLAYER_3DTEXT_ID, 0, "STRING");
	ShowPlayerDialog(0, 0, DIALOG_STYLE_MSGBOX, "STRING", "STRING", "STRING", "STRING");
	gpci(0, output, _);
	CreateVehicle(0, 0, 0, 0, 0, 0, 0, 0);
	DestroyVehicle(0);
	IsVehicleStreamedIn(0, 0);
	GetVehiclePos(0, fvar, fvar, fvar);
	SetVehiclePos(0, 0, 0, 0);
	GetVehicleZAngle(0, fvar);
	GetVehicleRotationQuat(0, fvar, fvar, fvar, fvar);
	GetVehicleDistanceFromPoint(0, 0, 0, 0);
	SetVehicleZAngle(0, 0);
	SetVehicleParamsForPlayer(0, 0, 0, 0);
	ManualVehicleEngineAndLights();
	SetVehicleParamsEx(0, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON);
	GetVehicleParamsEx(0, vparams, vparams, vparams, vparams, vparams, vparams, vparams);
	GetVehicleParamsSirenState(0);
	SetVehicleParamsCarDoors(0, 0, 0, 0, 0);
	GetVehicleParamsCarDoors(0, ivar, ivar, ivar, ivar);
	SetVehicleParamsCarWindows(0, 0, 0, 0, 0);
	GetVehicleParamsCarWindows(0, ivar, ivar, ivar, ivar);
	SetVehicleToRespawn(0);
	LinkVehicleToInterior(0, 0);
	AddVehicleComponent(0, 0);
	RemoveVehicleComponent(0, 0);
	ChangeVehicleColor(0, 0, 0);
	ChangeVehiclePaintjob(0, 0);
	SetVehicleHealth(0, 0);
	GetVehicleHealth(0, fvar);
	AttachTrailerToVehicle(0, 0);
	DetachTrailerFromVehicle(0);
	IsTrailerAttachedToVehicle(0);
	GetVehicleTrailer(0);
	SetVehicleNumberPlate(0, "STRING");
	GetVehicleModel(0);
	GetVehicleComponentInSlot(0, CARMODTYPE_EXHAUST);
	GetVehicleComponentType(0);
	RepairVehicle(0);
	GetVehicleVelocity(0, fvar, fvar, fvar);
	SetVehicleVelocity(0, 0, 0, 0);
	SetVehicleAngularVelocity(0, 0, 0, 0);
	GetVehicleDamageStatus(0, ivar, ivar, ivar, ivar);
	UpdateVehicleDamageStatus(0, VEHICLE_PANEL_STATUS_NONE, VEHICLE_DOOR_STATUS_NONE, 0, 0);
	GetVehicleModelInfo(0, VEHICLE_MODEL_INFO_SIZE, fvar, fvar, fvar);
	SetVehicleVirtualWorld(0, 0);
	GetVehicleVirtualWorld(0);
	IsValidVehicle(0);
	DB_Open__("STRING");
	DB_Close__(DB:0);
	DB_Query__(DB:0, "STRING");
	DB_FreeResult__(DBResult:0);
	DB_NumRows__(DBResult:0);
	DB_NextRow__(DBResult:0);
	DB_NumFields__(DBResult:0);
	DB_FieldName__(DBResult:0, 0, output, _);
	DB_GetField__(DBResult:0, 0, output, _);
	DB_GetFieldInt__(DBResult:0);
	DB_GetFieldFloat__(DBResult:0);
	DB_GetFieldAssoc__(DBResult:0, "STRING", output, _);
	DB_GetFieldAssocInt__(DBResult:0, "STRING");
	DB_GetFieldAssocFloat__(DBResult:0, "STRING");
	DB_GetMemHandle__(DB:0);
	DB_GetResultMemHandle__(DBResult:0);
	DB_DebugOpenFiles__();
	DB_DebugOpenResults__();
	SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	SpawnPlayer(0);
	SetPlayerPos(0, 0, 0, 0);
	SetPlayerPosFindZ(0, 0, 0, 0);
	GetPlayerPos(0, fvar, fvar, fvar);
	SetPlayerFacingAngle(0, 0);
	GetPlayerFacingAngle(0, fvar);
	IsPlayerInRangeOfPoint(0, 0, 0, 0, 0);
	GetPlayerDistanceFromPoint(0, 0, 0, 0);
	IsPlayerStreamedIn(0, 0);
	SetPlayerInterior(0, 0);
	GetPlayerInterior(0);
	SetPlayerHealth(0, 0);
	GetPlayerHealth(0, fvar);
	SetPlayerArmour(0, 0);
	GetPlayerArmour(0, fvar);
	SetPlayerAmmo(0, WEAPON_FIST, 0);
	GetPlayerAmmo(0);
	GetPlayerWeaponState(0);
	GetPlayerTargetPlayer(0);
	GetPlayerTargetActor(0);
	SetPlayerTeam(0, 0);
	GetPlayerTeam(0);
	SetPlayerScore(0, 0);
	GetPlayerScore(0);
	GetPlayerDrunkLevel(0);
	SetPlayerDrunkLevel(0, 0);
	SetPlayerColor(0, 0);
	GetPlayerColor(0);
	SetPlayerSkin(0, 0);
	GetPlayerSkin(0);
	GetPlayerCustomSkin__(0);
	GivePlayerWeapon(0, WEAPON_FIST, 0);
	ResetPlayerWeapons(0);
	SetPlayerArmedWeapon(0, WEAPON_FIST);
	GetPlayerWeaponData(0, WEAPON_SLOT_UNARMED, wvar, ivar);
	GivePlayerMoney(0, 0);
	ResetPlayerMoney(0);
	SetPlayerName(0, "STRING");
	GetPlayerMoney(0);
	GetPlayerState(0);
	GetPlayerIp(0, output, sizeof (output));
	GetPlayerPing(0);
	GetPlayerWeapon(0);
	GetPlayerKeys(0, kvar, kvar, kvar);
	GetPlayerActions(0, avar, avar, avar);
	GetPlayerName(0, output, sizeof (output));
	SetPlayerTime(0, 0, 0);
	GetPlayerTime(0, ivar, ivar);
	TogglePlayerClock(0, false);
	SetPlayerWeather(0, 0);
	ForceClassSelection(0);
	SetPlayerWantedLevel(0, 0);
	GetPlayerWantedLevel(0);
	SetPlayerFightingStyle(0, FIGHT_STYLE_KUNGFU);
	GetPlayerFightingStyle(0);
	SetPlayerVelocity(0, 0, 0, 0);
	GetPlayerVelocity(0, fvar, fvar, fvar);
	PlayCrimeReportForPlayer(0, 0, 0);
	PlayAudioStreamForPlayer(0, "STRING");
	StopAudioStreamForPlayer(0);
	SetPlayerShopName(0, "STRING");
	SetPlayerSkillLevel(0, WEAPONSKILL_PISTOL_SILENCED, 0);
	GetPlayerSurfingVehicleID(0);
	GetPlayerSurfingObjectID(0);
	RemoveBuildingForPlayer(0, 0, 0, 0, 0, 0);
	GetPlayerLastShotVectors(0, fvar, fvar, fvar, fvar, fvar, fvar);
	SetPlayerAttachedObject(0, 0, 0, 0);
	RemovePlayerAttachedObject(0, 0);
	IsPlayerAttachedObjectSlotUsed(0, 0);
	EditAttachedObject(0, 0);
	CreatePlayerTextDraw(0, 0, 0, "STRING");
	PlayerTextDrawDestroy(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawLetterSize(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	PlayerTextDrawTextSize(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	PlayerTextDrawAlignment(0, INVALID_PLAYER_TEXT_DRAW, TEXT_DRAW_ALIGN_CENTER);
	PlayerTextDrawColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawUseBox(0, INVALID_PLAYER_TEXT_DRAW, true);
	PlayerTextDrawBoxColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetShadow(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetOutline(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawBackgroundColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawFont(0, INVALID_PLAYER_TEXT_DRAW, TEXT_DRAW_FONT_2);
	PlayerTextDrawSetProportional(0, INVALID_PLAYER_TEXT_DRAW, false);
	PlayerTextDrawSetSelectable(0, INVALID_PLAYER_TEXT_DRAW, false);
	PlayerTextDrawShow(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawHide(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawSetString(0, INVALID_PLAYER_TEXT_DRAW, "STRING");
	PlayerTextDrawSetPreviewModel(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetPreviewRot(0, INVALID_PLAYER_TEXT_DRAW, 0, 0, 0.0);
	PlayerTextDrawSetPreviewVehCol(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	SetPVarInt(0, "STRING", 0);
	GetPVarInt(0, "STRING");
	SetPVarString(0, "STRING", "STRING");
	GetPVarString(0, "STRING", output, _);
	SetPVarFloat(0, "STRING", 0);
	GetPVarFloat(0, "STRING");
	DeletePVar(0, "STRING");
	GetPVarsUpperIndex(0);
	GetPVarNameAtIndex(0, 0, output, sizeof (output));
	GetPVarType(0, "STRING");
	SetPlayerChatBubble(0, "STRING", 0, 0, 0);
	PutPlayerInVehicle(0, 0, 0);
	GetPlayerVehicleID(0);
	GetPlayerVehicleSeat(0);
	RemovePlayerFromVehicle(0);
	TogglePlayerControllable(0, true);
	PlayerPlaySound(0, 0, 0, 0, 0);
	ApplyAnimation(0, "STRING", "STRING", 0.0, false, false, false, false, 0);
	ClearAnimations(0);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0, output, sizeof (output), output, sizeof (output));
	GetPlayerSpecialAction(0);
	SetPlayerSpecialAction(0, SPECIAL_ACTION_SMOKE_CIGGY);
	DisableRemoteVehicleCollisions(0, false);
	SetPlayerCheckpoint(0, 0, 0, 0, 0);
	DisablePlayerCheckpoint(0);
	SetPlayerRaceCheckpoint(0, CP_TYPE_GROUND_NORMAL, 0, 0, 0, 0, 0, 0, 0);
	DisablePlayerRaceCheckpoint(0);
	SetPlayerWorldBounds(0, 0, 0, 0, 0);
	SetPlayerMarkerForPlayer(0, 0, 0);
	ShowPlayerNameTagForPlayer(0, 0, false);
	SetPlayerMapIcon(0, 0, 0, 0, 0, 0, 0);
	RemovePlayerMapIcon(0, 0);
	AllowPlayerTeleport(0, false);
	SetPlayerCameraPos(0, 0, 0, 0);
	SetPlayerCameraLookAt(0, 0, 0, 0);
	SetCameraBehindPlayer(0);
	GetPlayerCameraPos(0, fvar, fvar, fvar);
	GetPlayerCameraFrontVector(0, fvar, fvar, fvar);
	GetPlayerCameraMode(0);
	EnablePlayerCameraTarget(0, false);
	GetPlayerCameraTargetObject(0);
	GetPlayerCameraTargetVehicle(0);
	GetPlayerCameraTargetPlayer(0);
	GetPlayerCameraTargetActor(0);
	GetPlayerCameraAspectRatio(0);
	GetPlayerCameraZoom(0);
	AttachCameraToObject(0, 0);
	AttachCameraToPlayerObject(0, 0);
	InterpolateCameraPos(0, 0, 0, 0, 0, 0, 0, 0);
	InterpolateCameraLookAt(0, 0, 0, 0, 0, 0, 0, 0);
	IsPlayerConnected(0);
	IsPlayerInVehicle(0, 0);
	IsPlayerInAnyVehicle(0);
	IsPlayerInCheckpoint(0);
	IsPlayerInRaceCheckpoint(0);
	SetPlayerVirtualWorld(0, 0);
	GetPlayerVirtualWorld(0);
	EnableStuntBonusForPlayer(0, false);
	EnableStuntBonusForAll(false);
	TogglePlayerSpectating(0, false);
	PlayerSpectatePlayer(0, 0);
	PlayerSpectateVehicle(0, 0);
	StartRecordingPlayerData(0, PLAYER_RECORDING_TYPE_ONFOOT, "STRING");
	StopRecordingPlayerData(0);
	SelectTextDraw(0, 0);
	CancelSelectTextDraw(0);
	CreateExplosionForPlayer(0, 0, 0, 0, 0, 0);
	SendClientCheck(0, 0, 0, 0, 0);
	CreateObject(0, 0, 0, 0, 0, 0, 0.0);
	AttachObjectToVehicle(0, 0, 0, 0, 0, 0, 0, 0);
	AttachObjectToObject(0, 0, 0, 0, 0, 0, 0, 0);
	AttachObjectToPlayer(0, 0, 0, 0, 0, 0, 0, 0);
	SetObjectPos(0, 0, 0, 0);
	GetObjectPos(0, fvar, fvar, fvar);
	SetObjectRot(0, 0, 0, 0);
	GetObjectRot(0, fvar, fvar, fvar);
	GetObjectModel(0);
	SetObjectNoCameraCol(0);
	IsValidObject(0);
	DestroyObject(0);
	MoveObject(0, 0, 0, 0, 0);
	StopObject(0);
	IsObjectMoving(0);
	EditObject(0, 0);
	EditPlayerObject(0, 0);
	SelectObject(0);
	CancelEdit(0);
	CreatePlayerObject(0, 0, 0, 0, 0, 0, 0, 0.0);
	AttachPlayerObjectToVehicle(0, 0, 0, 0, 0, 0, 0, 0, 0);
	SetPlayerObjectPos(0, 0, 0, 0, 0);
	GetPlayerObjectPos(0, 0, fvar, fvar, fvar);
	SetPlayerObjectRot(0, 0, 0, 0, 0);
	GetPlayerObjectRot(0, 0, fvar, fvar, fvar);
	GetPlayerObjectModel(0, 0);
	SetPlayerObjectNoCameraCol(0, 0);
	IsValidPlayerObject(0, 0);
	DestroyPlayerObject(0, 0);
	MovePlayerObject(0, 0, 0, 0, 0, 0);
	StopPlayerObject(0, 0);
	IsPlayerObjectMoving(0, 0);
	AttachPlayerObjectToPlayer(0, 0, 0, 0, 0, 0, 0, 0, 0);
	SetObjectMaterial(0, 0, 0, "STRING", "STRING");
	SetPlayerObjectMaterial(0, 0, 0, 0, "STRING", "STRING");
	SetObjectMaterialText(0, "STRING");
	SetPlayerObjectMaterialText(0, 0, "STRING");
	SetObjectsDefaultCameraCol(false);
	HTTP(0, HTTP_GET, "STRING", "STRING", "STRING");
	CreateActor(0, 0, 0, 0, 0);
	DestroyActor(0);
	IsActorStreamedIn(0, 0);
	SetActorVirtualWorld(0, 0);
	GetActorVirtualWorld(0);
	ApplyActorAnimation(0, "STRING", "STRING", 0.0, false, false, false, false, 0);
	ClearActorAnimations(0);
	SetActorPos(0, 0, 0, 0);
	GetActorPos(0, fvar, fvar, fvar);
	SetActorFacingAngle(0, 0);
	GetActorFacingAngle(0, fvar);
	SetActorHealth(0, 0);
	GetActorHealth(0, fvar);
	SetActorInvulnerable(0);
	IsActorInvulnerable(0);
	IsValidActor(0);




	// Using explicits.
	print("STRING");
	printf("STRING");
	format(output, _, "STRING");
	SendClientMessage(0, 0, "STRING");
	SendClientMessageToAll(0, "STRING");
	SendPlayerMessageToPlayer(0, 0, "STRING");
	SendPlayerMessageToAll(0, "STRING");
	SendDeathMessage(0, 0, 0);
	SendDeathMessageToPlayer(0, 0, 0, 0);
	GameTextForAll("STRING", 0, 0);
	GameTextForPlayer(0, "STRING", 0, 0);
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
	GetPlayerPoolSize();
	GetVehiclePoolSize();
	GetActorPoolSize();
	SHA256_PassHash("STRING", "STRING", output, _);
	SetSVarInt("STRING", 0);
	GetSVarInt("STRING");
	SetSVarString("STRING", "STRING");
	GetSVarString("STRING", output, _);
	SetSVarFloat("STRING", 0);
	GetSVarFloat("STRING");
	DeleteSVar("STRING");
	GetSVarsUpperIndex();
	GetSVarNameAtIndex(0, output, _);
	GetSVarType("STRING");
	SetGameModeText("STRING");
	SetTeamCount(0);
	AddPlayerClass(0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	AddPlayerClassEx(0, 0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	AddStaticVehicle(0, 0, 0, 0, 0, 0, 0);
	AddStaticVehicleEx(0, 0, 0, 0, 0, 0, 0, 0, false);
	AddStaticPickup(0, 0, 0, 0, 0, 0);
	CreatePickup(0, 0, 0, 0, 0, 0);
	DestroyPickup(0);
	ShowNameTags(true);
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	GameModeExit();
	SetWorldTime(0);
	GetWeaponName(WEAPON_FIST, output, _);
	EnableTirePopping(true);
	EnableVehicleFriendlyFire();
	AllowInteriorWeapons(false);
	SetWeather(0);
	GetGravity();
	SetGravity(0);
	AllowAdminTeleport(false);
	SetDeathDropAmount(0);
	CreateExplosion(0, 0, 0, 0, 0);
	EnableZoneNames(true);
	UsePlayerPedAnims();
	DisableInteriorEnterExits();
	SetNameTagDrawDistance(0);
	DisableNameTagLOS();
	LimitGlobalChatRadius(0);
	LimitPlayerMarkerRadius(0);
	ConnectNPC("STRING", "STRING");
	IsPlayerNPC(0);
	AddCharModel(0, 0, "STRING", "STRING");
	AddSimpleModel(0, 0, 0, "STRING", "STRING");
	AddSimpleModelTimed(0, 0, 0, "STRING", "STRING", 0, 0);
	FindModelFileNameFromCRC(0, output, _);
	FindTextureFileNameFromCRC(0, output, _);
	RedirectDownload(0, "STRING");
	IsPlayerAdmin(0);
	Kick(0);
	Ban(0);
	BanEx(0, "STRING");
	SendRconCommand("STRING");
	GetPlayerNetworkStats(0, output, _);
	GetNetworkStats(output, _);
	GetPlayerVersion(0, output, _);
	BlockIpAddress("STRING", 0);
	UnBlockIpAddress("STRING");
	GetServerVarAsString("STRING", output, _);
	GetServerVarAsInt("STRING");
	GetServerVarAsBool("STRING");
	GetConsoleVarAsString("STRING", output, _);
	GetConsoleVarAsInt("STRING");
	GetConsoleVarAsBool("STRING");
	GetServerTickRate();
	NetStats_GetConnectedTime(0);
	NetStats_MessagesReceived(0);
	NetStats_BytesReceived(0);
	NetStats_MessagesSent(0);
	NetStats_BytesSent(0);
	NetStats_MessagesRecvPerSecond(0);
	NetStats_PacketLossPercent(0);
	NetStats_ConnectionStatus(0);
	NetStats_GetIpPort(0, output, _);
	CreateMenu("STRING", 0, 0, 0, 0, 0.0);
	DestroyMenu(INVALID_MENU);
	AddMenuItem(INVALID_MENU, 0, "STRING");
	SetMenuColumnHeader(INVALID_MENU, 0, "STRING");
	ShowMenuForPlayer(INVALID_MENU, 0);
	HideMenuForPlayer(INVALID_MENU, 0);
	IsValidMenu(INVALID_MENU);
	DisableMenu(INVALID_MENU);
	DisableMenuRow(INVALID_MENU, 0);
	GetPlayerMenu(0);
	TextDrawCreate(0, 0, "STRING");
	TextDrawDestroy(INVALID_TEXT_DRAW);
	TextDrawLetterSize(INVALID_TEXT_DRAW, 0, 0);
	TextDrawTextSize(INVALID_TEXT_DRAW, 0, 0);
	TextDrawAlignment(INVALID_TEXT_DRAW, TEXT_DRAW_ALIGN_RIGHT);
	TextDrawColor(INVALID_TEXT_DRAW, 0);
	TextDrawUseBox(INVALID_TEXT_DRAW, true);
	TextDrawBoxColor(INVALID_TEXT_DRAW, 0);
	TextDrawSetShadow(INVALID_TEXT_DRAW, 0);
	TextDrawSetOutline(INVALID_TEXT_DRAW, 0);
	TextDrawBackgroundColor(INVALID_TEXT_DRAW, 0);
	TextDrawFont(INVALID_TEXT_DRAW, TEXT_DRAW_FONT_3);
	TextDrawSetProportional(INVALID_TEXT_DRAW, false);
	TextDrawSetSelectable(INVALID_TEXT_DRAW, false);
	TextDrawShowForPlayer(0, INVALID_TEXT_DRAW);
	TextDrawHideForPlayer(0, INVALID_TEXT_DRAW);
	TextDrawShowForAll(INVALID_TEXT_DRAW);
	TextDrawHideForAll(INVALID_TEXT_DRAW);
	TextDrawSetString(INVALID_TEXT_DRAW, "STRING");
	TextDrawSetPreviewModel(INVALID_TEXT_DRAW, 0);
	TextDrawSetPreviewRot(INVALID_TEXT_DRAW, 0, 0, 0, 1.0);
	TextDrawSetPreviewVehCol(INVALID_TEXT_DRAW, 0, 0);
	GangZoneCreate(0, 0, 0, 0);
	GangZoneDestroy(0);
	GangZoneShowForPlayer(0, 0, 0);
	GangZoneShowForAll(0, 0);
	GangZoneHideForPlayer(0, 0);
	GangZoneHideForAll(0);
	GangZoneFlashForPlayer(0, 0, 0);
	GangZoneFlashForAll(0, 0);
	GangZoneStopFlashForPlayer(0, 0);
	GangZoneStopFlashForAll(0);
	Create3DTextLabel("STRING", 0, 0, 0, 0, 0, 0, false);
	Delete3DTextLabel(INVALID_3DTEXT_ID);
	Attach3DTextLabelToPlayer(INVALID_3DTEXT_ID, 0, 0, 0, 0);
	Attach3DTextLabelToVehicle(INVALID_3DTEXT_ID, 0, 0, 0, 0);
	Update3DTextLabelText(INVALID_3DTEXT_ID, 0, "STRING");
	CreatePlayer3DTextLabel(0, "STRING", 0, 0, 0, 0, 0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, false);
	DeletePlayer3DTextLabel(0, INVALID_PLAYER_3DTEXT_ID);
	UpdatePlayer3DTextLabelText(0, INVALID_PLAYER_3DTEXT_ID, 0, "STRING");
	ShowPlayerDialog(0, 0, DIALOG_STYLE_MSGBOX, "STRING", "STRING", "STRING", "STRING");
	gpci(0, output, _);
	GPCI(0, output, _);
	CreateVehicle(0, 0, 0, 0, 0, 0, 0, 0, false);
	DestroyVehicle(0);
	IsVehicleStreamedIn(0, 0);
	GetVehiclePos(0, fvar, fvar, fvar);
	SetVehiclePos(0, 0, 0, 0);
	GetVehicleZAngle(0, fvar);
	GetVehicleRotationQuat(0, fvar, fvar, fvar, fvar);
	GetVehicleDistanceFromPoint(0, 0, 0, 0);
	SetVehicleZAngle(0, fvar);
	SetVehicleParamsForPlayer(0, 0, 0, 0);
	ManualVehicleEngineAndLights();
	SetVehicleParamsEx(0, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON);
	GetVehicleParamsEx(0, vparams, vparams, vparams, vparams, vparams, vparams, vparams);
	GetVehicleParamsSirenState(0);
	SetVehicleParamsCarDoors(0, 0, 0, 0, 0);
	GetVehicleParamsCarDoors(0, ivar, ivar, ivar, ivar);
	SetVehicleParamsCarWindows(0, 0, 0, 0, 0);
	GetVehicleParamsCarWindows(0, ivar, ivar, ivar, ivar);
	SetVehicleToRespawn(0);
	LinkVehicleToInterior(0, 0);
	AddVehicleComponent(0, 0);
	RemoveVehicleComponent(0, 0);
	ChangeVehicleColor(0, 0, 0);
	ChangeVehiclePaintjob(0, 0);
	SetVehicleHealth(0, 0);
	GetVehicleHealth(0, fvar);
	AttachTrailerToVehicle(0, 0);
	DetachTrailerFromVehicle(0);
	IsTrailerAttachedToVehicle(0);
	GetVehicleTrailer(0);
	SetVehicleNumberPlate(0, "STRING");
	GetVehicleModel(0);
	GetVehicleComponentInSlot(0, CARMODTYPE_FRONT_BULLBAR);
	GetVehicleComponentType(0);
	RepairVehicle(0);
	GetVehicleVelocity(0, fvar, fvar, fvar);
	SetVehicleVelocity(0, 0, 0, 0);
	SetVehicleAngularVelocity(0, 0, 0, 0);
	GetVehicleDamageStatus(0, ivar, ivar, ivar, ivar);
	UpdateVehicleDamageStatus(0, VEHICLE_PANEL_STATUS_NONE, VEHICLE_DOOR_STATUS_NONE, 0, 0);
	GetVehicleModelInfo(0, VEHICLE_MODEL_INFO_SIZE, fvar, fvar, fvar);
	SetVehicleVirtualWorld(0, 0);
	GetVehicleVirtualWorld(0);
	IsValidVehicle(0);
	DB_Open__("STRING");
	DB_Close__(DB:0);
	DB_Query__(DB:0, "STRING");
	DB_FreeResult__(DBResult:0);
	DB_NumRows__(DBResult:0);
	DB_NextRow__(DBResult:0);
	DB_NumFields__(DBResult:0);
	DB_FieldName__(DBResult:0, 0, output, _);
	DB_GetField__(DBResult:0, 0, output, _);
	DB_GetFieldInt__(DBResult:0, 0);
	DB_GetFieldFloat__(DBResult:0, 0);
	DB_GetFieldAssoc__(DBResult:0, "STRING", output, _);
	DB_GetFieldAssocInt__(DBResult:0, "STRING");
	DB_GetFieldAssocFloat__(DBResult:0, "STRING");
	DB_GetMemHandle__(DB:0);
	DB_GetResultMemHandle__(DBResult:0);
	DB_DebugOpenFiles__();
	DB_DebugOpenResults__();
	SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
	SpawnPlayer(0);
	SetPlayerPos(0, 0, 0, 0);
	SetPlayerPosFindZ(0, 0, 0, 0);
	GetPlayerPos(0, fvar, fvar, fvar);
	SetPlayerFacingAngle(0, 0);
	GetPlayerFacingAngle(0, fvar);
	IsPlayerInRangeOfPoint(0, 0, 0, 0, 0);
	GetPlayerDistanceFromPoint(0, 0, 0, 0);
	IsPlayerStreamedIn(0, 0);
	SetPlayerInterior(0, 0);
	GetPlayerInterior(0);
	SetPlayerHealth(0, 0);
	GetPlayerHealth(0, fvar);
	SetPlayerArmour(0, 0);
	GetPlayerArmour(0, fvar);
	SetPlayerAmmo(0, WEAPON_FIST, 0);
	GetPlayerAmmo(0);
	GetPlayerWeaponState(0);
	GetPlayerTargetPlayer(0);
	GetPlayerTargetActor(0);
	SetPlayerTeam(0, 0);
	GetPlayerTeam(0);
	SetPlayerScore(0, 0);
	GetPlayerScore(0);
	GetPlayerDrunkLevel(0);
	SetPlayerDrunkLevel(0, 0);
	SetPlayerColor(0, 0);
	GetPlayerColor(0);
	SetPlayerSkin(0, 0);
	GetPlayerSkin(0);
	GetPlayerCustomSkin(0);
	GivePlayerWeapon(0, WEAPON_FIST, 0);
	ResetPlayerWeapons(0);
	SetPlayerArmedWeapon(0, WEAPON_FIST);
	GetPlayerWeaponData(0, WEAPON_SLOT_UNARMED, wvar, ivar);
	GivePlayerMoney(0, 0);
	ResetPlayerMoney(0);
	SetPlayerName(0, "STRING");
	GetPlayerMoney(0);
	GetPlayerState(0);
	GetPlayerIp(0, output, _);
	GetPlayerPing(0);
	GetPlayerWeapon(0);
	GetPlayerKeys(0, kvar, kvar, kvar);
	GetPlayerName(0, output, _);
	SetPlayerTime(0, 0, 0);
	GetPlayerTime(0, ivar, ivar);
	TogglePlayerClock(0, false);
	SetPlayerWeather(0, 0);
	ForceClassSelection(0);
	SetPlayerWantedLevel(0, 0);
	GetPlayerWantedLevel(0);
	SetPlayerFightingStyle(0, FIGHT_STYLE_BOXING);
	GetPlayerFightingStyle(0);
	SetPlayerVelocity(0, 0, 0, 0);
	GetPlayerVelocity(0, fvar, fvar, fvar);
	PlayCrimeReportForPlayer(0, 0, 0);
	PlayAudioStreamForPlayer(0, "STRING", 0.0, 0.0, 0.0, 50.0, false);
	StopAudioStreamForPlayer(0);
	SetPlayerShopName(0, "STRING");
	SetPlayerSkillLevel(0, WEAPONSKILL_SPAS12_SHOTGUN, 0);
	GetPlayerSurfingVehicleID(0);
	GetPlayerSurfingObjectID(0);
	RemoveBuildingForPlayer(0, 0, 0, 0, 0, 0);
	GetPlayerLastShotVectors(0, fvar, fvar, fvar, fvar, fvar, fvar);
	SetPlayerAttachedObject(0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
	RemovePlayerAttachedObject(0, 0);
	IsPlayerAttachedObjectSlotUsed(0, 0);
	EditAttachedObject(0, 0);
	CreatePlayerTextDraw(0, 0, 0, "STRING");
	PlayerTextDrawDestroy(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawLetterSize(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	PlayerTextDrawTextSize(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	PlayerTextDrawAlignment(0, INVALID_PLAYER_TEXT_DRAW, TEXT_DRAW_ALIGN_CENTRE);
	PlayerTextDrawColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawUseBox(0, INVALID_PLAYER_TEXT_DRAW, false);
	PlayerTextDrawBoxColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetShadow(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetOutline(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawBackgroundColor(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawFont(0, INVALID_PLAYER_TEXT_DRAW, TEXT_DRAW_FONT_MODEL_PREVIEW);
	PlayerTextDrawSetProportional(0, INVALID_PLAYER_TEXT_DRAW, false);
	PlayerTextDrawSetSelectable(0, INVALID_PLAYER_TEXT_DRAW, false);
	PlayerTextDrawShow(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawHide(0, INVALID_PLAYER_TEXT_DRAW);
	PlayerTextDrawSetString(0, INVALID_PLAYER_TEXT_DRAW, "STRING");
	PlayerTextDrawSetPreviewModel(0, INVALID_PLAYER_TEXT_DRAW, 0);
	PlayerTextDrawSetPreviewRot(0, INVALID_PLAYER_TEXT_DRAW, 0, 0, 0.0);
	PlayerTextDrawSetPreviewVehCol(0, INVALID_PLAYER_TEXT_DRAW, 0, 0);
	SetPVarInt(0, "STRING", 0);
	GetPVarInt(0, "STRING");
	SetPVarString(0, "STRING", "STRING");
	GetPVarString(0, "STRING", output, _);
	SetPVarFloat(0, "STRING", 0);
	GetPVarFloat(0, "STRING");
	DeletePVar(0, "STRING");
	GetPVarsUpperIndex(0);
	GetPVarNameAtIndex(0, 0, output, _);
	GetPVarType(0, "STRING");
	SetPlayerChatBubble(0, "STRING", 0, 0, 0);
	PutPlayerInVehicle(0, 0, 0);
	GetPlayerVehicleID(0);
	GetPlayerVehicleSeat(0);
	RemovePlayerFromVehicle(0);
	TogglePlayerControllable(0, true);
	PlayerPlaySound(0, 0, 0, 0, 0);
	ApplyAnimation(0, "STRING", "STRING", 0.0, false, false, false, false, 0, SYNC_ALL);
	ClearAnimations(0, SYNC_NONE);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0, output, _, output, _);
	GetPlayerSpecialAction(0);
	SetPlayerSpecialAction(0, SPECIAL_ACTION_STOPUSECELLPHONE);
	DisableRemoteVehicleCollisions(0, false);
	SetPlayerCheckpoint(0, 0, 0, 0, 0);
	DisablePlayerCheckpoint(0);
	SetPlayerRaceCheckpoint(0, CP_TYPE_GROUND_NORMAL, 0, 0, 0, 0, 0, 0, 0);
	DisablePlayerRaceCheckpoint(0);
	SetPlayerWorldBounds(0, 0, 0, 0, 0);
	SetPlayerMarkerForPlayer(0, 0, 0);
	ShowPlayerNameTagForPlayer(0, 0, true);
	SetPlayerMapIcon(0, 0, 0, 0, 0, 0, 0, MAPICON_LOCAL);
	RemovePlayerMapIcon(0, 0);
	AllowPlayerTeleport(0, false);
	SetPlayerCameraPos(0, 0, 0, 0);
	SetPlayerCameraLookAt(0, 0, 0, 0, CAMERA_CUT);
	SetCameraBehindPlayer(0);
	GetPlayerCameraPos(0, fvar, fvar, fvar);
	GetPlayerCameraFrontVector(0, fvar, fvar, fvar);
	GetPlayerCameraMode(0);
	EnablePlayerCameraTarget(0, true);
	GetPlayerCameraTargetObject(0);
	GetPlayerCameraTargetVehicle(0);
	GetPlayerCameraTargetPlayer(0);
	GetPlayerCameraTargetActor(0);
	GetPlayerCameraAspectRatio(0);
	GetPlayerCameraZoom(0);
	AttachCameraToObject(0, 0);
	AttachCameraToPlayerObject(0, 0);
	InterpolateCameraPos(0, 0, 0, 0, 0, 0, 0, 0, CAMERA_CUT);
	InterpolateCameraLookAt(0, 0, 0, 0, 0, 0, 0, 0, CAMERA_CUT);
	IsPlayerConnected(0);
	IsPlayerInVehicle(0, 0);
	IsPlayerInAnyVehicle(0);
	IsPlayerInCheckpoint(0);
	IsPlayerInRaceCheckpoint(0);
	SetPlayerVirtualWorld(0, 0);
	GetPlayerVirtualWorld(0);
	EnableStuntBonusForPlayer(0, false);
	EnableStuntBonusForAll(true);
	TogglePlayerSpectating(0, false);
	PlayerSpectatePlayer(0, 0, SPECTATE_MODE_NORMAL);
	PlayerSpectateVehicle(0, 0, SPECTATE_MODE_NORMAL);
	StartRecordingPlayerData(0, PLAYER_RECORDING_TYPE_DRIVER, "STRING");
	StopRecordingPlayerData(0);
	SelectTextDraw(0, 0);
	CancelSelectTextDraw(0);
	CreateExplosionForPlayer(0, 0, 0, 0, 0, 0);
	SendClientCheck(0, 0, 0, 0, 0);
	CreateObject(0, 0, 0, 0, 0, 0, 0, 0.0);
	AttachObjectToVehicle(0, 0, 0, 0, 0, 0, 0, 0);
	AttachObjectToObject(0, 0, 0, 0, 0, 0, 0, 0, true);
	AttachObjectToPlayer(0, 0, 0, 0, 0, 0, 0, 0);
	SetObjectPos(0, 0, 0, 0);
	GetObjectPos(0, fvar, fvar, fvar);
	SetObjectRot(0, 0, 0, 0);
	GetObjectRot(0, fvar, fvar, fvar);
	GetObjectModel(0);
	SetObjectNoCameraCol(0);
	IsValidObject(0);
	DestroyObject(0);
	MoveObject(0, 0, 0, 0, 0, -1000.0, -1000.0, -1000.0);
	StopObject(0);
	IsObjectMoving(0);
	EditObject(0, 0);
	EditPlayerObject(0, 0);
	SelectObject(0);
	CancelEdit(0);
	CreatePlayerObject(0, 0, 0, 0, 0, 0, 0, 0, 0.0);
	AttachPlayerObjectToVehicle(0, 0, 0, 0, 0, 0, 0, 0, 0);
	SetPlayerObjectPos(0, 0, 0, 0, 0);
	GetPlayerObjectPos(0, 0, fvar, fvar, fvar);
	SetPlayerObjectRot(0, 0, 0, 0, 0);
	GetPlayerObjectRot(0, 0, fvar, fvar, fvar);
	GetPlayerObjectModel(0, 0);
	SetPlayerObjectNoCameraCol(0, 0);
	IsValidPlayerObject(0, 0);
	DestroyPlayerObject(0, 0);
	MovePlayerObject(0, 0, 0, 0, 0, 0, -1000.0, -1000.0, -1000.0);
	StopPlayerObject(0, 0);
	IsPlayerObjectMoving(0, 0);
	AttachPlayerObjectToPlayer(0, 0, 0, 0, 0, 0, 0, 0, 0);
	SetObjectMaterial(0, 0, 0, "STRING", "STRING", 0);
	SetPlayerObjectMaterial(0, 0, 0, 0, "STRING", "STRING", 0);
	SetObjectMaterialText(0, "STRING", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, true, 0xFFFFFFFF, 0, OBJECT_MATERIAL_TEXT_ALIGN_LEFT);
	SetPlayerObjectMaterialText(0, 0, "STRING", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, true, 0xFFFFFFFF, 0, OBJECT_MATERIAL_TEXT_ALIGN_LEFT);
	SetObjectsDefaultCameraCol(false);
	HTTP(0, HTTP_POST, "STRING", "STRING", "STRING");
	CreateActor(0, 0, 0, 0, 0);
	DestroyActor(0);
	IsActorStreamedIn(0, 0);
	SetActorVirtualWorld(0, 0);
	GetActorVirtualWorld(0);
	ApplyActorAnimation(0, "STRING", "STRING", 0.0, false, false, false, false, 0);
	ClearActorAnimations(0);
	SetActorPos(0, 0, 0, 0);
	GetActorPos(0, fvar, fvar, fvar);
	SetActorFacingAngle(0, 0);
	GetActorFacingAngle(0, fvar);
	SetActorHealth(0, 0);
	GetActorHealth(0, fvar);
	SetActorInvulnerable(0, true);
	IsActorInvulnerable(0);
	IsValidActor(0);


	// API
	GetDefaultPlayerColour(0);
	GetVehicleSeats(0);
	VehicleCanHaveComponent(0, 0);
	ivar = IsValidAnimationLibrary("STRING");
	GetRandomCarColPair(0, ivar, ivar);
	CarColIndexToColour(0);
	PlayerHasClockEnabled(0);
	IsMenuValid(INVALID_MENU);
	GetPlayerDialog(0);
	HideGameTextForAll(0);
	HideGameTextForPlayer(0, 0);
	GetPlayerWorldBounds(0, fvar, fvar, fvar, fvar);
	ClearPlayerWorldBounds(0);
	GetPlayerWeather(0);
	GetWeather();
	ivar = GetWorldTime();
}

public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{
	return 1;
}

public OnPlayerActionStateChange(playerid, ACTION:newactions, ACTION:oldactions)
{
	return 1;
}


