#if !_FIXES_NEW_COMPILER
	// This is the old compiler.  We have to use `#endinput` to hide warnings.
	// This is why the warnings are in a separate (optional) file - just
	// enclosing them in `#if` doesn't work properly (with good reason, the
	// compiler needs to know when to end the `#if`, and if it sees a pre-
	// processor directive it doesn't know, it can't know if it should now end
	// the block or not).  So we have to ensure that the compiler never reaches
	// that line.
	//
	// I considered putting these warnings at the very bottom of the main file
	// and having it recursively include itself.  It would work (probably), but
	// would cause havok with pawndoc comments (which are already a mess) and
	// `#emit` (which also doesn't like being put in `#if`, as the whole file
	// would need to be to make this work).  Plus, having a 20,000+ line file
	// repeatedly include another 20,000+ line file for just five lines of code
	// is truly awful, and I suspect will bring the compiler to a crawl.
	//
	// Do this check before the `_inc__fixes_settings` check so that we utilise
	// the old compiler's in-built compiler guards to avoid including this file
	// multiple times when not needed.
	#endinput
#endif

#if !FIXES_ExplicitSettings
	// Warning about unused settings is disabled.  Do this check before the
	// `_inc__fixes_settings` check so that we utilise the old compiler's
	// in-built compiler guards to avoid including this file multiple times when
	// not needed.
	#endinput
#endif

#if defined _inc__fixes_settings
	// Allow this file to be included multiple times.  This line is only hit on
	// the new compiler in compatibility mode.
	#undef _inc__fixes_settings
#endif

#if defined _FIXES_SETTING
	// Hide the warning variable so there aren't two.
	#undef _FIXES_SETTING
	#define _FIXES_SETTING stock
#endif

#if !defined _FIXES_WARNING
	#error `_fixes_settings.inc` included, but `_FIXES_WARNING` is not defined to select a warning message.
#endif

// The caller always undefines `_FIXES_WARNING` after trying to include this
// file, as it needs to be undefined whether the include worked or not.  Thus we
// can't also undefine it in here, as the sensible option would seem to be, as
// then it will be undefined twice in some situations.
#if _FIXES_WARNING == 1
	#warning The `FIXES_ExplicitSettings` setting, to make all settings explicit, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 2
	#warning The `FIXES_EnableAll` setting, to enable all fixes, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 3
	#warning The `FIXES_EnableDeprecated` setting, to enable fixes for fixed bugs, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 4
	#warning The `FIXES_DefaultDisabled` setting, to disable all fixes by default, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 5
	#warning The `FIXES_ExplicitOptions` setting, to make all fixes explicit, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 6
	#warning The `FIXES_SilentKick` setting, to kick users without any message, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 7
	#warning The `FIXES_Debug` setting, to enable debug mode, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 8
	#warning The `FIXES_Single` setting, to enable single script mode, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 9
	#warning The `FIXES_NoSingleMsg` setting, to disable the single mode warning message, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 10
	#warning The `FIXES_NoServerVarMsg` setting, to disable the config access warning message, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 11
	#warning The `FIXES_NoGetMaxPlayersMsg` setting, to disable the `MAX_PLAYERS` warning message, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 12
	#warning The `FIXES_NoPawndoc` setting, to disable all fixes.inc pawndoc output, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 13
	#warning The `FIXES_CorrectInvalidTimerID` setting, to specify that you know invalid timers are `0`, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 14
	#warning The `FIXES_NoYSI` setting, to optimise the code when YSI isn't used, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 15
	#warning The `FIXES_OneRandomVehicleColour` setting, to allow only one random vehicle colour, must now be explicit.
	#endinput
#endif

#if _FIXES_WARNING == 16
	#warning The `FIXES_NoVehicleColourMsg` setting, to disable the vehicle colours warning, must now be explicit.
	#endinput
#endif

#error `_fixes_settings.inc` included, but `_FIXES_WARNING` is not set to a valid warning message.

