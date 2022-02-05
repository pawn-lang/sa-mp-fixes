/*

     █████           █████   ██████ ████████  ██████  ██████
    ██   ██         ██   ██ ██         ██    ██    ██ ██   ██
    ███████         ███████ ██         ██    ██    ██ ██████
    ██   ██         ██   ██ ██         ██    ██    ██ ██   ██
    ██   ██ ███████ ██   ██  ██████    ██     ██████  ██   ██

*/

#if defined _ALS_CreateActor
	#error _ALS_CreateActor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreateActor__(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
#define _ALS_CreateActor
#define CreateActor( FIXES_CreateActor(

#if defined _ALS_DestroyActor
	#error _ALS_DestroyActor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyActor(actorid) = DestroyActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyActor(actorid) = DestroyActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyActor__(actorid) = DestroyActor;
#define _ALS_DestroyActor
#define DestroyActor( FIXES_DestroyActor(

#if defined _ALS_IsActorStreamedIn
	#error _ALS_IsActorStreamedIn defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsActorStreamedIn__(actorid, playerid) = IsActorStreamedIn;
#define _ALS_IsActorStreamedIn
#define IsActorStreamedIn( FIXES_IsActorStreamedIn(

#if defined _ALS_SetActorVirtualWorld
	#error _ALS_SetActorVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetActorVirtualWorld__(actorid, virtualWorld) = SetActorVirtualWorld;
#define _ALS_SetActorVirtualWorld
#define SetActorVirtualWorld( FIXES_SetActorVirtualWorld(

#if defined _ALS_GetActorVirtualWorld
	#error _ALS_GetActorVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetActorVirtualWorld__(actorid) = GetActorVirtualWorld;
#define _ALS_GetActorVirtualWorld
#define GetActorVirtualWorld( FIXES_GetActorVirtualWorld(

#if defined _ALS_ApplyActorAnimation
	#error _ALS_ApplyActorAnimation defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ApplyActorAnimation(actorid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time) = ApplyActorAnimation;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ApplyActorAnimation(actorid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time) = ApplyActorAnimation;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ApplyActorAnimation__(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time) = ApplyActorAnimation;
#define _ALS_ApplyActorAnimation
#define ApplyActorAnimation( FIXES_ApplyActorAnimation(

#if defined _ALS_ClearActorAnimations
	#error _ALS_ClearActorAnimations defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ClearActorAnimations(actorid) = ClearActorAnimations;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ClearActorAnimations(actorid) = ClearActorAnimations;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ClearActorAnimations__(actorid) = ClearActorAnimations;
#define _ALS_ClearActorAnimations
#define ClearActorAnimations( FIXES_ClearActorAnimations(

#if defined _ALS_SetActorPos
	#error _ALS_SetActorPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetActorPos__(actorid, Float:x, Float:y, Float:z) = SetActorPos;
#define _ALS_SetActorPos
#define SetActorPos( FIXES_SetActorPos(

#if defined _ALS_GetActorPos
	#error _ALS_GetActorPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetActorPos__(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
#define _ALS_GetActorPos
#define GetActorPos( FIXES_GetActorPos(

#if defined _ALS_SetActorFacingAngle
	#error _ALS_SetActorFacingAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetActorFacingAngle__(actorid, Float:angle) = SetActorFacingAngle;
#define _ALS_SetActorFacingAngle
#define SetActorFacingAngle( FIXES_SetActorFacingAngle(

#if defined _ALS_GetActorFacingAngle
	#error _ALS_GetActorFacingAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetActorFacingAngle__(actorid, &Float:angle) = GetActorFacingAngle;
#define _ALS_GetActorFacingAngle
#define GetActorFacingAngle( FIXES_GetActorFacingAngle(

#if defined _ALS_SetActorHealth
	#error _ALS_SetActorHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetActorHealth(actorid, Float:health) = SetActorHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetActorHealth(actorid, Float:health) = SetActorHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetActorHealth__(actorid, Float:health) = SetActorHealth;
#define _ALS_SetActorHealth
#define SetActorHealth( FIXES_SetActorHealth(

#if defined _ALS_GetActorHealth
	#error _ALS_GetActorHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetActorHealth(actorid, &Float:health) = GetActorHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetActorHealth(actorid, &Float:health) = GetActorHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetActorHealth__(actorid, &Float:health) = GetActorHealth;
#define _ALS_GetActorHealth
#define GetActorHealth( FIXES_GetActorHealth(

#if defined _ALS_SetActorInvulnerable
	#error _ALS_SetActorInvulnerable defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetActorInvulnerable(actorid, invulnerable = true) = SetActorInvulnerable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetActorInvulnerable(actorid, _FIXES_MAYBE_BOOL:invulnerable = true) = SetActorInvulnerable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetActorInvulnerable__(actorid, bool:invulnerable = true) = SetActorInvulnerable;
#define _ALS_SetActorInvulnerable
#define SetActorInvulnerable( FIXES_SetActorInvulnerable(

#if defined _ALS_IsActorInvulnerable
	#error _ALS_IsActorInvulnerable defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsActorInvulnerable(actorid) = IsActorInvulnerable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsActorInvulnerable(actorid) = IsActorInvulnerable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsActorInvulnerable__(actorid) = IsActorInvulnerable;
#define _ALS_IsActorInvulnerable
#define IsActorInvulnerable( FIXES_IsActorInvulnerable(

#if defined _ALS_IsValidActor
	#error _ALS_IsValidActor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsValidActor(actorid) = IsValidActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsValidActor(actorid) = IsValidActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsValidActor__(actorid) = IsValidActor;
#define _ALS_IsValidActor
#define IsValidActor( FIXES_IsValidActor(

/*

     █████          ██   ██ ████████ ████████ ██████
    ██   ██         ██   ██    ██       ██    ██   ██
    ███████         ███████    ██       ██    ██████
    ██   ██         ██   ██    ██       ██    ██
    ██   ██ ███████ ██   ██    ██       ██    ██

*/

#if defined _ALS_HTTP
	#error _ALS_HTTP defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_HTTP(index, HTTP_METHOD:method, url[], data[], callback[]) = HTTP;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_HTTP(index, HTTP_METHOD:method, _FIXES_MAYBE_CONST url[], _FIXES_MAYBE_CONST data[], _FIXES_MAYBE_CONST callback[]) = HTTP;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native HTTP__(index, HTTP_METHOD:method, const url[], const data[], const callback[]) = HTTP;
#define _ALS_HTTP
#define HTTP( FIXES_HTTP(

/*


     █████           ██████  ██████       ██ ███████  ██████ ████████ ███████
    ██   ██         ██    ██ ██   ██      ██ ██      ██         ██    ██
    ███████         ██    ██ ██████       ██ █████   ██         ██    ███████
    ██   ██         ██    ██ ██   ██ ██   ██ ██      ██         ██         ██
    ██   ██ ███████  ██████  ██████   █████  ███████  ██████    ██    ███████

*/

#if defined _ALS_CreateObject
	#error _ALS_CreateObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreateObject__(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
#define _ALS_CreateObject
#define CreateObject( FIXES_CreateObject(

#if defined _ALS_AttachObjectToVehicle
	#error _ALS_AttachObjectToVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachObjectToVehicle__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
#define _ALS_AttachObjectToVehicle
#define AttachObjectToVehicle( FIXES_AttachObjectToVehicle(

#if defined _ALS_AttachObjectToObject
	#error _ALS_AttachObjectToObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, syncRotation = true) = AttachObjectToObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, _FIXES_MAYBE_BOOL:syncRotation = true) = AttachObjectToObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachObjectToObject__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, bool:syncRotation = true) = AttachObjectToObject;
#define _ALS_AttachObjectToObject
#define AttachObjectToObject( FIXES_AttachObjectToObject(

#if defined _ALS_AttachObjectToPlayer
	#error _ALS_AttachObjectToPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachObjectToPlayer__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
#define _ALS_AttachObjectToPlayer
#define AttachObjectToPlayer( FIXES_AttachObjectToPlayer(

#if defined _ALS_SetObjectPos
	#error _ALS_SetObjectPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectPos__(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
#define _ALS_SetObjectPos
#define SetObjectPos( FIXES_SetObjectPos(

#if defined _ALS_GetObjectPos
	#error _ALS_GetObjectPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetObjectPos__(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
#define _ALS_GetObjectPos
#define GetObjectPos( FIXES_GetObjectPos(

#if defined _ALS_SetObjectRot
	#error _ALS_SetObjectRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectRot__(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
#define _ALS_SetObjectRot
#define SetObjectRot( FIXES_SetObjectRot(

#if defined _ALS_GetObjectRot
	#error _ALS_GetObjectRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetObjectRot__(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
#define _ALS_GetObjectRot
#define GetObjectRot( FIXES_GetObjectRot(

#if defined _ALS_GetObjectModel
	#error _ALS_GetObjectModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetObjectModel(objectid) = GetObjectModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetObjectModel(objectid) = GetObjectModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetObjectModel__(objectid) = GetObjectModel;
#define _ALS_GetObjectModel
#define GetObjectModel( FIXES_GetObjectModel(

#if defined _ALS_SetObjectNoCameraCol
	#error _ALS_SetObjectNoCameraCol defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectNoCameraCol__(objectid) = SetObjectNoCameraCol;
#define _ALS_SetObjectNoCameraCol
#define SetObjectNoCameraCol( FIXES_SetObjectNoCameraCol(

#if defined _ALS_IsValidObject
	#error _ALS_IsValidObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsValidObject(objectid) = IsValidObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsValidObject(objectid) = IsValidObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsValidObject__(objectid) = IsValidObject;
#define _ALS_IsValidObject
#define IsValidObject( FIXES_IsValidObject(

#if defined _ALS_DestroyObject
	#error _ALS_DestroyObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyObject(objectid) = DestroyObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyObject(objectid) = DestroyObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyObject__(objectid) = DestroyObject;
#define _ALS_DestroyObject
#define DestroyObject( FIXES_DestroyObject(

#if defined _ALS_MoveObject
	#error _ALS_MoveObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native MoveObject__(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
#define _ALS_MoveObject
#define MoveObject( FIXES_MoveObject(

#if defined _ALS_StopObject
	#error _ALS_StopObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_StopObject(objectid) = StopObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_StopObject(objectid) = StopObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native StopObject__(objectid) = StopObject;
#define _ALS_StopObject
#define StopObject( FIXES_StopObject(

#if defined _ALS_IsObjectMoving
	#error _ALS_IsObjectMoving defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsObjectMoving(objectid) = IsObjectMoving;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsObjectMoving(objectid) = IsObjectMoving;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsObjectMoving__(objectid) = IsObjectMoving;
#define _ALS_IsObjectMoving
#define IsObjectMoving( FIXES_IsObjectMoving(

#if defined _ALS_EditObject
	#error _ALS_EditObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EditObject(playerid, objectid) = EditObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EditObject(playerid, objectid) = EditObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EditObject__(playerid, objectid) = EditObject;
#define _ALS_EditObject
#define EditObject( FIXES_EditObject(

#if defined _ALS_EditPlayerObject
	#error _ALS_EditPlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EditPlayerObject(playerid, objectid) = EditPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EditPlayerObject(playerid, objectid) = EditPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EditPlayerObject__(playerid, objectid) = EditPlayerObject;
#define _ALS_EditPlayerObject
#define EditPlayerObject( FIXES_EditPlayerObject(

#if defined _ALS_SelectObject
	#error _ALS_SelectObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SelectObject(playerid) = SelectObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SelectObject(playerid) = SelectObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SelectObject__(playerid) = SelectObject;
#define _ALS_SelectObject
#define SelectObject( FIXES_SelectObject(

#if defined _ALS_CancelEdit
	#error _ALS_CancelEdit defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CancelEdit(playerid) = CancelEdit;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CancelEdit(playerid) = CancelEdit;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CancelEdit__(playerid) = CancelEdit;
#define _ALS_CancelEdit
#define CancelEdit( FIXES_CancelEdit(

#if defined _ALS_CreatePlayerObject
	#error _ALS_CreatePlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreatePlayerObject__(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
#define _ALS_CreatePlayerObject
#define CreatePlayerObject( FIXES_CreatePlayerObject(

#if defined _ALS_AttachPlayerObjectToVehicle
	#error _ALS_AttachPlayerObjectToVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachPlayerObjectToVehicle__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
#define _ALS_AttachPlayerObjectToVehicle
#define AttachPlayerObjectToVehicle( FIXES_AttachPlayerObjectToVehicle(

#if defined _ALS_SetPlayerObjectPos
	#error _ALS_SetPlayerObjectPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerObjectPos__(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
#define _ALS_SetPlayerObjectPos
#define SetPlayerObjectPos( FIXES_SetPlayerObjectPos(

#if defined _ALS_GetPlayerObjectPos
	#error _ALS_GetPlayerObjectPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerObjectPos__(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
#define _ALS_GetPlayerObjectPos
#define GetPlayerObjectPos( FIXES_GetPlayerObjectPos(

#if defined _ALS_SetPlayerObjectRot
	#error _ALS_SetPlayerObjectRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerObjectRot__(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
#define _ALS_SetPlayerObjectRot
#define SetPlayerObjectRot( FIXES_SetPlayerObjectRot(

#if defined _ALS_GetPlayerObjectRot
	#error _ALS_GetPlayerObjectRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerObjectRot__(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
#define _ALS_GetPlayerObjectRot
#define GetPlayerObjectRot( FIXES_GetPlayerObjectRot(

#if defined _ALS_GetPlayerObjectModel
	#error _ALS_GetPlayerObjectModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerObjectModel__(playerid, objectid) = GetPlayerObjectModel;
#define _ALS_GetPlayerObjectModel
#define GetPlayerObjectModel( FIXES_GetPlayerObjectModel(

#if defined _ALS_SetPlayerObjectNoCameraCol
	#error _ALS_SetPlayerObjectNoCameraCol defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerObjectNoCameraCol__(playerid, objectid) = SetPlayerObjectNoCameraCol;
#define _ALS_SetPlayerObjectNoCameraCol
#define SetPlayerObjectNoCameraCol( FIXES_SetPlayerObjectNoCameraCol(

#if defined _ALS_IsValidPlayerObject
	#error _ALS_IsValidPlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsValidPlayerObject__(playerid, objectid) = IsValidPlayerObject;
#define _ALS_IsValidPlayerObject
#define IsValidPlayerObject( FIXES_IsValidPlayerObject(

#if defined _ALS_DestroyPlayerObject
	#error _ALS_DestroyPlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyPlayerObject__(playerid, objectid) = DestroyPlayerObject;
#define _ALS_DestroyPlayerObject
#define DestroyPlayerObject( FIXES_DestroyPlayerObject(

#if defined _ALS_MovePlayerObject
	#error _ALS_MovePlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native MovePlayerObject__(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
#define _ALS_MovePlayerObject
#define MovePlayerObject( FIXES_MovePlayerObject(

#if defined _ALS_StopPlayerObject
	#error _ALS_StopPlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_StopPlayerObject(playerid, objectid) = StopPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_StopPlayerObject(playerid, objectid) = StopPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native StopPlayerObject__(playerid, objectid) = StopPlayerObject;
#define _ALS_StopPlayerObject
#define StopPlayerObject( FIXES_StopPlayerObject(

#if defined _ALS_IsPlayerObjectMoving
	#error _ALS_IsPlayerObjectMoving defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerObjectMoving__(playerid, objectid) = IsPlayerObjectMoving;
#define _ALS_IsPlayerObjectMoving
#define IsPlayerObjectMoving( FIXES_IsPlayerObjectMoving(

#if defined _ALS_AttachPlayerObjectToPlayer
	#error _ALS_AttachPlayerObjectToPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachPlayerObjectToPlayer__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
#define _ALS_AttachPlayerObjectToPlayer
#define AttachPlayerObjectToPlayer( FIXES_AttachPlayerObjectToPlayer(

#if defined _ALS_SetObjectMaterial
	#error _ALS_SetObjectMaterial defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectMaterial(objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetObjectMaterial;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectMaterial(objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetObjectMaterial;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectMaterial__(objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetObjectMaterial;
#define _ALS_SetObjectMaterial
#define SetObjectMaterial( FIXES_SetObjectMaterial(

#if defined _ALS_SetPlayerObjectMaterial
	#error _ALS_SetPlayerObjectMaterial defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetPlayerObjectMaterial;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetPlayerObjectMaterial;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerObjectMaterial__(playerid, objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetPlayerObjectMaterial;
#define _ALS_SetPlayerObjectMaterial
#define SetPlayerObjectMaterial( FIXES_SetPlayerObjectMaterial(

#if defined _ALS_SetObjectMaterialText
	#error _ALS_SetObjectMaterialText defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectMaterialText(objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectMaterialText(objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectMaterialText__(objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
#define _ALS_SetObjectMaterialText
#define SetObjectMaterialText( FIXES_SetObjectMaterialText(

#if defined _ALS_SetPlayerObjectMaterialText
	#error _ALS_SetPlayerObjectMaterialText defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerObjectMaterialText(playerid, objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerObjectMaterialText(playerid, objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerObjectMaterialText__(playerid, objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
#define _ALS_SetPlayerObjectMaterialText
#define SetPlayerObjectMaterialText( FIXES_SetPlayerObjectMaterialText(

#if defined _ALS_SetObjectsDefaultCameraCol
	#error _ALS_SetObjectsDefaultCameraCol defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetObjectsDefaultCameraCol(disable) = SetObjectsDefaultCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetObjectsDefaultCameraCol(_FIXES_MAYBE_BOOL:disable) = SetObjectsDefaultCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetObjectsDefaultCameraCol__(bool:disable) = SetObjectsDefaultCameraCol;
#define _ALS_SetObjectsDefaultCameraCol
#define SetObjectsDefaultCameraCol( FIXES_SetObjectsDefaultCameraCol(

/*

     █████          ██████  ██       █████  ██    ██ ███████ ██████  ███████
    ██   ██         ██   ██ ██      ██   ██  ██  ██  ██      ██   ██ ██
    ███████         ██████  ██      ███████   ████   █████   ██████  ███████
    ██   ██         ██      ██      ██   ██    ██    ██      ██   ██      ██
    ██   ██ ███████ ██      ███████ ██   ██    ██    ███████ ██   ██ ███████

*/

#if defined _ALS_SetSpawnInfo
	#error _ALS_SetSpawnInfo defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetSpawnInfo__(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
#define _ALS_SetSpawnInfo
#define SetSpawnInfo( FIXES_SetSpawnInfo(

#if defined _ALS_SpawnPlayer
	#error _ALS_SpawnPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SpawnPlayer(playerid) = SpawnPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SpawnPlayer(playerid) = SpawnPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SpawnPlayer__(playerid) = SpawnPlayer;
#define _ALS_SpawnPlayer
#define SpawnPlayer( FIXES_SpawnPlayer(

#if defined _ALS_SetPlayerPos
	#error _ALS_SetPlayerPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
