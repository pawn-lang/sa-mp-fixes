#pragma rational Float

#define _FIXES_MAYBE_BOOL: bool:
#define _FIXES_MAYBE_CONST const
#define _FIXES_NOT_CONST
#define _FIXES_MAYBE_SIZEOF(%0,%1) %0 = sizeof (%1)

/*

     ¦¦¦¦¦           ¦¦¦¦¦   ¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦   ¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦   ¦¦
    ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦   ¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦   ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦  ¦¦¦¦¦¦    ¦¦     ¦¦¦¦¦¦  ¦¦   ¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreateActor__(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
#if defined _ALS_CreateActor
	// Previous hook.
	#define _ALS_CreateActor__
	#define CreateActor__( CreateActor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyActor(actorid) = DestroyActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyActor(actorid) = DestroyActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyActor__(actorid) = DestroyActor;
#if defined _ALS_DestroyActor
	// Previous hook.
	#define _ALS_DestroyActor__
	#define DestroyActor__( DestroyActor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsActorStreamedIn(actorid, playerid) = IsActorStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsActorStreamedIn__(actorid, playerid) = IsActorStreamedIn;
#if defined _ALS_IsActorStreamedIn
	// Previous hook.
	#define _ALS_IsActorStreamedIn__
	#define IsActorStreamedIn__( IsActorStreamedIn(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetActorVirtualWorld(actorid, virtualWorld) = SetActorVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetActorVirtualWorld__(actorid, virtualWorld) = SetActorVirtualWorld;
#if defined _ALS_SetActorVirtualWorld
	// Previous hook.
	#define _ALS_SetActorVirtualWorld__
	#define SetActorVirtualWorld__( SetActorVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetActorVirtualWorld(actorid) = GetActorVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetActorVirtualWorld__(actorid) = GetActorVirtualWorld;
#if defined _ALS_GetActorVirtualWorld
	// Previous hook.
	#define _ALS_GetActorVirtualWorld__
	#define GetActorVirtualWorld__( GetActorVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ApplyActorAnimation(actorid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time) = ApplyActorAnimation;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ApplyActorAnimation(actorid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time) = ApplyActorAnimation;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ApplyActorAnimation__(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time) = ApplyActorAnimation;
#if defined _ALS_ApplyActorAnimation
	// Previous hook.
	#define _ALS_ApplyActorAnimation__
	#define ApplyActorAnimation__( ApplyActorAnimation(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ClearActorAnimations(actorid) = ClearActorAnimations;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ClearActorAnimations(actorid) = ClearActorAnimations;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ClearActorAnimations__(actorid) = ClearActorAnimations;
#if defined _ALS_ClearActorAnimations
	// Previous hook.
	#define _ALS_ClearActorAnimations__
	#define ClearActorAnimations__( ClearActorAnimations(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetActorPos(actorid, Float:x, Float:y, Float:z) = SetActorPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetActorPos__(actorid, Float:x, Float:y, Float:z) = SetActorPos;
#if defined _ALS_SetActorPos
	// Previous hook.
	#define _ALS_SetActorPos__
	#define SetActorPos__( SetActorPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetActorPos(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetActorPos__(actorid, &Float:x, &Float:y, &Float:z) = GetActorPos;
#if defined _ALS_GetActorPos
	// Previous hook.
	#define _ALS_GetActorPos__
	#define GetActorPos__( GetActorPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetActorFacingAngle(actorid, Float:angle) = SetActorFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetActorFacingAngle__(actorid, Float:angle) = SetActorFacingAngle;
#if defined _ALS_SetActorFacingAngle
	// Previous hook.
	#define _ALS_SetActorFacingAngle__
	#define SetActorFacingAngle__( SetActorFacingAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetActorFacingAngle(actorid, &Float:angle) = GetActorFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetActorFacingAngle__(actorid, &Float:angle) = GetActorFacingAngle;
#if defined _ALS_GetActorFacingAngle
	// Previous hook.
	#define _ALS_GetActorFacingAngle__
	#define GetActorFacingAngle__( GetActorFacingAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetActorHealth(actorid, Float:health) = SetActorHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetActorHealth(actorid, Float:health) = SetActorHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetActorHealth__(actorid, Float:health) = SetActorHealth;
#if defined _ALS_SetActorHealth
	// Previous hook.
	#define _ALS_SetActorHealth__
	#define SetActorHealth__( SetActorHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetActorHealth(actorid, &Float:health) = GetActorHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetActorHealth(actorid, &Float:health) = GetActorHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetActorHealth__(actorid, &Float:health) = GetActorHealth;
#if defined _ALS_GetActorHealth
	// Previous hook.
	#define _ALS_GetActorHealth__
	#define GetActorHealth__( GetActorHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetActorInvulnerable(actorid, invulnerable = true) = SetActorInvulnerable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetActorInvulnerable(actorid, _FIXES_MAYBE_BOOL:invulnerable = true) = SetActorInvulnerable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetActorInvulnerable__(actorid, bool:invulnerable = true) = SetActorInvulnerable;
#if defined _ALS_SetActorInvulnerable
	// Previous hook.
	#define _ALS_SetActorInvulnerable__
	#define SetActorInvulnerable__( SetActorInvulnerable(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsActorInvulnerable(actorid) = IsActorInvulnerable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsActorInvulnerable(actorid) = IsActorInvulnerable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsActorInvulnerable__(actorid) = IsActorInvulnerable;
#if defined _ALS_IsActorInvulnerable
	// Previous hook.
	#define _ALS_IsActorInvulnerable__
	#define IsActorInvulnerable__( IsActorInvulnerable(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsValidActor(actorid) = IsValidActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsValidActor(actorid) = IsValidActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsValidActor__(actorid) = IsValidActor;
#if defined _ALS_IsValidActor
	// Previous hook.
	#define _ALS_IsValidActor__
	#define IsValidActor__( IsValidActor(
#endif

/*

     ¦¦¦¦¦          ¦¦   ¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦   ¦¦    ¦¦       ¦¦    ¦¦   ¦¦
    ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦    ¦¦       ¦¦    ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦   ¦¦    ¦¦       ¦¦    ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦    ¦¦       ¦¦    ¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_HTTP(index, HTTP_METHOD:method, url[], data[], callback[]) = HTTP;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_HTTP(index, HTTP_METHOD:method, _FIXES_MAYBE_CONST url[], _FIXES_MAYBE_CONST data[], _FIXES_MAYBE_CONST callback[]) = HTTP;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native HTTP__(index, HTTP_METHOD:method, const url[], const data[], const callback[]) = HTTP;
#if defined _ALS_HTTP
	// Previous hook.
	#define _ALS_HTTP__
	#define HTTP__( HTTP(
#endif

/*


     ¦¦¦¦¦           ¦¦¦¦¦¦  ¦¦¦¦¦¦       ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦    ¦¦ ¦¦   ¦¦      ¦¦ ¦¦      ¦¦         ¦¦    ¦¦
    ¦¦¦¦¦¦¦         ¦¦    ¦¦ ¦¦¦¦¦¦       ¦¦ ¦¦¦¦¦   ¦¦         ¦¦    ¦¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦    ¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦      ¦¦         ¦¦         ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦¦¦¦¦  ¦¦¦¦¦¦    ¦¦    ¦¦¦¦¦¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreateObject__(modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreateObject;
#if defined _ALS_CreateObject
	// Previous hook.
	#define _ALS_CreateObject__
	#define CreateObject__( CreateObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachObjectToVehicle__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToVehicle;
#if defined _ALS_AttachObjectToVehicle
	// Previous hook.
	#define _ALS_AttachObjectToVehicle__
	#define AttachObjectToVehicle__( AttachObjectToVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, syncRotation = true) = AttachObjectToObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, _FIXES_MAYBE_BOOL:syncRotation = true) = AttachObjectToObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachObjectToObject__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, bool:syncRotation = true) = AttachObjectToObject;
#if defined _ALS_AttachObjectToObject
	// Previous hook.
	#define _ALS_AttachObjectToObject__
	#define AttachObjectToObject__( AttachObjectToObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachObjectToPlayer__(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachObjectToPlayer;
#if defined _ALS_AttachObjectToPlayer
	// Previous hook.
	#define _ALS_AttachObjectToPlayer__
	#define AttachObjectToPlayer__( AttachObjectToPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectPos(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectPos__(objectid, Float:x, Float:y, Float:z) = SetObjectPos;
#if defined _ALS_SetObjectPos
	// Previous hook.
	#define _ALS_SetObjectPos__
	#define SetObjectPos__( SetObjectPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetObjectPos(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetObjectPos__(objectid, &Float:x, &Float:y, &Float:z) = GetObjectPos;
#if defined _ALS_GetObjectPos
	// Previous hook.
	#define _ALS_GetObjectPos__
	#define GetObjectPos__( GetObjectPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectRot(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectRot__(objectid, Float:rotX, Float:rotY, Float:rotZ) = SetObjectRot;
#if defined _ALS_SetObjectRot
	// Previous hook.
	#define _ALS_SetObjectRot__
	#define SetObjectRot__( SetObjectRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetObjectRot(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetObjectRot__(objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetObjectRot;
#if defined _ALS_GetObjectRot
	// Previous hook.
	#define _ALS_GetObjectRot__
	#define GetObjectRot__( GetObjectRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetObjectModel(objectid) = GetObjectModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetObjectModel(objectid) = GetObjectModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetObjectModel__(objectid) = GetObjectModel;
#if defined _ALS_GetObjectModel
	// Previous hook.
	#define _ALS_GetObjectModel__
	#define GetObjectModel__( GetObjectModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectNoCameraCol(objectid) = SetObjectNoCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectNoCameraCol__(objectid) = SetObjectNoCameraCol;
#if defined _ALS_SetObjectNoCameraCol
	// Previous hook.
	#define _ALS_SetObjectNoCameraCol__
	#define SetObjectNoCameraCol__( SetObjectNoCameraCol(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsValidObject(objectid) = IsValidObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsValidObject(objectid) = IsValidObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsValidObject__(objectid) = IsValidObject;
#if defined _ALS_IsValidObject
	// Previous hook.
	#define _ALS_IsValidObject__
	#define IsValidObject__( IsValidObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyObject(objectid) = DestroyObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyObject(objectid) = DestroyObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyObject__(objectid) = DestroyObject;
#if defined _ALS_DestroyObject
	// Previous hook.
	#define _ALS_DestroyObject__
	#define DestroyObject__( DestroyObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_MoveObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native MoveObject__(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MoveObject;
#if defined _ALS_MoveObject
	// Previous hook.
	#define _ALS_MoveObject__
	#define MoveObject__( MoveObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_StopObject(objectid) = StopObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_StopObject(objectid) = StopObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native StopObject__(objectid) = StopObject;
#if defined _ALS_StopObject
	// Previous hook.
	#define _ALS_StopObject__
	#define StopObject__( StopObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsObjectMoving(objectid) = IsObjectMoving;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsObjectMoving(objectid) = IsObjectMoving;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsObjectMoving__(objectid) = IsObjectMoving;
#if defined _ALS_IsObjectMoving
	// Previous hook.
	#define _ALS_IsObjectMoving__
	#define IsObjectMoving__( IsObjectMoving(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EditObject(playerid, objectid) = EditObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EditObject(playerid, objectid) = EditObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EditObject__(playerid, objectid) = EditObject;
#if defined _ALS_EditObject
	// Previous hook.
	#define _ALS_EditObject__
	#define EditObject__( EditObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EditPlayerObject(playerid, objectid) = EditPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EditPlayerObject(playerid, objectid) = EditPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EditPlayerObject__(playerid, objectid) = EditPlayerObject;
#if defined _ALS_EditPlayerObject
	// Previous hook.
	#define _ALS_EditPlayerObject__
	#define EditPlayerObject__( EditPlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SelectObject(playerid) = SelectObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SelectObject(playerid) = SelectObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SelectObject__(playerid) = SelectObject;
#if defined _ALS_SelectObject
	// Previous hook.
	#define _ALS_SelectObject__
	#define SelectObject__( SelectObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CancelEdit(playerid) = CancelEdit;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CancelEdit(playerid) = CancelEdit;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CancelEdit__(playerid) = CancelEdit;
#if defined _ALS_CancelEdit
	// Previous hook.
	#define _ALS_CancelEdit__
	#define CancelEdit__( CancelEdit(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreatePlayerObject__(playerid, modelid, Float:x, Float:y, Float:z, Float:rotX, Float:rotY, Float:rotZ, Float:drawDistance = 0.0) = CreatePlayerObject;
#if defined _ALS_CreatePlayerObject
	// Previous hook.
	#define _ALS_CreatePlayerObject__
	#define CreatePlayerObject__( CreatePlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachPlayerObjectToVehicle__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToVehicle;
#if defined _ALS_AttachPlayerObjectToVehicle
	// Previous hook.
	#define _ALS_AttachPlayerObjectToVehicle__
	#define AttachPlayerObjectToVehicle__( AttachPlayerObjectToVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerObjectPos__(playerid, objectid, Float:x, Float:y, Float:z) = SetPlayerObjectPos;
#if defined _ALS_SetPlayerObjectPos
	// Previous hook.
	#define _ALS_SetPlayerObjectPos__
	#define SetPlayerObjectPos__( SetPlayerObjectPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerObjectPos__(playerid, objectid, &Float:x, &Float:y, &Float:z) = GetPlayerObjectPos;
#if defined _ALS_GetPlayerObjectPos
	// Previous hook.
	#define _ALS_GetPlayerObjectPos__
	#define GetPlayerObjectPos__( GetPlayerObjectPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerObjectRot(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerObjectRot__(playerid, objectid, Float:rotX, Float:rotY, Float:rotZ) = SetPlayerObjectRot;
#if defined _ALS_SetPlayerObjectRot
	// Previous hook.
	#define _ALS_SetPlayerObjectRot__
	#define SetPlayerObjectRot__( SetPlayerObjectRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerObjectRot(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerObjectRot__(playerid, objectid, &Float:rotX, &Float:rotY, &Float:rotZ) = GetPlayerObjectRot;
#if defined _ALS_GetPlayerObjectRot
	// Previous hook.
	#define _ALS_GetPlayerObjectRot__
	#define GetPlayerObjectRot__( GetPlayerObjectRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerObjectModel(playerid, objectid) = GetPlayerObjectModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerObjectModel__(playerid, objectid) = GetPlayerObjectModel;
#if defined _ALS_GetPlayerObjectModel
	// Previous hook.
	#define _ALS_GetPlayerObjectModel__
	#define GetPlayerObjectModel__( GetPlayerObjectModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerObjectNoCameraCol(playerid, objectid) = SetPlayerObjectNoCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerObjectNoCameraCol__(playerid, objectid) = SetPlayerObjectNoCameraCol;
#if defined _ALS_SetPlayerObjectNoCameraCol
	// Previous hook.
	#define _ALS_SetPlayerObjectNoCameraCol__
	#define SetPlayerObjectNoCameraCol__( SetPlayerObjectNoCameraCol(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsValidPlayerObject(playerid, objectid) = IsValidPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsValidPlayerObject__(playerid, objectid) = IsValidPlayerObject;
#if defined _ALS_IsValidPlayerObject
	// Previous hook.
	#define _ALS_IsValidPlayerObject__
	#define IsValidPlayerObject__( IsValidPlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyPlayerObject(playerid, objectid) = DestroyPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyPlayerObject__(playerid, objectid) = DestroyPlayerObject;
#if defined _ALS_DestroyPlayerObject
	// Previous hook.
	#define _ALS_DestroyPlayerObject__
	#define DestroyPlayerObject__( DestroyPlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_MovePlayerObject(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native MovePlayerObject__(playerid, objectid, Float:x, Float:y, Float:z, Float:speed, Float:rotX = -1000.0, Float:rotY = -1000.0, Float:rotZ = -1000.0) = MovePlayerObject;
#if defined _ALS_MovePlayerObject
	// Previous hook.
	#define _ALS_MovePlayerObject__
	#define MovePlayerObject__( MovePlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_StopPlayerObject(playerid, objectid) = StopPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_StopPlayerObject(playerid, objectid) = StopPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native StopPlayerObject__(playerid, objectid) = StopPlayerObject;
#if defined _ALS_StopPlayerObject
	// Previous hook.
	#define _ALS_StopPlayerObject__
	#define StopPlayerObject__( StopPlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerObjectMoving(playerid, objectid) = IsPlayerObjectMoving;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerObjectMoving__(playerid, objectid) = IsPlayerObjectMoving;
#if defined _ALS_IsPlayerObjectMoving
	// Previous hook.
	#define _ALS_IsPlayerObjectMoving__
	#define IsPlayerObjectMoving__( IsPlayerObjectMoving(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachPlayerObjectToPlayer__(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ) = AttachPlayerObjectToPlayer;
#if defined _ALS_AttachPlayerObjectToPlayer
	// Previous hook.
	#define _ALS_AttachPlayerObjectToPlayer__
	#define AttachPlayerObjectToPlayer__( AttachPlayerObjectToPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectMaterial(objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetObjectMaterial;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectMaterial(objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetObjectMaterial;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectMaterial__(objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetObjectMaterial;
#if defined _ALS_SetObjectMaterial
	// Previous hook.
	#define _ALS_SetObjectMaterial__
	#define SetObjectMaterial__( SetObjectMaterial(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, textureLibrary[], textureName[], materialColour = 0) = SetPlayerObjectMaterial;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, _FIXES_MAYBE_CONST textureLibrary[], _FIXES_MAYBE_CONST textureName[], materialColour = 0) = SetPlayerObjectMaterial;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerObjectMaterial__(playerid, objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0) = SetPlayerObjectMaterial;
#if defined _ALS_SetPlayerObjectMaterial
	// Previous hook.
	#define _ALS_SetPlayerObjectMaterial__
	#define SetPlayerObjectMaterial__( SetPlayerObjectMaterial(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectMaterialText(objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectMaterialText(objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectMaterialText__(objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetObjectMaterialText;
#if defined _ALS_SetObjectMaterialText
	// Previous hook.
	#define _ALS_SetObjectMaterialText__
	#define SetObjectMaterialText__( SetObjectMaterialText(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerObjectMaterialText(playerid, objectid, text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, fontFace[] = "Arial", fontSize = 24, bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerObjectMaterialText(playerid, objectid, _FIXES_MAYBE_CONST text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, _FIXES_MAYBE_CONST fontFace[] = "Arial", fontSize = 24, _FIXES_MAYBE_BOOL:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerObjectMaterialText__(playerid, objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT) = SetPlayerObjectMaterialText;
#if defined _ALS_SetPlayerObjectMaterialText
	// Previous hook.
	#define _ALS_SetPlayerObjectMaterialText__
	#define SetPlayerObjectMaterialText__( SetPlayerObjectMaterialText(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetObjectsDefaultCameraCol(disable) = SetObjectsDefaultCameraCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetObjectsDefaultCameraCol(_FIXES_MAYBE_BOOL:disable) = SetObjectsDefaultCameraCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetObjectsDefaultCameraCol__(bool:disable) = SetObjectsDefaultCameraCol;
#if defined _ALS_SetObjectsDefaultCameraCol
	// Previous hook.
	#define _ALS_SetObjectsDefaultCameraCol__
	#define SetObjectsDefaultCameraCol__( SetObjectsDefaultCameraCol(
#endif

/*

     ¦¦¦¦¦          ¦¦¦¦¦¦  ¦¦       ¦¦¦¦¦  ¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦   ¦¦ ¦¦      ¦¦   ¦¦  ¦¦  ¦¦  ¦¦      ¦¦   ¦¦ ¦¦
    ¦¦¦¦¦¦¦         ¦¦¦¦¦¦  ¦¦      ¦¦¦¦¦¦¦   ¦¦¦¦   ¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦      ¦¦      ¦¦   ¦¦    ¦¦    ¦¦      ¦¦   ¦¦      ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦   ¦¦    ¦¦    ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetSpawnInfo__(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = SetSpawnInfo;
#if defined _ALS_SetSpawnInfo
	// Previous hook.
	#define _ALS_SetSpawnInfo__
	#define SetSpawnInfo__( SetSpawnInfo(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SpawnPlayer(playerid) = SpawnPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SpawnPlayer(playerid) = SpawnPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SpawnPlayer__(playerid) = SpawnPlayer;
#if defined _ALS_SpawnPlayer
	// Previous hook.
	#define _ALS_SpawnPlayer__
	#define SpawnPlayer__( SpawnPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
#if defined _ALS_SetPlayerPos
	// Previous hook.
	#define _ALS_SetPlayerPos__
	#define SetPlayerPos__( SetPlayerPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerPosFindZ__(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
#if defined _ALS_SetPlayerPosFindZ
	// Previous hook.
	#define _ALS_SetPlayerPosFindZ__
	#define SetPlayerPosFindZ__( SetPlayerPosFindZ(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
#if defined _ALS_GetPlayerPos
	// Previous hook.
	#define _ALS_GetPlayerPos__
	#define GetPlayerPos__( GetPlayerPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerFacingAngle(playerid, Float:ang) = SetPlayerFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerFacingAngle__(playerid, Float:ang) = SetPlayerFacingAngle;
#if defined _ALS_SetPlayerFacingAngle
	// Previous hook.
	#define _ALS_SetPlayerFacingAngle__
	#define SetPlayerFacingAngle__( SetPlayerFacingAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerFacingAngle(playerid, &Float:ang) = GetPlayerFacingAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerFacingAngle__(playerid, &Float:ang) = GetPlayerFacingAngle;
#if defined _ALS_GetPlayerFacingAngle
	// Previous hook.
	#define _ALS_GetPlayerFacingAngle__
	#define GetPlayerFacingAngle__( GetPlayerFacingAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerInRangeOfPoint__(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
#if defined _ALS_IsPlayerInRangeOfPoint
	// Previous hook.
	#define _ALS_IsPlayerInRangeOfPoint__
	#define IsPlayerInRangeOfPoint__( IsPlayerInRangeOfPoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetPlayerDistanceFromPoint__(playerid, Float:x, Float:y, Float:z) = GetPlayerDistanceFromPoint;
#if defined _ALS_GetPlayerDistanceFromPoint
	// Previous hook.
	#define _ALS_GetPlayerDistanceFromPoint__
	#define GetPlayerDistanceFromPoint__( GetPlayerDistanceFromPoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerStreamedIn(targetid, playerid) = IsPlayerStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerStreamedIn__(targetid, playerid) = IsPlayerStreamedIn;
#if defined _ALS_IsPlayerStreamedIn
	// Previous hook.
	#define _ALS_IsPlayerStreamedIn__
	#define IsPlayerStreamedIn__( IsPlayerStreamedIn(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerInterior__(playerid, interiorid) = SetPlayerInterior;
#if defined _ALS_SetPlayerInterior
	// Previous hook.
	#define _ALS_SetPlayerInterior__
	#define SetPlayerInterior__( SetPlayerInterior(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerInterior(playerid) = GetPlayerInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerInterior(playerid) = GetPlayerInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerInterior__(playerid) = GetPlayerInterior;
#if defined _ALS_GetPlayerInterior
	// Previous hook.
	#define _ALS_GetPlayerInterior__
	#define GetPlayerInterior__( GetPlayerInterior(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerHealth__(playerid, Float:health) = SetPlayerHealth;
#if defined _ALS_SetPlayerHealth
	// Previous hook.
	#define _ALS_SetPlayerHealth__
	#define SetPlayerHealth__( SetPlayerHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerHealth__(playerid, &Float:health) = GetPlayerHealth;
#if defined _ALS_GetPlayerHealth
	// Previous hook.
	#define _ALS_GetPlayerHealth__
	#define GetPlayerHealth__( GetPlayerHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerArmour__(playerid, Float:armour) = SetPlayerArmour;
#if defined _ALS_SetPlayerArmour
	// Previous hook.
	#define _ALS_SetPlayerArmour__
	#define SetPlayerArmour__( SetPlayerArmour(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerArmour__(playerid, &Float:armour) = GetPlayerArmour;
#if defined _ALS_GetPlayerArmour
	// Previous hook.
	#define _ALS_GetPlayerArmour__
	#define GetPlayerArmour__( GetPlayerArmour(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerAmmo(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerAmmo__(playerid, WEAPON:weaponid, ammo) = SetPlayerAmmo;
#if defined _ALS_SetPlayerAmmo
	// Previous hook.
	#define _ALS_SetPlayerAmmo__
	#define SetPlayerAmmo__( SetPlayerAmmo(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerAmmo(playerid) = GetPlayerAmmo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerAmmo(playerid) = GetPlayerAmmo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerAmmo__(playerid) = GetPlayerAmmo;
#if defined _ALS_GetPlayerAmmo
	// Previous hook.
	#define _ALS_GetPlayerAmmo__
	#define GetPlayerAmmo__( GetPlayerAmmo(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native WEAPONSTATE:BAD_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native WEAPONSTATE:CST_GetPlayerWeaponState(playerid) = GetPlayerWeaponState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native WEAPONSTATE:GetPlayerWeaponState__(playerid) = GetPlayerWeaponState;
#if defined _ALS_GetPlayerWeaponState
	// Previous hook.
	#define _ALS_GetPlayerWeaponState__
	#define GetPlayerWeaponState__( GetPlayerWeaponState(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerTargetPlayer(playerid) = GetPlayerTargetPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerTargetPlayer__(playerid) = GetPlayerTargetPlayer;
#if defined _ALS_GetPlayerTargetPlayer
	// Previous hook.
	#define _ALS_GetPlayerTargetPlayer__
	#define GetPlayerTargetPlayer__( GetPlayerTargetPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerTargetActor(playerid) = GetPlayerTargetActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerTargetActor__(playerid) = GetPlayerTargetActor;
#if defined _ALS_GetPlayerTargetActor
	// Previous hook.
	#define _ALS_GetPlayerTargetActor__
	#define GetPlayerTargetActor__( GetPlayerTargetActor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerTeam__(playerid, teamid) = SetPlayerTeam;
#if defined _ALS_SetPlayerTeam
	// Previous hook.
	#define _ALS_SetPlayerTeam__
	#define SetPlayerTeam__( SetPlayerTeam(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerTeam(playerid) = GetPlayerTeam;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerTeam(playerid) = GetPlayerTeam;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerTeam__(playerid) = GetPlayerTeam;
#if defined _ALS_GetPlayerTeam
	// Previous hook.
	#define _ALS_GetPlayerTeam__
	#define GetPlayerTeam__( GetPlayerTeam(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerScore(playerid, score) = SetPlayerScore;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerScore(playerid, score) = SetPlayerScore;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerScore__(playerid, score) = SetPlayerScore;
#if defined _ALS_SetPlayerScore
	// Previous hook.
	#define _ALS_SetPlayerScore__
	#define SetPlayerScore__( SetPlayerScore(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerScore(playerid) = GetPlayerScore;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerScore(playerid) = GetPlayerScore;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerScore__(playerid) = GetPlayerScore;
#if defined _ALS_GetPlayerScore
	// Previous hook.
	#define _ALS_GetPlayerScore__
	#define GetPlayerScore__( GetPlayerScore(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerDrunkLevel(playerid) = GetPlayerDrunkLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerDrunkLevel__(playerid) = GetPlayerDrunkLevel;
#if defined _ALS_GetPlayerDrunkLevel
	// Previous hook.
	#define _ALS_GetPlayerDrunkLevel__
	#define GetPlayerDrunkLevel__( GetPlayerDrunkLevel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerDrunkLevel(playerid, level) = SetPlayerDrunkLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerDrunkLevel__(playerid, level) = SetPlayerDrunkLevel;
#if defined _ALS_SetPlayerDrunkLevel
	// Previous hook.
	#define _ALS_SetPlayerDrunkLevel__
	#define SetPlayerDrunkLevel__( SetPlayerDrunkLevel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerColor(playerid, colour) = SetPlayerColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerColor(playerid, colour) = SetPlayerColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerColor__(playerid, colour) = SetPlayerColor;
#if defined _ALS_SetPlayerColor
	// Previous hook.
	#define _ALS_SetPlayerColor__
	#define SetPlayerColor__( SetPlayerColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerColor(playerid) = GetPlayerColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerColor(playerid) = GetPlayerColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerColor__(playerid) = GetPlayerColor;
#if defined _ALS_GetPlayerColor
	// Previous hook.
	#define _ALS_GetPlayerColor__
	#define GetPlayerColor__( GetPlayerColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerSkin__(playerid, skinid) = SetPlayerSkin;
#if defined _ALS_SetPlayerSkin
	// Previous hook.
	#define _ALS_SetPlayerSkin__
	#define SetPlayerSkin__( SetPlayerSkin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerSkin(playerid) = GetPlayerSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerSkin(playerid) = GetPlayerSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerSkin__(playerid) = GetPlayerSkin;
#if defined _ALS_GetPlayerSkin
	// Previous hook.
	#define _ALS_GetPlayerSkin__
	#define GetPlayerSkin__( GetPlayerSkin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCustomSkin(playerid) = GetPlayerCustomSkin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCustomSkin__(playerid) = GetPlayerCustomSkin;
#if defined _ALS_GetPlayerCustomSkin
	// Previous hook.
	#define _ALS_GetPlayerCustomSkin__
	#define GetPlayerCustomSkin__( GetPlayerCustomSkin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GivePlayerWeapon(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GivePlayerWeapon__(playerid, WEAPON:weaponid, ammo) = GivePlayerWeapon;
#if defined _ALS_GivePlayerWeapon
	// Previous hook.
	#define _ALS_GivePlayerWeapon__
	#define GivePlayerWeapon__( GivePlayerWeapon(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ResetPlayerWeapons__(playerid) = ResetPlayerWeapons;
#if defined _ALS_ResetPlayerWeapons
	// Previous hook.
	#define _ALS_ResetPlayerWeapons__
	#define ResetPlayerWeapons__( ResetPlayerWeapons(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerArmedWeapon(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerArmedWeapon__(playerid, WEAPON:weaponid) = SetPlayerArmedWeapon;
#if defined _ALS_SetPlayerArmedWeapon
	// Previous hook.
	#define _ALS_SetPlayerArmedWeapon__
	#define SetPlayerArmedWeapon__( SetPlayerArmedWeapon(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerWeaponData(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerWeaponData__(playerid, slot, &WEAPON:weapons, &ammo) = GetPlayerWeaponData;
#if defined _ALS_GetPlayerWeaponData
	// Previous hook.
	#define _ALS_GetPlayerWeaponData__
	#define GetPlayerWeaponData__( GetPlayerWeaponData(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GivePlayerMoney(playerid, money) = GivePlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GivePlayerMoney(playerid, money) = GivePlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GivePlayerMoney__(playerid, money) = GivePlayerMoney;
#if defined _ALS_GivePlayerMoney
	// Previous hook.
	#define _ALS_GivePlayerMoney__
	#define GivePlayerMoney__( GivePlayerMoney(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ResetPlayerMoney(playerid) = ResetPlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ResetPlayerMoney(playerid) = ResetPlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ResetPlayerMoney__(playerid) = ResetPlayerMoney;
#if defined _ALS_ResetPlayerMoney
	// Previous hook.
	#define _ALS_ResetPlayerMoney__
	#define ResetPlayerMoney__( ResetPlayerMoney(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerName(playerid, name[]) = SetPlayerName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerName(playerid, _FIXES_MAYBE_CONST name[]) = SetPlayerName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerName__(playerid, const name[]) = SetPlayerName;
#if defined _ALS_SetPlayerName
	// Previous hook.
	#define _ALS_SetPlayerName__
	#define SetPlayerName__( SetPlayerName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerMoney(playerid) = GetPlayerMoney;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerMoney(playerid) = GetPlayerMoney;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerMoney__(playerid) = GetPlayerMoney;
#if defined _ALS_GetPlayerMoney
	// Previous hook.
	#define _ALS_GetPlayerMoney__
	#define GetPlayerMoney__( GetPlayerMoney(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native PLAYER_STATE:BAD_GetPlayerState(playerid) = GetPlayerState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native PLAYER_STATE:CST_GetPlayerState(playerid) = GetPlayerState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PLAYER_STATE:GetPlayerState__(playerid) = GetPlayerState;
#if defined _ALS_GetPlayerState
	// Previous hook.
	#define _ALS_GetPlayerState__
	#define GetPlayerState__( GetPlayerState(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerIp(playerid, ip[], len) = GetPlayerIp;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerIp(playerid, ip[], _FIXES_MAYBE_SIZEOF(len, ip)) = GetPlayerIp;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerIp__(playerid, ip[], len = sizeof (ip)) = GetPlayerIp;
#if defined _ALS_GetPlayerIp
	// Previous hook.
	#define _ALS_GetPlayerIp__
	#define GetPlayerIp__( GetPlayerIp(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerPing(playerid) = GetPlayerPing;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerPing(playerid) = GetPlayerPing;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerPing__(playerid) = GetPlayerPing;
#if defined _ALS_GetPlayerPing
	// Previous hook.
	#define _ALS_GetPlayerPing__
	#define GetPlayerPing__( GetPlayerPing(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native WEAPON:BAD_GetPlayerWeapon(playerid) = GetPlayerWeapon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native WEAPON:CST_GetPlayerWeapon(playerid) = GetPlayerWeapon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native WEAPON:GetPlayerWeapon__(playerid) = GetPlayerWeapon;
#if defined _ALS_GetPlayerWeapon
	// Previous hook.
	#define _ALS_GetPlayerWeapon__
	#define GetPlayerWeapon__( GetPlayerWeapon(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerKeys__(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
#if defined _ALS_GetPlayerKeys
	// Previous hook.
	#define _ALS_GetPlayerKeys__
	#define GetPlayerKeys__( GetPlayerKeys(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerName(playerid, const name[], len) = GetPlayerName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerName(playerid, _FIXES_NOT_CONST name[], _FIXES_MAYBE_SIZEOF(len, name)) = GetPlayerName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerName__(playerid, name[], len = sizeof (name)) = GetPlayerName;
#if defined _ALS_GetPlayerName
	// Previous hook.
	#define _ALS_GetPlayerName__
	#define GetPlayerName__( GetPlayerName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerTime__(playerid, hour, minute) = SetPlayerTime;
#if defined _ALS_SetPlayerTime
	// Previous hook.
	#define _ALS_SetPlayerTime__
	#define SetPlayerTime__( SetPlayerTime(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerTime(playerid, &hour, &minute) = GetPlayerTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerTime__(playerid, &hour, &minute) = GetPlayerTime;
#if defined _ALS_GetPlayerTime
	// Previous hook.
	#define _ALS_GetPlayerTime__
	#define GetPlayerTime__( GetPlayerTime(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TogglePlayerClock(playerid, toggle) = TogglePlayerClock;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TogglePlayerClock(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerClock;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TogglePlayerClock__(playerid, bool:toggle) = TogglePlayerClock;
#if defined _ALS_TogglePlayerClock
	// Previous hook.
	#define _ALS_TogglePlayerClock__
	#define TogglePlayerClock__( TogglePlayerClock(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerWeather(playerid, weather) = SetPlayerWeather;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerWeather__(playerid, weather) = SetPlayerWeather;
#if defined _ALS_SetPlayerWeather
	// Previous hook.
	#define _ALS_SetPlayerWeather__
	#define SetPlayerWeather__( SetPlayerWeather(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ForceClassSelection(playerid) = ForceClassSelection;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ForceClassSelection(playerid) = ForceClassSelection;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ForceClassSelection__(playerid) = ForceClassSelection;
#if defined _ALS_ForceClassSelection
	// Previous hook.
	#define _ALS_ForceClassSelection__
	#define ForceClassSelection__( ForceClassSelection(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerWantedLevel(playerid, level) = SetPlayerWantedLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerWantedLevel__(playerid, level) = SetPlayerWantedLevel;
#if defined _ALS_SetPlayerWantedLevel
	// Previous hook.
	#define _ALS_SetPlayerWantedLevel__
	#define SetPlayerWantedLevel__( SetPlayerWantedLevel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerWantedLevel(playerid) = GetPlayerWantedLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerWantedLevel__(playerid) = GetPlayerWantedLevel;
#if defined _ALS_GetPlayerWantedLevel
	// Previous hook.
	#define _ALS_GetPlayerWantedLevel__
	#define GetPlayerWantedLevel__( GetPlayerWantedLevel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerFightingStyle(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerFightingStyle__(playerid, FIGHT_STYLE:style) = SetPlayerFightingStyle;
#if defined _ALS_SetPlayerFightingStyle
	// Previous hook.
	#define _ALS_SetPlayerFightingStyle__
	#define SetPlayerFightingStyle__( SetPlayerFightingStyle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native FIGHT_STYLE:BAD_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native FIGHT_STYLE:CST_GetPlayerFightingStyle(playerid) = GetPlayerFightingStyle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native FIGHT_STYLE:GetPlayerFightingStyle__(playerid) = GetPlayerFightingStyle;
#if defined _ALS_GetPlayerFightingStyle
	// Previous hook.
	#define _ALS_GetPlayerFightingStyle__
	#define GetPlayerFightingStyle__( GetPlayerFightingStyle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerVelocity(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerVelocity__(playerid, Float:x, Float:y, Float:z) = SetPlayerVelocity;
#if defined _ALS_SetPlayerVelocity
	// Previous hook.
	#define _ALS_SetPlayerVelocity__
	#define SetPlayerVelocity__( SetPlayerVelocity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerVelocity__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerVelocity;
#if defined _ALS_GetPlayerVelocity
	// Previous hook.
	#define _ALS_GetPlayerVelocity__
	#define GetPlayerVelocity__( GetPlayerVelocity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayCrimeReportForPlayer(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayCrimeReportForPlayer__(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
#if defined _ALS_PlayCrimeReportForPlayer
	// Previous hook.
	#define _ALS_PlayCrimeReportForPlayer__
	#define PlayCrimeReportForPlayer__( PlayCrimeReportForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = false) = PlayAudioStreamForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayAudioStreamForPlayer(playerid, _FIXES_MAYBE_CONST url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, _FIXES_MAYBE_BOOL:usepos = false) = PlayAudioStreamForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayAudioStreamForPlayer__(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false) = PlayAudioStreamForPlayer;
#if defined _ALS_PlayAudioStreamForPlayer
	// Previous hook.
	#define _ALS_PlayAudioStreamForPlayer__
	#define PlayAudioStreamForPlayer__( PlayAudioStreamForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_StopAudioStreamForPlayer(playerid) = StopAudioStreamForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native StopAudioStreamForPlayer__(playerid) = StopAudioStreamForPlayer;
#if defined _ALS_StopAudioStreamForPlayer
	// Previous hook.
	#define _ALS_StopAudioStreamForPlayer__
	#define StopAudioStreamForPlayer__( StopAudioStreamForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerShopName(playerid, shopName[]) = SetPlayerShopName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerShopName(playerid, _FIXES_MAYBE_CONST shopName[]) = SetPlayerShopName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerShopName__(playerid, const shopName[]) = SetPlayerShopName;
#if defined _ALS_SetPlayerShopName
	// Previous hook.
	#define _ALS_SetPlayerShopName__
	#define SetPlayerShopName__( SetPlayerShopName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerSkillLevel__(playerid, WEAPONSKILL:skill, level) = SetPlayerSkillLevel;
#if defined _ALS_SetPlayerSkillLevel
	// Previous hook.
	#define _ALS_SetPlayerSkillLevel__
	#define SetPlayerSkillLevel__( SetPlayerSkillLevel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerSurfingVehicleID(playerid) = GetPlayerSurfingVehicleID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerSurfingVehicleID__(playerid) = GetPlayerSurfingVehicleID;
#if defined _ALS_GetPlayerSurfingVehicleID
	// Previous hook.
	#define _ALS_GetPlayerSurfingVehicleID__
	#define GetPlayerSurfingVehicleID__( GetPlayerSurfingVehicleID(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerSurfingObjectID(playerid) = GetPlayerSurfingObjectID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerSurfingObjectID__(playerid) = GetPlayerSurfingObjectID;
#if defined _ALS_GetPlayerSurfingObjectID
	// Previous hook.
	#define _ALS_GetPlayerSurfingObjectID__
	#define GetPlayerSurfingObjectID__( GetPlayerSurfingObjectID(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RemoveBuildingForPlayer__(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius) = RemoveBuildingForPlayer;
#if defined _ALS_RemoveBuildingForPlayer
	// Previous hook.
	#define _ALS_RemoveBuildingForPlayer__
	#define RemoveBuildingForPlayer__( RemoveBuildingForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerLastShotVectors__(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ) = GetPlayerLastShotVectors;
#if defined _ALS_GetPlayerLastShotVectors
	// Previous hook.
	#define _ALS_GetPlayerLastShotVectors__
	#define GetPlayerLastShotVectors__( GetPlayerLastShotVectors(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerAttachedObject__(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0) = SetPlayerAttachedObject;
#if defined _ALS_SetPlayerAttachedObject
	// Previous hook.
	#define _ALS_SetPlayerAttachedObject__
	#define SetPlayerAttachedObject__( SetPlayerAttachedObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RemovePlayerAttachedObject__(playerid, index) = RemovePlayerAttachedObject;
#if defined _ALS_RemovePlayerAttachedObject
	// Previous hook.
	#define _ALS_RemovePlayerAttachedObject__
	#define RemovePlayerAttachedObject__( RemovePlayerAttachedObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerAttachedObjectSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerAttachedObjectSlotUsed__(playerid, index) = IsPlayerAttachedObjectSlotUsed;
#if defined _ALS_IsPlayerAttachedObjectSlotUsed
	// Previous hook.
	#define _ALS_IsPlayerAttachedObjectSlotUsed__
	#define IsPlayerAttachedObjectSlotUsed__( IsPlayerAttachedObjectSlotUsed(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EditAttachedObject(playerid, index) = EditAttachedObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EditAttachedObject(playerid, index) = EditAttachedObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EditAttachedObject__(playerid, index) = EditAttachedObject;
#if defined _ALS_EditAttachedObject
	// Previous hook.
	#define _ALS_EditAttachedObject__
	#define EditAttachedObject__( EditAttachedObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native PlayerText:CST_CreatePlayerTextDraw(playerid, Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = CreatePlayerTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerText:CreatePlayerTextDraw__(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
#if defined _ALS_CreatePlayerTextDraw
	// Previous hook.
	#define _ALS_CreatePlayerTextDraw__
	#define CreatePlayerTextDraw__( CreatePlayerTextDraw(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawDestroy(playerid, PlayerText:text) = PlayerTextDrawDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawDestroy__(playerid, PlayerText:text) = PlayerTextDrawDestroy;
#if defined _ALS_PlayerTextDrawDestroy
	// Previous hook.
	#define _ALS_PlayerTextDrawDestroy__
	#define PlayerTextDrawDestroy__( PlayerTextDrawDestroy(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawLetterSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawLetterSize;
#if defined _ALS_PlayerTextDrawLetterSize
	// Previous hook.
	#define _ALS_PlayerTextDrawLetterSize__
	#define PlayerTextDrawLetterSize__( PlayerTextDrawLetterSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawTextSize__(playerid, PlayerText:text, Float:width, Float:height) = PlayerTextDrawTextSize;
#if defined _ALS_PlayerTextDrawTextSize
	// Previous hook.
	#define _ALS_PlayerTextDrawTextSize__
	#define PlayerTextDrawTextSize__( PlayerTextDrawTextSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawAlignment__(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment) = PlayerTextDrawAlignment;
#if defined _ALS_PlayerTextDrawAlignment
	// Previous hook.
	#define _ALS_PlayerTextDrawAlignment__
	#define PlayerTextDrawAlignment__( PlayerTextDrawAlignment(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawColor(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawColor__(playerid, PlayerText:text, colour) = PlayerTextDrawColor;
#if defined _ALS_PlayerTextDrawColor
	// Previous hook.
	#define _ALS_PlayerTextDrawColor__
	#define PlayerTextDrawColor__( PlayerTextDrawColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawUseBox(playerid, PlayerText:text, use) = PlayerTextDrawUseBox;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawUseBox(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:use) = PlayerTextDrawUseBox;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawUseBox__(playerid, PlayerText:text, bool:use) = PlayerTextDrawUseBox;
#if defined _ALS_PlayerTextDrawUseBox
	// Previous hook.
	#define _ALS_PlayerTextDrawUseBox__
	#define PlayerTextDrawUseBox__( PlayerTextDrawUseBox(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawBoxColor(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawBoxColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBoxColor;
#if defined _ALS_PlayerTextDrawBoxColor
	// Previous hook.
	#define _ALS_PlayerTextDrawBoxColor__
	#define PlayerTextDrawBoxColor__( PlayerTextDrawBoxColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetShadow(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetShadow__(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
#if defined _ALS_PlayerTextDrawSetShadow
	// Previous hook.
	#define _ALS_PlayerTextDrawSetShadow__
	#define PlayerTextDrawSetShadow__( PlayerTextDrawSetShadow(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetOutline(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetOutline__(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
#if defined _ALS_PlayerTextDrawSetOutline
	// Previous hook.
	#define _ALS_PlayerTextDrawSetOutline__
	#define PlayerTextDrawSetOutline__( PlayerTextDrawSetOutline(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawBackgroundColor__(playerid, PlayerText:text, colour) = PlayerTextDrawBackgroundColor;
#if defined _ALS_PlayerTextDrawBackgroundColor
	// Previous hook.
	#define _ALS_PlayerTextDrawBackgroundColor__
	#define PlayerTextDrawBackgroundColor__( PlayerTextDrawBackgroundColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawFont(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawFont__(playerid, PlayerText:text, TEXT_DRAW_FONT:font) = PlayerTextDrawFont;
#if defined _ALS_PlayerTextDrawFont
	// Previous hook.
	#define _ALS_PlayerTextDrawFont__
	#define PlayerTextDrawFont__( PlayerTextDrawFont(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetProportional(playerid, PlayerText:text, set) = PlayerTextDrawSetProportional;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetProportional(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetProportional;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetProportional__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetProportional;
#if defined _ALS_PlayerTextDrawSetProportional
	// Previous hook.
	#define _ALS_PlayerTextDrawSetProportional__
	#define PlayerTextDrawSetProportional__( PlayerTextDrawSetProportional(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetSelectable(playerid, PlayerText:text, set) = PlayerTextDrawSetSelectable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetSelectable(playerid, PlayerText:text, _FIXES_MAYBE_BOOL:set) = PlayerTextDrawSetSelectable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetSelectable__(playerid, PlayerText:text, bool:set) = PlayerTextDrawSetSelectable;
#if defined _ALS_PlayerTextDrawSetSelectable
	// Previous hook.
	#define _ALS_PlayerTextDrawSetSelectable__
	#define PlayerTextDrawSetSelectable__( PlayerTextDrawSetSelectable(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawShow(playerid, PlayerText:text) = PlayerTextDrawShow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawShow__(playerid, PlayerText:text) = PlayerTextDrawShow;
#if defined _ALS_PlayerTextDrawShow
	// Previous hook.
	#define _ALS_PlayerTextDrawShow__
	#define PlayerTextDrawShow__( PlayerTextDrawShow(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawHide(playerid, PlayerText:text) = PlayerTextDrawHide;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawHide__(playerid, PlayerText:text) = PlayerTextDrawHide;
#if defined _ALS_PlayerTextDrawHide
	// Previous hook.
	#define _ALS_PlayerTextDrawHide__
	#define PlayerTextDrawHide__( PlayerTextDrawHide(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetString(playerid, PlayerText:text, _FIXES_MAYBE_CONST string[]) = PlayerTextDrawSetString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetString__(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
#if defined _ALS_PlayerTextDrawSetString
	// Previous hook.
	#define _ALS_PlayerTextDrawSetString__
	#define PlayerTextDrawSetString__( PlayerTextDrawSetString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetPreviewModel__(playerid, PlayerText:text, modelIndex) = PlayerTextDrawSetPreviewModel;
#if defined _ALS_PlayerTextDrawSetPreviewModel
	// Previous hook.
	#define _ALS_PlayerTextDrawSetPreviewModel__
	#define PlayerTextDrawSetPreviewModel__( PlayerTextDrawSetPreviewModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetPreviewRot__(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = PlayerTextDrawSetPreviewRot;
#if defined _ALS_PlayerTextDrawSetPreviewRot
	// Previous hook.
	#define _ALS_PlayerTextDrawSetPreviewRot__
	#define PlayerTextDrawSetPreviewRot__( PlayerTextDrawSetPreviewRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerTextDrawSetPreviewVehCol__(playerid, PlayerText:text, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
#if defined _ALS_PlayerTextDrawSetPreviewVehCol
	// Previous hook.
	#define _ALS_PlayerTextDrawSetPreviewVehCol__
	#define PlayerTextDrawSetPreviewVehCol__( PlayerTextDrawSetPreviewVehCol(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPVarInt(playerid, pvar[], value) = SetPVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[], value) = SetPVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPVarInt__(playerid, const pvar[], value) = SetPVarInt;
#if defined _ALS_SetPVarInt
	// Previous hook.
	#define _ALS_SetPVarInt__
	#define SetPVarInt__( SetPVarInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPVarInt(playerid, pvar[]) = GetPVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPVarInt(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPVarInt__(playerid, const pvar[]) = GetPVarInt;
#if defined _ALS_GetPVarInt
	// Previous hook.
	#define _ALS_GetPVarInt__
	#define GetPVarInt__( GetPVarInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPVarString(playerid, pvar[], value[]) = SetPVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], _FIXES_MAYBE_CONST value[]) = SetPVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPVarString__(playerid, const pvar[], const value[]) = SetPVarString;
#if defined _ALS_SetPVarString
	// Previous hook.
	#define _ALS_SetPVarString__
	#define SetPVarString__( SetPVarString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPVarString(playerid, pvar[], output[], len) = GetPVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPVarString(playerid, _FIXES_MAYBE_CONST pvar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetPVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPVarString__(playerid, const pvar[], output[], len = sizeof (output)) = GetPVarString;
#if defined _ALS_GetPVarString
	// Previous hook.
	#define _ALS_GetPVarString__
	#define GetPVarString__( GetPVarString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPVarFloat(playerid, pvar[], Float:value) = SetPVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[], Float:value) = SetPVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPVarFloat__(playerid, const pvar[], Float:value) = SetPVarFloat;
#if defined _ALS_SetPVarFloat
	// Previous hook.
	#define _ALS_SetPVarFloat__
	#define SetPVarFloat__( SetPVarFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetPVarFloat(playerid, pvar[]) = GetPVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetPVarFloat(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetPVarFloat__(playerid, const pvar[]) = GetPVarFloat;
#if defined _ALS_GetPVarFloat
	// Previous hook.
	#define _ALS_GetPVarFloat__
	#define GetPVarFloat__( GetPVarFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DeletePVar(playerid, pvar[]) = DeletePVar;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DeletePVar(playerid, _FIXES_MAYBE_CONST pvar[]) = DeletePVar;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DeletePVar__(playerid, const pvar[]) = DeletePVar;
#if defined _ALS_DeletePVar
	// Previous hook.
	#define _ALS_DeletePVar__
	#define DeletePVar__( DeletePVar(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPVarsUpperIndex(playerid) = GetPVarsUpperIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPVarsUpperIndex__(playerid) = GetPVarsUpperIndex;
#if defined _ALS_GetPVarsUpperIndex
	// Previous hook.
	#define _ALS_GetPVarsUpperIndex__
	#define GetPVarsUpperIndex__( GetPVarsUpperIndex(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPVarNameAtIndex(playerid, index, output[], size) = GetPVarNameAtIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPVarNameAtIndex(playerid, index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPVarNameAtIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPVarNameAtIndex__(playerid, index, output[], size = sizeof (output)) = GetPVarNameAtIndex;
#if defined _ALS_GetPVarNameAtIndex
	// Previous hook.
	#define _ALS_GetPVarNameAtIndex__
	#define GetPVarNameAtIndex__( GetPVarNameAtIndex(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native PLAYER_VARTYPE:BAD_GetPVarType(playerid, pvar[]) = GetPVarType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native PLAYER_VARTYPE:CST_GetPVarType(playerid, _FIXES_MAYBE_CONST pvar[]) = GetPVarType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PLAYER_VARTYPE:GetPVarType__(playerid, const pvar[]) = GetPVarType;
#if defined _ALS_GetPVarType
	// Previous hook.
	#define _ALS_GetPVarType__
	#define GetPVarType__( GetPVarType(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerChatBubble(playerid, text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerChatBubble(playerid, _FIXES_MAYBE_CONST text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerChatBubble__(playerid, const text[], colour, Float:drawDistance, expireTime) = SetPlayerChatBubble;
#if defined _ALS_SetPlayerChatBubble
	// Previous hook.
	#define _ALS_SetPlayerChatBubble__
	#define SetPlayerChatBubble__( SetPlayerChatBubble(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PutPlayerInVehicle__(playerid, vehicleid, seatid) = PutPlayerInVehicle;
#if defined _ALS_PutPlayerInVehicle
	// Previous hook.
	#define _ALS_PutPlayerInVehicle__
	#define PutPlayerInVehicle__( PutPlayerInVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerVehicleID(playerid) = GetPlayerVehicleID;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerVehicleID__(playerid) = GetPlayerVehicleID;
#if defined _ALS_GetPlayerVehicleID
	// Previous hook.
	#define _ALS_GetPlayerVehicleID__
	#define GetPlayerVehicleID__( GetPlayerVehicleID(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerVehicleSeat(playerid) = GetPlayerVehicleSeat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerVehicleSeat__(playerid) = GetPlayerVehicleSeat;
#if defined _ALS_GetPlayerVehicleSeat
	// Previous hook.
	#define _ALS_GetPlayerVehicleSeat__
	#define GetPlayerVehicleSeat__( GetPlayerVehicleSeat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RemovePlayerFromVehicle(playerid) = RemovePlayerFromVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RemovePlayerFromVehicle__(playerid) = RemovePlayerFromVehicle;
#if defined _ALS_RemovePlayerFromVehicle
	// Previous hook.
	#define _ALS_RemovePlayerFromVehicle__
	#define RemovePlayerFromVehicle__( RemovePlayerFromVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TogglePlayerControllable(playerid, toggle) = TogglePlayerControllable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TogglePlayerControllable(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerControllable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TogglePlayerControllable__(playerid, bool:toggle) = TogglePlayerControllable;
#if defined _ALS_TogglePlayerControllable
	// Previous hook.
	#define _ALS_TogglePlayerControllable__
	#define TogglePlayerControllable__( TogglePlayerControllable(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerPlaySound__(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
#if defined _ALS_PlayerPlaySound
	// Previous hook.
	#define _ALS_PlayerPlaySound__
	#define PlayerPlaySound__( PlayerPlaySound(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ApplyAnimation(playerid, animationLibrary[], animationName[], Float:delta, loop, lockX, lockY, freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ApplyAnimation(playerid, _FIXES_MAYBE_CONST animationLibrary[], _FIXES_MAYBE_CONST animationName[], Float:delta, _FIXES_MAYBE_BOOL:loop, _FIXES_MAYBE_BOOL:lockX, _FIXES_MAYBE_BOOL:lockY, _FIXES_MAYBE_BOOL:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ApplyAnimation__(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE) = ApplyAnimation;
#if defined _ALS_ApplyAnimation
	// Previous hook.
	#define _ALS_ApplyAnimation__
	#define ApplyAnimation__( ApplyAnimation(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ClearAnimations__(playerid, FORCE_SYNC:forceSync = SYNC_NONE) = ClearAnimations;
#if defined _ALS_ClearAnimations
	// Previous hook.
	#define _ALS_ClearAnimations__
	#define ClearAnimations__( ClearAnimations(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerAnimationIndex(playerid) = GetPlayerAnimationIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerAnimationIndex__(playerid) = GetPlayerAnimationIndex;
#if defined _ALS_GetPlayerAnimationIndex
	// Previous hook.
	#define _ALS_GetPlayerAnimationIndex__
	#define GetPlayerAnimationIndex__( GetPlayerAnimationIndex(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2) = GetAnimationName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetAnimationName(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], _FIXES_MAYBE_SIZEOF(len2, animationName)) = GetAnimationName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetAnimationName__(index, animationLibrary[], _FIXES_MAYBE_SIZEOF(len1, animationLibrary), animationName[], len2 = sizeof (animationName)) = GetAnimationName;
#if defined _ALS_GetAnimationName
	// Previous hook.
	#define _ALS_GetAnimationName__
	#define GetAnimationName__( GetAnimationName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native SPECIAL_ACTION:BAD_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native SPECIAL_ACTION:CST_GetPlayerSpecialAction(playerid) = GetPlayerSpecialAction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SPECIAL_ACTION:GetPlayerSpecialAction__(playerid) = GetPlayerSpecialAction;
#if defined _ALS_GetPlayerSpecialAction
	// Previous hook.
	#define _ALS_GetPlayerSpecialAction__
	#define GetPlayerSpecialAction__( GetPlayerSpecialAction(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerSpecialAction__(playerid, SPECIAL_ACTION:actionid) = SetPlayerSpecialAction;
#if defined _ALS_SetPlayerSpecialAction
	// Previous hook.
	#define _ALS_SetPlayerSpecialAction__
	#define SetPlayerSpecialAction__( SetPlayerSpecialAction(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisableRemoteVehicleCollisions(playerid, disable) = DisableRemoteVehicleCollisions;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisableRemoteVehicleCollisions(playerid, _FIXES_MAYBE_BOOL:disable) = DisableRemoteVehicleCollisions;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisableRemoteVehicleCollisions__(playerid, bool:disable) = DisableRemoteVehicleCollisions;
#if defined _ALS_DisableRemoteVehicleCollisions
	// Previous hook.
	#define _ALS_DisableRemoteVehicleCollisions__
	#define DisableRemoteVehicleCollisions__( DisableRemoteVehicleCollisions(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerCheckpoint__(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
#if defined _ALS_SetPlayerCheckpoint
	// Previous hook.
	#define _ALS_SetPlayerCheckpoint__
	#define SetPlayerCheckpoint__( SetPlayerCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisablePlayerCheckpoint__(playerid) = DisablePlayerCheckpoint;
#if defined _ALS_DisablePlayerCheckpoint
	// Previous hook.
	#define _ALS_DisablePlayerCheckpoint__
	#define DisablePlayerCheckpoint__( DisablePlayerCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerRaceCheckpoint__(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size) = SetPlayerRaceCheckpoint;
#if defined _ALS_SetPlayerRaceCheckpoint
	// Previous hook.
	#define _ALS_SetPlayerRaceCheckpoint__
	#define SetPlayerRaceCheckpoint__( SetPlayerRaceCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisablePlayerRaceCheckpoint__(playerid) = DisablePlayerRaceCheckpoint;
#if defined _ALS_DisablePlayerRaceCheckpoint
	// Previous hook.
	#define _ALS_DisablePlayerRaceCheckpoint__
	#define DisablePlayerRaceCheckpoint__( DisablePlayerRaceCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerWorldBounds__(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY) = SetPlayerWorldBounds;
#if defined _ALS_SetPlayerWorldBounds
	// Previous hook.
	#define _ALS_SetPlayerWorldBounds__
	#define SetPlayerWorldBounds__( SetPlayerWorldBounds(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerMarkerForPlayer(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerMarkerForPlayer__(playerid, targetid, colour) = SetPlayerMarkerForPlayer;
#if defined _ALS_SetPlayerMarkerForPlayer
	// Previous hook.
	#define _ALS_SetPlayerMarkerForPlayer__
	#define SetPlayerMarkerForPlayer__( SetPlayerMarkerForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ShowPlayerNameTagForPlayer(playerid, targetid, show) = ShowPlayerNameTagForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ShowPlayerNameTagForPlayer(playerid, targetid, _FIXES_MAYBE_BOOL:show) = ShowPlayerNameTagForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ShowPlayerNameTagForPlayer__(playerid, targetid, bool:show) = ShowPlayerNameTagForPlayer;
#if defined _ALS_ShowPlayerNameTagForPlayer
	// Previous hook.
	#define _ALS_ShowPlayerNameTagForPlayer__
	#define ShowPlayerNameTagForPlayer__( ShowPlayerNameTagForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerMapIcon__(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL) = SetPlayerMapIcon;
#if defined _ALS_SetPlayerMapIcon
	// Previous hook.
	#define _ALS_SetPlayerMapIcon__
	#define SetPlayerMapIcon__( SetPlayerMapIcon(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RemovePlayerMapIcon(playerid, iconid) = RemovePlayerMapIcon;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RemovePlayerMapIcon__(playerid, iconid) = RemovePlayerMapIcon;
#if defined _ALS_RemovePlayerMapIcon
	// Previous hook.
	#define _ALS_RemovePlayerMapIcon__
	#define RemovePlayerMapIcon__( RemovePlayerMapIcon(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AllowPlayerTeleport(playerid, allow) = AllowPlayerTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AllowPlayerTeleport(playerid, _FIXES_MAYBE_BOOL:allow) = AllowPlayerTeleport;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AllowPlayerTeleport__(playerid, bool:allow) = AllowPlayerTeleport;
#if defined _ALS_AllowPlayerTeleport
	// Previous hook.
	#define _ALS_AllowPlayerTeleport__
	#define AllowPlayerTeleport__( AllowPlayerTeleport(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerCameraPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
#if defined _ALS_SetPlayerCameraPos
	// Previous hook.
	#define _ALS_SetPlayerCameraPos__
	#define SetPlayerCameraPos__( SetPlayerCameraPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerCameraLookAt__(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT) = SetPlayerCameraLookAt;
#if defined _ALS_SetPlayerCameraLookAt
	// Previous hook.
	#define _ALS_SetPlayerCameraLookAt__
	#define SetPlayerCameraLookAt__( SetPlayerCameraLookAt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetCameraBehindPlayer(playerid) = SetCameraBehindPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetCameraBehindPlayer__(playerid) = SetCameraBehindPlayer;
#if defined _ALS_SetCameraBehindPlayer
	// Previous hook.
	#define _ALS_SetCameraBehindPlayer__
	#define SetCameraBehindPlayer__( SetCameraBehindPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
#if defined _ALS_GetPlayerCameraPos
	// Previous hook.
	#define _ALS_GetPlayerCameraPos__
	#define GetPlayerCameraPos__( GetPlayerCameraPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraFrontVector__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
#if defined _ALS_GetPlayerCameraFrontVector
	// Previous hook.
	#define _ALS_GetPlayerCameraFrontVector__
	#define GetPlayerCameraFrontVector__( GetPlayerCameraFrontVector(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native CAM_MODE:BAD_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CAM_MODE:CST_GetPlayerCameraMode(playerid) = GetPlayerCameraMode;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CAM_MODE:GetPlayerCameraMode__(playerid) = GetPlayerCameraMode;
#if defined _ALS_GetPlayerCameraMode
	// Previous hook.
	#define _ALS_GetPlayerCameraMode__
	#define GetPlayerCameraMode__( GetPlayerCameraMode(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnablePlayerCameraTarget(playerid, enable) = EnablePlayerCameraTarget;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnablePlayerCameraTarget(playerid, _FIXES_MAYBE_BOOL:enable) = EnablePlayerCameraTarget;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnablePlayerCameraTarget__(playerid, bool:enable) = EnablePlayerCameraTarget;
#if defined _ALS_EnablePlayerCameraTarget
	// Previous hook.
	#define _ALS_EnablePlayerCameraTarget__
	#define EnablePlayerCameraTarget__( EnablePlayerCameraTarget(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraTargetObject(playerid) = GetPlayerCameraTargetObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraTargetObject__(playerid) = GetPlayerCameraTargetObject;
#if defined _ALS_GetPlayerCameraTargetObject
	// Previous hook.
	#define _ALS_GetPlayerCameraTargetObject__
	#define GetPlayerCameraTargetObject__( GetPlayerCameraTargetObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraTargetVehicle(playerid) = GetPlayerCameraTargetVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraTargetVehicle__(playerid) = GetPlayerCameraTargetVehicle;
#if defined _ALS_GetPlayerCameraTargetVehicle
	// Previous hook.
	#define _ALS_GetPlayerCameraTargetVehicle__
	#define GetPlayerCameraTargetVehicle__( GetPlayerCameraTargetVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraTargetPlayer(playerid) = GetPlayerCameraTargetPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraTargetPlayer__(playerid) = GetPlayerCameraTargetPlayer;
#if defined _ALS_GetPlayerCameraTargetPlayer
	// Previous hook.
	#define _ALS_GetPlayerCameraTargetPlayer__
	#define GetPlayerCameraTargetPlayer__( GetPlayerCameraTargetPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerCameraTargetActor(playerid) = GetPlayerCameraTargetActor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerCameraTargetActor__(playerid) = GetPlayerCameraTargetActor;
#if defined _ALS_GetPlayerCameraTargetActor
	// Previous hook.
	#define _ALS_GetPlayerCameraTargetActor__
	#define GetPlayerCameraTargetActor__( GetPlayerCameraTargetActor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetPlayerCameraAspectRatio(playerid) = GetPlayerCameraAspectRatio;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetPlayerCameraAspectRatio__(playerid) = GetPlayerCameraAspectRatio;
#if defined _ALS_GetPlayerCameraAspectRatio
	// Previous hook.
	#define _ALS_GetPlayerCameraAspectRatio__
	#define GetPlayerCameraAspectRatio__( GetPlayerCameraAspectRatio(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetPlayerCameraZoom(playerid) = GetPlayerCameraZoom;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetPlayerCameraZoom__(playerid) = GetPlayerCameraZoom;
#if defined _ALS_GetPlayerCameraZoom
	// Previous hook.
	#define _ALS_GetPlayerCameraZoom__
	#define GetPlayerCameraZoom__( GetPlayerCameraZoom(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachCameraToObject(playerid, objectid) = AttachCameraToObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachCameraToObject__(playerid, objectid) = AttachCameraToObject;
#if defined _ALS_AttachCameraToObject
	// Previous hook.
	#define _ALS_AttachCameraToObject__
	#define AttachCameraToObject__( AttachCameraToObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachCameraToPlayerObject(playerid, objectid) = AttachCameraToPlayerObject;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachCameraToPlayerObject__(playerid, objectid) = AttachCameraToPlayerObject;
#if defined _ALS_AttachCameraToPlayerObject
	// Previous hook.
	#define _ALS_AttachCameraToPlayerObject__
	#define AttachCameraToPlayerObject__( AttachCameraToPlayerObject(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native InterpolateCameraPos__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraPos;
#if defined _ALS_InterpolateCameraPos
	// Previous hook.
	#define _ALS_InterpolateCameraPos__
	#define InterpolateCameraPos__( InterpolateCameraPos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native InterpolateCameraLookAt__(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT) = InterpolateCameraLookAt;
#if defined _ALS_InterpolateCameraLookAt
	// Previous hook.
	#define _ALS_InterpolateCameraLookAt__
	#define InterpolateCameraLookAt__( InterpolateCameraLookAt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerConnected(playerid) = IsPlayerConnected;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerConnected(playerid) = IsPlayerConnected;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerConnected__(playerid) = IsPlayerConnected;
#if defined _ALS_IsPlayerConnected
	// Previous hook.
	#define _ALS_IsPlayerConnected__
	#define IsPlayerConnected__( IsPlayerConnected(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerInVehicle(playerid, vehicleid) = IsPlayerInVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerInVehicle__(playerid, vehicleid) = IsPlayerInVehicle;
#if defined _ALS_IsPlayerInVehicle
	// Previous hook.
	#define _ALS_IsPlayerInVehicle__
	#define IsPlayerInVehicle__( IsPlayerInVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerInAnyVehicle(playerid) = IsPlayerInAnyVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerInAnyVehicle__(playerid) = IsPlayerInAnyVehicle;
#if defined _ALS_IsPlayerInAnyVehicle
	// Previous hook.
	#define _ALS_IsPlayerInAnyVehicle__
	#define IsPlayerInAnyVehicle__( IsPlayerInAnyVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerInCheckpoint(playerid) = IsPlayerInCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerInCheckpoint__(playerid) = IsPlayerInCheckpoint;
#if defined _ALS_IsPlayerInCheckpoint
	// Previous hook.
	#define _ALS_IsPlayerInCheckpoint__
	#define IsPlayerInCheckpoint__( IsPlayerInCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerInRaceCheckpoint(playerid) = IsPlayerInRaceCheckpoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerInRaceCheckpoint__(playerid) = IsPlayerInRaceCheckpoint;
#if defined _ALS_IsPlayerInRaceCheckpoint
	// Previous hook.
	#define _ALS_IsPlayerInRaceCheckpoint__
	#define IsPlayerInRaceCheckpoint__( IsPlayerInRaceCheckpoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetPlayerVirtualWorld(playerid, virtualWorld) = SetPlayerVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetPlayerVirtualWorld__(playerid, virtualWorld) = SetPlayerVirtualWorld;
#if defined _ALS_SetPlayerVirtualWorld
	// Previous hook.
	#define _ALS_SetPlayerVirtualWorld__
	#define SetPlayerVirtualWorld__( SetPlayerVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerVirtualWorld(playerid) = GetPlayerVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerVirtualWorld__(playerid) = GetPlayerVirtualWorld;
#if defined _ALS_GetPlayerVirtualWorld
	// Previous hook.
	#define _ALS_GetPlayerVirtualWorld__
	#define GetPlayerVirtualWorld__( GetPlayerVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnableStuntBonusForPlayer(playerid, enable) = EnableStuntBonusForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnableStuntBonusForPlayer(playerid, _FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnableStuntBonusForPlayer__(playerid, bool:enable) = EnableStuntBonusForPlayer;
#if defined _ALS_EnableStuntBonusForPlayer
	// Previous hook.
	#define _ALS_EnableStuntBonusForPlayer__
	#define EnableStuntBonusForPlayer__( EnableStuntBonusForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnableStuntBonusForAll(enable) = EnableStuntBonusForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnableStuntBonusForAll(_FIXES_MAYBE_BOOL:enable) = EnableStuntBonusForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnableStuntBonusForAll__(bool:enable) = EnableStuntBonusForAll;
#if defined _ALS_EnableStuntBonusForAll
	// Previous hook.
	#define _ALS_EnableStuntBonusForAll__
	#define EnableStuntBonusForAll__( EnableStuntBonusForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TogglePlayerSpectating(playerid, toggle) = TogglePlayerSpectating;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TogglePlayerSpectating(playerid, _FIXES_MAYBE_BOOL:toggle) = TogglePlayerSpectating;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TogglePlayerSpectating__(playerid, bool:toggle) = TogglePlayerSpectating;
#if defined _ALS_TogglePlayerSpectating
	// Previous hook.
	#define _ALS_TogglePlayerSpectating__
	#define TogglePlayerSpectating__( TogglePlayerSpectating(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerSpectatePlayer__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
#if defined _ALS_PlayerSpectatePlayer
	// Previous hook.
	#define _ALS_PlayerSpectatePlayer__
	#define PlayerSpectatePlayer__( PlayerSpectatePlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerSpectateVehicle__(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
#if defined _ALS_PlayerSpectateVehicle
	// Previous hook.
	#define _ALS_PlayerSpectateVehicle__
	#define PlayerSpectateVehicle__( PlayerSpectateVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, recordFile[]) = StartRecordingPlayerData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, _FIXES_MAYBE_CONST recordFile[]) = StartRecordingPlayerData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native StartRecordingPlayerData__(playerid, PLAYER_RECORDING_TYPE:recordType, const recordFile[]) = StartRecordingPlayerData;
#if defined _ALS_StartRecordingPlayerData
	// Previous hook.
	#define _ALS_StartRecordingPlayerData__
	#define StartRecordingPlayerData__( StartRecordingPlayerData(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_StopRecordingPlayerData(playerid) = StopRecordingPlayerData;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native StopRecordingPlayerData__(playerid) = StopRecordingPlayerData;
#if defined _ALS_StopRecordingPlayerData
	// Previous hook.
	#define _ALS_StopRecordingPlayerData__
	#define StopRecordingPlayerData__( StopRecordingPlayerData(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SelectTextDraw(playerid, hoverColour) = SelectTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SelectTextDraw__(playerid, hoverColour) = SelectTextDraw;
#if defined _ALS_SelectTextDraw
	// Previous hook.
	#define _ALS_SelectTextDraw__
	#define SelectTextDraw__( SelectTextDraw(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CancelSelectTextDraw(playerid) = CancelSelectTextDraw;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CancelSelectTextDraw__(playerid) = CancelSelectTextDraw;
#if defined _ALS_CancelSelectTextDraw
	// Previous hook.
	#define _ALS_CancelSelectTextDraw__
	#define CancelSelectTextDraw__( CancelSelectTextDraw(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreateExplosionForPlayer__(playerid, Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosionForPlayer;
#if defined _ALS_CreateExplosionForPlayer
	// Previous hook.
	#define _ALS_CreateExplosionForPlayer__
	#define CreateExplosionForPlayer__( CreateExplosionForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendClientCheck__(playerid, type, memoryAddress, memoryOffset, byteCount) = SendClientCheck;
#if defined _ALS_SendClientCheck
	// Previous hook.
	#define _ALS_SendClientCheck__
	#define SendClientCheck__( SendClientCheck(
#endif

/*

     ¦¦¦¦¦          ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦      ¦¦   ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦
    ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦
    ¦¦   ¦¦              ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦ ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦      ¦¦ ¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_print(const string[]) = print;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_print(const string[]) = print;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native print__(const string[]) = print;
#if defined _ALS_print
	// Previous hook.
	#define _ALS_print__
	#define print__( print(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_printf(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_printf(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native printf__(const format[], {Float, _}:...) = printf;
#if defined _ALS_printf
	// Previous hook.
	#define _ALS_printf__
	#define printf__( printf(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_format(output[], len, const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#if defined _ALS_format
	// Previous hook.
	#define _ALS_format__
	#define format__( format(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Print(const string[]) = print;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Print(const string[]) = print;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Print__(const string[]) = print;
#if defined _ALS_Print
	// Previous hook.
	#define _ALS_Print__
	#define Print__( Print(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_PrintF(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_PrintF(const format[], {Float, _}:...) = printf;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PrintF__(const format[], {Float, _}:...) = printf;
#if defined _ALS_PrintF
	// Previous hook.
	#define _ALS_PrintF__
	#define PrintF__( PrintF(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Format(output[], len, const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Format(output[], _FIXES_MAYBE_SIZEOF(len, output), const format[], {Float, _}:...) = format;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Format__(output[], len = sizeof (output), const format[], {Float, _}:...) = format;
#if defined _ALS_Format
	// Previous hook.
	#define _ALS_Format__
	#define Format__( Format(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendClientMessage(playerid, colour, const message[]) = SendClientMessage;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendClientMessage__(playerid, colour, const message[]) = SendClientMessage;
#if defined _ALS_SendClientMessage
	// Previous hook.
	#define _ALS_SendClientMessage__
	#define SendClientMessage__( SendClientMessage(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendClientMessageToAll(colour, const message[]) = SendClientMessageToAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendClientMessageToAll__(colour, const message[]) = SendClientMessageToAll;
#if defined _ALS_SendClientMessageToAll
	// Previous hook.
	#define _ALS_SendClientMessageToAll__
	#define SendClientMessageToAll__( SendClientMessageToAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendPlayerMessageToPlayer(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendPlayerMessageToPlayer__(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
#if defined _ALS_SendPlayerMessageToPlayer
	// Previous hook.
	#define _ALS_SendPlayerMessageToPlayer__
	#define SendPlayerMessageToPlayer__( SendPlayerMessageToPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendPlayerMessageToAll(senderid, const message[]) = SendPlayerMessageToAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendPlayerMessageToAll__(senderid, const message[]) = SendPlayerMessageToAll;
#if defined _ALS_SendPlayerMessageToAll
	// Previous hook.
	#define _ALS_SendPlayerMessageToAll__
	#define SendPlayerMessageToAll__( SendPlayerMessageToAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendDeathMessage(killer, killee, weapon) = SendDeathMessage;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendDeathMessage__(killer, killee, weapon) = SendDeathMessage;
#if defined _ALS_SendDeathMessage
	// Previous hook.
	#define _ALS_SendDeathMessage__
	#define SendDeathMessage__( SendDeathMessage(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendDeathMessageToPlayer(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendDeathMessageToPlayer__(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
#if defined _ALS_SendDeathMessageToPlayer
	// Previous hook.
	#define _ALS_SendDeathMessageToPlayer__
	#define SendDeathMessageToPlayer__( SendDeathMessageToPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GameTextForAll(const string[], time, style) = GameTextForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GameTextForAll(const string[], time, style) = GameTextForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GameTextForAll__(const string[], time, style) = GameTextForAll;
#if defined _ALS_GameTextForAll
	// Previous hook.
	#define _ALS_GameTextForAll__
	#define GameTextForAll__( GameTextForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GameTextForPlayer__(playerid, const string[], time, style) = GameTextForPlayer;
#if defined _ALS_GameTextForPlayer
	// Previous hook.
	#define _ALS_GameTextForPlayer__
	#define GameTextForPlayer__( GameTextForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetTimer(functionName[], interval, repeating) = SetTimer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetTimer(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating) = SetTimer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetTimer__(const functionName[], interval, bool:repeating) = SetTimer;
#if defined _ALS_SetTimer
	// Previous hook.
	#define _ALS_SetTimer__
	#define SetTimer__( SetTimer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetTimerEx(functionName[], interval, repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetTimerEx(_FIXES_MAYBE_CONST functionName[], interval, _FIXES_MAYBE_BOOL:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetTimerEx__(const functionName[], interval, bool:repeating, const format[] = "", {Float, _}:...) = SetTimerEx;
#if defined _ALS_SetTimerEx
	// Previous hook.
	#define _ALS_SetTimerEx__
	#define SetTimerEx__( SetTimerEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_KillTimer(timerid) = KillTimer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_KillTimer(timerid) = KillTimer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native KillTimer__(timerid) = KillTimer;
#if defined _ALS_KillTimer
	// Previous hook.
	#define _ALS_KillTimer__
	#define KillTimer__( KillTimer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetTickCount() = GetTickCount;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetTickCount() = GetTickCount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetTickCount__() = GetTickCount;
#if defined _ALS_GetTickCount
	// Previous hook.
	#define _ALS_GetTickCount__
	#define GetTickCount__( GetTickCount(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetMaxPlayers() = GetMaxPlayers;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetMaxPlayers() = GetMaxPlayers;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetMaxPlayers__() = GetMaxPlayers;
#if defined _ALS_GetMaxPlayers
	// Previous hook.
	#define _ALS_GetMaxPlayers__
	#define GetMaxPlayers__( GetMaxPlayers(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CallRemoteFunction(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CallRemoteFunction__(const function[], const format[] = "", {Float, _}:...) = CallRemoteFunction;
#if defined _ALS_CallRemoteFunction
	// Previous hook.
	#define _ALS_CallRemoteFunction__
	#define CallRemoteFunction__( CallRemoteFunction(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CallLocalFunction(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CallLocalFunction__(const function[], const format[] = "", {Float, _}:...) = CallLocalFunction;
#if defined _ALS_CallLocalFunction
	// Previous hook.
	#define _ALS_CallLocalFunction__
	#define CallLocalFunction__( CallLocalFunction(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_VectorSize(Float:x, Float:y, Float:z) = VectorSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:VectorSize__(Float:x, Float:y, Float:z) = VectorSize;
#if defined _ALS_VectorSize
	// Previous hook.
	#define _ALS_VectorSize__
	#define VectorSize__( VectorSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_asin(Float:value) = asin;
#if FIX_camel_case
	#pragma deprecated Use `ASin`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_asin(Float:value) = asin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:asin__(Float:value) = asin;
#if defined _ALS_asin
	// Previous hook.
	#define _ALS_asin__
	#define asin__( asin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_acos(Float:value) = acos;
#if FIX_camel_case
	#pragma deprecated Use `ACos`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_acos(Float:value) = acos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:acos__(Float:value) = acos;
#if defined _ALS_acos
	// Previous hook.
	#define _ALS_acos__
	#define acos__( acos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_atan(Float:value) = atan;
#if FIX_camel_case
	#pragma deprecated Use `ATan`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_atan(Float:value) = atan;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:atan__(Float:value) = atan;
#if defined _ALS_atan
	// Previous hook.
	#define _ALS_atan__
	#define atan__( atan(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_atan2(Float:y, Float:x) = atan2;
#if FIX_camel_case
	#pragma deprecated Use `ATan2`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_atan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:atan2__(Float:y, Float:x) = atan2;
#if defined _ALS_atan2
	// Previous hook.
	#define _ALS_atan2__
	#define atan2__( atan2(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_ASin(Float:value) = asin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_ASin(Float:value) = asin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:ASin__(Float:value) = asin;
#if defined _ALS_ASin
	// Previous hook.
	#define _ALS_ASin__
	#define ASin__( ASin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_ACos(Float:value) = acos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_ACos(Float:value) = acos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:ACos__(Float:value) = acos;
#if defined _ALS_ACos
	// Previous hook.
	#define _ALS_ACos__
	#define ACos__( ACos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_ATan(Float:value) = atan;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_ATan(Float:value) = atan;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:ATan__(Float:value) = atan;
#if defined _ALS_ATan
	// Previous hook.
	#define _ALS_ATan__
	#define ATan__( ATan(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_ATan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_ATan2(Float:y, Float:x) = atan2;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:ATan2__(Float:y, Float:x) = atan2;
#if defined _ALS_ATan2
	// Previous hook.
	#define _ALS_ATan2__
	#define ATan2__( ATan2(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerPoolSize() = GetPlayerPoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerPoolSize() = GetPlayerPoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerPoolSize__() = GetPlayerPoolSize;
#if defined _ALS_GetPlayerPoolSize
	// Previous hook.
	#define _ALS_GetPlayerPoolSize__
	#define GetPlayerPoolSize__( GetPlayerPoolSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehiclePoolSize() = GetVehiclePoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehiclePoolSize() = GetVehiclePoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehiclePoolSize__() = GetVehiclePoolSize;
#if defined _ALS_GetVehiclePoolSize
	// Previous hook.
	#define _ALS_GetVehiclePoolSize__
	#define GetVehiclePoolSize__( GetVehiclePoolSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetActorPoolSize() = GetActorPoolSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetActorPoolSize() = GetActorPoolSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetActorPoolSize__() = GetActorPoolSize;
#if defined _ALS_GetActorPoolSize
	// Previous hook.
	#define _ALS_GetActorPoolSize__
	#define GetActorPoolSize__( GetActorPoolSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SHA256_PassHash(password[], salt[], output[], size) = SHA256_PassHash;
#pragma deprecated Use BCrypt for hashing passwords.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SHA256_PassHash(_FIXES_MAYBE_CONST password[], _FIXES_MAYBE_CONST salt[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = SHA256_PassHash;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SHA256_PassHash__(const password[], const salt[], output[], size = sizeof (output)) = SHA256_PassHash;
#if defined _ALS_SHA256_PassHash
	// Previous hook.
	#define _ALS_SHA256_PassHash__
	#define SHA256_PassHash__( SHA256_PassHash(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetSVarInt(svar[], value) = SetSVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetSVarInt(_FIXES_MAYBE_CONST svar[], value) = SetSVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetSVarInt__(const svar[], value) = SetSVarInt;
#if defined _ALS_SetSVarInt
	// Previous hook.
	#define _ALS_SetSVarInt__
	#define SetSVarInt__( SetSVarInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetSVarInt(svar[]) = GetSVarInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetSVarInt(_FIXES_MAYBE_CONST svar[]) = GetSVarInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetSVarInt__(const svar[]) = GetSVarInt;
#if defined _ALS_GetSVarInt
	// Previous hook.
	#define _ALS_GetSVarInt__
	#define GetSVarInt__( GetSVarInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetSVarString(svar[], value[]) = SetSVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetSVarString(_FIXES_MAYBE_CONST svar[], _FIXES_MAYBE_CONST value[]) = SetSVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetSVarString__(const svar[], const value[]) = SetSVarString;
#if defined _ALS_SetSVarString
	// Previous hook.
	#define _ALS_SetSVarString__
	#define SetSVarString__( SetSVarString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetSVarString(svar[], output[], len) = GetSVarString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetSVarString(_FIXES_MAYBE_CONST svar[], output[], _FIXES_MAYBE_SIZEOF(len, output)) = GetSVarString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetSVarString__(const svar[], output[], len = sizeof (output)) = GetSVarString;
#if defined _ALS_GetSVarString
	// Previous hook.
	#define _ALS_GetSVarString__
	#define GetSVarString__( GetSVarString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetSVarFloat(svar[], Float:value) = SetSVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetSVarFloat(_FIXES_MAYBE_CONST svar[], Float:value) = SetSVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetSVarFloat__(const svar[], Float:value) = SetSVarFloat;
#if defined _ALS_SetSVarFloat
	// Previous hook.
	#define _ALS_SetSVarFloat__
	#define SetSVarFloat__( SetSVarFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetSVarFloat(svar[]) = GetSVarFloat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetSVarFloat(_FIXES_MAYBE_CONST svar[]) = GetSVarFloat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetSVarFloat__(const svar[]) = GetSVarFloat;
#if defined _ALS_GetSVarFloat
	// Previous hook.
	#define _ALS_GetSVarFloat__
	#define GetSVarFloat__( GetSVarFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DeleteSVar(svar[]) = DeleteSVar;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DeleteSVar(_FIXES_MAYBE_CONST svar[]) = DeleteSVar;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DeleteSVar__(const svar[]) = DeleteSVar;
#if defined _ALS_DeleteSVar
	// Previous hook.
	#define _ALS_DeleteSVar__
	#define DeleteSVar__( DeleteSVar(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetSVarsUpperIndex() = GetSVarsUpperIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetSVarsUpperIndex() = GetSVarsUpperIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetSVarsUpperIndex__() = GetSVarsUpperIndex;
#if defined _ALS_GetSVarsUpperIndex
	// Previous hook.
	#define _ALS_GetSVarsUpperIndex__
	#define GetSVarsUpperIndex__( GetSVarsUpperIndex(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetSVarNameAtIndex(index, output[], size) = GetSVarNameAtIndex;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetSVarNameAtIndex(index, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetSVarNameAtIndex;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetSVarNameAtIndex__(index, output[], size = sizeof (output)) = GetSVarNameAtIndex;
#if defined _ALS_GetSVarNameAtIndex
	// Previous hook.
	#define _ALS_GetSVarNameAtIndex__
	#define GetSVarNameAtIndex__( GetSVarNameAtIndex(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native SERVER_VARTYPE:BAD_GetSVarType(svar[]) = GetSVarType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native SERVER_VARTYPE:CST_GetSVarType(_FIXES_MAYBE_CONST svar[]) = GetSVarType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SERVER_VARTYPE:GetSVarType__(const svar[]) = GetSVarType;
#if defined _ALS_GetSVarType
	// Previous hook.
	#define _ALS_GetSVarType__
	#define GetSVarType__( GetSVarType(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetGameModeText(const string[]) = SetGameModeText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetGameModeText(const string[]) = SetGameModeText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetGameModeText__(const string[]) = SetGameModeText;
#if defined _ALS_SetGameModeText
	// Previous hook.
	#define _ALS_SetGameModeText__
	#define SetGameModeText__( SetGameModeText(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetTeamCount(count) = SetTeamCount;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetTeamCount(count) = SetTeamCount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetTeamCount__(count) = SetTeamCount;
#if defined _ALS_SetTeamCount
	// Previous hook.
	#define _ALS_SetTeamCount__
	#define SetTeamCount__( SetTeamCount(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddPlayerClass(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddPlayerClass__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClass;
#if defined _ALS_AddPlayerClass
	// Previous hook.
	#define _ALS_AddPlayerClass__
	#define AddPlayerClass__( AddPlayerClass(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddPlayerClassEx(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddPlayerClassEx__(teamid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3) = AddPlayerClassEx;
#if defined _ALS_AddPlayerClassEx
	// Previous hook.
	#define _ALS_AddPlayerClassEx__
	#define AddPlayerClassEx__( AddPlayerClassEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddStaticVehicle__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2) = AddStaticVehicle;
#if defined _ALS_AddStaticVehicle
	// Previous hook.
	#define _ALS_AddStaticVehicle__
	#define AddStaticVehicle__( AddStaticVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, addSiren = false) = AddStaticVehicleEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = AddStaticVehicleEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddStaticVehicleEx__(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false) = AddStaticVehicleEx;
#if defined _ALS_AddStaticVehicleEx
	// Previous hook.
	#define _ALS_AddStaticVehicleEx__
	#define AddStaticVehicleEx__( AddStaticVehicleEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddStaticPickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = AddStaticPickup;
#if defined _ALS_AddStaticPickup
	// Previous hook.
	#define _ALS_AddStaticPickup__
	#define AddStaticPickup__( AddStaticPickup(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreatePickup__(model, type, Float:x, Float:y, Float:z, virtualWorld = 0) = CreatePickup;
#if defined _ALS_CreatePickup
	// Previous hook.
	#define _ALS_CreatePickup__
	#define CreatePickup__( CreatePickup(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyPickup(pickup) = DestroyPickup;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyPickup(pickup) = DestroyPickup;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyPickup__(pickup) = DestroyPickup;
#if defined _ALS_DestroyPickup
	// Previous hook.
	#define _ALS_DestroyPickup__
	#define DestroyPickup__( DestroyPickup(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ShowNameTags(show) = ShowNameTags;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ShowNameTags(_FIXES_MAYBE_BOOL:show) = ShowNameTags;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ShowNameTags__(bool:show) = ShowNameTags;
#if defined _ALS_ShowNameTags
	// Previous hook.
	#define _ALS_ShowNameTags__
	#define ShowNameTags__( ShowNameTags(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ShowPlayerMarkers__(PLAYER_MARKERS_MODE:mode) = ShowPlayerMarkers;
#if defined _ALS_ShowPlayerMarkers
	// Previous hook.
	#define _ALS_ShowPlayerMarkers__
	#define ShowPlayerMarkers__( ShowPlayerMarkers(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GameModeExit() = GameModeExit;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GameModeExit() = GameModeExit;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GameModeExit__() = GameModeExit;
#if defined _ALS_GameModeExit
	// Previous hook.
	#define _ALS_GameModeExit__
	#define GameModeExit__( GameModeExit(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetWorldTime(hour) = SetWorldTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetWorldTime(hour) = SetWorldTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetWorldTime__(hour) = SetWorldTime;
#if defined _ALS_SetWorldTime
	// Previous hook.
	#define _ALS_SetWorldTime__
	#define SetWorldTime__( SetWorldTime(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetWeaponName(WEAPON:weaponid, const weapon[], len) = GetWeaponName;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetWeaponName(WEAPON:weaponid, _FIXES_NOT_CONST weapon[], _FIXES_MAYBE_SIZEOF(len, weapon)) = GetWeaponName;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetWeaponName__(WEAPON:weaponid, weapon[], len = sizeof (weapon)) = GetWeaponName;
#if defined _ALS_GetWeaponName
	// Previous hook.
	#define _ALS_GetWeaponName__
	#define GetWeaponName__( GetWeaponName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnableTirePopping(enable) = EnableTirePopping;
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnableTirePopping(_FIXES_MAYBE_BOOL:enable) = EnableTirePopping;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnableTirePopping__(bool:enable) = EnableTirePopping;
#if defined _ALS_EnableTirePopping
	// Previous hook.
	#define _ALS_EnableTirePopping__
	#define EnableTirePopping__( EnableTirePopping(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnableVehicleFriendlyFire() = EnableVehicleFriendlyFire;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnableVehicleFriendlyFire__() = EnableVehicleFriendlyFire;
#if defined _ALS_EnableVehicleFriendlyFire
	// Previous hook.
	#define _ALS_EnableVehicleFriendlyFire__
	#define EnableVehicleFriendlyFire__( EnableVehicleFriendlyFire(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AllowInteriorWeapons(allow) = AllowInteriorWeapons;
#pragma deprecated Use `OnPlayerInteriorChange`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AllowInteriorWeapons(_FIXES_MAYBE_BOOL:allow) = AllowInteriorWeapons;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AllowInteriorWeapons__(bool:allow) = AllowInteriorWeapons;
#if defined _ALS_AllowInteriorWeapons
	// Previous hook.
	#define _ALS_AllowInteriorWeapons__
	#define AllowInteriorWeapons__( AllowInteriorWeapons(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetWeather(weatherid) = SetWeather;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetWeather(weatherid) = SetWeather;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetWeather__(weatherid) = SetWeather;
#if defined _ALS_SetWeather
	// Previous hook.
	#define _ALS_SetWeather__
	#define SetWeather__( SetWeather(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetGravity() = GetGravity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetGravity() = GetGravity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetGravity__() = GetGravity;
#if defined _ALS_GetGravity
	// Previous hook.
	#define _ALS_GetGravity__
	#define GetGravity__( GetGravity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetGravity(Float:gravity) = SetGravity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetGravity(Float:gravity) = SetGravity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetGravity__(Float:gravity) = SetGravity;
#if defined _ALS_SetGravity
	// Previous hook.
	#define _ALS_SetGravity__
	#define SetGravity__( SetGravity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AllowAdminTeleport(allow) = AllowAdminTeleport;
#pragma deprecated Use `OnPlayerClickMap`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AllowAdminTeleport(_FIXES_MAYBE_BOOL:allow) = AllowAdminTeleport;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AllowAdminTeleport__(bool:allow) = AllowAdminTeleport;
#if defined _ALS_AllowAdminTeleport
	// Previous hook.
	#define _ALS_AllowAdminTeleport__
	#define AllowAdminTeleport__( AllowAdminTeleport(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetDeathDropAmount(amount) = SetDeathDropAmount;
#pragma deprecated Use `CreatePickup`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetDeathDropAmount(amount) = SetDeathDropAmount;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetDeathDropAmount__(amount) = SetDeathDropAmount;
#if defined _ALS_SetDeathDropAmount
	// Previous hook.
	#define _ALS_SetDeathDropAmount__
	#define SetDeathDropAmount__( SetDeathDropAmount(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreateExplosion__(Float:x, Float:y, Float:z, type, Float:radius) = CreateExplosion;
#if defined _ALS_CreateExplosion
	// Previous hook.
	#define _ALS_CreateExplosion__
	#define CreateExplosion__( CreateExplosion(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_EnableZoneNames(enable) = EnableZoneNames;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_EnableZoneNames(_FIXES_MAYBE_BOOL:enable) = EnableZoneNames;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native EnableZoneNames__(bool:enable) = EnableZoneNames;
#if defined _ALS_EnableZoneNames
	// Previous hook.
	#define _ALS_EnableZoneNames__
	#define EnableZoneNames__( EnableZoneNames(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_UsePlayerPedAnims() = UsePlayerPedAnims;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_UsePlayerPedAnims() = UsePlayerPedAnims;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native UsePlayerPedAnims__() = UsePlayerPedAnims;
#if defined _ALS_UsePlayerPedAnims
	// Previous hook.
	#define _ALS_UsePlayerPedAnims__
	#define UsePlayerPedAnims__( UsePlayerPedAnims(
#endif

native DisableInteriorEnterExits();
/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetNameTagDrawDistance(Float:distance) = SetNameTagDrawDistance;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetNameTagDrawDistance__(Float:distance) = SetNameTagDrawDistance;
#if defined _ALS_SetNameTagDrawDistance
	// Previous hook.
	#define _ALS_SetNameTagDrawDistance__
	#define SetNameTagDrawDistance__( SetNameTagDrawDistance(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisableNameTagLOS() = DisableNameTagLOS;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisableNameTagLOS() = DisableNameTagLOS;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisableNameTagLOS__() = DisableNameTagLOS;
#if defined _ALS_DisableNameTagLOS
	// Previous hook.
	#define _ALS_DisableNameTagLOS__
	#define DisableNameTagLOS__( DisableNameTagLOS(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_LimitGlobalChatRadius(Float:chatRadius) = LimitGlobalChatRadius;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native LimitGlobalChatRadius__(Float:chatRadius) = LimitGlobalChatRadius;
#if defined _ALS_LimitGlobalChatRadius
	// Previous hook.
	#define _ALS_LimitGlobalChatRadius__
	#define LimitGlobalChatRadius__( LimitGlobalChatRadius(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_LimitPlayerMarkerRadius(Float:markerRadius) = LimitPlayerMarkerRadius;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native LimitPlayerMarkerRadius__(Float:markerRadius) = LimitPlayerMarkerRadius;
#if defined _ALS_LimitPlayerMarkerRadius
	// Previous hook.
	#define _ALS_LimitPlayerMarkerRadius__
	#define LimitPlayerMarkerRadius__( LimitPlayerMarkerRadius(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ConnectNPC(name[], script[]) = ConnectNPC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ConnectNPC(_FIXES_MAYBE_CONST name[], _FIXES_MAYBE_CONST script[]) = ConnectNPC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ConnectNPC__(const name[], const script[]) = ConnectNPC;
#if defined _ALS_ConnectNPC
	// Previous hook.
	#define _ALS_ConnectNPC__
	#define ConnectNPC__( ConnectNPC(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerNPC(playerid) = IsPlayerNPC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerNPC(playerid) = IsPlayerNPC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerNPC__(playerid) = IsPlayerNPC;
#if defined _ALS_IsPlayerNPC
	// Previous hook.
	#define _ALS_IsPlayerNPC__
	#define IsPlayerNPC__( IsPlayerNPC(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddCharModel(baseid, newid, dff[], textureLibrary[]) = AddCharModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddCharModel(baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddCharModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddCharModel__(baseid, newid, const dff[], const textureLibrary[]) = AddCharModel;
#if defined _ALS_AddCharModel
	// Previous hook.
	#define _ALS_AddCharModel__
	#define AddCharModel__( AddCharModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddSimpleModel(virtualWorld, baseid, newid, dff[], textureLibrary[]) = AddSimpleModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddSimpleModel(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[]) = AddSimpleModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddSimpleModel__(virtualWorld, baseid, newid, const dff[], const textureLibrary[]) = AddSimpleModel;
#if defined _ALS_AddSimpleModel
	// Previous hook.
	#define _ALS_AddSimpleModel__
	#define AddSimpleModel__( AddSimpleModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddSimpleModelTimed(virtualWorld, baseid, newid, dff[], textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddSimpleModelTimed(virtualWorld, baseid, newid, _FIXES_MAYBE_CONST dff[], _FIXES_MAYBE_CONST textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddSimpleModelTimed__(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff) = AddSimpleModelTimed;
#if defined _ALS_AddSimpleModelTimed
	// Previous hook.
	#define _ALS_AddSimpleModelTimed__
	#define AddSimpleModelTimed__( AddSimpleModelTimed(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_FindModelFileNameFromCRC(crc, output[], size) = FindModelFileNameFromCRC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_FindModelFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindModelFileNameFromCRC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native FindModelFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindModelFileNameFromCRC;
#if defined _ALS_FindModelFileNameFromCRC
	// Previous hook.
	#define _ALS_FindModelFileNameFromCRC__
	#define FindModelFileNameFromCRC__( FindModelFileNameFromCRC(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_FindTextureFileNameFromCRC(crc, output[], size) = FindTextureFileNameFromCRC;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_FindTextureFileNameFromCRC(crc, output[], _FIXES_MAYBE_SIZEOF(size, output)) = FindTextureFileNameFromCRC;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native FindTextureFileNameFromCRC__(crc, output[], size = sizeof (output)) = FindTextureFileNameFromCRC;
#if defined _ALS_FindTextureFileNameFromCRC
	// Previous hook.
	#define _ALS_FindTextureFileNameFromCRC__
	#define FindTextureFileNameFromCRC__( FindTextureFileNameFromCRC(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RedirectDownload(playerid, url[]) = RedirectDownload;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RedirectDownload(playerid, _FIXES_MAYBE_CONST url[]) = RedirectDownload;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RedirectDownload__(playerid, const url[]) = RedirectDownload;
#if defined _ALS_RedirectDownload
	// Previous hook.
	#define _ALS_RedirectDownload__
	#define RedirectDownload__( RedirectDownload(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsPlayerAdmin(playerid) = IsPlayerAdmin;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsPlayerAdmin(playerid) = IsPlayerAdmin;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsPlayerAdmin__(playerid) = IsPlayerAdmin;
#if defined _ALS_IsPlayerAdmin
	// Previous hook.
	#define _ALS_IsPlayerAdmin__
	#define IsPlayerAdmin__( IsPlayerAdmin(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Kick(playerid) = Kick;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Kick(playerid) = Kick;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Kick__(playerid) = Kick;
#if defined _ALS_Kick
	// Previous hook.
	#define _ALS_Kick__
	#define Kick__( Kick(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Ban(playerid) = Ban;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Ban(playerid) = Ban;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Ban__(playerid) = Ban;
#if defined _ALS_Ban
	// Previous hook.
	#define _ALS_Ban__
	#define Ban__( Ban(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_BanEx(playerid, const reason[]) = BanEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_BanEx(playerid, const reason[]) = BanEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native BanEx__(playerid, const reason[]) = BanEx;
#if defined _ALS_BanEx
	// Previous hook.
	#define _ALS_BanEx__
	#define BanEx__( BanEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SendRconCommand(command[]) = SendRconCommand;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SendRconCommand(_FIXES_MAYBE_CONST command[]) = SendRconCommand;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SendRconCommand__(const command[]) = SendRconCommand;
#if defined _ALS_SendRconCommand
	// Previous hook.
	#define _ALS_SendRconCommand__
	#define SendRconCommand__( SendRconCommand(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerNetworkStats(playerid, output[], size) = GetPlayerNetworkStats;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerNetworkStats(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetPlayerNetworkStats;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerNetworkStats__(playerid, output[], size = sizeof (output)) = GetPlayerNetworkStats;
#if defined _ALS_GetPlayerNetworkStats
	// Previous hook.
	#define _ALS_GetPlayerNetworkStats__
	#define GetPlayerNetworkStats__( GetPlayerNetworkStats(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetNetworkStats(output[], size) = GetNetworkStats;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetNetworkStats(output[], _FIXES_MAYBE_SIZEOF(size, output)) = GetNetworkStats;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetNetworkStats__(output[], size = sizeof (output)) = GetNetworkStats;
#if defined _ALS_GetNetworkStats
	// Previous hook.
	#define _ALS_GetNetworkStats__
	#define GetNetworkStats__( GetNetworkStats(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetPlayerVersion(playerid, const version[], len) = GetPlayerVersion;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetPlayerVersion(playerid, _FIXES_NOT_CONST version[], _FIXES_MAYBE_SIZEOF(len, version)) = GetPlayerVersion;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetPlayerVersion__(playerid, version[], len = sizeof (version)) = GetPlayerVersion;
#if defined _ALS_GetPlayerVersion
	// Previous hook.
	#define _ALS_GetPlayerVersion__
	#define GetPlayerVersion__( GetPlayerVersion(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_BlockIpAddress(ipAddress[], timeMS) = BlockIpAddress;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_BlockIpAddress(_FIXES_MAYBE_CONST ipAddress[], timeMS) = BlockIpAddress;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native BlockIpAddress__(const ipAddress[], timeMS) = BlockIpAddress;
#if defined _ALS_BlockIpAddress
	// Previous hook.
	#define _ALS_BlockIpAddress__
	#define BlockIpAddress__( BlockIpAddress(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_UnBlockIpAddress(ipAddress[]) = UnBlockIpAddress;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_UnBlockIpAddress(_FIXES_MAYBE_CONST ipAddress[]) = UnBlockIpAddress;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native UnBlockIpAddress__(const ipAddress[]) = UnBlockIpAddress;
#if defined _ALS_UnBlockIpAddress
	// Previous hook.
	#define _ALS_UnBlockIpAddress__
	#define UnBlockIpAddress__( UnBlockIpAddress(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetServerVarAsString(const cvar[], buffer[], len) = GetServerVarAsString;
#pragma deprecated Use `GetConsoleVarAsString`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetServerVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetServerVarAsString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetServerVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetServerVarAsString;
#if defined _ALS_GetServerVarAsString
	// Previous hook.
	#define _ALS_GetServerVarAsString__
	#define GetServerVarAsString__( GetServerVarAsString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
#pragma deprecated Use `GetConsoleVarAsInt`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetServerVarAsInt(const cvar[]) = GetServerVarAsInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetServerVarAsInt__(const cvar[]) = GetServerVarAsInt;
#if defined _ALS_GetServerVarAsInt
	// Previous hook.
	#define _ALS_GetServerVarAsInt__
	#define GetServerVarAsInt__( GetServerVarAsInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
#pragma deprecated Use `GetConsoleVarAsBool`.
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_GetServerVarAsBool(const cvar[]) = GetServerVarAsBool;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:GetServerVarAsBool__(const cvar[]) = GetServerVarAsBool;
#if defined _ALS_GetServerVarAsBool
	// Previous hook.
	#define _ALS_GetServerVarAsBool__
	#define GetServerVarAsBool__( GetServerVarAsBool(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetConsoleVarAsString(const cvar[], buffer[], len) = GetConsoleVarAsString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetConsoleVarAsString(const cvar[], buffer[], _FIXES_MAYBE_SIZEOF(len, buffer)) = GetConsoleVarAsString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetConsoleVarAsString__(const cvar[], buffer[], len = sizeof (buffer)) = GetConsoleVarAsString;
#if defined _ALS_GetConsoleVarAsString
	// Previous hook.
	#define _ALS_GetConsoleVarAsString__
	#define GetConsoleVarAsString__( GetConsoleVarAsString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetConsoleVarAsInt(const cvar[]) = GetConsoleVarAsInt;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetConsoleVarAsInt__(const cvar[]) = GetConsoleVarAsInt;
#if defined _ALS_GetConsoleVarAsInt
	// Previous hook.
	#define _ALS_GetConsoleVarAsInt__
	#define GetConsoleVarAsInt__( GetConsoleVarAsInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_GetConsoleVarAsBool(const cvar[]) = GetConsoleVarAsBool;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:GetConsoleVarAsBool__(const cvar[]) = GetConsoleVarAsBool;
#if defined _ALS_GetConsoleVarAsBool
	// Previous hook.
	#define _ALS_GetConsoleVarAsBool__
	#define GetConsoleVarAsBool__( GetConsoleVarAsBool(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetServerTickRate() = GetServerTickRate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetServerTickRate() = GetServerTickRate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetServerTickRate__() = GetServerTickRate;
#if defined _ALS_GetServerTickRate
	// Previous hook.
	#define _ALS_GetServerTickRate__
	#define GetServerTickRate__( GetServerTickRate(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_GetConnectedTime(playerid) = NetStats_GetConnectedTime;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_GetConnectedTime__(playerid) = NetStats_GetConnectedTime;
#if defined _ALS_NetStats_GetConnectedTime
	// Previous hook.
	#define _ALS_NetStats_GetConnectedTime__
	#define NetStats_GetConnectedTime__( NetStats_GetConnectedTime(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_MessagesReceived(playerid) = NetStats_MessagesReceived;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_MessagesReceived__(playerid) = NetStats_MessagesReceived;
#if defined _ALS_NetStats_MessagesReceived
	// Previous hook.
	#define _ALS_NetStats_MessagesReceived__
	#define NetStats_MessagesReceived__( NetStats_MessagesReceived(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_BytesReceived(playerid) = NetStats_BytesReceived;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_BytesReceived__(playerid) = NetStats_BytesReceived;
#if defined _ALS_NetStats_BytesReceived
	// Previous hook.
	#define _ALS_NetStats_BytesReceived__
	#define NetStats_BytesReceived__( NetStats_BytesReceived(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_MessagesSent(playerid) = NetStats_MessagesSent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_MessagesSent__(playerid) = NetStats_MessagesSent;
#if defined _ALS_NetStats_MessagesSent
	// Previous hook.
	#define _ALS_NetStats_MessagesSent__
	#define NetStats_MessagesSent__( NetStats_MessagesSent(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_BytesSent(playerid) = NetStats_BytesSent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_BytesSent(playerid) = NetStats_BytesSent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_BytesSent__(playerid) = NetStats_BytesSent;
#if defined _ALS_NetStats_BytesSent
	// Previous hook.
	#define _ALS_NetStats_BytesSent__
	#define NetStats_BytesSent__( NetStats_BytesSent(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_MessagesRecvPerSecond(playerid) = NetStats_MessagesRecvPerSecond;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_MessagesRecvPerSecond__(playerid) = NetStats_MessagesRecvPerSecond;
#if defined _ALS_NetStats_MessagesRecvPerSecond
	// Previous hook.
	#define _ALS_NetStats_MessagesRecvPerSecond__
	#define NetStats_MessagesRecvPerSecond__( NetStats_MessagesRecvPerSecond(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_NetStats_PacketLossPercent(playerid) = NetStats_PacketLossPercent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:NetStats_PacketLossPercent__(playerid) = NetStats_PacketLossPercent;
#if defined _ALS_NetStats_PacketLossPercent
	// Previous hook.
	#define _ALS_NetStats_PacketLossPercent__
	#define NetStats_PacketLossPercent__( NetStats_PacketLossPercent(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_ConnectionStatus(playerid) = NetStats_ConnectionStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_ConnectionStatus__(playerid) = NetStats_ConnectionStatus;
#if defined _ALS_NetStats_ConnectionStatus
	// Previous hook.
	#define _ALS_NetStats_ConnectionStatus__
	#define NetStats_ConnectionStatus__( NetStats_ConnectionStatus(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_NetStats_GetIpPort(playerid, output[], size) = NetStats_GetIpPort;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_NetStats_GetIpPort(playerid, output[], _FIXES_MAYBE_SIZEOF(size, output)) = NetStats_GetIpPort;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native NetStats_GetIpPort__(playerid, output[], size = sizeof (output)) = NetStats_GetIpPort;
#if defined _ALS_NetStats_GetIpPort
	// Previous hook.
	#define _ALS_NetStats_GetIpPort__
	#define NetStats_GetIpPort__( NetStats_GetIpPort(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Menu:BAD_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Menu:CST_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Menu:CreateMenu__(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
#if defined _ALS_CreateMenu
	// Previous hook.
	#define _ALS_CreateMenu__
	#define CreateMenu__( CreateMenu(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyMenu(Menu:menuid) = DestroyMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyMenu(Menu:menuid) = DestroyMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyMenu__(Menu:menuid) = DestroyMenu;
#if defined _ALS_DestroyMenu
	// Previous hook.
	#define _ALS_DestroyMenu__
	#define DestroyMenu__( DestroyMenu(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddMenuItem(Menu:menuid, column, const text[]) = AddMenuItem;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddMenuItem__(Menu:menuid, column, const text[]) = AddMenuItem;
#if defined _ALS_AddMenuItem
	// Previous hook.
	#define _ALS_AddMenuItem__
	#define AddMenuItem__( AddMenuItem(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetMenuColumnHeader(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetMenuColumnHeader__(Menu:menuid, column, const heading[]) = SetMenuColumnHeader;
#if defined _ALS_SetMenuColumnHeader
	// Previous hook.
	#define _ALS_SetMenuColumnHeader__
	#define SetMenuColumnHeader__( SetMenuColumnHeader(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ShowMenuForPlayer__(Menu:menuid, playerid) = ShowMenuForPlayer;
#if defined _ALS_ShowMenuForPlayer
	// Previous hook.
	#define _ALS_ShowMenuForPlayer__
	#define ShowMenuForPlayer__( ShowMenuForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native HideMenuForPlayer__(Menu:menuid, playerid) = HideMenuForPlayer;
#if defined _ALS_HideMenuForPlayer
	// Previous hook.
	#define _ALS_HideMenuForPlayer__
	#define HideMenuForPlayer__( HideMenuForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsValidMenu(Menu:menuid) = IsValidMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsValidMenu(Menu:menuid) = IsValidMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsValidMenu__(Menu:menuid) = IsValidMenu;
#if defined _ALS_IsValidMenu
	// Previous hook.
	#define _ALS_IsValidMenu__
	#define IsValidMenu__( IsValidMenu(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisableMenu(Menu:menuid) = DisableMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisableMenu(Menu:menuid) = DisableMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisableMenu__(Menu:menuid) = DisableMenu;
#if defined _ALS_DisableMenu
	// Previous hook.
	#define _ALS_DisableMenu__
	#define DisableMenu__( DisableMenu(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DisableMenuRow__(Menu:menuid, row) = DisableMenuRow;
#if defined _ALS_DisableMenuRow
	// Previous hook.
	#define _ALS_DisableMenuRow__
	#define DisableMenuRow__( DisableMenuRow(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Menu:BAD_GetPlayerMenu(playerid) = GetPlayerMenu;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Menu:CST_GetPlayerMenu(playerid) = GetPlayerMenu;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Menu:GetPlayerMenu__(playerid) = GetPlayerMenu;
#if defined _ALS_GetPlayerMenu
	// Previous hook.
	#define _ALS_GetPlayerMenu__
	#define GetPlayerMenu__( GetPlayerMenu(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Text:CST_TextDrawCreate(Float:x, Float:y, _FIXES_MAYBE_CONST text[]) = TextDrawCreate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Text:TextDrawCreate__(Float:x, Float:y, const text[]) = TextDrawCreate;
#if defined _ALS_TextDrawCreate
	// Previous hook.
	#define _ALS_TextDrawCreate__
	#define TextDrawCreate__( TextDrawCreate(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawDestroy(Text:text) = TextDrawDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawDestroy(Text:text) = TextDrawDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawDestroy__(Text:text) = TextDrawDestroy;
#if defined _ALS_TextDrawDestroy
	// Previous hook.
	#define _ALS_TextDrawDestroy__
	#define TextDrawDestroy__( TextDrawDestroy(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawLetterSize(Text:text, Float:width, Float:height) = TextDrawLetterSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawLetterSize__(Text:text, Float:width, Float:height) = TextDrawLetterSize;
#if defined _ALS_TextDrawLetterSize
	// Previous hook.
	#define _ALS_TextDrawLetterSize__
	#define TextDrawLetterSize__( TextDrawLetterSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawTextSize(Text:text, Float:width, Float:height) = TextDrawTextSize;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawTextSize__(Text:text, Float:width, Float:height) = TextDrawTextSize;
#if defined _ALS_TextDrawTextSize
	// Previous hook.
	#define _ALS_TextDrawTextSize__
	#define TextDrawTextSize__( TextDrawTextSize(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawAlignment(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawAlignment__(Text:text, TEXT_DRAW_ALIGN:alignment) = TextDrawAlignment;
#if defined _ALS_TextDrawAlignment
	// Previous hook.
	#define _ALS_TextDrawAlignment__
	#define TextDrawAlignment__( TextDrawAlignment(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawColor(Text:text, colour) = TextDrawColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawColor(Text:text, colour) = TextDrawColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawColor__(Text:text, colour) = TextDrawColor;
#if defined _ALS_TextDrawColor
	// Previous hook.
	#define _ALS_TextDrawColor__
	#define TextDrawColor__( TextDrawColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawUseBox(Text:text, use) = TextDrawUseBox;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawUseBox(Text:text, _FIXES_MAYBE_BOOL:use) = TextDrawUseBox;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawUseBox__(Text:text, bool:use) = TextDrawUseBox;
#if defined _ALS_TextDrawUseBox
	// Previous hook.
	#define _ALS_TextDrawUseBox__
	#define TextDrawUseBox__( TextDrawUseBox(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawBoxColor(Text:text, colour) = TextDrawBoxColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawBoxColor__(Text:text, colour) = TextDrawBoxColor;
#if defined _ALS_TextDrawBoxColor
	// Previous hook.
	#define _ALS_TextDrawBoxColor__
	#define TextDrawBoxColor__( TextDrawBoxColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetShadow(Text:text, size) = TextDrawSetShadow;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetShadow__(Text:text, size) = TextDrawSetShadow;
#if defined _ALS_TextDrawSetShadow
	// Previous hook.
	#define _ALS_TextDrawSetShadow__
	#define TextDrawSetShadow__( TextDrawSetShadow(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetOutline(Text:text, size) = TextDrawSetOutline;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetOutline__(Text:text, size) = TextDrawSetOutline;
#if defined _ALS_TextDrawSetOutline
	// Previous hook.
	#define _ALS_TextDrawSetOutline__
	#define TextDrawSetOutline__( TextDrawSetOutline(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawBackgroundColor(Text:text, colour) = TextDrawBackgroundColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawBackgroundColor__(Text:text, colour) = TextDrawBackgroundColor;
#if defined _ALS_TextDrawBackgroundColor
	// Previous hook.
	#define _ALS_TextDrawBackgroundColor__
	#define TextDrawBackgroundColor__( TextDrawBackgroundColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawFont(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawFont__(Text:text, TEXT_DRAW_FONT:font) = TextDrawFont;
#if defined _ALS_TextDrawFont
	// Previous hook.
	#define _ALS_TextDrawFont__
	#define TextDrawFont__( TextDrawFont(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetProportional(Text:text, set) = TextDrawSetProportional;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetProportional(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetProportional;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetProportional__(Text:text, bool:set) = TextDrawSetProportional;
#if defined _ALS_TextDrawSetProportional
	// Previous hook.
	#define _ALS_TextDrawSetProportional__
	#define TextDrawSetProportional__( TextDrawSetProportional(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetSelectable(Text:text, set) = TextDrawSetSelectable;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetSelectable(Text:text, _FIXES_MAYBE_BOOL:set) = TextDrawSetSelectable;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetSelectable__(Text:text, bool:set) = TextDrawSetSelectable;
#if defined _ALS_TextDrawSetSelectable
	// Previous hook.
	#define _ALS_TextDrawSetSelectable__
	#define TextDrawSetSelectable__( TextDrawSetSelectable(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawShowForPlayer(playerid, Text:text) = TextDrawShowForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawShowForPlayer__(playerid, Text:text) = TextDrawShowForPlayer;
#if defined _ALS_TextDrawShowForPlayer
	// Previous hook.
	#define _ALS_TextDrawShowForPlayer__
	#define TextDrawShowForPlayer__( TextDrawShowForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawHideForPlayer(playerid, Text:text) = TextDrawHideForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawHideForPlayer__(playerid, Text:text) = TextDrawHideForPlayer;
#if defined _ALS_TextDrawHideForPlayer
	// Previous hook.
	#define _ALS_TextDrawHideForPlayer__
	#define TextDrawHideForPlayer__( TextDrawHideForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawShowForAll(Text:text) = TextDrawShowForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawShowForAll__(Text:text) = TextDrawShowForAll;
#if defined _ALS_TextDrawShowForAll
	// Previous hook.
	#define _ALS_TextDrawShowForAll__
	#define TextDrawShowForAll__( TextDrawShowForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawHideForAll(Text:text) = TextDrawHideForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawHideForAll__(Text:text) = TextDrawHideForAll;
#if defined _ALS_TextDrawHideForAll
	// Previous hook.
	#define _ALS_TextDrawHideForAll__
	#define TextDrawHideForAll__( TextDrawHideForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetString(Text:text, _FIXES_MAYBE_CONST string[]) = TextDrawSetString;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetString__(Text:text, const string[]) = TextDrawSetString;
#if defined _ALS_TextDrawSetString
	// Previous hook.
	#define _ALS_TextDrawSetString__
	#define TextDrawSetString__( TextDrawSetString(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetPreviewModel(Text:text, modelIndex) = TextDrawSetPreviewModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetPreviewModel__(Text:text, modelIndex) = TextDrawSetPreviewModel;
#if defined _ALS_TextDrawSetPreviewModel
	// Previous hook.
	#define _ALS_TextDrawSetPreviewModel__
	#define TextDrawSetPreviewModel__( TextDrawSetPreviewModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetPreviewRot(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetPreviewRot__(Text:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0) = TextDrawSetPreviewRot;
#if defined _ALS_TextDrawSetPreviewRot
	// Previous hook.
	#define _ALS_TextDrawSetPreviewRot__
	#define TextDrawSetPreviewRot__( TextDrawSetPreviewRot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_TextDrawSetPreviewVehCol(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native TextDrawSetPreviewVehCol__(Text:text, colour1, colour2) = TextDrawSetPreviewVehCol;
#if defined _ALS_TextDrawSetPreviewVehCol
	// Previous hook.
	#define _ALS_TextDrawSetPreviewVehCol__
	#define TextDrawSetPreviewVehCol__( TextDrawSetPreviewVehCol(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneCreate__(Float:minX, Float:minY, Float:maxX, Float:maxY) = GangZoneCreate;
#if defined _ALS_GangZoneCreate
	// Previous hook.
	#define _ALS_GangZoneCreate__
	#define GangZoneCreate__( GangZoneCreate(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneDestroy(zone) = GangZoneDestroy;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneDestroy(zone) = GangZoneDestroy;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneDestroy__(zone) = GangZoneDestroy;
#if defined _ALS_GangZoneDestroy
	// Previous hook.
	#define _ALS_GangZoneDestroy__
	#define GangZoneDestroy__( GangZoneDestroy(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneShowForPlayer(playerid, zone, colour) = GangZoneShowForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneShowForPlayer__(playerid, zone, colour) = GangZoneShowForPlayer;
#if defined _ALS_GangZoneShowForPlayer
	// Previous hook.
	#define _ALS_GangZoneShowForPlayer__
	#define GangZoneShowForPlayer__( GangZoneShowForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneShowForAll(zone, colour) = GangZoneShowForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneShowForAll__(zone, colour) = GangZoneShowForAll;
#if defined _ALS_GangZoneShowForAll
	// Previous hook.
	#define _ALS_GangZoneShowForAll__
	#define GangZoneShowForAll__( GangZoneShowForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneHideForPlayer(playerid, zone) = GangZoneHideForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneHideForPlayer__(playerid, zone) = GangZoneHideForPlayer;
#if defined _ALS_GangZoneHideForPlayer
	// Previous hook.
	#define _ALS_GangZoneHideForPlayer__
	#define GangZoneHideForPlayer__( GangZoneHideForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneHideForAll(zone) = GangZoneHideForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneHideForAll(zone) = GangZoneHideForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneHideForAll__(zone) = GangZoneHideForAll;
#if defined _ALS_GangZoneHideForAll
	// Previous hook.
	#define _ALS_GangZoneHideForAll__
	#define GangZoneHideForAll__( GangZoneHideForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneFlashForPlayer(playerid, zone, flashColour) = GangZoneFlashForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneFlashForPlayer__(playerid, zone, flashColour) = GangZoneFlashForPlayer;
#if defined _ALS_GangZoneFlashForPlayer
	// Previous hook.
	#define _ALS_GangZoneFlashForPlayer__
	#define GangZoneFlashForPlayer__( GangZoneFlashForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneFlashForAll(zone, flashColour) = GangZoneFlashForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneFlashForAll__(zone, flashColour) = GangZoneFlashForAll;
#if defined _ALS_GangZoneFlashForAll
	// Previous hook.
	#define _ALS_GangZoneFlashForAll__
	#define GangZoneFlashForAll__( GangZoneFlashForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneStopFlashForPlayer(playerid, zone) = GangZoneStopFlashForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneStopFlashForPlayer__(playerid, zone) = GangZoneStopFlashForPlayer;
#if defined _ALS_GangZoneStopFlashForPlayer
	// Previous hook.
	#define _ALS_GangZoneStopFlashForPlayer__
	#define GangZoneStopFlashForPlayer__( GangZoneStopFlashForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GangZoneStopFlashForAll(zone) = GangZoneStopFlashForAll;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GangZoneStopFlashForAll__(zone) = GangZoneStopFlashForAll;
#if defined _ALS_GangZoneStopFlashForAll
	// Previous hook.
	#define _ALS_GangZoneStopFlashForAll__
	#define GangZoneStopFlashForAll__( GangZoneStopFlashForAll(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Text3D:BAD_Create3DTextLabel(text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, testLOS = false) = Create3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Text3D:CST_Create3DTextLabel(_FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, _FIXES_MAYBE_BOOL:testLOS = false) = Create3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Text3D:Create3DTextLabel__(const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, bool:testLOS = false) = Create3DTextLabel;
#if defined _ALS_Create3DTextLabel
	// Previous hook.
	#define _ALS_Create3DTextLabel__
	#define Create3DTextLabel__( Create3DTextLabel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Delete3DTextLabel(Text3D:textid) = Delete3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Delete3DTextLabel__(Text3D:textid) = Delete3DTextLabel;
#if defined _ALS_Delete3DTextLabel
	// Previous hook.
	#define _ALS_Delete3DTextLabel__
	#define Delete3DTextLabel__( Delete3DTextLabel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Attach3DTextLabelToPlayer__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToPlayer;
#if defined _ALS_Attach3DTextLabelToPlayer
	// Previous hook.
	#define _ALS_Attach3DTextLabelToPlayer__
	#define Attach3DTextLabelToPlayer__( Attach3DTextLabelToPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Attach3DTextLabelToVehicle__(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ) = Attach3DTextLabelToVehicle;
#if defined _ALS_Attach3DTextLabelToVehicle
	// Previous hook.
	#define _ALS_Attach3DTextLabelToVehicle__
	#define Attach3DTextLabelToVehicle__( Attach3DTextLabelToVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_Update3DTextLabelText(Text3D:textid, colour, text[]) = Update3DTextLabelText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_Update3DTextLabelText(Text3D:textid, colour, _FIXES_MAYBE_CONST text[]) = Update3DTextLabelText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Update3DTextLabelText__(Text3D:textid, colour, const text[]) = Update3DTextLabelText;
#if defined _ALS_Update3DTextLabelText
	// Previous hook.
	#define _ALS_Update3DTextLabelText__
	#define Update3DTextLabelText__( Update3DTextLabelText(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native PlayerText3D:BAD_CreatePlayer3DTextLabel(playerid, text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, testLOS = false) = CreatePlayer3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native PlayerText3D:CST_CreatePlayer3DTextLabel(playerid, _FIXES_MAYBE_CONST text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, _FIXES_MAYBE_BOOL:testLOS = false) = CreatePlayer3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native PlayerText3D:CreatePlayer3DTextLabel__(playerid, const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, bool:testLOS = false) = CreatePlayer3DTextLabel;
#if defined _ALS_CreatePlayer3DTextLabel
	// Previous hook.
	#define _ALS_CreatePlayer3DTextLabel__
	#define CreatePlayer3DTextLabel__( CreatePlayer3DTextLabel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DeletePlayer3DTextLabel(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DeletePlayer3DTextLabel__(playerid, PlayerText3D:textid) = DeletePlayer3DTextLabel;
#if defined _ALS_DeletePlayer3DTextLabel
	// Previous hook.
	#define _ALS_DeletePlayer3DTextLabel__
	#define DeletePlayer3DTextLabel__( DeletePlayer3DTextLabel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, text[]) = UpdatePlayer3DTextLabelText;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, _FIXES_MAYBE_CONST text[]) = UpdatePlayer3DTextLabelText;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native UpdatePlayer3DTextLabelText__(playerid, PlayerText3D:textid, colour, const text[]) = UpdatePlayer3DTextLabelText;
#if defined _ALS_UpdatePlayer3DTextLabelText
	// Previous hook.
	#define _ALS_UpdatePlayer3DTextLabelText__
	#define UpdatePlayer3DTextLabelText__( UpdatePlayer3DTextLabelText(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, caption[], info[], button1[], button2[]) = ShowPlayerDialog;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, _FIXES_MAYBE_CONST caption[], _FIXES_MAYBE_CONST info[], _FIXES_MAYBE_CONST button1[], _FIXES_MAYBE_CONST button2[]) = ShowPlayerDialog;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ShowPlayerDialog__(playerid, dialogid, DIALOG_STYLE:style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
#if defined _ALS_ShowPlayerDialog
	// Previous hook.
	#define _ALS_ShowPlayerDialog__
	#define ShowPlayerDialog__( ShowPlayerDialog(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_gpci(playerid, serial[], len) = gpci;
#if FIX_camel_case
	#pragma deprecated Use `GPCI`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_gpci(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native gpci__(playerid, serial[], len = sizeof (serial)) = gpci;
#if defined _ALS_gpci
	// Previous hook.
	#define _ALS_gpci__
	#define gpci__( gpci(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GPCI(playerid, serial[], len) = gpci;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GPCI(playerid, serial[], _FIXES_MAYBE_SIZEOF(len, serial)) = gpci;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GPCI__(playerid, serial[], len = sizeof (serial)) = gpci;
#if defined _ALS_GPCI
	// Previous hook.
	#define _ALS_GPCI__
	#define GPCI__( GPCI(
#endif

/*

     ¦¦¦¦¦          ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦      ¦¦   ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦   ¦¦
    ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦¦¦¦¦
    ¦¦   ¦¦              ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦ ¦¦      ¦¦   ¦¦ ¦¦   ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦      ¦¦ ¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native DB:BAD_db_open(name[]) = db_open;
#if FIX_camel_case
	#pragma deprecated Use `DB_Open`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native DB:CST_db_open(_FIXES_MAYBE_CONST name[]) = db_open;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB:db_open__(const name[]) = db_open;
#if defined _ALS_db_open
	// Previous hook.
	#define _ALS_db_open__
	#define db_open__( db_open(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native DB:BAD_DB_Open(name[]) = db_open;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native DB:CST_DB_Open(_FIXES_MAYBE_CONST name[]) = db_open;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB:DB_Open__(const name[]) = db_open;
#if defined _ALS_DB_Open
	// Previous hook.
	#define _ALS_DB_Open__
	#define DB_Open__( DB_Open(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_close(DB:db) = db_close;
#if FIX_camel_case
	#pragma deprecated Use `DB_Close`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_close(DB:db) = db_close;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_close__(DB:db) = db_close;
#if defined _ALS_db_close
	// Previous hook.
	#define _ALS_db_close__
	#define db_close__( db_close(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_Close(DB:db) = db_close;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_Close(DB:db) = db_close;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_Close__(DB:db) = db_close;
#if defined _ALS_DB_Close
	// Previous hook.
	#define _ALS_DB_Close__
	#define DB_Close__( DB_Close(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native DBResult:BAD_db_query(DB:db, query[]) = db_query;
#if FIX_camel_case
	#pragma deprecated Use `DB_Query`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native DBResult:CST_db_query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DBResult:db_query__(DB:db, const query[]) = db_query;
#if defined _ALS_db_query
	// Previous hook.
	#define _ALS_db_query__
	#define db_query__( db_query(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native DBResult:BAD_DB_Query(DB:db, query[]) = db_query;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native DBResult:CST_DB_Query(DB:db, _FIXES_MAYBE_CONST query[]) = db_query;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DBResult:DB_Query__(DB:db, const query[]) = db_query;
#if defined _ALS_DB_Query
	// Previous hook.
	#define _ALS_DB_Query__
	#define DB_Query__( DB_Query(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_free_result(DBResult:result) = db_free_result;
#if FIX_camel_case
	#pragma deprecated Use `DB_FreeResult`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_free_result(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_free_result__(DBResult:result) = db_free_result;
#if defined _ALS_db_free_result
	// Previous hook.
	#define _ALS_db_free_result__
	#define db_free_result__( db_free_result(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_FreeResult(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_FreeResult(DBResult:result) = db_free_result;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_FreeResult__(DBResult:result) = db_free_result;
#if defined _ALS_DB_FreeResult
	// Previous hook.
	#define _ALS_DB_FreeResult__
	#define DB_FreeResult__( DB_FreeResult(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_num_rows(DBResult:result) = db_num_rows;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumRows`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_num_rows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_num_rows__(DBResult:result) = db_num_rows;
#if defined _ALS_db_num_rows
	// Previous hook.
	#define _ALS_db_num_rows__
	#define db_num_rows__( db_num_rows(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_NumRows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_NumRows(DBResult:result) = db_num_rows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_NumRows__(DBResult:result) = db_num_rows;
#if defined _ALS_DB_NumRows
	// Previous hook.
	#define _ALS_DB_NumRows__
	#define DB_NumRows__( DB_NumRows(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_next_row(DBResult:result) = db_next_row;
#if FIX_camel_case
	#pragma deprecated Use `DB_NextRow`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_next_row(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_next_row__(DBResult:result) = db_next_row;
#if defined _ALS_db_next_row
	// Previous hook.
	#define _ALS_db_next_row__
	#define db_next_row__( db_next_row(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_NextRow(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_NextRow(DBResult:result) = db_next_row;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_NextRow__(DBResult:result) = db_next_row;
#if defined _ALS_DB_NextRow
	// Previous hook.
	#define _ALS_DB_NextRow__
	#define DB_NextRow__( DB_NextRow(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_num_fields(DBResult:result) = db_num_fields;
#if FIX_camel_case
	#pragma deprecated Use `DB_NumFields`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_num_fields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_num_fields__(DBResult:result) = db_num_fields;
#if defined _ALS_db_num_fields
	// Previous hook.
	#define _ALS_db_num_fields__
	#define db_num_fields__( db_num_fields(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_NumFields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_NumFields(DBResult:result) = db_num_fields;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_NumFields__(DBResult:result) = db_num_fields;
#if defined _ALS_DB_NumFields
	// Previous hook.
	#define _ALS_DB_NumFields__
	#define DB_NumFields__( DB_NumFields(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_field_name(DBResult:result, field, output[], size) = db_field_name;
#if FIX_camel_case
	#pragma deprecated Use `DB_FieldName`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_field_name(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_field_name__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#if defined _ALS_db_field_name
	// Previous hook.
	#define _ALS_db_field_name__
	#define db_field_name__( db_field_name(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_FieldName(DBResult:result, field, output[], size) = db_field_name;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_FieldName(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_field_name;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_FieldName__(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;
#if defined _ALS_DB_FieldName
	// Previous hook.
	#define _ALS_DB_FieldName__
	#define DB_FieldName__( DB_FieldName(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_field(DBResult:result, field, output[], size) = db_get_field;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetField`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_get_field(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_get_field__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#if defined _ALS_db_get_field
	// Previous hook.
	#define _ALS_db_get_field__
	#define db_get_field__( db_get_field(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetField(DBResult:result, field, output[], size) = db_get_field;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_GetField(DBResult:result, field, output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_GetField__(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;
#if defined _ALS_DB_GetField
	// Previous hook.
	#define _ALS_DB_GetField__
	#define DB_GetField__( DB_GetField(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldInt`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_get_field_int(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_get_field_int__(DBResult:result, field = 0) = db_get_field_int;
#if defined _ALS_db_get_field_int
	// Previous hook.
	#define _ALS_db_get_field_int__
	#define db_get_field_int__( db_get_field_int(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_GetFieldInt__(DBResult:result, field = 0) = db_get_field_int;
#if defined _ALS_DB_GetFieldInt
	// Previous hook.
	#define _ALS_DB_GetFieldInt__
	#define DB_GetFieldInt__( DB_GetFieldInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldFloat`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_db_get_field_float(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:db_get_field_float__(DBResult:result, field = 0) = db_get_field_float;
#if defined _ALS_db_get_field_float
	// Previous hook.
	#define _ALS_db_get_field_float__
	#define db_get_field_float__( db_get_field_float(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:DB_GetFieldFloat__(DBResult:result, field = 0) = db_get_field_float;
#if defined _ALS_DB_GetFieldFloat
	// Previous hook.
	#define _ALS_DB_GetFieldFloat__
	#define DB_GetFieldFloat__( DB_GetFieldFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_field_assoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssoc`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_db_get_field_assoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:db_get_field_assoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#if defined _ALS_db_get_field_assoc
	// Previous hook.
	#define _ALS_db_get_field_assoc__
	#define db_get_field_assoc__( db_get_field_assoc(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetFieldAssoc(DBResult:result, field[], output[], size) = db_get_field_assoc;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_DB_GetFieldAssoc(DBResult:result, _FIXES_MAYBE_CONST field[], output[], _FIXES_MAYBE_SIZEOF(size, output)) = db_get_field_assoc;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:DB_GetFieldAssoc__(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;
#if defined _ALS_DB_GetFieldAssoc
	// Previous hook.
	#define _ALS_DB_GetFieldAssoc__
	#define DB_GetFieldAssoc__( DB_GetFieldAssoc(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_field_assoc_int(DBResult:result, field[]) = db_get_field_assoc_int;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocInt`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_get_field_assoc_int(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_get_field_assoc_int__(DBResult:result, const field[]) = db_get_field_assoc_int;
#if defined _ALS_db_get_field_assoc_int
	// Previous hook.
	#define _ALS_db_get_field_assoc_int__
	#define db_get_field_assoc_int__( db_get_field_assoc_int(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetFieldAssocInt(DBResult:result, field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_GetFieldAssocInt(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_int;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_GetFieldAssocInt__(DBResult:result, const field[]) = db_get_field_assoc_int;
#if defined _ALS_DB_GetFieldAssocInt
	// Previous hook.
	#define _ALS_DB_GetFieldAssocInt__
	#define DB_GetFieldAssocInt__( DB_GetFieldAssocInt(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_db_get_field_assoc_float(DBResult:result, field[]) = db_get_field_assoc_float;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetFieldAssocFloat`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_db_get_field_assoc_float(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:db_get_field_assoc_float__(DBResult:result, const field[]) = db_get_field_assoc_float;
#if defined _ALS_db_get_field_assoc_float
	// Previous hook.
	#define _ALS_db_get_field_assoc_float__
	#define db_get_field_assoc_float__( db_get_field_assoc_float(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_DB_GetFieldAssocFloat(DBResult:result, field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_DB_GetFieldAssocFloat(DBResult:result, _FIXES_MAYBE_CONST field[]) = db_get_field_assoc_float;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:DB_GetFieldAssocFloat__(DBResult:result, const field[]) = db_get_field_assoc_float;
#if defined _ALS_DB_GetFieldAssocFloat
	// Previous hook.
	#define _ALS_DB_GetFieldAssocFloat__
	#define DB_GetFieldAssocFloat__( DB_GetFieldAssocFloat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_mem_handle(DB:db) = db_get_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetMemHandle`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_get_mem_handle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_get_mem_handle__(DB:db) = db_get_mem_handle;
#if defined _ALS_db_get_mem_handle
	// Previous hook.
	#define _ALS_db_get_mem_handle__
	#define db_get_mem_handle__( db_get_mem_handle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetMemHandle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_GetMemHandle(DB:db) = db_get_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_GetMemHandle__(DB:db) = db_get_mem_handle;
#if defined _ALS_DB_GetMemHandle
	// Previous hook.
	#define _ALS_DB_GetMemHandle__
	#define DB_GetMemHandle__( DB_GetMemHandle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
#if FIX_camel_case
	#pragma deprecated Use `DB_GetResultMemHandle`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_get_result_mem_handle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_get_result_mem_handle__(DBResult:result) = db_get_result_mem_handle;
#if defined _ALS_db_get_result_mem_handle
	// Previous hook.
	#define _ALS_db_get_result_mem_handle__
	#define db_get_result_mem_handle__( db_get_result_mem_handle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_GetResultMemHandle(DBResult:result) = db_get_result_mem_handle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_GetResultMemHandle__(DBResult:result) = db_get_result_mem_handle;
#if defined _ALS_DB_GetResultMemHandle
	// Previous hook.
	#define _ALS_DB_GetResultMemHandle__
	#define DB_GetResultMemHandle__( DB_GetResultMemHandle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_debug_openfiles() = db_debug_openfiles;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenFiles`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_debug_openfiles() = db_debug_openfiles;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_debug_openfiles__() = db_debug_openfiles;
#if defined _ALS_db_debug_openfiles
	// Previous hook.
	#define _ALS_db_debug_openfiles__
	#define db_debug_openfiles__( db_debug_openfiles(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_DebugOpenFiles() = db_debug_openfiles;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_DebugOpenFiles() = db_debug_openfiles;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_DebugOpenFiles__() = db_debug_openfiles;
#if defined _ALS_DB_DebugOpenFiles
	// Previous hook.
	#define _ALS_DB_DebugOpenFiles__
	#define DB_DebugOpenFiles__( DB_DebugOpenFiles(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_db_debug_openresults() = db_debug_openresults;
#if FIX_camel_case
	#pragma deprecated Use `DB_DebugOpenResults`.
#endif
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_db_debug_openresults() = db_debug_openresults;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native db_debug_openresults__() = db_debug_openresults;
#if defined _ALS_db_debug_openresults
	// Previous hook.
	#define _ALS_db_debug_openresults__
	#define db_debug_openresults__( db_debug_openresults(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DB_DebugOpenResults() = db_debug_openresults;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DB_DebugOpenResults() = db_debug_openresults;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DB_DebugOpenResults__() = db_debug_openresults;
#if defined _ALS_DB_DebugOpenResults
	// Previous hook.
	#define _ALS_DB_DebugOpenResults__
	#define DB_DebugOpenResults__( DB_DebugOpenResults(
#endif

/*

     ¦¦¦¦¦          ¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦  ¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦
    ¦¦   ¦¦         ¦¦    ¦¦ ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦      ¦¦      ¦¦
    ¦¦¦¦¦¦¦         ¦¦    ¦¦ ¦¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦ ¦¦      ¦¦      ¦¦¦¦¦   ¦¦¦¦¦¦¦
    ¦¦   ¦¦          ¦¦  ¦¦  ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦      ¦¦           ¦¦
    ¦¦   ¦¦ ¦¦¦¦¦¦¦   ¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦  ¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦

*/

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, addSiren = false) = CreateVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, _FIXES_MAYBE_BOOL:addSiren = false) = CreateVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CreateVehicle__(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, bool:addSiren = false) = CreateVehicle;
#if defined _ALS_CreateVehicle
	// Previous hook.
	#define _ALS_CreateVehicle__
	#define CreateVehicle__( CreateVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DestroyVehicle(vehicleid) = DestroyVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DestroyVehicle(vehicleid) = DestroyVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DestroyVehicle__(vehicleid) = DestroyVehicle;
