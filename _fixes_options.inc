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

#if !FIXES_ExplicitOptions
	// Warning about unused settings is disabled.  Do this check before the
	// `_inc__fixes_settings` check so that we utilise the old compiler's
	// in-built compiler guards to avoid including this file multiple times when
	// not needed.
	#endinput
#endif

#if defined _inc__fixes_options
	// Allow this file to be included multiple times.  This line is only hit on
	// the new compiler in compatibility mode.
	#undef _inc__fixes_options
#endif

#if defined _FIXES_OPTION
	// Hide the warning variable so there aren't two.
	#undef _FIXES_OPTION
	#define _FIXES_OPTION stock
#endif

#if !defined _FIXES_WARNING
	#error `_fixes_options.inc` included, but `_FIXES_WARNING` is not defined to select a warning message.
#endif

// The caller always undefines `_FIXES_WARNING` after trying to include this
// file, as it needs to be undefined whether the include worked or not.  Thus we
// can't also undefine it in here, as the sensible option would seem to be, as
// then it will be undefined twice in some situations.
//#if _FIXES_WARNING == 0
//	#warning The `FIX_ExplicitSettings` option must now be explicit.
//	#endinput
//#endif
//
//#if _FIXES_WARNING == 1
//	#warning The `FIX_EnableAll` option must now be explicit.
//	#endinput
//#endif

#error `_fixes_options.inc` included, but `_FIXES_WARNING` is not set to a valid warning message.