#define _ALS_SetPlayerPos
#define SetPlayerPos( FIXES_SetPlayerPos(

#if defined _ALS_SetPlayerPosFindZ
	#error _ALS_SetPlayerPosFindZ defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerPosFindZ__(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
#define _ALS_SetPlayerPosFindZ
#define SetPlayerPosFindZ( FIXES_SetPlayerPosFindZ(

#if defined _ALS_GetPlayerPos
	#error _ALS_GetPlayerPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
#define _ALS_GetPlayerPos
#define GetPlayerPos( FIXES_GetPlayerPos(

#if defined _ALS_SetPlayerFacingAngle
	#error _ALS_SetPlayerFacingAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerFacingAngle__(playerid, Float:ang) = SetPlayerFacingAngle;
#define _ALS_SetPlayerFacingAngle
#define SetPlayerFacingAngle( FIXES_SetPlayerFacingAngle(

#if defined _ALS_GetPlayerFacingAngle
	#error _ALS_GetPlayerFacingAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerFacingAngle__(playerid, &Float:ang) = GetPlayerFacingAngle;
#define _ALS_GetPlayerFacingAngle
#define GetPlayerFacingAngle( FIXES_GetPlayerFacingAngle(

#if defined _ALS_IsPlayerInRangeOfPoint
	#error _ALS_IsPlayerInRangeOfPoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerInRangeOfPoint__(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
#define _ALS_IsPlayerInRangeOfPoint
#define IsPlayerInRangeOfPoint( FIXES_IsPlayerInRangeOfPoint(

#if defined _ALS_GetPlayerDistanceFromPoint
	#error _ALS_GetPlayerDistanceFromPoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetPlayerDistanceFromPoint__(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
#define _ALS_GetPlayerDistanceFromPoint
#define GetPlayerDistanceFromPoint( FIXES_GetPlayerDistanceFromPoint(

#if defined _ALS_IsPlayerStreamedIn
	#error _ALS_IsPlayerStreamedIn defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerStreamedIn__(targetid, playerid) = IsPlayerStreamedIn;
#define _ALS_IsPlayerStreamedIn
#define IsPlayerStreamedIn( FIXES_IsPlayerStreamedIn(

#if defined _ALS_SetPlayerInterior
	#error _ALS_SetPlayerInterior defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerInterior__(playerid, interiorid) = SetPlayerInterior;
#define _ALS_SetPlayerInterior
#define SetPlayerInterior( FIXES_SetPlayerInterior(

#if defined _ALS_GetPlayerInterior
	#error _ALS_GetPlayerInterior defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerInterior(playerid) = GetPlayerInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerInterior(playerid) = GetPlayerInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerInterior__(playerid) = GetPlayerInterior;
#define _ALS_GetPlayerInterior
#define GetPlayerInterior( FIXES_GetPlayerInterior(

#if defined _ALS_SetPlayerHealth
	#error _ALS_SetPlayerHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerHealth__(playerid, Float:health) = SetPlayerHealth;
#define _ALS_SetPlayerHealth
#define SetPlayerHealth( FIXES_SetPlayerHealth(

#if defined _ALS_GetPlayerHealth
	#error _ALS_GetPlayerHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerHealth__(playerid, &Float:health) = GetPlayerHealth;
#define _ALS_GetPlayerHealth
#define GetPlayerHealth( FIXES_GetPlayerHealth(

#if defined _ALS_SetPlayerArmour
	#error _ALS_SetPlayerArmour defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerArmour__(playerid, Float:armour) = SetPlayerArmour;
#define _ALS_SetPlayerArmour
#define SetPlayerArmour( FIXES_SetPlayerArmour(

#if defined _ALS_GetPlayerArmour
	#error _ALS_GetPlayerArmour defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerArmour__(playerid, &Float:armour) = GetPlayerArmour;
#define _ALS_GetPlayerArmour
#define GetPlayerArmour( FIXES_GetPlayerArmour(

#if defined _ALS_SetPlayerAmmo
	#error _ALS_SetPlayerAmmo defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerAmmo__(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
#define _ALS_SetPlayerAmmo
#define SetPlayerAmmo( FIXES_SetPlayerAmmo(

#if defined _ALS_GetPlayerAmmo
	#error _ALS_GetPlayerAmmo defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerAmmo(playerid) = GetPlayerAmmo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerAmmo(playerid) = GetPlayerAmmo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerAmmo__(playerid) = GetPlayerAmmo;
#define _ALS_GetPlayerAmmo
#define GetPlayerAmmo( FIXES_GetPlayerAmmo(

#if defined _ALS_GetPlayerWeaponState
	#error _ALS_GetPlayerWeaponState defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native WEAPONSTATE:BAD_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native WEAPONSTATE:FIXES_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native WEAPONSTATE:GetPlayerWeaponState__(playerid) = GetPlayerWeaponState;
#define _ALS_GetPlayerWeaponState
#define GetPlayerWeaponState( FIXES_GetPlayerWeaponState(

#if defined _ALS_GetPlayerTargetPlayer
	#error _ALS_GetPlayerTargetPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerTargetPlayer__(playerid) = GetPlayerTargetPlayer;
#define _ALS_GetPlayerTargetPlayer
#define GetPlayerTargetPlayer( FIXES_GetPlayerTargetPlayer(

#if defined _ALS_GetPlayerTargetActor
	#error _ALS_GetPlayerTargetActor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerTargetActor__(playerid) = GetPlayerTargetActor;
#define _ALS_GetPlayerTargetActor
#define GetPlayerTargetActor( FIXES_GetPlayerTargetActor(

#if defined _ALS_SetPlayerTeam
	#error _ALS_SetPlayerTeam defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerTeam__(playerid, teamid) = SetPlayerTeam;
#define _ALS_SetPlayerTeam
#define SetPlayerTeam( FIXES_SetPlayerTeam(

#if defined _ALS_GetPlayerTeam
	#error _ALS_GetPlayerTeam defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerTeam(playerid) = GetPlayerTeam;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerTeam(playerid) = GetPlayerTeam;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerTeam__(playerid) = GetPlayerTeam;
#define _ALS_GetPlayerTeam
#define GetPlayerTeam( FIXES_GetPlayerTeam(

#if defined _ALS_SetPlayerScore
	#error _ALS_SetPlayerScore defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerScore(playerid, score) = SetPlayerScore;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerScore(playerid, score) = SetPlayerScore;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerScore__(playerid, score) = SetPlayerScore;
#define _ALS_SetPlayerScore
#define SetPlayerScore( FIXES_SetPlayerScore(

#if defined _ALS_GetPlayerScore
	#error _ALS_GetPlayerScore defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerScore(playerid) = GetPlayerScore;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerScore(playerid) = GetPlayerScore;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerScore__(playerid) = GetPlayerScore;
#define _ALS_GetPlayerScore
#define GetPlayerScore( FIXES_GetPlayerScore(

#if defined _ALS_GetPlayerDrunkLevel
	#error _ALS_GetPlayerDrunkLevel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerDrunkLevel__(playerid) = GetPlayerDrunkLevel;
#define _ALS_GetPlayerDrunkLevel
#define GetPlayerDrunkLevel( FIXES_GetPlayerDrunkLevel(

#if defined _ALS_SetPlayerDrunkLevel
	#error _ALS_SetPlayerDrunkLevel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerDrunkLevel__(playerid, level) = SetPlayerDrunkLevel;
#define _ALS_SetPlayerDrunkLevel
#define SetPlayerDrunkLevel( FIXES_SetPlayerDrunkLevel(

#if defined _ALS_SetPlayerColor
	#error _ALS_SetPlayerColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerColor(playerid, colour) = SetPlayerColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerColor(playerid, colour) = SetPlayerColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerColor__(playerid, colour) = SetPlayerColor;
#define _ALS_SetPlayerColor
#define SetPlayerColor( FIXES_SetPlayerColor(

#if defined _ALS_GetPlayerColor
	#error _ALS_GetPlayerColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerColor(playerid) = GetPlayerColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerColor(playerid) = GetPlayerColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerColor__(playerid) = GetPlayerColor;
#define _ALS_GetPlayerColor
#define GetPlayerColor( FIXES_GetPlayerColor(

#if defined _ALS_SetPlayerSkin
	#error _ALS_SetPlayerSkin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerSkin__(playerid, skinid) = SetPlayerSkin;
#define _ALS_SetPlayerSkin
#define SetPlayerSkin( FIXES_SetPlayerSkin(

#if defined _ALS_GetPlayerSkin
	#error _ALS_GetPlayerSkin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerSkin(playerid) = GetPlayerSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerSkin(playerid) = GetPlayerSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerSkin__(playerid) = GetPlayerSkin;
#define _ALS_GetPlayerSkin
#define GetPlayerSkin( FIXES_GetPlayerSkin(

#if defined _ALS_GetPlayerCustomSkin
	#error _ALS_GetPlayerCustomSkin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCustomSkin__(playerid) = GetPlayerCustomSkin;
#define _ALS_GetPlayerCustomSkin
#define GetPlayerCustomSkin( FIXES_GetPlayerCustomSkin(

#if defined _ALS_GivePlayerWeapon
	#error _ALS_GivePlayerWeapon defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GivePlayerWeapon__(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
#define _ALS_GivePlayerWeapon
#define GivePlayerWeapon( FIXES_GivePlayerWeapon(

#if defined _ALS_ResetPlayerWeapons
	#error _ALS_ResetPlayerWeapons defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ResetPlayerWeapons__(playerid) = ResetPlayerWeapons;
#define _ALS_ResetPlayerWeapons
#define ResetPlayerWeapons( FIXES_ResetPlayerWeapons(

#if defined _ALS_SetPlayerArmedWeapon
	#error _ALS_SetPlayerArmedWeapon defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerArmedWeapon__(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
#define _ALS_SetPlayerArmedWeapon
#define SetPlayerArmedWeapon( FIXES_SetPlayerArmedWeapon(

#if defined _ALS_GetPlayerWeaponData
	#error _ALS_GetPlayerWeaponData defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerWeaponData__(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
#define _ALS_GetPlayerWeaponData
#define GetPlayerWeaponData( FIXES_GetPlayerWeaponData(

#if defined _ALS_GivePlayerMoney
	#error _ALS_GivePlayerMoney defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GivePlayerMoney(playerid, money) = GivePlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GivePlayerMoney(playerid, money) = GivePlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GivePlayerMoney__(playerid, money) = GivePlayerMoney;
#define _ALS_GivePlayerMoney
#define GivePlayerMoney( FIXES_GivePlayerMoney(

#if defined _ALS_ResetPlayerMoney
	#error _ALS_ResetPlayerMoney defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ResetPlayerMoney(playerid) = ResetPlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ResetPlayerMoney(playerid) = ResetPlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ResetPlayerMoney__(playerid) = ResetPlayerMoney;
#define _ALS_ResetPlayerMoney
#define ResetPlayerMoney( FIXES_ResetPlayerMoney(

#if defined _ALS_SetPlayerName
	#error _ALS_SetPlayerName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerName(playerid, name[]) = SetPlayerName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerName(playerid, _FIXES_MAYBE_CONST name[]) = SetPlayerName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerName__(playerid, const name[]) = SetPlayerName;
#define _ALS_SetPlayerName
#define SetPlayerName( FIXES_SetPlayerName(

#if defined _ALS_GetPlayerMoney
	#error _ALS_GetPlayerMoney defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerMoney(playerid) = GetPlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerMoney(playerid) = GetPlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerMoney__(playerid) = GetPlayerMoney;
#define _ALS_GetPlayerMoney
#define GetPlayerMoney( FIXES_GetPlayerMoney(

#if defined _ALS_GetPlayerState
	#error _ALS_GetPlayerState defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native PLAYER_STATE:BAD_GetPlayerState(playerid) = GetPlayerState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native PLAYER_STATE:FIXES_GetPlayerState(playerid) = GetPlayerState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PLAYER_STATE:GetPlayerState__(playerid) = GetPlayerState;
#define _ALS_GetPlayerState
#define GetPlayerState( FIXES_GetPlayerState(

#if defined _ALS_GetPlayerIp
	#error _ALS_GetPlayerIp defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerIp(playerid, ip[], len) = GetPlayerIp;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerIp(playerid, ip[], _FIXES_MAYBE_SIZEOF(len, ip)) = GetPlayerIp;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerIp__(playerid, ip[], len = sizeof (ip)) = GetPlayerIp;
#define _ALS_GetPlayerIp
#define GetPlayerIp( FIXES_GetPlayerIp(

#if defined _ALS_GetPlayerPing
	#error _ALS_GetPlayerPing defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerPing(playerid) = GetPlayerPing;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerPing(playerid) = GetPlayerPing;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerPing__(playerid) = GetPlayerPing;
#define _ALS_GetPlayerPing
#define GetPlayerPing( FIXES_GetPlayerPing(

#if defined _ALS_GetPlayerWeapon
	#error _ALS_GetPlayerWeapon defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native WEAPON:BAD_GetPlayerWeapon(playerid) = GetPlayerWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native WEAPON:FIXES_GetPlayerWeapon(playerid) = GetPlayerWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native WEAPON:GetPlayerWeapon__(playerid) = GetPlayerWeapon;
#define _ALS_GetPlayerWeapon
#define GetPlayerWeapon( FIXES_GetPlayerWeapon(

#if defined _ALS_GetPlayerKeys
	#error _ALS_GetPlayerKeys defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerKeys__(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
#define _ALS_GetPlayerKeys
#define GetPlayerKeys( FIXES_GetPlayerKeys(

#if defined _ALS_GetPlayerName
	#error _ALS_GetPlayerName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerName(playerid, const name[], len) = GetPlayerName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerName(playerid, _FIXES_NOT_CONST name[], _FIXES_MAYBE_SIZEOF(len, name)) = GetPlayerName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerName__(playerid, name[], len = sizeof (name)) = GetPlayerName;
#define _ALS_GetPlayerName
#define GetPlayerName( FIXES_GetPlayerName(

#if defined _ALS_SetPlayerTime
	#error _ALS_SetPlayerTime defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerTime__(playerid, hour, minute) = SetPlayerTime;
#define _ALS_SetPlayerTime
#define SetPlayerTime( FIXES_SetPlayerTime(

#if defined _ALS_GetPlayerTime
	#error _ALS_GetPlayerTime defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerTime__(playerid, &hour, &minute) = GetPlayerTime;
#define _ALS_GetPlayerTime
#define GetPlayerTime( FIXES_GetPlayerTime(

#if defined _ALS_TogglePlayerClock
	#error _ALS_TogglePlayerClock defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TogglePlayerClock(playerid, toggle) = TogglePlayerClock;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TogglePlayerClock(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerClock;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TogglePlayerClock__(playerid, bool:toggle) = TogglePlayerClock;
#define _ALS_TogglePlayerClock
#define TogglePlayerClock( FIXES_TogglePlayerClock(

#if defined _ALS_SetPlayerWeather
	#error _ALS_SetPlayerWeather defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerWeather__(playerid, weather) = SetPlayerWeather;
#define _ALS_SetPlayerWeather
#define SetPlayerWeather( FIXES_SetPlayerWeather(

#if defined _ALS_ForceClassSelection
	#error _ALS_ForceClassSelection defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ForceClassSelection(playerid) = ForceClassSelection;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ForceClassSelection(playerid) = ForceClassSelection;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ForceClassSelection__(playerid) = ForceClassSelection;
#define _ALS_ForceClassSelection
#define ForceClassSelection( FIXES_ForceClassSelection(

#if defined _ALS_SetPlayerWantedLevel
	#error _ALS_SetPlayerWantedLevel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerWantedLevel__(playerid, level) = SetPlayerWantedLevel;
#define _ALS_SetPlayerWantedLevel
#define SetPlayerWantedLevel( FIXES_SetPlayerWantedLevel(

#if defined _ALS_GetPlayerWantedLevel
	#error _ALS_GetPlayerWantedLevel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerWantedLevel__(playerid) = GetPlayerWantedLevel;
#define _ALS_GetPlayerWantedLevel
#define GetPlayerWantedLevel( FIXES_GetPlayerWantedLevel(

#if defined _ALS_SetPlayerFightingStyle
	#error _ALS_SetPlayerFightingStyle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerFightingStyle__(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
#define _ALS_SetPlayerFightingStyle
#define SetPlayerFightingStyle( FIXES_SetPlayerFightingStyle(

#if defined _ALS_GetPlayerFightingStyle
	#error _ALS_GetPlayerFightingStyle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native FIGHT_STYLE:BAD_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIGHT_STYLE:FIXES_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native FIGHT_STYLE:GetPlayerFightingStyle__(playerid) = GetPlayerFightingStyle;
#define _ALS_GetPlayerFightingStyle
#define GetPlayerFightingStyle( FIXES_GetPlayerFightingStyle(

#if defined _ALS_SetPlayerVelocity
	#error _ALS_SetPlayerVelocity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerVelocity__(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
#define _ALS_SetPlayerVelocity
#define SetPlayerVelocity( FIXES_SetPlayerVelocity(

#if defined _ALS_GetPlayerVelocity
	#error _ALS_GetPlayerVelocity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerVelocity__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
#define _ALS_GetPlayerVelocity
#define GetPlayerVelocity( FIXES_GetPlayerVelocity(

#if defined _ALS_PlayCrimeReportForPlayer
	#error _ALS_PlayCrimeReportForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayCrimeReportForPlayer__(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
#define _ALS_PlayCrimeReportForPlayer
#define PlayCrimeReportForPlayer( FIXES_PlayCrimeReportForPlayer(

#if defined _ALS_PlayAudioStreamForPlayer
	#error _ALS_PlayAudioStreamForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = false) = PlayAudioStreamForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayAudioStreamForPlayer(playerid, _FIXES_MAYBE_CONST url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, _FIXES_MAYBE_BOOL:usepos = false) = PlayAudioStreamForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayAudioStreamForPlayer__(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false) = PlayAudioStreamForPlayer;
#define _ALS_PlayAudioStreamForPlayer
#define PlayAudioStreamForPlayer( FIXES_PlayAudioStreamForPlayer(

#if defined _ALS_StopAudioStreamForPlayer
	#error _ALS_StopAudioStreamForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native StopAudioStreamForPlayer__(playerid) = StopAudioStreamForPlayer;
#define _ALS_StopAudioStreamForPlayer
#define StopAudioStreamForPlayer( FIXES_StopAudioStreamForPlayer(

#if defined _ALS_SetPlayerShopName
	#error _ALS_SetPlayerShopName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerShopName(playerid, shopName[]) = SetPlayerShopName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerShopName(playerid, _FIXES_MAYBE_CONST shopName[]) = SetPlayerShopName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerShopName__(playerid, const shopName[]) = SetPlayerShopName;
#define _ALS_SetPlayerShopName
#define SetPlayerShopName( FIXES_SetPlayerShopName(

#if defined _ALS_SetPlayerSkillLevel
	#error _ALS_SetPlayerSkillLevel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerSkillLevel__(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