#if defined _ALS_DestroyVehicle
	// Previous hook.
	#define _ALS_DestroyVehicle__
	#define DestroyVehicle__( DestroyVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsVehicleStreamedIn(vehicleid, playerid) = IsVehicleStreamedIn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsVehicleStreamedIn__(vehicleid, playerid) = IsVehicleStreamedIn;
#if defined _ALS_IsVehicleStreamedIn
	// Previous hook.
	#define _ALS_IsVehicleStreamedIn__
	#define IsVehicleStreamedIn__( IsVehicleStreamedIn(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehiclePos__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
#if defined _ALS_GetVehiclePos
	// Previous hook.
	#define _ALS_GetVehiclePos__
	#define GetVehiclePos__( GetVehiclePos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehiclePos__(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
#if defined _ALS_SetVehiclePos
	// Previous hook.
	#define _ALS_SetVehiclePos__
	#define SetVehiclePos__( SetVehiclePos(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleZAngle(vehicleid, &Float:angle) = GetVehicleZAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleZAngle__(vehicleid, &Float:angle) = GetVehicleZAngle;
#if defined _ALS_GetVehicleZAngle
	// Previous hook.
	#define _ALS_GetVehicleZAngle__
	#define GetVehicleZAngle__( GetVehicleZAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleRotationQuat__(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
