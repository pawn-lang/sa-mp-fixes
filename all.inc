//
// a_actor
//

#if defined _ALS_CreateActor
	#error _ALS_CreateActor defined
#endif
native BAD_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
native FIXES_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
native CreateActor__(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
#define _ALS_CreateActor
#define CreateActor( FIXES_CreateActor(

#if defined _ALS_DestroyActor
	#error _ALS_DestroyActor defined
#endif
native BAD_DestroyActor(actorid) = DestroyActor;
native FIXES_DestroyActor(actorid) = DestroyActor;
native DestroyActor__(actorid) = DestroyActor;
#define _ALS_DestroyActor
#define DestroyActor( FIXES_DestroyActor(

#if defined _ALS_IsActorStreamedIn
	#error _ALS_IsActorStreamedIn defined
#endif
native BAD_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
native _FIXES_MAYBE_BOOL:FIXES_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
native bool:IsActorStreamedIn__(actorid, playerid) = IsActorStreamedIn;
#define _ALS_IsActorStreamedIn
#define IsActorStreamedIn( FIXES_IsActorStreamedIn(

#if defined _ALS_SetActorVirtualWorld
	#error _ALS_SetActorVirtualWorld defined
#endif
native BAD_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
native FIXES_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
native SetActorVirtualWorld__(actorid, virtualWorld) = SetActorVirtualWorld;
#define _ALS_SetActorVirtualWorld
#define SetActorVirtualWorld( FIXES_SetActorVirtualWorld(

#if defined _ALS_GetActorVirtualWorld
	#error _ALS_GetActorVirtualWorld defined
#endif
native BAD_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
native FIXES_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
native GetActorVirtualWorld__(actorid) = GetActorVirtualWorld;
#define _ALS_GetActorVirtualWorld
#define GetActorVirtualWorld( FIXES_GetActorVirtualWorld(

#if defined _ALS_ApplyActorAnimation
	#error _ALS_ApplyActorAnimation defined
#endif
native BAD_ApplyActorAnimation(actorid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time) = ApplyActorAnimation;
native FIXES_ApplyActorAnimation(actorid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time) = ApplyActorAnimation;
native ApplyActorAnimation__(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time) = ApplyActorAnimation;
#define _ALS_ApplyActorAnimation
#define ApplyActorAnimation( FIXES_ApplyActorAnimation(

#if defined _ALS_ClearActorAnimations
	#error _ALS_ClearActorAnimations defined
#endif
native BAD_ClearActorAnimations(actorid) = ClearActorAnimations;
native FIXES_ClearActorAnimations(actorid) = ClearActorAnimations;
native ClearActorAnimations__(actorid) = ClearActorAnimations;
#define _ALS_ClearActorAnimations
#define ClearActorAnimations( FIXES_ClearActorAnimations(

#if defined _ALS_SetActorPos
	#error _ALS_SetActorPos defined
#endif
native BAD_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
native FIXES_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
native SetActorPos__(actorid, Float:x, Float:y, Float:z) = SetActorPos;
#define _ALS_SetActorPos
#define SetActorPos( FIXES_SetActorPos(

#if defined _ALS_GetActorPos
	#error _ALS_GetActorPos defined
#endif
native BAD_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
native FIXES_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
native GetActorPos__(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
#define _ALS_GetActorPos
#define GetActorPos( FIXES_GetActorPos(

#if defined _ALS_SetActorFacingAngle
	#error _ALS_SetActorFacingAngle defined
#endif
native BAD_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
native FIXES_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
native SetActorFacingAngle__(actorid, Float:angle) = SetActorFacingAngle;
#define _ALS_SetActorFacingAngle
#define SetActorFacingAngle( FIXES_SetActorFacingAngle(

#if defined _ALS_GetActorFacingAngle
	#error _ALS_GetActorFacingAngle defined
#endif
native BAD_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
native FIXES_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
native GetActorFacingAngle__(actorid, &Float:angle) = GetActorFacingAngle;
#define _ALS_GetActorFacingAngle
#define GetActorFacingAngle( FIXES_GetActorFacingAngle(

#if defined _ALS_SetActorHealth
	#error _ALS_SetActorHealth defined
#endif
native BAD_SetActorHealth(actorid, Float:health) = SetActorHealth;
native FIXES_SetActorHealth(actorid, Float:health) = SetActorHealth;
native SetActorHealth__(actorid, Float:health) = SetActorHealth;
#define _ALS_SetActorHealth
#define SetActorHealth( FIXES_SetActorHealth(

#if defined _ALS_GetActorHealth
	#error _ALS_GetActorHealth defined
#endif
native BAD_GetActorHealth(actorid, &Float:health) = GetActorHealth;
native FIXES_GetActorHealth(actorid, &Float:health) = GetActorHealth;
native GetActorHealth__(actorid, &Float:health) = GetActorHealth;
#define _ALS_GetActorHealth
#define GetActorHealth( FIXES_GetActorHealth(

#if defined _ALS_SetActorInvulnerable
	#error _ALS_SetActorInvulnerable defined
#endif
native BAD_SetActorInvulnerable(actorid, invulnerable = true) = SetActorInvulnerable;
native FIXES_SetActorInvulnerable(actorid, _FIXES_MAYBE_BOOL:invulnerable = true) = SetActorInvulnerable;
native SetActorInvulnerable__(actorid, bool:invulnerable = true) = SetActorInvulnerable;
#define _ALS_SetActorInvulnerable
#define SetActorInvulnerable( FIXES_SetActorInvulnerable(

#if defined _ALS_IsActorInvulnerable
	#error _ALS_IsActorInvulnerable defined
#endif
native BAD_IsActorInvulnerable(actorid) = IsActorInvulnerable;
native _FIXES_MAYBE_BOOL:FIXES_IsActorInvulnerable(actorid) = IsActorInvulnerable;
native bool:IsActorInvulnerable__(actorid) = IsActorInvulnerable;
#define _ALS_IsActorInvulnerable
#define IsActorInvulnerable( FIXES_IsActorInvulnerable(

#if defined _ALS_IsValidActor
	#error _ALS_IsValidActor defined
#endif
native BAD_IsValidActor(actorid) = IsValidActor;
native _FIXES_MAYBE_BOOL:FIXES_IsValidActor(actorid) = IsValidActor;
native bool:IsValidActor__(actorid) = IsValidActor;
#define _ALS_IsValidActor
#define IsValidActor( FIXES_IsValidActor(

//
// a_http
//

#if defined _ALS_HTTP
	#error _ALS_HTTP defined
#endif
native BAD_HTTP(index, HTTP_METHOD:method, url[], data[], callback[]) = HTTP;
native FIXES_HTTP(index, HTTP_METHOD:method, _FIXES_MAYBE_CONST url[], _FIXES_MAYBE_CONST data[], _FIXES_MAYBE_CONST callback[]) = HTTP;
native HTTP__(index, HTTP_METHOD:method, const url[], const data[], const callback[]) = HTTP;
#define _ALS_HTTP
#define HTTP( FIXES_HTTP(

//
// a_objects
//

#if defined _ALS_CreateObject
	#error _ALS_CreateObject defined
#endif
native BAD_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
native FIXES_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
native CreateObject__(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
#define _ALS_CreateObject
#define CreateObject( FIXES_CreateObject(

#if defined _ALS_AttachObjectToVehicle
	#error _ALS_AttachObjectToVehicle defined
#endif
native BAD_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
native FIXES_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
native AttachObjectToVehicle__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
#define _ALS_AttachObjectToVehicle
#define AttachObjectToVehicle( FIXES_AttachObjectToVehicle(

#if defined _ALS_AttachObjectToObject
	#error _ALS_AttachObjectToObject defined
#endif
native BAD_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, syncRotation = true) = AttachObjectToObject;
native FIXES_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, _FIXES_MAYBE_BOOL:syncRotation = true) = AttachObjectToObject;
native AttachObjectToObject__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, bool:syncRotation = true) = AttachObjectToObject;
#define _ALS_AttachObjectToObject
#define AttachObjectToObject( FIXES_AttachObjectToObject(

#if defined _ALS_AttachObjectToPlayer
	#error _ALS_AttachObjectToPlayer defined
#endif
native BAD_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
native FIXES_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
native AttachObjectToPlayer__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
#define _ALS_AttachObjectToPlayer
#define AttachObjectToPlayer( FIXES_AttachObjectToPlayer(

#if defined _ALS_SetObjectPos
	#error _ALS_SetObjectPos defined