#define _ALS_SetPlayerSkillLevel
#define SetPlayerSkillLevel( FIXES_SetPlayerSkillLevel(

#if defined _ALS_GetPlayerSurfingVehicleID
	#error _ALS_GetPlayerSurfingVehicleID defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerSurfingVehicleID__(playerid) = GetPlayerSurfingVehicleID;
#define _ALS_GetPlayerSurfingVehicleID
#define GetPlayerSurfingVehicleID( FIXES_GetPlayerSurfingVehicleID(

#if defined _ALS_GetPlayerSurfingObjectID
	#error _ALS_GetPlayerSurfingObjectID defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerSurfingObjectID__(playerid) = GetPlayerSurfingObjectID;
#define _ALS_GetPlayerSurfingObjectID
#define GetPlayerSurfingObjectID( FIXES_GetPlayerSurfingObjectID(

#if defined _ALS_RemoveBuildingForPlayer
	#error _ALS_RemoveBuildingForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RemoveBuildingForPlayer__(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
#define _ALS_RemoveBuildingForPlayer
#define RemoveBuildingForPlayer( FIXES_RemoveBuildingForPlayer(

#if defined _ALS_GetPlayerLastShotVectors
	#error _ALS_GetPlayerLastShotVectors defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerLastShotVectors__(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
#define _ALS_GetPlayerLastShotVectors
#define GetPlayerLastShotVectors( FIXES_GetPlayerLastShotVectors(

#if defined _ALS_SetPlayerAttachedObject
	#error _ALS_SetPlayerAttachedObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerAttachedObject__(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
#define _ALS_SetPlayerAttachedObject
#define SetPlayerAttachedObject( FIXES_SetPlayerAttachedObject(

#if defined _ALS_RemovePlayerAttachedObject
	#error _ALS_RemovePlayerAttachedObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RemovePlayerAttachedObject__(playerid, index) = RemovePlayerAttachedObject;
#define _ALS_RemovePlayerAttachedObject
#define RemovePlayerAttachedObject( FIXES_RemovePlayerAttachedObject(

#if defined _ALS_IsPlayerAttachedObjectSlotUsed
	#error _ALS_IsPlayerAttachedObjectSlotUsed defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerAttachedObjectSlotUsed__(playerid, index) = IsPlayerAttachedObjectSlotUsed;
#define _ALS_IsPlayerAttachedObjectSlotUsed
#define IsPlayerAttachedObjectSlotUsed( FIXES_IsPlayerAttachedObjectSlotUsed(

#if defined _ALS_EditAttachedObject
	#error _ALS_EditAttachedObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EditAttachedObject(playerid, index) = EditAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EditAttachedObject(playerid, index) = EditAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EditAttachedObject__(playerid, index) = EditAttachedObject;
#define _ALS_EditAttachedObject
#define EditAttachedObject( FIXES_EditAttachedObject(

#if defined _ALS_CreatePlayerTextDraw
	#error _ALS_CreatePlayerTextDraw defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native PlayerText:FIXES_CreatePlayerTextDraw(playerid, Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = CreatePlayerTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerText:CreatePlayerTextDraw__(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
#define _ALS_CreatePlayerTextDraw
#define CreatePlayerTextDraw( FIXES_CreatePlayerTextDraw(

#if defined _ALS_PlayerTextDrawDestroy
	#error _ALS_PlayerTextDrawDestroy defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawDestroy__(playerid, PlayerText:text) = PlayerTextDrawDestroy;
#define _ALS_PlayerTextDrawDestroy
#define PlayerTextDrawDestroy( FIXES_PlayerTextDrawDestroy(

#if defined _ALS_PlayerTextDrawLetterSize
	#error _ALS_PlayerTextDrawLetterSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawLetterSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
#define _ALS_PlayerTextDrawLetterSize
#define PlayerTextDrawLetterSize( FIXES_PlayerTextDrawLetterSize(

#if defined _ALS_PlayerTextDrawTextSize
	#error _ALS_PlayerTextDrawTextSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawTextSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
#define _ALS_PlayerTextDrawTextSize
#define PlayerTextDrawTextSize( FIXES_PlayerTextDrawTextSize(

#if defined _ALS_PlayerTextDrawAlignment
	#error _ALS_PlayerTextDrawAlignment defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawAlignment__(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
#define _ALS_PlayerTextDrawAlignment
#define PlayerTextDrawAlignment( FIXES_PlayerTextDrawAlignment(

#if defined _ALS_PlayerTextDrawColor
	#error _ALS_PlayerTextDrawColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawColor__(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
#define _ALS_PlayerTextDrawColor
#define PlayerTextDrawColor( FIXES_PlayerTextDrawColor(

#if defined _ALS_PlayerTextDrawUseBox
	#error _ALS_PlayerTextDrawUseBox defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawUseBox(playerid, PlayerText:text, use) = PlayerTextDrawUseBox;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawUseBox(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:use) = PlayerTextDrawUseBox;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawUseBox__(playerid, PlayerText:text, bool:use) = PlayerTextDrawUseBox;
#define _ALS_PlayerTextDrawUseBox
#define PlayerTextDrawUseBox( FIXES_PlayerTextDrawUseBox(

#if defined _ALS_PlayerTextDrawBoxColor
	#error _ALS_PlayerTextDrawBoxColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawBoxColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
#define _ALS_PlayerTextDrawBoxColor
#define PlayerTextDrawBoxColor( FIXES_PlayerTextDrawBoxColor(

#if defined _ALS_PlayerTextDrawSetShadow
	#error _ALS_PlayerTextDrawSetShadow defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetShadow__(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
#define _ALS_PlayerTextDrawSetShadow
#define PlayerTextDrawSetShadow( FIXES_PlayerTextDrawSetShadow(

#if defined _ALS_PlayerTextDrawSetOutline
	#error _ALS_PlayerTextDrawSetOutline defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetOutline__(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
#define _ALS_PlayerTextDrawSetOutline
#define PlayerTextDrawSetOutline( FIXES_PlayerTextDrawSetOutline(

#if defined _ALS_PlayerTextDrawBackgroundColor
	#error _ALS_PlayerTextDrawBackgroundColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawBackgroundColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
#define _ALS_PlayerTextDrawBackgroundColor
#define PlayerTextDrawBackgroundColor( FIXES_PlayerTextDrawBackgroundColor(

#if defined _ALS_PlayerTextDrawFont
	#error _ALS_PlayerTextDrawFont defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawFont__(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
#define _ALS_PlayerTextDrawFont
#define PlayerTextDrawFont( FIXES_PlayerTextDrawFont(

#if defined _ALS_PlayerTextDrawSetProportional
	#error _ALS_PlayerTextDrawSetProportional defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetProportional(playerid, PlayerText:text, set) = PlayerTextDrawSetProportional;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetProportional(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetProportional;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetProportional__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetProportional;
#define _ALS_PlayerTextDrawSetProportional
#define PlayerTextDrawSetProportional( FIXES_PlayerTextDrawSetProportional(

#if defined _ALS_PlayerTextDrawSetSelectable
	#error _ALS_PlayerTextDrawSetSelectable defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetSelectable(playerid, PlayerText:text, set) = PlayerTextDrawSetSelectable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetSelectable(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetSelectable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetSelectable__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetSelectable;
#define _ALS_PlayerTextDrawSetSelectable
#define PlayerTextDrawSetSelectable( FIXES_PlayerTextDrawSetSelectable(

#if defined _ALS_PlayerTextDrawShow
	#error _ALS_PlayerTextDrawShow defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawShow__(playerid, PlayerText:text) = PlayerTextDrawShow;
#define _ALS_PlayerTextDrawShow
#define PlayerTextDrawShow( FIXES_PlayerTextDrawShow(

#if defined _ALS_PlayerTextDrawHide
	#error _ALS_PlayerTextDrawHide defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawHide__(playerid, PlayerText:text) = PlayerTextDrawHide;
#define _ALS_PlayerTextDrawHide
#define PlayerTextDrawHide( FIXES_PlayerTextDrawHide(

#if defined _ALS_PlayerTextDrawSetString
	#error _ALS_PlayerTextDrawSetString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetString(playerid, PlayerText:text, _FIXES_MAYBE_CONST string[]) = PlayerTextDrawSetString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetString__(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
#define _ALS_PlayerTextDrawSetString
#define PlayerTextDrawSetString( FIXES_PlayerTextDrawSetString(

#if defined _ALS_PlayerTextDrawSetPreviewModel
	#error _ALS_PlayerTextDrawSetPreviewModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetPreviewModel__(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
#define _ALS_PlayerTextDrawSetPreviewModel
#define PlayerTextDrawSetPreviewModel( FIXES_PlayerTextDrawSetPreviewModel(

#if defined _ALS_PlayerTextDrawSetPreviewRot
	#error _ALS_PlayerTextDrawSetPreviewRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetPreviewRot__(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
#define _ALS_PlayerTextDrawSetPreviewRot
#define PlayerTextDrawSetPreviewRot( FIXES_PlayerTextDrawSetPreviewRot(

#if defined _ALS_PlayerTextDrawSetPreviewVehCol
	#error _ALS_PlayerTextDrawSetPreviewVehCol defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerTextDrawSetPreviewVehCol__(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
#define _ALS_PlayerTextDrawSetPreviewVehCol
#define PlayerTextDrawSetPreviewVehCol( FIXES_PlayerTextDrawSetPreviewVehCol(

#if defined _ALS_SetPVarInt
	#error _ALS_SetPVarInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPVarInt(playerid, pvar[], value) = SetPVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[], value) = SetPVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPVarInt__(playerid, const pvar[], value) = SetPVarInt;
#define _ALS_SetPVarInt
#define SetPVarInt( FIXES_SetPVarInt(

#if defined _ALS_GetPVarInt
	#error _ALS_GetPVarInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPVarInt(playerid, pvar[]) = GetPVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPVarInt__(playerid, const pvar[]) = GetPVarInt;
#define _ALS_GetPVarInt
#define GetPVarInt( FIXES_GetPVarInt(

#if defined _ALS_SetPVarString
	#error _ALS_SetPVarString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPVarString(playerid, pvar[], value[]) = SetPVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], _FIXES_MAYBE_CONST value[]) = SetPVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPVarString__(playerid, const pvar[], const value[]) = SetPVarString;
#define _ALS_SetPVarString
#define SetPVarString( FIXES_SetPVarString(

#if defined _ALS_GetPVarString
	#error _ALS_GetPVarString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPVarString(playerid, pvar[], output[], len) = GetPVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetPVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPVarString__(playerid, const pvar[], output[], len = sizeof (output)) = GetPVarString;
#define _ALS_GetPVarString
#define GetPVarString( FIXES_GetPVarString(

#if defined _ALS_SetPVarFloat
	#error _ALS_SetPVarFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPVarFloat(playerid, pvar[], Float:value) = SetPVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[], Float:value) = SetPVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPVarFloat__(playerid, const pvar[], Float:value) = SetPVarFloat;
#define _ALS_SetPVarFloat
#define SetPVarFloat( FIXES_SetPVarFloat(

#if defined _ALS_GetPVarFloat
	#error _ALS_GetPVarFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetPVarFloat(playerid, pvar[]) = GetPVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetPVarFloat__(playerid, const pvar[]) = GetPVarFloat;
#define _ALS_GetPVarFloat
#define GetPVarFloat( FIXES_GetPVarFloat(

#if defined _ALS_DeletePVar
	#error _ALS_DeletePVar defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DeletePVar(playerid, pvar[]) = DeletePVar;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DeletePVar(playerid, _FIXES_MAYBE_CONST pvar[]) = DeletePVar;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DeletePVar__(playerid, const pvar[]) = DeletePVar;
#define _ALS_DeletePVar
#define DeletePVar( FIXES_DeletePVar(

#if defined _ALS_GetPVarsUpperIndex
	#error _ALS_GetPVarsUpperIndex defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPVarsUpperIndex__(playerid) = GetPVarsUpperIndex;
#define _ALS_GetPVarsUpperIndex
#define GetPVarsUpperIndex( FIXES_GetPVarsUpperIndex(

#if defined _ALS_GetPVarNameAtIndex
	#error _ALS_GetPVarNameAtIndex defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPVarNameAtIndex(playerid, index, output[], size) = GetPVarNameAtIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPVarNameAtIndex(playerid, index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPVarNameAtIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPVarNameAtIndex__(playerid, index, output[], size = sizeof (output)) = GetPVarNameAtIndex;
#define _ALS_GetPVarNameAtIndex
#define GetPVarNameAtIndex( FIXES_GetPVarNameAtIndex(

#if defined _ALS_GetPVarType
	#error _ALS_GetPVarType defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native PLAYER_VARTYPE:BAD_GetPVarType(playerid, pvar[]) = GetPVarType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native PLAYER_VARTYPE:FIXES_GetPVarType(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PLAYER_VARTYPE:GetPVarType__(playerid, const pvar[]) = GetPVarType;
#define _ALS_GetPVarType
#define GetPVarType( FIXES_GetPVarType(

#if defined _ALS_SetPlayerChatBubble
	#error _ALS_SetPlayerChatBubble defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerChatBubble(playerid, text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerChatBubble(playerid, _FIXES_MAYBE_CONST text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerChatBubble__(playerid, const text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
#define _ALS_SetPlayerChatBubble
#define SetPlayerChatBubble( FIXES_SetPlayerChatBubble(

#if defined _ALS_PutPlayerInVehicle
	#error _ALS_PutPlayerInVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PutPlayerInVehicle__(playerid, vehicleid, seatid) = PutPlayerInVehicle;
#define _ALS_PutPlayerInVehicle
#define PutPlayerInVehicle( FIXES_PutPlayerInVehicle(

#if defined _ALS_GetPlayerVehicleID
	#error _ALS_GetPlayerVehicleID defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerVehicleID__(playerid) = GetPlayerVehicleID;
#define _ALS_GetPlayerVehicleID
#define GetPlayerVehicleID( FIXES_GetPlayerVehicleID(

#if defined _ALS_GetPlayerVehicleSeat
	#error _ALS_GetPlayerVehicleSeat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerVehicleSeat__(playerid) = GetPlayerVehicleSeat;
#define _ALS_GetPlayerVehicleSeat
#define GetPlayerVehicleSeat( FIXES_GetPlayerVehicleSeat(

#if defined _ALS_RemovePlayerFromVehicle
	#error _ALS_RemovePlayerFromVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RemovePlayerFromVehicle__(playerid) = RemovePlayerFromVehicle;
#define _ALS_RemovePlayerFromVehicle
#define RemovePlayerFromVehicle( FIXES_RemovePlayerFromVehicle(

#if defined _ALS_TogglePlayerControllable
	#error _ALS_TogglePlayerControllable defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TogglePlayerControllable(playerid, toggle) = TogglePlayerControllable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TogglePlayerControllable(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerControllable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TogglePlayerControllable__(playerid, bool:toggle) = TogglePlayerControllable;
#define _ALS_TogglePlayerControllable
#define TogglePlayerControllable( FIXES_TogglePlayerControllable(

#if defined _ALS_PlayerPlaySound
	#error _ALS_PlayerPlaySound defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerPlaySound__(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
#define _ALS_PlayerPlaySound
#define PlayerPlaySound( FIXES_PlayerPlaySound(

#if defined _ALS_ApplyAnimation
	#error _ALS_ApplyAnimation defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ApplyAnimation(playerid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ApplyAnimation(playerid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ApplyAnimation__(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
#define _ALS_ApplyAnimation
#define ApplyAnimation( FIXES_ApplyAnimation(

#if defined _ALS_ClearAnimations
	#error _ALS_ClearAnimations defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ClearAnimations__(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
#define _ALS_ClearAnimations
#define ClearAnimations( FIXES_ClearAnimations(

#if defined _ALS_GetPlayerAnimationIndex
	#error _ALS_GetPlayerAnimationIndex defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerAnimationIndex__(playerid) = GetPlayerAnimationIndex;
#define _ALS_GetPlayerAnimationIndex
#define GetPlayerAnimationIndex( FIXES_GetPlayerAnimationIndex(

#if defined _ALS_GetAnimationName
	#error _ALS_GetAnimationName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2) = GetAnimationName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], _FIXES_MAYBE_SIZEOF(len2, animationName)) = GetAnimationName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetAnimationName__(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2 = sizeof (animationName)) = GetAnimationName;
#define _ALS_GetAnimationName
#define GetAnimationName( FIXES_GetAnimationName(

#if defined _ALS_GetPlayerSpecialAction
	#error _ALS_GetPlayerSpecialAction defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native SPECIAL_ACTION:BAD_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native SPECIAL_ACTION:FIXES_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SPECIAL_ACTION:GetPlayerSpecialAction__(playerid) = GetPlayerSpecialAction;
#define _ALS_GetPlayerSpecialAction
#define GetPlayerSpecialAction( FIXES_GetPlayerSpecialAction(

#if defined _ALS_SetPlayerSpecialAction
	#error _ALS_SetPlayerSpecialAction defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerSpecialAction__(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
#define _ALS_SetPlayerSpecialAction
#define SetPlayerSpecialAction( FIXES_SetPlayerSpecialAction(

#if defined _ALS_DisableRemoteVehicleCollisions
	#error _ALS_DisableRemoteVehicleCollisions defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisableRemoteVehicleCollisions(playerid, disable) = DisableRemoteVehicleCollisions;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisableRemoteVehicleCollisions(playerid, _FIXES_MAYBE_BOOL:disable) = DisableRemoteVehicleCollisions;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisableRemoteVehicleCollisions__(playerid, bool:disable) = DisableRemoteVehicleCollisions;
#define _ALS_DisableRemoteVehicleCollisions
#define DisableRemoteVehicleCollisions( FIXES_DisableRemoteVehicleCollisions(

#if defined _ALS_SetPlayerCheckpoint
	#error _ALS_SetPlayerCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerCheckpoint__(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
#define _ALS_SetPlayerCheckpoint
#define SetPlayerCheckpoint( FIXES_SetPlayerCheckpoint(

#if defined _ALS_DisablePlayerCheckpoint
	#error _ALS_DisablePlayerCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisablePlayerCheckpoint__(playerid) = DisablePlayerCheckpoint;
#define _ALS_DisablePlayerCheckpoint
#define DisablePlayerCheckpoint( FIXES_DisablePlayerCheckpoint(

#if defined _ALS_SetPlayerRaceCheckpoint
	#error _ALS_SetPlayerRaceCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerRaceCheckpoint__(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
#define _ALS_SetPlayerRaceCheckpoint
#define SetPlayerRaceCheckpoint( FIXES_SetPlayerRaceCheckpoint(

#if defined _ALS_DisablePlayerRaceCheckpoint
	#error _ALS_DisablePlayerRaceCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisablePlayerRaceCheckpoint__(playerid) = DisablePlayerRaceCheckpoint;
#define _ALS_DisablePlayerRaceCheckpoint
#define DisablePlayerRaceCheckpoint( FIXES_DisablePlayerRaceCheckpoint(