#if defined _ALS_GetVehicleRotationQuat
	// Previous hook.
	#define _ALS_GetVehicleRotationQuat__
	#define GetVehicleRotationQuat__( GetVehicleRotationQuat(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native Float:BAD_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native Float:CST_GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native Float:GetVehicleDistanceFromPoint__(vehicleid, Float:x, Float:y, Float:z) = GetVehicleDistanceFromPoint;
#if defined _ALS_GetVehicleDistanceFromPoint
	// Previous hook.
	#define _ALS_GetVehicleDistanceFromPoint__
	#define GetVehicleDistanceFromPoint__( GetVehicleDistanceFromPoint(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleZAngle(vehicleid, Float:angle) = SetVehicleZAngle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleZAngle__(vehicleid, Float:angle) = SetVehicleZAngle;
#if defined _ALS_SetVehicleZAngle
	// Previous hook.
	#define _ALS_SetVehicleZAngle__
	#define SetVehicleZAngle__( SetVehicleZAngle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleParamsForPlayer__(vehicleid, playerid, objective, doors) = SetVehicleParamsForPlayer;
#if defined _ALS_SetVehicleParamsForPlayer
	// Previous hook.
	#define _ALS_SetVehicleParamsForPlayer__
	#define SetVehicleParamsForPlayer__( SetVehicleParamsForPlayer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ManualVehicleEngineAndLights() = ManualVehicleEngineAndLights;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ManualVehicleEngineAndLights__() = ManualVehicleEngineAndLights;