#endif
native BAD_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
native FIXES_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
native SetObjectPos__(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
#define _ALS_SetObjectPos
#define SetObjectPos( FIXES_SetObjectPos(

#if defined _ALS_GetObjectPos
	#error _ALS_GetObjectPos defined
#endif
native BAD_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
native FIXES_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
native GetObjectPos__(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
#define _ALS_GetObjectPos
#define GetObjectPos( FIXES_GetObjectPos(

#if defined _ALS_SetObjectRot
	#error _ALS_SetObjectRot defined
#endif
native BAD_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
native FIXES_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
native SetObjectRot__(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
#define _ALS_SetObjectRot
#define SetObjectRot( FIXES_SetObjectRot(

#if defined _ALS_GetObjectRot
	#error _ALS_GetObjectRot defined
#endif
native BAD_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
native FIXES_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
native GetObjectRot__(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
#define _ALS_GetObjectRot
#define GetObjectRot( FIXES_GetObjectRot(

#if defined _ALS_GetObjectModel
	#error _ALS_GetObjectModel defined
#endif
native BAD_GetObjectModel(objectid) = GetObjectModel;
native FIXES_GetObjectModel(objectid) = GetObjectModel;
native GetObjectModel__(objectid) = GetObjectModel;
#define _ALS_GetObjectModel
#define GetObjectModel( FIXES_GetObjectModel(

#if defined _ALS_SetObjectNoCameraCol
	#error _ALS_SetObjectNoCameraCol defined
#endif
native BAD_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
native FIXES_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
native SetObjectNoCameraCol__(objectid) = SetObjectNoCameraCol;
#define _ALS_SetObjectNoCameraCol
#define SetObjectNoCameraCol( FIXES_SetObjectNoCameraCol(

#if defined _ALS_IsValidObject
	#error _ALS_IsValidObject defined
#endif
native BAD_IsValidObject(objectid) = IsValidObject;
native _FIXES_MAYBE_BOOL:FIXES_IsValidObject(objectid) = IsValidObject;
native bool:IsValidObject__(objectid) = IsValidObject;
#define _ALS_IsValidObject
#define IsValidObject( FIXES_IsValidObject(

#if defined _ALS_DestroyObject
	#error _ALS_DestroyObject defined
#endif
native BAD_DestroyObject(objectid) = DestroyObject;
native FIXES_DestroyObject(objectid) = DestroyObject;
native DestroyObject__(objectid) = DestroyObject;
#define _ALS_DestroyObject
#define DestroyObject( FIXES_DestroyObject(

#if defined _ALS_MoveObject
	#error _ALS_MoveObject defined
#endif
native BAD_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
native FIXES_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
native MoveObject__(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
#define _ALS_MoveObject
#define MoveObject( FIXES_MoveObject(

#if defined _ALS_StopObject
	#error _ALS_StopObject defined
#endif
native BAD_StopObject(objectid) = StopObject;
native FIXES_StopObject(objectid) = StopObject;
native StopObject__(objectid) = StopObject;
#define _ALS_StopObject
#define StopObject( FIXES_StopObject(

#if defined _ALS_IsObjectMoving
	#error _ALS_IsObjectMoving defined
#endif
native BAD_IsObjectMoving(objectid) = IsObjectMoving;
native _FIXES_MAYBE_BOOL:FIXES_IsObjectMoving(objectid) = IsObjectMoving;
native bool:IsObjectMoving__(objectid) = IsObjectMoving;
#define _ALS_IsObjectMoving
#define IsObjectMoving( FIXES_IsObjectMoving(

#if defined _ALS_EditObject
	#error _ALS_EditObject defined
#endif
native BAD_EditObject(playerid, objectid) = EditObject;
native FIXES_EditObject(playerid, objectid) = EditObject;
native EditObject__(playerid, objectid) = EditObject;
#define _ALS_EditObject
#define EditObject( FIXES_EditObject(

#if defined _ALS_EditPlayerObject
	#error _ALS_EditPlayerObject defined
#endif
native BAD_EditPlayerObject(playerid, objectid) = EditPlayerObject;
native FIXES_EditPlayerObject(playerid, objectid) = EditPlayerObject;
native EditPlayerObject__(playerid, objectid) = EditPlayerObject;
#define _ALS_EditPlayerObject
#define EditPlayerObject( FIXES_EditPlayerObject(

#if defined _ALS_SelectObject
	#error _ALS_SelectObject defined
#endif
native BAD_SelectObject(playerid) = SelectObject;
native FIXES_SelectObject(playerid) = SelectObject;
native SelectObject__(playerid) = SelectObject;
#define _ALS_SelectObject
#define SelectObject( FIXES_SelectObject(

#if defined _ALS_CancelEdit
	#error _ALS_CancelEdit defined
#endif
native BAD_CancelEdit(playerid) = CancelEdit;
native FIXES_CancelEdit(playerid) = CancelEdit;
native CancelEdit__(playerid) = CancelEdit;
#define _ALS_CancelEdit
#define CancelEdit( FIXES_CancelEdit(

#if defined _ALS_CreatePlayerObject
	#error _ALS_CreatePlayerObject defined
#endif
native BAD_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
native FIXES_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
native CreatePlayerObject__(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
#define _ALS_CreatePlayerObject
#define CreatePlayerObject( FIXES_CreatePlayerObject(

#if defined _ALS_AttachPlayerObjectToVehicle
	#error _ALS_AttachPlayerObjectToVehicle defined
#endif
native BAD_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
native FIXES_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
native AttachPlayerObjectToVehicle__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
#define _ALS_AttachPlayerObjectToVehicle
#define AttachPlayerObjectToVehicle( FIXES_AttachPlayerObjectToVehicle(

#if defined _ALS_SetPlayerObjectPos
	#error _ALS_SetPlayerObjectPos defined
#endif
native BAD_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
native FIXES_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
native SetPlayerObjectPos__(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
#define _ALS_SetPlayerObjectPos
#define SetPlayerObjectPos( FIXES_SetPlayerObjectPos(

#if defined _ALS_GetPlayerObjectPos
	#error _ALS_GetPlayerObjectPos defined
#endif
native BAD_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
native FIXES_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
native GetPlayerObjectPos__(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
#define _ALS_GetPlayerObjectPos
#define GetPlayerObjectPos( FIXES_GetPlayerObjectPos(

#if defined _ALS_SetPlayerObjectRot
	#error _ALS_SetPlayerObjectRot defined
#endif
native BAD_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
native FIXES_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
native SetPlayerObjectRot__(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
#define _ALS_SetPlayerObjectRot
#define SetPlayerObjectRot( FIXES_SetPlayerObjectRot(

#if defined _ALS_GetPlayerObjectRot
	#error _ALS_GetPlayerObjectRot defined
#endif
native BAD_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
native FIXES_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
native GetPlayerObjectRot__(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
#define _ALS_GetPlayerObjectRot
#define GetPlayerObjectRot( FIXES_GetPlayerObjectRot(

#if defined _ALS_GetPlayerObjectModel
	#error _ALS_GetPlayerObjectModel defined
#endif
native BAD_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
native FIXES_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
native GetPlayerObjectModel__(playerid, objectid) = GetPlayerObjectModel;
#define _ALS_GetPlayerObjectModel
#define GetPlayerObjectModel( FIXES_GetPlayerObjectModel(

#if defined _ALS_SetPlayerObjectNoCameraCol
	#error _ALS_SetPlayerObjectNoCameraCol defined
#endif
native BAD_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
native FIXES_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
native SetPlayerObjectNoCameraCol__(playerid, objectid) = SetPlayerObjectNoCameraCol;
#define _ALS_SetPlayerObjectNoCameraCol
#define SetPlayerObjectNoCameraCol( FIXES_SetPlayerObjectNoCameraCol(

#if defined _ALS_IsValidPlayerObject
	#error _ALS_IsValidPlayerObject defined
#endif
native BAD_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
native _FIXES_MAYBE_BOOL:FIXES_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
native bool:IsValidPlayerObject__(playerid, objectid) = IsValidPlayerObject;
#define _ALS_IsValidPlayerObject
#define IsValidPlayerObject( FIXES_IsValidPlayerObject(

#if defined _ALS_DestroyPlayerObject
	#error _ALS_DestroyPlayerObject defined
#endif
native BAD_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
native FIXES_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
native DestroyPlayerObject__(playerid, objectid) = DestroyPlayerObject;
#define _ALS_DestroyPlayerObject
#define DestroyPlayerObject( FIXES_DestroyPlayerObject(

#if defined _ALS_MovePlayerObject
	#error _ALS_MovePlayerObject defined
#endif
native BAD_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
native FIXES_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
native MovePlayerObject__(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
#define _ALS_MovePlayerObject
#define MovePlayerObject( FIXES_MovePlayerObject(

#if defined _ALS_StopPlayerObject
	#error _ALS_StopPlayerObject defined
#endif
native BAD_StopPlayerObject(playerid, objectid) = StopPlayerObject;
native FIXES_StopPlayerObject(playerid, objectid) = StopPlayerObject;
native StopPlayerObject__(playerid, objectid) = StopPlayerObject;
#define _ALS_StopPlayerObject
#define StopPlayerObject( FIXES_StopPlayerObject(

#if defined _ALS_IsPlayerObjectMoving
	#error _ALS_IsPlayerObjectMoving defined
#endif
native BAD_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
native bool:IsPlayerObjectMoving__(playerid, objectid) = IsPlayerObjectMoving;
#define _ALS_IsPlayerObjectMoving
#define IsPlayerObjectMoving( FIXES_IsPlayerObjectMoving(

#if defined _ALS_AttachPlayerObjectToPlayer
	#error _ALS_AttachPlayerObjectToPlayer defined
#endif
native BAD_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
native FIXES_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
native AttachPlayerObjectToPlayer__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
#define _ALS_AttachPlayerObjectToPlayer
#define AttachPlayerObjectToPlayer( FIXES_AttachPlayerObjectToPlayer(

#if defined _ALS_SetObjectMaterial
	#error _ALS_SetObjectMaterial defined
#endif
native BAD_SetObjectMaterial(objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetObjectMaterial;
native FIXES_SetObjectMaterial(objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetObjectMaterial;
native SetObjectMaterial__(objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetObjectMaterial;
#define _ALS_SetObjectMaterial
#define SetObjectMaterial( FIXES_SetObjectMaterial(

#if defined _ALS_SetPlayerObjectMaterial
	#error _ALS_SetPlayerObjectMaterial defined
#endif
native BAD_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetPlayerObjectMaterial;
native FIXES_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetPlayerObjectMaterial;
native SetPlayerObjectMaterial__(playerid, objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetPlayerObjectMaterial;
#define _ALS_SetPlayerObjectMaterial
#define SetPlayerObjectMaterial( FIXES_SetPlayerObjectMaterial(

#if defined _ALS_SetObjectMaterialText
	#error _ALS_SetObjectMaterialText defined
#endif
native BAD_SetObjectMaterialText(objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
native FIXES_SetObjectMaterialText(objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
native SetObjectMaterialText__(objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
#define _ALS_SetObjectMaterialText
#define SetObjectMaterialText( FIXES_SetObjectMaterialText(

#if defined _ALS_SetPlayerObjectMaterialText
	#error _ALS_SetPlayerObjectMaterialText defined
#endif
native BAD_SetPlayerObjectMaterialText(playerid, objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
native FIXES_SetPlayerObjectMaterialText(playerid, objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
native SetPlayerObjectMaterialText__(playerid, objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
#define _ALS_SetPlayerObjectMaterialText
#define SetPlayerObjectMaterialText( FIXES_SetPlayerObjectMaterialText(

#if defined _ALS_SetObjectsDefaultCameraCol
	#error _ALS_SetObjectsDefaultCameraCol defined
#endif
native BAD_SetObjectsDefaultCameraCol(disable) = SetObjectsDefaultCameraCol;
native FIXES_SetObjectsDefaultCameraCol(_FIXES_MAYBE_BOOL:disable) = SetObjectsDefaultCameraCol;
native SetObjectsDefaultCameraCol__(bool:disable) = SetObjectsDefaultCameraCol;
#define _ALS_SetObjectsDefaultCameraCol
#define SetObjectsDefaultCameraCol( FIXES_SetObjectsDefaultCameraCol(

//
// a_players
//

#if defined _ALS_SetSpawnInfo
	#error _ALS_SetSpawnInfo defined
#endif
native BAD_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
native FIXES_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
native SetSpawnInfo__(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
#define _ALS_SetSpawnInfo
#define SetSpawnInfo( FIXES_SetSpawnInfo(

#if defined _ALS_SpawnPlayer
	#error _ALS_SpawnPlayer defined
#endif
native BAD_SpawnPlayer(playerid) = SpawnPlayer;
native FIXES_SpawnPlayer(playerid) = SpawnPlayer;
native SpawnPlayer__(playerid) = SpawnPlayer;
#define _ALS_SpawnPlayer
#define SpawnPlayer( FIXES_SpawnPlayer(

#if defined _ALS_SetPlayerPos
	#error _ALS_SetPlayerPos defined
#endif
native BAD_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
native FIXES_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
native SetPlayerPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
#define _ALS_SetPlayerPos
#define SetPlayerPos( FIXES_SetPlayerPos(

#if defined _ALS_SetPlayerPosFindZ
	#error _ALS_SetPlayerPosFindZ defined
#endif
native BAD_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
native FIXES_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
native SetPlayerPosFindZ__(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
#define _ALS_SetPlayerPosFindZ
#define SetPlayerPosFindZ( FIXES_SetPlayerPosFindZ(

#if defined _ALS_GetPlayerPos
	#error _ALS_GetPlayerPos defined
#endif
native BAD_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
native FIXES_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
native GetPlayerPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
#define _ALS_GetPlayerPos
#define GetPlayerPos( FIXES_GetPlayerPos(

#if defined _ALS_SetPlayerFacingAngle
	#error _ALS_SetPlayerFacingAngle defined
#endif
native BAD_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
native FIXES_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
native SetPlayerFacingAngle__(playerid, Float:ang) = SetPlayerFacingAngle;
#define _ALS_SetPlayerFacingAngle
#define SetPlayerFacingAngle( FIXES_SetPlayerFacingAngle(

#if defined _ALS_GetPlayerFacingAngle
	#error _ALS_GetPlayerFacingAngle defined
#endif
native BAD_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
native FIXES_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
native GetPlayerFacingAngle__(playerid, &Float:ang) = GetPlayerFacingAngle;
#define _ALS_GetPlayerFacingAngle
#define GetPlayerFacingAngle( FIXES_GetPlayerFacingAngle(

#if defined _ALS_IsPlayerInRangeOfPoint
	#error _ALS_IsPlayerInRangeOfPoint defined
#endif
native BAD_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
native bool:IsPlayerInRangeOfPoint__(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
#define _ALS_IsPlayerInRangeOfPoint
#define IsPlayerInRangeOfPoint( FIXES_IsPlayerInRangeOfPoint(

#if defined _ALS_GetPlayerDistanceFromPoint
	#error _ALS_GetPlayerDistanceFromPoint defined
#endif
native Float:BAD_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
native Float:FIXES_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
native Float:GetPlayerDistanceFromPoint__(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
#define _ALS_GetPlayerDistanceFromPoint
#define GetPlayerDistanceFromPoint( FIXES_GetPlayerDistanceFromPoint(

#if defined _ALS_IsPlayerStreamedIn
	#error _ALS_IsPlayerStreamedIn defined
#endif
native BAD_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
native bool:IsPlayerStreamedIn__(targetid, playerid) = IsPlayerStreamedIn;
#define _ALS_IsPlayerStreamedIn
#define IsPlayerStreamedIn( FIXES_IsPlayerStreamedIn(

#if defined _ALS_SetPlayerInterior
	#error _ALS_SetPlayerInterior defined
#endif
native BAD_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
native FIXES_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
native SetPlayerInterior__(playerid, interiorid) = SetPlayerInterior;
#define _ALS_SetPlayerInterior
#define SetPlayerInterior( FIXES_SetPlayerInterior(

#if defined _ALS_GetPlayerInterior
	#error _ALS_GetPlayerInterior defined
#endif
native BAD_GetPlayerInterior(playerid) = GetPlayerInterior;
native FIXES_GetPlayerInterior(playerid) = GetPlayerInterior;
native GetPlayerInterior__(playerid) = GetPlayerInterior;
#define _ALS_GetPlayerInterior
#define GetPlayerInterior( FIXES_GetPlayerInterior(

#if defined _ALS_SetPlayerHealth
	#error _ALS_SetPlayerHealth defined
#endif
native BAD_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
native FIXES_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
native SetPlayerHealth__(playerid, Float:health) = SetPlayerHealth;
#define _ALS_SetPlayerHealth
#define SetPlayerHealth( FIXES_SetPlayerHealth(

#if defined _ALS_GetPlayerHealth
	#error _ALS_GetPlayerHealth defined
#endif
native BAD_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
native FIXES_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
native GetPlayerHealth__(playerid, &Float:health) = GetPlayerHealth;
#define _ALS_GetPlayerHealth
#define GetPlayerHealth( FIXES_GetPlayerHealth(

#if defined _ALS_SetPlayerArmour
	#error _ALS_SetPlayerArmour defined
#endif
native BAD_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
native FIXES_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
native SetPlayerArmour__(playerid, Float:armour) = SetPlayerArmour;
#define _ALS_SetPlayerArmour
#define SetPlayerArmour( FIXES_SetPlayerArmour(

#if defined _ALS_GetPlayerArmour
	#error _ALS_GetPlayerArmour defined
#endif
native BAD_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
native FIXES_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
native GetPlayerArmour__(playerid, &Float:armour) = GetPlayerArmour;
#define _ALS_GetPlayerArmour
#define GetPlayerArmour( FIXES_GetPlayerArmour(

#if defined _ALS_SetPlayerAmmo
	#error _ALS_SetPlayerAmmo defined
#endif
native BAD_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
native FIXES_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
native SetPlayerAmmo__(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
#define _ALS_SetPlayerAmmo
#define SetPlayerAmmo( FIXES_SetPlayerAmmo(

#if defined _ALS_GetPlayerAmmo
	#error _ALS_GetPlayerAmmo defined
#endif
native BAD_GetPlayerAmmo(playerid) = GetPlayerAmmo;
native FIXES_GetPlayerAmmo(playerid) = GetPlayerAmmo;
native GetPlayerAmmo__(playerid) = GetPlayerAmmo;
#define _ALS_GetPlayerAmmo
#define GetPlayerAmmo( FIXES_GetPlayerAmmo(

#if defined _ALS_GetPlayerWeaponState
	#error _ALS_GetPlayerWeaponState defined
#endif
native WEAPONSTATE:BAD_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
native WEAPONSTATE:FIXES_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
native WEAPONSTATE:GetPlayerWeaponState__(playerid) = GetPlayerWeaponState;
#define _ALS_GetPlayerWeaponState
#define GetPlayerWeaponState( FIXES_GetPlayerWeaponState(

#if defined _ALS_GetPlayerTargetPlayer
	#error _ALS_GetPlayerTargetPlayer defined
#endif
native BAD_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
native FIXES_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
native GetPlayerTargetPlayer__(playerid) = GetPlayerTargetPlayer;
#define _ALS_GetPlayerTargetPlayer
#define GetPlayerTargetPlayer( FIXES_GetPlayerTargetPlayer(

#if defined _ALS_GetPlayerTargetActor
	#error _ALS_GetPlayerTargetActor defined
#endif
native BAD_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
native FIXES_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
native GetPlayerTargetActor__(playerid) = GetPlayerTargetActor;
#define _ALS_GetPlayerTargetActor
#define GetPlayerTargetActor( FIXES_GetPlayerTargetActor(

#if defined _ALS_SetPlayerTeam
	#error _ALS_SetPlayerTeam defined
#endif
native BAD_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
native FIXES_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
native SetPlayerTeam__(playerid, teamid) = SetPlayerTeam;
#define _ALS_SetPlayerTeam
#define SetPlayerTeam( FIXES_SetPlayerTeam(

#if defined _ALS_GetPlayerTeam
	#error _ALS_GetPlayerTeam defined
#endif
native BAD_GetPlayerTeam(playerid) = GetPlayerTeam;
native FIXES_GetPlayerTeam(playerid) = GetPlayerTeam;
native GetPlayerTeam__(playerid) = GetPlayerTeam;
#define _ALS_GetPlayerTeam
#define GetPlayerTeam( FIXES_GetPlayerTeam(

#if defined _ALS_SetPlayerScore
	#error _ALS_SetPlayerScore defined
#endif
native BAD_SetPlayerScore(playerid, score) = SetPlayerScore;
native FIXES_SetPlayerScore(playerid, score) = SetPlayerScore;
native SetPlayerScore__(playerid, score) = SetPlayerScore;
#define _ALS_SetPlayerScore
#define SetPlayerScore( FIXES_SetPlayerScore(

#if defined _ALS_GetPlayerScore
	#error _ALS_GetPlayerScore defined
#endif
native BAD_GetPlayerScore(playerid) = GetPlayerScore;
native FIXES_GetPlayerScore(playerid) = GetPlayerScore;
native GetPlayerScore__(playerid) = GetPlayerScore;
#define _ALS_GetPlayerScore
#define GetPlayerScore( FIXES_GetPlayerScore(

#if defined _ALS_GetPlayerDrunkLevel
	#error _ALS_GetPlayerDrunkLevel defined
#endif
native BAD_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
native FIXES_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
native GetPlayerDrunkLevel__(playerid) = GetPlayerDrunkLevel;
#define _ALS_GetPlayerDrunkLevel
#define GetPlayerDrunkLevel( FIXES_GetPlayerDrunkLevel(

#if defined _ALS_SetPlayerDrunkLevel
	#error _ALS_SetPlayerDrunkLevel defined
#endif
native BAD_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
native FIXES_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
native SetPlayerDrunkLevel__(playerid, level) = SetPlayerDrunkLevel;
#define _ALS_SetPlayerDrunkLevel
#define SetPlayerDrunkLevel( FIXES_SetPlayerDrunkLevel(

#if defined _ALS_SetPlayerColor
	#error _ALS_SetPlayerColor defined
#endif
native BAD_SetPlayerColor(playerid, colour) = SetPlayerColor;
native FIXES_SetPlayerColor(playerid, colour) = SetPlayerColor;
native SetPlayerColor__(playerid, colour) = SetPlayerColor;
#define _ALS_SetPlayerColor
#define SetPlayerColor( FIXES_SetPlayerColor(

#if defined _ALS_GetPlayerColor
	#error _ALS_GetPlayerColor defined
#endif
native BAD_GetPlayerColor(playerid) = GetPlayerColor;
native FIXES_GetPlayerColor(playerid) = GetPlayerColor;
native GetPlayerColor__(playerid) = GetPlayerColor;
#define _ALS_GetPlayerColor
#define GetPlayerColor( FIXES_GetPlayerColor(

#if defined _ALS_SetPlayerSkin
	#error _ALS_SetPlayerSkin defined
#endif
native BAD_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
native FIXES_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
native SetPlayerSkin__(playerid, skinid) = SetPlayerSkin;
#define _ALS_SetPlayerSkin
#define SetPlayerSkin( FIXES_SetPlayerSkin(

#if defined _ALS_GetPlayerSkin
	#error _ALS_GetPlayerSkin defined
#endif
native BAD_GetPlayerSkin(playerid) = GetPlayerSkin;
native FIXES_GetPlayerSkin(playerid) = GetPlayerSkin;
native GetPlayerSkin__(playerid) = GetPlayerSkin;
#define _ALS_GetPlayerSkin
#define GetPlayerSkin( FIXES_GetPlayerSkin(

#if defined _ALS_GetPlayerCustomSkin
	#error _ALS_GetPlayerCustomSkin defined
#endif
native BAD_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
native FIXES_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
native GetPlayerCustomSkin__(playerid) = GetPlayerCustomSkin;
#define _ALS_GetPlayerCustomSkin
#define GetPlayerCustomSkin( FIXES_GetPlayerCustomSkin(

#if defined _ALS_GivePlayerWeapon
	#error _ALS_GivePlayerWeapon defined
#endif
native BAD_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
native FIXES_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
native GivePlayerWeapon__(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
#define _ALS_GivePlayerWeapon
#define GivePlayerWeapon( FIXES_GivePlayerWeapon(

#if defined _ALS_ResetPlayerWeapons
	#error _ALS_ResetPlayerWeapons defined
#endif
native BAD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
native FIXES_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
native ResetPlayerWeapons__(playerid) = ResetPlayerWeapons;
#define _ALS_ResetPlayerWeapons
#define ResetPlayerWeapons( FIXES_ResetPlayerWeapons(

#if defined _ALS_SetPlayerArmedWeapon
	#error _ALS_SetPlayerArmedWeapon defined
#endif
native BAD_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
native FIXES_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
native SetPlayerArmedWeapon__(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
#define _ALS_SetPlayerArmedWeapon
#define SetPlayerArmedWeapon( FIXES_SetPlayerArmedWeapon(

#if defined _ALS_GetPlayerWeaponData
	#error _ALS_GetPlayerWeaponData defined
#endif
native BAD_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
native FIXES_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
native GetPlayerWeaponData__(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
#define _ALS_GetPlayerWeaponData
#define GetPlayerWeaponData( FIXES_GetPlayerWeaponData(

#if defined _ALS_GivePlayerMoney
	#error _ALS_GivePlayerMoney defined
#endif
native BAD_GivePlayerMoney(playerid, money) = GivePlayerMoney;
native FIXES_GivePlayerMoney(playerid, money) = GivePlayerMoney;
native GivePlayerMoney__(playerid, money) = GivePlayerMoney;
#define _ALS_GivePlayerMoney
#define GivePlayerMoney( FIXES_GivePlayerMoney(

#if defined _ALS_ResetPlayerMoney
	#error _ALS_ResetPlayerMoney defined
#endif
native BAD_ResetPlayerMoney(playerid) = ResetPlayerMoney;
native FIXES_ResetPlayerMoney(playerid) = ResetPlayerMoney;
native ResetPlayerMoney__(playerid) = ResetPlayerMoney;
#define _ALS_ResetPlayerMoney
#define ResetPlayerMoney( FIXES_ResetPlayerMoney(

#if defined _ALS_SetPlayerName
	#error _ALS_SetPlayerName defined
#endif
native BAD_SetPlayerName(playerid, name[]) = SetPlayerName;
native FIXES_SetPlayerName(playerid, _FIXES_MAYBE_CONST name[]) = SetPlayerName;
native SetPlayerName__(playerid, const name[]) = SetPlayerName;
#define _ALS_SetPlayerName
#define SetPlayerName( FIXES_SetPlayerName(

#if defined _ALS_GetPlayerMoney
	#error _ALS_GetPlayerMoney defined
#endif
native BAD_GetPlayerMoney(playerid) = GetPlayerMoney;
native FIXES_GetPlayerMoney(playerid) = GetPlayerMoney;
native GetPlayerMoney__(playerid) = GetPlayerMoney;
#define _ALS_GetPlayerMoney
#define GetPlayerMoney( FIXES_GetPlayerMoney(

#if defined _ALS_GetPlayerState
	#error _ALS_GetPlayerState defined
#endif
native PLAYER_STATE:BAD_GetPlayerState(playerid) = GetPlayerState;
native PLAYER_STATE:FIXES_GetPlayerState(playerid) = GetPlayerState;
native PLAYER_STATE:GetPlayerState__(playerid) = GetPlayerState;
#define _ALS_GetPlayerState
#define GetPlayerState( FIXES_GetPlayerState(

#if defined _ALS_GetPlayerIp
	#error _ALS_GetPlayerIp defined
#endif
native BAD_GetPlayerIp(playerid, ip[], len) = GetPlayerIp;
native FIXES_GetPlayerIp(playerid, ip[], _FIXES_MAYBE_SIZEOF(len, ip)) = GetPlayerIp;
native GetPlayerIp__(playerid, ip[], len = sizeof (ip)) = GetPlayerIp;
#define _ALS_GetPlayerIp
#define GetPlayerIp( FIXES_GetPlayerIp(

#if defined _ALS_GetPlayerPing
	#error _ALS_GetPlayerPing defined
#endif
native BAD_GetPlayerPing(playerid) = GetPlayerPing;
native FIXES_GetPlayerPing(playerid) = GetPlayerPing;
native GetPlayerPing__(playerid) = GetPlayerPing;
#define _ALS_GetPlayerPing
#define GetPlayerPing( FIXES_GetPlayerPing(

#if defined _ALS_GetPlayerWeapon
	#error _ALS_GetPlayerWeapon defined
#endif
native WEAPON:BAD_GetPlayerWeapon(playerid) = GetPlayerWeapon;
native WEAPON:FIXES_GetPlayerWeapon(playerid) = GetPlayerWeapon;
native WEAPON:GetPlayerWeapon__(playerid) = GetPlayerWeapon;
#define _ALS_GetPlayerWeapon
#define GetPlayerWeapon( FIXES_GetPlayerWeapon(

#if defined _ALS_GetPlayerKeys
	#error _ALS_GetPlayerKeys defined
#endif
native BAD_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
native FIXES_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
native GetPlayerKeys__(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
#define _ALS_GetPlayerKeys
#define GetPlayerKeys( FIXES_GetPlayerKeys(

#if defined _ALS_GetPlayerName
	#error _ALS_GetPlayerName defined
#endif
native BAD_GetPlayerName(playerid, const name[], len) = GetPlayerName;
native FIXES_GetPlayerName(playerid, _FIXES_NOT_CONST name[], _FIXES_MAYBE_SIZEOF(len, name)) = GetPlayerName;
native GetPlayerName__(playerid, name[], len = sizeof (name)) = GetPlayerName;
#define _ALS_GetPlayerName
#define GetPlayerName( FIXES_GetPlayerName(

#if defined _ALS_SetPlayerTime
	#error _ALS_SetPlayerTime defined
#endif
native BAD_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
native FIXES_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
native SetPlayerTime__(playerid, hour, minute) = SetPlayerTime;
#define _ALS_SetPlayerTime
#define SetPlayerTime( FIXES_SetPlayerTime(

#if defined _ALS_GetPlayerTime
	#error _ALS_GetPlayerTime defined
#endif
native BAD_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
native FIXES_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
native GetPlayerTime__(playerid, &hour, &minute) = GetPlayerTime;
#define _ALS_GetPlayerTime
#define GetPlayerTime( FIXES_GetPlayerTime(

#if defined _ALS_TogglePlayerClock
	#error _ALS_TogglePlayerClock defined
#endif
native BAD_TogglePlayerClock(playerid, toggle) = TogglePlayerClock;
native FIXES_TogglePlayerClock(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerClock;
native TogglePlayerClock__(playerid, bool:toggle) = TogglePlayerClock;
#define _ALS_TogglePlayerClock
#define TogglePlayerClock( FIXES_TogglePlayerClock(

#if defined _ALS_SetPlayerWeather
	#error _ALS_SetPlayerWeather defined
#endif
native BAD_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
native FIXES_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
native SetPlayerWeather__(playerid, weather) = SetPlayerWeather;
#define _ALS_SetPlayerWeather
#define SetPlayerWeather( FIXES_SetPlayerWeather(

#if defined _ALS_ForceClassSelection
	#error _ALS_ForceClassSelection defined
#endif
native BAD_ForceClassSelection(playerid) = ForceClassSelection;
native FIXES_ForceClassSelection(playerid) = ForceClassSelection;
native ForceClassSelection__(playerid) = ForceClassSelection;
#define _ALS_ForceClassSelection
#define ForceClassSelection( FIXES_ForceClassSelection(

#if defined _ALS_SetPlayerWantedLevel
	#error _ALS_SetPlayerWantedLevel defined
#endif
native BAD_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
native FIXES_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
native SetPlayerWantedLevel__(playerid, level) = SetPlayerWantedLevel;
#define _ALS_SetPlayerWantedLevel
#define SetPlayerWantedLevel( FIXES_SetPlayerWantedLevel(

#if defined _ALS_GetPlayerWantedLevel
	#error _ALS_GetPlayerWantedLevel defined
#endif
native BAD_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
native FIXES_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
native GetPlayerWantedLevel__(playerid) = GetPlayerWantedLevel;
#define _ALS_GetPlayerWantedLevel
#define GetPlayerWantedLevel( FIXES_GetPlayerWantedLevel(

#if defined _ALS_SetPlayerFightingStyle
	#error _ALS_SetPlayerFightingStyle defined
#endif
native BAD_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
native FIXES_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
native SetPlayerFightingStyle__(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
#define _ALS_SetPlayerFightingStyle
#define SetPlayerFightingStyle( FIXES_SetPlayerFightingStyle(

#if defined _ALS_GetPlayerFightingStyle
	#error _ALS_GetPlayerFightingStyle defined
#endif
native FIGHT_STYLE:BAD_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
native FIGHT_STYLE:FIXES_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
native FIGHT_STYLE:GetPlayerFightingStyle__(playerid) = GetPlayerFightingStyle;
#define _ALS_GetPlayerFightingStyle
#define GetPlayerFightingStyle( FIXES_GetPlayerFightingStyle(

#if defined _ALS_SetPlayerVelocity
	#error _ALS_SetPlayerVelocity defined
#endif
native BAD_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
native FIXES_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
native SetPlayerVelocity__(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
#define _ALS_SetPlayerVelocity
#define SetPlayerVelocity( FIXES_SetPlayerVelocity(

#if defined _ALS_GetPlayerVelocity
	#error _ALS_GetPlayerVelocity defined
#endif
native BAD_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
native FIXES_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
native GetPlayerVelocity__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
#define _ALS_GetPlayerVelocity
#define GetPlayerVelocity( FIXES_GetPlayerVelocity(

#if defined _ALS_PlayCrimeReportForPlayer
	#error _ALS_PlayCrimeReportForPlayer defined
#endif
native BAD_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
native FIXES_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
native PlayCrimeReportForPlayer__(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
#define _ALS_PlayCrimeReportForPlayer
#define PlayCrimeReportForPlayer( FIXES_PlayCrimeReportForPlayer(

#if defined _ALS_PlayAudioStreamForPlayer
	#error _ALS_PlayAudioStreamForPlayer defined
#endif
native BAD_PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = false) = PlayAudioStreamForPlayer;
native FIXES_PlayAudioStreamForPlayer(playerid, _FIXES_MAYBE_CONST url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, _FIXES_MAYBE_BOOL:usepos = false) = PlayAudioStreamForPlayer;
native PlayAudioStreamForPlayer__(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false) = PlayAudioStreamForPlayer;
#define _ALS_PlayAudioStreamForPlayer
#define PlayAudioStreamForPlayer( FIXES_PlayAudioStreamForPlayer(

#if defined _ALS_StopAudioStreamForPlayer
	#error _ALS_StopAudioStreamForPlayer defined
#endif
native BAD_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
native FIXES_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
native StopAudioStreamForPlayer__(playerid) = StopAudioStreamForPlayer;
#define _ALS_StopAudioStreamForPlayer
#define StopAudioStreamForPlayer( FIXES_StopAudioStreamForPlayer(

#if defined _ALS_SetPlayerShopName
	#error _ALS_SetPlayerShopName defined
#endif
native BAD_SetPlayerShopName(playerid, shopName[]) = SetPlayerShopName;
native FIXES_SetPlayerShopName(playerid, _FIXES_MAYBE_CONST shopName[]) = SetPlayerShopName;
native SetPlayerShopName__(playerid, const shopName[]) = SetPlayerShopName;
#define _ALS_SetPlayerShopName
#define SetPlayerShopName( FIXES_SetPlayerShopName(

#if defined _ALS_SetPlayerSkillLevel
	#error _ALS_SetPlayerSkillLevel defined
#endif
native BAD_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
native FIXES_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
native SetPlayerSkillLevel__(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
#define _ALS_SetPlayerSkillLevel
#define SetPlayerSkillLevel( FIXES_SetPlayerSkillLevel(

#if defined _ALS_GetPlayerSurfingVehicleID
	#error _ALS_GetPlayerSurfingVehicleID defined
#endif
native BAD_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
native FIXES_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
native GetPlayerSurfingVehicleID__(playerid) = GetPlayerSurfingVehicleID;
#define _ALS_GetPlayerSurfingVehicleID
#define GetPlayerSurfingVehicleID( FIXES_GetPlayerSurfingVehicleID(

#if defined _ALS_GetPlayerSurfingObjectID
	#error _ALS_GetPlayerSurfingObjectID defined
#endif
native BAD_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
native FIXES_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
native GetPlayerSurfingObjectID__(playerid) = GetPlayerSurfingObjectID;
#define _ALS_GetPlayerSurfingObjectID
#define GetPlayerSurfingObjectID( FIXES_GetPlayerSurfingObjectID(

#if defined _ALS_RemoveBuildingForPlayer
	#error _ALS_RemoveBuildingForPlayer defined
#endif
native BAD_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
native FIXES_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
native RemoveBuildingForPlayer__(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
#define _ALS_RemoveBuildingForPlayer
#define RemoveBuildingForPlayer( FIXES_RemoveBuildingForPlayer(

#if defined _ALS_GetPlayerLastShotVectors
	#error _ALS_GetPlayerLastShotVectors defined
#endif
native BAD_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
native FIXES_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
native GetPlayerLastShotVectors__(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
#define _ALS_GetPlayerLastShotVectors
#define GetPlayerLastShotVectors( FIXES_GetPlayerLastShotVectors(

#if defined _ALS_SetPlayerAttachedObject
	#error _ALS_SetPlayerAttachedObject defined
#endif
native BAD_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
native FIXES_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
native SetPlayerAttachedObject__(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
#define _ALS_SetPlayerAttachedObject
#define SetPlayerAttachedObject( FIXES_SetPlayerAttachedObject(

#if defined _ALS_RemovePlayerAttachedObject
	#error _ALS_RemovePlayerAttachedObject defined
#endif
native BAD_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
native FIXES_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
native RemovePlayerAttachedObject__(playerid, index) = RemovePlayerAttachedObject;
#define _ALS_RemovePlayerAttachedObject
#define RemovePlayerAttachedObject( FIXES_RemovePlayerAttachedObject(

#if defined _ALS_IsPlayerAttachedObjectSlotUsed
	#error _ALS_IsPlayerAttachedObjectSlotUsed defined
#endif
native BAD_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
native bool:IsPlayerAttachedObjectSlotUsed__(playerid, index) = IsPlayerAttachedObjectSlotUsed;
#define _ALS_IsPlayerAttachedObjectSlotUsed
#define IsPlayerAttachedObjectSlotUsed( FIXES_IsPlayerAttachedObjectSlotUsed(

#if defined _ALS_EditAttachedObject
	#error _ALS_EditAttachedObject defined
#endif
native BAD_EditAttachedObject(playerid, index) = EditAttachedObject;
native FIXES_EditAttachedObject(playerid, index) = EditAttachedObject;
native EditAttachedObject__(playerid, index) = EditAttachedObject;
#define _ALS_EditAttachedObject
#define EditAttachedObject( FIXES_EditAttachedObject(

#if defined _ALS_CreatePlayerTextDraw
	#error _ALS_CreatePlayerTextDraw defined
#endif
native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
native PlayerText:FIXES_CreatePlayerTextDraw(playerid, Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = CreatePlayerTextDraw;
native PlayerText:CreatePlayerTextDraw__(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
#define _ALS_CreatePlayerTextDraw
#define CreatePlayerTextDraw( FIXES_CreatePlayerTextDraw(

#if defined _ALS_PlayerTextDrawDestroy
	#error _ALS_PlayerTextDrawDestroy defined
#endif
native BAD_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
native FIXES_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
native PlayerTextDrawDestroy__(playerid, PlayerText:text) = PlayerTextDrawDestroy;
#define _ALS_PlayerTextDrawDestroy
#define PlayerTextDrawDestroy( FIXES_PlayerTextDrawDestroy(

#if defined _ALS_PlayerTextDrawLetterSize
	#error _ALS_PlayerTextDrawLetterSize defined
#endif
native BAD_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
native FIXES_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
native PlayerTextDrawLetterSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
#define _ALS_PlayerTextDrawLetterSize
#define PlayerTextDrawLetterSize( FIXES_PlayerTextDrawLetterSize(

#if defined _ALS_PlayerTextDrawTextSize
	#error _ALS_PlayerTextDrawTextSize defined
#endif
native BAD_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
native FIXES_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
native PlayerTextDrawTextSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
#define _ALS_PlayerTextDrawTextSize
#define PlayerTextDrawTextSize( FIXES_PlayerTextDrawTextSize(

#if defined _ALS_PlayerTextDrawAlignment
	#error _ALS_PlayerTextDrawAlignment defined
#endif
native BAD_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
native FIXES_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
native PlayerTextDrawAlignment__(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
#define _ALS_PlayerTextDrawAlignment
#define PlayerTextDrawAlignment( FIXES_PlayerTextDrawAlignment(

#if defined _ALS_PlayerTextDrawColor
	#error _ALS_PlayerTextDrawColor defined
#endif
native BAD_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
native FIXES_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
native PlayerTextDrawColor__(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
#define _ALS_PlayerTextDrawColor
#define PlayerTextDrawColor( FIXES_PlayerTextDrawColor(

#if defined _ALS_PlayerTextDrawUseBox
	#error _ALS_PlayerTextDrawUseBox defined
#endif
native BAD_PlayerTextDrawUseBox(playerid, PlayerText:text, use) = PlayerTextDrawUseBox;
native FIXES_PlayerTextDrawUseBox(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:use) = PlayerTextDrawUseBox;
native PlayerTextDrawUseBox__(playerid, PlayerText:text, bool:use) = PlayerTextDrawUseBox;
#define _ALS_PlayerTextDrawUseBox
#define PlayerTextDrawUseBox( FIXES_PlayerTextDrawUseBox(

#if defined _ALS_PlayerTextDrawBoxColor
	#error _ALS_PlayerTextDrawBoxColor defined
#endif
native BAD_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
native FIXES_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
native PlayerTextDrawBoxColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
#define _ALS_PlayerTextDrawBoxColor
#define PlayerTextDrawBoxColor( FIXES_PlayerTextDrawBoxColor(

#if defined _ALS_PlayerTextDrawSetShadow
	#error _ALS_PlayerTextDrawSetShadow defined
#endif
native BAD_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
native FIXES_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
native PlayerTextDrawSetShadow__(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
#define _ALS_PlayerTextDrawSetShadow
#define PlayerTextDrawSetShadow( FIXES_PlayerTextDrawSetShadow(

#if defined _ALS_PlayerTextDrawSetOutline
	#error _ALS_PlayerTextDrawSetOutline defined
#endif
native BAD_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
native FIXES_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
native PlayerTextDrawSetOutline__(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
#define _ALS_PlayerTextDrawSetOutline
#define PlayerTextDrawSetOutline( FIXES_PlayerTextDrawSetOutline(

#if defined _ALS_PlayerTextDrawBackgroundColor
	#error _ALS_PlayerTextDrawBackgroundColor defined
#endif
native BAD_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
native FIXES_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
native PlayerTextDrawBackgroundColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
#define _ALS_PlayerTextDrawBackgroundColor
#define PlayerTextDrawBackgroundColor( FIXES_PlayerTextDrawBackgroundColor(

#if defined _ALS_PlayerTextDrawFont
	#error _ALS_PlayerTextDrawFont defined
#endif
native BAD_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
native FIXES_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
native PlayerTextDrawFont__(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
#define _ALS_PlayerTextDrawFont
#define PlayerTextDrawFont( FIXES_PlayerTextDrawFont(

#if defined _ALS_PlayerTextDrawSetProportional
	#error _ALS_PlayerTextDrawSetProportional defined
#endif
native BAD_PlayerTextDrawSetProportional(playerid, PlayerText:text, set) = PlayerTextDrawSetProportional;
native FIXES_PlayerTextDrawSetProportional(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetProportional;
native PlayerTextDrawSetProportional__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetProportional;
#define _ALS_PlayerTextDrawSetProportional
#define PlayerTextDrawSetProportional( FIXES_PlayerTextDrawSetProportional(

#if defined _ALS_PlayerTextDrawSetSelectable
	#error _ALS_PlayerTextDrawSetSelectable defined
#endif
native BAD_PlayerTextDrawSetSelectable(playerid, PlayerText:text, set) = PlayerTextDrawSetSelectable;
native FIXES_PlayerTextDrawSetSelectable(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetSelectable;
native PlayerTextDrawSetSelectable__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetSelectable;
#define _ALS_PlayerTextDrawSetSelectable
#define PlayerTextDrawSetSelectable( FIXES_PlayerTextDrawSetSelectable(

#if defined _ALS_PlayerTextDrawShow
	#error _ALS_PlayerTextDrawShow defined
#endif
native BAD_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
native FIXES_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
native PlayerTextDrawShow__(playerid, PlayerText:text) = PlayerTextDrawShow;
#define _ALS_PlayerTextDrawShow
#define PlayerTextDrawShow( FIXES_PlayerTextDrawShow(

#if defined _ALS_PlayerTextDrawHide
	#error _ALS_PlayerTextDrawHide defined
#endif
native BAD_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
native FIXES_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
native PlayerTextDrawHide__(playerid, PlayerText:text) = PlayerTextDrawHide;
#define _ALS_PlayerTextDrawHide
#define PlayerTextDrawHide( FIXES_PlayerTextDrawHide(

#if defined _ALS_PlayerTextDrawSetString
	#error _ALS_PlayerTextDrawSetString defined
#endif
native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
native FIXES_PlayerTextDrawSetString(playerid, PlayerText:text, _FIXES_MAYBE_CONST string[]) = PlayerTextDrawSetString;
native PlayerTextDrawSetString__(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
#define _ALS_PlayerTextDrawSetString
#define PlayerTextDrawSetString( FIXES_PlayerTextDrawSetString(

#if defined _ALS_PlayerTextDrawSetPreviewModel
	#error _ALS_PlayerTextDrawSetPreviewModel defined
#endif
native BAD_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
native FIXES_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
native PlayerTextDrawSetPreviewModel__(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
#define _ALS_PlayerTextDrawSetPreviewModel
#define PlayerTextDrawSetPreviewModel( FIXES_PlayerTextDrawSetPreviewModel(

#if defined _ALS_PlayerTextDrawSetPreviewRot
	#error _ALS_PlayerTextDrawSetPreviewRot defined
#endif
native BAD_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
native FIXES_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
native PlayerTextDrawSetPreviewRot__(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
#define _ALS_PlayerTextDrawSetPreviewRot
#define PlayerTextDrawSetPreviewRot( FIXES_PlayerTextDrawSetPreviewRot(

#if defined _ALS_PlayerTextDrawSetPreviewVehCol
	#error _ALS_PlayerTextDrawSetPreviewVehCol defined
#endif
native BAD_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
native FIXES_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
native PlayerTextDrawSetPreviewVehCol__(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
#define _ALS_PlayerTextDrawSetPreviewVehCol
#define PlayerTextDrawSetPreviewVehCol( FIXES_PlayerTextDrawSetPreviewVehCol(

#if defined _ALS_SetPVarInt
	#error _ALS_SetPVarInt defined
#endif
native BAD_SetPVarInt(playerid, pvar[], value) = SetPVarInt;
native FIXES_SetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[], value) = SetPVarInt;
native SetPVarInt__(playerid, const pvar[], value) = SetPVarInt;
#define _ALS_SetPVarInt
#define SetPVarInt( FIXES_SetPVarInt(

#if defined _ALS_GetPVarInt
	#error _ALS_GetPVarInt defined
#endif
native BAD_GetPVarInt(playerid, pvar[]) = GetPVarInt;
native FIXES_GetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarInt;
native GetPVarInt__(playerid, const pvar[]) = GetPVarInt;
#define _ALS_GetPVarInt
#define GetPVarInt( FIXES_GetPVarInt(

#if defined _ALS_SetPVarString
	#error _ALS_SetPVarString defined
#endif
native BAD_SetPVarString(playerid, pvar[], value[]) = SetPVarString;
native FIXES_SetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], _FIXES_MAYBE_CONST value[]) = SetPVarString;
native SetPVarString__(playerid, const pvar[], const value[]) = SetPVarString;
#define _ALS_SetPVarString
#define SetPVarString( FIXES_SetPVarString(

#if defined _ALS_GetPVarString
	#error _ALS_GetPVarString defined
#endif
native BAD_GetPVarString(playerid, pvar[], output[], len) = GetPVarString;
native FIXES_GetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetPVarString;
native GetPVarString__(playerid, const pvar[], output[], len = sizeof (output)) = GetPVarString;
#define _ALS_GetPVarString
#define GetPVarString( FIXES_GetPVarString(

#if defined _ALS_SetPVarFloat
	#error _ALS_SetPVarFloat defined
#endif
native BAD_SetPVarFloat(playerid, pvar[], Float:value) = SetPVarFloat;
native FIXES_SetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[], Float:value) = SetPVarFloat;
native SetPVarFloat__(playerid, const pvar[], Float:value) = SetPVarFloat;
#define _ALS_SetPVarFloat
#define SetPVarFloat( FIXES_SetPVarFloat(

#if defined _ALS_GetPVarFloat
	#error _ALS_GetPVarFloat defined
#endif
native Float:BAD_GetPVarFloat(playerid, pvar[]) = GetPVarFloat;
native Float:FIXES_GetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarFloat;
native Float:GetPVarFloat__(playerid, const pvar[]) = GetPVarFloat;
#define _ALS_GetPVarFloat
#define GetPVarFloat( FIXES_GetPVarFloat(

#if defined _ALS_DeletePVar
	#error _ALS_DeletePVar defined
#endif
native BAD_DeletePVar(playerid, pvar[]) = DeletePVar;
native FIXES_DeletePVar(playerid, _FIXES_MAYBE_CONST pvar[]) = DeletePVar;
native DeletePVar__(playerid, const pvar[]) = DeletePVar;
#define _ALS_DeletePVar
#define DeletePVar( FIXES_DeletePVar(

#if defined _ALS_GetPVarsUpperIndex
	#error _ALS_GetPVarsUpperIndex defined
#endif
native BAD_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
native FIXES_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
native GetPVarsUpperIndex__(playerid) = GetPVarsUpperIndex;
#define _ALS_GetPVarsUpperIndex
#define GetPVarsUpperIndex( FIXES_GetPVarsUpperIndex(

#if defined _ALS_GetPVarNameAtIndex
	#error _ALS_GetPVarNameAtIndex defined
#endif
native BAD_GetPVarNameAtIndex(playerid, index, output[], size) = GetPVarNameAtIndex;
native FIXES_GetPVarNameAtIndex(playerid, index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPVarNameAtIndex;
native GetPVarNameAtIndex__(playerid, index, output[], size = sizeof (output)) = GetPVarNameAtIndex;
#define _ALS_GetPVarNameAtIndex
#define GetPVarNameAtIndex( FIXES_GetPVarNameAtIndex(

#if defined _ALS_GetPVarType
	#error _ALS_GetPVarType defined
#endif
native PLAYER_VARTYPE:BAD_GetPVarType(playerid, pvar[]) = GetPVarType;
native PLAYER_VARTYPE:FIXES_GetPVarType(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarType;
native PLAYER_VARTYPE:GetPVarType__(playerid, const pvar[]) = GetPVarType;
#define _ALS_GetPVarType
#define GetPVarType( FIXES_GetPVarType(

#if defined _ALS_SetPlayerChatBubble
	#error _ALS_SetPlayerChatBubble defined
#endif
native BAD_SetPlayerChatBubble(playerid, text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
native FIXES_SetPlayerChatBubble(playerid, _FIXES_MAYBE_CONST text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
native SetPlayerChatBubble__(playerid, const text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
#define _ALS_SetPlayerChatBubble
#define SetPlayerChatBubble( FIXES_SetPlayerChatBubble(

#if defined _ALS_PutPlayerInVehicle
	#error _ALS_PutPlayerInVehicle defined
#endif
native BAD_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
native FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
native PutPlayerInVehicle__(playerid, vehicleid, seatid) = PutPlayerInVehicle;
#define _ALS_PutPlayerInVehicle
#define PutPlayerInVehicle( FIXES_PutPlayerInVehicle(

#if defined _ALS_GetPlayerVehicleID
	#error _ALS_GetPlayerVehicleID defined
#endif
native BAD_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
native FIXES_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
native GetPlayerVehicleID__(playerid) = GetPlayerVehicleID;
#define _ALS_GetPlayerVehicleID
#define GetPlayerVehicleID( FIXES_GetPlayerVehicleID(

#if defined _ALS_GetPlayerVehicleSeat
	#error _ALS_GetPlayerVehicleSeat defined
#endif
native BAD_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
native FIXES_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
native GetPlayerVehicleSeat__(playerid) = GetPlayerVehicleSeat;
#define _ALS_GetPlayerVehicleSeat
#define GetPlayerVehicleSeat( FIXES_GetPlayerVehicleSeat(

#if defined _ALS_RemovePlayerFromVehicle
	#error _ALS_RemovePlayerFromVehicle defined
#endif
native BAD_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
native FIXES_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
native RemovePlayerFromVehicle__(playerid) = RemovePlayerFromVehicle;
#define _ALS_RemovePlayerFromVehicle
#define RemovePlayerFromVehicle( FIXES_RemovePlayerFromVehicle(

#if defined _ALS_TogglePlayerControllable
	#error _ALS_TogglePlayerControllable defined
#endif
native BAD_TogglePlayerControllable(playerid, toggle) = TogglePlayerControllable;
native FIXES_TogglePlayerControllable(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerControllable;
native TogglePlayerControllable__(playerid, bool:toggle) = TogglePlayerControllable;
#define _ALS_TogglePlayerControllable
#define TogglePlayerControllable( FIXES_TogglePlayerControllable(

#if defined _ALS_PlayerPlaySound
	#error _ALS_PlayerPlaySound defined
#endif
native BAD_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
native FIXES_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
native PlayerPlaySound__(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
#define _ALS_PlayerPlaySound
#define PlayerPlaySound( FIXES_PlayerPlaySound(

#if defined _ALS_ApplyAnimation
	#error _ALS_ApplyAnimation defined
#endif
native BAD_ApplyAnimation(playerid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
native FIXES_ApplyAnimation(playerid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
native ApplyAnimation__(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
#define _ALS_ApplyAnimation
#define ApplyAnimation( FIXES_ApplyAnimation(

#if defined _ALS_ClearAnimations
	#error _ALS_ClearAnimations defined
#endif
native BAD_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
native FIXES_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
native ClearAnimations__(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
#define _ALS_ClearAnimations
#define ClearAnimations( FIXES_ClearAnimations(

#if defined _ALS_GetPlayerAnimationIndex
	#error _ALS_GetPlayerAnimationIndex defined
#endif
native BAD_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
native FIXES_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
native GetPlayerAnimationIndex__(playerid) = GetPlayerAnimationIndex;
#define _ALS_GetPlayerAnimationIndex
#define GetPlayerAnimationIndex( FIXES_GetPlayerAnimationIndex(

#if defined _ALS_GetAnimationName
	#error _ALS_GetAnimationName defined
#endif
native BAD_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2) = GetAnimationName;
native FIXES_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], _FIXES_MAYBE_SIZEOF(len2, animationName)) = GetAnimationName;
native GetAnimationName__(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2 = sizeof (animationName)) = GetAnimationName;
#define _ALS_GetAnimationName
#define GetAnimationName( FIXES_GetAnimationName(

#if defined _ALS_GetPlayerSpecialAction
	#error _ALS_GetPlayerSpecialAction defined
#endif
native SPECIAL_ACTION:BAD_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
native SPECIAL_ACTION:FIXES_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
native SPECIAL_ACTION:GetPlayerSpecialAction__(playerid) = GetPlayerSpecialAction;
#define _ALS_GetPlayerSpecialAction
#define GetPlayerSpecialAction( FIXES_GetPlayerSpecialAction(

#if defined _ALS_SetPlayerSpecialAction
	#error _ALS_SetPlayerSpecialAction defined
#endif
native BAD_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
native FIXES_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
native SetPlayerSpecialAction__(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
#define _ALS_SetPlayerSpecialAction
#define SetPlayerSpecialAction( FIXES_SetPlayerSpecialAction(

#if defined _ALS_DisableRemoteVehicleCollisions
	#error _ALS_DisableRemoteVehicleCollisions defined
#endif
native BAD_DisableRemoteVehicleCollisions(playerid, disable) = DisableRemoteVehicleCollisions;
native FIXES_DisableRemoteVehicleCollisions(playerid, _FIXES_MAYBE_BOOL:disable) = DisableRemoteVehicleCollisions;
native DisableRemoteVehicleCollisions__(playerid, bool:disable) = DisableRemoteVehicleCollisions;
#define _ALS_DisableRemoteVehicleCollisions
#define DisableRemoteVehicleCollisions( FIXES_DisableRemoteVehicleCollisions(

#if defined _ALS_SetPlayerCheckpoint
	#error _ALS_SetPlayerCheckpoint defined
#endif
native BAD_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
native FIXES_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
native SetPlayerCheckpoint__(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
#define _ALS_SetPlayerCheckpoint
#define SetPlayerCheckpoint( FIXES_SetPlayerCheckpoint(

#if defined _ALS_DisablePlayerCheckpoint
	#error _ALS_DisablePlayerCheckpoint defined
#endif
native BAD_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
native FIXES_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
native DisablePlayerCheckpoint__(playerid) = DisablePlayerCheckpoint;
#define _ALS_DisablePlayerCheckpoint
#define DisablePlayerCheckpoint( FIXES_DisablePlayerCheckpoint(

#if defined _ALS_SetPlayerRaceCheckpoint
	#error _ALS_SetPlayerRaceCheckpoint defined
#endif
native BAD_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
native FIXES_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
native SetPlayerRaceCheckpoint__(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
#define _ALS_SetPlayerRaceCheckpoint
#define SetPlayerRaceCheckpoint( FIXES_SetPlayerRaceCheckpoint(

#if defined _ALS_DisablePlayerRaceCheckpoint
	#error _ALS_DisablePlayerRaceCheckpoint defined
#endif
native BAD_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
native FIXES_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
native DisablePlayerRaceCheckpoint__(playerid) = DisablePlayerRaceCheckpoint;
#define _ALS_DisablePlayerRaceCheckpoint
#define DisablePlayerRaceCheckpoint( FIXES_DisablePlayerRaceCheckpoint(

#if defined _ALS_SetPlayerWorldBounds
	#error _ALS_SetPlayerWorldBounds defined
#endif
native BAD_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
native FIXES_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
native SetPlayerWorldBounds__(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
#define _ALS_SetPlayerWorldBounds
#define SetPlayerWorldBounds( FIXES_SetPlayerWorldBounds(

#if defined _ALS_SetPlayerMarkerForPlayer
	#error _ALS_SetPlayerMarkerForPlayer defined
#endif
native BAD_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
native FIXES_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
native SetPlayerMarkerForPlayer__(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
#define _ALS_SetPlayerMarkerForPlayer
#define SetPlayerMarkerForPlayer( FIXES_SetPlayerMarkerForPlayer(

#if defined _ALS_ShowPlayerNameTagForPlayer
	#error _ALS_ShowPlayerNameTagForPlayer defined
#endif
native BAD_ShowPlayerNameTagForPlayer(playerid, targetid, show) = ShowPlayerNameTagForPlayer;
native FIXES_ShowPlayerNameTagForPlayer(playerid, targetid, _FIXES_MAYBE_BOOL:show) = ShowPlayerNameTagForPlayer;
native ShowPlayerNameTagForPlayer__(playerid, targetid, bool:show) = ShowPlayerNameTagForPlayer;
#define _ALS_ShowPlayerNameTagForPlayer
#define ShowPlayerNameTagForPlayer( FIXES_ShowPlayerNameTagForPlayer(

#if defined _ALS_SetPlayerMapIcon
	#error _ALS_SetPlayerMapIcon defined
#endif
native BAD_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
native FIXES_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
native SetPlayerMapIcon__(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
#define _ALS_SetPlayerMapIcon
#define SetPlayerMapIcon( FIXES_SetPlayerMapIcon(

#if defined _ALS_RemovePlayerMapIcon
	#error _ALS_RemovePlayerMapIcon defined
#endif
native BAD_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
native FIXES_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
native RemovePlayerMapIcon__(playerid, iconid) = RemovePlayerMapIcon;
#define _ALS_RemovePlayerMapIcon
#define RemovePlayerMapIcon( FIXES_RemovePlayerMapIcon(

#if defined _ALS_AllowPlayerTeleport
	#error _ALS_AllowPlayerTeleport defined
#endif
native BAD_AllowPlayerTeleport(playerid, allow) = AllowPlayerTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
native FIXES_AllowPlayerTeleport(playerid, _FIXES_MAYBE_BOOL:allow) = AllowPlayerTeleport;
native AllowPlayerTeleport__(playerid, bool:allow) = AllowPlayerTeleport;
#define _ALS_AllowPlayerTeleport
#define AllowPlayerTeleport( FIXES_AllowPlayerTeleport(

#if defined _ALS_SetPlayerCameraPos
	#error _ALS_SetPlayerCameraPos defined
#endif
native BAD_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
native FIXES_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
native SetPlayerCameraPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
#define _ALS_SetPlayerCameraPos
#define SetPlayerCameraPos( FIXES_SetPlayerCameraPos(

#if defined _ALS_SetPlayerCameraLookAt
	#error _ALS_SetPlayerCameraLookAt defined
#endif
native BAD_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
native FIXES_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
native SetPlayerCameraLookAt__(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
#define _ALS_SetPlayerCameraLookAt
#define SetPlayerCameraLookAt( FIXES_SetPlayerCameraLookAt(

#if defined _ALS_SetCameraBehindPlayer
	#error _ALS_SetCameraBehindPlayer defined
#endif
native BAD_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
native FIXES_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
native SetCameraBehindPlayer__(playerid) = SetCameraBehindPlayer;
#define _ALS_SetCameraBehindPlayer
#define SetCameraBehindPlayer( FIXES_SetCameraBehindPlayer(

#if defined _ALS_GetPlayerCameraPos
	#error _ALS_GetPlayerCameraPos defined
#endif
native BAD_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
native FIXES_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
native GetPlayerCameraPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
#define _ALS_GetPlayerCameraPos
#define GetPlayerCameraPos( FIXES_GetPlayerCameraPos(

#if defined _ALS_GetPlayerCameraFrontVector
	#error _ALS_GetPlayerCameraFrontVector defined
#endif
native BAD_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
native FIXES_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
native GetPlayerCameraFrontVector__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
#define _ALS_GetPlayerCameraFrontVector
#define GetPlayerCameraFrontVector( FIXES_GetPlayerCameraFrontVector(

#if defined _ALS_GetPlayerCameraMode
	#error _ALS_GetPlayerCameraMode defined
#endif
native CAM_MODE:BAD_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
native CAM_MODE:FIXES_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
native CAM_MODE:GetPlayerCameraMode__(playerid) = GetPlayerCameraMode;
#define _ALS_GetPlayerCameraMode
#define GetPlayerCameraMode( FIXES_GetPlayerCameraMode(

#if defined _ALS_EnablePlayerCameraTarget
	#error _ALS_EnablePlayerCameraTarget defined
#endif
native BAD_EnablePlayerCameraTarget(playerid, enable) = EnablePlayerCameraTarget;
native FIXES_EnablePlayerCameraTarget(playerid, _FIXES_MAYBE_BOOL:enable) = EnablePlayerCameraTarget;
native EnablePlayerCameraTarget__(playerid, bool:enable) = EnablePlayerCameraTarget;
#define _ALS_EnablePlayerCameraTarget
#define EnablePlayerCameraTarget( FIXES_EnablePlayerCameraTarget(

#if defined _ALS_GetPlayerCameraTargetObject
	#error _ALS_GetPlayerCameraTargetObject defined
#endif
native BAD_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
native FIXES_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
native GetPlayerCameraTargetObject__(playerid) = GetPlayerCameraTargetObject;
#define _ALS_GetPlayerCameraTargetObject
#define GetPlayerCameraTargetObject( FIXES_GetPlayerCameraTargetObject(

#if defined _ALS_GetPlayerCameraTargetVehicle
	#error _ALS_GetPlayerCameraTargetVehicle defined
#endif
native BAD_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
native FIXES_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
native GetPlayerCameraTargetVehicle__(playerid) = GetPlayerCameraTargetVehicle;
#define _ALS_GetPlayerCameraTargetVehicle
#define GetPlayerCameraTargetVehicle( FIXES_GetPlayerCameraTargetVehicle(

#if defined _ALS_GetPlayerCameraTargetPlayer
	#error _ALS_GetPlayerCameraTargetPlayer defined
#endif
native BAD_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
native FIXES_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
native GetPlayerCameraTargetPlayer__(playerid) = GetPlayerCameraTargetPlayer;
#define _ALS_GetPlayerCameraTargetPlayer
#define GetPlayerCameraTargetPlayer( FIXES_GetPlayerCameraTargetPlayer(

#if defined _ALS_GetPlayerCameraTargetActor
	#error _ALS_GetPlayerCameraTargetActor defined
#endif
native BAD_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
native FIXES_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
native GetPlayerCameraTargetActor__(playerid) = GetPlayerCameraTargetActor;
#define _ALS_GetPlayerCameraTargetActor
#define GetPlayerCameraTargetActor( FIXES_GetPlayerCameraTargetActor(

#if defined _ALS_GetPlayerCameraAspectRatio
	#error _ALS_GetPlayerCameraAspectRatio defined
#endif
native Float:BAD_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
native Float:FIXES_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
native Float:GetPlayerCameraAspectRatio__(playerid) = GetPlayerCameraAspectRatio;
#define _ALS_GetPlayerCameraAspectRatio
#define GetPlayerCameraAspectRatio( FIXES_GetPlayerCameraAspectRatio(

#if defined _ALS_GetPlayerCameraZoom
	#error _ALS_GetPlayerCameraZoom defined
#endif
native Float:BAD_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
native Float:FIXES_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
native Float:GetPlayerCameraZoom__(playerid) = GetPlayerCameraZoom;
#define _ALS_GetPlayerCameraZoom
#define GetPlayerCameraZoom( FIXES_GetPlayerCameraZoom(

#if defined _ALS_AttachCameraToObject
	#error _ALS_AttachCameraToObject defined
#endif
native BAD_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
native FIXES_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
native AttachCameraToObject__(playerid, objectid) = AttachCameraToObject;
#define _ALS_AttachCameraToObject
#define AttachCameraToObject( FIXES_AttachCameraToObject(

#if defined _ALS_AttachCameraToPlayerObject
	#error _ALS_AttachCameraToPlayerObject defined
#endif
native BAD_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
native FIXES_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
native AttachCameraToPlayerObject__(playerid, objectid) = AttachCameraToPlayerObject;
#define _ALS_AttachCameraToPlayerObject
#define AttachCameraToPlayerObject( FIXES_AttachCameraToPlayerObject(

#if defined _ALS_InterpolateCameraPos
	#error _ALS_InterpolateCameraPos defined
#endif
native BAD_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
native FIXES_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
native InterpolateCameraPos__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
#define _ALS_InterpolateCameraPos
#define InterpolateCameraPos( FIXES_InterpolateCameraPos(

#if defined _ALS_InterpolateCameraLookAt
	#error _ALS_InterpolateCameraLookAt defined
#endif
native BAD_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
native FIXES_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
native InterpolateCameraLookAt__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
#define _ALS_InterpolateCameraLookAt
#define InterpolateCameraLookAt( FIXES_InterpolateCameraLookAt(

#if defined _ALS_IsPlayerConnected
	#error _ALS_IsPlayerConnected defined
#endif
native BAD_IsPlayerConnected(playerid) = IsPlayerConnected;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerConnected(playerid) = IsPlayerConnected;
native bool:IsPlayerConnected__(playerid) = IsPlayerConnected;
#define _ALS_IsPlayerConnected
#define IsPlayerConnected( FIXES_IsPlayerConnected(

#if defined _ALS_IsPlayerInVehicle
	#error _ALS_IsPlayerInVehicle defined
#endif
native BAD_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
native bool:IsPlayerInVehicle__(playerid, vehicleid) = IsPlayerInVehicle;
#define _ALS_IsPlayerInVehicle
#define IsPlayerInVehicle( FIXES_IsPlayerInVehicle(

#if defined _ALS_IsPlayerInAnyVehicle
	#error _ALS_IsPlayerInAnyVehicle defined
#endif
native BAD_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
native bool:IsPlayerInAnyVehicle__(playerid) = IsPlayerInAnyVehicle;
#define _ALS_IsPlayerInAnyVehicle
#define IsPlayerInAnyVehicle( FIXES_IsPlayerInAnyVehicle(

#if defined _ALS_IsPlayerInCheckpoint
	#error _ALS_IsPlayerInCheckpoint defined
#endif
native BAD_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
native bool:IsPlayerInCheckpoint__(playerid) = IsPlayerInCheckpoint;
#define _ALS_IsPlayerInCheckpoint
#define IsPlayerInCheckpoint( FIXES_IsPlayerInCheckpoint(

#if defined _ALS_IsPlayerInRaceCheckpoint
	#error _ALS_IsPlayerInRaceCheckpoint defined
#endif
native BAD_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
native bool:IsPlayerInRaceCheckpoint__(playerid) = IsPlayerInRaceCheckpoint;
#define _ALS_IsPlayerInRaceCheckpoint
#define IsPlayerInRaceCheckpoint( FIXES_IsPlayerInRaceCheckpoint(

#if defined _ALS_SetPlayerVirtualWorld
	#error _ALS_SetPlayerVirtualWorld defined
#endif
native BAD_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
native FIXES_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
native SetPlayerVirtualWorld__(playerid, virtualWorld) = SetPlayerVirtualWorld;
#define _ALS_SetPlayerVirtualWorld
#define SetPlayerVirtualWorld( FIXES_SetPlayerVirtualWorld(

#if defined _ALS_GetPlayerVirtualWorld
	#error _ALS_GetPlayerVirtualWorld defined
#endif
native BAD_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
native FIXES_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
native GetPlayerVirtualWorld__(playerid) = GetPlayerVirtualWorld;
#define _ALS_GetPlayerVirtualWorld
#define GetPlayerVirtualWorld( FIXES_GetPlayerVirtualWorld(

#if defined _ALS_EnableStuntBonusForPlayer
	#error _ALS_EnableStuntBonusForPlayer defined
#endif
native BAD_EnableStuntBonusForPlayer(playerid, enable) = EnableStuntBonusForPlayer;
native FIXES_EnableStuntBonusForPlayer(playerid, _FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForPlayer;
native EnableStuntBonusForPlayer__(playerid, bool:enable) = EnableStuntBonusForPlayer;
#define _ALS_EnableStuntBonusForPlayer
#define EnableStuntBonusForPlayer( FIXES_EnableStuntBonusForPlayer(

#if defined _ALS_EnableStuntBonusForAll
	#error _ALS_EnableStuntBonusForAll defined
#endif
native BAD_EnableStuntBonusForAll(enable) = EnableStuntBonusForAll;
native FIXES_EnableStuntBonusForAll(_FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForAll;
native EnableStuntBonusForAll__(bool:enable) = EnableStuntBonusForAll;
#define _ALS_EnableStuntBonusForAll
#define EnableStuntBonusForAll( FIXES_EnableStuntBonusForAll(

#if defined _ALS_TogglePlayerSpectating
	#error _ALS_TogglePlayerSpectating defined
#endif
native BAD_TogglePlayerSpectating(playerid, toggle) = TogglePlayerSpectating;
native FIXES_TogglePlayerSpectating(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerSpectating;
native TogglePlayerSpectating__(playerid, bool:toggle) = TogglePlayerSpectating;
#define _ALS_TogglePlayerSpectating
#define TogglePlayerSpectating( FIXES_TogglePlayerSpectating(

#if defined _ALS_PlayerSpectatePlayer
	#error _ALS_PlayerSpectatePlayer defined
#endif
native BAD_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
native FIXES_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
native PlayerSpectatePlayer__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
#define _ALS_PlayerSpectatePlayer
#define PlayerSpectatePlayer( FIXES_PlayerSpectatePlayer(

#if defined _ALS_PlayerSpectateVehicle
	#error _ALS_PlayerSpectateVehicle defined
#endif
native BAD_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
native FIXES_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
native PlayerSpectateVehicle__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
#define _ALS_PlayerSpectateVehicle
#define PlayerSpectateVehicle( FIXES_PlayerSpectateVehicle(

#if defined _ALS_StartRecordingPlayerData
	#error _ALS_StartRecordingPlayerData defined
#endif
native BAD_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, recordFile[]) = StartRecordingPlayerData;
native FIXES_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, _FIXES_MAYBE_CONST recordFile[]) = StartRecordingPlayerData;
native StartRecordingPlayerData__(playerid, PLAYER_RECORDING_TYPE:recordType, const recordFile[]) = StartRecordingPlayerData;
#define _ALS_StartRecordingPlayerData
#define StartRecordingPlayerData( FIXES_StartRecordingPlayerData(

#if defined _ALS_StopRecordingPlayerData
	#error _ALS_StopRecordingPlayerData defined
#endif
native BAD_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
native FIXES_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
native StopRecordingPlayerData__(playerid) = StopRecordingPlayerData;
#define _ALS_StopRecordingPlayerData
#define StopRecordingPlayerData( FIXES_StopRecordingPlayerData(

#if defined _ALS_SelectTextDraw
	#error _ALS_SelectTextDraw defined
#endif
native BAD_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
native FIXES_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
native SelectTextDraw__(playerid, hoverColour) = SelectTextDraw;
#define _ALS_SelectTextDraw
#define SelectTextDraw( FIXES_SelectTextDraw(

#if defined _ALS_CancelSelectTextDraw
	#error _ALS_CancelSelectTextDraw defined
#endif
native BAD_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
native FIXES_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
native CancelSelectTextDraw__(playerid) = CancelSelectTextDraw;
#define _ALS_CancelSelectTextDraw
#define CancelSelectTextDraw( FIXES_CancelSelectTextDraw(

#if defined _ALS_CreateExplosionForPlayer
	#error _ALS_CreateExplosionForPlayer defined
#endif
native BAD_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
native FIXES_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
native CreateExplosionForPlayer__(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
#define _ALS_CreateExplosionForPlayer
#define CreateExplosionForPlayer( FIXES_CreateExplosionForPlayer(

#if defined _ALS_SendClientCheck
	#error _ALS_SendClientCheck defined
#endif
native BAD_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
native FIXES_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
native SendClientCheck__(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
#define _ALS_SendClientCheck
#define SendClientCheck( FIXES_SendClientCheck(

//
// a_samp
//

#if defined _ALS_print
	#error _ALS_print defined
#endif
native BAD_print(const string[]) = print;
native FIXES_print(const string[]) = print;
native print__(const string[]) = print;
#define _ALS_print
#define print( FIXES_print(

#if defined _ALS_printf
	#error _ALS_printf defined
#endif
native BAD_printf(const format[], {Float, _}:...) = printf;
native FIXES_printf(const format[], {Float, _}:...) = printf;
native printf__(const format[], {Float, _}:...) = printf;
#define _ALS_printf
#define printf( FIXES_printf(

#if defined _ALS_format
	#error _ALS_format defined
#endif
native BAD_format(output[], len, const format[], {Float, _}:...) = format;
native FIXES_format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
native format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#define _ALS_format
#define format( FIXES_format(

#if defined _ALS_Print
	#error _ALS_Print defined
#endif
native BAD_Print(const string[]) = print;
native FIXES_Print(const string[]) = print;
native Print__(const string[]) = print;
#define _ALS_Print
#define Print( FIXES_Print(

#if defined _ALS_PrintF
	#error _ALS_PrintF defined
#endif
native BAD_PrintF(const format[], {Float, _}:...) = printf;
native FIXES_PrintF(const format[], {Float, _}:...) = printf;
native PrintF__(const format[], {Float, _}:...) = printf;
#define _ALS_PrintF
#define PrintF( FIXES_PrintF(

#if defined _ALS_Format
	#error _ALS_Format defined
#endif
native BAD_Format(output[], len, const format[], {Float, _}:...) = format;
native FIXES_Format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
native Format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#define _ALS_Format
#define Format( FIXES_Format(

#if defined _ALS_SendClientMessage
	#error _ALS_SendClientMessage defined
#endif
native BAD_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
native FIXES_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
native SendClientMessage__(playerid, colour, const message[]) = SendClientMessage;
#define _ALS_SendClientMessage
#define SendClientMessage( FIXES_SendClientMessage(

#if defined _ALS_SendClientMessageToAll
	#error _ALS_SendClientMessageToAll defined
#endif
native BAD_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
native FIXES_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
native SendClientMessageToAll__(colour, const message[]) = SendClientMessageToAll;
#define _ALS_SendClientMessageToAll
#define SendClientMessageToAll( FIXES_SendClientMessageToAll(

#if defined _ALS_SendPlayerMessageToPlayer
	#error _ALS_SendPlayerMessageToPlayer defined
#endif
native BAD_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
native FIXES_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
native SendPlayerMessageToPlayer__(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
#define _ALS_SendPlayerMessageToPlayer
#define SendPlayerMessageToPlayer( FIXES_SendPlayerMessageToPlayer(

#if defined _ALS_SendPlayerMessageToAll
	#error _ALS_SendPlayerMessageToAll defined
#endif
native BAD_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
native FIXES_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
native SendPlayerMessageToAll__(senderid, const message[]) = SendPlayerMessageToAll;
#define _ALS_SendPlayerMessageToAll
#define SendPlayerMessageToAll( FIXES_SendPlayerMessageToAll(

#if defined _ALS_SendDeathMessage
	#error _ALS_SendDeathMessage defined
#endif
native BAD_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
native FIXES_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
native SendDeathMessage__(killer, killee, weapon) = SendDeathMessage;
#define _ALS_SendDeathMessage
#define SendDeathMessage( FIXES_SendDeathMessage(

#if defined _ALS_SendDeathMessageToPlayer
	#error _ALS_SendDeathMessageToPlayer defined
#endif
native BAD_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
native FIXES_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
native SendDeathMessageToPlayer__(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
#define _ALS_SendDeathMessageToPlayer
#define SendDeathMessageToPlayer( FIXES_SendDeathMessageToPlayer(

#if defined _ALS_GameTextForAll
	#error _ALS_GameTextForAll defined
#endif
native BAD_GameTextForAll(const string[], time, style) = GameTextForAll;
native FIXES_GameTextForAll(const string[], time, style) = GameTextForAll;
native GameTextForAll__(const string[], time, style) = GameTextForAll;
#define _ALS_GameTextForAll
#define GameTextForAll( FIXES_GameTextForAll(

#if defined _ALS_GameTextForPlayer
	#error _ALS_GameTextForPlayer defined
#endif
native BAD_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
native FIXES_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
native GameTextForPlayer__(playerid, const string[], time, style) = GameTextForPlayer;
#define _ALS_GameTextForPlayer
#define GameTextForPlayer( FIXES_GameTextForPlayer(

#if defined _ALS_SetTimer
	#error _ALS_SetTimer defined
#endif
native BAD_SetTimer(functionName[], interval, repeating) = SetTimer;
native FIXES_SetTimer(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating) = SetTimer;
native SetTimer__(const functionName[], interval, bool:repeating) = SetTimer;
#define _ALS_SetTimer
#define SetTimer( FIXES_SetTimer(

#if defined _ALS_SetTimerEx
	#error _ALS_SetTimerEx defined
#endif
native BAD_SetTimerEx(functionName[], interval, repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
native FIXES_SetTimerEx(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
native SetTimerEx__(const functionName[], interval, bool:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
#define _ALS_SetTimerEx
#define SetTimerEx( FIXES_SetTimerEx(

#if defined _ALS_KillTimer
	#error _ALS_KillTimer defined
#endif
native BAD_KillTimer(timerid) = KillTimer;
native FIXES_KillTimer(timerid) = KillTimer;
native KillTimer__(timerid) = KillTimer;
#define _ALS_KillTimer
#define KillTimer( FIXES_KillTimer(

#if defined _ALS_GetTickCount
	#error _ALS_GetTickCount defined
#endif
native BAD_GetTickCount() = GetTickCount;
native FIXES_GetTickCount() = GetTickCount;
native GetTickCount__() = GetTickCount;
#define _ALS_GetTickCount
#define GetTickCount( FIXES_GetTickCount(

#if defined _ALS_GetMaxPlayers
	#error _ALS_GetMaxPlayers defined
#endif
native BAD_GetMaxPlayers() = GetMaxPlayers;
native FIXES_GetMaxPlayers() = GetMaxPlayers;
native GetMaxPlayers__() = GetMaxPlayers;
#define _ALS_GetMaxPlayers
#define GetMaxPlayers( FIXES_GetMaxPlayers(

#if defined _ALS_CallRemoteFunction
	#error _ALS_CallRemoteFunction defined
#endif
native BAD_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
native FIXES_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
native CallRemoteFunction__(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
#define _ALS_CallRemoteFunction
#define CallRemoteFunction( FIXES_CallRemoteFunction(

#if defined _ALS_CallLocalFunction
	#error _ALS_CallLocalFunction defined
#endif
native BAD_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
native FIXES_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
native CallLocalFunction__(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
#define _ALS_CallLocalFunction
#define CallLocalFunction( FIXES_CallLocalFunction(

#if defined _ALS_VectorSize
	#error _ALS_VectorSize defined
#endif
native Float:BAD_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
native Float:FIXES_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
native Float:VectorSize__(Float:x, Float:y, Float:z) = VectorSize;
#define _ALS_VectorSize
#define VectorSize( FIXES_VectorSize(

#if defined _ALS_asin
	#error _ALS_asin defined
#endif
native Float:BAD_asin(Float:value) = asin;
#if FIX_camel_case
	#pragma deprecated Use `ASin`.
#endif
native Float:FIXES_asin(Float:value) = asin;
native Float:asin__(Float:value) = asin;
#define _ALS_asin
#define asin( FIXES_asin(

#if defined _ALS_acos
	#error _ALS_acos defined
#endif
native Float:BAD_acos(Float:value) = acos;
#if FIX_camel_case
	#pragma deprecated Use `ACos`.
#endif
native Float:FIXES_acos(Float:value) = acos;
native Float:acos__(Float:value) = acos;
#define _ALS_acos
#define acos( FIXES_acos(

#if defined _ALS_atan
	#error _ALS_atan defined
#endif
native Float:BAD_atan(Float:value) = atan;
#if FIX_camel_case
	#pragma deprecated Use `ATan`.
#endif
native Float:FIXES_atan(Float:value) = atan;
native Float:atan__(Float:value) = atan;
#define _ALS_atan
#define atan( FIXES_atan(

#if defined _ALS_atan2
	#error _ALS_atan2 defined
#endif
native Float:BAD_atan2(Float:y, Float:x) = atan2;
#if FIX_camel_case
	#pragma deprecated Use `ATan2`.
#endif
native Float:FIXES_atan2(Float:y, Float:x) = atan2;
native Float:atan2__(Float:y, Float:x) = atan2;
#define _ALS_atan2
#define atan2( FIXES_atan2(

#if defined _ALS_ASin
	#error _ALS_ASin defined
#endif
native Float:BAD_ASin(Float:value) = asin;
native Float:FIXES_ASin(Float:value) = asin;
native Float:ASin__(Float:value) = asin;
#define _ALS_ASin
#define ASin( FIXES_ASin(

#if defined _ALS_ACos
	#error _ALS_ACos defined
#endif
native Float:BAD_ACos(Float:value) = acos;
native Float:FIXES_ACos(Float:value) = acos;
native Float:ACos__(Float:value) = acos;
#define _ALS_ACos
#define ACos( FIXES_ACos(

#if defined _ALS_ATan
	#error _ALS_ATan defined
#endif
native Float:BAD_ATan(Float:value) = atan;
native Float:FIXES_ATan(Float:value) = atan;
native Float:ATan__(Float:value) = atan;
#define _ALS_ATan
#define ATan( FIXES_ATan(

#if defined _ALS_ATan2
	#error _ALS_ATan2 defined
#endif
native Float:BAD_ATan2(Float:y, Float:x) = atan2;
native Float:FIXES_ATan2(Float:y, Float:x) = atan2;
native Float:ATan2__(Float:y, Float:x) = atan2;
#define _ALS_ATan2
#define ATan2( FIXES_ATan2(

#if defined _ALS_GetPlayerPoolSize
	#error _ALS_GetPlayerPoolSize defined
#endif
native BAD_GetPlayerPoolSize() = GetPlayerPoolSize;
native FIXES_GetPlayerPoolSize() = GetPlayerPoolSize;
native GetPlayerPoolSize__() = GetPlayerPoolSize;
#define _ALS_GetPlayerPoolSize
#define GetPlayerPoolSize( FIXES_GetPlayerPoolSize(

#if defined _ALS_GetVehiclePoolSize
	#error _ALS_GetVehiclePoolSize defined
#endif
native BAD_GetVehiclePoolSize() = GetVehiclePoolSize;
native FIXES_GetVehiclePoolSize() = GetVehiclePoolSize;
native GetVehiclePoolSize__() = GetVehiclePoolSize;
#define _ALS_GetVehiclePoolSize
#define GetVehiclePoolSize( FIXES_GetVehiclePoolSize(

#if defined _ALS_GetActorPoolSize
	#error _ALS_GetActorPoolSize defined
#endif
native BAD_GetActorPoolSize() = GetActorPoolSize;
native FIXES_GetActorPoolSize() = GetActorPoolSize;
native GetActorPoolSize__() = GetActorPoolSize;
#define _ALS_GetActorPoolSize
#define GetActorPoolSize( FIXES_GetActorPoolSize(

#if defined _ALS_SHA256_PassHash
	#error _ALS_SHA256_PassHash defined
#endif
native BAD_SHA256_PassHash(password[], salt[], output[], size) = SHA256_PassHash;
#pragma deprecated Use BCrypt for hashing passwords.
native FIXES_SHA256_PassHash(_FIXES_MAYBE_CONST password[], _FIXES_MAYBE_CONST salt[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = SHA256_PassHash;
native SHA256_PassHash__(const password[], const salt[], output[], size = sizeof (output)) = SHA256_PassHash;
#define _ALS_SHA256_PassHash
#define SHA256_PassHash( FIXES_SHA256_PassHash(

#if defined _ALS_SetSVarInt
	#error _ALS_SetSVarInt defined
#endif
native BAD_SetSVarInt(svar[], value) = SetSVarInt;
native FIXES_SetSVarInt(_FIXES_MAYBE_CONST svar[], value) = SetSVarInt;
native SetSVarInt__(const svar[], value) = SetSVarInt;
#define _ALS_SetSVarInt
#define SetSVarInt( FIXES_SetSVarInt(

#if defined _ALS_GetSVarInt
	#error _ALS_GetSVarInt defined
#endif
native BAD_GetSVarInt(svar[]) = GetSVarInt;
native FIXES_GetSVarInt(_FIXES_MAYBE_CONST svar[]) = GetSVarInt;
native GetSVarInt__(const svar[]) = GetSVarInt;
#define _ALS_GetSVarInt
#define GetSVarInt( FIXES_GetSVarInt(

#if defined _ALS_SetSVarString
	#error _ALS_SetSVarString defined
#endif
native BAD_SetSVarString(svar[], value[]) = SetSVarString;
native FIXES_SetSVarString(_FIXES_MAYBE_CONST svar[], _FIXES_MAYBE_CONST value[]) = SetSVarString;
native SetSVarString__(const svar[], const value[]) = SetSVarString;
#define _ALS_SetSVarString
#define SetSVarString( FIXES_SetSVarString(

#if defined _ALS_GetSVarString
	#error _ALS_GetSVarString defined
#endif
native BAD_GetSVarString(svar[], output[], len) = GetSVarString;
native FIXES_GetSVarString(_FIXES_MAYBE_CONST svar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetSVarString;
native GetSVarString__(const svar[], output[], len = sizeof (output)) = GetSVarString;
#define _ALS_GetSVarString
#define GetSVarString( FIXES_GetSVarString(

#if defined _ALS_SetSVarFloat
	#error _ALS_SetSVarFloat defined
#endif
native BAD_SetSVarFloat(svar[], Float:value) = SetSVarFloat;
native FIXES_SetSVarFloat(_FIXES_MAYBE_CONST svar[], Float:value) = SetSVarFloat;
native SetSVarFloat__(const svar[], Float:value) = SetSVarFloat;
#define _ALS_SetSVarFloat
#define SetSVarFloat( FIXES_SetSVarFloat(

#if defined _ALS_GetSVarFloat
	#error _ALS_GetSVarFloat defined
#endif
native Float:BAD_GetSVarFloat(svar[]) = GetSVarFloat;
native Float:FIXES_GetSVarFloat(_FIXES_MAYBE_CONST svar[]) = GetSVarFloat;
native Float:GetSVarFloat__(const svar[]) = GetSVarFloat;
#define _ALS_GetSVarFloat
#define GetSVarFloat( FIXES_GetSVarFloat(

#if defined _ALS_DeleteSVar
	#error _ALS_DeleteSVar defined
#endif
native BAD_DeleteSVar(svar[]) = DeleteSVar;
native FIXES_DeleteSVar(_FIXES_MAYBE_CONST svar[]) = DeleteSVar;
native DeleteSVar__(const svar[]) = DeleteSVar;
#define _ALS_DeleteSVar
#define DeleteSVar( FIXES_DeleteSVar(

#if defined _ALS_GetSVarsUpperIndex
	#error _ALS_GetSVarsUpperIndex defined
#endif
native BAD_GetSVarsUpperIndex() = GetSVarsUpperIndex;
native FIXES_GetSVarsUpperIndex() = GetSVarsUpperIndex;
native GetSVarsUpperIndex__() = GetSVarsUpperIndex;
#define _ALS_GetSVarsUpperIndex
#define GetSVarsUpperIndex( FIXES_GetSVarsUpperIndex(

#if defined _ALS_GetSVarNameAtIndex
	#error _ALS_GetSVarNameAtIndex defined
#endif
native BAD_GetSVarNameAtIndex(index, output[], size) = GetSVarNameAtIndex;
native FIXES_GetSVarNameAtIndex(index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetSVarNameAtIndex;
native GetSVarNameAtIndex__(index, output[], size = sizeof (output)) = GetSVarNameAtIndex;
#define _ALS_GetSVarNameAtIndex
#define GetSVarNameAtIndex( FIXES_GetSVarNameAtIndex(

#if defined _ALS_GetSVarType
	#error _ALS_GetSVarType defined
#endif
native SERVER_VARTYPE:BAD_GetSVarType(svar[]) = GetSVarType;
native SERVER_VARTYPE:FIXES_GetSVarType(_FIXES_MAYBE_CONST svar[]) = GetSVarType;
native SERVER_VARTYPE:GetSVarType__(const svar[]) = GetSVarType;
#define _ALS_GetSVarType
#define GetSVarType( FIXES_GetSVarType(

#if defined _ALS_SetGameModeText
	#error _ALS_SetGameModeText defined
#endif
native BAD_SetGameModeText(const string[]) = SetGameModeText;
native FIXES_SetGameModeText(const string[]) = SetGameModeText;
native SetGameModeText__(const string[]) = SetGameModeText;
#define _ALS_SetGameModeText
#define SetGameModeText( FIXES_SetGameModeText(

#if defined _ALS_SetTeamCount
	#error _ALS_SetTeamCount defined
#endif
native BAD_SetTeamCount(count) = SetTeamCount;
native FIXES_SetTeamCount(count) = SetTeamCount;
native SetTeamCount__(count) = SetTeamCount;
#define _ALS_SetTeamCount
#define SetTeamCount( FIXES_SetTeamCount(

#if defined _ALS_AddPlayerClass
	#error _ALS_AddPlayerClass defined
#endif
native BAD_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
native FIXES_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
native AddPlayerClass__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
#define _ALS_AddPlayerClass
#define AddPlayerClass( FIXES_AddPlayerClass(

#if defined _ALS_AddPlayerClassEx
	#error _ALS_AddPlayerClassEx defined
#endif
native BAD_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
native FIXES_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
native AddPlayerClassEx__(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
#define _ALS_AddPlayerClassEx
#define AddPlayerClassEx( FIXES_AddPlayerClassEx(

#if defined _ALS_AddStaticVehicle
	#error _ALS_AddStaticVehicle defined
#endif
native BAD_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
native FIXES_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
native AddStaticVehicle__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
#define _ALS_AddStaticVehicle
#define AddStaticVehicle( FIXES_AddStaticVehicle(

#if defined _ALS_AddStaticVehicleEx
	#error _ALS_AddStaticVehicleEx defined
#endif
native BAD_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, addSiren = false) = AddStaticVehicleEx;
native FIXES_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = AddStaticVehicleEx;
native AddStaticVehicleEx__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false) = AddStaticVehicleEx;
#define _ALS_AddStaticVehicleEx
#define AddStaticVehicleEx( FIXES_AddStaticVehicleEx(

#if defined _ALS_AddStaticPickup
	#error _ALS_AddStaticPickup defined
#endif
native BAD_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
native FIXES_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
native AddStaticPickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
#define _ALS_AddStaticPickup
#define AddStaticPickup( FIXES_AddStaticPickup(

#if defined _ALS_CreatePickup
	#error _ALS_CreatePickup defined
#endif
native BAD_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
native FIXES_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
native CreatePickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
#define _ALS_CreatePickup
#define CreatePickup( FIXES_CreatePickup(

#if defined _ALS_DestroyPickup
	#error _ALS_DestroyPickup defined
#endif
native BAD_DestroyPickup(pickup) = DestroyPickup;
native FIXES_DestroyPickup(pickup) = DestroyPickup;
native DestroyPickup__(pickup) = DestroyPickup;
#define _ALS_DestroyPickup
#define DestroyPickup( FIXES_DestroyPickup(

#if defined _ALS_ShowNameTags
	#error _ALS_ShowNameTags defined
#endif
native BAD_ShowNameTags(show) = ShowNameTags;
native FIXES_ShowNameTags(_FIXES_MAYBE_BOOL:show) = ShowNameTags;
native ShowNameTags__(bool:show) = ShowNameTags;
#define _ALS_ShowNameTags
#define ShowNameTags( FIXES_ShowNameTags(

#if defined _ALS_ShowPlayerMarkers
	#error _ALS_ShowPlayerMarkers defined
#endif
native BAD_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
native FIXES_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
native ShowPlayerMarkers__(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
#define _ALS_ShowPlayerMarkers
#define ShowPlayerMarkers( FIXES_ShowPlayerMarkers(

#if defined _ALS_GameModeExit
	#error _ALS_GameModeExit defined
#endif
native BAD_GameModeExit() = GameModeExit;
native FIXES_GameModeExit() = GameModeExit;
native GameModeExit__() = GameModeExit;
#define _ALS_GameModeExit
#define GameModeExit( FIXES_GameModeExit(

#if defined _ALS_SetWorldTime
	#error _ALS_SetWorldTime defined
#endif
native BAD_SetWorldTime(hour) = SetWorldTime;
native FIXES_SetWorldTime(hour) = SetWorldTime;
native SetWorldTime__(hour) = SetWorldTime;
#define _ALS_SetWorldTime
#define SetWorldTime( FIXES_SetWorldTime(

#if defined _ALS_GetWeaponName
	#error _ALS_GetWeaponName defined
#endif
native BAD_GetWeaponName(WEAPON:weaponid, const weapon[], len) = GetWeaponName;
native FIXES_GetWeaponName(WEAPON:weaponid, _FIXES_NOT_CONST weapon[], _FIXES_MAYBE_SIZEOF(len, weapon)) = GetWeaponName;
native GetWeaponName__(WEAPON:weaponid, weapon[], len = sizeof (weapon)) = GetWeaponName;
#define _ALS_GetWeaponName
#define GetWeaponName( FIXES_GetWeaponName(

#if defined _ALS_EnableTirePopping
	#error _ALS_EnableTirePopping defined
#endif
native BAD_EnableTirePopping(enable) = EnableTirePopping;
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
native FIXES_EnableTirePopping(_FIXES_MAYBE_BOOL:enable) = EnableTirePopping;
native EnableTirePopping__(bool:enable) = EnableTirePopping;
#define _ALS_EnableTirePopping
#define EnableTirePopping( FIXES_EnableTirePopping(

#if defined _ALS_EnableVehicleFriendlyFire
	#error _ALS_EnableVehicleFriendlyFire defined
#endif
native BAD_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
native FIXES_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
native EnableVehicleFriendlyFire__() = EnableVehicleFriendlyFire;
#define _ALS_EnableVehicleFriendlyFire
#define EnableVehicleFriendlyFire( FIXES_EnableVehicleFriendlyFire(

#if defined _ALS_AllowInteriorWeapons
	#error _ALS_AllowInteriorWeapons defined
#endif
native BAD_AllowInteriorWeapons(allow) = AllowInteriorWeapons;
#pragma deprecated Use `OnPlayerInteriorChange`.
native FIXES_AllowInteriorWeapons(_FIXES_MAYBE_BOOL:allow) = AllowInteriorWeapons;
native AllowInteriorWeapons__(bool:allow) = AllowInteriorWeapons;
#define _ALS_AllowInteriorWeapons
#define AllowInteriorWeapons( FIXES_AllowInteriorWeapons(

#if defined _ALS_SetWeather
	#error _ALS_SetWeather defined
#endif
native BAD_SetWeather(weatherid) = SetWeather;
native FIXES_SetWeather(weatherid) = SetWeather;
native SetWeather__(weatherid) = SetWeather;
#define _ALS_SetWeather
#define SetWeather( FIXES_SetWeather(

#if defined _ALS_GetGravity
	#error _ALS_GetGravity defined
#endif
native Float:BAD_GetGravity() = GetGravity;
native Float:FIXES_GetGravity() = GetGravity;
native Float:GetGravity__() = GetGravity;
#define _ALS_GetGravity
#define GetGravity( FIXES_GetGravity(

#if defined _ALS_SetGravity
	#error _ALS_SetGravity defined
#endif
native BAD_SetGravity(Float:gravity) = SetGravity;
native FIXES_SetGravity(Float:gravity) = SetGravity;
native SetGravity__(Float:gravity) = SetGravity;
#define _ALS_SetGravity
#define SetGravity( FIXES_SetGravity(

#if defined _ALS_AllowAdminTeleport
	#error _ALS_AllowAdminTeleport defined
#endif
native BAD_AllowAdminTeleport(allow) = AllowAdminTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
native FIXES_AllowAdminTeleport(_FIXES_MAYBE_BOOL:allow) = AllowAdminTeleport;
native AllowAdminTeleport__(bool:allow) = AllowAdminTeleport;
#define _ALS_AllowAdminTeleport
#define AllowAdminTeleport( FIXES_AllowAdminTeleport(

#if defined _ALS_SetDeathDropAmount
	#error _ALS_SetDeathDropAmount defined
#endif
native BAD_SetDeathDropAmount(amount) = SetDeathDropAmount;
#pragma deprecated Use `CreatePickup`.
native FIXES_SetDeathDropAmount(amount) = SetDeathDropAmount;
native SetDeathDropAmount__(amount) = SetDeathDropAmount;
#define _ALS_SetDeathDropAmount
#define SetDeathDropAmount( FIXES_SetDeathDropAmount(

#if defined _ALS_CreateExplosion
	#error _ALS_CreateExplosion defined
#endif
native BAD_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
native FIXES_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
native CreateExplosion__(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
#define _ALS_CreateExplosion
#define CreateExplosion( FIXES_CreateExplosion(

#if defined _ALS_EnableZoneNames
	#error _ALS_EnableZoneNames defined
#endif
native BAD_EnableZoneNames(enable) = EnableZoneNames;
native FIXES_EnableZoneNames(_FIXES_MAYBE_BOOL:enable) = EnableZoneNames;
native EnableZoneNames__(bool:enable) = EnableZoneNames;
#define _ALS_EnableZoneNames
#define EnableZoneNames( FIXES_EnableZoneNames(

#if defined _ALS_UsePlayerPedAnims
	#error _ALS_UsePlayerPedAnims defined
#endif
native BAD_UsePlayerPedAnims() = UsePlayerPedAnims;
native FIXES_UsePlayerPedAnims() = UsePlayerPedAnims;
native UsePlayerPedAnims__() = UsePlayerPedAnims;
#define _ALS_UsePlayerPedAnims
#define UsePlayerPedAnims( FIXES_UsePlayerPedAnims(

native DisableInteriorEnterExits(); 
#if defined _ALS_SetNameTagDrawDistance
	#error _ALS_SetNameTagDrawDistance defined
#endif
native BAD_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
native FIXES_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
native SetNameTagDrawDistance__(Float:distance) = SetNameTagDrawDistance;
#define _ALS_SetNameTagDrawDistance
#define SetNameTagDrawDistance( FIXES_SetNameTagDrawDistance(

#if defined _ALS_DisableNameTagLOS
	#error _ALS_DisableNameTagLOS defined
#endif
native BAD_DisableNameTagLOS() = DisableNameTagLOS;
native FIXES_DisableNameTagLOS() = DisableNameTagLOS;
native DisableNameTagLOS__() = DisableNameTagLOS;
#define _ALS_DisableNameTagLOS
#define DisableNameTagLOS( FIXES_DisableNameTagLOS(

#if defined _ALS_LimitGlobalChatRadius
	#error _ALS_LimitGlobalChatRadius defined
#endif
native BAD_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
native FIXES_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
native LimitGlobalChatRadius__(Float:chatRadius) = LimitGlobalChatRadius;
#define _ALS_LimitGlobalChatRadius
#define LimitGlobalChatRadius( FIXES_LimitGlobalChatRadius(

#if defined _ALS_LimitPlayerMarkerRadius
	#error _ALS_LimitPlayerMarkerRadius defined
#endif
native BAD_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
native FIXES_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
native LimitPlayerMarkerRadius__(Float:markerRadius) = LimitPlayerMarkerRadius;
#define _ALS_LimitPlayerMarkerRadius
#define LimitPlayerMarkerRadius( FIXES_LimitPlayerMarkerRadius(

#if defined _ALS_ConnectNPC
	#error _ALS_ConnectNPC defined
#endif
native BAD_ConnectNPC(name[], script[]) = ConnectNPC;
native FIXES_ConnectNPC(_FIXES_MAYBE_CONST name[], _FIXES_MAYBE_CONST script[]) = ConnectNPC;
native ConnectNPC__(const name[], const script[]) = ConnectNPC;
#define _ALS_ConnectNPC
#define ConnectNPC( FIXES_ConnectNPC(

#if defined _ALS_IsPlayerNPC
	#error _ALS_IsPlayerNPC defined
#endif
native BAD_IsPlayerNPC(playerid) = IsPlayerNPC;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerNPC(playerid) = IsPlayerNPC;
native bool:IsPlayerNPC__(playerid) = IsPlayerNPC;
#define _ALS_IsPlayerNPC
#define IsPlayerNPC( FIXES_IsPlayerNPC(

#if defined _ALS_AddCharModel
	#error _ALS_AddCharModel defined
#endif
native BAD_AddCharModel(baseid, newid, dff[], textureLibrary[]) = AddCharModel;
native FIXES_AddCharModel(baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddCharModel;
native AddCharModel__(baseid, newid, const dff[], const textureLibrary[]) = AddCharModel;
#define _ALS_AddCharModel
#define AddCharModel( FIXES_AddCharModel(

#if defined _ALS_AddSimpleModel
	#error _ALS_AddSimpleModel defined
#endif
native BAD_AddSimpleModel(virtualWorld, baseid, newid, dff[], textureLibrary[]) = AddSimpleModel;
native FIXES_AddSimpleModel(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddSimpleModel;
native AddSimpleModel__(virtualWorld, baseid, newid, const dff[], const textureLibrary[]) = AddSimpleModel;
#define _ALS_AddSimpleModel
#define AddSimpleModel( FIXES_AddSimpleModel(

#if defined _ALS_AddSimpleModelTimed
	#error _ALS_AddSimpleModelTimed defined
#endif
native BAD_AddSimpleModelTimed(virtualWorld, baseid, newid, dff[], textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
native FIXES_AddSimpleModelTimed(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
native AddSimpleModelTimed__(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
#define _ALS_AddSimpleModelTimed
#define AddSimpleModelTimed( FIXES_AddSimpleModelTimed(

#if defined _ALS_FindModelFileNameFromCRC
	#error _ALS_FindModelFileNameFromCRC defined
#endif
native BAD_FindModelFileNameFromCRC(crc, output[], size) = FindModelFileNameFromCRC;
native FIXES_FindModelFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindModelFileNameFromCRC;
native FindModelFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindModelFileNameFromCRC;
#define _ALS_FindModelFileNameFromCRC
#define FindModelFileNameFromCRC( FIXES_FindModelFileNameFromCRC(

#if defined _ALS_FindTextureFileNameFromCRC
	#error _ALS_FindTextureFileNameFromCRC defined
#endif
native BAD_FindTextureFileNameFromCRC(crc, output[], size) = FindTextureFileNameFromCRC;
native FIXES_FindTextureFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindTextureFileNameFromCRC;
native FindTextureFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindTextureFileNameFromCRC;
#define _ALS_FindTextureFileNameFromCRC
#define FindTextureFileNameFromCRC( FIXES_FindTextureFileNameFromCRC(

#if defined _ALS_RedirectDownload
	#error _ALS_RedirectDownload defined
#endif
native BAD_RedirectDownload(playerid, url[]) = RedirectDownload;
native FIXES_RedirectDownload(playerid, _FIXES_MAYBE_CONST url[]) = RedirectDownload;
native RedirectDownload__(playerid, const url[]) = RedirectDownload;
#define _ALS_RedirectDownload
#define RedirectDownload( FIXES_RedirectDownload(

#if defined _ALS_IsPlayerAdmin
	#error _ALS_IsPlayerAdmin defined
#endif
native BAD_IsPlayerAdmin(playerid) = IsPlayerAdmin;
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerAdmin(playerid) = IsPlayerAdmin;
native bool:IsPlayerAdmin__(playerid) = IsPlayerAdmin;
#define _ALS_IsPlayerAdmin
#define IsPlayerAdmin( FIXES_IsPlayerAdmin(

#if defined _ALS_Kick
	#error _ALS_Kick defined
#endif
native BAD_Kick(playerid) = Kick;
native FIXES_Kick(playerid) = Kick;
native Kick__(playerid) = Kick;
#define _ALS_Kick
#define Kick( FIXES_Kick(

#if defined _ALS_Ban
	#error _ALS_Ban defined
#endif
native BAD_Ban(playerid) = Ban;
native FIXES_Ban(playerid) = Ban;
native Ban__(playerid) = Ban;
#define _ALS_Ban
#define Ban( FIXES_Ban(

#if defined _ALS_BanEx
	#error _ALS_BanEx defined
#endif
native BAD_BanEx(playerid, const reason[]) = BanEx;
native FIXES_BanEx(playerid, const reason[]) = BanEx;
native BanEx__(playerid, const reason[]) = BanEx;
#define _ALS_BanEx
#define BanEx( FIXES_BanEx(

#if defined _ALS_SendRconCommand
	#error _ALS_SendRconCommand defined
#endif
native BAD_SendRconCommand(command[]) = SendRconCommand;
native FIXES_SendRconCommand(_FIXES_MAYBE_CONST command[]) = SendRconCommand;
native SendRconCommand__(const command[]) = SendRconCommand;
#define _ALS_SendRconCommand
#define SendRconCommand( FIXES_SendRconCommand(

#if defined _ALS_GetPlayerNetworkStats
	#error _ALS_GetPlayerNetworkStats defined
#endif
native BAD_GetPlayerNetworkStats(playerid, output[], size) = GetPlayerNetworkStats;
native FIXES_GetPlayerNetworkStats(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPlayerNetworkStats;
native GetPlayerNetworkStats__(playerid, output[], size = sizeof (output)) = GetPlayerNetworkStats;
#define _ALS_GetPlayerNetworkStats
#define GetPlayerNetworkStats( FIXES_GetPlayerNetworkStats(

#if defined _ALS_GetNetworkStats
	#error _ALS_GetNetworkStats defined
#endif
native BAD_GetNetworkStats(output[], size) = GetNetworkStats;
native FIXES_GetNetworkStats(output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetNetworkStats;
native GetNetworkStats__(output[], size = sizeof (output)) = GetNetworkStats;
#define _ALS_GetNetworkStats
#define GetNetworkStats( FIXES_GetNetworkStats(

#if defined _ALS_GetPlayerVersion
	#error _ALS_GetPlayerVersion defined
#endif
native BAD_GetPlayerVersion(playerid, const version[], len) = GetPlayerVersion;
native FIXES_GetPlayerVersion(playerid, _FIXES_NOT_CONST version[], _FIXES_MAYBE_SIZEOF(len, version)) = GetPlayerVersion;
native GetPlayerVersion__(playerid, version[], len = sizeof (version)) = GetPlayerVersion;
#define _ALS_GetPlayerVersion
#define GetPlayerVersion( FIXES_GetPlayerVersion(

#if defined _ALS_BlockIpAddress
	#error _ALS_BlockIpAddress defined
#endif
native BAD_BlockIpAddress(ipAddress[], timeMS) = BlockIpAddress;
native FIXES_BlockIpAddress(_FIXES_MAYBE_CONST ipAddress[], timeMS) = BlockIpAddress;
native BlockIpAddress__(const ipAddress[], timeMS) = BlockIpAddress;
#define _ALS_BlockIpAddress
#define BlockIpAddress( FIXES_BlockIpAddress(

#if defined _ALS_UnBlockIpAddress
	#error _ALS_UnBlockIpAddress defined
#endif
native BAD_UnBlockIpAddress(ipAddress[]) = UnBlockIpAddress;
native FIXES_UnBlockIpAddress(_FIXES_MAYBE_CONST ipAddress[]) = UnBlockIpAddress;
native UnBlockIpAddress__(const ipAddress[]) = UnBlockIpAddress;
#define _ALS_UnBlockIpAddress
#define UnBlockIpAddress( FIXES_UnBlockIpAddress(

#if defined _ALS_GetServerVarAsString
	#error _ALS_GetServerVarAsString defined
#endif
native BAD_GetServerVarAsString(const cvar[], buffer[], len) = GetServerVarAsString;
#pragma deprecated Use `GetConsoleVarAsString`.
native FIXES_GetServerVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetServerVarAsString;
native GetServerVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetServerVarAsString;
#define _ALS_GetServerVarAsString
#define GetServerVarAsString( FIXES_GetServerVarAsString(

#if defined _ALS_GetServerVarAsInt
	#error _ALS_GetServerVarAsInt defined
#endif
native BAD_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
#pragma deprecated Use `GetConsoleVarAsInt`.
native FIXES_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
native GetServerVarAsInt__(const cvar[]) = GetServerVarAsInt;
#define _ALS_GetServerVarAsInt
#define GetServerVarAsInt( FIXES_GetServerVarAsInt(

#if defined _ALS_GetServerVarAsBool
	#error _ALS_GetServerVarAsBool defined
#endif
native BAD_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
#pragma deprecated Use `GetConsoleVarAsBool`.
native _FIXES_MAYBE_BOOL:FIXES_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
native bool:GetServerVarAsBool__(const cvar[]) = GetServerVarAsBool;
#define _ALS_GetServerVarAsBool
#define GetServerVarAsBool( FIXES_GetServerVarAsBool(

#if defined _ALS_GetConsoleVarAsString
	#error _ALS_GetConsoleVarAsString defined
#endif
native BAD_GetConsoleVarAsString(const cvar[], buffer[], len) = GetConsoleVarAsString;
native FIXES_GetConsoleVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetConsoleVarAsString;
native GetConsoleVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetConsoleVarAsString;
#define _ALS_GetConsoleVarAsString
#define GetConsoleVarAsString( FIXES_GetConsoleVarAsString(

#if defined _ALS_GetConsoleVarAsInt
	#error _ALS_GetConsoleVarAsInt defined
#endif
native BAD_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
native FIXES_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
native GetConsoleVarAsInt__(const cvar[]) = GetConsoleVarAsInt;
#define _ALS_GetConsoleVarAsInt
#define GetConsoleVarAsInt( FIXES_GetConsoleVarAsInt(

#if defined _ALS_GetConsoleVarAsBool
	#error _ALS_GetConsoleVarAsBool defined
#endif
native BAD_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
native _FIXES_MAYBE_BOOL:FIXES_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
native bool:GetConsoleVarAsBool__(const cvar[]) = GetConsoleVarAsBool;
#define _ALS_GetConsoleVarAsBool
#define GetConsoleVarAsBool( FIXES_GetConsoleVarAsBool(

#if defined _ALS_GetServerTickRate
	#error _ALS_GetServerTickRate defined
#endif
native BAD_GetServerTickRate() = GetServerTickRate;
native FIXES_GetServerTickRate() = GetServerTickRate;
native GetServerTickRate__() = GetServerTickRate;
#define _ALS_GetServerTickRate
#define GetServerTickRate( FIXES_GetServerTickRate(

#if defined _ALS_NetStats_GetConnectedTime
	#error _ALS_NetStats_GetConnectedTime defined
#endif
native BAD_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
native FIXES_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
native NetStats_GetConnectedTime__(playerid) = NetStats_GetConnectedTime;
#define _ALS_NetStats_GetConnectedTime
#define NetStats_GetConnectedTime( FIXES_NetStats_GetConnectedTime(

#if defined _ALS_NetStats_MessagesReceived
	#error _ALS_NetStats_MessagesReceived defined
#endif
native BAD_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
native FIXES_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
native NetStats_MessagesReceived__(playerid) = NetStats_MessagesReceived;
#define _ALS_NetStats_MessagesReceived
#define NetStats_MessagesReceived( FIXES_NetStats_MessagesReceived(

#if defined _ALS_NetStats_BytesReceived
	#error _ALS_NetStats_BytesReceived defined
#endif
native BAD_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
native FIXES_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
native NetStats_BytesReceived__(playerid) = NetStats_BytesReceived;
#define _ALS_NetStats_BytesReceived
#define NetStats_BytesReceived( FIXES_NetStats_BytesReceived(

#if defined _ALS_NetStats_MessagesSent
	#error _ALS_NetStats_MessagesSent defined
#endif
native BAD_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
native FIXES_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
native NetStats_MessagesSent__(playerid) = NetStats_MessagesSent;
#define _ALS_NetStats_MessagesSent
#define NetStats_MessagesSent( FIXES_NetStats_MessagesSent(

#if defined _ALS_NetStats_BytesSent
	#error _ALS_NetStats_BytesSent defined
#endif
native BAD_NetStats_BytesSent(playerid) = NetStats_BytesSent;
native FIXES_NetStats_BytesSent(playerid) = NetStats_BytesSent;
native NetStats_BytesSent__(playerid) = NetStats_BytesSent;
#define _ALS_NetStats_BytesSent
#define NetStats_BytesSent( FIXES_NetStats_BytesSent(

#if defined _ALS_NetStats_MessagesRecvPerSecond
	#error _ALS_NetStats_MessagesRecvPerSecond defined
#endif
native BAD_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
native FIXES_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
native NetStats_MessagesRecvPerSecond__(playerid) = NetStats_MessagesRecvPerSecond;
#define _ALS_NetStats_MessagesRecvPerSecond
#define NetStats_MessagesRecvPerSecond( FIXES_NetStats_MessagesRecvPerSecond(

#if defined _ALS_NetStats_PacketLossPercent
	#error _ALS_NetStats_PacketLossPercent defined
#endif
native Float:BAD_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
native Float:FIXES_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
native Float:NetStats_PacketLossPercent__(playerid) = NetStats_PacketLossPercent;
#define _ALS_NetStats_PacketLossPercent
#define NetStats_PacketLossPercent( FIXES_NetStats_PacketLossPercent(

#if defined _ALS_NetStats_ConnectionStatus
	#error _ALS_NetStats_ConnectionStatus defined
#endif
native BAD_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
native FIXES_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
native NetStats_ConnectionStatus__(playerid) = NetStats_ConnectionStatus;
#define _ALS_NetStats_ConnectionStatus
#define NetStats_ConnectionStatus( FIXES_NetStats_ConnectionStatus(

#if defined _ALS_NetStats_GetIpPort
	#error _ALS_NetStats_GetIpPort defined
#endif
native BAD_NetStats_GetIpPort(playerid, output[], size) = NetStats_GetIpPort;
native FIXES_NetStats_GetIpPort(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = NetStats_GetIpPort;
native NetStats_GetIpPort__(playerid, output[], size = sizeof (output)) = NetStats_GetIpPort;
#define _ALS_NetStats_GetIpPort
#define NetStats_GetIpPort( FIXES_NetStats_GetIpPort(

#if defined _ALS_CreateMenu
	#error _ALS_CreateMenu defined
#endif
native Menu:BAD_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
native Menu:FIXES_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
native Menu:CreateMenu__(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
#define _ALS_CreateMenu
#define CreateMenu( FIXES_CreateMenu(

#if defined _ALS_DestroyMenu
	#error _ALS_DestroyMenu defined
#endif
native BAD_DestroyMenu(Menu:menuid) = DestroyMenu;
native FIXES_DestroyMenu(Menu:menuid) = DestroyMenu;
native DestroyMenu__(Menu:menuid) = DestroyMenu;
#define _ALS_DestroyMenu
#define DestroyMenu( FIXES_DestroyMenu(

#if defined _ALS_AddMenuItem
	#error _ALS_AddMenuItem defined
#endif
native BAD_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
native FIXES_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
native AddMenuItem__(Menu:menuid, column, const text[]) = AddMenuItem;
#define _ALS_AddMenuItem
#define AddMenuItem( FIXES_AddMenuItem(

#if defined _ALS_SetMenuColumnHeader
	#error _ALS_SetMenuColumnHeader defined
#endif
native BAD_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
native FIXES_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
native SetMenuColumnHeader__(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
#define _ALS_SetMenuColumnHeader
#define SetMenuColumnHeader( FIXES_SetMenuColumnHeader(

#if defined _ALS_ShowMenuForPlayer
	#error _ALS_ShowMenuForPlayer defined
#endif
native BAD_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
native FIXES_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
native ShowMenuForPlayer__(Menu:menuid, playerid) = ShowMenuForPlayer;
#define _ALS_ShowMenuForPlayer
#define ShowMenuForPlayer( FIXES_ShowMenuForPlayer(

#if defined _ALS_HideMenuForPlayer
	#error _ALS_HideMenuForPlayer defined
#endif
native BAD_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
native FIXES_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
native HideMenuForPlayer__(Menu:menuid, playerid) = HideMenuForPlayer;
#define _ALS_HideMenuForPlayer
#define HideMenuForPlayer( FIXES_HideMenuForPlayer(

#if defined _ALS_IsValidMenu
	#error _ALS_IsValidMenu defined
#endif
native BAD_IsValidMenu(Menu:menuid) = IsValidMenu;
native _FIXES_MAYBE_BOOL:FIXES_IsValidMenu(Menu:menuid) = IsValidMenu;
native bool:IsValidMenu__(Menu:menuid) = IsValidMenu;
#define _ALS_IsValidMenu
#define IsValidMenu( FIXES_IsValidMenu(

#if defined _ALS_DisableMenu
	#error _ALS_DisableMenu defined
#endif
native BAD_DisableMenu(Menu:menuid) = DisableMenu;
native FIXES_DisableMenu(Menu:menuid) = DisableMenu;
native DisableMenu__(Menu:menuid) = DisableMenu;
#define _ALS_DisableMenu
#define DisableMenu( FIXES_DisableMenu(

#if defined _ALS_DisableMenuRow
	#error _ALS_DisableMenuRow defined
#endif
native BAD_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
native FIXES_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
native DisableMenuRow__(Menu:menuid, row) = DisableMenuRow;
#define _ALS_DisableMenuRow
#define DisableMenuRow( FIXES_DisableMenuRow(

#if defined _ALS_GetPlayerMenu
	#error _ALS_GetPlayerMenu defined
#endif
native Menu:BAD_GetPlayerMenu(playerid) = GetPlayerMenu;
native Menu:FIXES_GetPlayerMenu(playerid) = GetPlayerMenu;
native Menu:GetPlayerMenu__(playerid) = GetPlayerMenu;
#define _ALS_GetPlayerMenu
#define GetPlayerMenu( FIXES_GetPlayerMenu(

#if defined _ALS_TextDrawCreate
	#error _ALS_TextDrawCreate defined
#endif
native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
native Text:FIXES_TextDrawCreate(Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = TextDrawCreate;
native Text:TextDrawCreate__(Float:x, Float:y, const text[]) = TextDrawCreate;
#define _ALS_TextDrawCreate
#define TextDrawCreate( FIXES_TextDrawCreate(

#if defined _ALS_TextDrawDestroy
	#error _ALS_TextDrawDestroy defined
#endif
native BAD_TextDrawDestroy(Text:text) = TextDrawDestroy;
native FIXES_TextDrawDestroy(Text:text) = TextDrawDestroy;
native TextDrawDestroy__(Text:text) = TextDrawDestroy;
#define _ALS_TextDrawDestroy
#define TextDrawDestroy( FIXES_TextDrawDestroy(

#if defined _ALS_TextDrawLetterSize
	#error _ALS_TextDrawLetterSize defined
#endif
native BAD_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
native FIXES_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
native TextDrawLetterSize__(Text:text, Float:width, Float:height) = TextDrawLetterSize;
#define _ALS_TextDrawLetterSize
#define TextDrawLetterSize( FIXES_TextDrawLetterSize(

#if defined _ALS_TextDrawTextSize
	#error _ALS_TextDrawTextSize defined
#endif
native BAD_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
native FIXES_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
native TextDrawTextSize__(Text:text, Float:width, Float:height) = TextDrawTextSize;
#define _ALS_TextDrawTextSize
#define TextDrawTextSize( FIXES_TextDrawTextSize(

#if defined _ALS_TextDrawAlignment
	#error _ALS_TextDrawAlignment defined
#endif
native BAD_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
native FIXES_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
native TextDrawAlignment__(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
#define _ALS_TextDrawAlignment
#define TextDrawAlignment( FIXES_TextDrawAlignment(

#if defined _ALS_TextDrawColor
	#error _ALS_TextDrawColor defined
#endif
native BAD_TextDrawColor(Text:text, colour) = TextDrawColor;
native FIXES_TextDrawColor(Text:text, colour) = TextDrawColor;
native TextDrawColor__(Text:text, colour) = TextDrawColor;
#define _ALS_TextDrawColor
#define TextDrawColor( FIXES_TextDrawColor(

#if defined _ALS_TextDrawUseBox
	#error _ALS_TextDrawUseBox defined
#endif
native BAD_TextDrawUseBox(Text:text, use) = TextDrawUseBox;
native FIXES_TextDrawUseBox(Text:text, _FIXES_MAYBE_BOOL:use) = TextDrawUseBox;
native TextDrawUseBox__(Text:text, bool:use) = TextDrawUseBox;
#define _ALS_TextDrawUseBox
#define TextDrawUseBox( FIXES_TextDrawUseBox(

#if defined _ALS_TextDrawBoxColor
	#error _ALS_TextDrawBoxColor defined
#endif
native BAD_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
native FIXES_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
native TextDrawBoxColor__(Text:text, colour) = TextDrawBoxColor;
#define _ALS_TextDrawBoxColor
#define TextDrawBoxColor( FIXES_TextDrawBoxColor(

#if defined _ALS_TextDrawSetShadow
	#error _ALS_TextDrawSetShadow defined
#endif
native BAD_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
native FIXES_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
native TextDrawSetShadow__(Text:text, size) = TextDrawSetShadow;
#define _ALS_TextDrawSetShadow
#define TextDrawSetShadow( FIXES_TextDrawSetShadow(

#if defined _ALS_TextDrawSetOutline
	#error _ALS_TextDrawSetOutline defined
#endif
native BAD_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
native FIXES_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
native TextDrawSetOutline__(Text:text, size) = TextDrawSetOutline;
#define _ALS_TextDrawSetOutline
#define TextDrawSetOutline( FIXES_TextDrawSetOutline(

#if defined _ALS_TextDrawBackgroundColor
	#error _ALS_TextDrawBackgroundColor defined
#endif
native BAD_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
native FIXES_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
native TextDrawBackgroundColor__(Text:text, colour) = TextDrawBackgroundColor;
#define _ALS_TextDrawBackgroundColor
#define TextDrawBackgroundColor( FIXES_TextDrawBackgroundColor(

#if defined _ALS_TextDrawFont
	#error _ALS_TextDrawFont defined
#endif
native BAD_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
native FIXES_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
native TextDrawFont__(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
#define _ALS_TextDrawFont
#define TextDrawFont( FIXES_TextDrawFont(

#if defined _ALS_TextDrawSetProportional
	#error _ALS_TextDrawSetProportional defined
#endif
native BAD_TextDrawSetProportional(Text:text, set) = TextDrawSetProportional;
native FIXES_TextDrawSetProportional(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetProportional;
native TextDrawSetProportional__(Text:text, bool:set) = TextDrawSetProportional;
#define _ALS_TextDrawSetProportional
#define TextDrawSetProportional( FIXES_TextDrawSetProportional(

#if defined _ALS_TextDrawSetSelectable
	#error _ALS_TextDrawSetSelectable defined
#endif
native BAD_TextDrawSetSelectable(Text:text, set) = TextDrawSetSelectable;
native FIXES_TextDrawSetSelectable(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetSelectable;
native TextDrawSetSelectable__(Text:text, bool:set) = TextDrawSetSelectable;
#define _ALS_TextDrawSetSelectable
#define TextDrawSetSelectable( FIXES_TextDrawSetSelectable(

#if defined _ALS_TextDrawShowForPlayer
	#error _ALS_TextDrawShowForPlayer defined
#endif
native BAD_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
native FIXES_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
native TextDrawShowForPlayer__(playerid, Text:text) = TextDrawShowForPlayer;
#define _ALS_TextDrawShowForPlayer
#define TextDrawShowForPlayer( FIXES_TextDrawShowForPlayer(

#if defined _ALS_TextDrawHideForPlayer
	#error _ALS_TextDrawHideForPlayer defined
#endif
native BAD_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
native FIXES_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
native TextDrawHideForPlayer__(playerid, Text:text) = TextDrawHideForPlayer;
#define _ALS_TextDrawHideForPlayer
#define TextDrawHideForPlayer( FIXES_TextDrawHideForPlayer(

#if defined _ALS_TextDrawShowForAll
	#error _ALS_TextDrawShowForAll defined
#endif
native BAD_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
native FIXES_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
native TextDrawShowForAll__(Text:text) = TextDrawShowForAll;
#define _ALS_TextDrawShowForAll
#define TextDrawShowForAll( FIXES_TextDrawShowForAll(

#if defined _ALS_TextDrawHideForAll
	#error _ALS_TextDrawHideForAll defined
#endif
native BAD_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
native FIXES_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
native TextDrawHideForAll__(Text:text) = TextDrawHideForAll;
#define _ALS_TextDrawHideForAll
#define TextDrawHideForAll( FIXES_TextDrawHideForAll(

#if defined _ALS_TextDrawSetString
	#error _ALS_TextDrawSetString defined
#endif
native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
native FIXES_TextDrawSetString(Text:text, _FIXES_MAYBE_CONST string[]) = TextDrawSetString;
native TextDrawSetString__(Text:text, const string[]) = TextDrawSetString;
#define _ALS_TextDrawSetString
#define TextDrawSetString( FIXES_TextDrawSetString(

#if defined _ALS_TextDrawSetPreviewModel
	#error _ALS_TextDrawSetPreviewModel defined
#endif
native BAD_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
native FIXES_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
native TextDrawSetPreviewModel__(Text:text, modelIndex) = TextDrawSetPreviewModel;
#define _ALS_TextDrawSetPreviewModel
#define TextDrawSetPreviewModel( FIXES_TextDrawSetPreviewModel(

#if defined _ALS_TextDrawSetPreviewRot
	#error _ALS_TextDrawSetPreviewRot defined
#endif
native BAD_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
native FIXES_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
native TextDrawSetPreviewRot__(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
#define _ALS_TextDrawSetPreviewRot
#define TextDrawSetPreviewRot( FIXES_TextDrawSetPreviewRot(

#if defined _ALS_TextDrawSetPreviewVehCol
	#error _ALS_TextDrawSetPreviewVehCol defined
#endif
native BAD_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
native FIXES_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
native TextDrawSetPreviewVehCol__(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
#define _ALS_TextDrawSetPreviewVehCol
#define TextDrawSetPreviewVehCol( FIXES_TextDrawSetPreviewVehCol(

#if defined _ALS_GangZoneCreate
	#error _ALS_GangZoneCreate defined
#endif
native BAD_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
native FIXES_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
native GangZoneCreate__(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
#define _ALS_GangZoneCreate
#define GangZoneCreate( FIXES_GangZoneCreate(

#if defined _ALS_GangZoneDestroy
	#error _ALS_GangZoneDestroy defined
#endif
native BAD_GangZoneDestroy(zone) = GangZoneDestroy;
native FIXES_GangZoneDestroy(zone) = GangZoneDestroy;
native GangZoneDestroy__(zone) = GangZoneDestroy;
#define _ALS_GangZoneDestroy
#define GangZoneDestroy( FIXES_GangZoneDestroy(

#if defined _ALS_GangZoneShowForPlayer
	#error _ALS_GangZoneShowForPlayer defined
#endif
native BAD_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
native FIXES_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
native GangZoneShowForPlayer__(playerid, zone, colour) = GangZoneShowForPlayer;
#define _ALS_GangZoneShowForPlayer
#define GangZoneShowForPlayer( FIXES_GangZoneShowForPlayer(

#if defined _ALS_GangZoneShowForAll
	#error _ALS_GangZoneShowForAll defined
#endif
native BAD_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
native FIXES_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
native GangZoneShowForAll__(zone, colour) = GangZoneShowForAll;
#define _ALS_GangZoneShowForAll
#define GangZoneShowForAll( FIXES_GangZoneShowForAll(

#if defined _ALS_GangZoneHideForPlayer
	#error _ALS_GangZoneHideForPlayer defined
#endif
native BAD_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
native FIXES_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
native GangZoneHideForPlayer__(playerid, zone) = GangZoneHideForPlayer;
#define _ALS_GangZoneHideForPlayer
#define GangZoneHideForPlayer( FIXES_GangZoneHideForPlayer(

#if defined _ALS_GangZoneHideForAll
	#error _ALS_GangZoneHideForAll defined
#endif
native BAD_GangZoneHideForAll(zone) = GangZoneHideForAll;
native FIXES_GangZoneHideForAll(zone) = GangZoneHideForAll;
native GangZoneHideForAll__(zone) = GangZoneHideForAll;
#define _ALS_GangZoneHideForAll
#define GangZoneHideForAll( FIXES_GangZoneHideForAll(

#if defined _ALS_GangZoneFlashForPlayer
	#error _ALS_GangZoneFlashForPlayer defined
#endif
native BAD_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
native FIXES_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
native GangZoneFlashForPlayer__(playerid, zone, flashColour) = GangZoneFlashForPlayer;
#define _ALS_GangZoneFlashForPlayer
#define GangZoneFlashForPlayer( FIXES_GangZoneFlashForPlayer(

#if defined _ALS_GangZoneFlashForAll
	#error _ALS_GangZoneFlashForAll defined
#endif
native BAD_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
native FIXES_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
native GangZoneFlashForAll__(zone, flashColour) = GangZoneFlashForAll;
#define _ALS_GangZoneFlashForAll
#define GangZoneFlashForAll( FIXES_GangZoneFlashForAll(

#if defined _ALS_GangZoneStopFlashForPlayer
	#error _ALS_GangZoneStopFlashForPlayer defined
#endif
native BAD_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
native FIXES_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
native GangZoneStopFlashForPlayer__(playerid, zone) = GangZoneStopFlashForPlayer;
#define _ALS_GangZoneStopFlashForPlayer
#define GangZoneStopFlashForPlayer( FIXES_GangZoneStopFlashForPlayer(

#if defined _ALS_GangZoneStopFlashForAll
	#error _ALS_GangZoneStopFlashForAll defined
#endif
native BAD_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
native FIXES_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
native GangZoneStopFlashForAll__(zone) = GangZoneStopFlashForAll;
#define _ALS_GangZoneStopFlashForAll
#define GangZoneStopFlashForAll( FIXES_GangZoneStopFlashForAll(

#if defined _ALS_Create3DTextLabel
	#error _ALS_Create3DTextLabel defined
#endif
native Text3D:BAD_Create3DTextLabel(text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, testLOS = false) = Create3DTextLabel;
native Text3D:FIXES_Create3DTextLabel(_FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, _FIXES_MAYBE_BOOL:testLOS = false) = Create3DTextLabel;
native Text3D:Create3DTextLabel__(const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, bool:testLOS = false) = Create3DTextLabel;
#define _ALS_Create3DTextLabel
#define Create3DTextLabel( FIXES_Create3DTextLabel(

#if defined _ALS_Delete3DTextLabel
	#error _ALS_Delete3DTextLabel defined
#endif
native BAD_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
native FIXES_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
native Delete3DTextLabel__(Text3D:textid) = Delete3DTextLabel;
#define _ALS_Delete3DTextLabel
#define Delete3DTextLabel( FIXES_Delete3DTextLabel(

#if defined _ALS_Attach3DTextLabelToPlayer
	#error _ALS_Attach3DTextLabelToPlayer defined
#endif
native BAD_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
native FIXES_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
native Attach3DTextLabelToPlayer__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
#define _ALS_Attach3DTextLabelToPlayer
#define Attach3DTextLabelToPlayer( FIXES_Attach3DTextLabelToPlayer(

#if defined _ALS_Attach3DTextLabelToVehicle
	#error _ALS_Attach3DTextLabelToVehicle defined
#endif
native BAD_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
native FIXES_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
native Attach3DTextLabelToVehicle__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
#define _ALS_Attach3DTextLabelToVehicle
#define Attach3DTextLabelToVehicle( FIXES_Attach3DTextLabelToVehicle(

#if defined _ALS_Update3DTextLabelText
	#error _ALS_Update3DTextLabelText defined
#endif
native BAD_Update3DTextLabelText(Text3D:textid, colour, text[]) = Update3DTextLabelText;
native FIXES_Update3DTextLabelText(Text3D:textid, colour, _FIXES_MAYBE_CONST text[]) = Update3DTextLabelText;
native Update3DTextLabelText__(Text3D:textid, colour, const text[]) = Update3DTextLabelText;
#define _ALS_Update3DTextLabelText
#define Update3DTextLabelText( FIXES_Update3DTextLabelText(

#if defined _ALS_CreatePlayer3DTextLabel
	#error _ALS_CreatePlayer3DTextLabel defined
#endif
native PlayerText3D:BAD_CreatePlayer3DTextLabel(playerid, text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, testLOS = false) = CreatePlayer3DTextLabel;
native PlayerText3D:FIXES_CreatePlayer3DTextLabel(playerid, _FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, _FIXES_MAYBE_BOOL:testLOS = false) = CreatePlayer3DTextLabel;
native PlayerText3D:CreatePlayer3DTextLabel__(playerid, const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, bool:testLOS = false) = CreatePlayer3DTextLabel;
#define _ALS_CreatePlayer3DTextLabel
#define CreatePlayer3DTextLabel( FIXES_CreatePlayer3DTextLabel(

#if defined _ALS_DeletePlayer3DTextLabel
	#error _ALS_DeletePlayer3DTextLabel defined
#endif
native BAD_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
native FIXES_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
native DeletePlayer3DTextLabel__(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
#define _ALS_DeletePlayer3DTextLabel
#define DeletePlayer3DTextLabel( FIXES_DeletePlayer3DTextLabel(

#if defined _ALS_UpdatePlayer3DTextLabelText
	#error _ALS_UpdatePlayer3DTextLabelText defined
#endif
native BAD_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, text[]) = UpdatePlayer3DTextLabelText;
native FIXES_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, _FIXES_MAYBE_CONST text[]) = UpdatePlayer3DTextLabelText;
native UpdatePlayer3DTextLabelText__(playerid, PlayerText3D:textid, colour, const text[]) = UpdatePlayer3DTextLabelText;
#define _ALS_UpdatePlayer3DTextLabelText
#define UpdatePlayer3DTextLabelText( FIXES_UpdatePlayer3DTextLabelText(

#if defined _ALS_ShowPlayerDialog
	#error _ALS_ShowPlayerDialog defined
#endif
native BAD_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, caption[], info[], button1[], button2[]) = ShowPlayerDialog;
native FIXES_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, _FIXES_MAYBE_CONST caption[], _FIXES_MAYBE_CONST info[], _FIXES_MAYBE_CONST button1[], _FIXES_MAYBE_CONST button2[]) = ShowPlayerDialog;
native ShowPlayerDialog__(playerid, dialogid, DIALOG_STYLE:style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
#define _ALS_ShowPlayerDialog
#define ShowPlayerDialog( FIXES_ShowPlayerDialog(

#if defined _ALS_gpci
	#error _ALS_gpci defined
#endif
native BAD_gpci(playerid, serial[], len) = gpci;
#if FIX_camel_case
	#pragma deprecated Use `GPCI`.
#endif
native FIXES_gpci(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
native gpci__(playerid, serial[], len = sizeof (serial)) = gpci;
#define _ALS_gpci
#define gpci( FIXES_gpci(

#if defined _ALS_GPCI
	#error _ALS_GPCI defined
#endif
native BAD_GPCI(playerid, serial[], len) = gpci;
native FIXES_GPCI(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
native GPCI__(playerid, serial[], len = sizeof (serial)) = gpci;
#define _ALS_GPCI
#define GPCI( FIXES_GPCI(

//
// a_sampdb
//

#if defined _ALS_db_open
	#error _ALS_db_open defined
#endif
native DB:BAD_db_open(name[]) = db_open;
#if FIX_camel_case
	#pragma deprecated Use `DB_Open`.
#endif
native DB:FIXES_db_open(_FIXES_MAYBE_CONST name[]) = db_open;
native DB:db_open__(const name[]) = db_open;
#define _ALS_db_open
#define db_open( FIXES_db_open(

#if defined _ALS_DB_Open
	#error _ALS_DB_Open defined
#endif
native DB:BAD_DB_Open(name[]) = db_open;
native DB:FIXES_DB_Open(_FIXES_MAYBE_CONST name[]) = db_open;
native DB:DB_Open__(const name[]) = db_open;
#define _ALS_DB_Open
#define DB_Open( FIXES_DB_Open(

#if defined _ALS_db_close
	#error _ALS_db_close defined
#endif
native BAD_db_close(DB:db) = db_close;
#if FIX_camel_case
	#pragma deprecated Use `DB_Close`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_close(DB:db) = db_close;
native bool:db_close__(DB:db) = db_close;
#define _ALS_db_close
#define db_close( FIXES_db_close(

#if defined _ALS_DB_Close
	#error _ALS_DB_Close defined
#endif
native BAD_DB_Close(DB:db) = db_close;
native _FIXES_MAYBE_BOOL:FIXES_DB_Close(DB:db) = db_close;
native bool:DB_Close__(DB:db) = db_close;
#define _ALS_DB_Close
#define DB_Close( FIXES_DB_Close(

#if defined _ALS_db_query
	#error _ALS_db_query defined
#endif
native DBResult:BAD_db_query(DB:db, query[]) = db_query;
#if FIX_camel_case
	#pragma deprecated Use `DB_Query`.
#endif
native DBResult:FIXES_db_query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
native DBResult:db_query__(DB:db, const query[]) = db_query;
#define _ALS_db_query
#define db_query( FIXES_db_query(

#if defined _ALS_DB_Query
	#error _ALS_DB_Query defined
#endif
native DBResult:BAD_DB_Query(DB:db, query[]) = db_query;
native DBResult:FIXES_DB_Query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
native DBResult:DB_Query__(DB:db, const query[]) = db_query;
#define _ALS_DB_Query
#define DB_Query( FIXES_DB_Query(

#if defined _ALS_db_free_result
	#error _ALS_db_free_result defined
#endif
native BAD_db_free_result(DBResult:result) = db_free_result;
#if FIX_camel_case
	#pragma deprecated Use `DB_FreeResult`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_free_result(DBResult:result) = db_free_result;
native bool:db_free_result__(DBResult:result) = db_free_result;
#define _ALS_db_free_result
#define db_free_result( FIXES_db_free_result(

#if defined _ALS_DB_FreeResult
	#error _ALS_DB_FreeResult defined
#endif
native BAD_DB_FreeResult(DBResult:result) = db_free_result;
native _FIXES_MAYBE_BOOL:FIXES_DB_FreeResult(DBResult:result) = db_free_result;
native bool:DB_FreeResult__(DBResult:result) = db_free_result;
#define _ALS_DB_FreeResult
#define DB_FreeResult( FIXES_DB_FreeResult(

#if defined _ALS_db_num_rows
	#error _ALS_db_num_rows defined
#endif
native BAD_db_num_rows(DBResult:result) = db_num_rows;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumRows`.
#endif
native FIXES_db_num_rows(DBResult:result) = db_num_rows;
native db_num_rows__(DBResult:result) = db_num_rows;
#define _ALS_db_num_rows
#define db_num_rows( FIXES_db_num_rows(

#if defined _ALS_DB_NumRows
	#error _ALS_DB_NumRows defined
#endif
native BAD_DB_NumRows(DBResult:result) = db_num_rows;
native FIXES_DB_NumRows(DBResult:result) = db_num_rows;
native DB_NumRows__(DBResult:result) = db_num_rows;
#define _ALS_DB_NumRows
#define DB_NumRows( FIXES_DB_NumRows(

#if defined _ALS_db_next_row
	#error _ALS_db_next_row defined
#endif
native BAD_db_next_row(DBResult:result) = db_next_row;
#if FIX_camel_case
	#pragma deprecated Use `DB_NextRow`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_next_row(DBResult:result) = db_next_row;
native bool:db_next_row__(DBResult:result) = db_next_row;
#define _ALS_db_next_row
#define db_next_row( FIXES_db_next_row(

#if defined _ALS_DB_NextRow
	#error _ALS_DB_NextRow defined
#endif
native BAD_DB_NextRow(DBResult:result) = db_next_row;
native _FIXES_MAYBE_BOOL:FIXES_DB_NextRow(DBResult:result) = db_next_row;
native bool:DB_NextRow__(DBResult:result) = db_next_row;
#define _ALS_DB_NextRow
#define DB_NextRow( FIXES_DB_NextRow(

#if defined _ALS_db_num_fields
	#error _ALS_db_num_fields defined
#endif
native BAD_db_num_fields(DBResult:result) = db_num_fields;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumFields`.
#endif
native FIXES_db_num_fields(DBResult:result) = db_num_fields;
native db_num_fields__(DBResult:result) = db_num_fields;
#define _ALS_db_num_fields
#define db_num_fields( FIXES_db_num_fields(

#if defined _ALS_DB_NumFields
	#error _ALS_DB_NumFields defined
#endif
native BAD_DB_NumFields(DBResult:result) = db_num_fields;
native FIXES_DB_NumFields(DBResult:result) = db_num_fields;
native DB_NumFields__(DBResult:result) = db_num_fields;
#define _ALS_DB_NumFields
#define DB_NumFields( FIXES_DB_NumFields(

#if defined _ALS_db_field_name
	#error _ALS_db_field_name defined
#endif
native BAD_db_field_name(DBResult:result, field, output[], size) = db_field_name;
#if FIX_camel_case
	#pragma deprecated Use `DB_FieldName`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_field_name(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
native bool:db_field_name__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#define _ALS_db_field_name
#define db_field_name( FIXES_db_field_name(

#if defined _ALS_DB_FieldName
	#error _ALS_DB_FieldName defined
#endif
native BAD_DB_FieldName(DBResult:result, field, output[], size) = db_field_name;
native _FIXES_MAYBE_BOOL:FIXES_DB_FieldName(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
native bool:DB_FieldName__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#define _ALS_DB_FieldName
#define DB_FieldName( FIXES_DB_FieldName(

#if defined _ALS_db_get_field
	#error _ALS_db_get_field defined
#endif
native BAD_db_get_field(DBResult:result, field, output[], size) = db_get_field;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetField`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_get_field(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
native bool:db_get_field__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#define _ALS_db_get_field
#define db_get_field( FIXES_db_get_field(

#if defined _ALS_DB_GetField
	#error _ALS_DB_GetField defined
#endif
native BAD_DB_GetField(DBResult:result, field, output[], size) = db_get_field;
native _FIXES_MAYBE_BOOL:FIXES_DB_GetField(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
native bool:DB_GetField__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#define _ALS_DB_GetField
#define DB_GetField( FIXES_DB_GetField(

#if defined _ALS_db_get_field_int
	#error _ALS_db_get_field_int defined
#endif
native BAD_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldInt`.
#endif
native FIXES_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
native db_get_field_int__(DBResult:result, field = 0) = db_get_field_int;
#define _ALS_db_get_field_int
#define db_get_field_int( FIXES_db_get_field_int(

#if defined _ALS_DB_GetFieldInt
	#error _ALS_DB_GetFieldInt defined
#endif
native BAD_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
native FIXES_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
native DB_GetFieldInt__(DBResult:result, field = 0) = db_get_field_int;
#define _ALS_DB_GetFieldInt
#define DB_GetFieldInt( FIXES_DB_GetFieldInt(

#if defined _ALS_db_get_field_float
	#error _ALS_db_get_field_float defined
#endif
native Float:BAD_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldFloat`.
#endif
native Float:FIXES_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
native Float:db_get_field_float__(DBResult:result, field = 0) = db_get_field_float;
#define _ALS_db_get_field_float
#define db_get_field_float( FIXES_db_get_field_float(

#if defined _ALS_DB_GetFieldFloat
	#error _ALS_DB_GetFieldFloat defined
#endif
native Float:BAD_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
native Float:FIXES_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
native Float:DB_GetFieldFloat__(DBResult:result, field = 0) = db_get_field_float;
#define _ALS_DB_GetFieldFloat
#define DB_GetFieldFloat( FIXES_DB_GetFieldFloat(

#if defined _ALS_db_get_field_assoc
	#error _ALS_db_get_field_assoc defined
#endif
native BAD_db_get_field_assoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssoc`.
#endif
native _FIXES_MAYBE_BOOL:FIXES_db_get_field_assoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
native bool:db_get_field_assoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#define _ALS_db_get_field_assoc
#define db_get_field_assoc( FIXES_db_get_field_assoc(

#if defined _ALS_DB_GetFieldAssoc
	#error _ALS_DB_GetFieldAssoc defined
#endif
native BAD_DB_GetFieldAssoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
native _FIXES_MAYBE_BOOL:FIXES_DB_GetFieldAssoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
native bool:DB_GetFieldAssoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#define _ALS_DB_GetFieldAssoc
#define DB_GetFieldAssoc( FIXES_DB_GetFieldAssoc(

#if defined _ALS_db_get_field_assoc_int
	#error _ALS_db_get_field_assoc_int defined
#endif
native BAD_db_get_field_assoc_int(DBResult:result, field[]) = db_get_field_assoc_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocInt`.
#endif
native FIXES_db_get_field_assoc_int(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
native db_get_field_assoc_int__(DBResult:result, const field[]) = db_get_field_assoc_int;
#define _ALS_db_get_field_assoc_int
#define db_get_field_assoc_int( FIXES_db_get_field_assoc_int(

#if defined _ALS_DB_GetFieldAssocInt
	#error _ALS_DB_GetFieldAssocInt defined
#endif
native BAD_DB_GetFieldAssocInt(DBResult:result, field[]) = db_get_field_assoc_int;
native FIXES_DB_GetFieldAssocInt(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
native DB_GetFieldAssocInt__(DBResult:result, const field[]) = db_get_field_assoc_int;
#define _ALS_DB_GetFieldAssocInt
#define DB_GetFieldAssocInt( FIXES_DB_GetFieldAssocInt(

#if defined _ALS_db_get_field_assoc_float
	#error _ALS_db_get_field_assoc_float defined
#endif
native Float:BAD_db_get_field_assoc_float(DBResult:result, field[]) = db_get_field_assoc_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocFloat`.
#endif
native Float:FIXES_db_get_field_assoc_float(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
native Float:db_get_field_assoc_float__(DBResult:result, const field[]) = db_get_field_assoc_float;
#define _ALS_db_get_field_assoc_float
#define db_get_field_assoc_float( FIXES_db_get_field_assoc_float(

#if defined _ALS_DB_GetFieldAssocFloat
	#error _ALS_DB_GetFieldAssocFloat defined
#endif
native Float:BAD_DB_GetFieldAssocFloat(DBResult:result, field[]) = db_get_field_assoc_float;
native Float:FIXES_DB_GetFieldAssocFloat(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
native Float:DB_GetFieldAssocFloat__(DBResult:result, const field[]) = db_get_field_assoc_float;
#define _ALS_DB_GetFieldAssocFloat
#define DB_GetFieldAssocFloat( FIXES_DB_GetFieldAssocFloat(

#if defined _ALS_db_get_mem_handle
	#error _ALS_db_get_mem_handle defined
#endif
native BAD_db_get_mem_handle(DB:db) = db_get_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetMemHandle`.
#endif
native FIXES_db_get_mem_handle(DB:db) = db_get_mem_handle;
native db_get_mem_handle__(DB:db) = db_get_mem_handle;
#define _ALS_db_get_mem_handle
#define db_get_mem_handle( FIXES_db_get_mem_handle(

#if defined _ALS_DB_GetMemHandle
	#error _ALS_DB_GetMemHandle defined
#endif
native BAD_DB_GetMemHandle(DB:db) = db_get_mem_handle;
native FIXES_DB_GetMemHandle(DB:db) = db_get_mem_handle;
native DB_GetMemHandle__(DB:db) = db_get_mem_handle;
#define _ALS_DB_GetMemHandle
#define DB_GetMemHandle( FIXES_DB_GetMemHandle(

#if defined _ALS_db_get_result_mem_handle
	#error _ALS_db_get_result_mem_handle defined
#endif
native BAD_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetResultMemHandle`.
#endif
native FIXES_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
native db_get_result_mem_handle__(DBResult:result) = db_get_result_mem_handle;
#define _ALS_db_get_result_mem_handle
#define db_get_result_mem_handle( FIXES_db_get_result_mem_handle(

#if defined _ALS_DB_GetResultMemHandle
	#error _ALS_DB_GetResultMemHandle defined
#endif
native BAD_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
native FIXES_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
native DB_GetResultMemHandle__(DBResult:result) = db_get_result_mem_handle;
#define _ALS_DB_GetResultMemHandle
#define DB_GetResultMemHandle( FIXES_DB_GetResultMemHandle(

#if defined _ALS_db_debug_openfiles
	#error _ALS_db_debug_openfiles defined
#endif
native BAD_db_debug_openfiles() = db_debug_openfiles;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenFiles`.
#endif
native FIXES_db_debug_openfiles() = db_debug_openfiles;
native db_debug_openfiles__() = db_debug_openfiles;
#define _ALS_db_debug_openfiles
#define db_debug_openfiles( FIXES_db_debug_openfiles(

#if defined _ALS_DB_DebugOpenFiles
	#error _ALS_DB_DebugOpenFiles defined
#endif
native BAD_DB_DebugOpenFiles() = db_debug_openfiles;
native FIXES_DB_DebugOpenFiles() = db_debug_openfiles;
native DB_DebugOpenFiles__() = db_debug_openfiles;
#define _ALS_DB_DebugOpenFiles
#define DB_DebugOpenFiles( FIXES_DB_DebugOpenFiles(

#if defined _ALS_db_debug_openresults
	#error _ALS_db_debug_openresults defined
#endif
native BAD_db_debug_openresults() = db_debug_openresults;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenResults`.
#endif
native FIXES_db_debug_openresults() = db_debug_openresults;
native db_debug_openresults__() = db_debug_openresults;
#define _ALS_db_debug_openresults
#define db_debug_openresults( FIXES_db_debug_openresults(

#if defined _ALS_DB_DebugOpenResults
	#error _ALS_DB_DebugOpenResults defined
#endif
native BAD_DB_DebugOpenResults() = db_debug_openresults;
native FIXES_DB_DebugOpenResults() = db_debug_openresults;
native DB_DebugOpenResults__() = db_debug_openresults;
#define _ALS_DB_DebugOpenResults
#define DB_DebugOpenResults( FIXES_DB_DebugOpenResults(

//
// a_vehicles
//

#if defined _ALS_CreateVehicle
	#error _ALS_CreateVehicle defined
#endif
native BAD_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, addSiren = false) = CreateVehicle;
native FIXES_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = CreateVehicle;
native CreateVehicle__(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, bool:addSiren = false) = CreateVehicle;
#define _ALS_CreateVehicle
#define CreateVehicle( FIXES_CreateVehicle(

#if defined _ALS_DestroyVehicle
	#error _ALS_DestroyVehicle defined
#endif
native BAD_DestroyVehicle(vehicleid) = DestroyVehicle;
native FIXES_DestroyVehicle(vehicleid) = DestroyVehicle;
native DestroyVehicle__(vehicleid) = DestroyVehicle;
#define _ALS_DestroyVehicle
#define DestroyVehicle( FIXES_DestroyVehicle(

#if defined _ALS_IsVehicleStreamedIn
	#error _ALS_IsVehicleStreamedIn defined
#endif
native BAD_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
native _FIXES_MAYBE_BOOL:FIXES_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
native bool:IsVehicleStreamedIn__(vehicleid, playerid) = IsVehicleStreamedIn;
#define _ALS_IsVehicleStreamedIn
#define IsVehicleStreamedIn( FIXES_IsVehicleStreamedIn(

#if defined _ALS_GetVehiclePos
	#error _ALS_GetVehiclePos defined
#endif
native BAD_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
native FIXES_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
native GetVehiclePos__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
#define _ALS_GetVehiclePos
#define GetVehiclePos( FIXES_GetVehiclePos(

#if defined _ALS_SetVehiclePos
	#error _ALS_SetVehiclePos defined
#endif
native BAD_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
native FIXES_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
native SetVehiclePos__(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
#define _ALS_SetVehiclePos
#define SetVehiclePos( FIXES_SetVehiclePos(

#if defined _ALS_GetVehicleZAngle
	#error _ALS_GetVehicleZAngle defined
#endif
native BAD_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
native FIXES_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
native GetVehicleZAngle__(vehicleid, &Float:angle) = GetVehicleZAngle;
#define _ALS_GetVehicleZAngle
#define GetVehicleZAngle( FIXES_GetVehicleZAngle(

#if defined _ALS_GetVehicleRotationQuat
	#error _ALS_GetVehicleRotationQuat defined
#endif
native BAD_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
native FIXES_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
native GetVehicleRotationQuat__(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
#define _ALS_GetVehicleRotationQuat
#define GetVehicleRotationQuat( FIXES_GetVehicleRotationQuat(

#if defined _ALS_GetVehicleDistanceFromPoint
	#error _ALS_GetVehicleDistanceFromPoint defined
#endif
native Float:BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
native Float:FIXES_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
native Float:GetVehicleDistanceFromPoint__(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#define _ALS_GetVehicleDistanceFromPoint
#define GetVehicleDistanceFromPoint( FIXES_GetVehicleDistanceFromPoint(

#if defined _ALS_SetVehicleZAngle
	#error _ALS_SetVehicleZAngle defined
#endif
native BAD_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
native FIXES_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
native SetVehicleZAngle__(vehicleid, Float:angle) = SetVehicleZAngle;
#define _ALS_SetVehicleZAngle
#define SetVehicleZAngle( FIXES_SetVehicleZAngle(

#if defined _ALS_SetVehicleParamsForPlayer
	#error _ALS_SetVehicleParamsForPlayer defined
#endif
native BAD_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
native FIXES_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
native SetVehicleParamsForPlayer__(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
#define _ALS_SetVehicleParamsForPlayer
#define SetVehicleParamsForPlayer( FIXES_SetVehicleParamsForPlayer(

#if defined _ALS_ManualVehicleEngineAndLights
	#error _ALS_ManualVehicleEngineAndLights defined
#endif
native BAD_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
native FIXES_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
native ManualVehicleEngineAndLights__() = ManualVehicleEngineAndLights;
#define _ALS_ManualVehicleEngineAndLights
#define ManualVehicleEngineAndLights( FIXES_ManualVehicleEngineAndLights(

#if defined _ALS_SetVehicleParamsEx
	#error _ALS_SetVehicleParamsEx defined
#endif
native BAD_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
native FIXES_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
native SetVehicleParamsEx__(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
#define _ALS_SetVehicleParamsEx
#define SetVehicleParamsEx( FIXES_SetVehicleParamsEx(

#if defined _ALS_GetVehicleParamsEx
	#error _ALS_GetVehicleParamsEx defined
#endif
native BAD_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
native FIXES_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
native GetVehicleParamsEx__(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
#define _ALS_GetVehicleParamsEx
#define GetVehicleParamsEx( FIXES_GetVehicleParamsEx(

#if defined _ALS_GetVehicleParamsSirenState
	#error _ALS_GetVehicleParamsSirenState defined
#endif
native BAD_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
native FIXES_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
native GetVehicleParamsSirenState__(vehicleid) = GetVehicleParamsSirenState;
#define _ALS_GetVehicleParamsSirenState
#define GetVehicleParamsSirenState( FIXES_GetVehicleParamsSirenState(

#if defined _ALS_SetVehicleParamsCarDoors
	#error _ALS_SetVehicleParamsCarDoors defined
#endif
native BAD_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
native FIXES_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
native SetVehicleParamsCarDoors__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
#define _ALS_SetVehicleParamsCarDoors
#define SetVehicleParamsCarDoors( FIXES_SetVehicleParamsCarDoors(

#if defined _ALS_GetVehicleParamsCarDoors
	#error _ALS_GetVehicleParamsCarDoors defined
#endif
native BAD_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
native FIXES_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
native GetVehicleParamsCarDoors__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
#define _ALS_GetVehicleParamsCarDoors
#define GetVehicleParamsCarDoors( FIXES_GetVehicleParamsCarDoors(

#if defined _ALS_SetVehicleParamsCarWindows
	#error _ALS_SetVehicleParamsCarWindows defined
#endif
native BAD_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
native FIXES_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
native SetVehicleParamsCarWindows__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
#define _ALS_SetVehicleParamsCarWindows
#define SetVehicleParamsCarWindows( FIXES_SetVehicleParamsCarWindows(

#if defined _ALS_GetVehicleParamsCarWindows
	#error _ALS_GetVehicleParamsCarWindows defined
#endif
native BAD_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
native FIXES_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
native GetVehicleParamsCarWindows__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
#define _ALS_GetVehicleParamsCarWindows
#define GetVehicleParamsCarWindows( FIXES_GetVehicleParamsCarWindows(

#if defined _ALS_SetVehicleToRespawn
	#error _ALS_SetVehicleToRespawn defined
#endif
native BAD_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
native FIXES_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
native SetVehicleToRespawn__(vehicleid) = SetVehicleToRespawn;
#define _ALS_SetVehicleToRespawn
#define SetVehicleToRespawn( FIXES_SetVehicleToRespawn(

#if defined _ALS_LinkVehicleToInterior
	#error _ALS_LinkVehicleToInterior defined
#endif
native BAD_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
native FIXES_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
native LinkVehicleToInterior__(vehicleid, interiorid) = LinkVehicleToInterior;
#define _ALS_LinkVehicleToInterior
#define LinkVehicleToInterior( FIXES_LinkVehicleToInterior(

#if defined _ALS_AddVehicleComponent
	#error _ALS_AddVehicleComponent defined
#endif
native BAD_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
native FIXES_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
native AddVehicleComponent__(vehicleid, componentid) = AddVehicleComponent;
#define _ALS_AddVehicleComponent
#define AddVehicleComponent( FIXES_AddVehicleComponent(

#if defined _ALS_RemoveVehicleComponent
	#error _ALS_RemoveVehicleComponent defined
#endif
native BAD_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
native FIXES_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
native RemoveVehicleComponent__(vehicleid, componentid) = RemoveVehicleComponent;
#define _ALS_RemoveVehicleComponent
#define RemoveVehicleComponent( FIXES_RemoveVehicleComponent(

#if defined _ALS_ChangeVehicleColor
	#error _ALS_ChangeVehicleColor defined
#endif
native BAD_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
native FIXES_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
native ChangeVehicleColor__(vehicleid, colour1, colour2) = ChangeVehicleColor;
#define _ALS_ChangeVehicleColor
#define ChangeVehicleColor( FIXES_ChangeVehicleColor(

#if defined _ALS_ChangeVehiclePaintjob
	#error _ALS_ChangeVehiclePaintjob defined
#endif
native BAD_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
native FIXES_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
native ChangeVehiclePaintjob__(vehicleid, paintjobid) = ChangeVehiclePaintjob;
#define _ALS_ChangeVehiclePaintjob
#define ChangeVehiclePaintjob( FIXES_ChangeVehiclePaintjob(

#if defined _ALS_SetVehicleHealth
	#error _ALS_SetVehicleHealth defined
#endif
native BAD_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
native FIXES_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
native SetVehicleHealth__(vehicleid, Float:health) = SetVehicleHealth;
#define _ALS_SetVehicleHealth
#define SetVehicleHealth( FIXES_SetVehicleHealth(

#if defined _ALS_GetVehicleHealth
	#error _ALS_GetVehicleHealth defined
#endif
native BAD_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
native FIXES_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
native GetVehicleHealth__(vehicleid, &Float:health) = GetVehicleHealth;
#define _ALS_GetVehicleHealth
#define GetVehicleHealth( FIXES_GetVehicleHealth(

#if defined _ALS_AttachTrailerToVehicle
	#error _ALS_AttachTrailerToVehicle defined
#endif
native BAD_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
native FIXES_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
native AttachTrailerToVehicle__(trailerid, vehicleid) = AttachTrailerToVehicle;
#define _ALS_AttachTrailerToVehicle
#define AttachTrailerToVehicle( FIXES_AttachTrailerToVehicle(

#if defined _ALS_DetachTrailerFromVehicle
	#error _ALS_DetachTrailerFromVehicle defined
#endif
native BAD_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
native FIXES_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
native DetachTrailerFromVehicle__(vehicleid) = DetachTrailerFromVehicle;
#define _ALS_DetachTrailerFromVehicle
#define DetachTrailerFromVehicle( FIXES_DetachTrailerFromVehicle(

#if defined _ALS_IsTrailerAttachedToVehicle
	#error _ALS_IsTrailerAttachedToVehicle defined
#endif
native BAD_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
native _FIXES_MAYBE_BOOL:FIXES_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
native bool:IsTrailerAttachedToVehicle__(vehicleid) = IsTrailerAttachedToVehicle;
#define _ALS_IsTrailerAttachedToVehicle
#define IsTrailerAttachedToVehicle( FIXES_IsTrailerAttachedToVehicle(

#if defined _ALS_GetVehicleTrailer
	#error _ALS_GetVehicleTrailer defined
#endif
native BAD_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
native FIXES_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
native GetVehicleTrailer__(vehicleid) = GetVehicleTrailer;
#define _ALS_GetVehicleTrailer
#define GetVehicleTrailer( FIXES_GetVehicleTrailer(

#if defined _ALS_SetVehicleNumberPlate
	#error _ALS_SetVehicleNumberPlate defined
#endif
native BAD_SetVehicleNumberPlate(vehicleid, numberPlate[]) = SetVehicleNumberPlate;
native FIXES_SetVehicleNumberPlate(vehicleid, _FIXES_MAYBE_CONST numberPlate[]) = SetVehicleNumberPlate;
native SetVehicleNumberPlate__(vehicleid, const numberPlate[]) = SetVehicleNumberPlate;
#define _ALS_SetVehicleNumberPlate
#define SetVehicleNumberPlate( FIXES_SetVehicleNumberPlate(

#if defined _ALS_GetVehicleModel
	#error _ALS_GetVehicleModel defined
#endif
native BAD_GetVehicleModel(vehicleid) = GetVehicleModel;
native FIXES_GetVehicleModel(vehicleid) = GetVehicleModel;
native GetVehicleModel__(vehicleid) = GetVehicleModel;
#define _ALS_GetVehicleModel
#define GetVehicleModel( FIXES_GetVehicleModel(

#if defined _ALS_GetVehicleComponentInSlot
	#error _ALS_GetVehicleComponentInSlot defined
#endif
native BAD_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
native FIXES_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
native GetVehicleComponentInSlot__(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
#define _ALS_GetVehicleComponentInSlot
#define GetVehicleComponentInSlot( FIXES_GetVehicleComponentInSlot(

#if defined _ALS_GetVehicleComponentType
	#error _ALS_GetVehicleComponentType defined
#endif
native CARMODTYPE:BAD_GetVehicleComponentType(component) = GetVehicleComponentType;
native CARMODTYPE:FIXES_GetVehicleComponentType(component) = GetVehicleComponentType;
native CARMODTYPE:GetVehicleComponentType__(component) = GetVehicleComponentType;
#define _ALS_GetVehicleComponentType
#define GetVehicleComponentType( FIXES_GetVehicleComponentType(

#if defined _ALS_RepairVehicle
	#error _ALS_RepairVehicle defined
#endif
native BAD_RepairVehicle(vehicleid) = RepairVehicle;
native FIXES_RepairVehicle(vehicleid) = RepairVehicle;
native RepairVehicle__(vehicleid) = RepairVehicle;
#define _ALS_RepairVehicle
#define RepairVehicle( FIXES_RepairVehicle(

#if defined _ALS_GetVehicleVelocity
	#error _ALS_GetVehicleVelocity defined
#endif
native BAD_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
native FIXES_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
native GetVehicleVelocity__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
#define _ALS_GetVehicleVelocity
#define GetVehicleVelocity( FIXES_GetVehicleVelocity(

#if defined _ALS_SetVehicleVelocity
	#error _ALS_SetVehicleVelocity defined
#endif
native BAD_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
native FIXES_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
native SetVehicleVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
#define _ALS_SetVehicleVelocity
#define SetVehicleVelocity( FIXES_SetVehicleVelocity(

#if defined _ALS_SetVehicleAngularVelocity
	#error _ALS_SetVehicleAngularVelocity defined
#endif
native BAD_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
native FIXES_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
native SetVehicleAngularVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
#define _ALS_SetVehicleAngularVelocity
#define SetVehicleAngularVelocity( FIXES_SetVehicleAngularVelocity(

#if defined _ALS_GetVehicleDamageStatus
	#error _ALS_GetVehicleDamageStatus defined
#endif
native BAD_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
native FIXES_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
native GetVehicleDamageStatus__(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
#define _ALS_GetVehicleDamageStatus
#define GetVehicleDamageStatus( FIXES_GetVehicleDamageStatus(

#if defined _ALS_UpdateVehicleDamageStatus
	#error _ALS_UpdateVehicleDamageStatus defined
#endif
native BAD_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
native FIXES_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
native UpdateVehicleDamageStatus__(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
#define _ALS_UpdateVehicleDamageStatus
#define UpdateVehicleDamageStatus( FIXES_UpdateVehicleDamageStatus(

#if defined _ALS_GetVehicleModelInfo
	#error _ALS_GetVehicleModelInfo defined
#endif
native BAD_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
native FIXES_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
native GetVehicleModelInfo__(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
#define _ALS_GetVehicleModelInfo
#define GetVehicleModelInfo( FIXES_GetVehicleModelInfo(

#if defined _ALS_SetVehicleVirtualWorld
	#error _ALS_SetVehicleVirtualWorld defined
#endif
native BAD_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
native FIXES_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
native SetVehicleVirtualWorld__(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
#define _ALS_SetVehicleVirtualWorld
#define SetVehicleVirtualWorld( FIXES_SetVehicleVirtualWorld(

#if defined _ALS_GetVehicleVirtualWorld
	#error _ALS_GetVehicleVirtualWorld defined
#endif
native BAD_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
native FIXES_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
native GetVehicleVirtualWorld__(vehicleid) = GetVehicleVirtualWorld;
#define _ALS_GetVehicleVirtualWorld
#define GetVehicleVirtualWorld( FIXES_GetVehicleVirtualWorld(

#if defined _ALS_IsValidVehicle
	#error _ALS_IsValidVehicle defined
#endif
native BAD_IsValidVehicle(vehicleid) = IsValidVehicle;
native _FIXES_MAYBE_BOOL:FIXES_IsValidVehicle(vehicleid) = IsValidVehicle;
native bool:IsValidVehicle__(vehicleid) = IsValidVehicle;
#define _ALS_IsValidVehicle
#define IsValidVehicle( FIXES_IsValidVehicle(