#if defined _ALS_SetPlayerWorldBounds
	#error _ALS_SetPlayerWorldBounds defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerWorldBounds__(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
#define _ALS_SetPlayerWorldBounds
#define SetPlayerWorldBounds( FIXES_SetPlayerWorldBounds(

#if defined _ALS_SetPlayerMarkerForPlayer
	#error _ALS_SetPlayerMarkerForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerMarkerForPlayer__(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
#define _ALS_SetPlayerMarkerForPlayer
#define SetPlayerMarkerForPlayer( FIXES_SetPlayerMarkerForPlayer(

#if defined _ALS_ShowPlayerNameTagForPlayer
	#error _ALS_ShowPlayerNameTagForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ShowPlayerNameTagForPlayer(playerid, targetid, show) = ShowPlayerNameTagForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ShowPlayerNameTagForPlayer(playerid, targetid, _FIXES_MAYBE_BOOL:show) = ShowPlayerNameTagForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ShowPlayerNameTagForPlayer__(playerid, targetid, bool:show) = ShowPlayerNameTagForPlayer;
#define _ALS_ShowPlayerNameTagForPlayer
#define ShowPlayerNameTagForPlayer( FIXES_ShowPlayerNameTagForPlayer(

#if defined _ALS_SetPlayerMapIcon
	#error _ALS_SetPlayerMapIcon defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerMapIcon__(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
#define _ALS_SetPlayerMapIcon
#define SetPlayerMapIcon( FIXES_SetPlayerMapIcon(

#if defined _ALS_RemovePlayerMapIcon
	#error _ALS_RemovePlayerMapIcon defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RemovePlayerMapIcon__(playerid, iconid) = RemovePlayerMapIcon;
#define _ALS_RemovePlayerMapIcon
#define RemovePlayerMapIcon( FIXES_RemovePlayerMapIcon(

#if defined _ALS_AllowPlayerTeleport
	#error _ALS_AllowPlayerTeleport defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AllowPlayerTeleport(playerid, allow) = AllowPlayerTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AllowPlayerTeleport(playerid, _FIXES_MAYBE_BOOL:allow) = AllowPlayerTeleport;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AllowPlayerTeleport__(playerid, bool:allow) = AllowPlayerTeleport;
#define _ALS_AllowPlayerTeleport
#define AllowPlayerTeleport( FIXES_AllowPlayerTeleport(

#if defined _ALS_SetPlayerCameraPos
	#error _ALS_SetPlayerCameraPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerCameraPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
#define _ALS_SetPlayerCameraPos
#define SetPlayerCameraPos( FIXES_SetPlayerCameraPos(

#if defined _ALS_SetPlayerCameraLookAt
	#error _ALS_SetPlayerCameraLookAt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerCameraLookAt__(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
#define _ALS_SetPlayerCameraLookAt
#define SetPlayerCameraLookAt( FIXES_SetPlayerCameraLookAt(

#if defined _ALS_SetCameraBehindPlayer
	#error _ALS_SetCameraBehindPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetCameraBehindPlayer__(playerid) = SetCameraBehindPlayer;
#define _ALS_SetCameraBehindPlayer
#define SetCameraBehindPlayer( FIXES_SetCameraBehindPlayer(

#if defined _ALS_GetPlayerCameraPos
	#error _ALS_GetPlayerCameraPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
#define _ALS_GetPlayerCameraPos
#define GetPlayerCameraPos( FIXES_GetPlayerCameraPos(

#if defined _ALS_GetPlayerCameraFrontVector
	#error _ALS_GetPlayerCameraFrontVector defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraFrontVector__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
#define _ALS_GetPlayerCameraFrontVector
#define GetPlayerCameraFrontVector( FIXES_GetPlayerCameraFrontVector(

#if defined _ALS_GetPlayerCameraMode
	#error _ALS_GetPlayerCameraMode defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native CAM_MODE:BAD_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native CAM_MODE:FIXES_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CAM_MODE:GetPlayerCameraMode__(playerid) = GetPlayerCameraMode;
#define _ALS_GetPlayerCameraMode
#define GetPlayerCameraMode( FIXES_GetPlayerCameraMode(

#if defined _ALS_EnablePlayerCameraTarget
	#error _ALS_EnablePlayerCameraTarget defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnablePlayerCameraTarget(playerid, enable) = EnablePlayerCameraTarget;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnablePlayerCameraTarget(playerid, _FIXES_MAYBE_BOOL:enable) = EnablePlayerCameraTarget;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnablePlayerCameraTarget__(playerid, bool:enable) = EnablePlayerCameraTarget;
#define _ALS_EnablePlayerCameraTarget
#define EnablePlayerCameraTarget( FIXES_EnablePlayerCameraTarget(

#if defined _ALS_GetPlayerCameraTargetObject
	#error _ALS_GetPlayerCameraTargetObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraTargetObject__(playerid) = GetPlayerCameraTargetObject;
#define _ALS_GetPlayerCameraTargetObject
#define GetPlayerCameraTargetObject( FIXES_GetPlayerCameraTargetObject(

#if defined _ALS_GetPlayerCameraTargetVehicle
	#error _ALS_GetPlayerCameraTargetVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraTargetVehicle__(playerid) = GetPlayerCameraTargetVehicle;
#define _ALS_GetPlayerCameraTargetVehicle
#define GetPlayerCameraTargetVehicle( FIXES_GetPlayerCameraTargetVehicle(

#if defined _ALS_GetPlayerCameraTargetPlayer
	#error _ALS_GetPlayerCameraTargetPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraTargetPlayer__(playerid) = GetPlayerCameraTargetPlayer;
#define _ALS_GetPlayerCameraTargetPlayer
#define GetPlayerCameraTargetPlayer( FIXES_GetPlayerCameraTargetPlayer(

#if defined _ALS_GetPlayerCameraTargetActor
	#error _ALS_GetPlayerCameraTargetActor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerCameraTargetActor__(playerid) = GetPlayerCameraTargetActor;
#define _ALS_GetPlayerCameraTargetActor
#define GetPlayerCameraTargetActor( FIXES_GetPlayerCameraTargetActor(

#if defined _ALS_GetPlayerCameraAspectRatio
	#error _ALS_GetPlayerCameraAspectRatio defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetPlayerCameraAspectRatio__(playerid) = GetPlayerCameraAspectRatio;
#define _ALS_GetPlayerCameraAspectRatio
#define GetPlayerCameraAspectRatio( FIXES_GetPlayerCameraAspectRatio(

#if defined _ALS_GetPlayerCameraZoom
	#error _ALS_GetPlayerCameraZoom defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetPlayerCameraZoom__(playerid) = GetPlayerCameraZoom;
#define _ALS_GetPlayerCameraZoom
#define GetPlayerCameraZoom( FIXES_GetPlayerCameraZoom(

#if defined _ALS_AttachCameraToObject
	#error _ALS_AttachCameraToObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachCameraToObject__(playerid, objectid) = AttachCameraToObject;
#define _ALS_AttachCameraToObject
#define AttachCameraToObject( FIXES_AttachCameraToObject(

#if defined _ALS_AttachCameraToPlayerObject
	#error _ALS_AttachCameraToPlayerObject defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachCameraToPlayerObject__(playerid, objectid) = AttachCameraToPlayerObject;
#define _ALS_AttachCameraToPlayerObject
#define AttachCameraToPlayerObject( FIXES_AttachCameraToPlayerObject(

#if defined _ALS_InterpolateCameraPos
	#error _ALS_InterpolateCameraPos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native InterpolateCameraPos__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
#define _ALS_InterpolateCameraPos
#define InterpolateCameraPos( FIXES_InterpolateCameraPos(

#if defined _ALS_InterpolateCameraLookAt
	#error _ALS_InterpolateCameraLookAt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native InterpolateCameraLookAt__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
#define _ALS_InterpolateCameraLookAt
#define InterpolateCameraLookAt( FIXES_InterpolateCameraLookAt(

#if defined _ALS_IsPlayerConnected
	#error _ALS_IsPlayerConnected defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerConnected(playerid) = IsPlayerConnected;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerConnected(playerid) = IsPlayerConnected;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerConnected__(playerid) = IsPlayerConnected;
#define _ALS_IsPlayerConnected
#define IsPlayerConnected( FIXES_IsPlayerConnected(

#if defined _ALS_IsPlayerInVehicle
	#error _ALS_IsPlayerInVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerInVehicle__(playerid, vehicleid) = IsPlayerInVehicle;
#define _ALS_IsPlayerInVehicle
#define IsPlayerInVehicle( FIXES_IsPlayerInVehicle(

#if defined _ALS_IsPlayerInAnyVehicle
	#error _ALS_IsPlayerInAnyVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerInAnyVehicle__(playerid) = IsPlayerInAnyVehicle;
#define _ALS_IsPlayerInAnyVehicle
#define IsPlayerInAnyVehicle( FIXES_IsPlayerInAnyVehicle(

#if defined _ALS_IsPlayerInCheckpoint
	#error _ALS_IsPlayerInCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerInCheckpoint__(playerid) = IsPlayerInCheckpoint;
#define _ALS_IsPlayerInCheckpoint
#define IsPlayerInCheckpoint( FIXES_IsPlayerInCheckpoint(

#if defined _ALS_IsPlayerInRaceCheckpoint
	#error _ALS_IsPlayerInRaceCheckpoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerInRaceCheckpoint__(playerid) = IsPlayerInRaceCheckpoint;
#define _ALS_IsPlayerInRaceCheckpoint
#define IsPlayerInRaceCheckpoint( FIXES_IsPlayerInRaceCheckpoint(

#if defined _ALS_SetPlayerVirtualWorld
	#error _ALS_SetPlayerVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetPlayerVirtualWorld__(playerid, virtualWorld) = SetPlayerVirtualWorld;
#define _ALS_SetPlayerVirtualWorld
#define SetPlayerVirtualWorld( FIXES_SetPlayerVirtualWorld(

#if defined _ALS_GetPlayerVirtualWorld
	#error _ALS_GetPlayerVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerVirtualWorld__(playerid) = GetPlayerVirtualWorld;
#define _ALS_GetPlayerVirtualWorld
#define GetPlayerVirtualWorld( FIXES_GetPlayerVirtualWorld(

#if defined _ALS_EnableStuntBonusForPlayer
	#error _ALS_EnableStuntBonusForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnableStuntBonusForPlayer(playerid, enable) = EnableStuntBonusForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnableStuntBonusForPlayer(playerid, _FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnableStuntBonusForPlayer__(playerid, bool:enable) = EnableStuntBonusForPlayer;
#define _ALS_EnableStuntBonusForPlayer
#define EnableStuntBonusForPlayer( FIXES_EnableStuntBonusForPlayer(

#if defined _ALS_EnableStuntBonusForAll
	#error _ALS_EnableStuntBonusForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnableStuntBonusForAll(enable) = EnableStuntBonusForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnableStuntBonusForAll(_FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnableStuntBonusForAll__(bool:enable) = EnableStuntBonusForAll;
#define _ALS_EnableStuntBonusForAll
#define EnableStuntBonusForAll( FIXES_EnableStuntBonusForAll(

#if defined _ALS_TogglePlayerSpectating
	#error _ALS_TogglePlayerSpectating defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TogglePlayerSpectating(playerid, toggle) = TogglePlayerSpectating;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TogglePlayerSpectating(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerSpectating;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TogglePlayerSpectating__(playerid, bool:toggle) = TogglePlayerSpectating;
#define _ALS_TogglePlayerSpectating
#define TogglePlayerSpectating( FIXES_TogglePlayerSpectating(

#if defined _ALS_PlayerSpectatePlayer
	#error _ALS_PlayerSpectatePlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerSpectatePlayer__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
#define _ALS_PlayerSpectatePlayer
#define PlayerSpectatePlayer( FIXES_PlayerSpectatePlayer(

#if defined _ALS_PlayerSpectateVehicle
	#error _ALS_PlayerSpectateVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerSpectateVehicle__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
#define _ALS_PlayerSpectateVehicle
#define PlayerSpectateVehicle( FIXES_PlayerSpectateVehicle(

#if defined _ALS_StartRecordingPlayerData
	#error _ALS_StartRecordingPlayerData defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, recordFile[]) = StartRecordingPlayerData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, _FIXES_MAYBE_CONST recordFile[]) = StartRecordingPlayerData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native StartRecordingPlayerData__(playerid, PLAYER_RECORDING_TYPE:recordType, const recordFile[]) = StartRecordingPlayerData;
#define _ALS_StartRecordingPlayerData
#define StartRecordingPlayerData( FIXES_StartRecordingPlayerData(

#if defined _ALS_StopRecordingPlayerData
	#error _ALS_StopRecordingPlayerData defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native StopRecordingPlayerData__(playerid) = StopRecordingPlayerData;
#define _ALS_StopRecordingPlayerData
#define StopRecordingPlayerData( FIXES_StopRecordingPlayerData(

#if defined _ALS_SelectTextDraw
	#error _ALS_SelectTextDraw defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SelectTextDraw__(playerid, hoverColour) = SelectTextDraw;
#define _ALS_SelectTextDraw
#define SelectTextDraw( FIXES_SelectTextDraw(

#if defined _ALS_CancelSelectTextDraw
	#error _ALS_CancelSelectTextDraw defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CancelSelectTextDraw__(playerid) = CancelSelectTextDraw;
#define _ALS_CancelSelectTextDraw
#define CancelSelectTextDraw( FIXES_CancelSelectTextDraw(

#if defined _ALS_CreateExplosionForPlayer
	#error _ALS_CreateExplosionForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreateExplosionForPlayer__(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
#define _ALS_CreateExplosionForPlayer
#define CreateExplosionForPlayer( FIXES_CreateExplosionForPlayer(

#if defined _ALS_SendClientCheck
	#error _ALS_SendClientCheck defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendClientCheck__(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
#define _ALS_SendClientCheck
#define SendClientCheck( FIXES_SendClientCheck(

/*

     █████          ███████  █████  ███    ███ ██████
    ██   ██         ██      ██   ██ ████  ████ ██   ██
    ███████         ███████ ███████ ██ ████ ██ ██████
    ██   ██              ██ ██   ██ ██  ██  ██ ██
    ██   ██ ███████ ███████ ██   ██ ██      ██ ██

*/

#if defined _ALS_print
	#error _ALS_print defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_print(const string[]) = print;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_print(const string[]) = print;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native print__(const string[]) = print;
#define _ALS_print
#define print( FIXES_print(

#if defined _ALS_printf
	#error _ALS_printf defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_printf(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_printf(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native printf__(const format[], {Float, _}:...) = printf;
#define _ALS_printf
#define printf( FIXES_printf(

#if defined _ALS_format
	#error _ALS_format defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_format(output[], len, const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#define _ALS_format
#define format( FIXES_format(

#if defined _ALS_Print
	#error _ALS_Print defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Print(const string[]) = print;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Print(const string[]) = print;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Print__(const string[]) = print;
#define _ALS_Print
#define Print( FIXES_Print(

#if defined _ALS_PrintF
	#error _ALS_PrintF defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_PrintF(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_PrintF(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PrintF__(const format[], {Float, _}:...) = printf;
#define _ALS_PrintF
#define PrintF( FIXES_PrintF(

#if defined _ALS_Format
	#error _ALS_Format defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Format(output[], len, const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#define _ALS_Format
#define Format( FIXES_Format(

#if defined _ALS_SendClientMessage
	#error _ALS_SendClientMessage defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendClientMessage__(playerid, colour, const message[]) = SendClientMessage;
#define _ALS_SendClientMessage
#define SendClientMessage( FIXES_SendClientMessage(

#if defined _ALS_SendClientMessageToAll
	#error _ALS_SendClientMessageToAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendClientMessageToAll__(colour, const message[]) = SendClientMessageToAll;
#define _ALS_SendClientMessageToAll
#define SendClientMessageToAll( FIXES_SendClientMessageToAll(

#if defined _ALS_SendPlayerMessageToPlayer
	#error _ALS_SendPlayerMessageToPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendPlayerMessageToPlayer__(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
#define _ALS_SendPlayerMessageToPlayer
#define SendPlayerMessageToPlayer( FIXES_SendPlayerMessageToPlayer(

#if defined _ALS_SendPlayerMessageToAll
	#error _ALS_SendPlayerMessageToAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendPlayerMessageToAll__(senderid, const message[]) = SendPlayerMessageToAll;
#define _ALS_SendPlayerMessageToAll
#define SendPlayerMessageToAll( FIXES_SendPlayerMessageToAll(

#if defined _ALS_SendDeathMessage
	#error _ALS_SendDeathMessage defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendDeathMessage__(killer, killee, weapon) = SendDeathMessage;
#define _ALS_SendDeathMessage
#define SendDeathMessage( FIXES_SendDeathMessage(

#if defined _ALS_SendDeathMessageToPlayer
	#error _ALS_SendDeathMessageToPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendDeathMessageToPlayer__(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
#define _ALS_SendDeathMessageToPlayer
#define SendDeathMessageToPlayer( FIXES_SendDeathMessageToPlayer(

#if defined _ALS_GameTextForAll
	#error _ALS_GameTextForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GameTextForAll(const string[], time, style) = GameTextForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GameTextForAll(const string[], time, style) = GameTextForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GameTextForAll__(const string[], time, style) = GameTextForAll;
#define _ALS_GameTextForAll
#define GameTextForAll( FIXES_GameTextForAll(

#if defined _ALS_GameTextForPlayer
	#error _ALS_GameTextForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GameTextForPlayer__(playerid, const string[], time, style) = GameTextForPlayer;
#define _ALS_GameTextForPlayer
#define GameTextForPlayer( FIXES_GameTextForPlayer(

#if defined _ALS_SetTimer
	#error _ALS_SetTimer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetTimer(functionName[], interval, repeating) = SetTimer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetTimer(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating) = SetTimer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetTimer__(const functionName[], interval, bool:repeating) = SetTimer;
#define _ALS_SetTimer
#define SetTimer( FIXES_SetTimer(

#if defined _ALS_SetTimerEx
	#error _ALS_SetTimerEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetTimerEx(functionName[], interval, repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetTimerEx(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetTimerEx__(const functionName[], interval, bool:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
#define _ALS_SetTimerEx
#define SetTimerEx( FIXES_SetTimerEx(

#if defined _ALS_KillTimer
	#error _ALS_KillTimer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_KillTimer(timerid) = KillTimer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_KillTimer(timerid) = KillTimer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native KillTimer__(timerid) = KillTimer;
#define _ALS_KillTimer
#define KillTimer( FIXES_KillTimer(

#if defined _ALS_GetTickCount
	#error _ALS_GetTickCount defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetTickCount() = GetTickCount;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetTickCount() = GetTickCount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetTickCount__() = GetTickCount;
#define _ALS_GetTickCount
#define GetTickCount( FIXES_GetTickCount(