#if defined _ALS_ManualVehicleEngineAndLights
	// Previous hook.
	#define _ALS_ManualVehicleEngineAndLights__
	#define ManualVehicleEngineAndLights__( ManualVehicleEngineAndLights(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleParamsEx__(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
#if defined _ALS_SetVehicleParamsEx
	// Previous hook.
	#define _ALS_SetVehicleParamsEx__
	#define SetVehicleParamsEx__( SetVehicleParamsEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleParamsEx__(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
#if defined _ALS_GetVehicleParamsEx
	// Previous hook.
	#define _ALS_GetVehicleParamsEx__
	#define GetVehicleParamsEx__( GetVehicleParamsEx(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleParamsSirenState(vehicleid) = GetVehicleParamsSirenState;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleParamsSirenState__(vehicleid) = GetVehicleParamsSirenState;
#if defined _ALS_GetVehicleParamsSirenState
	// Previous hook.
	#define _ALS_GetVehicleParamsSirenState__
	#define GetVehicleParamsSirenState__( GetVehicleParamsSirenState(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleParamsCarDoors(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleParamsCarDoors__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarDoors;
#if defined _ALS_SetVehicleParamsCarDoors
	// Previous hook.
	#define _ALS_SetVehicleParamsCarDoors__
	#define SetVehicleParamsCarDoors__( SetVehicleParamsCarDoors(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleParamsCarDoors(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleParamsCarDoors__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarDoors;