#if defined _ALS_GetMaxPlayers
	#error _ALS_GetMaxPlayers defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetMaxPlayers() = GetMaxPlayers;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetMaxPlayers() = GetMaxPlayers;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetMaxPlayers__() = GetMaxPlayers;
#define _ALS_GetMaxPlayers
#define GetMaxPlayers( FIXES_GetMaxPlayers(

#if defined _ALS_CallRemoteFunction
	#error _ALS_CallRemoteFunction defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CallRemoteFunction__(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
#define _ALS_CallRemoteFunction
#define CallRemoteFunction( FIXES_CallRemoteFunction(

#if defined _ALS_CallLocalFunction
	#error _ALS_CallLocalFunction defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CallLocalFunction__(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
#define _ALS_CallLocalFunction
#define CallLocalFunction( FIXES_CallLocalFunction(

#if defined _ALS_VectorSize
	#error _ALS_VectorSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:VectorSize__(Float:x, Float:y, Float:z) = VectorSize;
#define _ALS_VectorSize
#define VectorSize( FIXES_VectorSize(

#if defined _ALS_asin
	#error _ALS_asin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_asin(Float:value) = asin;
#if FIX_camel_case
	#pragma deprecated Use `ASin`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_asin(Float:value) = asin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:asin__(Float:value) = asin;
#define _ALS_asin
#define asin( FIXES_asin(

#if defined _ALS_acos
	#error _ALS_acos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_acos(Float:value) = acos;
#if FIX_camel_case
	#pragma deprecated Use `ACos`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_acos(Float:value) = acos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:acos__(Float:value) = acos;
#define _ALS_acos
#define acos( FIXES_acos(

#if defined _ALS_atan
	#error _ALS_atan defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_atan(Float:value) = atan;
#if FIX_camel_case
	#pragma deprecated Use `ATan`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_atan(Float:value) = atan;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:atan__(Float:value) = atan;
#define _ALS_atan
#define atan( FIXES_atan(

#if defined _ALS_atan2
	#error _ALS_atan2 defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_atan2(Float:y, Float:x) = atan2;
#if FIX_camel_case
	#pragma deprecated Use `ATan2`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_atan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:atan2__(Float:y, Float:x) = atan2;
#define _ALS_atan2
#define atan2( FIXES_atan2(

#if defined _ALS_ASin
	#error _ALS_ASin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_ASin(Float:value) = asin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_ASin(Float:value) = asin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:ASin__(Float:value) = asin;
#define _ALS_ASin
#define ASin( FIXES_ASin(

#if defined _ALS_ACos
	#error _ALS_ACos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_ACos(Float:value) = acos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_ACos(Float:value) = acos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:ACos__(Float:value) = acos;
#define _ALS_ACos
#define ACos( FIXES_ACos(

#if defined _ALS_ATan
	#error _ALS_ATan defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_ATan(Float:value) = atan;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_ATan(Float:value) = atan;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:ATan__(Float:value) = atan;
#define _ALS_ATan
#define ATan( FIXES_ATan(

#if defined _ALS_ATan2
	#error _ALS_ATan2 defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_ATan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_ATan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:ATan2__(Float:y, Float:x) = atan2;
#define _ALS_ATan2
#define ATan2( FIXES_ATan2(

#if defined _ALS_GetPlayerPoolSize
	#error _ALS_GetPlayerPoolSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerPoolSize() = GetPlayerPoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerPoolSize() = GetPlayerPoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerPoolSize__() = GetPlayerPoolSize;
#define _ALS_GetPlayerPoolSize
#define GetPlayerPoolSize( FIXES_GetPlayerPoolSize(

#if defined _ALS_GetVehiclePoolSize
	#error _ALS_GetVehiclePoolSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehiclePoolSize() = GetVehiclePoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehiclePoolSize() = GetVehiclePoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehiclePoolSize__() = GetVehiclePoolSize;
#define _ALS_GetVehiclePoolSize
#define GetVehiclePoolSize( FIXES_GetVehiclePoolSize(

#if defined _ALS_GetActorPoolSize
	#error _ALS_GetActorPoolSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetActorPoolSize() = GetActorPoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetActorPoolSize() = GetActorPoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetActorPoolSize__() = GetActorPoolSize;
#define _ALS_GetActorPoolSize
#define GetActorPoolSize( FIXES_GetActorPoolSize(

#if defined _ALS_SHA256_PassHash
	#error _ALS_SHA256_PassHash defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SHA256_PassHash(password[], salt[], output[], size) = SHA256_PassHash;
#pragma deprecated Use BCrypt for hashing passwords.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SHA256_PassHash(_FIXES_MAYBE_CONST password[], _FIXES_MAYBE_CONST salt[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = SHA256_PassHash;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SHA256_PassHash__(const password[], const salt[], output[], size = sizeof (output)) = SHA256_PassHash;
#define _ALS_SHA256_PassHash
#define SHA256_PassHash( FIXES_SHA256_PassHash(

#if defined _ALS_SetSVarInt
	#error _ALS_SetSVarInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetSVarInt(svar[], value) = SetSVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetSVarInt(_FIXES_MAYBE_CONST svar[], value) = SetSVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetSVarInt__(const svar[], value) = SetSVarInt;
#define _ALS_SetSVarInt
#define SetSVarInt( FIXES_SetSVarInt(

#if defined _ALS_GetSVarInt
	#error _ALS_GetSVarInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetSVarInt(svar[]) = GetSVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetSVarInt(_FIXES_MAYBE_CONST svar[]) = GetSVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetSVarInt__(const svar[]) = GetSVarInt;
#define _ALS_GetSVarInt
#define GetSVarInt( FIXES_GetSVarInt(

#if defined _ALS_SetSVarString
	#error _ALS_SetSVarString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetSVarString(svar[], value[]) = SetSVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetSVarString(_FIXES_MAYBE_CONST svar[], _FIXES_MAYBE_CONST value[]) = SetSVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetSVarString__(const svar[], const value[]) = SetSVarString;
#define _ALS_SetSVarString
#define SetSVarString( FIXES_SetSVarString(

#if defined _ALS_GetSVarString
	#error _ALS_GetSVarString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetSVarString(svar[], output[], len) = GetSVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetSVarString(_FIXES_MAYBE_CONST svar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetSVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetSVarString__(const svar[], output[], len = sizeof (output)) = GetSVarString;
#define _ALS_GetSVarString
#define GetSVarString( FIXES_GetSVarString(

#if defined _ALS_SetSVarFloat
	#error _ALS_SetSVarFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetSVarFloat(svar[], Float:value) = SetSVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetSVarFloat(_FIXES_MAYBE_CONST svar[], Float:value) = SetSVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetSVarFloat__(const svar[], Float:value) = SetSVarFloat;
#define _ALS_SetSVarFloat
#define SetSVarFloat( FIXES_SetSVarFloat(

#if defined _ALS_GetSVarFloat
	#error _ALS_GetSVarFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetSVarFloat(svar[]) = GetSVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetSVarFloat(_FIXES_MAYBE_CONST svar[]) = GetSVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetSVarFloat__(const svar[]) = GetSVarFloat;
#define _ALS_GetSVarFloat
#define GetSVarFloat( FIXES_GetSVarFloat(

#if defined _ALS_DeleteSVar
	#error _ALS_DeleteSVar defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DeleteSVar(svar[]) = DeleteSVar;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DeleteSVar(_FIXES_MAYBE_CONST svar[]) = DeleteSVar;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DeleteSVar__(const svar[]) = DeleteSVar;
#define _ALS_DeleteSVar
#define DeleteSVar( FIXES_DeleteSVar(

#if defined _ALS_GetSVarsUpperIndex
	#error _ALS_GetSVarsUpperIndex defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetSVarsUpperIndex() = GetSVarsUpperIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetSVarsUpperIndex() = GetSVarsUpperIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetSVarsUpperIndex__() = GetSVarsUpperIndex;
#define _ALS_GetSVarsUpperIndex
#define GetSVarsUpperIndex( FIXES_GetSVarsUpperIndex(

#if defined _ALS_GetSVarNameAtIndex
	#error _ALS_GetSVarNameAtIndex defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetSVarNameAtIndex(index, output[], size) = GetSVarNameAtIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetSVarNameAtIndex(index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetSVarNameAtIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetSVarNameAtIndex__(index, output[], size = sizeof (output)) = GetSVarNameAtIndex;
#define _ALS_GetSVarNameAtIndex
#define GetSVarNameAtIndex( FIXES_GetSVarNameAtIndex(

#if defined _ALS_GetSVarType
	#error _ALS_GetSVarType defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native SERVER_VARTYPE:BAD_GetSVarType(svar[]) = GetSVarType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native SERVER_VARTYPE:FIXES_GetSVarType(_FIXES_MAYBE_CONST svar[]) = GetSVarType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SERVER_VARTYPE:GetSVarType__(const svar[]) = GetSVarType;
#define _ALS_GetSVarType
#define GetSVarType( FIXES_GetSVarType(

#if defined _ALS_SetGameModeText
	#error _ALS_SetGameModeText defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetGameModeText(const string[]) = SetGameModeText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetGameModeText(const string[]) = SetGameModeText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetGameModeText__(const string[]) = SetGameModeText;
#define _ALS_SetGameModeText
#define SetGameModeText( FIXES_SetGameModeText(

#if defined _ALS_SetTeamCount
	#error _ALS_SetTeamCount defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetTeamCount(count) = SetTeamCount;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetTeamCount(count) = SetTeamCount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetTeamCount__(count) = SetTeamCount;
#define _ALS_SetTeamCount
#define SetTeamCount( FIXES_SetTeamCount(

#if defined _ALS_AddPlayerClass
	#error _ALS_AddPlayerClass defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddPlayerClass__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
#define _ALS_AddPlayerClass
#define AddPlayerClass( FIXES_AddPlayerClass(

#if defined _ALS_AddPlayerClassEx
	#error _ALS_AddPlayerClassEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddPlayerClassEx__(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
#define _ALS_AddPlayerClassEx
#define AddPlayerClassEx( FIXES_AddPlayerClassEx(

#if defined _ALS_AddStaticVehicle
	#error _ALS_AddStaticVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddStaticVehicle__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
#define _ALS_AddStaticVehicle
#define AddStaticVehicle( FIXES_AddStaticVehicle(

#if defined _ALS_AddStaticVehicleEx
	#error _ALS_AddStaticVehicleEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, addSiren = false) = AddStaticVehicleEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = AddStaticVehicleEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddStaticVehicleEx__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false) = AddStaticVehicleEx;
#define _ALS_AddStaticVehicleEx
#define AddStaticVehicleEx( FIXES_AddStaticVehicleEx(

#if defined _ALS_AddStaticPickup
	#error _ALS_AddStaticPickup defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddStaticPickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
#define _ALS_AddStaticPickup
#define AddStaticPickup( FIXES_AddStaticPickup(

#if defined _ALS_CreatePickup
	#error _ALS_CreatePickup defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreatePickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
#define _ALS_CreatePickup
#define CreatePickup( FIXES_CreatePickup(

#if defined _ALS_DestroyPickup
	#error _ALS_DestroyPickup defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyPickup(pickup) = DestroyPickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyPickup(pickup) = DestroyPickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyPickup__(pickup) = DestroyPickup;
#define _ALS_DestroyPickup
#define DestroyPickup( FIXES_DestroyPickup(

#if defined _ALS_ShowNameTags
	#error _ALS_ShowNameTags defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ShowNameTags(show) = ShowNameTags;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ShowNameTags(_FIXES_MAYBE_BOOL:show) = ShowNameTags;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ShowNameTags__(bool:show) = ShowNameTags;
#define _ALS_ShowNameTags
#define ShowNameTags( FIXES_ShowNameTags(

#if defined _ALS_ShowPlayerMarkers
	#error _ALS_ShowPlayerMarkers defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ShowPlayerMarkers__(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
#define _ALS_ShowPlayerMarkers
#define ShowPlayerMarkers( FIXES_ShowPlayerMarkers(

#if defined _ALS_GameModeExit
	#error _ALS_GameModeExit defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GameModeExit() = GameModeExit;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GameModeExit() = GameModeExit;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GameModeExit__() = GameModeExit;
#define _ALS_GameModeExit
#define GameModeExit( FIXES_GameModeExit(

#if defined _ALS_SetWorldTime
	#error _ALS_SetWorldTime defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetWorldTime(hour) = SetWorldTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetWorldTime(hour) = SetWorldTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetWorldTime__(hour) = SetWorldTime;
#define _ALS_SetWorldTime
#define SetWorldTime( FIXES_SetWorldTime(

#if defined _ALS_GetWeaponName
	#error _ALS_GetWeaponName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetWeaponName(WEAPON:weaponid, const weapon[], len) = GetWeaponName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetWeaponName(WEAPON:weaponid, _FIXES_NOT_CONST weapon[], _FIXES_MAYBE_SIZEOF(len, weapon)) = GetWeaponName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetWeaponName__(WEAPON:weaponid, weapon[], len = sizeof (weapon)) = GetWeaponName;
#define _ALS_GetWeaponName
#define GetWeaponName( FIXES_GetWeaponName(

#if defined _ALS_EnableTirePopping
	#error _ALS_EnableTirePopping defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnableTirePopping(enable) = EnableTirePopping;
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnableTirePopping(_FIXES_MAYBE_BOOL:enable) = EnableTirePopping;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnableTirePopping__(bool:enable) = EnableTirePopping;
#define _ALS_EnableTirePopping
#define EnableTirePopping( FIXES_EnableTirePopping(

#if defined _ALS_EnableVehicleFriendlyFire
	#error _ALS_EnableVehicleFriendlyFire defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnableVehicleFriendlyFire__() = EnableVehicleFriendlyFire;
#define _ALS_EnableVehicleFriendlyFire
#define EnableVehicleFriendlyFire( FIXES_EnableVehicleFriendlyFire(

#if defined _ALS_AllowInteriorWeapons
	#error _ALS_AllowInteriorWeapons defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AllowInteriorWeapons(allow) = AllowInteriorWeapons;
#pragma deprecated Use `OnPlayerInteriorChange`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AllowInteriorWeapons(_FIXES_MAYBE_BOOL:allow) = AllowInteriorWeapons;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AllowInteriorWeapons__(bool:allow) = AllowInteriorWeapons;
#define _ALS_AllowInteriorWeapons
#define AllowInteriorWeapons( FIXES_AllowInteriorWeapons(

#if defined _ALS_SetWeather
	#error _ALS_SetWeather defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetWeather(weatherid) = SetWeather;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetWeather(weatherid) = SetWeather;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetWeather__(weatherid) = SetWeather;
#define _ALS_SetWeather
#define SetWeather( FIXES_SetWeather(

#if defined _ALS_GetGravity
	#error _ALS_GetGravity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetGravity() = GetGravity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetGravity() = GetGravity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetGravity__() = GetGravity;
#define _ALS_GetGravity
#define GetGravity( FIXES_GetGravity(

#if defined _ALS_SetGravity
	#error _ALS_SetGravity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetGravity(Float:gravity) = SetGravity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetGravity(Float:gravity) = SetGravity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetGravity__(Float:gravity) = SetGravity;
#define _ALS_SetGravity
#define SetGravity( FIXES_SetGravity(

#if defined _ALS_AllowAdminTeleport
	#error _ALS_AllowAdminTeleport defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AllowAdminTeleport(allow) = AllowAdminTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AllowAdminTeleport(_FIXES_MAYBE_BOOL:allow) = AllowAdminTeleport;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AllowAdminTeleport__(bool:allow) = AllowAdminTeleport;
#define _ALS_AllowAdminTeleport
#define AllowAdminTeleport( FIXES_AllowAdminTeleport(

#if defined _ALS_SetDeathDropAmount
	#error _ALS_SetDeathDropAmount defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetDeathDropAmount(amount) = SetDeathDropAmount;
#pragma deprecated Use `CreatePickup`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetDeathDropAmount(amount) = SetDeathDropAmount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetDeathDropAmount__(amount) = SetDeathDropAmount;
#define _ALS_SetDeathDropAmount
#define SetDeathDropAmount( FIXES_SetDeathDropAmount(

#if defined _ALS_CreateExplosion
	#error _ALS_CreateExplosion defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreateExplosion__(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
#define _ALS_CreateExplosion
#define CreateExplosion( FIXES_CreateExplosion(

#if defined _ALS_EnableZoneNames
	#error _ALS_EnableZoneNames defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_EnableZoneNames(enable) = EnableZoneNames;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_EnableZoneNames(_FIXES_MAYBE_BOOL:enable) = EnableZoneNames;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native EnableZoneNames__(bool:enable) = EnableZoneNames;
#define _ALS_EnableZoneNames
#define EnableZoneNames( FIXES_EnableZoneNames(

#if defined _ALS_UsePlayerPedAnims
	#error _ALS_UsePlayerPedAnims defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_UsePlayerPedAnims() = UsePlayerPedAnims;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_UsePlayerPedAnims() = UsePlayerPedAnims;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native UsePlayerPedAnims__() = UsePlayerPedAnims;
#define _ALS_UsePlayerPedAnims
#define UsePlayerPedAnims( FIXES_UsePlayerPedAnims(

native DisableInteriorEnterExits(); 
#if defined _ALS_SetNameTagDrawDistance
	#error _ALS_SetNameTagDrawDistance defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetNameTagDrawDistance__(Float:distance) = SetNameTagDrawDistance;
#define _ALS_SetNameTagDrawDistance
#define SetNameTagDrawDistance( FIXES_SetNameTagDrawDistance(

#if defined _ALS_DisableNameTagLOS
	#error _ALS_DisableNameTagLOS defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisableNameTagLOS() = DisableNameTagLOS;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisableNameTagLOS() = DisableNameTagLOS;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisableNameTagLOS__() = DisableNameTagLOS;
#define _ALS_DisableNameTagLOS
#define DisableNameTagLOS( FIXES_DisableNameTagLOS(

#if defined _ALS_LimitGlobalChatRadius
	#error _ALS_LimitGlobalChatRadius defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native LimitGlobalChatRadius__(Float:chatRadius) = LimitGlobalChatRadius;
#define _ALS_LimitGlobalChatRadius
#define LimitGlobalChatRadius( FIXES_LimitGlobalChatRadius(

#if defined _ALS_LimitPlayerMarkerRadius
	#error _ALS_LimitPlayerMarkerRadius defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native LimitPlayerMarkerRadius__(Float:markerRadius) = LimitPlayerMarkerRadius;
#define _ALS_LimitPlayerMarkerRadius
#define LimitPlayerMarkerRadius( FIXES_LimitPlayerMarkerRadius(

#if defined _ALS_ConnectNPC
	#error _ALS_ConnectNPC defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ConnectNPC(name[], script[]) = ConnectNPC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ConnectNPC(_FIXES_MAYBE_CONST name[], _FIXES_MAYBE_CONST script[]) = ConnectNPC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ConnectNPC__(const name[], const script[]) = ConnectNPC;
#define _ALS_ConnectNPC
#define ConnectNPC( FIXES_ConnectNPC(

#if defined _ALS_IsPlayerNPC
	#error _ALS_IsPlayerNPC defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerNPC(playerid) = IsPlayerNPC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerNPC(playerid) = IsPlayerNPC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerNPC__(playerid) = IsPlayerNPC;
#define _ALS_IsPlayerNPC
#define IsPlayerNPC( FIXES_IsPlayerNPC(

#if defined _ALS_AddCharModel
	#error _ALS_AddCharModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddCharModel(baseid, newid, dff[], textureLibrary[]) = AddCharModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddCharModel(baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddCharModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddCharModel__(baseid, newid, const dff[], const textureLibrary[]) = AddCharModel;
#define _ALS_AddCharModel
#define AddCharModel( FIXES_AddCharModel(

#if defined _ALS_AddSimpleModel
	#error _ALS_AddSimpleModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddSimpleModel(virtualWorld, baseid, newid, dff[], textureLibrary[]) = AddSimpleModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddSimpleModel(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddSimpleModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddSimpleModel__(virtualWorld, baseid, newid, const dff[], const textureLibrary[]) = AddSimpleModel;
#define _ALS_AddSimpleModel
#define AddSimpleModel( FIXES_AddSimpleModel(

#if defined _ALS_AddSimpleModelTimed
	#error _ALS_AddSimpleModelTimed defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddSimpleModelTimed(virtualWorld, baseid, newid, dff[], textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddSimpleModelTimed(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddSimpleModelTimed__(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
#define _ALS_AddSimpleModelTimed
#define AddSimpleModelTimed( FIXES_AddSimpleModelTimed(

#if defined _ALS_FindModelFileNameFromCRC
	#error _ALS_FindModelFileNameFromCRC defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_FindModelFileNameFromCRC(crc, output[], size) = FindModelFileNameFromCRC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_FindModelFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindModelFileNameFromCRC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native FindModelFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindModelFileNameFromCRC;
#define _ALS_FindModelFileNameFromCRC
#define FindModelFileNameFromCRC( FIXES_FindModelFileNameFromCRC(

#if defined _ALS_FindTextureFileNameFromCRC
	#error _ALS_FindTextureFileNameFromCRC defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_FindTextureFileNameFromCRC(crc, output[], size) = FindTextureFileNameFromCRC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_FindTextureFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindTextureFileNameFromCRC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native FindTextureFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindTextureFileNameFromCRC;
#define _ALS_FindTextureFileNameFromCRC
#define FindTextureFileNameFromCRC( FIXES_FindTextureFileNameFromCRC(

#if defined _ALS_RedirectDownload
	#error _ALS_RedirectDownload defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RedirectDownload(playerid, url[]) = RedirectDownload;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RedirectDownload(playerid, _FIXES_MAYBE_CONST url[]) = RedirectDownload;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RedirectDownload__(playerid, const url[]) = RedirectDownload;
#define _ALS_RedirectDownload
#define RedirectDownload( FIXES_RedirectDownload(

#if defined _ALS_IsPlayerAdmin
	#error _ALS_IsPlayerAdmin defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsPlayerAdmin(playerid) = IsPlayerAdmin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsPlayerAdmin(playerid) = IsPlayerAdmin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsPlayerAdmin__(playerid) = IsPlayerAdmin;
#define _ALS_IsPlayerAdmin
#define IsPlayerAdmin( FIXES_IsPlayerAdmin(

#if defined _ALS_Kick
	#error _ALS_Kick defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Kick(playerid) = Kick;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Kick(playerid) = Kick;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Kick__(playerid) = Kick;
#define _ALS_Kick
#define Kick( FIXES_Kick(

#if defined _ALS_Ban
	#error _ALS_Ban defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Ban(playerid) = Ban;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Ban(playerid) = Ban;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Ban__(playerid) = Ban;
#define _ALS_Ban
#define Ban( FIXES_Ban(

#if defined _ALS_BanEx
	#error _ALS_BanEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_BanEx(playerid, const reason[]) = BanEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_BanEx(playerid, const reason[]) = BanEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native BanEx__(playerid, const reason[]) = BanEx;
#define _ALS_BanEx
#define BanEx( FIXES_BanEx(

#if defined _ALS_SendRconCommand
	#error _ALS_SendRconCommand defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SendRconCommand(command[]) = SendRconCommand;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SendRconCommand(_FIXES_MAYBE_CONST command[]) = SendRconCommand;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SendRconCommand__(const command[]) = SendRconCommand;
#define _ALS_SendRconCommand
#define SendRconCommand( FIXES_SendRconCommand(

#if defined _ALS_GetPlayerNetworkStats
	#error _ALS_GetPlayerNetworkStats defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerNetworkStats(playerid, output[], size) = GetPlayerNetworkStats;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerNetworkStats(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPlayerNetworkStats;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerNetworkStats__(playerid, output[], size = sizeof (output)) = GetPlayerNetworkStats;
#define _ALS_GetPlayerNetworkStats
#define GetPlayerNetworkStats( FIXES_GetPlayerNetworkStats(

#if defined _ALS_GetNetworkStats
	#error _ALS_GetNetworkStats defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetNetworkStats(output[], size) = GetNetworkStats;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetNetworkStats(output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetNetworkStats;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetNetworkStats__(output[], size = sizeof (output)) = GetNetworkStats;
#define _ALS_GetNetworkStats
#define GetNetworkStats( FIXES_GetNetworkStats(

#if defined _ALS_GetPlayerVersion
	#error _ALS_GetPlayerVersion defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetPlayerVersion(playerid, const version[], len) = GetPlayerVersion;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetPlayerVersion(playerid, _FIXES_NOT_CONST version[], _FIXES_MAYBE_SIZEOF(len, version)) = GetPlayerVersion;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetPlayerVersion__(playerid, version[], len = sizeof (version)) = GetPlayerVersion;
#define _ALS_GetPlayerVersion
#define GetPlayerVersion( FIXES_GetPlayerVersion(

#if defined _ALS_BlockIpAddress
	#error _ALS_BlockIpAddress defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_BlockIpAddress(ipAddress[], timeMS) = BlockIpAddress;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_BlockIpAddress(_FIXES_MAYBE_CONST ipAddress[], timeMS) = BlockIpAddress;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native BlockIpAddress__(const ipAddress[], timeMS) = BlockIpAddress;
#define _ALS_BlockIpAddress
#define BlockIpAddress( FIXES_BlockIpAddress(

#if defined _ALS_UnBlockIpAddress
	#error _ALS_UnBlockIpAddress defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_UnBlockIpAddress(ipAddress[]) = UnBlockIpAddress;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_UnBlockIpAddress(_FIXES_MAYBE_CONST ipAddress[]) = UnBlockIpAddress;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native UnBlockIpAddress__(const ipAddress[]) = UnBlockIpAddress;
#define _ALS_UnBlockIpAddress
#define UnBlockIpAddress( FIXES_UnBlockIpAddress(

#if defined _ALS_GetServerVarAsString
	#error _ALS_GetServerVarAsString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetServerVarAsString(const cvar[], buffer[], len) = GetServerVarAsString;
#pragma deprecated Use `GetConsoleVarAsString`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetServerVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetServerVarAsString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetServerVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetServerVarAsString;
#define _ALS_GetServerVarAsString
#define GetServerVarAsString( FIXES_GetServerVarAsString(

#if defined _ALS_GetServerVarAsInt
	#error _ALS_GetServerVarAsInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
#pragma deprecated Use `GetConsoleVarAsInt`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetServerVarAsInt__(const cvar[]) = GetServerVarAsInt;
#define _ALS_GetServerVarAsInt
#define GetServerVarAsInt( FIXES_GetServerVarAsInt(

#if defined _ALS_GetServerVarAsBool
	#error _ALS_GetServerVarAsBool defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
#pragma deprecated Use `GetConsoleVarAsBool`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:GetServerVarAsBool__(const cvar[]) = GetServerVarAsBool;
#define _ALS_GetServerVarAsBool
#define GetServerVarAsBool( FIXES_GetServerVarAsBool(

#if defined _ALS_GetConsoleVarAsString
	#error _ALS_GetConsoleVarAsString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetConsoleVarAsString(const cvar[], buffer[], len) = GetConsoleVarAsString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetConsoleVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetConsoleVarAsString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetConsoleVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetConsoleVarAsString;
#define _ALS_GetConsoleVarAsString
#define GetConsoleVarAsString( FIXES_GetConsoleVarAsString(

#if defined _ALS_GetConsoleVarAsInt
	#error _ALS_GetConsoleVarAsInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetConsoleVarAsInt__(const cvar[]) = GetConsoleVarAsInt;
#define _ALS_GetConsoleVarAsInt
#define GetConsoleVarAsInt( FIXES_GetConsoleVarAsInt(

#if defined _ALS_GetConsoleVarAsBool
	#error _ALS_GetConsoleVarAsBool defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:GetConsoleVarAsBool__(const cvar[]) = GetConsoleVarAsBool;
#define _ALS_GetConsoleVarAsBool
#define GetConsoleVarAsBool( FIXES_GetConsoleVarAsBool(

#if defined _ALS_GetServerTickRate
	#error _ALS_GetServerTickRate defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetServerTickRate() = GetServerTickRate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetServerTickRate() = GetServerTickRate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetServerTickRate__() = GetServerTickRate;
#define _ALS_GetServerTickRate
#define GetServerTickRate( FIXES_GetServerTickRate(

#if defined _ALS_NetStats_GetConnectedTime
	#error _ALS_NetStats_GetConnectedTime defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_GetConnectedTime__(playerid) = NetStats_GetConnectedTime;
#define _ALS_NetStats_GetConnectedTime
#define NetStats_GetConnectedTime( FIXES_NetStats_GetConnectedTime(

#if defined _ALS_NetStats_MessagesReceived
	#error _ALS_NetStats_MessagesReceived defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_MessagesReceived__(playerid) = NetStats_MessagesReceived;
#define _ALS_NetStats_MessagesReceived
#define NetStats_MessagesReceived( FIXES_NetStats_MessagesReceived(

#if defined _ALS_NetStats_BytesReceived
	#error _ALS_NetStats_BytesReceived defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_BytesReceived__(playerid) = NetStats_BytesReceived;
#define _ALS_NetStats_BytesReceived
#define NetStats_BytesReceived( FIXES_NetStats_BytesReceived(

#if defined _ALS_NetStats_MessagesSent
	#error _ALS_NetStats_MessagesSent defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_MessagesSent__(playerid) = NetStats_MessagesSent;
#define _ALS_NetStats_MessagesSent
#define NetStats_MessagesSent( FIXES_NetStats_MessagesSent(

#if defined _ALS_NetStats_BytesSent
	#error _ALS_NetStats_BytesSent defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_BytesSent(playerid) = NetStats_BytesSent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_BytesSent(playerid) = NetStats_BytesSent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_BytesSent__(playerid) = NetStats_BytesSent;
#define _ALS_NetStats_BytesSent
#define NetStats_BytesSent( FIXES_NetStats_BytesSent(

#if defined _ALS_NetStats_MessagesRecvPerSecond
	#error _ALS_NetStats_MessagesRecvPerSecond defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_MessagesRecvPerSecond__(playerid) = NetStats_MessagesRecvPerSecond;
#define _ALS_NetStats_MessagesRecvPerSecond
#define NetStats_MessagesRecvPerSecond( FIXES_NetStats_MessagesRecvPerSecond(

#if defined _ALS_NetStats_PacketLossPercent
	#error _ALS_NetStats_PacketLossPercent defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:NetStats_PacketLossPercent__(playerid) = NetStats_PacketLossPercent;
#define _ALS_NetStats_PacketLossPercent
#define NetStats_PacketLossPercent( FIXES_NetStats_PacketLossPercent(

#if defined _ALS_NetStats_ConnectionStatus
	#error _ALS_NetStats_ConnectionStatus defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_ConnectionStatus__(playerid) = NetStats_ConnectionStatus;
#define _ALS_NetStats_ConnectionStatus
#define NetStats_ConnectionStatus( FIXES_NetStats_ConnectionStatus(

#if defined _ALS_NetStats_GetIpPort
	#error _ALS_NetStats_GetIpPort defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_NetStats_GetIpPort(playerid, output[], size) = NetStats_GetIpPort;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_NetStats_GetIpPort(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = NetStats_GetIpPort;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native NetStats_GetIpPort__(playerid, output[], size = sizeof (output)) = NetStats_GetIpPort;
#define _ALS_NetStats_GetIpPort
#define NetStats_GetIpPort( FIXES_NetStats_GetIpPort(

#if defined _ALS_CreateMenu
	#error _ALS_CreateMenu defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Menu:BAD_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Menu:FIXES_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Menu:CreateMenu__(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
#define _ALS_CreateMenu
#define CreateMenu( FIXES_CreateMenu(

#if defined _ALS_DestroyMenu
	#error _ALS_DestroyMenu defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyMenu(Menu:menuid) = DestroyMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyMenu(Menu:menuid) = DestroyMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyMenu__(Menu:menuid) = DestroyMenu;
#define _ALS_DestroyMenu
#define DestroyMenu( FIXES_DestroyMenu(

#if defined _ALS_AddMenuItem
	#error _ALS_AddMenuItem defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddMenuItem__(Menu:menuid, column, const text[]) = AddMenuItem;
#define _ALS_AddMenuItem
#define AddMenuItem( FIXES_AddMenuItem(

#if defined _ALS_SetMenuColumnHeader
	#error _ALS_SetMenuColumnHeader defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetMenuColumnHeader__(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
#define _ALS_SetMenuColumnHeader
#define SetMenuColumnHeader( FIXES_SetMenuColumnHeader(

#if defined _ALS_ShowMenuForPlayer
	#error _ALS_ShowMenuForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ShowMenuForPlayer__(Menu:menuid, playerid) = ShowMenuForPlayer;
#define _ALS_ShowMenuForPlayer
#define ShowMenuForPlayer( FIXES_ShowMenuForPlayer(

#if defined _ALS_HideMenuForPlayer
	#error _ALS_HideMenuForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native HideMenuForPlayer__(Menu:menuid, playerid) = HideMenuForPlayer;
#define _ALS_HideMenuForPlayer
#define HideMenuForPlayer( FIXES_HideMenuForPlayer(

#if defined _ALS_IsValidMenu
	#error _ALS_IsValidMenu defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsValidMenu(Menu:menuid) = IsValidMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsValidMenu(Menu:menuid) = IsValidMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsValidMenu__(Menu:menuid) = IsValidMenu;
#define _ALS_IsValidMenu
#define IsValidMenu( FIXES_IsValidMenu(

#if defined _ALS_DisableMenu
	#error _ALS_DisableMenu defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisableMenu(Menu:menuid) = DisableMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisableMenu(Menu:menuid) = DisableMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisableMenu__(Menu:menuid) = DisableMenu;
#define _ALS_DisableMenu
#define DisableMenu( FIXES_DisableMenu(

#if defined _ALS_DisableMenuRow
	#error _ALS_DisableMenuRow defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DisableMenuRow__(Menu:menuid, row) = DisableMenuRow;
#define _ALS_DisableMenuRow
#define DisableMenuRow( FIXES_DisableMenuRow(

#if defined _ALS_GetPlayerMenu
	#error _ALS_GetPlayerMenu defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Menu:BAD_GetPlayerMenu(playerid) = GetPlayerMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Menu:FIXES_GetPlayerMenu(playerid) = GetPlayerMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Menu:GetPlayerMenu__(playerid) = GetPlayerMenu;
#define _ALS_GetPlayerMenu
#define GetPlayerMenu( FIXES_GetPlayerMenu(

#if defined _ALS_TextDrawCreate
	#error _ALS_TextDrawCreate defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Text:FIXES_TextDrawCreate(Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = TextDrawCreate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Text:TextDrawCreate__(Float:x, Float:y, const text[]) = TextDrawCreate;
#define _ALS_TextDrawCreate
#define TextDrawCreate( FIXES_TextDrawCreate(

#if defined _ALS_TextDrawDestroy
	#error _ALS_TextDrawDestroy defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawDestroy(Text:text) = TextDrawDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawDestroy(Text:text) = TextDrawDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawDestroy__(Text:text) = TextDrawDestroy;
#define _ALS_TextDrawDestroy
#define TextDrawDestroy( FIXES_TextDrawDestroy(

#if defined _ALS_TextDrawLetterSize
	#error _ALS_TextDrawLetterSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawLetterSize__(Text:text, Float:width, Float:height) = TextDrawLetterSize;
#define _ALS_TextDrawLetterSize
#define TextDrawLetterSize( FIXES_TextDrawLetterSize(

#if defined _ALS_TextDrawTextSize
	#error _ALS_TextDrawTextSize defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawTextSize__(Text:text, Float:width, Float:height) = TextDrawTextSize;
#define _ALS_TextDrawTextSize
#define TextDrawTextSize( FIXES_TextDrawTextSize(

#if defined _ALS_TextDrawAlignment
	#error _ALS_TextDrawAlignment defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawAlignment__(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
#define _ALS_TextDrawAlignment
#define TextDrawAlignment( FIXES_TextDrawAlignment(

#if defined _ALS_TextDrawColor
	#error _ALS_TextDrawColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawColor(Text:text, colour) = TextDrawColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawColor(Text:text, colour) = TextDrawColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawColor__(Text:text, colour) = TextDrawColor;
#define _ALS_TextDrawColor
#define TextDrawColor( FIXES_TextDrawColor(

#if defined _ALS_TextDrawUseBox
	#error _ALS_TextDrawUseBox defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawUseBox(Text:text, use) = TextDrawUseBox;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawUseBox(Text:text, _FIXES_MAYBE_BOOL:use) = TextDrawUseBox;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawUseBox__(Text:text, bool:use) = TextDrawUseBox;
#define _ALS_TextDrawUseBox
#define TextDrawUseBox( FIXES_TextDrawUseBox(

#if defined _ALS_TextDrawBoxColor
	#error _ALS_TextDrawBoxColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawBoxColor__(Text:text, colour) = TextDrawBoxColor;
#define _ALS_TextDrawBoxColor
#define TextDrawBoxColor( FIXES_TextDrawBoxColor(

#if defined _ALS_TextDrawSetShadow
	#error _ALS_TextDrawSetShadow defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetShadow__(Text:text, size) = TextDrawSetShadow;
#define _ALS_TextDrawSetShadow
#define TextDrawSetShadow( FIXES_TextDrawSetShadow(

#if defined _ALS_TextDrawSetOutline
	#error _ALS_TextDrawSetOutline defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetOutline__(Text:text, size) = TextDrawSetOutline;
#define _ALS_TextDrawSetOutline
#define TextDrawSetOutline( FIXES_TextDrawSetOutline(

#if defined _ALS_TextDrawBackgroundColor
	#error _ALS_TextDrawBackgroundColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawBackgroundColor__(Text:text, colour) = TextDrawBackgroundColor;
#define _ALS_TextDrawBackgroundColor
#define TextDrawBackgroundColor( FIXES_TextDrawBackgroundColor(