#if defined _ALS_GetVehicleParamsCarDoors
	// Previous hook.
	#define _ALS_GetVehicleParamsCarDoors__
	#define GetVehicleParamsCarDoors__( GetVehicleParamsCarDoors(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleParamsCarWindows(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleParamsCarWindows__(vehicleid, frontLeft, frontRight, rearLeft, rearRight) = SetVehicleParamsCarWindows;
#if defined _ALS_SetVehicleParamsCarWindows
	// Previous hook.
	#define _ALS_SetVehicleParamsCarWindows__
	#define SetVehicleParamsCarWindows__( SetVehicleParamsCarWindows(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleParamsCarWindows(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleParamsCarWindows__(vehicleid, &frontLeft, &frontRight, &rearLeft, &rearRight) = GetVehicleParamsCarWindows;
#if defined _ALS_GetVehicleParamsCarWindows
	// Previous hook.
	#define _ALS_GetVehicleParamsCarWindows__
	#define GetVehicleParamsCarWindows__( GetVehicleParamsCarWindows(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleToRespawn(vehicleid) = SetVehicleToRespawn;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleToRespawn__(vehicleid) = SetVehicleToRespawn;
#if defined _ALS_SetVehicleToRespawn
	// Previous hook.
	#define _ALS_SetVehicleToRespawn__
	#define SetVehicleToRespawn__( SetVehicleToRespawn(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_LinkVehicleToInterior(vehicleid, interiorid) = LinkVehicleToInterior;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native LinkVehicleToInterior__(vehicleid, interiorid) = LinkVehicleToInterior;
#if defined _ALS_LinkVehicleToInterior
	// Previous hook.
	#define _ALS_LinkVehicleToInterior__
	#define LinkVehicleToInterior__( LinkVehicleToInterior(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AddVehicleComponent__(vehicleid, componentid) = AddVehicleComponent;
#if defined _ALS_AddVehicleComponent
	// Previous hook.
	#define _ALS_AddVehicleComponent__
	#define AddVehicleComponent__( AddVehicleComponent(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RemoveVehicleComponent__(vehicleid, componentid) = RemoveVehicleComponent;
#if defined _ALS_RemoveVehicleComponent
	// Previous hook.
	#define _ALS_RemoveVehicleComponent__
	#define RemoveVehicleComponent__( RemoveVehicleComponent(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ChangeVehicleColor(vehicleid, colour1, colour2) = ChangeVehicleColor;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ChangeVehicleColor__(vehicleid, colour1, colour2) = ChangeVehicleColor;
#if defined _ALS_ChangeVehicleColor
	// Previous hook.
	#define _ALS_ChangeVehicleColor__
	#define ChangeVehicleColor__( ChangeVehicleColor(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_ChangeVehiclePaintjob(vehicleid, paintjobid) = ChangeVehiclePaintjob;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native ChangeVehiclePaintjob__(vehicleid, paintjobid) = ChangeVehiclePaintjob;
#if defined _ALS_ChangeVehiclePaintjob
	// Previous hook.
	#define _ALS_ChangeVehiclePaintjob__
	#define ChangeVehiclePaintjob__( ChangeVehiclePaintjob(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleHealth(vehicleid, Float:health) = SetVehicleHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleHealth__(vehicleid, Float:health) = SetVehicleHealth;
#if defined _ALS_SetVehicleHealth
	// Previous hook.
	#define _ALS_SetVehicleHealth__
	#define SetVehicleHealth__( SetVehicleHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleHealth(vehicleid, &Float:health) = GetVehicleHealth;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleHealth__(vehicleid, &Float:health) = GetVehicleHealth;
#if defined _ALS_GetVehicleHealth
	// Previous hook.
	#define _ALS_GetVehicleHealth__
	#define GetVehicleHealth__( GetVehicleHealth(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native AttachTrailerToVehicle__(trailerid, vehicleid) = AttachTrailerToVehicle;
#if defined _ALS_AttachTrailerToVehicle
	// Previous hook.
	#define _ALS_AttachTrailerToVehicle__
	#define AttachTrailerToVehicle__( AttachTrailerToVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_DetachTrailerFromVehicle(vehicleid) = DetachTrailerFromVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native DetachTrailerFromVehicle__(vehicleid) = DetachTrailerFromVehicle;
#if defined _ALS_DetachTrailerFromVehicle
	// Previous hook.
	#define _ALS_DetachTrailerFromVehicle__
	#define DetachTrailerFromVehicle__( DetachTrailerFromVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsTrailerAttachedToVehicle(vehicleid) = IsTrailerAttachedToVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsTrailerAttachedToVehicle__(vehicleid) = IsTrailerAttachedToVehicle;
#if defined _ALS_IsTrailerAttachedToVehicle
	// Previous hook.
	#define _ALS_IsTrailerAttachedToVehicle__
	#define IsTrailerAttachedToVehicle__( IsTrailerAttachedToVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleTrailer(vehicleid) = GetVehicleTrailer;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleTrailer__(vehicleid) = GetVehicleTrailer;
#if defined _ALS_GetVehicleTrailer
	// Previous hook.
	#define _ALS_GetVehicleTrailer__
	#define GetVehicleTrailer__( GetVehicleTrailer(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleNumberPlate(vehicleid, numberPlate[]) = SetVehicleNumberPlate;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleNumberPlate(vehicleid, _FIXES_MAYBE_CONST numberPlate[]) = SetVehicleNumberPlate;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleNumberPlate__(vehicleid, const numberPlate[]) = SetVehicleNumberPlate;
#if defined _ALS_SetVehicleNumberPlate
	// Previous hook.
	#define _ALS_SetVehicleNumberPlate__
	#define SetVehicleNumberPlate__( SetVehicleNumberPlate(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleModel(vehicleid) = GetVehicleModel;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleModel(vehicleid) = GetVehicleModel;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleModel__(vehicleid) = GetVehicleModel;
#if defined _ALS_GetVehicleModel
	// Previous hook.
	#define _ALS_GetVehicleModel__
	#define GetVehicleModel__( GetVehicleModel(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleComponentInSlot__(vehicleid, CARMODTYPE:slot) = GetVehicleComponentInSlot;
#if defined _ALS_GetVehicleComponentInSlot
	// Previous hook.
	#define _ALS_GetVehicleComponentInSlot__
	#define GetVehicleComponentInSlot__( GetVehicleComponentInSlot(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native CARMODTYPE:BAD_GetVehicleComponentType(component) = GetVehicleComponentType;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CARMODTYPE:CST_GetVehicleComponentType(component) = GetVehicleComponentType;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native CARMODTYPE:GetVehicleComponentType__(component) = GetVehicleComponentType;
#if defined _ALS_GetVehicleComponentType
	// Previous hook.
	#define _ALS_GetVehicleComponentType__
	#define GetVehicleComponentType__( GetVehicleComponentType(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_RepairVehicle(vehicleid) = RepairVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_RepairVehicle(vehicleid) = RepairVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native RepairVehicle__(vehicleid) = RepairVehicle;
#if defined _ALS_RepairVehicle
	// Previous hook.
	#define _ALS_RepairVehicle__
	#define RepairVehicle__( RepairVehicle(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleVelocity__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehicleVelocity;
#if defined _ALS_GetVehicleVelocity
	// Previous hook.
	#define _ALS_GetVehicleVelocity__
	#define GetVehicleVelocity__( GetVehicleVelocity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleVelocity;
#if defined _ALS_SetVehicleVelocity
	// Previous hook.
	#define _ALS_SetVehicleVelocity__
	#define SetVehicleVelocity__( SetVehicleVelocity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleAngularVelocity__(vehicleid, Float:x, Float:y, Float:z) = SetVehicleAngularVelocity;
#if defined _ALS_SetVehicleAngularVelocity
	// Previous hook.
	#define _ALS_SetVehicleAngularVelocity__
	#define SetVehicleAngularVelocity__( SetVehicleAngularVelocity(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleDamageStatus__(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
#if defined _ALS_GetVehicleDamageStatus
	// Previous hook.
	#define _ALS_GetVehicleDamageStatus__
	#define GetVehicleDamageStatus__( GetVehicleDamageStatus(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native UpdateVehicleDamageStatus__(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
#if defined _ALS_UpdateVehicleDamageStatus
	// Previous hook.
	#define _ALS_UpdateVehicleDamageStatus__
	#define UpdateVehicleDamageStatus__( UpdateVehicleDamageStatus(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleModelInfo__(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z) = GetVehicleModelInfo;
#if defined _ALS_GetVehicleModelInfo
	// Previous hook.
	#define _ALS_GetVehicleModelInfo__
	#define GetVehicleModelInfo__( GetVehicleModelInfo(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_SetVehicleVirtualWorld(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native SetVehicleVirtualWorld__(vehicleid, virtualWorld) = SetVehicleVirtualWorld;
#if defined _ALS_SetVehicleVirtualWorld
	// Previous hook.
	#define _ALS_SetVehicleVirtualWorld__
	#define SetVehicleVirtualWorld__( SetVehicleVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native CST_GetVehicleVirtualWorld(vehicleid) = GetVehicleVirtualWorld;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native GetVehicleVirtualWorld__(vehicleid) = GetVehicleVirtualWorld;
#if defined _ALS_GetVehicleVirtualWorld
	// Previous hook.
	#define _ALS_GetVehicleVirtualWorld__
	#define GetVehicleVirtualWorld__( GetVehicleVirtualWorld(
#endif

/**
 * <remarks>
 *   The original declaration as in the basic SA:MP includes.
 * </remarks>
 */
native BAD_IsValidVehicle(vehicleid) = IsValidVehicle;
/**
 * <remarks>
 *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.
 * </remarks>
 */
native _FIXES_MAYBE_BOOL:CST_IsValidVehicle(vehicleid) = IsValidVehicle;
/**
 * <remarks>
 *   The best declaration with all fixes aways applied.
 * </remarks>
 */
native bool:IsValidVehicle__(vehicleid) = IsValidVehicle;
#if defined _ALS_IsValidVehicle
	// Previous hook.
	#define _ALS_IsValidVehicle__
	#define IsValidVehicle__( IsValidVehicle(
#endif

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
}

/*

	 ¦¦¦¦¦           ¦¦¦¦¦   ¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦   ¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦   ¦¦
	¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦   ¦¦ ¦¦         ¦¦    ¦¦    ¦¦ ¦¦   ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦  ¦¦¦¦¦¦    ¦¦     ¦¦¦¦¦¦  ¦¦   ¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_CreateActor
		#undef CreateActor
	#endif
	#define _ALS_CreateActor
	#define CreateActor( CST_CreateActor(

	#if defined _ALS_DestroyActor
		#undef DestroyActor
	#endif
	#define _ALS_DestroyActor
	#define DestroyActor( CST_DestroyActor(

	#if defined _ALS_IsActorStreamedIn
		#undef IsActorStreamedIn
	#endif
	#define _ALS_IsActorStreamedIn
	#define IsActorStreamedIn( CST_IsActorStreamedIn(

	#if defined _ALS_SetActorVirtualWorld
		#undef SetActorVirtualWorld
	#endif
	#define _ALS_SetActorVirtualWorld
	#define SetActorVirtualWorld( CST_SetActorVirtualWorld(

	#if defined _ALS_GetActorVirtualWorld
		#undef GetActorVirtualWorld
	#endif
	#define _ALS_GetActorVirtualWorld
	#define GetActorVirtualWorld( CST_GetActorVirtualWorld(

	#if defined _ALS_ApplyActorAnimation
		#undef ApplyActorAnimation
	#endif
	#define _ALS_ApplyActorAnimation
	#define ApplyActorAnimation( CST_ApplyActorAnimation(

	#if defined _ALS_ClearActorAnimations
		#undef ClearActorAnimations
	#endif
	#define _ALS_ClearActorAnimations
	#define ClearActorAnimations( CST_ClearActorAnimations(

	#if defined _ALS_SetActorPos
		#undef SetActorPos
	#endif
	#define _ALS_SetActorPos
	#define SetActorPos( CST_SetActorPos(

	#if defined _ALS_GetActorPos
		#undef GetActorPos
	#endif
	#define _ALS_GetActorPos
	#define GetActorPos( CST_GetActorPos(

	#if defined _ALS_SetActorFacingAngle
		#undef SetActorFacingAngle
	#endif
	#define _ALS_SetActorFacingAngle
	#define SetActorFacingAngle( CST_SetActorFacingAngle(

	#if defined _ALS_GetActorFacingAngle
		#undef GetActorFacingAngle
	#endif
	#define _ALS_GetActorFacingAngle
	#define GetActorFacingAngle( CST_GetActorFacingAngle(

	#if defined _ALS_SetActorHealth
		#undef SetActorHealth
	#endif
	#define _ALS_SetActorHealth
	#define SetActorHealth( CST_SetActorHealth(

	#if defined _ALS_GetActorHealth
		#undef GetActorHealth
	#endif
	#define _ALS_GetActorHealth
	#define GetActorHealth( CST_GetActorHealth(

	#if defined _ALS_SetActorInvulnerable
		#undef SetActorInvulnerable
	#endif
	#define _ALS_SetActorInvulnerable
	#define SetActorInvulnerable( CST_SetActorInvulnerable(

	#if defined _ALS_IsActorInvulnerable
		#undef IsActorInvulnerable
	#endif
	#define _ALS_IsActorInvulnerable
	#define IsActorInvulnerable( CST_IsActorInvulnerable(

	#if defined _ALS_IsValidActor
		#undef IsValidActor
	#endif
	#define _ALS_IsValidActor
	#define IsValidActor( CST_IsValidActor(
#endif

/*

	 ¦¦¦¦¦          ¦¦   ¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦   ¦¦    ¦¦       ¦¦    ¦¦   ¦¦
	¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦    ¦¦       ¦¦    ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦   ¦¦    ¦¦       ¦¦    ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦    ¦¦       ¦¦    ¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_HTTP
		#undef HTTP
	#endif
	#define _ALS_HTTP
	#define HTTP( CST_HTTP(
#endif

/*

	 ¦¦¦¦¦           ¦¦¦¦¦¦  ¦¦¦¦¦¦       ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦    ¦¦ ¦¦   ¦¦      ¦¦ ¦¦      ¦¦         ¦¦    ¦¦
	¦¦¦¦¦¦¦         ¦¦    ¦¦ ¦¦¦¦¦¦       ¦¦ ¦¦¦¦¦   ¦¦         ¦¦    ¦¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦    ¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦      ¦¦         ¦¦         ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦¦¦¦¦  ¦¦¦¦¦¦    ¦¦    ¦¦¦¦¦¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_CreateObject
		#undef CreateObject
	#endif
	#define _ALS_CreateObject
	#define CreateObject( CST_CreateObject(

	#if defined _ALS_AttachObjectToVehicle
		#undef AttachObjectToVehicle
	#endif
	#define _ALS_AttachObjectToVehicle
	#define AttachObjectToVehicle( CST_AttachObjectToVehicle(

	#if defined _ALS_AttachObjectToObject
		#undef AttachObjectToObject
	#endif
	#define _ALS_AttachObjectToObject
	#define AttachObjectToObject( CST_AttachObjectToObject(

	#if defined _ALS_AttachObjectToPlayer
		#undef AttachObjectToPlayer
	#endif
	#define _ALS_AttachObjectToPlayer
	#define AttachObjectToPlayer( CST_AttachObjectToPlayer(

	#if defined _ALS_SetObjectPos
		#undef SetObjectPos
	#endif
	#define _ALS_SetObjectPos
	#define SetObjectPos( CST_SetObjectPos(

	#if defined _ALS_GetObjectPos
		#undef GetObjectPos
	#endif
	#define _ALS_GetObjectPos
	#define GetObjectPos( CST_GetObjectPos(

	#if defined _ALS_SetObjectRot
		#undef SetObjectRot
	#endif
	#define _ALS_SetObjectRot
	#define SetObjectRot( CST_SetObjectRot(

	#if defined _ALS_GetObjectRot
		#undef GetObjectRot
	#endif
	#define _ALS_GetObjectRot
	#define GetObjectRot( CST_GetObjectRot(

	#if defined _ALS_GetObjectModel
		#undef GetObjectModel
	#endif
	#define _ALS_GetObjectModel
	#define GetObjectModel( CST_GetObjectModel(

	#if defined _ALS_SetObjectNoCameraCol
		#undef SetObjectNoCameraCol
	#endif
	#define _ALS_SetObjectNoCameraCol
	#define SetObjectNoCameraCol( CST_SetObjectNoCameraCol(

	#if defined _ALS_IsValidObject
		#undef IsValidObject
	#endif
	#define _ALS_IsValidObject
	#define IsValidObject( CST_IsValidObject(

	#if defined _ALS_DestroyObject
		#undef DestroyObject
	#endif
	#define _ALS_DestroyObject
	#define DestroyObject( CST_DestroyObject(

	#if defined _ALS_MoveObject
		#undef MoveObject
	#endif
	#define _ALS_MoveObject
	#define MoveObject( CST_MoveObject(

	#if defined _ALS_StopObject
		#undef StopObject
	#endif
	#define _ALS_StopObject
	#define StopObject( CST_StopObject(

	#if defined _ALS_IsObjectMoving
		#undef IsObjectMoving
	#endif
	#define _ALS_IsObjectMoving
	#define IsObjectMoving( CST_IsObjectMoving(

	#if defined _ALS_EditObject
		#undef EditObject
	#endif
	#define _ALS_EditObject
	#define EditObject( CST_EditObject(

	#if defined _ALS_EditPlayerObject
		#undef EditPlayerObject
	#endif
	#define _ALS_EditPlayerObject
	#define EditPlayerObject( CST_EditPlayerObject(

	#if defined _ALS_SelectObject
		#undef SelectObject
	#endif
	#define _ALS_SelectObject
	#define SelectObject( CST_SelectObject(

	#if defined _ALS_CancelEdit
		#undef CancelEdit
	#endif
	#define _ALS_CancelEdit
	#define CancelEdit( CST_CancelEdit(

	#if defined _ALS_CreatePlayerObject
		#undef CreatePlayerObject
	#endif
	#define _ALS_CreatePlayerObject
	#define CreatePlayerObject( CST_CreatePlayerObject(

	#if defined _ALS_AttachPlayerObjectToVehicle
		#undef AttachPlayerObjectToVehicle
	#endif
	#define _ALS_AttachPlayerObjectToVehicle
	#define AttachPlayerObjectToVehicle( CST_AttachPlayerObjectToVehicle(

	#if defined _ALS_SetPlayerObjectPos
		#undef SetPlayerObjectPos
	#endif
	#define _ALS_SetPlayerObjectPos
	#define SetPlayerObjectPos( CST_SetPlayerObjectPos(

	#if defined _ALS_GetPlayerObjectPos
		#undef GetPlayerObjectPos
	#endif
	#define _ALS_GetPlayerObjectPos
	#define GetPlayerObjectPos( CST_GetPlayerObjectPos(

	#if defined _ALS_SetPlayerObjectRot
		#undef SetPlayerObjectRot
	#endif
	#define _ALS_SetPlayerObjectRot
	#define SetPlayerObjectRot( CST_SetPlayerObjectRot(

	#if defined _ALS_GetPlayerObjectRot
		#undef GetPlayerObjectRot
	#endif
	#define _ALS_GetPlayerObjectRot
	#define GetPlayerObjectRot( CST_GetPlayerObjectRot(

	#if defined _ALS_GetPlayerObjectModel
		#undef GetPlayerObjectModel
	#endif
	#define _ALS_GetPlayerObjectModel
	#define GetPlayerObjectModel( CST_GetPlayerObjectModel(

	#if defined _ALS_SetPlayerObjectNoCameraCol
		#undef SetPlayerObjectNoCameraCol
	#endif
	#define _ALS_SetPlayerObjectNoCameraCol
	#define SetPlayerObjectNoCameraCol( CST_SetPlayerObjectNoCameraCol(

	#if defined _ALS_IsValidPlayerObject
		#undef IsValidPlayerObject
	#endif
	#define _ALS_IsValidPlayerObject
	#define IsValidPlayerObject( CST_IsValidPlayerObject(

	#if defined _ALS_DestroyPlayerObject
		#undef DestroyPlayerObject
	#endif
	#define _ALS_DestroyPlayerObject
	#define DestroyPlayerObject( CST_DestroyPlayerObject(

	#if defined _ALS_MovePlayerObject
		#undef MovePlayerObject
	#endif
	#define _ALS_MovePlayerObject
	#define MovePlayerObject( CST_MovePlayerObject(

	#if defined _ALS_StopPlayerObject
		#undef StopPlayerObject
	#endif
	#define _ALS_StopPlayerObject
	#define StopPlayerObject( CST_StopPlayerObject(

	#if defined _ALS_IsPlayerObjectMoving
		#undef IsPlayerObjectMoving
	#endif
	#define _ALS_IsPlayerObjectMoving
	#define IsPlayerObjectMoving( CST_IsPlayerObjectMoving(

	#if defined _ALS_AttachPlayerObjectToPlayer
		#undef AttachPlayerObjectToPlayer
	#endif
	#define _ALS_AttachPlayerObjectToPlayer
	#define AttachPlayerObjectToPlayer( CST_AttachPlayerObjectToPlayer(

	#if defined _ALS_SetObjectMaterial
		#undef SetObjectMaterial
	#endif
	#define _ALS_SetObjectMaterial
	#define SetObjectMaterial( CST_SetObjectMaterial(

	#if defined _ALS_SetPlayerObjectMaterial
		#undef SetPlayerObjectMaterial
	#endif
	#define _ALS_SetPlayerObjectMaterial
	#define SetPlayerObjectMaterial( CST_SetPlayerObjectMaterial(

	#if defined _ALS_SetObjectMaterialText
		#undef SetObjectMaterialText
	#endif
	#define _ALS_SetObjectMaterialText
	#define SetObjectMaterialText( CST_SetObjectMaterialText(

	#if defined _ALS_SetPlayerObjectMaterialText
		#undef SetPlayerObjectMaterialText
	#endif
	#define _ALS_SetPlayerObjectMaterialText
	#define SetPlayerObjectMaterialText( CST_SetPlayerObjectMaterialText(

	#if defined _ALS_SetObjectsDefaultCameraCol
		#undef SetObjectsDefaultCameraCol
	#endif
	#define _ALS_SetObjectsDefaultCameraCol
	#define SetObjectsDefaultCameraCol( CST_SetObjectsDefaultCameraCol(
#endif

/*

	 ¦¦¦¦¦          ¦¦¦¦¦¦  ¦¦       ¦¦¦¦¦  ¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦   ¦¦ ¦¦      ¦¦   ¦¦  ¦¦  ¦¦  ¦¦      ¦¦   ¦¦ ¦¦
	¦¦¦¦¦¦¦         ¦¦¦¦¦¦  ¦¦      ¦¦¦¦¦¦¦   ¦¦¦¦   ¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦      ¦¦      ¦¦   ¦¦    ¦¦    ¦¦      ¦¦   ¦¦      ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦   ¦¦    ¦¦    ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_SetSpawnInfo
		#undef SetSpawnInfo
	#endif
	#define _ALS_SetSpawnInfo
	#define SetSpawnInfo( CST_SetSpawnInfo(

	#if defined _ALS_SpawnPlayer
		#undef SpawnPlayer
	#endif
	#define _ALS_SpawnPlayer
	#define SpawnPlayer( CST_SpawnPlayer(

	#if defined _ALS_SetPlayerPos
		#undef SetPlayerPos
	#endif
	#define _ALS_SetPlayerPos
	#define SetPlayerPos( CST_SetPlayerPos(

	#if defined _ALS_SetPlayerPosFindZ
		#undef SetPlayerPosFindZ
	#endif
	#define _ALS_SetPlayerPosFindZ
	#define SetPlayerPosFindZ( CST_SetPlayerPosFindZ(

	#if defined _ALS_GetPlayerPos
		#undef GetPlayerPos
	#endif
	#define _ALS_GetPlayerPos
	#define GetPlayerPos( CST_GetPlayerPos(

	#if defined _ALS_SetPlayerFacingAngle
		#undef SetPlayerFacingAngle
	#endif
	#define _ALS_SetPlayerFacingAngle
	#define SetPlayerFacingAngle( CST_SetPlayerFacingAngle(

	#if defined _ALS_GetPlayerFacingAngle
		#undef GetPlayerFacingAngle
	#endif
	#define _ALS_GetPlayerFacingAngle
	#define GetPlayerFacingAngle( CST_GetPlayerFacingAngle(

	#if defined _ALS_IsPlayerInRangeOfPoint
		#undef IsPlayerInRangeOfPoint
	#endif
	#define _ALS_IsPlayerInRangeOfPoint
	#define IsPlayerInRangeOfPoint( CST_IsPlayerInRangeOfPoint(

	#if defined _ALS_GetPlayerDistanceFromPoint
		#undef GetPlayerDistanceFromPoint
	#endif
	#define _ALS_GetPlayerDistanceFromPoint
	#define GetPlayerDistanceFromPoint( CST_GetPlayerDistanceFromPoint(

	#if defined _ALS_IsPlayerStreamedIn
		#undef IsPlayerStreamedIn
	#endif
	#define _ALS_IsPlayerStreamedIn
	#define IsPlayerStreamedIn( CST_IsPlayerStreamedIn(

	#if defined _ALS_SetPlayerInterior
		#undef SetPlayerInterior
	#endif
	#define _ALS_SetPlayerInterior
	#define SetPlayerInterior( CST_SetPlayerInterior(

	#if defined _ALS_GetPlayerInterior
		#undef GetPlayerInterior
	#endif
	#define _ALS_GetPlayerInterior
	#define GetPlayerInterior( CST_GetPlayerInterior(

	#if defined _ALS_SetPlayerHealth
		#undef SetPlayerHealth
	#endif
	#define _ALS_SetPlayerHealth
	#define SetPlayerHealth( CST_SetPlayerHealth(

	#if defined _ALS_GetPlayerHealth
		#undef GetPlayerHealth
	#endif
	#define _ALS_GetPlayerHealth
	#define GetPlayerHealth( CST_GetPlayerHealth(

	#if defined _ALS_SetPlayerArmour
		#undef SetPlayerArmour
	#endif
	#define _ALS_SetPlayerArmour
	#define SetPlayerArmour( CST_SetPlayerArmour(

	#if defined _ALS_GetPlayerArmour
		#undef GetPlayerArmour
	#endif
	#define _ALS_GetPlayerArmour
	#define GetPlayerArmour( CST_GetPlayerArmour(

	#if defined _ALS_SetPlayerAmmo
		#undef SetPlayerAmmo
	#endif
	#define _ALS_SetPlayerAmmo
	#define SetPlayerAmmo( CST_SetPlayerAmmo(

	#if defined _ALS_GetPlayerAmmo
		#undef GetPlayerAmmo
	#endif
	#define _ALS_GetPlayerAmmo
	#define GetPlayerAmmo( CST_GetPlayerAmmo(

	#if defined _ALS_GetPlayerWeaponState
		#undef GetPlayerWeaponState
	#endif
	#define _ALS_GetPlayerWeaponState
	#define GetPlayerWeaponState( CST_GetPlayerWeaponState(

	#if defined _ALS_GetPlayerTargetPlayer
		#undef GetPlayerTargetPlayer
	#endif
	#define _ALS_GetPlayerTargetPlayer
	#define GetPlayerTargetPlayer( CST_GetPlayerTargetPlayer(

	#if defined _ALS_GetPlayerTargetActor
		#undef GetPlayerTargetActor
	#endif
	#define _ALS_GetPlayerTargetActor
	#define GetPlayerTargetActor( CST_GetPlayerTargetActor(

	#if defined _ALS_SetPlayerTeam
		#undef SetPlayerTeam
	#endif
	#define _ALS_SetPlayerTeam
	#define SetPlayerTeam( CST_SetPlayerTeam(

	#if defined _ALS_GetPlayerTeam
		#undef GetPlayerTeam
	#endif
	#define _ALS_GetPlayerTeam
	#define GetPlayerTeam( CST_GetPlayerTeam(

	#if defined _ALS_SetPlayerScore
		#undef SetPlayerScore
	#endif
	#define _ALS_SetPlayerScore
	#define SetPlayerScore( CST_SetPlayerScore(

	#if defined _ALS_GetPlayerScore
		#undef GetPlayerScore
	#endif
	#define _ALS_GetPlayerScore
	#define GetPlayerScore( CST_GetPlayerScore(

	#if defined _ALS_GetPlayerDrunkLevel
		#undef GetPlayerDrunkLevel
	#endif
	#define _ALS_GetPlayerDrunkLevel
	#define GetPlayerDrunkLevel( CST_GetPlayerDrunkLevel(

	#if defined _ALS_SetPlayerDrunkLevel
		#undef SetPlayerDrunkLevel
	#endif
	#define _ALS_SetPlayerDrunkLevel
	#define SetPlayerDrunkLevel( CST_SetPlayerDrunkLevel(

	#if defined _ALS_SetPlayerColor
		#undef SetPlayerColor
	#endif
	#define _ALS_SetPlayerColor
	#define SetPlayerColor( CST_SetPlayerColor(

	#if defined _ALS_GetPlayerColor
		#undef GetPlayerColor
	#endif
	#define _ALS_GetPlayerColor
	#define GetPlayerColor( CST_GetPlayerColor(

	#if defined _ALS_SetPlayerSkin
		#undef SetPlayerSkin
	#endif
	#define _ALS_SetPlayerSkin
	#define SetPlayerSkin( CST_SetPlayerSkin(

	#if defined _ALS_GetPlayerSkin
		#undef GetPlayerSkin
	#endif
	#define _ALS_GetPlayerSkin
	#define GetPlayerSkin( CST_GetPlayerSkin(

	#if defined _ALS_GetPlayerCustomSkin
		#undef GetPlayerCustomSkin
	#endif
	#define _ALS_GetPlayerCustomSkin
	#define GetPlayerCustomSkin( CST_GetPlayerCustomSkin(

	#if defined _ALS_GivePlayerWeapon
		#undef GivePlayerWeapon
	#endif
	#define _ALS_GivePlayerWeapon
	#define GivePlayerWeapon( CST_GivePlayerWeapon(

	#if defined _ALS_ResetPlayerWeapons
		#undef ResetPlayerWeapons
	#endif
	#define _ALS_ResetPlayerWeapons
	#define ResetPlayerWeapons( CST_ResetPlayerWeapons(

	#if defined _ALS_SetPlayerArmedWeapon
		#undef SetPlayerArmedWeapon
	#endif
	#define _ALS_SetPlayerArmedWeapon
	#define SetPlayerArmedWeapon( CST_SetPlayerArmedWeapon(

	#if defined _ALS_GetPlayerWeaponData
		#undef GetPlayerWeaponData
	#endif
	#define _ALS_GetPlayerWeaponData
	#define GetPlayerWeaponData( CST_GetPlayerWeaponData(

	#if defined _ALS_GivePlayerMoney
		#undef GivePlayerMoney
	#endif
	#define _ALS_GivePlayerMoney
	#define GivePlayerMoney( CST_GivePlayerMoney(

	#if defined _ALS_ResetPlayerMoney
		#undef ResetPlayerMoney
	#endif
	#define _ALS_ResetPlayerMoney
	#define ResetPlayerMoney( CST_ResetPlayerMoney(

	#if defined _ALS_SetPlayerName
		#undef SetPlayerName
	#endif
	#define _ALS_SetPlayerName
	#define SetPlayerName( CST_SetPlayerName(

	#if defined _ALS_GetPlayerMoney
		#undef GetPlayerMoney
	#endif
	#define _ALS_GetPlayerMoney
	#define GetPlayerMoney( CST_GetPlayerMoney(

	#if defined _ALS_GetPlayerState
		#undef GetPlayerState
	#endif
	#define _ALS_GetPlayerState
	#define GetPlayerState( CST_GetPlayerState(

	#if defined _ALS_GetPlayerIp
		#undef GetPlayerIp
	#endif
	#define _ALS_GetPlayerIp
	#define GetPlayerIp( CST_GetPlayerIp(

	#if defined _ALS_GetPlayerPing
		#undef GetPlayerPing
	#endif
	#define _ALS_GetPlayerPing
	#define GetPlayerPing( CST_GetPlayerPing(

	#if defined _ALS_GetPlayerWeapon
		#undef GetPlayerWeapon
	#endif
	#define _ALS_GetPlayerWeapon
	#define GetPlayerWeapon( CST_GetPlayerWeapon(

	#if defined _ALS_GetPlayerKeys
		#undef GetPlayerKeys
	#endif
	#define _ALS_GetPlayerKeys
	#define GetPlayerKeys( CST_GetPlayerKeys(

	#if defined _ALS_GetPlayerName
		#undef GetPlayerName
	#endif
	#define _ALS_GetPlayerName
	#define GetPlayerName( CST_GetPlayerName(

	#if defined _ALS_SetPlayerTime
		#undef SetPlayerTime
	#endif
	#define _ALS_SetPlayerTime
	#define SetPlayerTime( CST_SetPlayerTime(

	#if defined _ALS_GetPlayerTime
		#undef GetPlayerTime
	#endif
	#define _ALS_GetPlayerTime
	#define GetPlayerTime( CST_GetPlayerTime(

	#if defined _ALS_TogglePlayerClock
		#undef TogglePlayerClock
	#endif
	#define _ALS_TogglePlayerClock
	#define TogglePlayerClock( CST_TogglePlayerClock(

	#if defined _ALS_SetPlayerWeather
		#undef SetPlayerWeather
	#endif
	#define _ALS_SetPlayerWeather
	#define SetPlayerWeather( CST_SetPlayerWeather(

	#if defined _ALS_ForceClassSelection
		#undef ForceClassSelection
	#endif
	#define _ALS_ForceClassSelection
	#define ForceClassSelection( CST_ForceClassSelection(

	#if defined _ALS_SetPlayerWantedLevel
		#undef SetPlayerWantedLevel
	#endif
	#define _ALS_SetPlayerWantedLevel
	#define SetPlayerWantedLevel( CST_SetPlayerWantedLevel(

	#if defined _ALS_GetPlayerWantedLevel
		#undef GetPlayerWantedLevel
	#endif
	#define _ALS_GetPlayerWantedLevel
	#define GetPlayerWantedLevel( CST_GetPlayerWantedLevel(

	#if defined _ALS_SetPlayerFightingStyle
		#undef SetPlayerFightingStyle
	#endif
	#define _ALS_SetPlayerFightingStyle
	#define SetPlayerFightingStyle( CST_SetPlayerFightingStyle(

	#if defined _ALS_GetPlayerFightingStyle
		#undef GetPlayerFightingStyle
	#endif
	#define _ALS_GetPlayerFightingStyle
	#define GetPlayerFightingStyle( CST_GetPlayerFightingStyle(

	#if defined _ALS_SetPlayerVelocity
		#undef SetPlayerVelocity
	#endif
	#define _ALS_SetPlayerVelocity
	#define SetPlayerVelocity( CST_SetPlayerVelocity(

	#if defined _ALS_GetPlayerVelocity
		#undef GetPlayerVelocity
	#endif
	#define _ALS_GetPlayerVelocity
	#define GetPlayerVelocity( CST_GetPlayerVelocity(

	#if defined _ALS_PlayCrimeReportForPlayer
		#undef PlayCrimeReportForPlayer
	#endif
	#define _ALS_PlayCrimeReportForPlayer
	#define PlayCrimeReportForPlayer( CST_PlayCrimeReportForPlayer(

	#if defined _ALS_PlayAudioStreamForPlayer
		#undef PlayAudioStreamForPlayer
	#endif
	#define _ALS_PlayAudioStreamForPlayer
	#define PlayAudioStreamForPlayer( CST_PlayAudioStreamForPlayer(

	#if defined _ALS_StopAudioStreamForPlayer
		#undef StopAudioStreamForPlayer
	#endif
	#define _ALS_StopAudioStreamForPlayer
	#define StopAudioStreamForPlayer( CST_StopAudioStreamForPlayer(

	#if defined _ALS_SetPlayerShopName
		#undef SetPlayerShopName
	#endif
	#define _ALS_SetPlayerShopName
	#define SetPlayerShopName( CST_SetPlayerShopName(

	#if defined _ALS_SetPlayerSkillLevel
		#undef SetPlayerSkillLevel
	#endif
	#define _ALS_SetPlayerSkillLevel
	#define SetPlayerSkillLevel( CST_SetPlayerSkillLevel(

	#if defined _ALS_GetPlayerSurfingVehicleID
		#undef GetPlayerSurfingVehicleID
	#endif
	#define _ALS_GetPlayerSurfingVehicleID
	#define GetPlayerSurfingVehicleID( CST_GetPlayerSurfingVehicleID(

	#if defined _ALS_GetPlayerSurfingObjectID
		#undef GetPlayerSurfingObjectID
	#endif
	#define _ALS_GetPlayerSurfingObjectID
	#define GetPlayerSurfingObjectID( CST_GetPlayerSurfingObjectID(

	#if defined _ALS_RemoveBuildingForPlayer
		#undef RemoveBuildingForPlayer
	#endif
	#define _ALS_RemoveBuildingForPlayer
	#define RemoveBuildingForPlayer( CST_RemoveBuildingForPlayer(

	#if defined _ALS_GetPlayerLastShotVectors
		#undef GetPlayerLastShotVectors
	#endif
	#define _ALS_GetPlayerLastShotVectors
	#define GetPlayerLastShotVectors( CST_GetPlayerLastShotVectors(

	#if defined _ALS_SetPlayerAttachedObject
		#undef SetPlayerAttachedObject
	#endif
	#define _ALS_SetPlayerAttachedObject
	#define SetPlayerAttachedObject( CST_SetPlayerAttachedObject(

	#if defined _ALS_RemovePlayerAttachedObject
		#undef RemovePlayerAttachedObject
	#endif
	#define _ALS_RemovePlayerAttachedObject
	#define RemovePlayerAttachedObject( CST_RemovePlayerAttachedObject(

	#if defined _ALS_IsPlayerAttachedObjectSlotUsed
		#undef IsPlayerAttachedObjectSlotUsed
	#endif
	#define _ALS_IsPlayerAttachedObjectSlotUsed
	#define IsPlayerAttachedObjectSlotUsed( CST_IsPlayerAttachedObjectSlotUsed(

	#if defined _ALS_EditAttachedObject
		#undef EditAttachedObject
	#endif
	#define _ALS_EditAttachedObject
	#define EditAttachedObject( CST_EditAttachedObject(

	#if defined _ALS_CreatePlayerTextDraw
		#undef CreatePlayerTextDraw
	#endif
	#define _ALS_CreatePlayerTextDraw
	#define CreatePlayerTextDraw( CST_CreatePlayerTextDraw(

	#if defined _ALS_PlayerTextDrawDestroy
		#undef PlayerTextDrawDestroy
	#endif
	#define _ALS_PlayerTextDrawDestroy
	#define PlayerTextDrawDestroy( CST_PlayerTextDrawDestroy(

	#if defined _ALS_PlayerTextDrawLetterSize
		#undef PlayerTextDrawLetterSize
	#endif
	#define _ALS_PlayerTextDrawLetterSize
	#define PlayerTextDrawLetterSize( CST_PlayerTextDrawLetterSize(

	#if defined _ALS_PlayerTextDrawTextSize
		#undef PlayerTextDrawTextSize
	#endif
	#define _ALS_PlayerTextDrawTextSize
	#define PlayerTextDrawTextSize( CST_PlayerTextDrawTextSize(

	#if defined _ALS_PlayerTextDrawAlignment
		#undef PlayerTextDrawAlignment
	#endif
	#define _ALS_PlayerTextDrawAlignment
	#define PlayerTextDrawAlignment( CST_PlayerTextDrawAlignment(

	#if defined _ALS_PlayerTextDrawColor
		#undef PlayerTextDrawColor
	#endif
	#define _ALS_PlayerTextDrawColor
	#define PlayerTextDrawColor( CST_PlayerTextDrawColor(

	#if defined _ALS_PlayerTextDrawUseBox
		#undef PlayerTextDrawUseBox
	#endif
	#define _ALS_PlayerTextDrawUseBox
	#define PlayerTextDrawUseBox( CST_PlayerTextDrawUseBox(

	#if defined _ALS_PlayerTextDrawBoxColor
		#undef PlayerTextDrawBoxColor
	#endif
	#define _ALS_PlayerTextDrawBoxColor
	#define PlayerTextDrawBoxColor( CST_PlayerTextDrawBoxColor(

	#if defined _ALS_PlayerTextDrawSetShadow
		#undef PlayerTextDrawSetShadow
	#endif
	#define _ALS_PlayerTextDrawSetShadow
	#define PlayerTextDrawSetShadow( CST_PlayerTextDrawSetShadow(

	#if defined _ALS_PlayerTextDrawSetOutline
		#undef PlayerTextDrawSetOutline
	#endif
	#define _ALS_PlayerTextDrawSetOutline
	#define PlayerTextDrawSetOutline( CST_PlayerTextDrawSetOutline(

	#if defined _ALS_PlayerTextDrawBackgroundColor
		#undef PlayerTextDrawBackgroundColor
	#endif
	#define _ALS_PlayerTextDrawBackgroundColor
	#define PlayerTextDrawBackgroundColor( CST_PlayerTextDrawBackgroundColor(

	#if defined _ALS_PlayerTextDrawFont
		#undef PlayerTextDrawFont
	#endif
	#define _ALS_PlayerTextDrawFont
	#define PlayerTextDrawFont( CST_PlayerTextDrawFont(

	#if defined _ALS_PlayerTextDrawSetProportional
		#undef PlayerTextDrawSetProportional
	#endif
	#define _ALS_PlayerTextDrawSetProportional
	#define PlayerTextDrawSetProportional( CST_PlayerTextDrawSetProportional(

	#if defined _ALS_PlayerTextDrawSetSelectable
		#undef PlayerTextDrawSetSelectable
	#endif
	#define _ALS_PlayerTextDrawSetSelectable
	#define PlayerTextDrawSetSelectable( CST_PlayerTextDrawSetSelectable(

	#if defined _ALS_PlayerTextDrawShow
		#undef PlayerTextDrawShow
	#endif
	#define _ALS_PlayerTextDrawShow
	#define PlayerTextDrawShow( CST_PlayerTextDrawShow(

	#if defined _ALS_PlayerTextDrawHide
		#undef PlayerTextDrawHide
	#endif
	#define _ALS_PlayerTextDrawHide
	#define PlayerTextDrawHide( CST_PlayerTextDrawHide(

	#if defined _ALS_PlayerTextDrawSetString
		#undef PlayerTextDrawSetString
	#endif
	#define _ALS_PlayerTextDrawSetString
	#define PlayerTextDrawSetString( CST_PlayerTextDrawSetString(

	#if defined _ALS_PlayerTextDrawSetPreviewModel
		#undef PlayerTextDrawSetPreviewModel
	#endif
	#define _ALS_PlayerTextDrawSetPreviewModel
	#define PlayerTextDrawSetPreviewModel( CST_PlayerTextDrawSetPreviewModel(

	#if defined _ALS_PlayerTextDrawSetPreviewRot
		#undef PlayerTextDrawSetPreviewRot
	#endif
	#define _ALS_PlayerTextDrawSetPreviewRot
	#define PlayerTextDrawSetPreviewRot( CST_PlayerTextDrawSetPreviewRot(

	#if defined _ALS_PlayerTextDrawSetPreviewVehCol
		#undef PlayerTextDrawSetPreviewVehCol
	#endif
	#define _ALS_PlayerTextDrawSetPreviewVehCol
	#define PlayerTextDrawSetPreviewVehCol( CST_PlayerTextDrawSetPreviewVehCol(

	#if defined _ALS_SetPVarInt
		#undef SetPVarInt
	#endif
	#define _ALS_SetPVarInt
	#define SetPVarInt( CST_SetPVarInt(

	#if defined _ALS_GetPVarInt
		#undef GetPVarInt
	#endif
	#define _ALS_GetPVarInt
	#define GetPVarInt( CST_GetPVarInt(

	#if defined _ALS_SetPVarString
		#undef SetPVarString
	#endif
	#define _ALS_SetPVarString
	#define SetPVarString( CST_SetPVarString(

	#if defined _ALS_GetPVarString
		#undef GetPVarString
	#endif
	#define _ALS_GetPVarString
	#define GetPVarString( CST_GetPVarString(

	#if defined _ALS_SetPVarFloat
		#undef SetPVarFloat
	#endif
	#define _ALS_SetPVarFloat
	#define SetPVarFloat( CST_SetPVarFloat(

	#if defined _ALS_GetPVarFloat
		#undef GetPVarFloat
	#endif
	#define _ALS_GetPVarFloat
	#define GetPVarFloat( CST_GetPVarFloat(

	#if defined _ALS_DeletePVar
		#undef DeletePVar
	#endif
	#define _ALS_DeletePVar
	#define DeletePVar( CST_DeletePVar(

	#if defined _ALS_GetPVarsUpperIndex
		#undef GetPVarsUpperIndex
	#endif
	#define _ALS_GetPVarsUpperIndex
	#define GetPVarsUpperIndex( CST_GetPVarsUpperIndex(

	#if defined _ALS_GetPVarNameAtIndex
		#undef GetPVarNameAtIndex
	#endif
	#define _ALS_GetPVarNameAtIndex
	#define GetPVarNameAtIndex( CST_GetPVarNameAtIndex(

	#if defined _ALS_GetPVarType
		#undef GetPVarType
	#endif
	#define _ALS_GetPVarType
	#define GetPVarType( CST_GetPVarType(

	#if defined _ALS_SetPlayerChatBubble
		#undef SetPlayerChatBubble
	#endif
	#define _ALS_SetPlayerChatBubble
	#define SetPlayerChatBubble( CST_SetPlayerChatBubble(

	#if defined _ALS_PutPlayerInVehicle
		#undef PutPlayerInVehicle
	#endif
	#define _ALS_PutPlayerInVehicle
	#define PutPlayerInVehicle( CST_PutPlayerInVehicle(

	#if defined _ALS_GetPlayerVehicleID
		#undef GetPlayerVehicleID
	#endif
	#define _ALS_GetPlayerVehicleID
	#define GetPlayerVehicleID( CST_GetPlayerVehicleID(

	#if defined _ALS_GetPlayerVehicleSeat
		#undef GetPlayerVehicleSeat
	#endif
	#define _ALS_GetPlayerVehicleSeat
	#define GetPlayerVehicleSeat( CST_GetPlayerVehicleSeat(

	#if defined _ALS_RemovePlayerFromVehicle
		#undef RemovePlayerFromVehicle
	#endif
	#define _ALS_RemovePlayerFromVehicle
	#define RemovePlayerFromVehicle( CST_RemovePlayerFromVehicle(

	#if defined _ALS_TogglePlayerControllable
		#undef TogglePlayerControllable
	#endif
	#define _ALS_TogglePlayerControllable
	#define TogglePlayerControllable( CST_TogglePlayerControllable(

	#if defined _ALS_PlayerPlaySound
		#undef PlayerPlaySound
	#endif
	#define _ALS_PlayerPlaySound
	#define PlayerPlaySound( CST_PlayerPlaySound(

	#if defined _ALS_ApplyAnimation
		#undef ApplyAnimation
	#endif
	#define _ALS_ApplyAnimation
	#define ApplyAnimation( CST_ApplyAnimation(

	#if defined _ALS_ClearAnimations
		#undef ClearAnimations
	#endif
	#define _ALS_ClearAnimations
	#define ClearAnimations( CST_ClearAnimations(

	#if defined _ALS_GetPlayerAnimationIndex
		#undef GetPlayerAnimationIndex
	#endif
	#define _ALS_GetPlayerAnimationIndex
	#define GetPlayerAnimationIndex( CST_GetPlayerAnimationIndex(

	#if defined _ALS_GetAnimationName
		#undef GetAnimationName
	#endif
	#define _ALS_GetAnimationName
	#define GetAnimationName( CST_GetAnimationName(

	#if defined _ALS_GetPlayerSpecialAction
		#undef GetPlayerSpecialAction
	#endif
	#define _ALS_GetPlayerSpecialAction
	#define GetPlayerSpecialAction( CST_GetPlayerSpecialAction(

	#if defined _ALS_SetPlayerSpecialAction
		#undef SetPlayerSpecialAction
	#endif
	#define _ALS_SetPlayerSpecialAction
	#define SetPlayerSpecialAction( CST_SetPlayerSpecialAction(

	#if defined _ALS_DisableRemoteVehicleCollisions
		#undef DisableRemoteVehicleCollisions
	#endif
	#define _ALS_DisableRemoteVehicleCollisions
	#define DisableRemoteVehicleCollisions( CST_DisableRemoteVehicleCollisions(

	#if defined _ALS_SetPlayerCheckpoint
		#undef SetPlayerCheckpoint
	#endif
	#define _ALS_SetPlayerCheckpoint
	#define SetPlayerCheckpoint( CST_SetPlayerCheckpoint(

	#if defined _ALS_DisablePlayerCheckpoint
		#undef DisablePlayerCheckpoint
	#endif
	#define _ALS_DisablePlayerCheckpoint
	#define DisablePlayerCheckpoint( CST_DisablePlayerCheckpoint(

	#if defined _ALS_SetPlayerRaceCheckpoint
		#undef SetPlayerRaceCheckpoint
	#endif
	#define _ALS_SetPlayerRaceCheckpoint
	#define SetPlayerRaceCheckpoint( CST_SetPlayerRaceCheckpoint(

	#if defined _ALS_DisablePlayerRaceCheckpoint
		#undef DisablePlayerRaceCheckpoint
	#endif
	#define _ALS_DisablePlayerRaceCheckpoint
	#define DisablePlayerRaceCheckpoint( CST_DisablePlayerRaceCheckpoint(

	#if defined _ALS_SetPlayerWorldBounds
		#undef SetPlayerWorldBounds
	#endif
	#define _ALS_SetPlayerWorldBounds
	#define SetPlayerWorldBounds( CST_SetPlayerWorldBounds(

	#if defined _ALS_SetPlayerMarkerForPlayer
		#undef SetPlayerMarkerForPlayer
	#endif
	#define _ALS_SetPlayerMarkerForPlayer
	#define SetPlayerMarkerForPlayer( CST_SetPlayerMarkerForPlayer(

	#if defined _ALS_ShowPlayerNameTagForPlayer
		#undef ShowPlayerNameTagForPlayer
	#endif
	#define _ALS_ShowPlayerNameTagForPlayer
	#define ShowPlayerNameTagForPlayer( CST_ShowPlayerNameTagForPlayer(

	#if defined _ALS_SetPlayerMapIcon
		#undef SetPlayerMapIcon
	#endif
	#define _ALS_SetPlayerMapIcon
	#define SetPlayerMapIcon( CST_SetPlayerMapIcon(

	#if defined _ALS_RemovePlayerMapIcon
		#undef RemovePlayerMapIcon
	#endif
	#define _ALS_RemovePlayerMapIcon
	#define RemovePlayerMapIcon( CST_RemovePlayerMapIcon(

	#if defined _ALS_AllowPlayerTeleport
		#undef AllowPlayerTeleport
	#endif
	#define _ALS_AllowPlayerTeleport
	#define AllowPlayerTeleport( CST_AllowPlayerTeleport(

	#if defined _ALS_SetPlayerCameraPos
		#undef SetPlayerCameraPos
	#endif
	#define _ALS_SetPlayerCameraPos
	#define SetPlayerCameraPos( CST_SetPlayerCameraPos(

	#if defined _ALS_SetPlayerCameraLookAt
		#undef SetPlayerCameraLookAt
	#endif
	#define _ALS_SetPlayerCameraLookAt
	#define SetPlayerCameraLookAt( CST_SetPlayerCameraLookAt(

	#if defined _ALS_SetCameraBehindPlayer
		#undef SetCameraBehindPlayer
	#endif
	#define _ALS_SetCameraBehindPlayer
	#define SetCameraBehindPlayer( CST_SetCameraBehindPlayer(

	#if defined _ALS_GetPlayerCameraPos
		#undef GetPlayerCameraPos
	#endif
	#define _ALS_GetPlayerCameraPos
	#define GetPlayerCameraPos( CST_GetPlayerCameraPos(

	#if defined _ALS_GetPlayerCameraFrontVector
		#undef GetPlayerCameraFrontVector
	#endif
	#define _ALS_GetPlayerCameraFrontVector
	#define GetPlayerCameraFrontVector( CST_GetPlayerCameraFrontVector(

	#if defined _ALS_GetPlayerCameraMode
		#undef GetPlayerCameraMode
	#endif
	#define _ALS_GetPlayerCameraMode
	#define GetPlayerCameraMode( CST_GetPlayerCameraMode(

	#if defined _ALS_EnablePlayerCameraTarget
		#undef EnablePlayerCameraTarget
	#endif
	#define _ALS_EnablePlayerCameraTarget
	#define EnablePlayerCameraTarget( CST_EnablePlayerCameraTarget(

	#if defined _ALS_GetPlayerCameraTargetObject
		#undef GetPlayerCameraTargetObject
	#endif
	#define _ALS_GetPlayerCameraTargetObject
	#define GetPlayerCameraTargetObject( CST_GetPlayerCameraTargetObject(

	#if defined _ALS_GetPlayerCameraTargetVehicle
		#undef GetPlayerCameraTargetVehicle
	#endif
	#define _ALS_GetPlayerCameraTargetVehicle
	#define GetPlayerCameraTargetVehicle( CST_GetPlayerCameraTargetVehicle(

	#if defined _ALS_GetPlayerCameraTargetPlayer
		#undef GetPlayerCameraTargetPlayer
	#endif
	#define _ALS_GetPlayerCameraTargetPlayer
	#define GetPlayerCameraTargetPlayer( CST_GetPlayerCameraTargetPlayer(

	#if defined _ALS_GetPlayerCameraTargetActor
		#undef GetPlayerCameraTargetActor
	#endif
	#define _ALS_GetPlayerCameraTargetActor
	#define GetPlayerCameraTargetActor( CST_GetPlayerCameraTargetActor(

	#if defined _ALS_GetPlayerCameraAspectRatio
		#undef GetPlayerCameraAspectRatio
	#endif
	#define _ALS_GetPlayerCameraAspectRatio
	#define GetPlayerCameraAspectRatio( CST_GetPlayerCameraAspectRatio(

	#if defined _ALS_GetPlayerCameraZoom
		#undef GetPlayerCameraZoom
	#endif
	#define _ALS_GetPlayerCameraZoom
	#define GetPlayerCameraZoom( CST_GetPlayerCameraZoom(

	#if defined _ALS_AttachCameraToObject
		#undef AttachCameraToObject
	#endif
	#define _ALS_AttachCameraToObject
	#define AttachCameraToObject( CST_AttachCameraToObject(

	#if defined _ALS_AttachCameraToPlayerObject
		#undef AttachCameraToPlayerObject
	#endif
	#define _ALS_AttachCameraToPlayerObject
	#define AttachCameraToPlayerObject( CST_AttachCameraToPlayerObject(

	#if defined _ALS_InterpolateCameraPos
		#undef InterpolateCameraPos
	#endif
	#define _ALS_InterpolateCameraPos
	#define InterpolateCameraPos( CST_InterpolateCameraPos(

	#if defined _ALS_InterpolateCameraLookAt
		#undef InterpolateCameraLookAt
	#endif
	#define _ALS_InterpolateCameraLookAt
	#define InterpolateCameraLookAt( CST_InterpolateCameraLookAt(

	#if defined _ALS_IsPlayerConnected
		#undef IsPlayerConnected
	#endif
	#define _ALS_IsPlayerConnected
	#define IsPlayerConnected( CST_IsPlayerConnected(

	#if defined _ALS_IsPlayerInVehicle
		#undef IsPlayerInVehicle
	#endif
	#define _ALS_IsPlayerInVehicle
	#define IsPlayerInVehicle( CST_IsPlayerInVehicle(

	#if defined _ALS_IsPlayerInAnyVehicle
		#undef IsPlayerInAnyVehicle
	#endif
	#define _ALS_IsPlayerInAnyVehicle
	#define IsPlayerInAnyVehicle( CST_IsPlayerInAnyVehicle(

	#if defined _ALS_IsPlayerInCheckpoint
		#undef IsPlayerInCheckpoint
	#endif
	#define _ALS_IsPlayerInCheckpoint
	#define IsPlayerInCheckpoint( CST_IsPlayerInCheckpoint(

	#if defined _ALS_IsPlayerInRaceCheckpoint
		#undef IsPlayerInRaceCheckpoint
	#endif
	#define _ALS_IsPlayerInRaceCheckpoint
	#define IsPlayerInRaceCheckpoint( CST_IsPlayerInRaceCheckpoint(

	#if defined _ALS_SetPlayerVirtualWorld
		#undef SetPlayerVirtualWorld
	#endif
	#define _ALS_SetPlayerVirtualWorld
	#define SetPlayerVirtualWorld( CST_SetPlayerVirtualWorld(

	#if defined _ALS_GetPlayerVirtualWorld
		#undef GetPlayerVirtualWorld
	#endif
	#define _ALS_GetPlayerVirtualWorld
	#define GetPlayerVirtualWorld( CST_GetPlayerVirtualWorld(

	#if defined _ALS_EnableStuntBonusForPlayer
		#undef EnableStuntBonusForPlayer
	#endif
	#define _ALS_EnableStuntBonusForPlayer
	#define EnableStuntBonusForPlayer( CST_EnableStuntBonusForPlayer(

	#if defined _ALS_EnableStuntBonusForAll
		#undef EnableStuntBonusForAll
	#endif
	#define _ALS_EnableStuntBonusForAll
	#define EnableStuntBonusForAll( CST_EnableStuntBonusForAll(

	#if defined _ALS_TogglePlayerSpectating
		#undef TogglePlayerSpectating
	#endif
	#define _ALS_TogglePlayerSpectating
	#define TogglePlayerSpectating( CST_TogglePlayerSpectating(

	#if defined _ALS_PlayerSpectatePlayer
		#undef PlayerSpectatePlayer
	#endif
	#define _ALS_PlayerSpectatePlayer
	#define PlayerSpectatePlayer( CST_PlayerSpectatePlayer(

	#if defined _ALS_PlayerSpectateVehicle
		#undef PlayerSpectateVehicle
	#endif
	#define _ALS_PlayerSpectateVehicle
	#define PlayerSpectateVehicle( CST_PlayerSpectateVehicle(

	#if defined _ALS_StartRecordingPlayerData
		#undef StartRecordingPlayerData
	#endif
	#define _ALS_StartRecordingPlayerData
	#define StartRecordingPlayerData( CST_StartRecordingPlayerData(

	#if defined _ALS_StopRecordingPlayerData
		#undef StopRecordingPlayerData
	#endif
	#define _ALS_StopRecordingPlayerData
	#define StopRecordingPlayerData( CST_StopRecordingPlayerData(

	#if defined _ALS_SelectTextDraw
		#undef SelectTextDraw
	#endif
	#define _ALS_SelectTextDraw
	#define SelectTextDraw( CST_SelectTextDraw(

	#if defined _ALS_CancelSelectTextDraw
		#undef CancelSelectTextDraw
	#endif
	#define _ALS_CancelSelectTextDraw
	#define CancelSelectTextDraw( CST_CancelSelectTextDraw(

	#if defined _ALS_CreateExplosionForPlayer
		#undef CreateExplosionForPlayer
	#endif
	#define _ALS_CreateExplosionForPlayer
	#define CreateExplosionForPlayer( CST_CreateExplosionForPlayer(

	#if defined _ALS_SendClientCheck
		#undef SendClientCheck
	#endif
	#define _ALS_SendClientCheck
	#define SendClientCheck( CST_SendClientCheck(
#endif

/*

	 ¦¦¦¦¦          ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦      ¦¦   ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦
	¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦
	¦¦   ¦¦              ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦ ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦      ¦¦ ¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_print
		#undef print
	#endif
	#define _ALS_print
	#define print( CST_print(

	#if defined _ALS_printf
		#undef printf
	#endif
	#define _ALS_printf
	#define printf( CST_printf(

	#if defined _ALS_format
		#undef format
	#endif
	#define _ALS_format
	#define format( CST_format(

	#if defined _ALS_Print
		#undef Print
	#endif
	#define _ALS_Print
	#define Print( CST_Print(

	#if defined _ALS_PrintF
		#undef PrintF
	#endif
	#define _ALS_PrintF
	#define PrintF( CST_PrintF(

	#if defined _ALS_Format
		#undef Format
	#endif
	#define _ALS_Format
	#define Format( CST_Format(

	#if defined _ALS_SendClientMessage
		#undef SendClientMessage
	#endif
	#define _ALS_SendClientMessage
	#define SendClientMessage( CST_SendClientMessage(

	#if defined _ALS_SendClientMessageToAll
		#undef SendClientMessageToAll
	#endif
	#define _ALS_SendClientMessageToAll
	#define SendClientMessageToAll( CST_SendClientMessageToAll(

	#if defined _ALS_SendPlayerMessageToPlayer
		#undef SendPlayerMessageToPlayer
	#endif
	#define _ALS_SendPlayerMessageToPlayer
	#define SendPlayerMessageToPlayer( CST_SendPlayerMessageToPlayer(

	#if defined _ALS_SendPlayerMessageToAll
		#undef SendPlayerMessageToAll
	#endif
	#define _ALS_SendPlayerMessageToAll
	#define SendPlayerMessageToAll( CST_SendPlayerMessageToAll(

	#if defined _ALS_SendDeathMessage
		#undef SendDeathMessage
	#endif
	#define _ALS_SendDeathMessage
	#define SendDeathMessage( CST_SendDeathMessage(

	#if defined _ALS_SendDeathMessageToPlayer
		#undef SendDeathMessageToPlayer
	#endif
	#define _ALS_SendDeathMessageToPlayer
	#define SendDeathMessageToPlayer( CST_SendDeathMessageToPlayer(

	#if defined _ALS_GameTextForAll
		#undef GameTextForAll
	#endif
	#define _ALS_GameTextForAll
	#define GameTextForAll( CST_GameTextForAll(

	#if defined _ALS_GameTextForPlayer
		#undef GameTextForPlayer
	#endif
	#define _ALS_GameTextForPlayer
	#define GameTextForPlayer( CST_GameTextForPlayer(

	#if defined _ALS_SetTimer
		#undef SetTimer
	#endif
	#define _ALS_SetTimer
	#define SetTimer( CST_SetTimer(

	#if defined _ALS_SetTimerEx
		#undef SetTimerEx
	#endif
	#define _ALS_SetTimerEx
	#define SetTimerEx( CST_SetTimerEx(

	#if defined _ALS_KillTimer
		#undef KillTimer
	#endif
	#define _ALS_KillTimer
	#define KillTimer( CST_KillTimer(

	#if defined _ALS_GetTickCount
		#undef GetTickCount
	#endif
	#define _ALS_GetTickCount
	#define GetTickCount( CST_GetTickCount(

	#if defined _ALS_GetMaxPlayers
		#undef GetMaxPlayers
	#endif
	#define _ALS_GetMaxPlayers
	#define GetMaxPlayers( CST_GetMaxPlayers(

	#if defined _ALS_CallRemoteFunction
		#undef CallRemoteFunction
	#endif
	#define _ALS_CallRemoteFunction
	#define CallRemoteFunction( CST_CallRemoteFunction(

	#if defined _ALS_CallLocalFunction
		#undef CallLocalFunction
	#endif
	#define _ALS_CallLocalFunction
	#define CallLocalFunction( CST_CallLocalFunction(

	#if defined _ALS_VectorSize
		#undef VectorSize
	#endif
	#define _ALS_VectorSize
	#define VectorSize( CST_VectorSize(

	#if defined _ALS_asin
		#undef asin
	#endif
	#define _ALS_asin
	#define asin( CST_asin(

	#if defined _ALS_acos
		#undef acos
	#endif
	#define _ALS_acos
	#define acos( CST_acos(

	#if defined _ALS_atan
		#undef atan
	#endif
	#define _ALS_atan
	#define atan( CST_atan(

	#if defined _ALS_atan2
		#undef atan2
	#endif
	#define _ALS_atan2
	#define atan2( CST_atan2(

	#if defined _ALS_ASin
		#undef ASin
	#endif
	#define _ALS_ASin
	#define ASin( CST_ASin(

	#if defined _ALS_ACos
		#undef ACos
	#endif
	#define _ALS_ACos
	#define ACos( CST_ACos(

	#if defined _ALS_ATan
		#undef ATan
	#endif
	#define _ALS_ATan
	#define ATan( CST_ATan(

	#if defined _ALS_ATan2
		#undef ATan2
	#endif
	#define _ALS_ATan2
	#define ATan2( CST_ATan2(

	#if defined _ALS_GetPlayerPoolSize
		#undef GetPlayerPoolSize
	#endif
	#define _ALS_GetPlayerPoolSize
	#define GetPlayerPoolSize( CST_GetPlayerPoolSize(

	#if defined _ALS_GetVehiclePoolSize
		#undef GetVehiclePoolSize
	#endif
	#define _ALS_GetVehiclePoolSize
	#define GetVehiclePoolSize( CST_GetVehiclePoolSize(

	#if defined _ALS_GetActorPoolSize
		#undef GetActorPoolSize
	#endif
	#define _ALS_GetActorPoolSize
	#define GetActorPoolSize( CST_GetActorPoolSize(

	#if defined _ALS_SHA256_PassHash
		#undef SHA256_PassHash
	#endif
	#define _ALS_SHA256_PassHash
	#define SHA256_PassHash( CST_SHA256_PassHash(

	#if defined _ALS_SetSVarInt
		#undef SetSVarInt
	#endif
	#define _ALS_SetSVarInt
	#define SetSVarInt( CST_SetSVarInt(

	#if defined _ALS_GetSVarInt
		#undef GetSVarInt
	#endif
	#define _ALS_GetSVarInt
	#define GetSVarInt( CST_GetSVarInt(

	#if defined _ALS_SetSVarString
		#undef SetSVarString
	#endif
	#define _ALS_SetSVarString
	#define SetSVarString( CST_SetSVarString(

	#if defined _ALS_GetSVarString
		#undef GetSVarString
	#endif
	#define _ALS_GetSVarString
	#define GetSVarString( CST_GetSVarString(

	#if defined _ALS_SetSVarFloat
		#undef SetSVarFloat
	#endif
	#define _ALS_SetSVarFloat
	#define SetSVarFloat( CST_SetSVarFloat(

	#if defined _ALS_GetSVarFloat
		#undef GetSVarFloat
	#endif
	#define _ALS_GetSVarFloat
	#define GetSVarFloat( CST_GetSVarFloat(

	#if defined _ALS_DeleteSVar
		#undef DeleteSVar
	#endif
	#define _ALS_DeleteSVar
	#define DeleteSVar( CST_DeleteSVar(

	#if defined _ALS_GetSVarsUpperIndex
		#undef GetSVarsUpperIndex
	#endif
	#define _ALS_GetSVarsUpperIndex
	#define GetSVarsUpperIndex( CST_GetSVarsUpperIndex(

	#if defined _ALS_GetSVarNameAtIndex
		#undef GetSVarNameAtIndex
	#endif
	#define _ALS_GetSVarNameAtIndex
	#define GetSVarNameAtIndex( CST_GetSVarNameAtIndex(

	#if defined _ALS_GetSVarType
		#undef GetSVarType
	#endif
	#define _ALS_GetSVarType
	#define GetSVarType( CST_GetSVarType(

	#if defined _ALS_SetGameModeText
		#undef SetGameModeText
	#endif
	#define _ALS_SetGameModeText
	#define SetGameModeText( CST_SetGameModeText(

	#if defined _ALS_SetTeamCount
		#undef SetTeamCount
	#endif
	#define _ALS_SetTeamCount
	#define SetTeamCount( CST_SetTeamCount(

	#if defined _ALS_AddPlayerClass
		#undef AddPlayerClass
	#endif
	#define _ALS_AddPlayerClass
	#define AddPlayerClass( CST_AddPlayerClass(

	#if defined _ALS_AddPlayerClassEx
		#undef AddPlayerClassEx
	#endif
	#define _ALS_AddPlayerClassEx
	#define AddPlayerClassEx( CST_AddPlayerClassEx(

	#if defined _ALS_AddStaticVehicle
		#undef AddStaticVehicle
	#endif
	#define _ALS_AddStaticVehicle
	#define AddStaticVehicle( CST_AddStaticVehicle(

	#if defined _ALS_AddStaticVehicleEx
		#undef AddStaticVehicleEx
	#endif
	#define _ALS_AddStaticVehicleEx
	#define AddStaticVehicleEx( CST_AddStaticVehicleEx(

	#if defined _ALS_AddStaticPickup
		#undef AddStaticPickup
	#endif
	#define _ALS_AddStaticPickup
	#define AddStaticPickup( CST_AddStaticPickup(

	#if defined _ALS_CreatePickup
		#undef CreatePickup
	#endif
	#define _ALS_CreatePickup
	#define CreatePickup( CST_CreatePickup(

	#if defined _ALS_DestroyPickup
		#undef DestroyPickup
	#endif
	#define _ALS_DestroyPickup
	#define DestroyPickup( CST_DestroyPickup(

	#if defined _ALS_ShowNameTags
		#undef ShowNameTags
	#endif
	#define _ALS_ShowNameTags
	#define ShowNameTags( CST_ShowNameTags(

	#if defined _ALS_ShowPlayerMarkers
		#undef ShowPlayerMarkers
	#endif
	#define _ALS_ShowPlayerMarkers
	#define ShowPlayerMarkers( CST_ShowPlayerMarkers(

	#if defined _ALS_GameModeExit
		#undef GameModeExit
	#endif
	#define _ALS_GameModeExit
	#define GameModeExit( CST_GameModeExit(

	#if defined _ALS_SetWorldTime
		#undef SetWorldTime
	#endif
	#define _ALS_SetWorldTime
	#define SetWorldTime( CST_SetWorldTime(

	#if defined _ALS_GetWeaponName
		#undef GetWeaponName
	#endif
	#define _ALS_GetWeaponName
	#define GetWeaponName( CST_GetWeaponName(

	#if defined _ALS_EnableTirePopping
		#undef EnableTirePopping
	#endif
	#define _ALS_EnableTirePopping
	#define EnableTirePopping( CST_EnableTirePopping(

	#if defined _ALS_EnableVehicleFriendlyFire
		#undef EnableVehicleFriendlyFire
	#endif
	#define _ALS_EnableVehicleFriendlyFire
	#define EnableVehicleFriendlyFire( CST_EnableVehicleFriendlyFire(

	#if defined _ALS_AllowInteriorWeapons
		#undef AllowInteriorWeapons
	#endif
	#define _ALS_AllowInteriorWeapons
	#define AllowInteriorWeapons( CST_AllowInteriorWeapons(

	#if defined _ALS_SetWeather
		#undef SetWeather
	#endif
	#define _ALS_SetWeather
	#define SetWeather( CST_SetWeather(

	#if defined _ALS_GetGravity
		#undef GetGravity
	#endif
	#define _ALS_GetGravity
	#define GetGravity( CST_GetGravity(

	#if defined _ALS_SetGravity
		#undef SetGravity
	#endif
	#define _ALS_SetGravity
	#define SetGravity( CST_SetGravity(

	#if defined _ALS_AllowAdminTeleport
		#undef AllowAdminTeleport
	#endif
	#define _ALS_AllowAdminTeleport
	#define AllowAdminTeleport( CST_AllowAdminTeleport(

	#if defined _ALS_SetDeathDropAmount
		#undef SetDeathDropAmount
	#endif
	#define _ALS_SetDeathDropAmount
	#define SetDeathDropAmount( CST_SetDeathDropAmount(

	#if defined _ALS_CreateExplosion
		#undef CreateExplosion
	#endif
	#define _ALS_CreateExplosion
	#define CreateExplosion( CST_CreateExplosion(

	#if defined _ALS_EnableZoneNames
		#undef EnableZoneNames
	#endif
	#define _ALS_EnableZoneNames
	#define EnableZoneNames( CST_EnableZoneNames(

	#if defined _ALS_UsePlayerPedAnims
		#undef UsePlayerPedAnims
	#endif
	#define _ALS_UsePlayerPedAnims
	#define UsePlayerPedAnims( CST_UsePlayerPedAnims(

	#if defined _ALS_SetNameTagDrawDistance
		#undef SetNameTagDrawDistance
	#endif
	#define _ALS_SetNameTagDrawDistance
	#define SetNameTagDrawDistance( CST_SetNameTagDrawDistance(

	#if defined _ALS_DisableNameTagLOS
		#undef DisableNameTagLOS
	#endif
	#define _ALS_DisableNameTagLOS
	#define DisableNameTagLOS( CST_DisableNameTagLOS(

	#if defined _ALS_LimitGlobalChatRadius
		#undef LimitGlobalChatRadius
	#endif
	#define _ALS_LimitGlobalChatRadius
	#define LimitGlobalChatRadius( CST_LimitGlobalChatRadius(

	#if defined _ALS_LimitPlayerMarkerRadius
		#undef LimitPlayerMarkerRadius
	#endif
	#define _ALS_LimitPlayerMarkerRadius
	#define LimitPlayerMarkerRadius( CST_LimitPlayerMarkerRadius(

	#if defined _ALS_ConnectNPC
		#undef ConnectNPC
	#endif
	#define _ALS_ConnectNPC
	#define ConnectNPC( CST_ConnectNPC(

	#if defined _ALS_IsPlayerNPC
		#undef IsPlayerNPC
	#endif
	#define _ALS_IsPlayerNPC
	#define IsPlayerNPC( CST_IsPlayerNPC(

	#if defined _ALS_AddCharModel
		#undef AddCharModel
	#endif
	#define _ALS_AddCharModel
	#define AddCharModel( CST_AddCharModel(

	#if defined _ALS_AddSimpleModel
		#undef AddSimpleModel
	#endif
	#define _ALS_AddSimpleModel
	#define AddSimpleModel( CST_AddSimpleModel(

	#if defined _ALS_AddSimpleModelTimed
		#undef AddSimpleModelTimed
	#endif
	#define _ALS_AddSimpleModelTimed
	#define AddSimpleModelTimed( CST_AddSimpleModelTimed(

	#if defined _ALS_FindModelFileNameFromCRC
		#undef FindModelFileNameFromCRC
	#endif
	#define _ALS_FindModelFileNameFromCRC
	#define FindModelFileNameFromCRC( CST_FindModelFileNameFromCRC(

	#if defined _ALS_FindTextureFileNameFromCRC
		#undef FindTextureFileNameFromCRC
	#endif
	#define _ALS_FindTextureFileNameFromCRC
	#define FindTextureFileNameFromCRC( CST_FindTextureFileNameFromCRC(

	#if defined _ALS_RedirectDownload
		#undef RedirectDownload
	#endif
	#define _ALS_RedirectDownload
	#define RedirectDownload( CST_RedirectDownload(

	#if defined _ALS_IsPlayerAdmin
		#undef IsPlayerAdmin
	#endif
	#define _ALS_IsPlayerAdmin
	#define IsPlayerAdmin( CST_IsPlayerAdmin(

	#if defined _ALS_Kick
		#undef Kick
	#endif
	#define _ALS_Kick
	#define Kick( CST_Kick(

	#if defined _ALS_Ban
		#undef Ban
	#endif
	#define _ALS_Ban
	#define Ban( CST_Ban(

	#if defined _ALS_BanEx
		#undef BanEx
	#endif
	#define _ALS_BanEx
	#define BanEx( CST_BanEx(

	#if defined _ALS_SendRconCommand
		#undef SendRconCommand
	#endif
	#define _ALS_SendRconCommand
	#define SendRconCommand( CST_SendRconCommand(

	#if defined _ALS_GetPlayerNetworkStats
		#undef GetPlayerNetworkStats
	#endif
	#define _ALS_GetPlayerNetworkStats
	#define GetPlayerNetworkStats( CST_GetPlayerNetworkStats(

	#if defined _ALS_GetNetworkStats
		#undef GetNetworkStats
	#endif
	#define _ALS_GetNetworkStats
	#define GetNetworkStats( CST_GetNetworkStats(

	#if defined _ALS_GetPlayerVersion
		#undef GetPlayerVersion
	#endif
	#define _ALS_GetPlayerVersion
	#define GetPlayerVersion( CST_GetPlayerVersion(

	#if defined _ALS_BlockIpAddress
		#undef BlockIpAddress
	#endif
	#define _ALS_BlockIpAddress
	#define BlockIpAddress( CST_BlockIpAddress(

	#if defined _ALS_UnBlockIpAddress
		#undef UnBlockIpAddress
	#endif
	#define _ALS_UnBlockIpAddress
	#define UnBlockIpAddress( CST_UnBlockIpAddress(

	#if defined _ALS_GetServerVarAsString
		#undef GetServerVarAsString
	#endif
	#define _ALS_GetServerVarAsString
	#define GetServerVarAsString( CST_GetServerVarAsString(

	#if defined _ALS_GetServerVarAsInt
		#undef GetServerVarAsInt
	#endif
	#define _ALS_GetServerVarAsInt
	#define GetServerVarAsInt( CST_GetServerVarAsInt(

	#if defined _ALS_GetServerVarAsBool
		#undef GetServerVarAsBool
	#endif
	#define _ALS_GetServerVarAsBool
	#define GetServerVarAsBool( CST_GetServerVarAsBool(

	#if defined _ALS_GetConsoleVarAsString
		#undef GetConsoleVarAsString
	#endif
	#define _ALS_GetConsoleVarAsString
	#define GetConsoleVarAsString( CST_GetConsoleVarAsString(

	#if defined _ALS_GetConsoleVarAsInt
		#undef GetConsoleVarAsInt
	#endif
	#define _ALS_GetConsoleVarAsInt
	#define GetConsoleVarAsInt( CST_GetConsoleVarAsInt(

	#if defined _ALS_GetConsoleVarAsBool
		#undef GetConsoleVarAsBool
	#endif
	#define _ALS_GetConsoleVarAsBool
	#define GetConsoleVarAsBool( CST_GetConsoleVarAsBool(

	#if defined _ALS_GetServerTickRate
		#undef GetServerTickRate
	#endif
	#define _ALS_GetServerTickRate
	#define GetServerTickRate( CST_GetServerTickRate(

	#if defined _ALS_NetStats_GetConnectedTime
		#undef NetStats_GetConnectedTime
	#endif
	#define _ALS_NetStats_GetConnectedTime
	#define NetStats_GetConnectedTime( CST_NetStats_GetConnectedTime(

	#if defined _ALS_NetStats_MessagesReceived
		#undef NetStats_MessagesReceived
	#endif
	#define _ALS_NetStats_MessagesReceived
	#define NetStats_MessagesReceived( CST_NetStats_MessagesReceived(

	#if defined _ALS_NetStats_BytesReceived
		#undef NetStats_BytesReceived
	#endif
	#define _ALS_NetStats_BytesReceived
	#define NetStats_BytesReceived( CST_NetStats_BytesReceived(

	#if defined _ALS_NetStats_MessagesSent
		#undef NetStats_MessagesSent
	#endif
	#define _ALS_NetStats_MessagesSent
	#define NetStats_MessagesSent( CST_NetStats_MessagesSent(

	#if defined _ALS_NetStats_BytesSent
		#undef NetStats_BytesSent
	#endif
	#define _ALS_NetStats_BytesSent
	#define NetStats_BytesSent( CST_NetStats_BytesSent(

	#if defined _ALS_NetStats_MessagesRecvPerSecond
		#undef NetStats_MessagesRecvPerSecond
	#endif
	#define _ALS_NetStats_MessagesRecvPerSecond
	#define NetStats_MessagesRecvPerSecond( CST_NetStats_MessagesRecvPerSecond(

	#if defined _ALS_NetStats_PacketLossPercent
		#undef NetStats_PacketLossPercent
	#endif
	#define _ALS_NetStats_PacketLossPercent
	#define NetStats_PacketLossPercent( CST_NetStats_PacketLossPercent(

	#if defined _ALS_NetStats_ConnectionStatus
		#undef NetStats_ConnectionStatus
	#endif
	#define _ALS_NetStats_ConnectionStatus
	#define NetStats_ConnectionStatus( CST_NetStats_ConnectionStatus(

	#if defined _ALS_NetStats_GetIpPort
		#undef NetStats_GetIpPort
	#endif
	#define _ALS_NetStats_GetIpPort
	#define NetStats_GetIpPort( CST_NetStats_GetIpPort(

	#if defined _ALS_CreateMenu
		#undef CreateMenu
	#endif
	#define _ALS_CreateMenu
	#define CreateMenu( CST_CreateMenu(

	#if defined _ALS_DestroyMenu
		#undef DestroyMenu
	#endif
	#define _ALS_DestroyMenu
	#define DestroyMenu( CST_DestroyMenu(

	#if defined _ALS_AddMenuItem
		#undef AddMenuItem
	#endif
	#define _ALS_AddMenuItem
	#define AddMenuItem( CST_AddMenuItem(

	#if defined _ALS_SetMenuColumnHeader
		#undef SetMenuColumnHeader
	#endif
	#define _ALS_SetMenuColumnHeader
	#define SetMenuColumnHeader( CST_SetMenuColumnHeader(

	#if defined _ALS_ShowMenuForPlayer
		#undef ShowMenuForPlayer
	#endif
	#define _ALS_ShowMenuForPlayer
	#define ShowMenuForPlayer( CST_ShowMenuForPlayer(

	#if defined _ALS_HideMenuForPlayer
		#undef HideMenuForPlayer
	#endif
	#define _ALS_HideMenuForPlayer
	#define HideMenuForPlayer( CST_HideMenuForPlayer(

	#if defined _ALS_IsValidMenu
		#undef IsValidMenu
	#endif
	#define _ALS_IsValidMenu
	#define IsValidMenu( CST_IsValidMenu(

	#if defined _ALS_DisableMenu
		#undef DisableMenu
	#endif
	#define _ALS_DisableMenu
	#define DisableMenu( CST_DisableMenu(

	#if defined _ALS_DisableMenuRow
		#undef DisableMenuRow
	#endif
	#define _ALS_DisableMenuRow
	#define DisableMenuRow( CST_DisableMenuRow(

	#if defined _ALS_GetPlayerMenu
		#undef GetPlayerMenu
	#endif
	#define _ALS_GetPlayerMenu
	#define GetPlayerMenu( CST_GetPlayerMenu(

	#if defined _ALS_TextDrawCreate
		#undef TextDrawCreate
	#endif
	#define _ALS_TextDrawCreate
	#define TextDrawCreate( CST_TextDrawCreate(

	#if defined _ALS_TextDrawDestroy
		#undef TextDrawDestroy
	#endif
	#define _ALS_TextDrawDestroy
	#define TextDrawDestroy( CST_TextDrawDestroy(

	#if defined _ALS_TextDrawLetterSize
		#undef TextDrawLetterSize
	#endif
	#define _ALS_TextDrawLetterSize
	#define TextDrawLetterSize( CST_TextDrawLetterSize(

	#if defined _ALS_TextDrawTextSize
		#undef TextDrawTextSize
	#endif
	#define _ALS_TextDrawTextSize
	#define TextDrawTextSize( CST_TextDrawTextSize(

	#if defined _ALS_TextDrawAlignment
		#undef TextDrawAlignment
	#endif
	#define _ALS_TextDrawAlignment
	#define TextDrawAlignment( CST_TextDrawAlignment(

	#if defined _ALS_TextDrawColor
		#undef TextDrawColor
	#endif
	#define _ALS_TextDrawColor
	#define TextDrawColor( CST_TextDrawColor(

	#if defined _ALS_TextDrawUseBox
		#undef TextDrawUseBox
	#endif
	#define _ALS_TextDrawUseBox
	#define TextDrawUseBox( CST_TextDrawUseBox(

	#if defined _ALS_TextDrawBoxColor
		#undef TextDrawBoxColor
	#endif
	#define _ALS_TextDrawBoxColor
	#define TextDrawBoxColor( CST_TextDrawBoxColor(

	#if defined _ALS_TextDrawSetShadow
		#undef TextDrawSetShadow
	#endif
	#define _ALS_TextDrawSetShadow
	#define TextDrawSetShadow( CST_TextDrawSetShadow(

	#if defined _ALS_TextDrawSetOutline
		#undef TextDrawSetOutline
	#endif
	#define _ALS_TextDrawSetOutline
	#define TextDrawSetOutline( CST_TextDrawSetOutline(

	#if defined _ALS_TextDrawBackgroundColor
		#undef TextDrawBackgroundColor
	#endif
	#define _ALS_TextDrawBackgroundColor
	#define TextDrawBackgroundColor( CST_TextDrawBackgroundColor(

	#if defined _ALS_TextDrawFont
		#undef TextDrawFont
	#endif
	#define _ALS_TextDrawFont
	#define TextDrawFont( CST_TextDrawFont(

	#if defined _ALS_TextDrawSetProportional
		#undef TextDrawSetProportional
	#endif
	#define _ALS_TextDrawSetProportional
	#define TextDrawSetProportional( CST_TextDrawSetProportional(

	#if defined _ALS_TextDrawSetSelectable
		#undef TextDrawSetSelectable
	#endif
	#define _ALS_TextDrawSetSelectable
	#define TextDrawSetSelectable( CST_TextDrawSetSelectable(

	#if defined _ALS_TextDrawShowForPlayer
		#undef TextDrawShowForPlayer
	#endif
	#define _ALS_TextDrawShowForPlayer
	#define TextDrawShowForPlayer( CST_TextDrawShowForPlayer(

	#if defined _ALS_TextDrawHideForPlayer
		#undef TextDrawHideForPlayer
	#endif
	#define _ALS_TextDrawHideForPlayer
	#define TextDrawHideForPlayer( CST_TextDrawHideForPlayer(

	#if defined _ALS_TextDrawShowForAll
		#undef TextDrawShowForAll
	#endif
	#define _ALS_TextDrawShowForAll
	#define TextDrawShowForAll( CST_TextDrawShowForAll(

	#if defined _ALS_TextDrawHideForAll
		#undef TextDrawHideForAll
	#endif
	#define _ALS_TextDrawHideForAll
	#define TextDrawHideForAll( CST_TextDrawHideForAll(

	#if defined _ALS_TextDrawSetString
		#undef TextDrawSetString
	#endif
	#define _ALS_TextDrawSetString
	#define TextDrawSetString( CST_TextDrawSetString(

	#if defined _ALS_TextDrawSetPreviewModel
		#undef TextDrawSetPreviewModel
	#endif
	#define _ALS_TextDrawSetPreviewModel
	#define TextDrawSetPreviewModel( CST_TextDrawSetPreviewModel(

	#if defined _ALS_TextDrawSetPreviewRot
		#undef TextDrawSetPreviewRot
	#endif
	#define _ALS_TextDrawSetPreviewRot
	#define TextDrawSetPreviewRot( CST_TextDrawSetPreviewRot(

	#if defined _ALS_TextDrawSetPreviewVehCol
		#undef TextDrawSetPreviewVehCol
	#endif
	#define _ALS_TextDrawSetPreviewVehCol
	#define TextDrawSetPreviewVehCol( CST_TextDrawSetPreviewVehCol(

	#if defined _ALS_GangZoneCreate
		#undef GangZoneCreate
	#endif
	#define _ALS_GangZoneCreate
	#define GangZoneCreate( CST_GangZoneCreate(

	#if defined _ALS_GangZoneDestroy
		#undef GangZoneDestroy
	#endif
	#define _ALS_GangZoneDestroy
	#define GangZoneDestroy( CST_GangZoneDestroy(

	#if defined _ALS_GangZoneShowForPlayer
		#undef GangZoneShowForPlayer
	#endif
	#define _ALS_GangZoneShowForPlayer
	#define GangZoneShowForPlayer( CST_GangZoneShowForPlayer(

	#if defined _ALS_GangZoneShowForAll
		#undef GangZoneShowForAll
	#endif
	#define _ALS_GangZoneShowForAll
	#define GangZoneShowForAll( CST_GangZoneShowForAll(

	#if defined _ALS_GangZoneHideForPlayer
		#undef GangZoneHideForPlayer
	#endif
	#define _ALS_GangZoneHideForPlayer
	#define GangZoneHideForPlayer( CST_GangZoneHideForPlayer(

	#if defined _ALS_GangZoneHideForAll
		#undef GangZoneHideForAll
	#endif
	#define _ALS_GangZoneHideForAll
	#define GangZoneHideForAll( CST_GangZoneHideForAll(

	#if defined _ALS_GangZoneFlashForPlayer
		#undef GangZoneFlashForPlayer
	#endif
	#define _ALS_GangZoneFlashForPlayer
	#define GangZoneFlashForPlayer( CST_GangZoneFlashForPlayer(

	#if defined _ALS_GangZoneFlashForAll
		#undef GangZoneFlashForAll
	#endif
	#define _ALS_GangZoneFlashForAll
	#define GangZoneFlashForAll( CST_GangZoneFlashForAll(

	#if defined _ALS_GangZoneStopFlashForPlayer
		#undef GangZoneStopFlashForPlayer
	#endif
	#define _ALS_GangZoneStopFlashForPlayer
	#define GangZoneStopFlashForPlayer( CST_GangZoneStopFlashForPlayer(

	#if defined _ALS_GangZoneStopFlashForAll
		#undef GangZoneStopFlashForAll
	#endif
	#define _ALS_GangZoneStopFlashForAll
	#define GangZoneStopFlashForAll( CST_GangZoneStopFlashForAll(

	#if defined _ALS_Create3DTextLabel
		#undef Create3DTextLabel
	#endif
	#define _ALS_Create3DTextLabel
	#define Create3DTextLabel( CST_Create3DTextLabel(

	#if defined _ALS_Delete3DTextLabel
		#undef Delete3DTextLabel
	#endif
	#define _ALS_Delete3DTextLabel
	#define Delete3DTextLabel( CST_Delete3DTextLabel(

	#if defined _ALS_Attach3DTextLabelToPlayer
		#undef Attach3DTextLabelToPlayer
	#endif
	#define _ALS_Attach3DTextLabelToPlayer
	#define Attach3DTextLabelToPlayer( CST_Attach3DTextLabelToPlayer(

	#if defined _ALS_Attach3DTextLabelToVehicle
		#undef Attach3DTextLabelToVehicle
	#endif
	#define _ALS_Attach3DTextLabelToVehicle
	#define Attach3DTextLabelToVehicle( CST_Attach3DTextLabelToVehicle(

	#if defined _ALS_Update3DTextLabelText
		#undef Update3DTextLabelText
	#endif
	#define _ALS_Update3DTextLabelText
	#define Update3DTextLabelText( CST_Update3DTextLabelText(

	#if defined _ALS_CreatePlayer3DTextLabel
		#undef CreatePlayer3DTextLabel
	#endif
	#define _ALS_CreatePlayer3DTextLabel
	#define CreatePlayer3DTextLabel( CST_CreatePlayer3DTextLabel(

	#if defined _ALS_DeletePlayer3DTextLabel
		#undef DeletePlayer3DTextLabel
	#endif
	#define _ALS_DeletePlayer3DTextLabel
	#define DeletePlayer3DTextLabel( CST_DeletePlayer3DTextLabel(

	#if defined _ALS_UpdatePlayer3DTextLabelText
		#undef UpdatePlayer3DTextLabelText
	#endif
	#define _ALS_UpdatePlayer3DTextLabelText
	#define UpdatePlayer3DTextLabelText( CST_UpdatePlayer3DTextLabelText(

	#if defined _ALS_ShowPlayerDialog
		#undef ShowPlayerDialog
	#endif
	#define _ALS_ShowPlayerDialog
	#define ShowPlayerDialog( CST_ShowPlayerDialog(

	#if defined _ALS_gpci
		#undef gpci
	#endif
	#define _ALS_gpci
	#define gpci( CST_gpci(

	#if defined _ALS_GPCI
		#undef GPCI
	#endif
	#define _ALS_GPCI
	#define GPCI( CST_GPCI(
#endif

/*

	 ¦¦¦¦¦          ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦      ¦¦   ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦ ¦¦   ¦¦ ¦¦   ¦¦
	¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦¦¦¦¦
	¦¦   ¦¦              ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦ ¦¦      ¦¦   ¦¦ ¦¦   ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦      ¦¦ ¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_db_open
		#undef db_open
	#endif
	#define _ALS_db_open
	#define db_open( CST_db_open(

	#if defined _ALS_DB_Open
		#undef DB_Open
	#endif
	#define _ALS_DB_Open
	#define DB_Open( CST_DB_Open(

	#if defined _ALS_db_close
		#undef db_close
	#endif
	#define _ALS_db_close
	#define db_close( CST_db_close(

	#if defined _ALS_DB_Close
		#undef DB_Close
	#endif
	#define _ALS_DB_Close
	#define DB_Close( CST_DB_Close(

	#if defined _ALS_db_query
		#undef db_query
	#endif
	#define _ALS_db_query
	#define db_query( CST_db_query(

	#if defined _ALS_DB_Query
		#undef DB_Query
	#endif
	#define _ALS_DB_Query
	#define DB_Query( CST_DB_Query(

	#if defined _ALS_db_free_result
		#undef db_free_result
	#endif
	#define _ALS_db_free_result
	#define db_free_result( CST_db_free_result(

	#if defined _ALS_DB_FreeResult
		#undef DB_FreeResult
	#endif
	#define _ALS_DB_FreeResult
	#define DB_FreeResult( CST_DB_FreeResult(

	#if defined _ALS_db_num_rows
		#undef db_num_rows
	#endif
	#define _ALS_db_num_rows
	#define db_num_rows( CST_db_num_rows(

	#if defined _ALS_DB_NumRows
		#undef DB_NumRows
	#endif
	#define _ALS_DB_NumRows
	#define DB_NumRows( CST_DB_NumRows(

	#if defined _ALS_db_next_row
		#undef db_next_row
	#endif
	#define _ALS_db_next_row
	#define db_next_row( CST_db_next_row(

	#if defined _ALS_DB_NextRow
		#undef DB_NextRow
	#endif
	#define _ALS_DB_NextRow
	#define DB_NextRow( CST_DB_NextRow(

	#if defined _ALS_db_num_fields
		#undef db_num_fields
	#endif
	#define _ALS_db_num_fields
	#define db_num_fields( CST_db_num_fields(

	#if defined _ALS_DB_NumFields
		#undef DB_NumFields
	#endif
	#define _ALS_DB_NumFields
	#define DB_NumFields( CST_DB_NumFields(

	#if defined _ALS_db_field_name
		#undef db_field_name
	#endif
	#define _ALS_db_field_name
	#define db_field_name( CST_db_field_name(

	#if defined _ALS_DB_FieldName
		#undef DB_FieldName
	#endif
	#define _ALS_DB_FieldName
	#define DB_FieldName( CST_DB_FieldName(

	#if defined _ALS_db_get_field
		#undef db_get_field
	#endif
	#define _ALS_db_get_field
	#define db_get_field( CST_db_get_field(

	#if defined _ALS_DB_GetField
		#undef DB_GetField
	#endif
	#define _ALS_DB_GetField
	#define DB_GetField( CST_DB_GetField(

	#if defined _ALS_db_get_field_int
		#undef db_get_field_int
	#endif
	#define _ALS_db_get_field_int
	#define db_get_field_int( CST_db_get_field_int(

	#if defined _ALS_DB_GetFieldInt
		#undef DB_GetFieldInt
	#endif
	#define _ALS_DB_GetFieldInt
	#define DB_GetFieldInt( CST_DB_GetFieldInt(

	#if defined _ALS_db_get_field_float
		#undef db_get_field_float
	#endif
	#define _ALS_db_get_field_float
	#define db_get_field_float( CST_db_get_field_float(

	#if defined _ALS_DB_GetFieldFloat
		#undef DB_GetFieldFloat
	#endif
	#define _ALS_DB_GetFieldFloat
	#define DB_GetFieldFloat( CST_DB_GetFieldFloat(

	#if defined _ALS_db_get_field_assoc
		#undef db_get_field_assoc
	#endif
	#define _ALS_db_get_field_assoc
	#define db_get_field_assoc( CST_db_get_field_assoc(

	#if defined _ALS_DB_GetFieldAssoc
		#undef DB_GetFieldAssoc
	#endif
	#define _ALS_DB_GetFieldAssoc
	#define DB_GetFieldAssoc( CST_DB_GetFieldAssoc(

	#if defined _ALS_db_get_field_assoc_int
		#undef db_get_field_assoc_int
	#endif
	#define _ALS_db_get_field_assoc_int
	#define db_get_field_assoc_int( CST_db_get_field_assoc_int(

	#if defined _ALS_DB_GetFieldAssocInt
		#undef DB_GetFieldAssocInt
	#endif
	#define _ALS_DB_GetFieldAssocInt
	#define DB_GetFieldAssocInt( CST_DB_GetFieldAssocInt(

	#if defined _ALS_db_get_field_assoc_float
		#undef db_get_field_assoc_float
	#endif
	#define _ALS_db_get_field_assoc_float
	#define db_get_field_assoc_float( CST_db_get_field_assoc_float(

	#if defined _ALS_DB_GetFieldAssocFloat
		#undef DB_GetFieldAssocFloat
	#endif
	#define _ALS_DB_GetFieldAssocFloat
	#define DB_GetFieldAssocFloat( CST_DB_GetFieldAssocFloat(

	#if defined _ALS_db_get_mem_handle
		#undef db_get_mem_handle
	#endif
	#define _ALS_db_get_mem_handle
	#define db_get_mem_handle( CST_db_get_mem_handle(

	#if defined _ALS_DB_GetMemHandle
		#undef DB_GetMemHandle
	#endif
	#define _ALS_DB_GetMemHandle
	#define DB_GetMemHandle( CST_DB_GetMemHandle(

	#if defined _ALS_db_get_result_mem_handle
		#undef db_get_result_mem_handle
	#endif
	#define _ALS_db_get_result_mem_handle
	#define db_get_result_mem_handle( CST_db_get_result_mem_handle(

	#if defined _ALS_DB_GetResultMemHandle
		#undef DB_GetResultMemHandle
	#endif
	#define _ALS_DB_GetResultMemHandle
	#define DB_GetResultMemHandle( CST_DB_GetResultMemHandle(

	#if defined _ALS_db_debug_openfiles
		#undef db_debug_openfiles
	#endif
	#define _ALS_db_debug_openfiles
	#define db_debug_openfiles( CST_db_debug_openfiles(

	#if defined _ALS_DB_DebugOpenFiles
		#undef DB_DebugOpenFiles
	#endif
	#define _ALS_DB_DebugOpenFiles
	#define DB_DebugOpenFiles( CST_DB_DebugOpenFiles(

	#if defined _ALS_db_debug_openresults
		#undef db_debug_openresults
	#endif
	#define _ALS_db_debug_openresults
	#define db_debug_openresults( CST_db_debug_openresults(

	#if defined _ALS_DB_DebugOpenResults
		#undef DB_DebugOpenResults
	#endif
	#define _ALS_DB_DebugOpenResults
	#define DB_DebugOpenResults( CST_DB_DebugOpenResults(
#endif

/*

	 ¦¦¦¦¦          ¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦  ¦¦¦¦¦¦ ¦¦      ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦
	¦¦   ¦¦         ¦¦    ¦¦ ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦      ¦¦      ¦¦
	¦¦¦¦¦¦¦         ¦¦    ¦¦ ¦¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦ ¦¦      ¦¦      ¦¦¦¦¦   ¦¦¦¦¦¦¦
	¦¦   ¦¦          ¦¦  ¦¦  ¦¦      ¦¦   ¦¦ ¦¦ ¦¦      ¦¦      ¦¦           ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦   ¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦  ¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦

*/