#if defined _ALS_TextDrawFont
	#error _ALS_TextDrawFont defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawFont__(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
#define _ALS_TextDrawFont
#define TextDrawFont( FIXES_TextDrawFont(

#if defined _ALS_TextDrawSetProportional
	#error _ALS_TextDrawSetProportional defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetProportional(Text:text, set) = TextDrawSetProportional;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetProportional(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetProportional;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetProportional__(Text:text, bool:set) = TextDrawSetProportional;
#define _ALS_TextDrawSetProportional
#define TextDrawSetProportional( FIXES_TextDrawSetProportional(

#if defined _ALS_TextDrawSetSelectable
	#error _ALS_TextDrawSetSelectable defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetSelectable(Text:text, set) = TextDrawSetSelectable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetSelectable(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetSelectable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetSelectable__(Text:text, bool:set) = TextDrawSetSelectable;
#define _ALS_TextDrawSetSelectable
#define TextDrawSetSelectable( FIXES_TextDrawSetSelectable(

#if defined _ALS_TextDrawShowForPlayer
	#error _ALS_TextDrawShowForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawShowForPlayer__(playerid, Text:text) = TextDrawShowForPlayer;
#define _ALS_TextDrawShowForPlayer
#define TextDrawShowForPlayer( FIXES_TextDrawShowForPlayer(

#if defined _ALS_TextDrawHideForPlayer
	#error _ALS_TextDrawHideForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawHideForPlayer__(playerid, Text:text) = TextDrawHideForPlayer;
#define _ALS_TextDrawHideForPlayer
#define TextDrawHideForPlayer( FIXES_TextDrawHideForPlayer(

#if defined _ALS_TextDrawShowForAll
	#error _ALS_TextDrawShowForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawShowForAll__(Text:text) = TextDrawShowForAll;
#define _ALS_TextDrawShowForAll
#define TextDrawShowForAll( FIXES_TextDrawShowForAll(

#if defined _ALS_TextDrawHideForAll
	#error _ALS_TextDrawHideForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawHideForAll__(Text:text) = TextDrawHideForAll;
#define _ALS_TextDrawHideForAll
#define TextDrawHideForAll( FIXES_TextDrawHideForAll(

#if defined _ALS_TextDrawSetString
	#error _ALS_TextDrawSetString defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetString(Text:text, _FIXES_MAYBE_CONST string[]) = TextDrawSetString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetString__(Text:text, const string[]) = TextDrawSetString;
#define _ALS_TextDrawSetString
#define TextDrawSetString( FIXES_TextDrawSetString(

#if defined _ALS_TextDrawSetPreviewModel
	#error _ALS_TextDrawSetPreviewModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetPreviewModel__(Text:text, modelIndex) = TextDrawSetPreviewModel;
#define _ALS_TextDrawSetPreviewModel
#define TextDrawSetPreviewModel( FIXES_TextDrawSetPreviewModel(

#if defined _ALS_TextDrawSetPreviewRot
	#error _ALS_TextDrawSetPreviewRot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetPreviewRot__(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
#define _ALS_TextDrawSetPreviewRot
#define TextDrawSetPreviewRot( FIXES_TextDrawSetPreviewRot(

#if defined _ALS_TextDrawSetPreviewVehCol
	#error _ALS_TextDrawSetPreviewVehCol defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native TextDrawSetPreviewVehCol__(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
#define _ALS_TextDrawSetPreviewVehCol
#define TextDrawSetPreviewVehCol( FIXES_TextDrawSetPreviewVehCol(

#if defined _ALS_GangZoneCreate
	#error _ALS_GangZoneCreate defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneCreate__(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
#define _ALS_GangZoneCreate
#define GangZoneCreate( FIXES_GangZoneCreate(

#if defined _ALS_GangZoneDestroy
	#error _ALS_GangZoneDestroy defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneDestroy(zone) = GangZoneDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneDestroy(zone) = GangZoneDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneDestroy__(zone) = GangZoneDestroy;
#define _ALS_GangZoneDestroy
#define GangZoneDestroy( FIXES_GangZoneDestroy(

#if defined _ALS_GangZoneShowForPlayer
	#error _ALS_GangZoneShowForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneShowForPlayer__(playerid, zone, colour) = GangZoneShowForPlayer;
#define _ALS_GangZoneShowForPlayer
#define GangZoneShowForPlayer( FIXES_GangZoneShowForPlayer(

#if defined _ALS_GangZoneShowForAll
	#error _ALS_GangZoneShowForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneShowForAll__(zone, colour) = GangZoneShowForAll;
#define _ALS_GangZoneShowForAll
#define GangZoneShowForAll( FIXES_GangZoneShowForAll(

#if defined _ALS_GangZoneHideForPlayer
	#error _ALS_GangZoneHideForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneHideForPlayer__(playerid, zone) = GangZoneHideForPlayer;
#define _ALS_GangZoneHideForPlayer
#define GangZoneHideForPlayer( FIXES_GangZoneHideForPlayer(

#if defined _ALS_GangZoneHideForAll
	#error _ALS_GangZoneHideForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneHideForAll(zone) = GangZoneHideForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneHideForAll(zone) = GangZoneHideForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneHideForAll__(zone) = GangZoneHideForAll;
#define _ALS_GangZoneHideForAll
#define GangZoneHideForAll( FIXES_GangZoneHideForAll(

#if defined _ALS_GangZoneFlashForPlayer
	#error _ALS_GangZoneFlashForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneFlashForPlayer__(playerid, zone, flashColour) = GangZoneFlashForPlayer;
#define _ALS_GangZoneFlashForPlayer
#define GangZoneFlashForPlayer( FIXES_GangZoneFlashForPlayer(

#if defined _ALS_GangZoneFlashForAll
	#error _ALS_GangZoneFlashForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneFlashForAll__(zone, flashColour) = GangZoneFlashForAll;
#define _ALS_GangZoneFlashForAll
#define GangZoneFlashForAll( FIXES_GangZoneFlashForAll(

#if defined _ALS_GangZoneStopFlashForPlayer
	#error _ALS_GangZoneStopFlashForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneStopFlashForPlayer__(playerid, zone) = GangZoneStopFlashForPlayer;
#define _ALS_GangZoneStopFlashForPlayer
#define GangZoneStopFlashForPlayer( FIXES_GangZoneStopFlashForPlayer(

#if defined _ALS_GangZoneStopFlashForAll
	#error _ALS_GangZoneStopFlashForAll defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GangZoneStopFlashForAll__(zone) = GangZoneStopFlashForAll;
#define _ALS_GangZoneStopFlashForAll
#define GangZoneStopFlashForAll( FIXES_GangZoneStopFlashForAll(

#if defined _ALS_Create3DTextLabel
	#error _ALS_Create3DTextLabel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Text3D:BAD_Create3DTextLabel(text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, testLOS = false) = Create3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Text3D:FIXES_Create3DTextLabel(_FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, _FIXES_MAYBE_BOOL:testLOS = false) = Create3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Text3D:Create3DTextLabel__(const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, bool:testLOS = false) = Create3DTextLabel;
#define _ALS_Create3DTextLabel
#define Create3DTextLabel( FIXES_Create3DTextLabel(

#if defined _ALS_Delete3DTextLabel
	#error _ALS_Delete3DTextLabel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Delete3DTextLabel__(Text3D:textid) = Delete3DTextLabel;
#define _ALS_Delete3DTextLabel
#define Delete3DTextLabel( FIXES_Delete3DTextLabel(

#if defined _ALS_Attach3DTextLabelToPlayer
	#error _ALS_Attach3DTextLabelToPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Attach3DTextLabelToPlayer__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
#define _ALS_Attach3DTextLabelToPlayer
#define Attach3DTextLabelToPlayer( FIXES_Attach3DTextLabelToPlayer(

#if defined _ALS_Attach3DTextLabelToVehicle
	#error _ALS_Attach3DTextLabelToVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Attach3DTextLabelToVehicle__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
#define _ALS_Attach3DTextLabelToVehicle
#define Attach3DTextLabelToVehicle( FIXES_Attach3DTextLabelToVehicle(

#if defined _ALS_Update3DTextLabelText
	#error _ALS_Update3DTextLabelText defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_Update3DTextLabelText(Text3D:textid, colour, text[]) = Update3DTextLabelText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_Update3DTextLabelText(Text3D:textid, colour, _FIXES_MAYBE_CONST text[]) = Update3DTextLabelText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Update3DTextLabelText__(Text3D:textid, colour, const text[]) = Update3DTextLabelText;
#define _ALS_Update3DTextLabelText
#define Update3DTextLabelText( FIXES_Update3DTextLabelText(

#if defined _ALS_CreatePlayer3DTextLabel
	#error _ALS_CreatePlayer3DTextLabel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native PlayerText3D:BAD_CreatePlayer3DTextLabel(playerid, text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, testLOS = false) = CreatePlayer3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native PlayerText3D:FIXES_CreatePlayer3DTextLabel(playerid, _FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, _FIXES_MAYBE_BOOL:testLOS = false) = CreatePlayer3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native PlayerText3D:CreatePlayer3DTextLabel__(playerid, const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, bool:testLOS = false) = CreatePlayer3DTextLabel;
#define _ALS_CreatePlayer3DTextLabel
#define CreatePlayer3DTextLabel( FIXES_CreatePlayer3DTextLabel(

#if defined _ALS_DeletePlayer3DTextLabel
	#error _ALS_DeletePlayer3DTextLabel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DeletePlayer3DTextLabel__(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
#define _ALS_DeletePlayer3DTextLabel
#define DeletePlayer3DTextLabel( FIXES_DeletePlayer3DTextLabel(

#if defined _ALS_UpdatePlayer3DTextLabelText
	#error _ALS_UpdatePlayer3DTextLabelText defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, text[]) = UpdatePlayer3DTextLabelText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, _FIXES_MAYBE_CONST text[]) = UpdatePlayer3DTextLabelText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native UpdatePlayer3DTextLabelText__(playerid, PlayerText3D:textid, colour, const text[]) = UpdatePlayer3DTextLabelText;
#define _ALS_UpdatePlayer3DTextLabelText
#define UpdatePlayer3DTextLabelText( FIXES_UpdatePlayer3DTextLabelText(

#if defined _ALS_ShowPlayerDialog
	#error _ALS_ShowPlayerDialog defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, caption[], info[], button1[], button2[]) = ShowPlayerDialog;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, _FIXES_MAYBE_CONST caption[], _FIXES_MAYBE_CONST info[], _FIXES_MAYBE_CONST button1[], _FIXES_MAYBE_CONST button2[]) = ShowPlayerDialog;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ShowPlayerDialog__(playerid, dialogid, DIALOG_STYLE:style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
#define _ALS_ShowPlayerDialog
#define ShowPlayerDialog( FIXES_ShowPlayerDialog(

#if defined _ALS_gpci
	#error _ALS_gpci defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_gpci(playerid, serial[], len) = gpci;
#if FIX_camel_case
	#pragma deprecated Use `GPCI`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_gpci(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native gpci__(playerid, serial[], len = sizeof (serial)) = gpci;
#define _ALS_gpci
#define gpci( FIXES_gpci(

#if defined _ALS_GPCI
	#error _ALS_GPCI defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GPCI(playerid, serial[], len) = gpci;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GPCI(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GPCI__(playerid, serial[], len = sizeof (serial)) = gpci;
#define _ALS_GPCI
#define GPCI( FIXES_GPCI(

/*

     █████          ███████  █████  ███    ███ ██████  ██████  ██████
    ██   ██         ██      ██   ██ ████  ████ ██   ██ ██   ██ ██   ██
    ███████         ███████ ███████ ██ ████ ██ ██████  ██   ██ ██████
    ██   ██              ██ ██   ██ ██  ██  ██ ██      ██   ██ ██   ██
    ██   ██ ███████ ███████ ██   ██ ██      ██ ██      ██████  ██████

*/

#if defined _ALS_db_open
	#error _ALS_db_open defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native DB:BAD_db_open(name[]) = db_open;
#if FIX_camel_case
	#pragma deprecated Use `DB_Open`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native DB:FIXES_db_open(_FIXES_MAYBE_CONST name[]) = db_open;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB:db_open__(const name[]) = db_open;
#define _ALS_db_open
#define db_open( FIXES_db_open(

#if defined _ALS_DB_Open
	#error _ALS_DB_Open defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native DB:BAD_DB_Open(name[]) = db_open;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native DB:FIXES_DB_Open(_FIXES_MAYBE_CONST name[]) = db_open;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB:DB_Open__(const name[]) = db_open;
#define _ALS_DB_Open
#define DB_Open( FIXES_DB_Open(

#if defined _ALS_db_close
	#error _ALS_db_close defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_close(DB:db) = db_close;
#if FIX_camel_case
	#pragma deprecated Use `DB_Close`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_close(DB:db) = db_close;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_close__(DB:db) = db_close;
#define _ALS_db_close
#define db_close( FIXES_db_close(

#if defined _ALS_DB_Close
	#error _ALS_DB_Close defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_Close(DB:db) = db_close;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_Close(DB:db) = db_close;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_Close__(DB:db) = db_close;
#define _ALS_DB_Close
#define DB_Close( FIXES_DB_Close(

#if defined _ALS_db_query
	#error _ALS_db_query defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native DBResult:BAD_db_query(DB:db, query[]) = db_query;
#if FIX_camel_case
	#pragma deprecated Use `DB_Query`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native DBResult:FIXES_db_query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DBResult:db_query__(DB:db, const query[]) = db_query;
#define _ALS_db_query
#define db_query( FIXES_db_query(

#if defined _ALS_DB_Query
	#error _ALS_DB_Query defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native DBResult:BAD_DB_Query(DB:db, query[]) = db_query;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native DBResult:FIXES_DB_Query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DBResult:DB_Query__(DB:db, const query[]) = db_query;
#define _ALS_DB_Query
#define DB_Query( FIXES_DB_Query(

#if defined _ALS_db_free_result
	#error _ALS_db_free_result defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_free_result(DBResult:result) = db_free_result;
#if FIX_camel_case
	#pragma deprecated Use `DB_FreeResult`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_free_result(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_free_result__(DBResult:result) = db_free_result;
#define _ALS_db_free_result
#define db_free_result( FIXES_db_free_result(

#if defined _ALS_DB_FreeResult
	#error _ALS_DB_FreeResult defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_FreeResult(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_FreeResult(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_FreeResult__(DBResult:result) = db_free_result;
#define _ALS_DB_FreeResult
#define DB_FreeResult( FIXES_DB_FreeResult(

#if defined _ALS_db_num_rows
	#error _ALS_db_num_rows defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_num_rows(DBResult:result) = db_num_rows;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumRows`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_num_rows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_num_rows__(DBResult:result) = db_num_rows;
#define _ALS_db_num_rows
#define db_num_rows( FIXES_db_num_rows(

#if defined _ALS_DB_NumRows
	#error _ALS_DB_NumRows defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_NumRows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_NumRows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_NumRows__(DBResult:result) = db_num_rows;
#define _ALS_DB_NumRows
#define DB_NumRows( FIXES_DB_NumRows(

#if defined _ALS_db_next_row
	#error _ALS_db_next_row defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_next_row(DBResult:result) = db_next_row;
#if FIX_camel_case
	#pragma deprecated Use `DB_NextRow`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_next_row(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_next_row__(DBResult:result) = db_next_row;
#define _ALS_db_next_row
#define db_next_row( FIXES_db_next_row(

#if defined _ALS_DB_NextRow
	#error _ALS_DB_NextRow defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_NextRow(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_NextRow(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_NextRow__(DBResult:result) = db_next_row;
#define _ALS_DB_NextRow
#define DB_NextRow( FIXES_DB_NextRow(

#if defined _ALS_db_num_fields
	#error _ALS_db_num_fields defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_num_fields(DBResult:result) = db_num_fields;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumFields`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_num_fields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_num_fields__(DBResult:result) = db_num_fields;
#define _ALS_db_num_fields
#define db_num_fields( FIXES_db_num_fields(

#if defined _ALS_DB_NumFields
	#error _ALS_DB_NumFields defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_NumFields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_NumFields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_NumFields__(DBResult:result) = db_num_fields;
#define _ALS_DB_NumFields
#define DB_NumFields( FIXES_DB_NumFields(

#if defined _ALS_db_field_name
	#error _ALS_db_field_name defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_field_name(DBResult:result, field, output[], size) = db_field_name;
#if FIX_camel_case
	#pragma deprecated Use `DB_FieldName`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_field_name(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_field_name__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#define _ALS_db_field_name
#define db_field_name( FIXES_db_field_name(

#if defined _ALS_DB_FieldName
	#error _ALS_DB_FieldName defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_FieldName(DBResult:result, field, output[], size) = db_field_name;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_FieldName(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_FieldName__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#define _ALS_DB_FieldName
#define DB_FieldName( FIXES_DB_FieldName(

#if defined _ALS_db_get_field
	#error _ALS_db_get_field defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_field(DBResult:result, field, output[], size) = db_get_field;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetField`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_get_field(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_get_field__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#define _ALS_db_get_field
#define db_get_field( FIXES_db_get_field(

#if defined _ALS_DB_GetField
	#error _ALS_DB_GetField defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetField(DBResult:result, field, output[], size) = db_get_field;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_GetField(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_GetField__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#define _ALS_DB_GetField
#define DB_GetField( FIXES_DB_GetField(

#if defined _ALS_db_get_field_int
	#error _ALS_db_get_field_int defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldInt`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_get_field_int__(DBResult:result, field = 0) = db_get_field_int;
#define _ALS_db_get_field_int
#define db_get_field_int( FIXES_db_get_field_int(

#if defined _ALS_DB_GetFieldInt
	#error _ALS_DB_GetFieldInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_GetFieldInt__(DBResult:result, field = 0) = db_get_field_int;
#define _ALS_DB_GetFieldInt
#define DB_GetFieldInt( FIXES_DB_GetFieldInt(

#if defined _ALS_db_get_field_float
	#error _ALS_db_get_field_float defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldFloat`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:db_get_field_float__(DBResult:result, field = 0) = db_get_field_float;
#define _ALS_db_get_field_float
#define db_get_field_float( FIXES_db_get_field_float(

#if defined _ALS_DB_GetFieldFloat
	#error _ALS_DB_GetFieldFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:DB_GetFieldFloat__(DBResult:result, field = 0) = db_get_field_float;
#define _ALS_DB_GetFieldFloat
#define DB_GetFieldFloat( FIXES_DB_GetFieldFloat(

#if defined _ALS_db_get_field_assoc
	#error _ALS_db_get_field_assoc defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_field_assoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssoc`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_db_get_field_assoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:db_get_field_assoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#define _ALS_db_get_field_assoc
#define db_get_field_assoc( FIXES_db_get_field_assoc(

#if defined _ALS_DB_GetFieldAssoc
	#error _ALS_DB_GetFieldAssoc defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetFieldAssoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_DB_GetFieldAssoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:DB_GetFieldAssoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#define _ALS_DB_GetFieldAssoc