#if _FIXES_SAMP
	#if defined _ALS_CreateVehicle
		#undef CreateVehicle
	#endif
	#define _ALS_CreateVehicle
	#define CreateVehicle( CST_CreateVehicle(

	#if defined _ALS_DestroyVehicle
		#undef DestroyVehicle
	#endif
	#define _ALS_DestroyVehicle
	#define DestroyVehicle( CST_DestroyVehicle(

	#if defined _ALS_IsVehicleStreamedIn
		#undef IsVehicleStreamedIn
	#endif
	#define _ALS_IsVehicleStreamedIn
	#define IsVehicleStreamedIn( CST_IsVehicleStreamedIn(

	#if defined _ALS_GetVehiclePos
		#undef GetVehiclePos
	#endif
	#define _ALS_GetVehiclePos
	#define GetVehiclePos( CST_GetVehiclePos(

	#if defined _ALS_SetVehiclePos
		#undef SetVehiclePos
	#endif
	#define _ALS_SetVehiclePos
	#define SetVehiclePos( CST_SetVehiclePos(

	#if defined _ALS_GetVehicleZAngle
		#undef GetVehicleZAngle
	#endif
	#define _ALS_GetVehicleZAngle
	#define GetVehicleZAngle( CST_GetVehicleZAngle(

	#if defined _ALS_GetVehicleRotationQuat
		#undef GetVehicleRotationQuat
	#endif
	#define _ALS_GetVehicleRotationQuat
	#define GetVehicleRotationQuat( CST_GetVehicleRotationQuat(

	#if defined _ALS_GetVehicleDistanceFromPoint
		#undef GetVehicleDistanceFromPoint
	#endif
	#define _ALS_GetVehicleDistanceFromPoint
	#define GetVehicleDistanceFromPoint( CST_GetVehicleDistanceFromPoint(

	#if defined _ALS_SetVehicleZAngle
		#undef SetVehicleZAngle
	#endif
	#define _ALS_SetVehicleZAngle
	#define SetVehicleZAngle( CST_SetVehicleZAngle(

	#if defined _ALS_SetVehicleParamsForPlayer
		#undef SetVehicleParamsForPlayer
	#endif
	#define _ALS_SetVehicleParamsForPlayer
	#define SetVehicleParamsForPlayer( CST_SetVehicleParamsForPlayer(

	#if defined _ALS_ManualVehicleEngineAndLights
		#undef ManualVehicleEngineAndLights
	#endif
	#define _ALS_ManualVehicleEngineAndLights
	#define ManualVehicleEngineAndLights( CST_ManualVehicleEngineAndLights(

	#if defined _ALS_SetVehicleParamsEx
		#undef SetVehicleParamsEx
	#endif
	#define _ALS_SetVehicleParamsEx
	#define SetVehicleParamsEx( CST_SetVehicleParamsEx(

	#if defined _ALS_GetVehicleParamsEx
		#undef GetVehicleParamsEx
	#endif
	#define _ALS_GetVehicleParamsEx
	#define GetVehicleParamsEx( CST_GetVehicleParamsEx(

	#if defined _ALS_GetVehicleParamsSirenState
		#undef GetVehicleParamsSirenState
	#endif
	#define _ALS_GetVehicleParamsSirenState
	#define GetVehicleParamsSirenState( CST_GetVehicleParamsSirenState(

	#if defined _ALS_SetVehicleParamsCarDoors
		#undef SetVehicleParamsCarDoors
	#endif
	#define _ALS_SetVehicleParamsCarDoors
	#define SetVehicleParamsCarDoors( CST_SetVehicleParamsCarDoors(

	#if defined _ALS_GetVehicleParamsCarDoors
		#undef GetVehicleParamsCarDoors
	#endif
	#define _ALS_GetVehicleParamsCarDoors
	#define GetVehicleParamsCarDoors( CST_GetVehicleParamsCarDoors(

	#if defined _ALS_SetVehicleParamsCarWindows
		#undef SetVehicleParamsCarWindows
	#endif
	#define _ALS_SetVehicleParamsCarWindows
	#define SetVehicleParamsCarWindows( CST_SetVehicleParamsCarWindows(

	#if defined _ALS_GetVehicleParamsCarWindows
		#undef GetVehicleParamsCarWindows
	#endif
	#define _ALS_GetVehicleParamsCarWindows
	#define GetVehicleParamsCarWindows( CST_GetVehicleParamsCarWindows(

	#if defined _ALS_SetVehicleToRespawn
		#undef SetVehicleToRespawn
	#endif
	#define _ALS_SetVehicleToRespawn
	#define SetVehicleToRespawn( CST_SetVehicleToRespawn(

	#if defined _ALS_LinkVehicleToInterior
		#undef LinkVehicleToInterior
	#endif
	#define _ALS_LinkVehicleToInterior
	#define LinkVehicleToInterior( CST_LinkVehicleToInterior(

	#if defined _ALS_AddVehicleComponent
		#undef AddVehicleComponent
	#endif
	#define _ALS_AddVehicleComponent
	#define AddVehicleComponent( CST_AddVehicleComponent(

	#if defined _ALS_RemoveVehicleComponent
		#undef RemoveVehicleComponent
	#endif
	#define _ALS_RemoveVehicleComponent
	#define RemoveVehicleComponent( CST_RemoveVehicleComponent(

	#if defined _ALS_ChangeVehicleColor
		#undef ChangeVehicleColor
	#endif
	#define _ALS_ChangeVehicleColor
	#define ChangeVehicleColor( CST_ChangeVehicleColor(

	#if defined _ALS_ChangeVehiclePaintjob
		#undef ChangeVehiclePaintjob
	#endif
	#define _ALS_ChangeVehiclePaintjob
	#define ChangeVehiclePaintjob( CST_ChangeVehiclePaintjob(

	#if defined _ALS_SetVehicleHealth
		#undef SetVehicleHealth
	#endif
	#define _ALS_SetVehicleHealth
	#define SetVehicleHealth( CST_SetVehicleHealth(

	#if defined _ALS_GetVehicleHealth
		#undef GetVehicleHealth
	#endif
	#define _ALS_GetVehicleHealth
	#define GetVehicleHealth( CST_GetVehicleHealth(

	#if defined _ALS_AttachTrailerToVehicle
		#undef AttachTrailerToVehicle
	#endif
	#define _ALS_AttachTrailerToVehicle
	#define AttachTrailerToVehicle( CST_AttachTrailerToVehicle(

	#if defined _ALS_DetachTrailerFromVehicle
		#undef DetachTrailerFromVehicle
	#endif
	#define _ALS_DetachTrailerFromVehicle
	#define DetachTrailerFromVehicle( CST_DetachTrailerFromVehicle(

	#if defined _ALS_IsTrailerAttachedToVehicle
		#undef IsTrailerAttachedToVehicle
	#endif
	#define _ALS_IsTrailerAttachedToVehicle
	#define IsTrailerAttachedToVehicle( CST_IsTrailerAttachedToVehicle(

	#if defined _ALS_GetVehicleTrailer
		#undef GetVehicleTrailer
	#endif
	#define _ALS_GetVehicleTrailer
	#define GetVehicleTrailer( CST_GetVehicleTrailer(

	#if defined _ALS_SetVehicleNumberPlate
		#undef SetVehicleNumberPlate
	#endif
	#define _ALS_SetVehicleNumberPlate
	#define SetVehicleNumberPlate( CST_SetVehicleNumberPlate(

	#if defined _ALS_GetVehicleModel
		#undef GetVehicleModel
	#endif
	#define _ALS_GetVehicleModel
	#define GetVehicleModel( CST_GetVehicleModel(

	#if defined _ALS_GetVehicleComponentInSlot
		#undef GetVehicleComponentInSlot
	#endif
	#define _ALS_GetVehicleComponentInSlot
	#define GetVehicleComponentInSlot( CST_GetVehicleComponentInSlot(

	#if defined _ALS_GetVehicleComponentType
		#undef GetVehicleComponentType
	#endif
	#define _ALS_GetVehicleComponentType
	#define GetVehicleComponentType( CST_GetVehicleComponentType(

	#if defined _ALS_RepairVehicle
		#undef RepairVehicle
	#endif
	#define _ALS_RepairVehicle
	#define RepairVehicle( CST_RepairVehicle(

	#if defined _ALS_GetVehicleVelocity
		#undef GetVehicleVelocity
	#endif
	#define _ALS_GetVehicleVelocity
	#define GetVehicleVelocity( CST_GetVehicleVelocity(

	#if defined _ALS_SetVehicleVelocity
		#undef SetVehicleVelocity
	#endif
	#define _ALS_SetVehicleVelocity
	#define SetVehicleVelocity( CST_SetVehicleVelocity(

	#if defined _ALS_SetVehicleAngularVelocity
		#undef SetVehicleAngularVelocity
	#endif
	#define _ALS_SetVehicleAngularVelocity
	#define SetVehicleAngularVelocity( CST_SetVehicleAngularVelocity(

	#if defined _ALS_GetVehicleDamageStatus
		#undef GetVehicleDamageStatus
	#endif
	#define _ALS_GetVehicleDamageStatus
	#define GetVehicleDamageStatus( CST_GetVehicleDamageStatus(

	#if defined _ALS_UpdateVehicleDamageStatus
		#undef UpdateVehicleDamageStatus
	#endif
	#define _ALS_UpdateVehicleDamageStatus
	#define UpdateVehicleDamageStatus( CST_UpdateVehicleDamageStatus(

	#if defined _ALS_GetVehicleModelInfo
		#undef GetVehicleModelInfo
	#endif
	#define _ALS_GetVehicleModelInfo
	#define GetVehicleModelInfo( CST_GetVehicleModelInfo(

	#if defined _ALS_SetVehicleVirtualWorld
		#undef SetVehicleVirtualWorld
	#endif
	#define _ALS_SetVehicleVirtualWorld
	#define SetVehicleVirtualWorld( CST_SetVehicleVirtualWorld(

	#if defined _ALS_GetVehicleVirtualWorld
		#undef GetVehicleVirtualWorld
	#endif
	#define _ALS_GetVehicleVirtualWorld
	#define GetVehicleVirtualWorld( CST_GetVehicleVirtualWorld(

	#if defined _ALS_IsValidVehicle
		#undef IsValidVehicle
	#endif
	#define _ALS_IsValidVehicle
	#define IsValidVehicle( CST_IsValidVehicle(
#endif