#define DB_GetFieldAssoc( FIXES_DB_GetFieldAssoc(

#if defined _ALS_db_get_field_assoc_int
	#error _ALS_db_get_field_assoc_int defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_field_assoc_int(DBResult:result, field[]) = db_get_field_assoc_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocInt`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_get_field_assoc_int(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_get_field_assoc_int__(DBResult:result, const field[]) = db_get_field_assoc_int;
#define _ALS_db_get_field_assoc_int
#define db_get_field_assoc_int( FIXES_db_get_field_assoc_int(

#if defined _ALS_DB_GetFieldAssocInt
	#error _ALS_DB_GetFieldAssocInt defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetFieldAssocInt(DBResult:result, field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_GetFieldAssocInt(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_GetFieldAssocInt__(DBResult:result, const field[]) = db_get_field_assoc_int;
#define _ALS_DB_GetFieldAssocInt
#define DB_GetFieldAssocInt( FIXES_DB_GetFieldAssocInt(

#if defined _ALS_db_get_field_assoc_float
	#error _ALS_db_get_field_assoc_float defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_db_get_field_assoc_float(DBResult:result, field[]) = db_get_field_assoc_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocFloat`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_db_get_field_assoc_float(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:db_get_field_assoc_float__(DBResult:result, const field[]) = db_get_field_assoc_float;
#define _ALS_db_get_field_assoc_float
#define db_get_field_assoc_float( FIXES_db_get_field_assoc_float(

#if defined _ALS_DB_GetFieldAssocFloat
	#error _ALS_DB_GetFieldAssocFloat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_DB_GetFieldAssocFloat(DBResult:result, field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_DB_GetFieldAssocFloat(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:DB_GetFieldAssocFloat__(DBResult:result, const field[]) = db_get_field_assoc_float;
#define _ALS_DB_GetFieldAssocFloat
#define DB_GetFieldAssocFloat( FIXES_DB_GetFieldAssocFloat(

#if defined _ALS_db_get_mem_handle
	#error _ALS_db_get_mem_handle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_mem_handle(DB:db) = db_get_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetMemHandle`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_get_mem_handle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_get_mem_handle__(DB:db) = db_get_mem_handle;
#define _ALS_db_get_mem_handle
#define db_get_mem_handle( FIXES_db_get_mem_handle(

#if defined _ALS_DB_GetMemHandle
	#error _ALS_DB_GetMemHandle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetMemHandle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_GetMemHandle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_GetMemHandle__(DB:db) = db_get_mem_handle;
#define _ALS_DB_GetMemHandle
#define DB_GetMemHandle( FIXES_DB_GetMemHandle(

#if defined _ALS_db_get_result_mem_handle
	#error _ALS_db_get_result_mem_handle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetResultMemHandle`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_get_result_mem_handle__(DBResult:result) = db_get_result_mem_handle;
#define _ALS_db_get_result_mem_handle
#define db_get_result_mem_handle( FIXES_db_get_result_mem_handle(

#if defined _ALS_DB_GetResultMemHandle
	#error _ALS_DB_GetResultMemHandle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_GetResultMemHandle__(DBResult:result) = db_get_result_mem_handle;
#define _ALS_DB_GetResultMemHandle
#define DB_GetResultMemHandle( FIXES_DB_GetResultMemHandle(

#if defined _ALS_db_debug_openfiles
	#error _ALS_db_debug_openfiles defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_debug_openfiles() = db_debug_openfiles;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenFiles`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_debug_openfiles() = db_debug_openfiles;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_debug_openfiles__() = db_debug_openfiles;
#define _ALS_db_debug_openfiles
#define db_debug_openfiles( FIXES_db_debug_openfiles(

#if defined _ALS_DB_DebugOpenFiles
	#error _ALS_DB_DebugOpenFiles defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_DebugOpenFiles() = db_debug_openfiles;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_DebugOpenFiles() = db_debug_openfiles;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_DebugOpenFiles__() = db_debug_openfiles;
#define _ALS_DB_DebugOpenFiles
#define DB_DebugOpenFiles( FIXES_DB_DebugOpenFiles(

#if defined _ALS_db_debug_openresults
	#error _ALS_db_debug_openresults defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_db_debug_openresults() = db_debug_openresults;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenResults`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_db_debug_openresults() = db_debug_openresults;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native db_debug_openresults__() = db_debug_openresults;
#define _ALS_db_debug_openresults
#define db_debug_openresults( FIXES_db_debug_openresults(

#if defined _ALS_DB_DebugOpenResults
	#error _ALS_DB_DebugOpenResults defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DB_DebugOpenResults() = db_debug_openresults;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DB_DebugOpenResults() = db_debug_openresults;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DB_DebugOpenResults__() = db_debug_openresults;
#define _ALS_DB_DebugOpenResults
#define DB_DebugOpenResults( FIXES_DB_DebugOpenResults(

/*

     █████          ██    ██ ███████ ██   ██ ██  ██████ ██      ███████ ███████
    ██   ██         ██    ██ ██      ██   ██ ██ ██      ██      ██      ██
    ███████         ██    ██ █████   ███████ ██ ██      ██      █████   ███████
    ██   ██          ██  ██  ██      ██   ██ ██ ██      ██      ██           ██
    ██   ██ ███████   ████   ███████ ██   ██ ██  ██████ ███████ ███████ ███████

*/

#if defined _ALS_CreateVehicle
	#error _ALS_CreateVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, addSiren = false) = CreateVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = CreateVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CreateVehicle__(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, bool:addSiren = false) = CreateVehicle;
#define _ALS_CreateVehicle
#define CreateVehicle( FIXES_CreateVehicle(

#if defined _ALS_DestroyVehicle
	#error _ALS_DestroyVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DestroyVehicle(vehicleid) = DestroyVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DestroyVehicle(vehicleid) = DestroyVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DestroyVehicle__(vehicleid) = DestroyVehicle;
#define _ALS_DestroyVehicle
#define DestroyVehicle( FIXES_DestroyVehicle(

#if defined _ALS_IsVehicleStreamedIn
	#error _ALS_IsVehicleStreamedIn defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsVehicleStreamedIn__(vehicleid, playerid) = IsVehicleStreamedIn;
#define _ALS_IsVehicleStreamedIn
#define IsVehicleStreamedIn( FIXES_IsVehicleStreamedIn(

#if defined _ALS_GetVehiclePos
	#error _ALS_GetVehiclePos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehiclePos__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
#define _ALS_GetVehiclePos
#define GetVehiclePos( FIXES_GetVehiclePos(

#if defined _ALS_SetVehiclePos
	#error _ALS_SetVehiclePos defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehiclePos__(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
#define _ALS_SetVehiclePos
#define SetVehiclePos( FIXES_SetVehiclePos(

#if defined _ALS_GetVehicleZAngle
	#error _ALS_GetVehicleZAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleZAngle__(vehicleid, &Float:angle) = GetVehicleZAngle;
#define _ALS_GetVehicleZAngle
#define GetVehicleZAngle( FIXES_GetVehicleZAngle(

#if defined _ALS_GetVehicleRotationQuat
	#error _ALS_GetVehicleRotationQuat defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleRotationQuat__(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
#define _ALS_GetVehicleRotationQuat
#define GetVehicleRotationQuat( FIXES_GetVehicleRotationQuat(

#if defined _ALS_GetVehicleDistanceFromPoint
	#error _ALS_GetVehicleDistanceFromPoint defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native Float:BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native Float:FIXES_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native Float:GetVehicleDistanceFromPoint__(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#define _ALS_GetVehicleDistanceFromPoint
#define GetVehicleDistanceFromPoint( FIXES_GetVehicleDistanceFromPoint(

#if defined _ALS_SetVehicleZAngle
	#error _ALS_SetVehicleZAngle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleZAngle__(vehicleid, Float:angle) = SetVehicleZAngle;
#define _ALS_SetVehicleZAngle
#define SetVehicleZAngle( FIXES_SetVehicleZAngle(

#if defined _ALS_SetVehicleParamsForPlayer
	#error _ALS_SetVehicleParamsForPlayer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleParamsForPlayer__(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
#define _ALS_SetVehicleParamsForPlayer
#define SetVehicleParamsForPlayer( FIXES_SetVehicleParamsForPlayer(

#if defined _ALS_ManualVehicleEngineAndLights
	#error _ALS_ManualVehicleEngineAndLights defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ManualVehicleEngineAndLights__() = ManualVehicleEngineAndLights;
#define _ALS_ManualVehicleEngineAndLights
#define ManualVehicleEngineAndLights( FIXES_ManualVehicleEngineAndLights(

#if defined _ALS_SetVehicleParamsEx
	#error _ALS_SetVehicleParamsEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleParamsEx__(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
#define _ALS_SetVehicleParamsEx
#define SetVehicleParamsEx( FIXES_SetVehicleParamsEx(

#if defined _ALS_GetVehicleParamsEx
	#error _ALS_GetVehicleParamsEx defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleParamsEx__(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
#define _ALS_GetVehicleParamsEx
#define GetVehicleParamsEx( FIXES_GetVehicleParamsEx(

#if defined _ALS_GetVehicleParamsSirenState
	#error _ALS_GetVehicleParamsSirenState defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleParamsSirenState__(vehicleid) = GetVehicleParamsSirenState;
#define _ALS_GetVehicleParamsSirenState
#define GetVehicleParamsSirenState( FIXES_GetVehicleParamsSirenState(

#if defined _ALS_SetVehicleParamsCarDoors
	#error _ALS_SetVehicleParamsCarDoors defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleParamsCarDoors__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
#define _ALS_SetVehicleParamsCarDoors
#define SetVehicleParamsCarDoors( FIXES_SetVehicleParamsCarDoors(

#if defined _ALS_GetVehicleParamsCarDoors
	#error _ALS_GetVehicleParamsCarDoors defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleParamsCarDoors__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
#define _ALS_GetVehicleParamsCarDoors
#define GetVehicleParamsCarDoors( FIXES_GetVehicleParamsCarDoors(

#if defined _ALS_SetVehicleParamsCarWindows
	#error _ALS_SetVehicleParamsCarWindows defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleParamsCarWindows__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
#define _ALS_SetVehicleParamsCarWindows
#define SetVehicleParamsCarWindows( FIXES_SetVehicleParamsCarWindows(

#if defined _ALS_GetVehicleParamsCarWindows
	#error _ALS_GetVehicleParamsCarWindows defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleParamsCarWindows__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
#define _ALS_GetVehicleParamsCarWindows
#define GetVehicleParamsCarWindows( FIXES_GetVehicleParamsCarWindows(

#if defined _ALS_SetVehicleToRespawn
	#error _ALS_SetVehicleToRespawn defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleToRespawn__(vehicleid) = SetVehicleToRespawn;
#define _ALS_SetVehicleToRespawn
#define SetVehicleToRespawn( FIXES_SetVehicleToRespawn(

#if defined _ALS_LinkVehicleToInterior
	#error _ALS_LinkVehicleToInterior defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native LinkVehicleToInterior__(vehicleid, interiorid) = LinkVehicleToInterior;
#define _ALS_LinkVehicleToInterior
#define LinkVehicleToInterior( FIXES_LinkVehicleToInterior(

#if defined _ALS_AddVehicleComponent
	#error _ALS_AddVehicleComponent defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AddVehicleComponent__(vehicleid, componentid) = AddVehicleComponent;
#define _ALS_AddVehicleComponent
#define AddVehicleComponent( FIXES_AddVehicleComponent(

#if defined _ALS_RemoveVehicleComponent
	#error _ALS_RemoveVehicleComponent defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RemoveVehicleComponent__(vehicleid, componentid) = RemoveVehicleComponent;
#define _ALS_RemoveVehicleComponent
#define RemoveVehicleComponent( FIXES_RemoveVehicleComponent(

#if defined _ALS_ChangeVehicleColor
	#error _ALS_ChangeVehicleColor defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ChangeVehicleColor__(vehicleid, colour1, colour2) = ChangeVehicleColor;
#define _ALS_ChangeVehicleColor
#define ChangeVehicleColor( FIXES_ChangeVehicleColor(

#if defined _ALS_ChangeVehiclePaintjob
	#error _ALS_ChangeVehiclePaintjob defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native ChangeVehiclePaintjob__(vehicleid, paintjobid) = ChangeVehiclePaintjob;
#define _ALS_ChangeVehiclePaintjob
#define ChangeVehiclePaintjob( FIXES_ChangeVehiclePaintjob(

#if defined _ALS_SetVehicleHealth
	#error _ALS_SetVehicleHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleHealth__(vehicleid, Float:health) = SetVehicleHealth;
#define _ALS_SetVehicleHealth
#define SetVehicleHealth( FIXES_SetVehicleHealth(

#if defined _ALS_GetVehicleHealth
	#error _ALS_GetVehicleHealth defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleHealth__(vehicleid, &Float:health) = GetVehicleHealth;
#define _ALS_GetVehicleHealth
#define GetVehicleHealth( FIXES_GetVehicleHealth(

#if defined _ALS_AttachTrailerToVehicle
	#error _ALS_AttachTrailerToVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native AttachTrailerToVehicle__(trailerid, vehicleid) = AttachTrailerToVehicle;
#define _ALS_AttachTrailerToVehicle
#define AttachTrailerToVehicle( FIXES_AttachTrailerToVehicle(

#if defined _ALS_DetachTrailerFromVehicle
	#error _ALS_DetachTrailerFromVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native DetachTrailerFromVehicle__(vehicleid) = DetachTrailerFromVehicle;
#define _ALS_DetachTrailerFromVehicle
#define DetachTrailerFromVehicle( FIXES_DetachTrailerFromVehicle(

#if defined _ALS_IsTrailerAttachedToVehicle
	#error _ALS_IsTrailerAttachedToVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsTrailerAttachedToVehicle__(vehicleid) = IsTrailerAttachedToVehicle;
#define _ALS_IsTrailerAttachedToVehicle
#define IsTrailerAttachedToVehicle( FIXES_IsTrailerAttachedToVehicle(

#if defined _ALS_GetVehicleTrailer
	#error _ALS_GetVehicleTrailer defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleTrailer__(vehicleid) = GetVehicleTrailer;
#define _ALS_GetVehicleTrailer
#define GetVehicleTrailer( FIXES_GetVehicleTrailer(

#if defined _ALS_SetVehicleNumberPlate
	#error _ALS_SetVehicleNumberPlate defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleNumberPlate(vehicleid, numberPlate[]) = SetVehicleNumberPlate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleNumberPlate(vehicleid, _FIXES_MAYBE_CONST numberPlate[]) = SetVehicleNumberPlate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleNumberPlate__(vehicleid, const numberPlate[]) = SetVehicleNumberPlate;
#define _ALS_SetVehicleNumberPlate
#define SetVehicleNumberPlate( FIXES_SetVehicleNumberPlate(

#if defined _ALS_GetVehicleModel
	#error _ALS_GetVehicleModel defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleModel(vehicleid) = GetVehicleModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleModel(vehicleid) = GetVehicleModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleModel__(vehicleid) = GetVehicleModel;
#define _ALS_GetVehicleModel
#define GetVehicleModel( FIXES_GetVehicleModel(

#if defined _ALS_GetVehicleComponentInSlot
	#error _ALS_GetVehicleComponentInSlot defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleComponentInSlot__(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
#define _ALS_GetVehicleComponentInSlot
#define GetVehicleComponentInSlot( FIXES_GetVehicleComponentInSlot(

#if defined _ALS_GetVehicleComponentType
	#error _ALS_GetVehicleComponentType defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native CARMODTYPE:BAD_GetVehicleComponentType(component) = GetVehicleComponentType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native CARMODTYPE:FIXES_GetVehicleComponentType(component) = GetVehicleComponentType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native CARMODTYPE:GetVehicleComponentType__(component) = GetVehicleComponentType;
#define _ALS_GetVehicleComponentType
#define GetVehicleComponentType( FIXES_GetVehicleComponentType(

#if defined _ALS_RepairVehicle
	#error _ALS_RepairVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_RepairVehicle(vehicleid) = RepairVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_RepairVehicle(vehicleid) = RepairVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native RepairVehicle__(vehicleid) = RepairVehicle;
#define _ALS_RepairVehicle
#define RepairVehicle( FIXES_RepairVehicle(

#if defined _ALS_GetVehicleVelocity
	#error _ALS_GetVehicleVelocity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleVelocity__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
#define _ALS_GetVehicleVelocity
#define GetVehicleVelocity( FIXES_GetVehicleVelocity(

#if defined _ALS_SetVehicleVelocity
	#error _ALS_SetVehicleVelocity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
#define _ALS_SetVehicleVelocity
#define SetVehicleVelocity( FIXES_SetVehicleVelocity(

#if defined _ALS_SetVehicleAngularVelocity
	#error _ALS_SetVehicleAngularVelocity defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleAngularVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
#define _ALS_SetVehicleAngularVelocity
#define SetVehicleAngularVelocity( FIXES_SetVehicleAngularVelocity(

#if defined _ALS_GetVehicleDamageStatus
	#error _ALS_GetVehicleDamageStatus defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleDamageStatus__(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
#define _ALS_GetVehicleDamageStatus
#define GetVehicleDamageStatus( FIXES_GetVehicleDamageStatus(

#if defined _ALS_UpdateVehicleDamageStatus
	#error _ALS_UpdateVehicleDamageStatus defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native UpdateVehicleDamageStatus__(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
#define _ALS_UpdateVehicleDamageStatus
#define UpdateVehicleDamageStatus( FIXES_UpdateVehicleDamageStatus(

#if defined _ALS_GetVehicleModelInfo
	#error _ALS_GetVehicleModelInfo defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleModelInfo__(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
#define _ALS_GetVehicleModelInfo
#define GetVehicleModelInfo( FIXES_GetVehicleModelInfo(

#if defined _ALS_SetVehicleVirtualWorld
	#error _ALS_SetVehicleVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native SetVehicleVirtualWorld__(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
#define _ALS_SetVehicleVirtualWorld
#define SetVehicleVirtualWorld( FIXES_SetVehicleVirtualWorld(

#if defined _ALS_GetVehicleVirtualWorld
	#error _ALS_GetVehicleVirtualWorld defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native FIXES_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native GetVehicleVirtualWorld__(vehicleid) = GetVehicleVirtualWorld;
#define _ALS_GetVehicleVirtualWorld
#define GetVehicleVirtualWorld( FIXES_GetVehicleVirtualWorld(

#if defined _ALS_IsValidVehicle
	#error _ALS_IsValidVehicle defined
#endif
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>.
 */
native BAD_IsValidVehicle(vehicleid) = IsValidVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>.
 */
native _FIXES_MAYBE_BOOL:FIXES_IsValidVehicle(vehicleid) = IsValidVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>.
 */
native bool:IsValidVehicle__(vehicleid) = IsValidVehicle;
#define _ALS_IsValidVehicle
#define IsValidVehicle( FIXES_IsValidVehicle(

