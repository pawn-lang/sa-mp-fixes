/*
            ========================================================
             fixes.inc - Community patch for buggy SA:MP functions.
            ========================================================
*/
/**
 * <!--
 * <transition target[^/]+/>
 * -->
*/
#if (__Pawn & 0x0F) >= 0x0A
const HIDE_THE_FIXES_COMMENT_1 = 1;
#endif
/**
 * <!--
 * :::::::: README ::::::::
 * 
 * To read the generated XML output, copy `pawndoc.xsl` to `pawno/xml/`.
 * 
 * This information goes very close to the top of the generated XML
 * documentation (because of include dependency orders), but doesn't appear in
 * the visual output.
 * -->
*/
/**
 * <!--
 * There is <a href="https://github.com/Zeex/pawn/issues/184">a bug</a> in the
 * old compiler related to outputting documentation on state transitions ().  So
 * after generation of the XML file, you should clean it up with the following
 * RegEx replacement:
 * 
 * Search: <transition target[^/]+/>
 * Replace: (nothing)
 * 
 * This works 99% of the time, though you may get one where the corrupted target
 * includes the character `/`, in which case you should manually delete them.
 * Note that YSI now includes manual documentation for transitions, but these
 * all include the parameter `keep="true"`, which exists simply to not match
 * that RegEx.  I also put the search at the top of this block so it is easier
 * to find in the output code.  This is fixed in the community compiler, but
 * thanks to <a href="https://github.com/pawn-lang/compiler/issues/674">a
 * different bug</a> tricks are needed to hide these comments.
 * -->
 */
#if (__Pawn & 0x0F) >= 0x0A
const HIDE_THE_FIXES_COMMENT_1 = 1;
#endif
/**
 * <library name="fixes.inc"
 *   description="Community patches for buggy SA:MP functions.">
 *
 * <section>
 *             Introduction
 * </section>
 *
 * <p>SA:MP is beta software written by a small team in their spare time, thus
 * it has bugs (as does all software).  Some of these have been known for a long
 * time but are low priority due to their minor effects, others go undiscovered
 * for a long time.  Many of these bugs have solutions which can be implemented
 * in PAWN (and this may be simpler than implementing them in the SA:MP source
 * code).  This include aims to collect fixes for as many of these bugs as
 * possible from the community (i.e. anyone who has a fix) together in to one
 * easy to use place for everyone's benefit.</p>
 *
 * <section>
 *             Use
 * </section>
 *
 * <p>To use this, simply include it after the default SA:MP functions, but
 * before third party includes:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     // Any default re-definitions should go here.                            <br />
 *     //#undef MAX_PLAYERS                                                     <br />
 *     //#define MAX_PLAYERS 10                                                 <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <p>To disable any fix for whatever reason simply do:</p>
 *
 * <code>#define FIX_&lt;name&gt; 0</code>
 *
 * <p>For example, to disable all the file.inc fixes if you always correctly
 * check the file handle, do:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     #define FIX_file_inc 0                                                   <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <p>All the names of the fixes are single words, and are all listed with their
 * fix descriptions below.</p>
 *
 * <p>If you only have one script running on your server (i.e. no
 * FilterScripts), you can use this define to improve the fixes.inc code:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     #define FIXES_Single 1                                                   <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <section>
 *             Fixes
 * </section>
 *
 * <fixeslist>
 * <fix name="GetPlayerColor">
 *     <problem>
 *         Returns "0" if "SetPlayerColor" has never been called.
 *     </problem>
 *     <solution>
 *         Call "SetPlayerColor" in "OnPlayerConnect".
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    >KoczkaHUN</author>
 * </fix>
 *
 * <fix name="FILTERSCRIPT">
 *     <problem>
 *         Despite the fact that is in every new script, many people dont'
 *         define "FILTERSCRIPT" where appropriate.
 *     </problem>
 *     <solution>
 *         Provide an "IS_FILTERSCRIPT" variable (note the naming to
 *         match the original macro).
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <see>OnFilterScriptInit</see>
 *     <see>OnGameModeInit</see>
 * </fix>
 *
 * <fix name="SpawnPlayer">
 *     <problem>
 *         Kills the player if they are in a vehicle.
 *     </problem>
 *     <solution>
 *         Remove the from the vehicle.
 *     </solution>
 *     <see>FIXES_SpawnPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerName">
 *     <problem>
 *         Using "SetPlayerName" when the new name only differs from the old
 *         name in case does not alter the name at all.
 *     </problem>
 *     <solution>
 *         Change their name twice - once to "_FIXES TEMP NAME" and then
 *         to the actual required name.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>FIXES_SetPlayerName</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="GetPlayerSkin">
 *     <problem>
 *         Returns the new skin after "SetSpawnInfo" is called but before the
 *         player actually respawns to get the new skin.
 *     </problem>
 *     <solution>
 *         Record the skin in "OnPlayerSpawn" and always return that one.
 *
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <see>FIXES_GetPlayerSkin</see>
 *     <see>FIXES_SetPlayerSkin</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetWeaponName" fixed="0.3.7">
 *     <problem>
 *         Returns nothing for 18, 44, and 45.
 *     </problem>
 *     <solution>
 *         Return the correct names (<c>Molotov Cocktail</c>, <c>Thermal
 *         Goggles</c>, and <c>Night vision Goggles</c>).
 *     </solution>
 *     <see>FIXES_GetWeaponName</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerWorldBounds">
 *     <problem>
 *         Aiming can bypass the edge.
 *     </problem>
 *     <solution>
 *         Check for the player leaving the area and reset them to their last
 *         good position if they leave the area (aiming or not).
 *     </solution>
 *     <see>OnPlayerUpdate</see>
 *     <see>FIXES_SetPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="TogglePlayerControllable">
 *     <problem>
 *         Other players see you moving on the spot.
 *     </problem>
 *     <solution>
 *         Return 0 in OnPlayerUpdate.
 *     </solution>
 *     <see>FIXES_TogglePlayerControllable</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=876854" />
 * </fix>
 *
 * <fix name="HydraSniper">
 *     <problem>
 *         Entering military aircraft with a sniper rifle messes up views.
 *     </problem>
 *     <solution>
 *         Set their armed weapon to fists.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <see>FIXES_SetPlayerArmedWeapon</see>
 *     <author    >funky1234</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=965644" />
 * </fix>
 *
 * <fix name="IsPlayerInCheckpoint">
 *     <problem>
 *         Function returns an undefined value if it is called before any other
 *         checkpoint functions are called to initialise the value.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerCheckpoint" when they connect.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="IsPlayerInRaceCheckpoint">
 *     <problem>
 *         Function returns an undefined value if it is called before any other
 *         race checkpoint functions are called to initialise the value.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerRaceCheckpoint" when they connect.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerWeapon">
 *     <problem>
 *         Returns the old value after entering in a vehicle.
 *     </problem>
 *     <solution>
 *         If "SetPlayerArmedWeapon" and other similar functions is called in a
 *         vehicle, store the new value and return that instead.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_SetPlayerArmedWeapon</see>
 *     <see>FIXES_GetPlayerWeapon</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <see>FIXES_ResetPlayerWeapons</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/ronixtey/" >ronixtey</author>
 * </fix>
 *
 * <fix name="PutPlayerInVehicle">
 *     <problem>
 *         If this is used on a passenger the driver of their old vehicle
 *         doesn't see them in their new vehicle.
 *     </problem>
 *     <solution>
 *         Remove them from the vehicle first.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_PutPlayerInVehicle</see>
 *     <author    >leong124</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1265965" />
 * </fix>
 *
 * <fix name="KEY_AIM">
 *     <problem>
 *         "KEY_AIM" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerCheckpoint">
 *     <problem>
 *         If a checkpoint is already set it will use the size of that
 *         checkpoint instead of the new one.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerCheckpoint" before setting the checkpoint.
 *     </solution>
 *     <see>FIXES_SetPlayerCheckpoint</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="SetPlayerRaceCheckpoint">
 *     <problem>
 *         If a checkpoint is already set it will use the size of that
 *         checkpoint instead of the new one.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerRaceCheckpoint" before setting the checkpoint.
 *     </solution>
 *     <see>FIXES_SetPlayerRaceCheckpoint</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="TextDrawCreate">
 *     <problem>
 *         Crashes on a blank string.
 *     </problem>
 *     <solution>
 *         Intercept blank strings.
 *     </solution>
 *     <see>FIXES_TextDrawCreate</see>
 *     <author    >wups</author>
 * </fix>
 *
 * <fix name="TextDrawCreate_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_TextDrawCreate</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 *
 * <fix name="TextDrawSetString">
 *     <problem>
 *         Crashes on a blank string and size greater than 1024.
 *     </problem>
 *     <solution>
 *         Intercept blank strings and truncate long strings.
 *     </solution>
 *     <see>FIXES_TextDrawSetString</see>
 *     <author    >TomTrox</author>
 * </fix>
 *
 * <fix name="TextDrawSetString_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_TextDrawSetString</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 *
 * <fix name="CreatePlayerTextDraw">
 *     <problem>
 *         Crashes on a blank string.
 *     </problem>
 *     <solution>
 *         Intercept blank strings.
 *     </solution>
 *     <see>FIXES_CreatePlayerTextDraw</see>
 *     <author    >wups</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="CreatePlayerTextDraw_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_CreatePlayerTextDraw</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 *
 * <fix name="PlayerTextDrawSetString">
 *     <problem>
 *         Crashes on a blank string and size greater than 1024.
 *     </problem>
 *     <solution>
 *         Intercept blank strings and truncate long strings.
 *     </solution>
 *     <see>FIXES_PlayerTextDrawSetString</see>
 *     <author    >TomTrox</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="PlayerTextDrawSetString_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_PlayerTextDrawSetString</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 *
 * <fix name="AllowInteriorWeapons">
 *     <problem>
 *         Does nothing.
 *     </problem>
 *     <solution>
 *         Set the player's weapon to fists in an interior.
 *     </solution>
 *     <see>FIXES_AllowInteriorWeapons</see>
 *     <see>OnGameModeInit</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >KoczkaHUN</author>
 * </fix>
 *
 * <fix name="OnPlayerEnterVehicle">
 *     <problem>
 *         Crashes other players when people enter an invalid seat.
 *     </problem>
 *     <solution>
 *         Desync the people with invalid seats.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >RyDeR`</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/NexiusTailer">NexiusTailer</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1410296" />
 * </fix>
 *
 * <fix name="OnPlayerEnterVehicle_2">
 *     <problem>
 *         Crashes the server when hacks enter an invalid vehicle.
 *     </problem>
 *     <solution>
 *         Desync the people with invalid vehicles.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <author    >im</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="OnPlayerEnterVehicle_3">
 *     <problem>
 *         No player animation when trying to enter the driver door of a locked
 *         vehicle
 *     </problem>
 *     <solution>
 *         Leave the door unlocked and activate an animation when the player
 *         attemps to enter a 'locked' vehicle.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    href="https://github.com/rt-2" >rt-2</author>
 *     <post      href="http://forum.sa-mp.com/showthread.php?t=560019" />
 * </fix>
 *
 * <fix name="AllowTeleport">
 *     <problem>
 *         0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in
 *         favour of "OnPlayerClickMap".  Some scripts used the old code and.
 *     </problem>
 *     <solution>
 *         Teleport the player in "OnPlayerClickMap".
 *     </solution>
 *     <see>OnPlayerClickMap</see>
 *     <see>FIXES_AllowPlayerTeleport</see>
 *     <see>FIXES_AllowAdminTeleport</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerSpecialAction">
 *     <problem>
 *         Removing jetpacks from players by setting their special action to 0
 *         causes the sound to stay until death.
 *     </problem>
 *     <solution>
 *         Call "ClearAnimations" before "SetPlayerSpecialAction".
 *     </solution>
 *     <see>FIXES_SetPlayerSpecialAction</see>
 *     <author    >MP2</author>
 * </fix>
 *
 * <fix name="OnDialogResponse" fixed="0.3e RC6">
 *     <problem>
 *         Cheaters can spoof the dialogid they are using to respond to ones
 *         they can't actually see.
 *     </problem>
 *     <solution>
 *         Store the displayed dialogid and use that instead.
 *     </solution>
 *     <see>FIXES_OnDialogResponse</see>
 *     <see>FIXES_ShowPlayerDialog</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerDialog" disabled="true">
 *     <problem>
 *         This function doesn't exist.  Fixed for hidden dialogs.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetPlayerDialog</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="PlayerDialogResponse">
 *     <problem>
 *         A player's dialog doesn't hide when the gamemode restarts, causing
 *         the server to print "Warning: PlayerDialogResponse PlayerId: 0
 *         dialog ID doesn't match last sent dialog ID".
 *     </problem>
 *     <solution>
 *         Hide it.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>OnGameModeExit</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="SetSpawnInfo">
 *     <problem>
 *         Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo".
 *     </problem>
 *     <solution>
 *         Call "SetSpawnInfo" at least once.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetSpawnInfo_2">
 *     <problem>
 *         Does not set the correct team after spawn.
 *     </problem>
 *     <solution>
 *         Call "SetPlayerTeam" when they spawn.
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <author    href="http://forum.sa-mp.com/member.php?u=24012" >NaS</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=3994248" />
 * </fix>
 *
 * <fix name="SetPlayerSkin">
 *     <problem>
 *         Breaks sitting on bikes.
 *     </problem>
 *     <solution>
 *         Put them back in the vehicle after setting their skin.
 *     </solution>
 *     <see>FIXES_SetPlayerSkin</see>
 *     <author    >CyNiC</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1756094" />
 * </fix>
 *
 * <fix name="HideMenuForPlayer">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_HideMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1787297" />
 * </fix>
 *
 * <fix name="valstr">
 *     <problem>
 *         Crashes on large numbers.
 *     </problem>
 *     <solution>
 *         Use "format" instead.
 *     </solution>
 *     <see>FIXES_valstr</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fclose">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fclose</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fwrite">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fwrite</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fread">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fread</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fputchar">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fputchar</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fgetchar">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fgetchar</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fblockwrite">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fblockwrite</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fblockread">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fblockread</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="fseek">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fseek</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="flength">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_flength</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="file_inc" disabled="true">
 *     <problem>
 *         Includes or excludes all the file function fixes together (can cause
 *         major overhead).
 *     </problem>
 *     <solution>
 *         Optionally group them all under one define.
 *     </solution>
 *     <see>FIX_file_inc</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerAttachedObject">
 *     <problem>
 *         Doesn't remove objects when the mode ends.
 *     </problem>
 *     <solution>
 *         Remove them.
 *     </solution>
 *     <see>OnPlayerDisconnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetVehicleComponentInSlot">
 *     <problem>
 *         The function GetVehicleComponentInSlot doesn't work for CARMODTYPE_STEREO.  Both front
 *         bull bars and front bumper components are saved in the CARMODTYPE_FRONT_BUMPER slot.  If
 *         a vehicle has both of them installed, this function will only return the one which was
 *         installed last.  Both rear bull bars and rear bumper components are saved in the
 *         <c>CARMODTYPE_REAR_BUMPER</c> slot.  If a vehicle has both of them installed this
 *         function will only return the one which was installed last.
 *     </problem>
 *     <solution>
 *         Hook functions and store components. This uses some code from vSync library.
 *     </solution>
 *     <see>FIXES_GetVehicleComponentInSlot</see>
 *     <author    href="https://github.com/Mergevos/" >Mergevos</author>
 * </fix>
 *
 * <fix name="AttachTrailerToVehicle">
 *     <problem>
 *         When trailerid is equal to vehicleid and passenger is in vehicleid, it starts spinning.
 *     </problem>
 *     <solution>
 *         Check if trailerid and vehicleid are equal.
 *     </solution>
 *     <see>FIX_AttachTrailerToVehicle</see>
 *     <author    href="https://github.com/Mergevos/" >Mergevos</author>
 * </fix>
 *
 * <fix name="OnPlayerDeath">
 *     <problem>
 *         Clients get stuck when they die with an animation applied.
 *     </problem>
 *     <solution>
 *         Clear their animations.
 *     </solution>
 *     <see>OnPlayerDeath</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >h02</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1641144" />
 * </fix>
 *
 * <fix name="strins">
 *     <problem>
 *         Ignores the "maxlength" parameter causing possible crashes.
 *     </problem>
 *     <solution>
 *         Manually check the length.
 *     </solution>
 *     <see>FIXES_strins</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="IsPlayerConnected">
 *     <problem>
 *         Only uses the lower two bytes of a passed ID.
 *     </problem>
 *     <solution>
 *         Mask the numbers.
 *     </solution>
 *     <see>FIXES_IsPlayerConnected</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 *
 * <fix name="TrainExit">
 *     <problem>
 *         When getting out of a train entered by "PutPlayerInVehicle", the
 *         camera does not reset properly.
 *     </problem>
 *     <solution>
 *         Reset the camera.
 *     </solution>
 *     <see>FIXES_PutPlayerInVehicle</see>
 *     <see>FIXES_OnPlayerStateChange</see>
 *     <author    >Terminator3</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="Kick" fixed="0.3x">
 *     <problem>
 *         Calling "Kick" in "OnPlayerConnect" doesn't work properly.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>FIXES_Kick</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1989453" />
 * </fix>
 *
 * <fix name="OnVehicleMod">
 *     <problem>
 *         Crashes other players when invalid mods are applied.
 *     </problem>
 *     <solution>
 *         Desync the player.
 *     </solution>
 *     <see>OnVehicleMod</see>
 *     <author    href="https://github.com/JernejL/" >JernejL</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1671500" />
 * </fix>
 *
 * <fix name="random" disabled="true">
 *     <problem>
 *         Doesn't work with negative numbers.
 *     </problem>
 *     <solution>
 *         Invert then reinvert.
 *     </solution>
 *     <see>FIXES_random</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="sleep">
 *     <problem>
 *         Leaks bytes from the stack.
 *     </problem>
 *     <solution>
 *         Call a function to store the correct value.
 *     </solution>
 *     <see>FIXES_sleep</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="AddMenuItem">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_AddMenuItem</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetMenuColumnHeader">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_SetMenuColumnHeader</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="ShowMenuForPlayer">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_ShowMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="HideMenuForPlayer">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_HideMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1787297" />
 * </fix>
 *
 * <fix name="HideMenuForPlayer_2" disabled="true">
 *     <problem>
 *         Ignores the "menuid" parameter.
 *     </problem>
 *     <solution>
 *         Only hide the correct menu.
 *     </solution>
 *     <see>FIXES_HideMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="DisableMenu">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_DisableMenu</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="DisableMenuRow">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_DisableMenuRow</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="Menus">
 *     <problem>
 *         All menu function fixes are included separately for major overhead.
 *     </problem>
 *     <solution>
 *         Optionally group them all under one define.
 *     </solution>
 *     <see>FIX_Menus</see>
 *     <see>_FIX_Menus</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerMenu">
 *     <problem>
 *         Returns previous menu when none is displayed.
 *     </problem>
 *     <solution>
 *         Return the correct value.
 *     </solution>
 *     <see>FIXES_GetPlayerMenu</see>
 *     <see>OnPlayerSelectedMenuRow</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerInterior">
 *     <problem>
 *         Always returns 0 for NPCs.
 *     </problem>
 *     <solution>
 *         Return the correct value.
 *     </solution>
 *     <see>FIXES_GetPlayerInterior</see>
 *     <see>FIXES_SetPlayerInterior</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="ClearAnimations">
 *     <problem>
 *         Use ClearAnimation while you are in a vehicle cause the player exit
 *         from it.
 *     </problem>
 *     <solution>
 *         Apply an animation instead of clear animation.
 *     </solution>
 *     <see>FIXES_ClearAnimations</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="ClearAnimations_2">
 *     <problem>
 *         ClearAnimations doesn't do anything when the animation ends if we
 *         pass 1 for the freeze parameter in ApplyAnimation.
 *     </problem>
 *     <solution>
 *         Apply an idle animation for stop and then use ClearAnimation.
 *     </solution>
 *     <see>FIXES_ClearAnimations</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="DriveBy">
 *     <problem>
 *         If you press KEY_CROUCH while you're passenger and if you are armed,
 *         the player start to aim; if you repress KEY_CROUCH the player don't
 *         return in vehicle.
 *     </problem>
 *     <solution>
 *         Apply the animation to return the player in the vehicle.
 *     </solution>
 *     <see>OnPlayerKeyStateChange</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="SilentTeleport">
 *     <problem>
 *         Player teleports silently while trying to enter a vehicle as that vehicle teleports/changes original interior.
 *     </problem>
 *     <solution>
 *         Stop the player from teleporting by using 'ClearAnimations' before the teleport happens.
 *     </solution>
 *	   <see>OnPlayerEnterVehicle</see>
 *	   <see>OnPlayerInteriorChange</see>
 *     <author    href="https://github.com/RogueDrifter/" >RogueDrifter</author>
 * </fix>
 *
 * <fix name="GangZoneCreate">
 *     <problem>
 *         Gang zones bug on the main map for players at certain angles relative
 *         to them.
 *     </problem>
 *     <solution>
 *         Set a non floating value for the gang zone co-ordinate.
 *     </solution>
 *     <see>FIXES_GangZoneCreate</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SPECIAL_ACTION_PISSING">
 *     <problem>
 *         "SPECIAL_ACTION_PISSING" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="IsValidVehicle">
 *     <problem>
 *         "IsValidVehicle" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="ApplyAnimation">
 *     <problem>
 *         Passing an invalid animation library in ApplyAnimation causes a
 *         client crash for streamed in players.
 *     </problem>
 *     <solution>
 *         Block ApplyAnimation when an invalid library is passed.
 *     </solution>
 *     <see>FIXES_ApplyAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 *
 * <fix name="ApplyAnimation_2">
 *     <problem>
 *         First time a library is used, it does nothing.
 *     </problem>
 *     <solution>
 *         Apply animations twice when first using a library.
 *     </solution>
 *     <see>FIXES_ApplyAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Lordzy/" >Lordzy</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="ApplyActorAnimation">
 *     <problem>
 *         Passing an invalid animation library in ApplyAnimation causes a
 *         client crash for streamed in players.
 *     </problem>
 *     <solution>
 *         Block ApplyActorAnimation when an invalid library is passed.
 *     </solution>
 *     <see>FIXES_ApplyActorAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="ApplyActorAnimation_2">
 *     <problem>
 *         First time a library is used, it does nothing.
 *     </problem>
 *     <solution>
 *         Apply animations twice when first using a library.
 *     </solution>
 *     <see>FIXES_ApplyActorAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Lordzy/" >Lordzy</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="OnPlayerSpawn">
 *     <problem>
 *         San Andreas deducts $100 from players.
 *     </problem>
 *     <solution>
 *         Give them it back.
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetGravity">
 *     <problem>
 *         "GetGravity" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1706447" />
 * </fix>
 *
 * <fix name="gpci">
 *     <problem>
 *         "gpci" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <post      href="http://pastebin.com/VQSGpbSm" />
 * </fix>
 *
 * <fix name="Natives">
 *     <problem>
 *         Several natives are included by default, this enables or disables
 *         them all.  Therefore this is an umbrella fix for several fixes.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <see>FIX_GetGravity</see>
 *     <see>FIX_gpci</see>
 *     <see>FIX_IsValidVehicle</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="OnPlayerConnect">
 *     <problem>
 *         This function isn't called for players when a filterscript starts.
 *     </problem>
 *     <solution>
 *         Call it for all connected players.
 *     </solution>
 *     <see>FIXES_OnFilterScriptInit</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="OnPlayerDisconnect">
 *     <problem>
 *         This function isn't called for players when a filterscript ends.
 *     </problem>
 *     <solution>
 *         Call it for all connected players.
 *     </solution>
 *     <see>FIXES_OnFilterScriptExit</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GameText">
 *     <problem>
 *         Several styles do not display for the time specified.
 *     </problem>
 *     <solution>
 *         Recreate the styles in Text Draws and use those instead.
 *     </solution>
 *     <see>FIXES_GameTextForAll</see>
 *     <see>FIXES_GameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GameTextStyles" disabled="true">
 *     <problem>
 *         San Andreas has fixed styles for area and vehicle names, but they are
 *         not included in the GameText styles list.
 *     </problem>
 *     <solution>
 *         Add them.
 *     </solution>
 *     <see>FIXES_GameTextForAll</see>
 *     <see>FIXES_GameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/NexiusTailer">NexiusTailer</author>
 * </fix>
 *
 * <fix name="HideGameText">
 *     <problem>
 *         There is no "HideGameTextForXYZ" function.
 *     </problem>
 *     <solution>
 *         Show a single space for a game text.
 *     </solution>
 *     <see>FIXES_HideGameTextForAll</see>
 *     <see>FIXES_HideGameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="ClearPlayerWorldBounds">
 *     <problem>
 *         There is no "ClearPlayerWorldBounds" function.
 *     </problem>
 *     <solution>
 *         Put the world bounds back to the default.
 *     </solution>
 *     <see>FIXES_ClearPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerWorldBounds">
 *     <problem>
 *         There is no "GetPlayerWorldBounds" function.
 *     </problem>
 *     <solution>
 *         Store them and retrieve them.
 *     </solution>
 *     <see>FIXES_GetPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="WEAPONS">
 *     <problem>
 *         Some weapons are not defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 *
 * <fix name="BODYPARTS">
 *     <problem>
 *         The bodyparts to be used in OnPlayer(Take/Give)Damage are not defined
 *         by default
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 * </fix>
 *
 * <fix name="CAMERAMODES">
 *     <problem>
 *         The camera modes for GetPlayerCameraMode are not defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=1309730" />
 * </fix>
 *
 * <fix name="SetPlayerCamera">
 *     <problem>
 *         Using the camera functions directly after enabling spectator mode
 *         doesn't work.
 *     </problem>
 *     <solution>
 *         Defer them.
 *     </solution>
 *     <see>FIXES_SetPlayerCameraPos</see>
 *     <see>FIXES_SetPlayerCameraLookAt</see>
 *     <see>FIXES_TogglePlayerSpectating</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 * </fix>
 *
 * <fix name="SetPlayerTime">
 *     <problem>
 *         Using this function under "OnPlayerConnect" doesn't work.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>FIXES_SetPlayerTime</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 * </fix>
 *
 * <fix name="OnPlayerRequestClass">
 *     <problem>
 *         Random blunts and bottles sometimes appear in class selection.
 *     </problem>
 *     <solution>
 *         Call "RemoveBuildingForPlayer".
 *     </solution>
 *     <see>OnPlayerRequestClass</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetPlayerColor">
 *     <problem>
 *         If used under OnPlayerConnect, the affecting player will not see the
 *         color in the TAB menu.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>FIXES_SetPlayerColor</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 *     <post      href="http://forum.sa-mp.com/showthread.php?t=452407" />
 * </fix>
 *
 * <fix name="FileMaths">
 *     <problem>
 *         You can write gibberish like "File:a; ++a;".
 *     </problem>
 *     <solution>
 *         Remove the operators.
 *     </solution>
 *     <see>File:operator</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPlayerWeaponData">
 *     <problem>
 *         Old weapons with no ammo left are still returned.
 *     </problem>
 *     <solution>
 *         Set "weapons" to 0.
 *     </solution>
 *     <see>FIXES_GetPlayerWeaponData</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showthread.php?t=567400" />
 * </fix>
 *
 * <fix name="strcmp">
 *     <problem>
 *         Return 0 if anyone of the string is empty.
 *     </problem>
 *     <solution>
 *         Add a check for empty string.
 *     </solution>
 *     <see>FIXES_strcmp</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetPVarString">
 *     <problem>
 *         Wrong symbol code for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Use logical conjunction on symbol and 0xFF.
 *     </solution>
 *     <see>FIXES_GetPVarString</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    >Mutha_X</author>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <post      href="http://forum.sa-mp.com/showthread.php?t=572724&amp;page=11" />
 *     <post      href="http://pro-pawn.ru/showthread.php?13007" />
 * </fix>
 *
 * <fix name="GetSVarString">
 *     <problem>
 *         Wrong symbol code for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Use logical conjunction on symbol and 0xFF.
 *     </solution>
 *     <see>FIXES_GetSVarString</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    >Mutha_X</author>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <post      href="http://forum.sa-mp.com/showthread.php?t=572724&amp;page=11" />
 *     <post      href="http://pro-pawn.ru/showthread.php?13007" />
 * </fix>
 *
 * <fix name="toupper">
 *     <problem>
 *         Not working on Linux for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Recreate the function.
 *     </solution>
 *     <see>FIXES_toupper</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <post      href="http://pro-pawn.ru/showthread.php?13466&amp;p=72954#post72954" />
 * </fix>
 *
 * <fix name="tolower">
 *     <problem>
 *         Not working on Linux for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Recreate the function.
 *     </solution>
 *     <see>FIXES_tolower</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <post      href="http://pro-pawn.ru/showthread.php?13466&amp;p=72954#post72954" />
 * </fix>
 *
 * <fix name="ispacked">
 *     <problem>
 *         Returns false when the string is packed and starts with a symbol with code 128 and above.
 *     </problem>
 *     <solution>
 *         Check the string manually.
 *     </solution>
 *     <see>FIXES_ispacked</see>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <author    href="https://github.com/VVWVV" >VVWVV</author>
 * </fix>
 *
 * <fix name="PassengerSeating">
 *     <problem>
 *         Teleporting player to passenger seat after delay.
 *     </problem>
 *     <solution>
 *         Call ClearAnimation after some delay.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <see>OnPlayerStateChange</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 *
 * <fix name="GogglesSync">
 *     <problem>
 *         Visual effects show for all players.
 *     </problem>
 *     <solution>
 *         return 0 in OnPlayerUpdate after key pressed.
 *     </solution>
 *     <see>OnPlayerUpdate</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 *
 * <fix name="GetPlayerPoolSize">
 *     <problem>
 *         Returns "0" even if there are no players on the server.
 *     </problem>
 *     <solution>
 *         Return "-1" if PlayerPoolsize is 0 but Player 0 is not connected.
 *     </solution>
 *     <see>FIXES_GetPlayerPoolSize</see>
 *     <author    href="https://github.com/Bios-Marcel" >Bios-Marcel</author>
 * </fix>
 *
 * <fix name="SetPlayerPos">
 *     <problem>
 *         Using this function on skydiving players kills them.
 *     </problem>
 *     <solution>
 *         Remove the parachute when the player is skydiving.
 *     </solution>
 *     <see>FIXES_SetPlayerPos</see>
 *     <see>FIXES_SetPlayerPosFindZ</see>
 *     <author    href="https://github.com/WoutProvost" >Freaksken</author>
 * </fix>
 *
 * <fix name="GetPlayerAmmo">
 *     <problem>
 *         Returns erroneous values over 32767 and under -32768 due to overflow.
 *     </problem>
 *     <solution>
 *         Prevent setting or adding ammo above 32767 and setting or removing
 *         ammo below 0.
 *     </solution>
 *     <see>FIXES_SetPlayerAmmo</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <author    href="https://github.com/WoutProvost" >Freaksken</author>
 * </fix>
 *
 * <fix name="JIT">
 *     <problem>
 *         Can't easily determine if the script is JIT compiled.
 *     </problem>
 *     <solution>
 *         Provide "IS_JIT" to the script for tests.
 *     </solution>
 *     <see>OnJITCompile</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="OS">
 *     <problem>
 *         Can't easily determine what OS the script is running on.
 *     </problem>
 *     <solution>
 *         Provide "IS_WINDOWS" and "IS_LINUX" to the script for tests.
 *     </solution>
 *     <see>_FIXES_DetermineOS</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="const">
 *     <problem>
 *         Some SA-MP natives don't use "const" when they could.
 *     </problem>
 *     <solution>
 *         Redefine the natives.
 *     </solution>
 *     <see>FIX_const</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="VEHICLES">
 *     <problem>
 *         The vehicle models IDs are not defined by default.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <author    href="https://github.com/IstuntmanI" >stuntman</author>
 * </fix>
 *
 * <fix name="GetPlayerWeather" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetPlayerWeather</see>
 *     <author    href="https://github.com/IstuntmanI/" >IstuntmanI</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="GetWeather" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetWeather</see>
 *     <author    href="https://github.com/IstuntmanI/" >IstuntmanI</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="GetWorldTime" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetWorldTime</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 *
 * <fix name="GetServerVarAsString">
 *     <problem>
 *         Crashes on unknown string variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetServerVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 *
 * <fix name="GetServerVarAsInt">
 *     <problem>
 *         Crashes on unknown int variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetServerVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 *
 * <fix name="GetServerVarAsBool">
 *     <problem>
 *         Crashes on unknown boolean variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetServerVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 *
 * <fix name="GetServerVarAsFloat">
 *     <problem>
 *         Doesn't even exist.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetServerVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 *
 * <fix name="GetConsoleVarAsString">
 *     <problem>
 *         Crashes on unknown string variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetConsoleVarAsInt">
 *     <problem>
 *         Crashes on unknown int variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetConsoleVarAsBool">
 *     <problem>
 *         Crashes on unknown boolean variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetConsoleVarAsFloat">
 *     <problem>
 *         Doesn't even exist.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="tabsize">
 *     <problem>
 *         Some people still use <c>tabsize 0</c>.
 *     </problem>
 *     <solution>
 *         Break the pragma.
 *     </solution>
 *     <see>_DUMMY_do_not_use_tabsize_0</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=3929000" />
 * </fix>
 *
 * <fix name="OnRconCommand">
 *     <problem>
 *         Is not called in the gamemode unless first called in a filterscript.
 *     </problem>
 *     <solution>
 *         Load a minimal (embedded) FS to bootstrap it.
 *     </solution>
 *     <see>OnGameModeInit</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="OnClientCheckResponse">
 *     <problem>
 *         Is not called in the gamemode ever.
 *     </problem>
 *     <solution>
 *         Load a minimal (embedded) FS to bootstrap it.
 *     </solution>
 *     <see>OnGameModeInit</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="GetMaxPlayers">
 *     <problem>
 *         If this is > MAX_PLAYERS, can cause OOBs in code.
 *     </problem>
 *     <solution>
 *         Constrain it; but also warn because that doesn't really help.
 *     </solution>
 *     <see>GetMaxPlayers</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="BypassDialog">
 *     <problem>
 *         You can type commands and move while in dialogs.
 *     </problem>
 *     <solution>
 *         Return 0.
 *     </solution>
 *     <see>OnPlayerCommandText</see>
 *     <see>OnPlayerText</see>
 *     <see>OnPlayerUpdate</see>
 *     <see>OnDialogResponse</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="SetTimer">
 *     <problem>
 *         Valid timers can return ID 0.
 *     </problem>
 *     <solution>
 *         Recreate them and kill the original.
 *     </solution>
 *     <see>FIXES_SetTimer</see>
 *     <see>FIXES_SetTimerEx</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="main">
 *     <problem>
 *         Gamemodes without this function give a console error.
 *     </problem>
 *     <solution>
 *         Make a stub version.
 *     </solution>
 *     <see>main</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="CreateVehicle">
 *     <problem>
 *         Colour <c>-1</c> isn't synced.
 *     </problem>
 *     <solution>
 *         Manually control the colours.
 *     </solution>
 *     <see>FIXES_CreateVehicle</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="API">
 *     <problem>
 *         fixes.inc isn't intended to extend the SA:MP API, but has a lot of information internally
 *         that can be useful to other scripts.  By not exposing this data, we complicate and bloat
 *         scripts by requiring them to re-implement said functionality.
 *     </problem>
 *     <solution>
 *         Expose the data, behind a tightly controlled API.
 *     </solution>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 *
 * <fix name="Pawndoc">
 *     <problem>
 *         Pawndoc comments aren't ignored inside <c>#if</c> blocks, nor used on macros.
 *     </problem>
 *     <solution>
 *         Place an unconditional <c>const</c> directly after comments, to which the documentation
 *         is attached.  All this "fix" does is provide a meaningful name, and does this on the
 *         first pass for comments you want to keep on macros.
 *     </solution>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 *     <post   href="https://github.com/pawn-lang/compiler/issues/674#issuecomment-908927779" />
 *     <see>HIDE_PAWNDOC</see>
 *     <see>SHOW_PAWNDOC</see>
 * </fix>
 * </fixeslist>
 *
 * <section>
 *             Options
 * </section>
 *
 * <p>There are a few options for improved execution of this script.  Define
 * these symbols as <c>1</c> before you include fixes.inc (remove them or set
 * them to <c>0</c> to disable them):</p>
 *
 * <ul>
 *   <symbol name="FIXES_Single">You only have one script running (no
 *       filterscripts), simplify the code.</symbol>
 *   <symbol name="FIXES_SilentKick">When a player is kicked for illegal
 *       mods/vehicles, don't send them a message.</symbol>
 *   <symbol name="FIXES_Debug">Additional information in the server
 *       console.</symbol>
 * </ul>
 *
 * <p>A few fixes are disabled by default, to enable them all do:</p>
 *
 * <code>
 * #define GetPlayerDialog     1                                                <br />
 * #define file_inc            1                                                <br />
 * #define random              1                                                <br />
 * #define HideMenuForPlayer_2 1                                                <br />
 * #define GameTextStyles      1                                                <br />
 * #define GetPlayerWeather    1                                                <br />
 * #define GetWeather          1                                                <br />
 * #define GetWorldTime        1
 * </code>
 *
 * <p>Or more simply (and future-proof-ly):</p>
 *
 * <code>
 * #define FIXES_EnableAll                                                      <br />
 * #define FIXES_EnableDeprecated
 * </code>
 *
 * <section>
 *             Expansion
 * </section>
 *
 * <p>The file is fairly well documented, with a list of the currently
 * (hopefully) fixed bugs at the top.  If you know of others, or have solutions
 * for others, it would be greatly appreciated if you could post them as issues
 * on this repository.  The fixes also need extensive testing to find bugs in
 * the fixes themselves.</p>
 *
 * <p>Again, this is a community project, merely managed by Y_Less and others -
 * if anyone has comments, contributions, criticisms etc. please again post them
 * as issues on the repository.  This includes additions to source code,
 * documentation, presentation, translations (mainly of this documentation -
 * multiple versions of the include should be avoided to reduce fragmentation),
 * or any other related area you can think of.</p>
 *
 * <section>
 *             Other Fixes
 * </section>
 *
 * <p>There are a few other includes which aim to fix issues too large to be
 * included here:</p>
 *
 * <ul>
 *   <li><a href="http://forum.sa-mp.com/showthread.php?t=435525">Timerfix</a> -
 *       <a href="https://github.com/udan11">udan11 (Dan..)</a>'s fixes to make
 *       "SetTimer" and "SetTimerEx" vastly more accurate in their delays.</li>
 *   <li><a href="http://forum.sa-mp.com/showthread.php?t=303682">SQLitei</a> -
 *       <a href="https://github.com/oscar-broman/">Slice</a>'s fixes and
 *       improvements for many SQLite functions.</li>
 * </ul>
 *
 * <section>
 *             Bugs
 * </section>
 *
 * <p>Originally Posted by <a href="https://github.com/Y-Less/">Y_Less</a>:</p>
 *
 * <p><em>[This] is beta software written by a small team in their spare time,
 * thus it has bugs (as does all software).  This software is explicitly
 * designed to solve bugs, not cause them, but there may still be bugs.</em></p>
 *
 * <p>The most likely cause of bugs is certain combinations of disabled fixes.
 * Some fixes are inter-mixed and while they SHOULD work when the fixes they are
 * combined with are disabled, not every combination has been tested.  There are
 * literally billions of possible combinations - if you find one that doesn't
 * compile or work, please tell us.</p>
 *
 * <section>
 *             Style Rules
 * </section>
 *
 * <ul>
 * <li>All globals should be <c>static stock</c> whenever possible (so they can only be
 *     accessed from this one file).
 * </li>
 * <li>Statics must start with <c>FIXES_gs</c>, and all other globals with <c>FIXES_g</c>.
 * </li>
 * <li>All functions not overriding existing functions must start with <c>FIXES_</c>.
 * </li>
 * <li>Macros must be upper case, use underscores, and start <c>FIXES_</c>:
 *     <c>FIXES_LIKE_THIS</c>.
 * </li>
 * <li>Functions should be upper camel case (as the original functions are)
 *     <c>FIXES_LikeThis</c>.
 * </li>
 * <li>Globals (after the prefix) should be upper camel case <c>LikeThis</c>, and locals
 *     lower camel case <c>likeThis</c>.
 * </li>
 * <li>ALS should be used to hook functions and callbacks.  See this topic for more
 *    details:
 *
 *        http://forum.sa-mp.com/showthread.php?t=570910
 * </li>
 * <li>The ALS prefix for chaining is <c>FIXES_</c>.
 * </li>
 * <li>When redefining a native, add a <c>BAD_</c> external name declaration with the
 *     <c>_ALS_</c> definition so that others may use the original native if they so
 *     desire (with the caveat that it may break all fixes).  Note the <c>BAD_</c>
 *     name is meant to indicate the possibility of breaking the fix, not a
 *     comment on the original native function.
 * </li>
 * <li>The ALS hook defines used here are a little different to the normal ones as
 *     this file assumes that it is always first.  The pattern is:
 * <code>
 *         ///
 *         /// <remarks>Information about fix here</remarks>
 *         /// <fixes>NameOfFixHere</fixes>
 *         ///
 *         
 *         #if _FIXES_SAMP &amp;&amp; defined _ALS_NameOfFixHere
 *         	#error _ALS_NameOfFixHere defined
 *         #endif
 *         native BAD_NameOfFixHere(params) = NameOfFixHere;
 *         
 *         ///
 *         /// <remarks>Information about fix here</remarks>
 *         /// <fixes>NameOfFixHere</fixes>
 *         ///
 *         
 *         #if FIX_NameOfFixHere
 *             stock FIXES_NameOfFixHere(params)
 *             {
 *                 return 0;
 *             }
 *         
 *             // The trailing `(` is VERY important to keep future `native X() = Y;`s working.
 *             #if _FIXES_SAMP
 *                 #define _ALS_NameOfFixHere
 *                 #define NameOfFixHere( FIXES_NameOfFixHere(
 *             #endif
 *             // `__` suffix version for hidden calls to the originals.
 *             #define _ALS_NameOfFixHere__
 *             #define NameOfFixHere__( FIXES_NameOfFixHere(
 *         #endif
 * </code>
 *    A copyable version of this pattern is at the end of the file.
 * </li>
 * <li>Enums start with <c>E_</c> or <c>e_</c> depending on type, then follow rules for
 *     macros.
 * </li>
 * <li>NO libraries should be included - not even the default SA:MP ones.  Let the
 *     user do it.
 * </li>
 * <li>Due to the above rule, you cannot assume any third party libraries AT ALL, so
 *     do not use them.  This can lead to some code duplication, but also means
 *     that the version of the code used here can be tailored for optimisations.
 * </li>
 * <li>Certain terms may be shortened when dealing with long callback names to avoid
 *     compile truncation warnings (max symbol length is 31).  Current list:
 * <ul>
 *         <li><c>Checkpoint</c>: <c>CP</c></li>
 *         <li><c>Update   </c>: <c>Upd</c></li>
 *         <li><c>TextDraw </c>: <c>TD</c></li>
 *         <li><c>Object   </c>: <c>Obj</c></li>
 *         <li><c>Player   </c>: <c>P</c></li>
 * </ul></li>
 * <li>Document all fixes at the top of the file, and highlight code.
 * </li>
 * <li>4 space TABS - do not edit this file in PAWNO unless you know how to correct
 *     the indentation.
 * </li>
 * <li>All rules have exceptions, but they must be justifiable.  For example
 *     <c>IS_FILTERSCRIPT</c> is a global variable, but is not called
 *     <c>FIXES_gIsFilterscript</c> to better match the <c>FILTERSCRIPT</c> macro it
 *     replaces.  Now a macro for <c>_FIXES_gIsFilterscript</c>.
 * </li>
 * <li>Variables which need to be fully global (i.e. not <c>static</c>), but should not
 *     actually be used by other people (e.g. appear inside a macro) should be
 *     prefixed with <c>_FIXES</c> instead of <c>FIXES</c> to indicate their private use.
 * </li>
 * <li>No comments beyond the end of column 80 (where the line in <c>PAWNO</c> is).
 * </li>
 * <li>If a bug is fixed in some version of the server it can be conditionally
 *     included here.  This is done by checking for the existance of a native
 *     function introduced in the same server version.  For example
 *     <c>TogglePlayerControllable</c> was fixed in 0.3eRC6, the same time as the
 *     <c>SetObjectMaterial</c> native was introduced, thus the inclusion becomes:
 * <code>
 *         #if !defined FIX_TogglePlayerControllable                            <br /><indent />
 *             #if defined SetObjectMaterial                                    <br /><indent /><indent />
 *                 #define FIX_TogglePlayerControllable (0)                     <br /><indent />
 *             #else                                                            <br /><indent /><indent />
 *                 #define FIX_TogglePlayerControllable (1)                     <br /><indent />
 *             #endif                                                           <br />
 *         #elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)                <br /><indent />
 *             #undef FIX_TogglePlayerControllable                              <br /><indent />
 *             #define FIX_TogglePlayerControllable     (2)                     <br />
 *         #endif
 * </code>
 *     This only includes this fix if that native doesn't exist.  A copyable
 *     version of this pattern is at the end of the file.
 * </li>
 * <li>To reduce general memory consumption, strings in this include are stored
 *     globally in constant arrays and referenced.  This is EXACTLY as fast as
 *     using the string constants directly, but means that strings are not
 *     stored in the assembly multiple times (unless the string is only used
 *     once, in which case it's more work for no gain).  See this post for more
 *     details:
 *
 *         <a href="http://forum.sa-mp.com/showpost.php?p=1795601" />
 * </li>
 * <li>DO NOT EDIT THIS FILE IN PAWNO OR ON GITHUB.  Both mess up the spacing -
 *     GitHub in an almost irreversible way (except for the fact that nothing is
 *     irreversible in source control.  Pawno spacing is less tricky to solve,
 *     and can be worked around if you know when it uses spaces and tabs - in
 *     short, always write code first THEN indent and you won't have a problem
 *     (in that editor at least, that is normally a bad way to write code).
 * </li>
 * </ul>
 * <section>
 *             Documentation Explanation
 * </section>
 *
 * <p>The <em>fixes.inc</em> code itself now contains all of the documentation
 * in its header, formatted using the compiler's natively supported pawn-doc,
 * plus some custom XSL.  Previously <em>README.md</em> and the header had to be
 * kept in sync manually.  Now you can just compile a script with <c>-r</c> and
 * get a large amount of XML documentation, including all of this header in a
 * <c>&lt;library&gt;&lt;/library&gt;</c> pair.  The repository comes with a
 * file called <em>markdown.xsl</em> that, when saved as
 * <em>pawno/xml/pawndoc.xsl</em>, will transform that XML to markdown to keep
 * <em>README.md</em> fully up-to-data almost automatically.</p>
 *
 * <p>The descriptions of the fixes all look like:</p>
 *
 * <code lang="xml">
 *     &lt;fix name="Short Name" disabled="true" fixed="Optional server version of official fix where applicable"&gt; <br /><indent />
 *         &lt;problem&gt;                                                                                                        <br /><indent />
 *             Description of problem.                                                                                            <br /><indent /><indent />
 *         &lt;/problem&gt;                                                                                                       <br /><indent />
 *         &lt;solution&gt;                                                                                                       <br /><indent /><indent />
 *             Description of solution.                                                                                           <br /><indent />
 *         &lt;/solution&gt;                                                                                                      <br /><indent />
 *         &lt;see&gt;Relevant functions.&lt;/see&gt;                                                                             <br /><indent />
 *         &lt;author    href="Optional address of their profile"&gt;Person who wrote the fix&lt;/author&gt;                      <br /><indent />
 *         &lt;post      href="Optional link to the original post where applicable." /&gt;                                        <br />
 *     &lt;/fix&gt;
 * </code>
 *
 *
 *
 * </library>
 *//** */

/*

    88        88                                   88                          
    88        88                                   88                          
    88        88                                   88                          
    88aaaaaaaa88   ,adPPYba,  ,adPPYYba,   ,adPPYb,88   ,adPPYba,  8b,dPPYba,  
    88""""""""88  a8P_____88  ""     `Y8  a8"    `Y88  a8P_____88  88P'   "Y8  
    88        88  8PP"""""""  ,adPPPPP88  8b       88  8PP"""""""  88          
    88        88  "8b,   ,aa  88,    ,88  "8a,   ,d88  "8b,   ,aa  88          
    88        88   `"Ybbd8"'  `"8bbdP"Y8   `"8bbdP"Y8   `"Ybbd8"'  88          



*/

#if defined _INC_SAMP_Community_fixes
	#endinput
#endif
#define _INC_SAMP_Community_fixes

#if !defined _inc_fixes
	#define _inc_fixes
#endif

#pragma tabsize 4
#pragma semicolon 1
#pragma ctrlchar '\\'
#pragma rational Float

#define _FIXES_ENUM enum

#if (__Pawn & 0x0F) >= 0x0A
	#define _FIXES_NEW_COMPILER (1)
#else
	#define _FIXES_NEW_COMPILER (0)
#endif

#if _FIXES_NEW_COMPILER
	#if defined __PawnBuild
		// Extra flags.
		#if __PawnBuild >= 4
			#pragma option -(+
		#endif
		
		// Use `static enum` if it is available.
		#if __PawnBuild >= 2
			#undef _FIXES_ENUM
			#define _FIXES_ENUM static enum
		#endif
	#endif
	
	// Stupid "warning" that should not exist ever.
	#pragma warning push
	#pragma warning disable 207
	#pragma disablerecursion
	#pragma warning pop
#endif

// Detect compiling on open.mp.
#if !defined OPEN_MP
	// Try them all until one sticks.  If we already included one these
	// repeat includes are internally short-circuited, so no harm done.
#if !defined _samp_included
	#tryinclude <a_samp>
	#tryinclude "a_samp"
#endif
#if !defined _samp_included
	#tryinclude <a_npc>
	#tryinclude "a_npc"
#endif
#if !defined _samp_included
	#error Could not find a_samp.inc
#endif
	#if defined SendClientMessage
		#define _FIXES_NPC 0
		// Do nothing.
	#elseif defined GetDistanceFromMeToPoint
		#define _FIXES_NPC 1
	#elseif defined GetDistanceFromMeToPoint__
		#define _FIXES_NPC 1
	#else
		#error Could not determine script include type - <a_samp> or <a_npc>
	#endif
	#define _FIXES_SAMP 1
	#define _FIXES_OMP 0
#elseif defined OPENMP_SAMP
	// Backwards-compatible development mode.
	#if defined OPENMP_COMPAT
		#define _FIXES_SAMP 1
	#else
		#define _FIXES_SAMP 0
	#endif
	#define _FIXES_OMP 1
	#define _FIXES_NPC 0
#else
	#error fixes.inc is not required for open.mp
#endif

/**
 * <remarks>
 * Creates fake functions that Pawndoc comments can be attached to in the
 * first compilation phase, before the real macros are created.  Macros
 * can't have documentation comments, but why not?  They need documenting...
 * Used internally as <c>_FIXES_SHOW_PAWNDOC</c>.
 * </remarks>
 */
#if defined _FIXES_DetermineOS
	#define _FIXES_SHOW_PAWNDOC(%0)%1\10;
#else
	// First compiler pass only.
	#define _FIXES_SHOW_PAWNDOC(%0)%1\10; static stock %0 %1 const __PAWNDOC:_PD@%0 = 1;
#endif

// Convert functions to constants.
#define __PAWNDOC:%0(%1); __PAWNDOC:%0;

// Strip tags and spaces.
#define _PD@%0\32; _PD@
#define _PD@bool: _PD@
#define _PD@Float: _PD@
#define _PD@File: _PD@

// All other `_FIXES_SHOW_PAWNDOC`s go before their definition, this one goes
// after, because it needs itself to be defined first.  To avoid the problem of
// redefinition, it this defines the name as `SHOW_PAWNDOC` instead.
_FIXES_SHOW_PAWNDOC(SHOW_PAWNDOC(const symbol[])) {}

/**
 * <remarks>
 * Create a <c>const</c> that is never used, which has pawndoc documentation
 * attached to it.  This seems to be the best way to prevent the documentation
 * from appearing in XML (<c>-r</c>) output - even conditional compilation
 * doesn't work on comments.  Used internally as <c>_FIXES_HIDE_PAWNDOC</c>.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(HIDE_PAWNDOC(const symbol[])) {}
#define _FIXES_HIDE_PAWNDOC(%0); const _PX@%0 = 0;
#define _PX@%0\32; _PX@

/**
 * <remarks>
 * Check if the symbol is undefined, or only defined because of a first pass
 * pawndoc macro.  Used internally as <c>_FIXES_IS_DEFINED</c>.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:IS_DEFINED(const symbol[])) {}
#define _FIXES_IS_DEFINED(%0) ((defined %0) && !(defined _PD@%0))
#define _PD@%0\32; _PD@

/**
 * <remarks>
 * <p>Test if something is defined, but without a value.  For example:</p>
 *
 * <code>
 *     #define FIX_AddMenuItem
 * </code>
 *
 * <p>Instead of:</p>
 *
 * <code>
 *     #define FIX_AddMenuItem 1
 * </code>
 *
 * <p>Exploits the fact that <c>FIX_AddMenuItem - 1</c> is valid in both cases.
 * When a value is set this becomes (say) <c>0 - 1</c>, i.e. a sum.  When it
 * isn't set this becomes <c>-1</c>, i.e. just the unary value <c>-1</c>.  Also
 * exploits operator precedence - <c>2 * 0 - 1</c> is not the same as
 * <c>2 * (0 - 1)</c>.  The former is <c>-1</c>, the latter is <c>-2</c>.  The
 * expression is never true for any real number (it might be for complex
 * expressions that change the evaluation order).  This can be shown be trying
 * to solve <c>2n - 1 = 2(n - 1)</c> - you end up trying to prove that
 * <c>n = n - 0.5</c>, a contradiction.  Q.E.D.</p>
 *
 * <p>Conversely, when no value is given this becomes <c>2 * -1 = 2 * (-1)</c>,
 * which is trivially correct.</p>
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_IS_UNSET(const symbol[])) {}
#define _FIXES_IS_UNSET(%0) ((2*%0-1)==2*(%0-1))

/*

     ad88888ba                                 88                                       
    d8"     "8b                ,d       ,d     ""                                       
    Y8,                        88       88                                              
    `Y8aaaaa,     ,adPPYba,  MM88MMM  MM88MMM  88  8b,dPPYba,    ,adPPYb,d8  ,adPPYba,  
      `"""""8b,  a8P_____88    88       88     88  88P'   `"8a  a8"    `Y88  I8[    ""  
            `8b  8PP"""""""    88       88     88  88       88  8b       88   `"Y8ba,   
    Y8a     a8P  "8b,   ,aa    88,      88,    88  88       88  "8a,   ,d88  aa    ]8I  
     "Y88888P"    `"Ybbd8"'    "Y888    "Y888  88  88       88   `"YbbdP"Y8  `"YbbdP"'  
                                                                 aa,    ,88             
                                                                  "Y8bbdP"              


*/

/**
 * <remarks>
 * Enable everything, even things that probably shouldn't be enabled.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_EnableAll)
	_FIXES_SHOW_PAWNDOC(FIXES_EnableAll);
	#define FIXES_EnableAll                      (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableAll)
	#undef FIXES_EnableAll
	_FIXES_SHOW_PAWNDOC(FIXES_EnableAll);
	#define FIXES_EnableAll                      (2)
#elseif FIXES_EnableAll
	#undef FIXES_EnableAll
	_FIXES_SHOW_PAWNDOC(FIXES_EnableAll);
	#define FIXES_EnableAll                      (1)
#else
	#undef FIXES_EnableAll
	_FIXES_SHOW_PAWNDOC(FIXES_EnableAll);
	#define FIXES_EnableAll                      (0)
#endif

/**
 * <remarks>
 * Enable deprecated fixes - those that are no longer needed.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_EnableDeprecated)
	_FIXES_SHOW_PAWNDOC(FIXES_EnableDeprecated);
	#define FIXES_EnableDeprecated               (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableDeprecated)
	#undef FIXES_EnableDeprecated
	_FIXES_SHOW_PAWNDOC(FIXES_EnableDeprecated);
	#define FIXES_EnableDeprecated               (2)
#elseif FIXES_EnableDeprecated
	#undef FIXES_EnableDeprecated
	_FIXES_SHOW_PAWNDOC(FIXES_EnableDeprecated);
	#define FIXES_EnableDeprecated               (1)
#else
	#undef FIXES_EnableDeprecated
	_FIXES_SHOW_PAWNDOC(FIXES_EnableDeprecated);
	#define FIXES_EnableDeprecated               (0)
#endif

/**
 * <remarks>
 * Disable all fixes by default and explicitly enable them.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_DefaultDisabled)
	_FIXES_SHOW_PAWNDOC(FIXES_DefaultDisabled);
	#define FIXES_DefaultDisabled                (0)
	#define _FIXES_DEFAULT                       (1)
#elseif _FIXES_IS_UNSET(FIXES_DefaultDisabled)
	#undef FIXES_DefaultDisabled
	_FIXES_SHOW_PAWNDOC(FIXES_DefaultDisabled);
	#define FIXES_DefaultDisabled                (2)
	// If we want things disabled by default and everything enabled, do it.
	#define _FIXES_DEFAULT                       FIXES_EnableAll
#elseif FIXES_DefaultDisabled
	#undef FIXES_DefaultDisabled
	_FIXES_SHOW_PAWNDOC(FIXES_DefaultDisabled);
	#define FIXES_DefaultDisabled                (1)
	#define _FIXES_DEFAULT                       (0)
#else
	#undef FIXES_DefaultDisabled
	_FIXES_SHOW_PAWNDOC(FIXES_DefaultDisabled);
	#define FIXES_DefaultDisabled                (0)
	#define _FIXES_DEFAULT                       (1)
#endif

/**
 * <remarks>
 * Explicitly enable or disable all fixes, with warnings for the rest.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_ExplicitOptions)
	_FIXES_SHOW_PAWNDOC(FIXES_ExplicitOptions);
	#if FIXES_DefaultDisabled
		#define FIXES_ExplicitOptions            (1)
		#define _FIXES_STOCK                     static
	#else
		#define FIXES_ExplicitOptions            (0)
		#define _FIXES_STOCK                     static stock
	#endif
#elseif _FIXES_IS_UNSET(FIXES_ExplicitOptions)
	#undef FIXES_ExplicitOptions
	_FIXES_SHOW_PAWNDOC(FIXES_ExplicitOptions);
	#define FIXES_ExplicitOptions                (2)
	#define _FIXES_STOCK                         static
#elseif FIXES_ExplicitOptions
	#undef FIXES_ExplicitOptions
	_FIXES_SHOW_PAWNDOC(FIXES_ExplicitOptions);
	#define FIXES_ExplicitOptions                (1)
	#define _FIXES_STOCK                         static
#else
	#undef FIXES_ExplicitOptions
	_FIXES_SHOW_PAWNDOC(FIXES_ExplicitOptions);
	#define FIXES_ExplicitOptions                (0)
	#define _FIXES_STOCK                         static stock
#endif

/**
 * <remarks>
 * If this define is set to 1, then players will not be given a message when
 * they are kicked for cheats, instead they will just loose connection to the
 * server.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_SilentKick)
	_FIXES_SHOW_PAWNDOC(FIXES_SilentKick);
	#define FIXES_SilentKick                     (0)
#elseif _FIXES_IS_UNSET(FIXES_SilentKick)
	#undef FIXES_SilentKick
	_FIXES_SHOW_PAWNDOC(FIXES_SilentKick);
	#define FIXES_SilentKick                     (2)
#elseif FIXES_SilentKick
	#undef FIXES_SilentKick
	_FIXES_SHOW_PAWNDOC(FIXES_SilentKick);
	#define FIXES_SilentKick                     (1)
#else
	#undef FIXES_SilentKick
	_FIXES_SHOW_PAWNDOC(FIXES_SilentKick);
	#define FIXES_SilentKick                     (0)
#endif

/**
 * <remarks>
 * If this define is set to 1, then debug printing is turned on for any
 * functions which may use it.  Otherwise, the compiler entirely removes the
 * code to print anything, leaving 0 run-time overhead.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_Debug)
	_FIXES_SHOW_PAWNDOC(FIXES_Debug);
	#define FIXES_Debug                          (0)
	#define FIXES_PRINTF(%0);
#elseif _FIXES_IS_UNSET(FIXES_Debug)
	#undef FIXES_Debug
	_FIXES_SHOW_PAWNDOC(FIXES_Debug);
	#define FIXES_Debug                          (2)
	#define FIXES_PRINTF                         _FIXES_PRINTF
#elseif FIXES_Debug
	#undef FIXES_Debug
	_FIXES_SHOW_PAWNDOC(FIXES_Debug);
	#define FIXES_Debug                          (1)
	#define FIXES_PRINTF                         _FIXES_PRINTF
#else
	#undef FIXES_Debug
	_FIXES_SHOW_PAWNDOC(FIXES_Debug);
	#define FIXES_Debug                          (0)
	#define FIXES_PRINTF(%0);
#endif

/**
 * <remarks>
 * If this define is set to 1, then the old style include is used, with no
 * support for multiple scripts running at the same time on the server (i.e. no
 * gamemodes and filter scripts at the same time).  You can only have one or the
 * other or bugs.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_Single)
	_FIXES_SHOW_PAWNDOC(FIXES_Single);
	#define FIXES_Single                         (0)
#elseif _FIXES_IS_UNSET(FIXES_Single)
	#undef FIXES_Single
	_FIXES_SHOW_PAWNDOC(FIXES_Single);
	#define FIXES_Single                         (2)
#elseif FIXES_Single
	#undef FIXES_Single
	_FIXES_SHOW_PAWNDOC(FIXES_Single);
	#define FIXES_Single                         (1)
#else
	#undef FIXES_Single
	_FIXES_SHOW_PAWNDOC(FIXES_Single);
	#define FIXES_Single                         (0)
#endif

/**
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>FIXES_Single</see> is set, but the script isn't REALLY the only one.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_SingleMsg)
	_FIXES_SHOW_PAWNDOC(FIXES_SingleMsg);
	#define FIXES_SingleMsg                      (0)
#elseif _FIXES_IS_UNSET(FIXES_SingleMsg)
	#undef FIXES_SingleMsg
	_FIXES_SHOW_PAWNDOC(FIXES_SingleMsg);
	#define FIXES_SingleMsg                      (2)
#elseif FIXES_SingleMsg
	#undef FIXES_SingleMsg
	_FIXES_SHOW_PAWNDOC(FIXES_SingleMsg);
	#define FIXES_SingleMsg                      (1)
#else
	#undef FIXES_SingleMsg
	_FIXES_SHOW_PAWNDOC(FIXES_SingleMsg);
	#define FIXES_SingleMsg                      (0)
#endif

/**
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>GetServerVarAsString</see> and related functions are used without a
 * valid directory redirect.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_ServerVarMsg)
	_FIXES_SHOW_PAWNDOC(FIXES_ServerVarMsg);
	#define FIXES_ServerVarMsg                   (0)
#elseif _FIXES_IS_UNSET(FIXES_ServerVarMsg)
	#undef FIXES_ServerVarMsg
	_FIXES_SHOW_PAWNDOC(FIXES_ServerVarMsg);
	#define FIXES_ServerVarMsg                   (2)
#elseif FIXES_ServerVarMsg
	#undef FIXES_ServerVarMsg
	_FIXES_SHOW_PAWNDOC(FIXES_ServerVarMsg);
	#define FIXES_ServerVarMsg                   (1)
#else
	#undef FIXES_ServerVarMsg
	_FIXES_SHOW_PAWNDOC(FIXES_ServerVarMsg);
	#define FIXES_ServerVarMsg                   (0)
#endif

/**
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>GetMaxPlayer</see> doesn't match <c>MAX_PLAYERS</c>.
 * </remarks>
 */

#if !_FIXES_IS_DEFINED(FIXES_GetMaxPlayersMsg)
	_FIXES_SHOW_PAWNDOC(FIXES_GetMaxPlayersMsg);
	#define FIXES_GetMaxPlayersMsg               (0)
#elseif _FIXES_IS_UNSET(FIXES_GetMaxPlayersMsg)
	#undef FIXES_GetMaxPlayersMsg
	_FIXES_SHOW_PAWNDOC(FIXES_GetMaxPlayersMsg);
	#define FIXES_GetMaxPlayersMsg               (2)
#elseif FIXES_GetMaxPlayersMsg
	#undef FIXES_GetMaxPlayersMsg
	_FIXES_SHOW_PAWNDOC(FIXES_GetMaxPlayersMsg);
	#define FIXES_GetMaxPlayersMsg               (1)
#else
	#undef FIXES_GetMaxPlayersMsg
	_FIXES_SHOW_PAWNDOC(FIXES_GetMaxPlayersMsg);
	#define FIXES_GetMaxPlayersMsg               (0)
#endif

/*

      ,ad8888ba,                         88                                       
     d8"'    `"8b                 ,d     ""                                       
    d8'        `8b                88                                              
    88          88  8b,dPPYba,  MM88MMM  88   ,adPPYba,   8b,dPPYba,   ,adPPYba,  
    88          88  88P'    "8a   88     88  a8"     "8a  88P'   `"8a  I8[    ""  
    Y8,        ,8P  88       d8   88     88  8b       d8  88       88   `"Y8ba,   
     Y8a.    .a8P   88b,   ,a8"   88,    88  "8a,   ,a8"  88       88  aa    ]8I  
      `"Y8888Y"'    88`YbbdP"'    "Y888  88   `"YbbdP"'   88       88  `"YbbdP"'  
                    88                                                            
                    88                                                            

*/

// We can add server version compiler code here to only compile fixes that apply
// to the version of the includes for which the user is compiling.

// Controls multiple other fixes.
#if !defined FIX_API
	_FIXES_STOCK FIX_API = _FIXES_DEFAULT;
	#define FIX_API                              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_API)
	#undef FIX_API
	#define FIX_API                              (2)
#endif

// Controls multiple other fixes.
#if !defined FIX_Natives
	_FIXES_STOCK FIX_Natives = _FIXES_DEFAULT;
	#define FIX_Natives                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Natives)
	#undef FIX_Natives
	#define FIX_Natives                          (2)
#endif

#if !defined FIX_GetPlayerColour
	#if defined FIX_GetPlayerColor
		#if _FIXES_IS_UNSET(FIX_GetPlayerColor)
			#define FIX_GetPlayerColour          (2)
		#else
			#define FIX_GetPlayerColour          (FIX_GetPlayerColor)
		#endif
	#else
		_FIXES_STOCK FIX_GetPlayerColour = _FIXES_DEFAULT;
		#define FIX_GetPlayerColour              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerColour)
	#undef FIX_GetPlayerColour
	#define FIX_GetPlayerColour                  (2)
#endif

#if !defined FIX_FILTERSCRIPT
	_FIXES_STOCK FIX_FILTERSCRIPT = _FIXES_DEFAULT;
	#define FIX_FILTERSCRIPT                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_FILTERSCRIPT)
	#undef FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT                     (2)
#endif

#if !defined FIX_SpawnPlayer
	_FIXES_STOCK FIX_SpawnPlayer = _FIXES_DEFAULT;
	#define FIX_SpawnPlayer                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SpawnPlayer)
	#undef FIX_SpawnPlayer
	#define FIX_SpawnPlayer                      (2)
#endif

#if !defined FIX_SetPlayerName
	_FIXES_STOCK FIX_SetPlayerName = _FIXES_DEFAULT;
	#define FIX_SetPlayerName                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerName)
	#undef FIX_SetPlayerName
	#define FIX_SetPlayerName                    (2)
#endif

#if !defined FIX_GetPlayerSkin
	_FIXES_STOCK FIX_GetPlayerSkin = _FIXES_DEFAULT;
	#define FIX_GetPlayerSkin                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerSkin)
	#undef FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin                    (2)
#endif

#if !defined FIX_GetWeaponName
	#if defined GetVehicleParamsSirenState
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetWeaponName = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetWeaponName                FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetWeaponName = _FIXES_DEFAULT;
		#define FIX_GetWeaponName                _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWeaponName)
	#undef FIX_GetWeaponName
	#define FIX_GetWeaponName                    (2)
#endif

#if !defined FIX_SetPlayerWorldBounds
	_FIXES_STOCK FIX_SetPlayerWorldBounds = _FIXES_DEFAULT;
	#define FIX_SetPlayerWorldBounds             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerWorldBounds)
	#undef FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds             (2)
#endif

#if !defined FIX_TogglePlayerControllable
	#if defined SetObjectMaterial
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_TogglePlayerControllable = FIXES_EnableDeprecated;
		#endif
		#define FIX_TogglePlayerControllable     FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_TogglePlayerControllable = _FIXES_DEFAULT;
		#define FIX_TogglePlayerControllable     _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
	#undef FIX_TogglePlayerControllable
	#define FIX_TogglePlayerControllable         (2)
#endif

#if !defined FIX_HydraSniper
	_FIXES_STOCK FIX_HydraSniper = _FIXES_DEFAULT;
	#define FIX_HydraSniper                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_HydraSniper)
	#undef FIX_HydraSniper
	#define FIX_HydraSniper                      (2)
#endif

#if !defined FIX_IsPlayerInCheckpoint
	_FIXES_STOCK FIX_IsPlayerInCheckpoint = _FIXES_DEFAULT;
	#define FIX_IsPlayerInCheckpoint             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInCheckpoint)
	#undef FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint             (2)
#endif

#if !defined FIX_IsPlayerInRaceCheckpoint
	_FIXES_STOCK FIX_IsPlayerInRaceCheckpoint = _FIXES_DEFAULT;
	#define FIX_IsPlayerInRaceCheckpoint         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInRaceCheckpoint)
	#undef FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint         (2)
#endif

#if !defined FIX_GetPlayerWeapon
	_FIXES_STOCK FIX_GetPlayerWeapon = _FIXES_DEFAULT;
	#define FIX_GetPlayerWeapon                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeapon)
	#undef FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon                  (2)
#endif

#if !defined FIX_PutPlayerInVehicle
	_FIXES_STOCK FIX_PutPlayerInVehicle = _FIXES_DEFAULT;
	#define FIX_PutPlayerInVehicle               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PutPlayerInVehicle)
	#undef FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle               (2)
#endif

#if !defined FIX_KEY_AIM
	#if defined KEY_AIM
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_KEY_AIM = FIXES_EnableDeprecated;
		#endif
		#define FIX_KEY_AIM                      FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_KEY_AIM = _FIXES_DEFAULT;
		#define FIX_KEY_AIM                      _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_KEY_AIM)
	#undef FIX_KEY_AIM
	#define FIX_KEY_AIM                          (2)
#endif

#if !defined FIX_SPECIAL_ACTION_PISSING
	#if defined SPECIAL_ACTION_PISSING
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_SPECIAL_ACTION_PISSING = FIXES_EnableDeprecated;
		#endif
		#define FIX_SPECIAL_ACTION_PISSING       FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_SPECIAL_ACTION_PISSING = _FIXES_DEFAULT;
		#define FIX_SPECIAL_ACTION_PISSING       _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SPECIAL_ACTION_PISSING)
	#undef FIX_SPECIAL_ACTION_PISSING
	#define FIX_SPECIAL_ACTION_PISSING           (2)
#endif

#if !defined FIX_IsValidVehicle
	#if defined IsValidVehicle
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_IsValidVehicle = FIXES_EnableDeprecated;
		#endif
		#define FIX_IsValidVehicle               FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_IsValidVehicle = FIX_Natives;
	#define FIX_IsValidVehicle               FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_IsValidVehicle)
	#undef FIX_IsValidVehicle
	#define FIX_IsValidVehicle                   (2)
#endif

#if !defined FIX_GetGravity
	#if defined GetGravity
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetGravity = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetGravity                   FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetGravity = FIX_Natives;
		#define FIX_GetGravity                   FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetGravity)
	#undef FIX_GetGravity
	#define FIX_GetGravity                       (2)
#endif

#if !defined FIX_gpci
	#if defined gpci
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_gpci = FIXES_EnableDeprecated;
		#endif
		#define FIX_gpci                         FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_gpci = FIX_Natives;
		#define FIX_gpci                         FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_gpci)
	#undef FIX_gpci
	#define FIX_gpci                             (2)
#endif

#if !defined FIX_WEAPONS
	#if defined WEAPON_FIST
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_WEAPONS = FIXES_EnableDeprecated;
		#endif
		#define FIX_WEAPONS                      FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_WEAPONS = _FIXES_DEFAULT;
		#define FIX_WEAPONS                      _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_WEAPONS)
	#undef FIX_WEAPONS
	#define FIX_WEAPONS                          (2)
#endif

#if !defined FIX_BODYPARTS
	#if defined BODY_PART_LEFT_ARM
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_BODYPARTS = FIXES_EnableDeprecated;
		#endif
		#define FIX_BODYPARTS                    FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_BODYPARTS = _FIXES_DEFAULT;
		#define FIX_BODYPARTS                    _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_BODYPARTS)
	#undef FIX_BODYPARTS
	#define FIX_BODYPARTS                        (2)
#endif

#if !defined FIX_CAMERAMODES
	#if defined CAM_MODE_NONE
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_CAMERAMODES = FIXES_EnableDeprecated;
		#endif
		#define FIX_CAMERAMODES                  FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_CAMERAMODES = _FIXES_DEFAULT;
		#define FIX_CAMERAMODES                  _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_CAMERAMODES)
	#undef FIX_CAMERAMODES
	#define FIX_CAMERAMODES                      (2)
#endif

#if !defined FIX_DriveBy
	_FIXES_STOCK FIX_DriveBy = _FIXES_DEFAULT;
	#define FIX_DriveBy                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_DriveBy)
	#undef FIX_DriveBy
	#define FIX_DriveBy                          (2)
#endif

#if !defined FIX_SilentTeleport
	_FIXES_STOCK FIX_SilentTeleport = _FIXES_DEFAULT;
	#define FIX_SilentTeleport                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SilentTeleport)
	#undef FIX_SilentTeleport
	#define FIX_SilentTeleport                   (2)
#endif

#if !defined FIX_SetPlayerCheckpoint
	_FIXES_STOCK FIX_SetPlayerCheckpoint = _FIXES_DEFAULT;
	#define FIX_SetPlayerCheckpoint              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCheckpoint)
	#undef FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint              (2)
#endif

#if !defined FIX_SetPlayerRaceCheckpoint
	_FIXES_STOCK FIX_SetPlayerRaceCheckpoint = _FIXES_DEFAULT;
	#define FIX_SetPlayerRaceCheckpoint          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerRaceCheckpoint)
	#undef FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint          (2)
#endif

#if !defined FIX_TextDrawCreate
	_FIXES_STOCK FIX_TextDrawCreate = _FIXES_DEFAULT;
	#define FIX_TextDrawCreate                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate)
	#undef FIX_TextDrawCreate
	#define FIX_TextDrawCreate                   (2)
#endif

#if !defined FIX_AttachTrailerToVehicle
	_FIXES_STOCK FIX_AttachTrailerToVehicle = _FIXES_DEFAULT;
	#define FIX_AttachTrailerToVehicle                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_AttachTrailerToVehicle)
	#undef FIX_AttachTrailerToVehicle
	#define FIX_AttachTrailerToVehicle                   (2)
#endif

#if !defined FIX_GetVehicleComponentInSlot
	_FIXES_STOCK FIX_GetVehicleComponentInSlot = _FIXES_DEFAULT;
	#define FIX_GetVehicleComponentInSlot        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetVehicleComponentInSlot)
	#undef FIX_GetVehicleComponentInSlot
	#define FIX_GetVehicleComponentInSlot        (2)
#endif

#if !defined FIX_TextDrawCreate_2
	_FIXES_STOCK FIX_TextDrawCreate_2 = _FIXES_DEFAULT;
	#define FIX_TextDrawCreate_2                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate_2)
	#undef FIX_TextDrawCreate_2
	#define FIX_TextDrawCreate_2                 (2)
#endif

#if !defined FIX_TextDrawSetString
	_FIXES_STOCK FIX_TextDrawSetString = _FIXES_DEFAULT;
	#define FIX_TextDrawSetString                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString)
	#undef FIX_TextDrawSetString
	#define FIX_TextDrawSetString                (2)
#endif

#if !defined FIX_TextDrawSetString_2
	_FIXES_STOCK FIX_TextDrawSetString_2 = _FIXES_DEFAULT;
	#define FIX_TextDrawSetString_2              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString_2)
	#undef FIX_TextDrawSetString_2
	#define FIX_TextDrawSetString_2              (2)
#endif

#if !defined FIX_AllowInteriorWeapons
	_FIXES_STOCK FIX_AllowInteriorWeapons = _FIXES_DEFAULT;
	#define FIX_AllowInteriorWeapons             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_AllowInteriorWeapons)
	#undef FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons             (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle
	#if defined OnPlayerClickMap
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_OnPlayerEnterVehicle = FIXES_EnableDeprecated;
		#endif
		#define FIX_OnPlayerEnterVehicle         FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_OnPlayerEnterVehicle = _FIXES_DEFAULT;
		#define FIX_OnPlayerEnterVehicle         _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle)
	#undef FIX_OnPlayerEnterVehicle
	#define FIX_OnPlayerEnterVehicle             (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle_2
	_FIXES_STOCK FIX_OnPlayerEnterVehicle_2 = _FIXES_DEFAULT;
	#define FIX_OnPlayerEnterVehicle_2           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_2)
	#undef FIX_OnPlayerEnterVehicle_2
	#define FIX_OnPlayerEnterVehicle_2           (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle_3
	_FIXES_STOCK FIX_OnPlayerEnterVehicle_3 = _FIXES_DEFAULT;
	#define FIX_OnPlayerEnterVehicle_3           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_3)
	#undef FIX_OnPlayerEnterVehicle_3
	#define FIX_OnPlayerEnterVehicle_3           (2)
#endif

#if !defined FIX_AllowTeleport
	#if defined OnPlayerClickMap
		_FIXES_STOCK FIX_AllowTeleport = _FIXES_DEFAULT;
		#define FIX_AllowTeleport                _FIXES_DEFAULT
	#else
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_AllowTeleport = FIXES_EnableDeprecated;
		#endif
		#define FIX_AllowTeleport                FIXES_EnableDeprecated
	#endif
#elseif _FIXES_IS_UNSET(FIX_AllowTeleport)
	#undef FIX_AllowTeleport
	#define FIX_AllowTeleport                    (2)
#endif

#if !defined FIX_SetPlayerSpecialAction
	_FIXES_STOCK FIX_SetPlayerSpecialAction = _FIXES_DEFAULT;
	#define FIX_SetPlayerSpecialAction           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSpecialAction)
	#undef FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction           (2)
#endif

#if !defined FIX_ClearAnimations
	_FIXES_STOCK FIX_ClearAnimations = _FIXES_DEFAULT;
	#define FIX_ClearAnimations                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations)
	#undef FIX_ClearAnimations
	#define FIX_ClearAnimations                  (2)
#endif

#if !defined FIX_ClearAnimations_2
	_FIXES_STOCK FIX_ClearAnimations_2 = _FIXES_DEFAULT;
	#define FIX_ClearAnimations_2                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations_2)
	#undef FIX_ClearAnimations_2
	#define FIX_ClearAnimations_2                (2)
#endif

#if !defined FIX_GangZoneCreate
	_FIXES_STOCK FIX_GangZoneCreate = _FIXES_DEFAULT;
	#define FIX_GangZoneCreate                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GangZoneCreate)
	#undef FIX_GangZoneCreate
	#define FIX_GangZoneCreate                   (2)
#endif

#if !defined FIX_OnDialogResponse
	#if defined GetVehicleModelInfo
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_OnDialogResponse = FIXES_EnableDeprecated;
		#endif
		#define FIX_OnDialogResponse             FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_OnDialogResponse = _FIXES_DEFAULT;
		#define FIX_OnDialogResponse             _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnDialogResponse)
	#undef FIX_OnDialogResponse
	#define FIX_OnDialogResponse                 (2)
#endif

#if !defined FIX_GetPlayerDialog
	#if defined GetPlayerDialog
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetPlayerDialog = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetPlayerDialog              FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetPlayerDialog = FIX_API;
		#define FIX_GetPlayerDialog              FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerDialog)
	#undef FIX_GetPlayerDialog
	#define FIX_GetPlayerDialog                  (2)
#endif

#if !defined FIX_PlayerDialogResponse
	_FIXES_STOCK FIX_PlayerDialogResponse = _FIXES_DEFAULT;
	#define FIX_PlayerDialogResponse             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerDialogResponse)
	#undef FIX_PlayerDialogResponse
	#define FIX_PlayerDialogResponse             (2)
#endif

#if !defined FIX_SetSpawnInfo
	#if defined GetPlayerVersion
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_SetSpawnInfo = FIXES_EnableDeprecated;
		#endif
		#define FIX_SetSpawnInfo                 FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_SetSpawnInfo = _FIXES_DEFAULT;
		#define FIX_SetSpawnInfo                 _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo)
	#undef FIX_SetSpawnInfo
	#define FIX_SetSpawnInfo                     (2)
#endif

#if !defined FIX_SetSpawnInfo_2
	_FIXES_STOCK FIX_SetSpawnInfo_2 = _FIXES_DEFAULT;
	#define FIX_SetSpawnInfo_2                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo_2)
	#undef FIX_SetSpawnInfo_2
	#define FIX_SetSpawnInfo_2                   (2)
#endif

#if !defined FIX_SetPlayerSkin
	_FIXES_STOCK FIX_SetPlayerSkin = _FIXES_DEFAULT;
	#define FIX_SetPlayerSkin                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSkin)
	#undef FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin                    (2)
#endif

#if !defined FIX_HideMenuForPlayer
	_FIXES_STOCK FIX_HideMenuForPlayer = _FIXES_DEFAULT;
	#define FIX_HideMenuForPlayer                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (2)
#endif

#if !defined FIX_valstr
	_FIXES_STOCK FIX_valstr = _FIXES_DEFAULT;
	#define FIX_valstr                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_valstr)
	#undef FIX_valstr
	#define FIX_valstr                           (2)
#endif

#if !defined FIX_file_inc
	_FIXES_STOCK FIX_file_inc = _FIXES_DEFAULT;
	#define FIX_file_inc                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_file_inc)
	#undef FIX_file_inc
	#define FIX_file_inc                         (2)
#endif

#if !defined FIX_fclose
	#define FIX_fclose                           (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fclose)
	#undef FIX_fclose
	#define FIX_fclose                           (2)
#endif

#if !defined FIX_fwrite
	#define FIX_fwrite                           (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fwrite)
	#undef FIX_fwrite
	#define FIX_fwrite                           (2)
#endif

#if !defined FIX_fread
	#define FIX_fread                            (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fread)
	#undef FIX_fread
	#define FIX_fread                            (2)
#endif

#if !defined FIX_fputchar
	#define FIX_fputchar                         (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fputchar)
	#undef FIX_fputchar
	#define FIX_fputchar                         (2)
#endif

#if !defined FIX_fgetchar
	#define FIX_fgetchar                         (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fgetchar)
	#undef FIX_fgetchar
	#define FIX_fgetchar                         (2)
#endif

#if !defined FIX_fblockwrite
	#define FIX_fblockwrite                      (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockwrite)
	#undef FIX_fblockwrite
	#define FIX_fblockwrite                      (2)
#endif

#if !defined FIX_fblockread
	#define FIX_fblockread                       (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockread)
	#undef FIX_fblockread
	#define FIX_fblockread                       (2)
#endif

#if !defined FIX_fseek
	#define FIX_fseek                            (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fseek)
	#undef FIX_fseek
	#define FIX_fseek                            (2)
#endif

#if !defined FIX_flength
	#define FIX_flength                          (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_flength)
	#undef FIX_flength
	#define FIX_flength                          (2)
#endif

#if !defined FIX_SetPlayerAttachedObject
	_FIXES_STOCK FIX_SetPlayerAttachedObject = _FIXES_DEFAULT;
	#define FIX_SetPlayerAttachedObject          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerAttachedObject)
	#undef FIX_SetPlayerAttachedObject
	#define FIX_SetPlayerAttachedObject          (2)
#endif

#if !defined FIX_OnPlayerDeath
	_FIXES_STOCK FIX_OnPlayerDeath = _FIXES_DEFAULT;
	#define FIX_OnPlayerDeath                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDeath)
	#undef FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath                    (2)
#endif

#if !defined FIX_strins
	_FIXES_STOCK FIX_strins = _FIXES_DEFAULT;
	#define FIX_strins                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strins)
	#undef FIX_strins
	#define FIX_strins                           (2)
#endif

#if !defined FIX_IsPlayerConnected
	_FIXES_STOCK FIX_IsPlayerConnected = _FIXES_DEFAULT;
	#define FIX_IsPlayerConnected                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerConnected)
	#undef FIX_IsPlayerConnected
	#define FIX_IsPlayerConnected                (2)
#endif

#if !defined FIX_TrainExit
	_FIXES_STOCK FIX_TrainExit = _FIXES_DEFAULT;
	#define FIX_TrainExit                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TrainExit)
	#undef FIX_TrainExit
	#define FIX_TrainExit                        (2)
#endif

#if !defined FIX_Kick
	#if defined EnableVehicleFriendlyFire
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_Kick = FIXES_EnableDeprecated;
		#endif
		#define FIX_Kick                         FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_Kick = _FIXES_DEFAULT;
		#define FIX_Kick                         _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_Kick)
	#undef FIX_Kick
	#define FIX_Kick                             (2)
#endif

#if !defined FIX_OnVehicleMod
	_FIXES_STOCK FIX_OnVehicleMod = _FIXES_DEFAULT;
	#define FIX_OnVehicleMod                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnVehicleMod)
	#undef FIX_OnVehicleMod
	#define FIX_OnVehicleMod                     (2)
#endif

#if !defined FIX_random
	_FIXES_STOCK FIX_random = _FIXES_DEFAULT;
	#define FIX_random                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_random)
	#undef FIX_random
	#define FIX_random                           (2)
#endif

#if !defined FIX_sleep
	_FIXES_STOCK FIX_sleep = _FIXES_DEFAULT;
	#define FIX_sleep                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_sleep)
	#undef FIX_sleep
	#define FIX_sleep                            (2)
#endif

#if !defined FIX_Menus
	_FIXES_STOCK FIX_Menus = _FIXES_DEFAULT;
	#define FIX_Menus                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Menus)
	#undef FIX_Menus
	#define FIX_Menus                            (2)
#endif

#if !defined FIX_AddMenuItem
	_FIXES_STOCK FIX_AddMenuItem = FIX_Menus;
	#define FIX_AddMenuItem                      FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_AddMenuItem)
	#undef FIX_AddMenuItem
	#define FIX_AddMenuItem                      (2)
#endif

#if !defined FIX_SetMenuColumnHeader
	_FIXES_STOCK FIX_SetMenuColumnHeader = FIX_Menus;
	#define FIX_SetMenuColumnHeader              FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_SetMenuColumnHeader)
	#undef FIX_SetMenuColumnHeader
	#define FIX_SetMenuColumnHeader              (2)
#endif

#if !defined FIX_ShowMenuForPlayer
	_FIXES_STOCK FIX_ShowMenuForPlayer = FIX_Menus;
	#define FIX_ShowMenuForPlayer                FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_ShowMenuForPlayer)
	#undef FIX_ShowMenuForPlayer
	#define FIX_ShowMenuForPlayer                (2)
#endif

#if !defined FIX_HideMenuForPlayer
	_FIXES_STOCK FIX_HideMenuForPlayer = FIX_Menus;
	#define FIX_HideMenuForPlayer                FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (2)
#endif

#if !defined FIX_GetPlayerMenu
	_FIXES_STOCK FIX_GetPlayerMenu = _FIXES_DEFAULT;
	#define FIX_GetPlayerMenu                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerMenu)
	#undef FIX_GetPlayerMenu
	#define FIX_GetPlayerMenu                    (2)
#endif

#if !defined FIX_HideMenuForPlayer_2
	_FIXES_STOCK FIX_HideMenuForPlayer_2 = FIXES_EnableAll;
	#define FIX_HideMenuForPlayer_2              FIXES_EnableAll
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer_2)
	#undef FIX_HideMenuForPlayer_2
	#define FIX_HideMenuForPlayer_2              (2)
#elseif FIX_HideMenuForPlayer_2 && !FIX_GetPlayerMenu
	#error FIX_HideMenuForPlayer_2 requires FIX_GetPlayerMenu
#endif

#if !defined FIX_DisableMenu
	_FIXES_STOCK FIX_DisableMenu = FIX_Menus;
	#define FIX_DisableMenu                      FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_DisableMenu)
	#undef FIX_DisableMenu
	#define FIX_DisableMenu                      (2)
#endif

#if !defined FIX_DisableMenuRow
	_FIXES_STOCK FIX_DisableMenuRow = FIX_Menus;
	#define FIX_DisableMenuRow                   FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_DisableMenuRow)
	#undef FIX_DisableMenuRow
	#define FIX_DisableMenuRow                   (2)
#endif

#if !defined FIX_GetPlayerInterior
	_FIXES_STOCK FIX_GetPlayerInterior = _FIXES_DEFAULT;
	#define FIX_GetPlayerInterior                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerInterior)
	#undef FIX_GetPlayerInterior
	#define FIX_GetPlayerInterior                (2)
#endif

#if !defined FIX_ApplyAnimation
	_FIXES_STOCK FIX_ApplyAnimation = _FIXES_DEFAULT;
	#define FIX_ApplyAnimation                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation)
	#undef FIX_ApplyAnimation
	#define FIX_ApplyAnimation                   (2)
#endif

#if !defined FIX_ApplyAnimation_2
	_FIXES_STOCK FIX_ApplyAnimation_2 = _FIXES_DEFAULT;
	#define FIX_ApplyAnimation_2                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation_2)
	#undef FIX_ApplyAnimation_2
	#define FIX_ApplyAnimation_2                 (2)
#endif

#if !defined FIX_ApplyActorAnimation
	_FIXES_STOCK FIX_ApplyActorAnimation = _FIXES_DEFAULT;
	#define FIX_ApplyActorAnimation              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation)
	#undef FIX_ApplyActorAnimation
	#define FIX_ApplyActorAnimation              (2)
#endif

#if !defined FIX_ApplyActorAnimation_2
	_FIXES_STOCK FIX_ApplyActorAnimation_2 = _FIXES_DEFAULT;
	#define FIX_ApplyActorAnimation_2            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation_2)
	#undef FIX_ApplyActorAnimation_2
	#define FIX_ApplyActorAnimation_2            (2)
#endif

#if !defined FIX_OnPlayerSpawn
	_FIXES_STOCK FIX_OnPlayerSpawn = _FIXES_DEFAULT;
	#define FIX_OnPlayerSpawn                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerSpawn)
	#undef FIX_OnPlayerSpawn
	#define FIX_OnPlayerSpawn                    (2)
#endif

#if !defined FIX_GameText
	_FIXES_STOCK FIX_GameText = _FIXES_DEFAULT;
	#define FIX_GameText                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GameText)
	#undef FIX_GameText
	#define FIX_GameText                         (2)
#endif

#if !defined FIX_HideGameText
	#if defined HideGameText
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_HideGameText = FIXES_EnableDeprecated;
		#endif
		#define FIX_HideGameText                 FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_HideGameText = FIX_API;
		#define FIX_HideGameText                 FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_HideGameText)
	#undef FIX_HideGameText
	#define FIX_HideGameText                     (2)
#endif

#if !defined FIX_GetPlayerWorldBounds
	#if defined GetPlayerWorldBounds
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetPlayerWorldBounds = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetPlayerWorldBounds         FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetPlayerWorldBounds = FIX_API;
		#define FIX_GetPlayerWorldBounds         FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWorldBounds)
	#undef FIX_GetPlayerWorldBounds
	#define FIX_GetPlayerWorldBounds             (2)
#endif

#if !defined FIX_ClearPlayerWorldBounds
	#if defined ClearPlayerWorldBounds
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_ClearPlayerWorldBounds = FIXES_EnableDeprecated;
		#endif
		#define FIX_ClearPlayerWorldBounds       FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_ClearPlayerWorldBounds = FIX_API;
		#define FIX_ClearPlayerWorldBounds       FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_ClearPlayerWorldBounds)
	#undef FIX_ClearPlayerWorldBounds
	#define FIX_ClearPlayerWorldBounds           (2)
#endif

#if !defined FIX_GameTextStyles
	_FIXES_STOCK FIX_GameTextStyles = _FIXES_DEFAULT;
	#define FIX_GameTextStyles                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GameTextStyles)
	#undef FIX_GameTextStyles
	#define FIX_GameTextStyles                   (2)
#elseif FIX_GameTextStyles && !FIX_GameText
	#error FIX_GameTextStyles requires FIX_GameText
#endif

#if !defined FIX_OnPlayerConnect
	_FIXES_STOCK FIX_OnPlayerConnect = _FIXES_DEFAULT;
	#define FIX_OnPlayerConnect                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerConnect)
	#undef FIX_OnPlayerConnect
	#define FIX_OnPlayerConnect                  (2)
#endif

#if !defined FIX_OnPlayerDisconnect
	_FIXES_STOCK FIX_OnPlayerDisconnect = _FIXES_DEFAULT;
	#define FIX_OnPlayerDisconnect               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDisconnect)
	#undef FIX_OnPlayerDisconnect
	#define FIX_OnPlayerDisconnect               (2)
#endif

#if !defined FIX_CreatePlayerTextDraw
	_FIXES_STOCK FIX_CreatePlayerTextDraw = _FIXES_DEFAULT;
	#define FIX_CreatePlayerTextDraw             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw)
	#undef FIX_CreatePlayerTextDraw
	#define FIX_CreatePlayerTextDraw             (2)
#endif

#if !defined FIX_CreatePlayerTextDraw_2
	_FIXES_STOCK FIX_CreatePlayerTextDraw_2 = _FIXES_DEFAULT;
	#define FIX_CreatePlayerTextDraw_2           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw_2)
	#undef FIX_CreatePlayerTextDraw_2
	#define FIX_CreatePlayerTextDraw_2           (2)
#endif

#if !defined FIX_PlayerTextDrawSetString
	_FIXES_STOCK FIX_PlayerTextDrawSetString = _FIXES_DEFAULT;
	#define FIX_PlayerTextDrawSetString          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString)
	#undef FIX_PlayerTextDrawSetString
	#define FIX_PlayerTextDrawSetString          (2)
#endif

#if !defined FIX_PlayerTextDrawSetString_2
	_FIXES_STOCK FIX_PlayerTextDrawSetString_2 = _FIXES_DEFAULT;
	#define FIX_PlayerTextDrawSetString_2        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString_2)
	#undef FIX_PlayerTextDrawSetString_2
	#define FIX_PlayerTextDrawSetString_2        (2)
#endif

#if !defined FIX_SetPlayerCamera
	_FIXES_STOCK FIX_SetPlayerCamera = _FIXES_DEFAULT;
	#define FIX_SetPlayerCamera                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCamera)
	#undef FIX_SetPlayerCamera
	#define FIX_SetPlayerCamera                  (2)
#endif

#if !defined FIX_SetPlayerTime
	_FIXES_STOCK FIX_SetPlayerTime = _FIXES_DEFAULT;
	#define FIX_SetPlayerTime                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerTime)
	#undef FIX_SetPlayerTime
	#define FIX_SetPlayerTime                    (2)
#endif

#if !defined FIX_OnPlayerRequestClass
	_FIXES_STOCK FIX_OnPlayerRequestClass = _FIXES_DEFAULT;
	#define FIX_OnPlayerRequestClass             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerRequestClass)
	#undef FIX_OnPlayerRequestClass
	#define FIX_OnPlayerRequestClass             (2)
#endif

#if !defined FIX_SetPlayerColour
	#if defined FIX_SetPlayerColor
		#if _FIXES_IS_UNSET(FIX_SetPlayerColor)
			#define FIX_SetPlayerColour          (2)
		#else
			#define FIX_SetPlayerColour          (FIX_SetPlayerColor)
		#endif
	#else
		_FIXES_STOCK FIX_SetPlayerColour = _FIXES_DEFAULT;
		#define FIX_SetPlayerColour              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetPlayerColour)
	#undef FIX_SetPlayerColour
	#define FIX_SetPlayerColour                  (2)
#endif

#if !defined FIX_FileMaths
	_FIXES_STOCK FIX_FileMaths = _FIXES_DEFAULT;
	#define FIX_FileMaths                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_FileMaths)
	#undef FIX_FileMaths
	#define FIX_FileMaths                        (2)
#endif

#if !defined FIX_GetPlayerWeaponData
	_FIXES_STOCK FIX_GetPlayerWeaponData = _FIXES_DEFAULT;
	#define FIX_GetPlayerWeaponData              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeaponData)
	#undef FIX_GetPlayerWeaponData
	#define FIX_GetPlayerWeaponData              (2)
#endif

#if !defined FIX_strcmp
	_FIXES_STOCK FIX_strcmp = _FIXES_DEFAULT;
	#define FIX_strcmp                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strcmp)
	#undef FIX_strcmp
	#define FIX_strcmp                           (2)
#endif

#if !defined FIX_GetPVarString
	_FIXES_STOCK FIX_GetPVarString = _FIXES_DEFAULT;
	#define FIX_GetPVarString                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPVarString)
	#undef FIX_GetPVarString
	#define FIX_GetPVarString                    (2)
#endif

#if !defined FIX_GetSVarString
	_FIXES_STOCK FIX_GetSVarString = _FIXES_DEFAULT;
	#define FIX_GetSVarString                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetSVarString)
	#undef FIX_GetSVarString
	#define FIX_GetSVarString                    (2)
#endif

#if !defined FIX_toupper
	_FIXES_STOCK FIX_toupper = _FIXES_DEFAULT;
	#define FIX_toupper                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_toupper)
	#undef FIX_toupper
	#define FIX_toupper                          (2)
#endif

#if !defined FIX_tolower
	_FIXES_STOCK FIX_tolower = _FIXES_DEFAULT;
	#define FIX_tolower                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_tolower)
	#undef FIX_tolower
	#define FIX_tolower                          (2)
#endif

#if !defined FIX_ispacked
	_FIXES_STOCK FIX_ispacked = _FIXES_DEFAULT;
	#define FIX_ispacked                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ispacked)
	#undef FIX_ispacked
	#define FIX_ispacked                         (2)
#endif

#if !defined FIX_PassengerSeating
	_FIXES_STOCK FIX_PassengerSeating = _FIXES_DEFAULT;
	#define FIX_PassengerSeating                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PassengerSeating)
	#undef FIX_PassengerSeating
	#define FIX_PassengerSeating                 (2)
#endif

#if !defined FIX_GogglesSync
	_FIXES_STOCK FIX_GogglesSync = _FIXES_DEFAULT;
	#define FIX_GogglesSync                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GogglesSync)
	#undef FIX_GogglesSync
	#define FIX_GogglesSync                      (2)
#endif

#if !defined FIX_GetPlayerPoolSize
	_FIXES_STOCK FIX_GetPlayerPoolSize = _FIXES_DEFAULT;
	#define FIX_GetPlayerPoolSize                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerPoolSize)
	#undef FIX_GetPlayerPoolSize
	#define FIX_GetPlayerPoolSize                (2)
#endif

#if !defined FIX_SetPlayerPos
	_FIXES_STOCK FIX_SetPlayerPos = _FIXES_DEFAULT;
	#define FIX_SetPlayerPos                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerPos)
	#undef FIX_SetPlayerPos
	#define FIX_SetPlayerPos                     (2)
#endif

#if !defined FIX_GetPlayerAmmo
	_FIXES_STOCK FIX_GetPlayerAmmo = _FIXES_DEFAULT;
	#define FIX_GetPlayerAmmo                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerAmmo)
	#undef FIX_GetPlayerAmmo
	#define FIX_GetPlayerAmmo                    (2)
#endif

#if !defined FIX_JIT
	_FIXES_STOCK FIX_JIT = _FIXES_DEFAULT;
	#define FIX_JIT                              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_JIT)
	#undef FIX_JIT
	#define FIX_JIT                              (2)
#endif

#if !defined FIX_OS
	_FIXES_STOCK FIX_OS = _FIXES_DEFAULT;
	#define FIX_OS                               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OS)
	#undef FIX_OS
	#define FIX_OS                               (2)
#endif

#if !defined FIX_const
	_FIXES_STOCK FIX_const = _FIXES_DEFAULT;
	#define FIX_const                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_const)
	#undef FIX_const
	#define FIX_const                            (2)
#endif

#if !defined FIX_VEHICLES
	#if defined VEHICLE_INFERNUS
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_VEHICLES = FIXES_EnableDeprecated;
		#endif
		#define FIX_VEHICLES                     FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_VEHICLES = _FIXES_DEFAULT;
		#define FIX_VEHICLES                     _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_VEHICLES)
	#undef FIX_VEHICLES
	#define FIX_VEHICLES                         (2)
#endif

#if !defined FIX_GetPlayerWeather
	#if defined GetPlayerWeather
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetPlayerWeather = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetPlayerWeather             FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetPlayerWeather = FIX_API;
		#define FIX_GetPlayerWeather             FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeather)
	#undef FIX_GetPlayerWeather
	#define FIX_GetPlayerWeather                 (2)
#endif

#if !defined FIX_GetWeather
	#if defined GetWeather
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetWeather = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetWeather                   FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetWeather = FIX_API;
		#define FIX_GetWeather                   FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWeather)
	#undef FIX_GetWeather
	#define FIX_GetWeather                       (2)
#endif

#if !defined FIX_GetWorldTime
	#if defined GetWorldTime
		#if FIXES_EnableDeprecated
			_FIXES_STOCK FIX_GetWorldTime = FIXES_EnableDeprecated;
		#endif
		#define FIX_GetWorldTime                 FIXES_EnableDeprecated
	#else
		_FIXES_STOCK FIX_GetWorldTime = FIX_API;
		#define FIX_GetWorldTime                 FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWorldTime)
	#undef FIX_GetWorldTime
	#define FIX_GetWorldTime                     (2)
#endif

#if !defined FIX_GetConsoleVarAsString
	#if defined FIX_GetServerVarAsString
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsString)
			#define FIX_GetConsoleVarAsString    (2)
		#else
			#define FIX_GetConsoleVarAsString    (FIX_GetServerVarAsString)
		#endif
	#else
		_FIXES_STOCK FIX_GetConsoleVarAsString = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsString        _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsString)
	#undef FIX_GetConsoleVarAsString
	#define FIX_GetConsoleVarAsString            (2)
#endif

#if !defined FIX_GetConsoleVarAsInt
	#if defined FIX_GetServerVarAsInt   
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsInt)
			#define FIX_GetConsoleVarAsInt       (2)
		#else
			#define FIX_GetConsoleVarAsInt       (FIX_GetServerVarAsInt)
		#endif
	#else
		_FIXES_STOCK FIX_GetConsoleVarAsInt    = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsInt           _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsInt)
	#undef FIX_GetConsoleVarAsInt
	#define FIX_GetConsoleVarAsInt               (2)
#endif

#if !defined FIX_GetConsoleVarAsBool
	#if defined FIX_GetServerVarAsBool  
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsBool)
			#define FIX_GetConsoleVarAsBool      (2)
		#else
			#define FIX_GetConsoleVarAsBool      (FIX_GetServerVarAsBool)
		#endif
	#else
		_FIXES_STOCK FIX_GetConsoleVarAsBool   = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsBool          _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsBool)
	#undef FIX_GetConsoleVarAsBool
	#define FIX_GetConsoleVarAsBool              (2)
#endif

#if !defined FIX_GetConsoleVarAsFloat
	#if defined GetConsoleVarAsFloat
		#if FIX_GetConsoleVarAsString
			_FIXES_STOCK FIX_GetConsoleVarAsFloat = _FIXES_DEFAULT;
			#define FIX_GetConsoleVarAsFloat     _FIXES_DEFAULT
		#else
			#if FIXES_EnableDeprecated
				_FIXES_STOCK FIX_GetConsoleVarAsFloat = FIXES_EnableDeprecated;
			#endif
			#define FIX_GetConsoleVarAsFloat     FIXES_EnableDeprecated
		#endif
	#else
		#if defined FIX_GetServerVarAsFloat
			#if _FIXES_IS_UNSET(FIX_GetServerVarAsFloat)
				#define FIX_GetConsoleVarAsFloat (2)
			#else
				#define FIX_GetConsoleVarAsFloat (FIX_GetServerVarAsFloat)
	#endif
		#else
			_FIXES_STOCK FIX_GetConsoleVarAsFloat = FIX_Natives;
			#define FIX_GetConsoleVarAsFloat     FIX_Natives
		#endif
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsFloat)
	#undef FIX_GetConsoleVarAsFloat
	#define FIX_GetConsoleVarAsFloat             (2)
#endif

#if !defined FIX_tabsize
	_FIXES_STOCK FIX_tabsize = _FIXES_DEFAULT;
	#define FIX_tabsize                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_tabsize)
	#undef FIX_tabsize
	#define FIX_tabsize                          (2)
#endif

#if !defined FIX_Callbacks
	_FIXES_STOCK FIX_Callbacks = _FIXES_DEFAULT;
	#define FIX_Callbacks                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Callbacks)
	#undef FIX_Callbacks
	#define FIX_Callbacks                        (2)
#endif

#if !defined FIX_OnRconCommand
	_FIXES_STOCK FIX_OnRconCommand = FIX_Callbacks;
	#define FIX_OnRconCommand                    FIX_Callbacks
#elseif _FIXES_IS_UNSET(FIX_OnRconCommand)
	#undef FIX_OnRconCommand
	#define FIX_OnRconCommand                    (2)
#endif

#if !defined FIX_OnClientCheckResponse
	_FIXES_STOCK FIX_OnClientCheckResponse = FIX_Callbacks;
	#define FIX_OnClientCheckResponse            FIX_Callbacks
#elseif _FIXES_IS_UNSET(FIX_OnClientCheckResponse)
	#undef FIX_OnClientCheckResponse
	#define FIX_OnClientCheckResponse            (2)
#endif

#if !defined FIX_GetMaxPlayers
	_FIXES_STOCK FIX_GetMaxPlayers = _FIXES_DEFAULT;
	#define FIX_GetMaxPlayers                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetMaxPlayers)
	#undef FIX_GetMaxPlayers
	#define FIX_GetMaxPlayers                    (2)
#endif

#if !defined FIX_BypassDialog
	_FIXES_STOCK FIX_BypassDialog = _FIXES_DEFAULT;
	#define FIX_BypassDialog                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_BypassDialog)
	#undef FIX_BypassDialog
	#define FIX_BypassDialog                     (2)
#endif

#if !defined FIX_SetTimer
	_FIXES_STOCK FIX_SetTimer = _FIXES_DEFAULT;
	#define FIX_SetTimer                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetTimer)
	#undef FIX_SetTimer
	#define FIX_SetTimer                         (2)
#endif

#if !defined FIX_main
	_FIXES_STOCK FIX_main = _FIXES_DEFAULT;
	#define FIX_main                             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_main)
	#undef FIX_main
	#define FIX_main                             (2)
#endif

#if !defined FIX_Pawndoc
	_FIXES_STOCK FIX_Pawndoc = _FIXES_DEFAULT;
	#define FIX_Pawndoc                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Pawndoc)
	#undef FIX_Pawndoc
	#define FIX_Pawndoc                          (2)
#endif

//#if !defined FIX_CreateVehicle
//	_FIXES_STOCK FIX_CreateVehicle = _FIXES_DEFAULT;
//	#define FIX_CreateVehicle                    _FIXES_DEFAULT
//#elseif _FIXES_IS_UNSET(FIX_CreateVehicle)
//	#undef FIX_CreateVehicle
//	#define FIX_CreateVehicle                    (2)
//#endif
// Disable it for now.
#if defined FIX_CreateVehicle
	#undef FIX_CreateVehicle
#endif
#define FIX_CreateVehicle (0)

/*

    88b           d88                                                              
    888b         d888                                                              
    88`8b       d8'88                                                              
    88 `8b     d8' 88  ,adPPYYba,   ,adPPYba,  8b,dPPYba,   ,adPPYba,   ,adPPYba,  
    88  `8b   d8'  88  ""     `Y8  a8"     ""  88P'   "Y8  a8"     "8a  I8[    ""  
    88   `8b d8'   88  ,adPPPPP88  8b          88          8b       d8   `"Y8ba,   
    88    `888'    88  88,    ,88  "8a,   ,aa  88          "8a,   ,a8"  aa    ]8I  
    88     `8'     88  `"8bbdP"Y8   `"Ybbd8"'  88           `"YbbdP"'   `"YbbdP"'  



*/

// Generic check to see if ANY menu fix is enabled.  Used to simplify tests.
#if FIX_Menus || FIX_AddMenuItem || FIX_SetMenuColumnHeader || FIX_ShowMenuForPlayer || FIX_HideMenuForPlayer || FIX_DisableMenu || FIX_DisableMenuRow
	#define _FIX_Menus                           (1)
#else
	#define _FIX_Menus                           (0)
#endif

// Creates a `const` var using a descriptive syntax.  See:
// https://github.com/pawn-lang/compiler/issues/674#issuecomment-908927779
#if FIX_Pawndoc
	#define HIDE_PAWNDOC(%0) const HIDE_PAWNDOC_%0
#endif

#if FIX_Pawndoc
	#define SHOW_PAWNDOC _FIXES_SHOW_PAWNDOC
#endif

#if FIX_Pawndoc
	#define IS_DEFINED _FIXES_IS_DEFINED
#endif

/**
 * <remarks>
 * Breaks <c>#pragma tabsize 0</c> in such a way that the compiler gives the
 * following error:
 *
 * <code>
 *     error 017: undefined symbol "do_not_use_tabsize_0"
 * </code>
 *
 * There is ZERO reason to use it.  There are ocassionally times when an
 * indentation reset is required, usually because of macros containing code that
 * would otherwise appear correct.  For example:
 *
 * <code>
 *     #define TEST_MACRO
 *
 *     main()
 *     {
 *         new a = 42;
 *         if (a)
 *         {
 *             printf("true");
 *         }
 *         #if defined TEST_MACRO
 *             else
 *             {
 *                 printf("false");
 *             }
 *             a = 42;
 *         #endif
 *         printf("a = %d", a);
 *     }
 * </code>
 *
 * Even that can be fixed without <c>tabsize 0</c>, simply by restating the
 * correct indentation level, which resets the internal depth tracking:
 *
 * <code>
 *     #define TEST_MACRO
 *
 *     main()
 *     {
 *         new a = 42;
 *         if (a)
 *         {
 *             printf("true");
 *         }
 *         #if defined TEST_MACRO
 *             else
 *             {
 *                 printf("false");
 *             }
 *             #pragma tabsize 4
 *             a = 42;
 *         #endif
 *         printf("a = %d", a);
 *     }
 * </code>
 *
 * There is just no excuse.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(do_not_use_tabsize_0);
#if FIX_tabsize
	#define tabsize%00%0\10;%0 _DUMMY_do_not_use_tabsize_0
#endif

/**
 * <remarks>
 * fixes.inc exists
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_EXISTS);
#define FIXES_EXISTS

/**
 * <remarks>
 * The include is fully const-correct.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_CONST_CORRECT);
#define FIXES_CONST_CORRECT

/**
 * <remarks>
 * The include is fully tag-correct.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_TAG_CORRECT);
#define FIXES_TAG_CORRECT

/**
 * <remarks>
 * Is the extended API defined for use?  Better for testing (<c>#if defined FIXES_API</c>).
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_API);
#if FIX_API
	#define FIXES_API
#endif

/**
 * <remarks>
 * A marker to indicate that this version of fixes.inc uses state-based hooks.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_USES_STATE_HOOKS);
#define FIXES_UseStateHooks
#define FIXES_USES_STATE_HOOKS

/**
 * <remarks>
 * A special "printf" function only compiled when "FIXES_Debug" is set.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_PRINTF(const str[], ...)) {}
#define _FIXES_PRINTF(%0); print(_FIXES_gIsFilterscript ? FIXES_gscPrintFFS : FIXES_gscPrintFGM),printf("*** " %0);

/**
 * <remarks>
 * Test to see if this script is in command or not (master).
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_IS_IN_CHARGE()) {}
#if FIXES_Single
	#define _FIXES_IS_IN_CHARGE(%0)
#else
	#define _FIXES_IS_IN_CHARGE(%0) if (%0(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
#endif

/**
 * <remarks>
 * Set a variable, which may be a property or an array, depending on compile-
 * time options.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_SET(const var[], playerid, value)) {}
#if FIXES_Single
	#define FIXES_SET(%0,%1,%2) (FIXES_gs%0[%1] = %2)
#else
	#define FIXES_SET(%0,%1,%2) SetPVarInt(%1, FIXES_pvar%0, %2)
#endif

/**
 * <remarks>
 * Get a variable, which may be a property or an array, depending on compile-
 * time options.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_GET(const var[], playerid)) {}
#if FIXES_Single
	#define FIXES_GET(%0,%1) (FIXES_gs%0[%1])
#else
	#define FIXES_GET(%0,%1) GetPVarInt(%1, FIXES_pvar%0)
#endif

/**
 * <remarks>
 * Pretty standard.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_IS_NULL(const string[])) {}
#define _FIXES_IS_NULL(%0) ((%0[(%0[0])=='\1'])=='\0')

/**
 * <remarks>
 * Do a ceiling division of the first number by the second number.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_CEILDIV(a, b)) {}
#define _FIXES_CEILDIV(%0,%1) (((%0) + (%1) - 1) / (%1))

/**
 * <remarks>
 * A new version of "foreach", but just for this library.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_FOREACH(iterator[], &playerid)) {}
#define _FIXES_FOREACH(%1,%0) for (new %0 = MAX_PLAYERS; (%0 = %1[%0]) != MAX_PLAYERS; )

/**
 * <remarks>
 * Checks if the first parameter is between the other two: %1 &lt;= %0 &lt;%2 (but
 * faster).
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_IN_RANGE(min, value, max)) {}
#define _FIXES_IN_RANGE(%0,%1,%2) ((_:(%0) - (_:(%1) + cellmin)) < (_:(%2) - (_:(%1) + cellmin)))

/**
 * <remarks>
 * Checks if the first parameter is not between the other two:
 * <c>!(%1 &lt;= %0 &lt; %2)</c>(but faster).
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_NO_RANGE(min, value, max)) {}
#define _FIXES_NO_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) >= ((%2) - ((%1) + cellmin)))

/**
 * <remarks>
 * Forwards a hooked callbacks, and defines the default state implementations.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_FOREACH(const function[], ...)) {}
#define _FIXES_FORWARD%0(%1); \
	forward%0(%1); \
	public%0(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> { return 1; } \
	public%0(%1) <> { return 1; }

/**
 * <remarks>
 * Check if the ID is in range of player IDs.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_IS_VALID_PLAYER(playerid)) {}
#define _FIXES_IS_VALID_PLAYER(%0) _FIXES_IN_RANGE((%0), 0, MAX_PLAYERS)

/**
 * <remarks>
 * Always valid <c>IsPlayerConnected</c> check.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(bool:_FIXES_IS_PLAYER_CONNECTED(playerid)) {}
#define _FIXES_IS_PLAYER_CONNECTED(%0) (_FIXES_IS_VALID_PLAYER(%0) && IsPlayerConnected__(%0))

/*

    88888888ba,                   ad88  88               88           88                                       
    88      `"8b                 d8"    ""               ""    ,d     ""                                       
    88        `8b                88                            88                                              
    88         88   ,adPPYba,  MM88MMM  88  8b,dPPYba,   88  MM88MMM  88   ,adPPYba,   8b,dPPYba,   ,adPPYba,  
    88         88  a8P_____88    88     88  88P'   `"8a  88    88     88  a8"     "8a  88P'   `"8a  I8[    ""  
    88         8P  8PP"""""""    88     88  88       88  88    88     88  8b       d8  88       88   `"Y8ba,   
    88      .a8P   "8b,   ,aa    88     88  88       88  88    88,    88  "8a,   ,a8"  88       88  aa    ]8I  
    88888888Y"'     `"Ybbd8"'    88     88  88       88  88    "Y888  88   `"YbbdP"'   88       88  `"YbbdP"'  



*/

/**
 * <remarks>
 * The number of GameText styles recreated using TextDraw functions.  This is 7
 * by default, but can be extended to 16 if you want more default GTA styles.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(FIXES_GT_STYLE_COUNT);
#if FIX_GameText
	#if FIX_GameTextStyles
		#define FIXES_GT_STYLE_COUNT (16)
	#else
		#define FIXES_GT_STYLE_COUNT (7)
	#endif
#endif

/**
 * <remarks>
 * Set when a player can't see a dialog.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(INVALID_DIALOG_ID)
	_FIXES_HIDE_PAWNDOC(INVALID_DIALOG_ID);
#else
	_FIXES_SHOW_PAWNDOC(INVALID_DIALOG_ID);
	#define INVALID_DIALOG_ID (-1)
#endif

/**
 * <remarks>
 * Default worldbound range.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_MIN_WORLDBOUNDS);
#define _FIXES_MIN_WORLDBOUNDS (-20000.0)

/**
 * <remarks>
 * Default worldbound range.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_MAX_WORLDBOUNDS);
#define _FIXES_MAX_WORLDBOUNDS (20000.0)

/**
 * <remarks>
 * Defines property offset used for vehicle components.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_PROPERTY_OFFSET);
#define _FIXES_PROPERTY_OFFSET (12)

/**
 * <remarks>
 * Defines additional component slots
 * </remarks>
 */

#if _FIXES_IS_DEFINED(CARMODTYPE_FRONT_BULLBAR)
	_FIXES_HIDE_PAWNDOC(CARMODTYPE_FRONT_BULLBAR);
#else
	_FIXES_SHOW_PAWNDOC(CARMODTYPE_FRONT_BULLBAR);
	#define CARMODTYPE_FRONT_BULLBAR (14)
#endif

/**
 * <remarks>
 * Defines additional component slots
 * </remarks>
 */

#if _FIXES_IS_DEFINED(CARMODTYPE_REAR_BULLBAR)
	_FIXES_HIDE_PAWNDOC(CARMODTYPE_REAR_BULLBAR);
#else
	_FIXES_SHOW_PAWNDOC(CARMODTYPE_REAR_BULLBAR);
	#define CARMODTYPE_REAR_BULLBAR (15)
#endif

/**
 * <remarks>
 * IEEE 754 definition of infinity.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_INFINITY);
#define _FIXES_INFINITY (Float:0x7F800000)

/**
 * <remarks>
 * IEEE 754 definition of negative infinity.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_N_INFINITY);
#define _FIXES_N_INFINITY (Float:0xFF800000)

/**
 * <remarks>
 * The number of players whose attachment data (10-bits) can be stored in one
 * cell.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_ATTACHMENTS);
#define _FIXES_ATTACHMENTS (cellbits / MAX_PLAYER_ATTACHED_OBJECTS)

/**
 * <remarks>
 * Future-compatible tag definitions.  <c>KEY:</c> is defined as <c>_:</c> when
 * enhanced tags are disabled, and `E_KEY:` when they are enabled.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(KEY)
	_FIXES_HIDE_PAWNDOC(KEY);
#else
	_FIXES_SHOW_PAWNDOC(KEY);
	#define KEY: _:
#endif

/**
 * <remarks>
 * Future-compatible tag definitions.  <c>VEHICLE_PARAMS:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and `E_VEHICLE_PARAMS:` when they
 * are enabled.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(VEHICLE_PARAMS)
	_FIXES_HIDE_PAWNDOC(VEHICLE_PARAMS);
#else
	_FIXES_SHOW_PAWNDOC(VEHICLE_PARAMS);
	#define VEHICLE_PARAMS: _:
#endif

/**
 * <remarks>
 * Future-compatible tag definitions.  <c>PLAYER_STATE:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and `E_PLAYER_STATE:` when they
 * are enabled.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(PLAYER_STATE)
	_FIXES_HIDE_PAWNDOC(PLAYER_STATE);
#else
	_FIXES_SHOW_PAWNDOC(PLAYER_STATE);
	#define PLAYER_STATE: _:
#endif

/**
 * <remarks>
 * Future-compatible tag definitions.  <c>SPECIAL_ACTION:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and `E_SPECIAL_ACTION:` when they
 * are enabled.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(SPECIAL_ACTION)
	_FIXES_HIDE_PAWNDOC(SPECIAL_ACTION);
#else
	_FIXES_SHOW_PAWNDOC(SPECIAL_ACTION);
	#define SPECIAL_ACTION: _:
#endif

/**
 * <remarks>
 * Future-compatible tag definitions.  <c>PLAYER_VARTYPE:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and `E_PLAYER_VARTYPE:` when they
 * are enabled.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(PLAYER_VARTYPE)
	_FIXES_HIDE_PAWNDOC(PLAYER_VARTYPE);
#else
	_FIXES_SHOW_PAWNDOC(PLAYER_VARTYPE);
	#define PLAYER_VARTYPE: _:
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed this one.  Used internally via
 * <c>_FIXES_KEY_AIM</c>.
 * </remarks>
 */

#define _FIXES_KEY_AIM                           (KEY:128)
#if _FIXES_IS_DEFINED(KEY_AIM)
	_FIXES_HIDE_PAWNDOC(KEY_AIM);
#else
	_FIXES_SHOW_PAWNDOC(KEY_AIM);
	#define KEY_AIM                              _FIXES_KEY_AIM
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed this one.  Used internally via
 * <c>_FIXES_SPECIAL_ACTION_PISSING</c>.
 * </remarks>
 */

#define _FIXES_SPECIAL_ACTION_PISSING            (68)
#if _FIXES_IS_DEFINED(SPECIAL_ACTION_PISSING)
	_FIXES_HIDE_PAWNDOC(SPECIAL_ACTION_PISSING);
#else
	_FIXES_SHOW_PAWNDOC(SPECIAL_ACTION_PISSING);
	#define SPECIAL_ACTION_PISSING               _FIXES_SPECIAL_ACTION_PISSING
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed some weapon names and aliases.
 * Used internally via <c>_FIXES_WEAPON_FIST</c>.
 * </remarks>
 */

#define _FIXES_WEAPON_FIST                       (0)
#if _FIXES_IS_DEFINED(WEAPON_FIST)
	_FIXES_HIDE_PAWNDOC(WEAPON_FIST);
#else
	_FIXES_SHOW_PAWNDOC(WEAPON_FIST);
	#define WEAPON_FIST                          _FIXES_WEAPON_FIST
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed some weapon names and aliases.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(WEAPON_NIGHTSTICK)
	_FIXES_HIDE_PAWNDOC(WEAPON_NIGHTSTICK);
#else
	_FIXES_SHOW_PAWNDOC(WEAPON_NIGHTSTICK);
	#define WEAPON_NIGHTSTICK                    WEAPON_NITESTICK
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed some weapon names and aliases.
 * </remarks>
 */

#if _FIXES_IS_DEFINED(WEAPON_MOLOTOV)
	_FIXES_HIDE_PAWNDOC(WEAPON_MOLOTOV);
#else
	_FIXES_SHOW_PAWNDOC(WEAPON_MOLOTOV);
	#define WEAPON_MOLOTOV                       WEAPON_MOLTOV
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed some weapon names and aliases.
 * Used internally via <c>_FIXES_WEAPON_NIGHT_VIS_GOGGLES</c>.
 * </remarks>
 */

#define _FIXES_WEAPON_NIGHT_VIS_GOGGLES          (44)
#if _FIXES_IS_DEFINED(WEAPON_NIGHT_VIS_GOGGLES)
	_FIXES_HIDE_PAWNDOC(WEAPON_NIGHT_VIS_GOGGLES);
#else
	_FIXES_SHOW_PAWNDOC(WEAPON_NIGHT_VIS_GOGGLES);
	#define WEAPON_NIGHT_VIS_GOGGLES             _FIXES_WEAPON_NIGHT_VIS_GOGGLES
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed some weapon names and aliases.
 * Used internally via <c>_FIXES_WEAPON_THERMAL_GOGGLES</c>.
 * </remarks>
 */

#define _FIXES_WEAPON_THERMAL_GOGGLES            (45)
#if _FIXES_IS_DEFINED(WEAPON_THERMAL_GOGGLES)
	_FIXES_HIDE_PAWNDOC(WEAPON_THERMAL_GOGGLES);
#else
	_FIXES_SHOW_PAWNDOC(WEAPON_THERMAL_GOGGLES);
	#define WEAPON_THERMAL_GOGGLES               _FIXES_WEAPON_THERMAL_GOGGLES
#endif

/**
 * <remarks>
 * Maximum number of weapon slots.
 * </remarks>
 */

_FIXES_SHOW_PAWNDOC(_FIXES_WEAPON_SLOTS);
#define _FIXES_WEAPON_SLOTS                      (13)

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_TORSO);
	#define BODY_PART_TORSO                      (3)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_TORSO);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_GROIN);
	#define BODY_PART_GROIN                      (4)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_GROIN);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_LEFT_ARM);
	#define BODY_PART_LEFT_ARM                   (5)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_LEFT_ARM);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_RIGHT_ARM);
	#define BODY_PART_RIGHT_ARM                  (6)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_RIGHT_ARM);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_LEFT_LEG);
	#define BODY_PART_LEFT_LEG                   (7)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_LEFT_LEG);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_RIGHT_LEG);
	#define BODY_PART_RIGHT_LEG                  (8)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_RIGHT_LEG);
#endif

/**
 * <remarks>
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	_FIXES_SHOW_PAWNDOC(BODY_PART_HEAD);
	#define BODY_PART_HEAD                       (9)
#else
	_FIXES_HIDE_PAWNDOC(BODY_PART_HEAD);
#endif

/**
 * <remarks>
 * <c>CAMERAMODES</c>
 *
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_CAMERAMODES
	#define CAM_MODE_DISCONNECTED               (-1)
	#define CAM_MODE_NONE                       (0)
	#define CAM_MODE_BEHINDCAR                  (3)
	#define CAM_MODE_FOLLOWPED                  (4)
	#define CAM_MODE_SNIPER                     (7)
	#define CAM_MODE_ROCKETLAUNCHER             (8)
	#define CAM_MODE_FIXED                      (15)
	#define CAM_MODE_1STPERSON                  (16)
	#define CAM_MODE_CAM_ON_A_STRING            (18)
	#define CAM_MODE_BEHINDBOAT                 (22)
	#define CAM_MODE_CAMERA                     (46)
	#define CAM_MODE_ROCKETLAUNCHER_HS          (51)
	#define CAM_MODE_AIMWEAPON                  (53)
	#define CAM_MODE_AIMWEAPON_FROMCAR          (55)
	#define CAM_MODE_DW_HELI_CHASE              (56)
#endif

/**
 * <remarks>
 * <c>VEHICLES</c>
 *
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_VEHICLES
	// In alphabetical order.
	#define VEHICLE_ADMIRAL                     (445)
	#define VEHICLE_ALPHA                       (602)
	#define VEHICLE_AMBULAN                     (416)
	#define VEHICLE_AMBULANCE                   (416)
	#define VEHICLE_ANDROM                      (592)
	#define VEHICLE_ANDROMADA                   (592)
	#define VEHICLE_ARTICT1                     (435)
	#define VEHICLE_ARTICT2                     (450)
	#define VEHICLE_ARTICT3                     (591)
	#define VEHICLE_ARTICLETRAILER1             (435)
	#define VEHICLE_ARTICLETRAILER2             (450)
	#define VEHICLE_ARTICLETRAILER3             (591)
	#define VEHICLE_AT400                       (577)
	#define VEHICLE_BAGGAGE                     (485)
	#define VEHICLE_BANDITO                     (568)
	#define VEHICLE_BANSHEE                     (429)
	#define VEHICLE_BARRACKS                    (433)
	#define VEHICLE_BEAGLE                      (511)
	#define VEHICLE_BENSON                      (499)
	#define VEHICLE_BERKLEYSRCVAN               (459)
	#define VEHICLE_BF400                       (581)
	#define VEHICLE_BFINJECT                    (424)
	#define VEHICLE_BFINJECTION                 (424)
	#define VEHICLE_BIKE                        (509)
	#define VEHICLE_BLADE                       (536)
	#define VEHICLE_BLISTAC                     (496)
	#define VEHICLE_BLISTACOMPACT               (496)
	#define VEHICLE_BLOODRA                     (504)
	#define VEHICLE_BLOODRINGBANGER             (504)
	#define VEHICLE_BMX                         (481)
	#define VEHICLE_BOBCAT                      (422)
	#define VEHICLE_BOXBURG                     (609)
	#define VEHICLE_BOXVILLE                    (498)
	#define VEHICLE_BRAVURA                     (401)
	#define VEHICLE_BROADWAY                    (575)
	#define VEHICLE_BROWNSTREAK                 (538)
	#define VEHICLE_BUCCANEE                    (518)
	#define VEHICLE_BUCCANEER                   (518)
	#define VEHICLE_BUFFALO                     (402)
	#define VEHICLE_BULLET                      (541)
	#define VEHICLE_BURRITO                     (482)
	#define VEHICLE_BUS                         (431)
	#define VEHICLE_CABBIE                      (438)
	#define VEHICLE_CADDY                       (457)
	#define VEHICLE_CADRONA                     (527)
	#define VEHICLE_CAMPER                      (483)
	#define VEHICLE_CARGOBOB                    (548)
	#define VEHICLE_CEMENT                      (524)
	#define VEHICLE_CEMENTTRUCK                 (524)
	#define VEHICLE_CHEETAH                     (415)
	#define VEHICLE_CLOVER                      (542)
	#define VEHICLE_CLUB                        (589)
	#define VEHICLE_COACH                       (437)
	#define VEHICLE_COASTG                      (472)
	#define VEHICLE_COASTGUARD                  (472)
	#define VEHICLE_COMET                       (480)
	#define VEHICLE_COPCARLA                    (596)
	#define VEHICLE_COPCARSF                    (597)
	#define VEHICLE_COPCARVG                    (598)
	#define VEHICLE_COPCARRU                    (599)
	#define VEHICLE_CROPDUST                    (512)
	#define VEHICLE_DFT30                       (578)
	#define VEHICLE_DINGHY                      (473)
	#define VEHICLE_DODO                        (593)
	#define VEHICLE_DOZER                       (486)
	#define VEHICLE_DUMPER                      (406)
	#define VEHICLE_DUNERIDE                    (573)
	#define VEHICLE_ELEGANT                     (507)
	#define VEHICLE_ELEGY                       (562)
	#define VEHICLE_EMPEROR                     (585)
	#define VEHICLE_ENFORCER                    (427)
	#define VEHICLE_ESPERANT                    (419)
	#define VEHICLE_ESPERANTO                   (419)
	#define VEHICLE_EUROS                       (587)
	#define VEHICLE_FAGGIO                      (462)
	#define VEHICLE_FBIRANCH                    (490)
	#define VEHICLE_FBIRANCHER                  (490)
	#define VEHICLE_FCR900                      (521)
	#define VEHICLE_FELTZER                     (533)
	#define VEHICLE_FIRELA                      (544)
	#define VEHICLE_FIRETRUK                    (407)
	#define VEHICLE_FIRETRUCK                   (407)
	#define VEHICLE_FIRETRUCKLA                 (544)
	#define VEHICLE_FLASH                       (565)
	#define VEHICLE_FLATBED                     (455)
	#define VEHICLE_FORKLIFT                    (530)
	#define VEHICLE_FORTUNE                     (526)
	#define VEHICLE_FREEWAY                     (463)
	#define VEHICLE_FREIGHT                     (537)
	#define VEHICLE_GLENDALE                    (466)
	#define VEHICLE_GLENDALESHIT                (604)
	#define VEHICLE_GLENSHIT                    (604)
	#define VEHICLE_GREENWOO                    (492)
	#define VEHICLE_GREENWOOD                   (492)
	#define VEHICLE_HERMES                      (474)
	#define VEHICLE_HOTDOG                      (588)
	#define VEHICLE_HOTKNIFE                    (434)
	#define VEHICLE_HOTRINA                     (502)
	#define VEHICLE_HOTRINB                     (503)
	#define VEHICLE_HOTRING                     (494)
	#define VEHICLE_HOTRINGRACER                (494)
	#define VEHICLE_HOTRINGRACERA               (502)
	#define VEHICLE_HOTRINGRACERB               (503)
	#define VEHICLE_HUNTER                      (425)
	#define VEHICLE_HUNTLEY                     (579)
	#define VEHICLE_HUSTLER                     (545)
	#define VEHICLE_INFERNUS                    (411)
	#define VEHICLE_INTRUDER                    (546)
	#define VEHICLE_JESTER                      (559)
	#define VEHICLE_JETMAX                      (493)
	#define VEHICLE_JOURNEY                     (508)
	#define VEHICLE_KART                        (571)
	#define VEHICLE_LANDSTAL                    (400)
	#define VEHICLE_LANDSTALKER                 (400)
	#define VEHICLE_LAUNCH                      (595)
	#define VEHICLE_LINERUN                     (403)
	#define VEHICLE_LINERUNNER                  (403)
	#define VEHICLE_QUAD                        (471)
	#define VEHICLE_MAJESTIC                    (517)
	#define VEHICLE_MTBIKE                      (510)
	#define VEHICLE_MOUNTAINBIKE                (510)
	#define VEHICLE_MANANA                      (410)
	#define VEHICLE_MARQUIS                     (484)
	#define VEHICLE_MAVERICK                    (487)
	#define VEHICLE_MERIT                       (551)
	#define VEHICLE_MESA                        (500)
	#define VEHICLE_MONSTER                     (444)
	#define VEHICLE_MONSTERA                    (556)
	#define VEHICLE_MONSTERB                    (557)
	#define VEHICLE_MOONBEAM                    (418)
	#define VEHICLE_MOWER                       (572)
	#define VEHICLE_MRWHOOP                     (423)
	#define VEHICLE_MRWHOOPEE                   (423)
	#define VEHICLE_MULE                        (414)
	#define VEHICLE_NEBULA                      (516)
	#define VEHICLE_NEVADA                      (553)
	#define VEHICLE_NEWSVAN                     (582)
	#define VEHICLE_NRG500                      (522)
	#define VEHICLE_OCEANIC                     (467)
	#define VEHICLE_PACKER                      (443)
	#define VEHICLE_PATRIOT                     (470)
	#define VEHICLE_PCJ600                      (461)
	#define VEHICLE_PEREN                       (404)
	#define VEHICLE_PERRENIAL                   (404)
	#define VEHICLE_PETRO                       (514)
	#define VEHICLE_PETROLTRAILER               (584)
	#define VEHICLE_PETROTR                     (584)
	#define VEHICLE_PHOENIX                     (603)
	#define VEHICLE_PICADOR                     (600)
	#define VEHICLE_PIZZABOY                    (448)
	#define VEHICLE_POLICECARLSPD               (596)
	#define VEHICLE_POLICECARSFPD               (597)
	#define VEHICLE_POLICECARLVPD               (598)
	#define VEHICLE_POLICERANGER                (599)
	#define VEHICLE_POLMAV                      (497)
	#define VEHICLE_POLICEMAVERICK              (497)
	#define VEHICLE_PONY                        (413)
	#define VEHICLE_PREDATOR                    (430)
	#define VEHICLE_PREMIER                     (426)
	#define VEHICLE_PREVION                     (436)
	#define VEHICLE_PRIMO                       (547)
	#define VEHICLE_RAINDANC                    (563)
	#define VEHICLE_RAINDANCE                   (563)
	#define VEHICLE_RANCHER                     (489)
	#define VEHICLE_RANCHERLURE                 (505)
	#define VEHICLE_RCBANDIT                    (441)
	#define VEHICLE_RCBARON                     (464)
	#define VEHICLE_RCRAIDER                    (465)
	#define VEHICLE_RCGOBLIN                    (501)
	#define VEHICLE_RDTRAIN                     (515)
	#define VEHICLE_REEFER                      (453)
	#define VEHICLE_REGINA                      (479)
	#define VEHICLE_REMINGTN                    (534)
	#define VEHICLE_REMINGTON                   (534)
	#define VEHICLE_RHINO                       (432)
	#define VEHICLE_RNCHLURE                    (505)
	#define VEHICLE_ROADTRAIN                   (515)
	#define VEHICLE_ROMERO                      (442)
	#define VEHICLE_RUMPO                       (440)
	#define VEHICLE_RUSTLER                     (476)
	#define VEHICLE_SABRE                       (475)
	#define VEHICLE_SADLER                      (543)
	#define VEHICLE_SADLERSHIT                  (605)
	#define VEHICLE_SADLSHIT                    (605)
	#define VEHICLE_SANCHEZ                     (468)
	#define VEHICLE_SANDKING                    (495)
	#define VEHICLE_SAVANNA                     (567)
	#define VEHICLE_SEASPAR                     (447)
	#define VEHICLE_SEASPARROW                  (447)
	#define VEHICLE_SECURICA                    (428)
	#define VEHICLE_SECURICAR                   (428)
	#define VEHICLE_SENTINEL                    (405)
	#define VEHICLE_SHAMAL                      (519)
	#define VEHICLE_STREAK                      (538)
	#define VEHICLE_STREAKC                     (570)
	#define VEHICLE_STREAKTRAILER               (570)
	#define VEHICLE_SKIMMER                     (460)
	#define VEHICLE_SLAMVAN                     (535)
	#define VEHICLE_SOLAIR                      (458)
	#define VEHICLE_SPARROW                     (469)
	#define VEHICLE_SPEEDER                     (452)
	#define VEHICLE_SQUALO                      (446)
	#define VEHICLE_STAFFORD                    (580)
	#define VEHICLE_STALLION                    (439)
	#define VEHICLE_STRATUM                     (561)
	#define VEHICLE_STRETCH                     (409)
	#define VEHICLE_STUNT                       (513)
	#define VEHICLE_STUNTPLANE                  (513)
	#define VEHICLE_SULTAN                      (560)
	#define VEHICLE_SUNRISE                     (550)
	#define VEHICLE_SUPERGT                     (506)
	#define VEHICLE_SWAT                        (601)
	#define VEHICLE_SWATVAN                     (601)
	#define VEHICLE_SWEEPER                     (574)
	#define VEHICLE_TAHOMA                      (566)
	#define VEHICLE_TAMPA                       (549)
	#define VEHICLE_TANKER                      (514)
	#define VEHICLE_TAXI                        (420)
	#define VEHICLE_TOPFUN                      (459)
	#define VEHICLE_TORNADO                     (576)
	#define VEHICLE_TOWTRUCK                    (525)
	#define VEHICLE_TRACTOR                     (531)
	#define VEHICLE_TRAM                        (449)
	#define VEHICLE_TRASH                       (408)
	#define VEHICLE_TRASHMASTER                 (408)
	#define VEHICLE_TROPIC                      (454)
	#define VEHICLE_TUG                         (583)
	#define VEHICLE_TUGSTAIR                    (608)
	#define VEHICLE_TUGSTAIRSTRAILER            (608)
	#define VEHICLE_TURISMO                     (451)
	#define VEHICLE_URANUS                      (558)
	#define VEHICLE_UTILITY                     (552)
	#define VEHICLE_UTILITYVAN                  (552)
	#define VEHICLE_VCNMAV                      (488)
	#define VEHICLE_SANNEWSMAVERICK             (488)
	#define VEHICLE_VINCENT                     (540)
	#define VEHICLE_VIRGO                       (491)
	#define VEHICLE_VOODOO                      (412)
	#define VEHICLE_VORTEX                      (539)
	#define VEHICLE_WALTON                      (478)
	#define VEHICLE_WASHING                     (421)
	#define VEHICLE_WASHINGTON                  (421)
	#define VEHICLE_WAYFARER                    (586)
	#define VEHICLE_WILLARD                     (529)
	#define VEHICLE_WINDSOR                     (555)
	#define VEHICLE_YANKEE                      (456)
	#define VEHICLE_YOSEMITE                    (554)
	#define VEHICLE_ZR350                       (477)

	// In numerical order.
	#define VEHICLE_LANDSTAL                    (400)
	#define VEHICLE_LANDSTALKER                 (400)
	#define VEHICLE_BRAVURA                     (401)
	#define VEHICLE_BUFFALO                     (402)
	#define VEHICLE_LINERUN                     (403)
	#define VEHICLE_LINERUNNER                  (403)
	#define VEHICLE_PEREN                       (404)
	#define VEHICLE_PERRENIAL                   (404)
	#define VEHICLE_SENTINEL                    (405)
	#define VEHICLE_DUMPER                      (406)
	#define VEHICLE_FIRETRUK                    (407)
	#define VEHICLE_FIRETRUCK                   (407)
	#define VEHICLE_TRASH                       (408)
	#define VEHICLE_TRASHMASTER                 (408)
	#define VEHICLE_STRETCH                     (409)
	#define VEHICLE_MANANA                      (410)
	#define VEHICLE_INFERNUS                    (411)
	#define VEHICLE_VOODOO                      (412)
	#define VEHICLE_PONY                        (413)
	#define VEHICLE_MULE                        (414)
	#define VEHICLE_CHEETAH                     (415)
	#define VEHICLE_AMBULAN                     (416)
	#define VEHICLE_AMBULANCE                   (416)
	#define VEHICLE_LEVIATHAN                   (417)
	#define VEHICLE_MOONBEAM                    (418)
	#define VEHICLE_ESPERANT                    (419)
	#define VEHICLE_ESPERANTO                   (419)
	#define VEHICLE_TAXI                        (420)
	#define VEHICLE_WASHING                     (421)
	#define VEHICLE_WASHINGTON                  (421)
	#define VEHICLE_BOBCAT                      (422)
	#define VEHICLE_MRWHOOP                     (423)
	#define VEHICLE_MRWHOOPEE                   (423)
	#define VEHICLE_BFINJECT                    (424)
	#define VEHICLE_BFINJECTION                 (424)
	#define VEHICLE_HUNTER                      (425)
	#define VEHICLE_PREMIER                     (426)
	#define VEHICLE_ENFORCER                    (427)
	#define VEHICLE_SECURICA                    (428)
	#define VEHICLE_SECURICAR                   (428)
	#define VEHICLE_BANSHEE                     (429)
	#define VEHICLE_PREDATOR                    (430)
	#define VEHICLE_BUS                         (431)
	#define VEHICLE_RHINO                       (432)
	#define VEHICLE_BARRACKS                    (433)
	#define VEHICLE_HOTKNIFE                    (434)
	#define VEHICLE_ARTICT1                     (435)
	#define VEHICLE_ARTICLETRAILER1             (435)
	#define VEHICLE_PREVION                     (436)
	#define VEHICLE_COACH                       (437)
	#define VEHICLE_CABBIE                      (438)
	#define VEHICLE_STALLION                    (439)
	#define VEHICLE_RUMPO                       (440)
	#define VEHICLE_RCBANDIT                    (441)
	#define VEHICLE_ROMERO                      (442)
	#define VEHICLE_PACKER                      (443)
	#define VEHICLE_MONSTER                     (444)
	#define VEHICLE_ADMIRAL                     (445)
	#define VEHICLE_SQUALO                      (446)
	#define VEHICLE_SEASPAR                     (447)
	#define VEHICLE_SEASPARROW                  (447)
	#define VEHICLE_PIZZABOY                    (448)
	#define VEHICLE_TRAM                        (449)
	#define VEHICLE_ARTICT2                     (450)
	#define VEHICLE_ARTICLETRAILER2             (450)
	#define VEHICLE_TURISMO                     (451)
	#define VEHICLE_SPEEDER                     (452)
	#define VEHICLE_REEFER                      (453)
	#define VEHICLE_TROPIC                      (454)
	#define VEHICLE_FLATBED                     (455)
	#define VEHICLE_YANKEE                      (456)
	#define VEHICLE_CADDY                       (457)
	#define VEHICLE_SOLAIR                      (458)
	#define VEHICLE_TOPFUN                      (459)
	#define VEHICLE_BERKLEYSRCVAN               (459)
	#define VEHICLE_SKIMMER                     (460)
	#define VEHICLE_PCJ600                      (461)
	#define VEHICLE_FAGGIO                      (462)
	#define VEHICLE_FREEWAY                     (463)
	#define VEHICLE_RCBARON                     (464)
	#define VEHICLE_RCRAIDER                    (465)
	#define VEHICLE_GLENDALE                    (466)
	#define VEHICLE_OCEANIC                     (467)
	#define VEHICLE_SANCHEZ                     (468)
	#define VEHICLE_SPARROW                     (469)
	#define VEHICLE_PATRIOT                     (470)
	#define VEHICLE_QUAD                        (471)
	#define VEHICLE_COASTG                      (472)
	#define VEHICLE_COASTGUARD                  (472)
	#define VEHICLE_DINGHY                      (473)
	#define VEHICLE_HERMES                      (474)
	#define VEHICLE_SABRE                       (475)
	#define VEHICLE_RUSTLER                     (476)
	#define VEHICLE_ZR350                       (477)
	#define VEHICLE_WALTON                      (478)
	#define VEHICLE_REGINA                      (479)
	#define VEHICLE_COMET                       (480)
	#define VEHICLE_BMX                         (481)
	#define VEHICLE_BURRITO                     (482)
	#define VEHICLE_CAMPER                      (483)
	#define VEHICLE_MARQUIS                     (484)
	#define VEHICLE_BAGGAGE                     (485)
	#define VEHICLE_DOZER                       (486)
	#define VEHICLE_MAVERICK                    (487)
	#define VEHICLE_VCNMAV                      (488)
	#define VEHICLE_SANNEWSMAVERICK             (488)
	#define VEHICLE_RANCHER                     (489)
	#define VEHICLE_FBIRANCHER                  (490)
	#define VEHICLE_VIRGO                       (491)
	#define VEHICLE_GREENWOO                    (492)
	#define VEHICLE_GREENWOOD                   (492)
	#define VEHICLE_JETMAX                      (493)
	#define VEHICLE_HOTRING                     (494)
	#define VEHICLE_HOTRINGRACER                (494)
	#define VEHICLE_SANDKING                    (495)
	#define VEHICLE_BLISTAC                     (496)
	#define VEHICLE_BLISTACOMPACT               (496)
	#define VEHICLE_POLMAV                      (497)
	#define VEHICLE_POLICEMAVERICK              (497)
	#define VEHICLE_BOXVILLE                    (498)
	#define VEHICLE_BENSON                      (499)
	#define VEHICLE_MESA                        (500)
	#define VEHICLE_RCGOBLIN                    (501)
	#define VEHICLE_HOTRINA                     (502)
	#define VEHICLE_HOTRINGRACERA               (502)
	#define VEHICLE_HOTRINB                     (503)
	#define VEHICLE_HOTRINGRACERB               (503)
	#define VEHICLE_BLOODRA                     (504)
	#define VEHICLE_BLOODRINGBANGER             (504)
	#define VEHICLE_RNCHLURE                    (505)
	#define VEHICLE_RANCHERLURE                 (505)
	#define VEHICLE_SUPERGT                     (506)
	#define VEHICLE_ELEGANT                     (507)
	#define VEHICLE_JOURNEY                     (508)
	#define VEHICLE_BIKE                        (509)
	#define VEHICLE_MTBIKE                      (510)
	#define VEHICLE_MOUNTAINBIKE                (510)
	#define VEHICLE_BEAGLE                      (511)
	#define VEHICLE_CROPDUST                    (512)
	#define VEHICLE_STUNT                       (513)
	#define VEHICLE_STUNTPLANE                  (513)
	#define VEHICLE_PETRO                       (514)
	#define VEHICLE_TANKER                      (514)
	#define VEHICLE_RDTRAIN                     (515)
	#define VEHICLE_ROADTRAIN                   (515)
	#define VEHICLE_NEBULA                      (516)
	#define VEHICLE_MAJESTIC                    (517)
	#define VEHICLE_BUCCANEE                    (518)
	#define VEHICLE_BUCCANEER                   (518)
	#define VEHICLE_SHAMAL                      (519)
	#define VEHICLE_HYDRA                       (520)
	#define VEHICLE_FCR900                      (521)
	#define VEHICLE_NRG500                      (522)
	#define VEHICLE_HPV1000                     (523)
	#define VEHICLE_CEMENT                      (524)
	#define VEHICLE_CEMENTTRUCK                 (524)
	#define VEHICLE_TOWTRUCK                    (525)
	#define VEHICLE_FORTUNE                     (526)
	#define VEHICLE_CADRONA                     (527)
	#define VEHICLE_FBITRUCK                    (528)
	#define VEHICLE_WILLARD                     (529)
	#define VEHICLE_FORKLIFT                    (530)
	#define VEHICLE_TRACTOR                     (531)
	#define VEHICLE_COMBINE                     (532)
	#define VEHICLE_FELTZER                     (533)
	#define VEHICLE_REMINGTN                    (534)
	#define VEHICLE_REMINGTON                   (534)
	#define VEHICLE_SLAMVAN                     (535)
	#define VEHICLE_BLADE                       (536)
	#define VEHICLE_FREIGHT                     (537)
	#define VEHICLE_STREAK                      (538)
	#define VEHICLE_BROWNSTREAK                 (538)
	#define VEHICLE_VORTEX                      (539)
	#define VEHICLE_VINCENT                     (540)
	#define VEHICLE_BULLET                      (541)
	#define VEHICLE_CLOVER                      (542)
	#define VEHICLE_SADLER                      (543)
	#define VEHICLE_FIRELA                      (544)
	#define VEHICLE_FIRETRUCKLA                 (544)
	#define VEHICLE_HUSTLER                     (545)
	#define VEHICLE_INTRUDER                    (546)
	#define VEHICLE_PRIMO                       (547)
	#define VEHICLE_CARGOBOB                    (548)
	#define VEHICLE_TAMPA                       (549)
	#define VEHICLE_SUNRISE                     (550)
	#define VEHICLE_MERIT                       (551)
	#define VEHICLE_UTILITY                     (552)
	#define VEHICLE_UTILITYVAN                  (552)
	#define VEHICLE_NEVADA                      (553)
	#define VEHICLE_YOSEMITE                    (554)
	#define VEHICLE_WINDSOR                     (555)
	#define VEHICLE_MONSTERA                    (556)
	#define VEHICLE_MONSTERB                    (557)
	#define VEHICLE_URANUS                      (558)
	#define VEHICLE_JESTER                      (559)
	#define VEHICLE_SULTAN                      (560)
	#define VEHICLE_STRATUM                     (561)
	#define VEHICLE_ELEGY                       (562)
	#define VEHICLE_RAINDANC                    (563)
	#define VEHICLE_RAINDANCE                   (563)
	#define VEHICLE_RCTIGER                     (564)
	#define VEHICLE_FLASH                       (565)
	#define VEHICLE_TAHOMA                      (566)
	#define VEHICLE_SAVANNA                     (567)
	#define VEHICLE_BANDITO                     (568)
	#define VEHICLE_FREIGHTFLATTRAILER          (569)
	#define VEHICLE_STREAKC                     (570)
	#define VEHICLE_STREAKTRAILER               (570)
	#define VEHICLE_KART                        (571)
	#define VEHICLE_MOWER                       (572)
	#define VEHICLE_DUNERIDE                    (573)
	#define VEHICLE_SWEEPER                     (574)
	#define VEHICLE_BROADWAY                    (575)
	#define VEHICLE_TORNADO                     (576)
	#define VEHICLE_AT400                       (577)
	#define VEHICLE_DFT30                       (578)
	#define VEHICLE_HUNTLEY                     (579)
	#define VEHICLE_STAFFORD                    (580)
	#define VEHICLE_BF400                       (581)
	#define VEHICLE_NEWSVAN                     (582)
	#define VEHICLE_TUG                         (583)
	#define VEHICLE_PETROTR                     (584)
	#define VEHICLE_PETROLTRAILER               (584)
	#define VEHICLE_EMPEROR                     (585)
	#define VEHICLE_WAYFARER                    (586)
	#define VEHICLE_EUROS                       (587)
	#define VEHICLE_HOTDOG                      (588)
	#define VEHICLE_CLUB                        (589)
	#define VEHICLE_FREIGHTBOXTRAILER           (590)
	#define VEHICLE_ARTICT3                     (591)
	#define VEHICLE_ARTICLETRAILER3             (591)
	#define VEHICLE_ANDROM                      (592)
	#define VEHICLE_ANDROMADA                   (592)
	#define VEHICLE_DODO                        (593)
	#define VEHICLE_RCCAM                       (594)
	#define VEHICLE_LAUNCH                      (595)
	#define VEHICLE_COPCARLA                    (596)
	#define VEHICLE_POLICECARLSPD               (596)
	#define VEHICLE_COPCARSF                    (597)
	#define VEHICLE_POLICECARSFPD               (597)
	#define VEHICLE_COPCARVG                    (598)
	#define VEHICLE_POLICECARLVPD               (598)
	#define VEHICLE_COPCARRU                    (599)
	#define VEHICLE_POLICERANGER                (599)
	#define VEHICLE_PICADOR                     (600)
	#define VEHICLE_SWATVAN                     (601)
	#define VEHICLE_SWAT                        (601)
	#define VEHICLE_ALPHA                       (602)
	#define VEHICLE_PHOENIX                     (603)
	#define VEHICLE_GLENSHIT                    (604)
	#define VEHICLE_GLENDALESHIT                (604)
	#define VEHICLE_SADLSHIT                    (605)
	#define VEHICLE_SADLERSHIT                  (605)
	#define VEHICLE_BAGGAGETRAILERA             (606)
	#define VEHICLE_BAGGAGETRAILERB             (607)
	#define VEHICLE_TUGSTAIR                    (608)
	#define VEHICLE_TUGSTAIRSTRAILER            (608)
	#define VEHICLE_BOXBURG                     (609)
	#define VEHICLE_FARMTRAILER                 (610)
	#define VEHICLE_UTILITYTRAILER              (611)
#endif

/**
 * <remarks>
 * <c>IS_JIT</c>
 *
 * True when the code is JIT compiled.
 * </remarks>
 */

#if FIX_JIT
	_FIXES_SHOW_PAWNDOC(IS_JIT);
	#define IS_JIT (_FIXES_gIsJIT)
#else
	_FIXES_HIDE_PAWNDOC(IS_JIT);
#endif

/**
 * <remarks>
 * "FILTERSCRIPT" can't always be relied on to be set.  This is not a pre-
 * processor macro, but may be better than nothing (also used internally).
 * </remarks>
 */

#if FIX_FILTERSCRIPT
	_FIXES_SHOW_PAWNDOC(IS_FILTERSCRIPT);
	#define IS_FILTERSCRIPT (_FIXES_gIsFilterscript)
#else
	_FIXES_HIDE_PAWNDOC(IS_FILTERSCRIPT);
#endif

/**
 * <remarks>
 * True when the code is running on Windows.  NOT a pre-processor macro, since
 * the OS you are running the code on can't be determined at compile-time.
 * </remarks>
 */

#if FIX_OS
	_FIXES_SHOW_PAWNDOC(IS_WINDOWS);
	#define IS_WINDOWS (_FIXES_gIsWindows)
#else
	_FIXES_HIDE_PAWNDOC(IS_WINDOWS);
#endif

/**
 * <remarks>
 * True when the code is running on Linux.  NOT a pre-processor macro, since the
 * OS you are running the code on can't be determined at compile-time.
 * </remarks>
 */

#if FIX_OS
	_FIXES_SHOW_PAWNDOC(IS_LINUX);
	#define IS_LINUX (!_FIXES_gIsWindows)
#else
	_FIXES_HIDE_PAWNDOC(IS_LINUX);
#endif

/*

           db         88           ad88888ba   
          d88b        88          d8"     "8b  
         d8'`8b       88          Y8,          
        d8'  `8b      88          `Y8aaaaa,    
       d8YaaaaY8b     88            `"""""8b,  
      d8""""""""8b    88                  `8b  
     d8'        `8b   88          Y8a     a8P  
    d8'          `8b  88888888888  "Y88888P"   



*/

/**
 * <remarks>
 * CHAIN_ORDER
 *
 * Allows y_hooks to call things in the correct order when it exists.
 * </remarks>
 */

#if !defined CHAIN_ORDER
	#define CHAIN_ORDER() 0
#endif

/**
 * <remarks>
 * PRE_HOOK
 *
 * A method of pre-hooking callbacks to still have them called before any ones
 * re-written by y_hooks.
 * </remarks>
 */

#define PRE_HOOK(%0) forward @CO_%0();public @CO_%0(){return CHAIN_ORDER()+1;}

PRE_HOOK(FIXES)
#undef CHAIN_ORDER
#define CHAIN_ORDER @CO_FIXES

/**
 * <remarks>
 * Ensure natives used be various fixes are included in the AMX.  Done before
 * anything else, and using multiple lines, to try and mitigate the effects of
 * ALS (these MUST include the original natives, not hooks).
 * </remarks>
 */

#if _FIXES_NEW_COMPILER
	_FIXES_HIDE_PAWNDOC(_FIXES_IncludeNatives);
#else
	forward _FIXES_IncludeNatives();

	public _FIXES_IncludeNatives()
	{
		static FIXES_glEmpty[] = "";
		// Do not put this on one line - this prevents macro replacements.
		SetTimerEx
			(FIXES_glEmpty, 0, false, FIXES_glEmpty);
		// Do not put this on one line - this prevents macro replacements.
		KillTimer
			(0);
	}
#endif

/**
 * <remarks>
 * _FIXES_IncludeStates
 *
 * Define the "_ALS" states used by hooks.
 * </remarks>
 */

static stock _FIXES_IncludeStates() <_ALS : _ALS_x0, _ALS : _ALS_x1, _ALS : _ALS_x2, _ALS : _ALS_x3>
{
}

static stock _FIXES_IncludeStates() <_ALS : _ALS_go>
{
}

/*

    88888888888                                                           
    88                                                                    
    88                                                                    
    88aaaaa      8b,dPPYba,   88       88  88,dPYba,,adPYba,   ,adPPYba,  
    88"""""      88P'   `"8a  88       88  88P'   "88"    "8a  I8[    ""  
    88           88       88  88       88  88      88      88   `"Y8ba,   
    88           88       88  "8a,   ,a88  88      88      88  aa    ]8I  
    88888888888  88       88   `"YbbdP'Y8  88      88      88  `"YbbdP"'  



*/

/**
 * <remarks>
 * e_FIXES_BOOLS
 *
 * Collection of boolean values for players, designed to collect multiple checks
 * in to one variable to reduce memory consumption.
 * </remarks>
 */
_FIXES_ENUM e_FIXES_BOOLS:(<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_BOOLS_NONE = 0,
	// Does this player have worldbounds enabled?
	e_FIXES_BOOLS_UNCONTROLLABLE = 1,
	e_FIXES_BOOLS_PUT_IN_VEHICLE,
	e_FIXES_BOOLS_BLOCK,
	e_FIXES_BOOLS_TELEPORT,
	e_FIXES_BOOLS_CONNECTED,
	e_FIXES_BOOLS_INTERIOR,
	e_FIXES_BOOLS_PUT_IN_TRAIN,
	e_FIXES_BOOLS_KICKED,
	e_FIXES_BOOLS_ON_PLAYER_CONNECT,
	e_FIXES_BOOLS_DRIVE_BY,
	e_FIXES_BOOLS_FIRST_SPAWN,
	e_FIXES_BOOLS_FIRST_CLASS,
	e_FIXES_BOOLS_SPECTATING,
	e_FIXES_BOOLS_DIED_TO_SPAWN,
	e_FIXES_BOOLS_CP_DELAYED,
	e_FIXES_BOOLS_RACE_CP_DELAYED,
	e_FIXES_BOOLS_CLOCK_ENABLED,
	e_FIXES_BOOLS_VEH_ENTER,
	e_FIXES_BOOLS_VEH_ENTER_ANIM,
	e_FIXES_BOOLS_DIALOG_BLOCK,
	e_FIXES_BOOLS_FORCE_BLOCK,
}

/**
 * <remarks>
 * e_FIXES_SETTINGS
 *
 * Collection of boolean values for the script as a whole.  Stores a variety of
 * settings that are true/false.
 * </remarks>
 */
_FIXES_ENUM e_FIXES_SETTINGS:(<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_SETTINGS_NONE = 0,
	e_FIXES_SETTINGS_INTERIOR = 1,
	e_FIXES_SETTINGS_ADMIN_TELEPORT,
	e_FIXES_SETTINGS_IN_CHARGE,
	e_FIXES_SETTINGS_DROP_ALL_DATA,
	e_FIXES_SETTINGS_MENU_SET,
	e_FIXES_SETTINGS_ENDING,
	e_FIXES_SETTINGS_ENDED,
	e_FIXES_SETTINGS_NO_GAME_TEXT,
	e_FIXES_SETTINGS_SECOND_USE
}

/*

                                                88         
                 ,d                             88         
                 88                             88         
    ,adPPYba,  MM88MMM  ,adPPYba,    ,adPPYba,  88   ,d8   
    I8[    ""    88    a8"     "8a  a8"     ""  88 ,a8"    
     `"Y8ba,     88    8b       d8  8b          8888[      
    aa    ]8I    88,   "8a,   ,a8"  "8a,   ,aa  88`"Yba,   
    `"YbbdP"'    "Y888  `"YbbdP"'    `"Ybbd8"'  88   `Y8a  



*/

// These varaibles are NOT pre-processor dependent as they are stock.  It's just
// simpler than trying to figure out when or if a semi-colon is needed.  The
// three `_FIXES_gIs...` variables always exist, they are only `static` if the
// relevant fixes are not enabled since they may still be needed in this file.
#if !FIX_FILTERSCRIPT
static
#endif
stock
	/**
	 * <remarks>
	 * Runtime equivalent of "FILTERSCRIPT" for when it is not set by the user.
	 * </remarks>
	 */
	bool:_FIXES_gIsFilterscript;

#if !FIX_JIT
static
#endif
stock
	/**
	 * <remarks>
	 * True when the JIT plugin is being used.
	 * </remarks>
	 */
	bool:_FIXES_gIsJIT = false;

#if !FIX_OS
static
#endif
stock
	/**
	 * <remarks>
	 * True on Windows, false on Linux.
	 * </remarks>
	 */
	bool:_FIXES_gIsWindows;

#if FIX_GetMaxPlayers
stock
	/**
	 * <remarks>
	 * `maxplayers` server var value.
	 * </remarks>
	 */
	_FIXES_gsMaxPlayers = MAX_PLAYERS;
#endif

#if FIX_GetWorldTime
stock
	/**
	 * <remarks>
	 * Stores the current server world time (hours).
	 * </remarks>
	 */
	_FIXES_gsWorldTime = 12;
#endif

/*

                                                88                                                                      
                 ,d                             88                                                               ,d     
                 88                             88                                                               88     
    ,adPPYba,  MM88MMM  ,adPPYba,    ,adPPYba,  88   ,d8       ,adPPYba,   ,adPPYba,   8b,dPPYba,   ,adPPYba,  MM88MMM  
    I8[    ""    88    a8"     "8a  a8"     ""  88 ,a8"       a8"     ""  a8"     "8a  88P'   `"8a  I8[    ""    88     
     `"Y8ba,     88    8b       d8  8b          8888[         8b          8b       d8  88       88   `"Y8ba,     88     
    aa    ]8I    88,   "8a,   ,a8"  "8a,   ,aa  88`"Yba,      "8a,   ,aa  "8a,   ,a8"  88       88  aa    ]8I    88,    
    `"YbbdP"'    "Y888  `"YbbdP"'    `"Ybbd8"'  88   `Y8a      `"Ybbd8"'   `"YbbdP"'   88       88  `"YbbdP"'    "Y888  



*/

stock const
	/**
	 * <remarks>
	 * A single re-usable null string.  Const not static because it is used in
	 * macros <c>HideGameTextForAll</c> and <c>HideGameTextForPlayer</c>.
	 * </remarks>
	 */
	FIXES_gcNull[] = "\1";

/*

                                             88                                                             88         
                 ,d                   ,d     ""                              ,d                             88         
                 88                   88                                     88                             88         
    ,adPPYba,  MM88MMM  ,adPPYYba,  MM88MMM  88   ,adPPYba,     ,adPPYba,  MM88MMM  ,adPPYba,    ,adPPYba,  88   ,d8   
    I8[    ""    88     ""     `Y8    88     88  a8"     ""     I8[    ""    88    a8"     "8a  a8"     ""  88 ,a8"    
     `"Y8ba,     88     ,adPPPPP88    88     88  8b              `"Y8ba,     88    8b       d8  8b          8888[      
    aa    ]8I    88,    88,    ,88    88,    88  "8a,   ,aa     aa    ]8I    88,   "8a,   ,a8"  "8a,   ,aa  88`"Yba,   
    `"YbbdP"'    "Y888  `"8bbdP"Y8    "Y888  88   `"Ybbd8"'     `"YbbdP"'    "Y888  `"YbbdP"'    `"Ybbd8"'  88   `Y8a  



*/

#if FIXES_Debug
new
#else
static stock
#endif
	/**
	 * <remarks>
	 * A single re-usable space.  Static not const because it is used in this
	 * file in functions that don't take <c>const</c> strings.
	 * </remarks>
	 */
	FIXES_gsSpace[] = " ",
	/**
	 * <remarks>
	 * Only determine the OS once.
	 * </remarks>
	 */
	bool:FIXES_gsKnownOS = false,
	/**
	 * <remarks>
	 * A record of which players are connected to the server.  We ensure that
	 * this only exists when required, since it depends on add and remove
	 * functions to be called at the right time.
	 * </remarks>
	 */
#if _FIX_Menus || FIX_GetPlayerMenu || FIX_OnPlayerDisconnect || FIX_GameText || FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable
	FIXES_gsPlayersIterator[MAX_PLAYERS + 1] = {0, 1, ...},
#endif
	/**
	 * <remarks>
	 * A record of which menus have and haven't been shown yet.
	 * </remarks>
	 */
	FIXES_gsValidMenus[_FIXES_CEILDIV(_:MAX_MENUS, cellbits)],
	/**
	 * <remarks>
	 * A player's IP as a 32-bit integer.
	 * </remarks>
	 */
#if FIXES_SilentKick && (FIX_OnVehicleMod || FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2)
	FIXES_gsPlayerIP[MAX_PLAYERS] = {-1, ...},
#endif
	/**
	 * <remarks>
	 * Stores the locked vehicle's id that the player
	 * is currently trying to enter.
	 * </remarks>
	 */
#if FIX_OnPlayerEnterVehicle_3
	FIXES_gsPlayerVehicleID[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Stores the server tick when the player started
	 * trying to enter the locked vehicle.
	 * </remarks>
	 */
	FIXES_gsPlayerVehicleTickCount[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Boolean: Stores if a certain vehicle is 'locked' or not.
	 * </remarks>
	 */
	bool:FIXES_gsVehicleIsLocked[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The skin the player is currently using.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetPlayerSkin
	FIXES_gsPlayerSkin[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * Collection of boolean values for players.
	 * </remarks>
	 */
	e_FIXES_BOOLS:FIXES_gsPlayerBools[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Handle to read from server.cfg.
	 * </remarks>
	 */
	File:FIXES_gsServerCFG,
	/**
	 * <remarks>
	 * All data for players on where their worldbounds are and where they last
	 * were before they went through the bounds by crouching.
	 *
	 * P = Previous.
	 * L = Lower.
	 * U = Upper.
	 *
	 * </remarks>
	 */
#if FIX_SetPlayerWorldBounds || FIX_GetPlayerWorldBounds
	// Previous.
	Float:FIXES_gsWorldbounds_PX[MAX_PLAYERS],
	Float:FIXES_gsWorldbounds_PY[MAX_PLAYERS],
	Float:FIXES_gsWorldbounds_PZ[MAX_PLAYERS],
	// Lower.
	Float:FIXES_gsWorldbounds_LX[MAX_PLAYERS],
	Float:FIXES_gsWorldbounds_LY[MAX_PLAYERS],
	// Upper.
	Float:FIXES_gsWorldbounds_UX[MAX_PLAYERS],
	Float:FIXES_gsWorldbounds_UY[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * Stores the weapon set by "SetPlayerArmedWeapon" when in a vehicle.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetPlayerWeapon
	FIXES_gsPlayerWeapon[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * What vehicle the player is due to go in.
	 * </remarks>
	 */
	FIXES_gsVehicleSeatData[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Stores the true ID of the dialog the player is looking at to prevent
	 * spoofing.
	 * </remarks>
	 */
#if FIX_OnDialogResponse || FIX_GetPlayerDialog
	FIXES_gsPlayerDialog[MAX_PLAYERS] = {-1, ...},
#endif
	/**
	 * <remarks>
	 * Stores the ID of the player weather.
	 * </remarks>
	 */
#if FIX_GetPlayerWeather
	FIXES_gsPlayerWeather[MAX_PLAYERS] = {-1, ...},
#endif
	/**
	 * <remarks>
	 * Stores the ID of the server weather.
	 * </remarks>
	 */
#if FIX_GetWeather
	FIXES_gsServerWeather = 10,
#endif
	/**
	 * <remarks>
	 * The player's current interior.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetPlayerInterior
	FIXES_gsPlayerInterior[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * A collection of 1-bit options, compressed together to save space.
	 * </remarks>
	 */
	e_FIXES_SETTINGS:FIXES_gsSettings = e_FIXES_SETTINGS_SECOND_USE,
	/**
	 * <remarks>
	 * The last animation a player used.
	 * </remarks>
	 */
#if FIX_OnPlayerDeath
	FIXES_gsLastAnimation[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * A player's cash before dying.
	 * </remarks>
	 */
#if FIX_OnPlayerSpawn
	FIXES_gsPlayerLastCash[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * The weapon to set after re-enter to vehicle.
	 * </remarks>
	 */
	FIXES_gsDriveByWeapon[MAX_PLAYERS],
	/**
	 * <remarks>
	 * The menu the player can currently see.
	 * </remarks>
	 */
	Menu:FIXES_gsCurrentMenu[MAX_PLAYERS] = {Menu:INVALID_MENU, ...},
	/**
	 * <remarks>
	 * The pre-defined TextDraw styles used to recreate the bugged GameText
	 * styles for GameTextForAll.
	 * </remarks>
	 */
#if FIX_GameText
	Text:FIXES_gsGTStyle[FIXES_GT_STYLE_COUNT],
#endif
	/**
	 * <remarks>
	 * A linked list of which players can see a certain GameText style.
	 * </remarks>
	 */
#if FIX_GameText
	FIXES_gsPlayerPGTShown[FIXES_GT_STYLE_COUNT][MAX_PLAYERS + 1],
#endif
	/**
	 * <remarks>
	 * The predefined TextDraw styles used to recreate the bugged GameText
	 * styles for GameTextForPlayer.
	 * </remarks>
	 */
#if FIX_GameText
	PlayerText:FIXES_gsPGTStyle[MAX_PLAYERS][FIXES_GT_STYLE_COUNT],
#endif
	/**
	 * <remarks>
	 * The timers used to hide per-player GameText messages.
	 * </remarks>
	 */
#if FIX_GameText
	FIXES_gsGTTimer[FIXES_GT_STYLE_COUNT][MAX_PLAYERS + 1],
#endif
	/**
	 * <remarks>
	 * Used for storing the timer ID for deferring class selection animation
	 * application.
	 * </remarks>
	 */
#if FIX_ApplyAnimation_2
	FIXES_gsPlayerAnimTimer[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * Used for storing the animation name.
	 * </remarks>
	 */
#if FIX_ApplyAnimation_2
	FIXES_gsPlayerAnimName[MAX_PLAYERS * 64],
#endif
	/**
	 * <remarks>
	 * Which animation libraries the player has synced.
	 * </remarks>
	 */
#if FIX_ApplyAnimation_2
	FIXES_gsPlayerAnimLibs[MAX_PLAYERS][_FIXES_CEILDIV(135, cellbits)],
#endif
	/**
	 * <remarks>
	 * Used for storing the timer ID for deferring class selection animation
	 * application.
	 * </remarks>
	 */
#if FIX_ApplyActorAnimation_2
	FIXES_gsActorAnimTimer[MAX_ACTORS],
#endif
	/**
	 * <remarks>
	 * Used for storing the animation name.
	 * </remarks>
	 */
#if FIX_ApplyActorAnimation_2
	FIXES_gsActorAnimName[MAX_ACTORS * 64],
#endif
	/**
	 * <remarks>
	 * Which animation libraries the actor has synced.
	 * </remarks>
	 */
#if FIX_ApplyActorAnimation_2
	FIXES_gsActorAnimLibs[MAX_ACTORS][_FIXES_CEILDIV(135, cellbits)],
#endif
	/**
	 * <remarks>
	 * The timers used to prevent players seating.
	 * </remarks>
	 */
#if FIX_PassengerSeating
	FIXES_gsPSTimer[MAX_PLAYERS],
#endif
	/**
	 * <remarks>
	 * The vehicle's stereo used in GetVehicleComponent.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetVehicleComponentInSlot
	FIXES_gsStereo[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The vehicle's front bumper used in GetVehicleComponent.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetVehicleComponentInSlot
	FIXES_gsFrontBumper[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The vehicle's rear bumper used in GetVehicleComponent.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetVehicleComponentInSlot
	FIXES_gsRearBumper[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The vehicle's front bullbar used in GetVehicleComponent.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetVehicleComponentInSlot
	FIXES_gsFrontBullbar[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The vehicle's rear bullbar used in GetVehicleComponent.
	 * </remarks>
	 */
#if FIXES_Single && FIX_GetVehicleComponentInSlot
	FIXES_gsRearBullbar[MAX_VEHICLES],
#endif
	/**
	 * <remarks>
	 * The player id who is getting carjacked before the car teleports.
	 * </remarks>
	 */
#if FIX_SilentTeleport
	FIXES_gsJackedId[MAX_PLAYERS] = {INVALID_PLAYER_ID, ...},
#endif
	/**
	 * <remarks>
	 * The position of the character right-trimmed from a "const" string.
	 * </remarks>
	 */
	FIXES_gsTrimPos,
	/**
	 * <remarks>
	 * The character right-trimmed from a "const" string.
	 * </remarks>
	 */
	FIXES_gsTrimChr;

/*

                                             88                                                             88                                                                      
                 ,d                   ,d     ""                              ,d                             88                                                               ,d     
                 88                   88                                     88                             88                                                               88     
    ,adPPYba,  MM88MMM  ,adPPYYba,  MM88MMM  88   ,adPPYba,     ,adPPYba,  MM88MMM  ,adPPYba,    ,adPPYba,  88   ,d8       ,adPPYba,   ,adPPYba,   8b,dPPYba,   ,adPPYba,  MM88MMM  
    I8[    ""    88     ""     `Y8    88     88  a8"     ""     I8[    ""    88    a8"     "8a  a8"     ""  88 ,a8"       a8"     ""  a8"     "8a  88P'   `"8a  I8[    ""    88     
     `"Y8ba,     88     ,adPPPPP88    88     88  8b              `"Y8ba,     88    8b       d8  8b          8888[         8b          8b       d8  88       88   `"Y8ba,     88     
    aa    ]8I    88,    88,    ,88    88,    88  "8a,   ,aa     aa    ]8I    88,   "8a,   ,a8"  "8a,   ,aa  88`"Yba,      "8a,   ,aa  "8a,   ,a8"  88       88  aa    ]8I    88,    
    `"YbbdP"'    "Y888  `"8bbdP"Y8    "Y888  88   `"Ybbd8"'     `"YbbdP"'    "Y888  `"YbbdP"'    `"Ybbd8"'  88   `Y8a      `"Ybbd8"'   `"YbbdP"'   88       88  `"YbbdP"'    "Y888  



*/

#if FIXES_Debug
new
#else
static stock const
#endif
	/**
	 * <remarks>
	 * This variable records wether or not this player is brand new to the
	 * server, and not just having "OnPlayerConnect" called due to a script
	 * load.  There are certain functions that need applying only the very first
	 * time they connect, then this gets set.
	 * </remarks>
	 */
#if !FIXES_Single
	FIXES_pvarNotNewPlayer[] = "FIXES_pvarNotNewPlayer",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's current weapon.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_GetPlayerWeapon
	FIXES_pvarPlayerWeapon[] = "FIXES_pvarPlayerWeapon",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's current skin.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_GetPlayerSkin
	FIXES_pvarPlayerSkin[] = "FIXES_pvarPlayerSkin",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's spectator mode.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_SetPlayerCamera
	FIXES_pvarPlayerSpectate[] = "FIXES_pvarPlayerSpectate",
#endif
	/**
	 * <remarks>
	 * Name of the kick timer function.
	 * </remarks>
	 */
#if FIX_Kick
	FIXES_gscKick[] = "_FIXES_Kick",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store a player's kick timer.
	 * </remarks>
	 */
#if FIX_Kick
	FIXES_pvarKick[] = "FIXES_pvarKick",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's current dialogid.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_OnDialogResponse || FIX_GetPlayerDialog
	FIXES_pvarPlayerDialog[] = "FIXES_pvarPlayerDialog",
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's current weather.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_GetPlayerWeather
	FIXES_pvarPlayerWeather[] = "FIXES_pvarPlayerWeather",
#endif
	/**
	 * <remarks>
	 * A player's current interior.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_GetPlayerInterior
	FIXES_pvarPlayerInterior[] = "FIXES_pvarPlayerInterior",
#endif
	/**
	 * <remarks>
	 * Used in OnDialogResponse to be able to get the correct ID in multiple
	 * scripts while still correctly resetting the ID for future use.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_OnDialogResponse
	FIXES_pvarCurrentDialog[] = "FIXES_pvarCurrentDialog",
#endif
	/**
	 * <remarks>
	 * Used in OnPlayerDeath to save a player's cash before death.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_OnPlayerSpawn
	FIXES_pvarPlayerLastCash[] = "FIXES_pvarPlayerLastCash",
#endif
	/**
	 * <remarks>
	 * Name of the GameText hide timer function.
	 * </remarks>
	 */
	FIXES_gscHideGameTextTimer[] = "_FIXES_HideGameTextTimer",
	/**
	 * <remarks>
	 * Name of the Drive-By timer function.
	 * </remarks>
	 */
	FIXES_gscDriveBy[] = "_FIXES_DriveBy",
	/**
	 * <remarks>
	 * Name of the SetCamera timer function.
	 * </remarks>
	 */
	FIXES_gscSetCamera[] = "_FIXES_SetCamera",
	/**
	 * <remarks>
	 * Name of the SetTime timer function.
	 * </remarks>
	 */
	FIXES_gscSetTime[] = "_FIXES_SetTime",
	/**
	 * <remarks>
	 * Name of the SetColor timer function.
	 * </remarks>
	 */
	FIXES_gscSetColor[] = "_FIXES_SetColor",
	/**
	 * <remarks>
	 * Name of the SetCheckpoint timer function.
	 * </remarks>
	 */
	FIXES_gscSetCheckpoint[] = "_FIXES_SetCheckpoint",
	/**
	 * <remarks>
	 * Name of the SetCheckpoint timer function.
	 * </remarks>
	 */
	FIXES_gscPrintFFS[] = "* FIXES_PRINTF (FS):",
	/**
	 * <remarks>
	 * Name of the SetCheckpoint timer function.
	 * </remarks>
	 */
	FIXES_gscPrintFGM[] = "* FIXES_PRINTF (GM):",	/**
	 * <remarks>
	 * <c>***</c>, for debug prints.
	 * </remarks>
	 */
	FIXES_gscThreeStars[] = "***",
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's checkpoint state.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_SetPlayerCheckpoint
	FIXES_pvarPlayerCheckpoint[] = "FIXES_pvarPlayerCheckpoint",
#endif
	/**
	 * <remarks>
	 * Name of the SetRaceCheckpoint timer function.
	 * </remarks>
	 */
	FIXES_gscSetRaceCheckpoint[] = "_FIXES_SetRaceCheckpoint",
	/**
	 * <remarks>
	 * All vehicle primary colours from carcols.dat.
	 * </remarks>
	 */
#if FIX_CreateVehicle || FIX_API
	FIXES_gscVehiclePrimary[1158] =
		{
			4, 123, 113, 101, 75, 62, 40, 36,      // 400 - landstal
			41, 47, 52, 66, 74, 87, 91, 113,       // 401 - bravura
			10, 13, 22, 30, 39, 90, 98, 110,       // 402 - buffalo
			36, 37, 30, 28, 25, 40, 101, 113,      // 403 - linerun
			113, 119, 123, 109, 101, 95, 83, 66,   // 404 - peren
			11, 24, 36, 40, 75, 91, 123, 4,        // 405 - sentinel
			1,                                     // 406 - dumper
			3,                                     // 407 - firetruk
			26,                                    // 408 - trash
			1,                                     // 409 - stretch
			4, 9, 10, 25, 36, 40, 45, 84,          // 410 - manana
			12, 64, 123, 116, 112, 106, 80, 75,    // 411 - infernus
			9, 10, 11, 25, 27, 29, 30, 37,         // 412 - voodoo
			87, 88, 91, 105, 109, 119, 4, 25,      // 413 - pony
			25, 28, 43, 67, 72, 9, 95, 24,         // 414 - mule
			20, 25, 36, 40, 62, 75, 92, 0,         // 415 - cheetah
			1,                                     // 416 - ambulan
			                                       // 417 - leviathn
			119, 117, 114, 108, 95, 81, 61, 41,    // 418 - moonbeam
			45, 47, 33, 13, 54, 69, 59, 87,        // 419 - esperant
			6,                                     // 420 - taxi
			4, 13, 25, 30, 36, 40, 75, 95,         // 421 - washing
			96, 97, 101, 111, 113, 83, 67,         // 422 - bobcat
			1, 1, 1, 1, 1, 1,                      // 423 - mrwhoop
			1, 2, 3, 3, 6, 15, 24, 35,             // 424 - bfinject
			43,                                    // 425 - hunter
			37, 42, 53, 62, 7, 10, 11, 15,         // 426 - premier
			0,                                     // 427 - enforcer
			4,                                     // 428 - securica
			12, 13, 14, 1, 2, 1, 3, 10,            // 429 - banshee
			46,                                    // 430 - predator
			71, 75, 92, 47, 55, 59, 71, 82,        // 431 - bus
			43,                                    // 432 - rhino
			43,                                    // 433 - barracks
			1, 12, 2, 6, 4, 46, 53,                // 434 - hotknife
			1,                                     // 435 - artict1
			83, 87, 92, 95, 109, 119, 11,          // 436 - previon
			54, 79, 87, 95, 98, 105, 123, 125,     // 437 - coach
			6,                                     // 438 - cabbie
			57, 8, 43, 54, 67, 37, 65, 25,         // 439 - stallion
			34, 32, 20, 110, 66, 84, 118, 121,     // 440 - rumpo
			2, 79, 82, 67, 126, 70, 110, 67,       // 441 - rcbandit
			0, 11, 25, 36, 40, 75, 0, 0,           // 442 - romero
			4, 20, 24, 25, 36, 40, 54, 84,         // 443 - packer
			32, 32, 32, 32, 32, 32,                // 444 - monster
			34, 35, 37, 39, 41, 43, 45, 47,        // 445 - admiral
			0, 1, 3, 1, 1, 1, 1, 1,                // 446 - squalo
			75,                                    // 447 - seaspar
			3,                                     // 448 - pizzaboy
			1,                                     // 449 - tram
			1,                                     // 450 - artict2
			123, 125, 36, 16, 18, 46, 61, 75,      // 451 - turismo
			1, 1, 1, 1, 1, 1, 1, 1,                // 452 - speeder
			56,                                    // 453 - reefer
			26,                                    // 454 - tropic
			84, 84, 84, 32, 43, 1, 77, 32,         // 455 - flatbed
			84, 91, 102, 105, 110, 121, 12, 23,    // 456 - yankee
			58, 2, 63, 18, 32, 45, 13, 34,         // 457 - caddy
			91, 101, 109, 113, 4, 25, 30, 36,      // 458 - solair
			26, 28, 44, 51, 57, 72, 106, 112,      // 459 - topfun
			1, 1, 1, 1, 17, 46, 46, 57,            // 460 - skimmer
			36, 37, 43, 53, 61, 75, 79, 88,        // 461 - pcj600
			12, 13, 14, 1, 2, 1, 3, 10,            // 462 - faggio
			79, 84, 7, 11, 19, 22, 36, 53,         // 463 - freeway
			14,                                    // 464 - rcbaron
			14,                                    // 465 - rcraider
			67, 68, 78, 2, 16, 18, 25, 45,         // 466 - glendale
			51, 58, 60, 68, 2, 13, 22, 36,         // 467 - oceanic
			6, 46, 53, 3,                          // 468 - sanchez
			1,                                     // 469 - sparrow
			43,                                    // 470 - patriot
			120, 103, 120, 74, 120, 74, 120, 66,   // 471 - quad
			56, 56,                                // 472 - coastg
			56, 56,                                // 473 - dinghy
			97, 81, 105, 110, 91, 74, 84, 83,      // 474 - hermes
			2, 9, 17, 21, 33, 37, 41, 56,          // 475 - sabre
			6, 7, 1, 89, 119, 103, 77, 71,         // 476 - rustler
			92, 94, 101, 121, 0, 22, 36, 75,       // 477 - zr350
			72, 66, 59, 45, 40, 39, 35, 20,        // 478 - walton
			27, 59, 60, 55, 54, 49, 45, 40,        // 479 - regina
			73, 12, 2, 6, 4, 46, 53,               // 480 - comet
			1, 3, 6, 46, 65, 14, 12, 26,           // 481 - bmx
			41, 48, 52, 64, 71, 85, 10, 62,        // 482 - burrito
			1, 1, 1, 1, 0, 3, 16, 17,              // 483 - camper
			12, 50, 40, 66,                        // 484 - marquis
			1, 1, 1, 1, 1, 1, 1,                   // 485 - baggage
			1,                                     // 486 - dozer
			26, 29, 26, 54, 26, 3, 12, 74,         // 487 - maverick
			2, 2,                                  // 488 - vcnmav
			13, 14, 120, 112, 84, 76,              // 489 - rancher
			0,                                     // 490 - fbiranch
			40, 71, 52, 64, 30, 60,                // 491 - virgo
			30, 77, 81, 24, 28, 49, 52, 71,        // 492 - greenwoo
			36,                                    // 493 - jetmax
			36, 36, 42, 42, 54, 75, 92, 98,        // 494 - hotring
			123, 119, 118, 116, 114, 101, 88, 5,   // 495 - sandking
			74, 66, 53, 37, 22, 20, 9, 0,          // 496 - blistac
			0,                                     // 497 - polmav
			11, 13, 20, 24, 27, 36, 37, 43,        // 498 - boxville
			109, 109, 112, 10, 30, 32, 84, 84,     // 499 - benson
			75, 40, 40, 28, 25, 21, 13, 4,         // 500 - mesa
			14,                                    // 501 - rcgoblin
			7, 36, 51, 53, 58, 75, 75, 79,         // 502 - hotrina
			83, 87, 87, 98, 101, 103, 117, 123,    // 503 - hotrinb
			51, 57, 45, 34, 65, 14, 12, 26,        // 504 - bloodra
			13, 14, 120, 112, 84, 76,              // 505 - rnchlure
			3, 6, 7, 52, 76,                       // 506 - supergt
			37, 42, 53, 62, 7, 10, 11, 15,         // 507 - elegant
			1,                                     // 508 - journey
			7, 74, 61, 16, 25, 30, 36, 53,         // 509 - bike
			43, 46, 39, 28, 16, 6, 5, 2,           // 510 - mtbike
			3, 4, 7, 8, 12, 27, 34, 37,            // 511 - beagle
			17, 15, 32, 45, 52, 57, 61, 96,        // 512 - cropdust
			38, 21, 21, 30, 54, 55, 48, 51,        // 513 - stunt
			10, 25, 28, 36, 40, 54, 75, 113,       // 514 - petro
			13, 24, 63, 42, 54, 39, 11, 62,        // 515 - rdtrain
			116, 119, 122, 4, 9, 24, 27, 36,       // 516 - nebula
			37, 36, 40, 43, 47, 51, 54, 55,        // 517 - majestic
			2, 9, 17, 21, 33, 37, 41, 56,          // 518 - buccanee
			1,                                     // 519 - shamal
			                                       // 520 - hydra
			74, 75, 87, 92, 115, 25, 36, 118,      // 521 - fcr900
			3, 3, 6, 7, 8, 36, 39, 51,             // 522 - nrg500
			                                       // 523 - copbike
			60, 61, 65, 61, 81, 62, 83, 83,        // 524 - cement
			1, 17, 18, 22, 36, 44, 52,             // 525 - towtruck
			2, 9, 17, 21, 33, 37, 41, 56,          // 526 - fortune
			52, 53, 66, 75, 76, 81, 95, 109,       // 527 - cadrona
			                                       // 528 - fbitruck
			37, 42, 53, 62, 7, 10, 11, 15,         // 529 - willard
			110, 111, 112, 114, 119, 122, 4, 13,   // 530 - forklift
			2, 36, 51, 91, 11, 40,                 // 531 - tractor
			                                       // 532 - combine
			73, 74, 75, 77, 79, 83, 84, 91,        // 533 - feltzer
			37, 42, 53, 62, 7, 10, 11, 15,         // 534 - remingtn
			3, 28, 31, 55, 66, 97, 123, 118,       // 535 - slamvan
			9, 12, 26, 30, 32, 37, 57, 71,         // 536 - blade
			1,                                     // 537 - freight
			1,                                     // 538 - streak
			96, 86, 79, 70, 61, 75, 75,            // 539 - vortex
			37, 42, 53, 62, 7, 10, 11, 15,         // 540 - vincent
			51, 58, 60, 68, 2, 13, 22, 36,         // 541 - bullet
			13, 24, 31, 32, 45, 113, 119, 122,     // 542 - clover
			76, 32, 43, 67, 11, 8, 2, 83,          // 543 - sadler
			3,                                     // 544 - firela
			50, 47, 44, 40, 39, 30, 28, 9,         // 545 - hustler
			62, 78, 2, 3, 2, 113, 119, 7,          // 546 - intruder
			122, 123, 125, 10, 24, 37, 55, 66,     // 547 - primo
			1,                                     // 548 - cargobob
			74, 72, 75, 79, 83, 84, 89, 91,        // 549 - tampa
			37, 42, 53, 62, 7, 10, 11, 15,         // 550 - sunrise
			67, 72, 75, 83, 91, 101, 109, 20,      // 551 - merit
			56, 49, 26,                            // 552 - utility
			38, 55, 61, 71, 91, 98, 102, 111,      // 553 - nevada
			53, 15, 45, 34, 65, 14, 12, 43,        // 554 - yosemite
			51, 58, 60, 68, 2, 13, 22, 36,         // 555 - windsor
			1,                                     // 556 - monstera
			1,                                     // 557 - monsterb
			112, 116, 117, 24, 30, 35, 36, 40,     // 558 - uranus
			51, 58, 60, 68, 2, 13, 22, 36,         // 559 - jester
			52, 9, 17, 21, 33, 37, 41, 56,         // 560 - sultan
			57, 8, 43, 54, 67, 37, 65, 25,         // 561 - stratum
			36, 35, 17, 11, 116, 113, 101, 92,     // 562 - elegy
			1,                                     // 563 - raindanc
			                                       // 564 - rctiger
			37, 42, 53, 62, 7, 10, 11, 15,         // 565 - flash
			109, 30, 95, 84, 83, 72, 71, 52,       // 566 - tahoma
			97, 88, 90, 93, 97, 99, 102, 114,      // 567 - savanna
			2, 9, 17, 21, 33, 37, 41, 56,          // 568 - bandito
			                                       // 569 - freiflat
			1,                                     // 570 - streakc
			2, 36, 51, 91, 11, 40,                 // 571 - kart
			94, 101, 116, 117, 4, 25, 30, 37,      // 572 - mower
			91, 115, 85, 79, 78, 77, 79, 86,       // 573 - duneride
			26,                                    // 574 - sweeper
			12, 19, 31, 25, 38, 51, 57, 66,        // 575 - broadway
			67, 68, 72, 74, 75, 76, 79, 84,        // 576 - tornado
			1, 8, 8, 8, 23, 40,                    // 577 - at400
			1,                                     // 578 - dft30
			37, 42, 53, 62, 7, 10, 11, 15,         // 579 - huntley
			92, 81, 67, 66, 61, 53, 51, 47, 43,    // 580 - stafford
			54, 58, 66, 72, 75, 87, 101, 36,       // 581 - bf400
			41, 41, 49, 56, 110, 112, 114, 119,    // 582 - newsvan
			1,                                     // 583 - tug
			1,                                     // 584 - petrotr
			37, 42, 53, 62, 7, 10, 11, 15,         // 585 - emperor
			119, 122, 8, 10, 13, 25, 27, 32,       // 586 - wayfarer
			36, 40, 43, 53, 72, 75, 95, 101,       // 587 - euros
			1,                                     // 588 - hotdog
			37, 31, 23, 22, 7, 124, 114, 112,      // 589 - club
			                                       // 590 - freibox
			1,                                     // 591 - artict3
			1,                                     // 592 - androm
			51, 58, 60, 68, 2, 13, 22, 36,         // 593 - dodo
			                                       // 594 - rccam
			112,                                   // 595 - launch
			0,                                     // 596 - copcarla
			0,                                     // 597 - copcarsf
			0,                                     // 598 - copcarvg
			0,                                     // 599 - copcarru
			81, 32, 43, 67, 11, 8, 2, 83,          // 600 - picador
			1,                                     // 601 - swatvan
			58, 69, 75, 18, 32, 45, 13, 34,        // 602 - alpha
			58, 69, 75, 18, 32, 45, 13, 34,        // 603 - phoenix
			67, 68, 78, 2, 16, 18, 25, 45,         // 604 - glenshit
			61, 32, 43, 67, 11, 8, 2, 83,          // 605 - sadlshit
			                                       // 606 - bagboxa
			                                       // 607 - bagboxb
			1,                                     // 608 - tugstair
			36                                     // 609 - boxburg
			                                       // 610 - farmtr1
			                                       // 611 - utiltr1
		},
#endif
	/**
	 * <remarks>
	 * All vehicle secondary colours from carcols.dat.
	 * </remarks>
	 */
#if FIX_CreateVehicle || FIX_API
	FIXES_gscVehicleSecondary[1158] =
		{
			1, 1, 1, 1, 1, 1, 1, 1,                // 400 - landstal
			41, 47, 52, 66, 74, 87, 91, 113,       // 401 - bravura
			10, 13, 22, 30, 39, 90, 98, 110,       // 402 - buffalo
			1, 1, 1, 1, 1, 1, 1, 1,                // 403 - linerun
			39, 50, 92, 100, 101, 105, 110, 25,    // 404 - peren
			1, 1, 1, 1, 1, 1, 1, 1,                // 405 - sentinel
			1,                                     // 406 - dumper
			1,                                     // 407 - firetruk
			26,                                    // 408 - trash
			1,                                     // 409 - stretch
			1, 1, 1, 1, 1, 1, 1, 1,                // 410 - manana
			1, 1, 1, 1, 1, 1, 1, 1,                // 411 - infernus
			1, 8, 1, 8, 1, 8, 1, 8,                // 412 - voodoo
			1, 1, 1, 1, 1, 1, 1, 1,                // 413 - pony
			1, 1, 1, 1, 1, 1, 1, 1,                // 414 - mule
			1, 1, 1, 1, 1, 1, 1, 1,                // 415 - cheetah
			3,                                     // 416 - ambulan
			                                       // 417 - leviathn
			119, 227, 114, 108, 95, 81, 61, 41,    // 418 - moonbeam
			75, 76, 75, 76, 75, 76, 75, 76,        // 419 - esperant
			1,                                     // 420 - taxi
			1, 1, 1, 1, 1, 1, 1, 1,                // 421 - washing
			25, 25, 25, 31, 36, 57, 59,            // 422 - bobcat
			16, 56, 17, 53, 5, 35,                 // 423 - mrwhoop
			0, 2, 2, 6, 16, 30, 53, 61,            // 424 - bfinject
			0,                                     // 425 - hunter
			37, 42, 53, 62, 7, 10, 11, 15,         // 426 - premier
			1,                                     // 427 - enforcer
			75,                                    // 428 - securica
			12, 13, 14, 2, 1, 3, 1, 10,            // 429 - banshee
			26,                                    // 430 - predator
			59, 59, 72, 74, 83, 83, 87, 87,        // 431 - bus
			0,                                     // 432 - rhino
			0,                                     // 433 - barracks
			1, 12, 2, 6, 4, 46, 53,                // 434 - hotknife
			1,                                     // 435 - artict1
			1, 1, 1, 1, 1, 45, 1,                  // 436 - previon
			7, 7, 7, 16, 20, 20, 20, 21,           // 437 - coach
			76,                                    // 438 - cabbie
			8, 17, 21, 38, 8, 78, 79, 78,          // 439 - stallion
			34, 32, 20, 110, 66, 84, 118, 121,     // 440 - rumpo
			96, 42, 54, 86, 96, 96, 54, 98,        // 441 - rcbandit
			0, 105, 109, 0, 36, 36, 36, 109,       // 442 - romero
			1, 1, 1, 1, 1, 1, 1, 1,                // 443 - packer
			36, 42, 53, 66, 14, 32,                // 444 - monster
			34, 35, 37, 39, 41, 43, 45, 47,        // 445 - admiral
			0, 5, 3, 22, 35, 44, 53, 57,           // 446 - squalo
			2,                                     // 447 - seaspar
			6,                                     // 448 - pizzaboy
			74,                                    // 449 - tram
			1,                                     // 450 - artict2
			123, 125, 36, 16, 18, 46, 61, 75,      // 451 - turismo
			3, 5, 16, 22, 35, 44, 53, 57,          // 452 - speeder
			56,                                    // 453 - reefer
			26,                                    // 454 - tropic
			15, 58, 31, 74, 31, 31, 31, 74,        // 455 - flatbed
			63, 63, 65, 72, 93, 93, 95, 1,         // 456 - yankee
			1, 1, 1, 1, 1, 1, 1, 1,                // 457 - caddy
			1, 1, 1, 1, 1, 1, 1, 1,                // 458 - solair
			26, 28, 44, 51, 57, 72, 106, 112,      // 459 - topfun
			3, 9, 18, 30, 23, 23, 32, 34,          // 460 - skimmer
			1, 1, 1, 1, 1, 1, 1, 1,                // 461 - pcj600
			12, 13, 14, 2, 1, 3, 1, 10,            // 462 - faggio
			79, 84, 7, 11, 19, 22, 36, 53,         // 463 - freeway
			75,                                    // 464 - rcbaron
			75,                                    // 465 - rcraider
			76, 76, 76, 76, 76, 76, 76, 88,        // 466 - glendale
			1, 8, 1, 8, 1, 8, 1, 8,                // 467 - oceanic
			6, 46, 53, 3,                          // 468 - sanchez
			3,                                     // 469 - sparrow
			0,                                     // 470 - patriot
			117, 111, 114, 91, 112, 83, 113, 71,   // 471 - quad
			15, 53,                                // 472 - coastg
			15, 53,                                // 473 - dinghy
			1, 1, 1, 1, 1, 1, 1, 1,                // 474 - hermes
			39, 39, 1, 1, 0, 0, 29, 29,            // 475 - sabre
			7, 6, 6, 91, 117, 102, 87, 77,         // 476 - rustler
			1, 1, 1, 1, 1, 1, 1, 1,                // 477 - zr350
			1, 1, 1, 1, 1, 1, 1, 1,                // 478 - walton
			36, 36, 35, 41, 31, 23, 32, 29,        // 479 - regina
			45, 12, 2, 6, 4, 46, 53,               // 480 - comet
			1, 3, 6, 46, 9, 1, 9, 1,               // 481 - bmx
			41, 48, 52, 64, 71, 85, 10, 62,        // 482 - burrito
			31, 31, 20, 5, 6, 6, 0, 0,             // 483 - camper
			35, 32, 26, 36,                        // 484 - marquis
			73, 74, 75, 76, 77, 78, 79,            // 485 - baggage
			1,                                     // 486 - dozer
			14, 42, 57, 29, 3, 29, 39, 35,         // 487 - maverick
			26, 29,                                // 488 - vcnmav
			118, 123, 123, 120, 110, 102,          // 489 - rancher
			0,                                     // 490 - fbiranch
			65, 72, 66, 72, 72, 72,                // 491 - virgo
			26, 26, 27, 55, 56, 59, 69, 107,       // 492 - greenwoo
			13,                                    // 493 - jetmax
			117, 13, 30, 33, 36, 79, 101, 109,     // 494 - hotring
			124, 122, 117, 115, 108, 106, 99, 6,   // 495 - sandking
			72, 72, 56, 19, 22, 20, 14, 0,         // 496 - blistac
			1,                                     // 497 - polmav
			123, 120, 117, 112, 107, 105, 107, 93, // 498 - boxville
			25, 32, 32, 32, 44, 52, 66, 69,        // 499 - benson
			84, 84, 110, 119, 119, 119, 119, 119,  // 500 - mesa
			75,                                    // 501 - rcgoblin
			94, 88, 75, 75, 67, 67, 61, 62,        // 502 - hotrina
			66, 74, 75, 83, 100, 101, 116, 36,     // 503 - hotrinb
			39, 38, 29, 9, 9, 1, 9, 1,             // 504 - bloodra
			118, 123, 123, 120, 110, 102,          // 505 - rnchlure
			3, 6, 7, 52, 76,                       // 506 - supergt
			37, 42, 53, 62, 7, 10, 11, 15,         // 507 - elegant
			1,                                     // 508 - journey
			1, 1, 1, 1, 1, 1, 1, 1,                // 509 - bike
			43, 46, 39, 28, 16, 6, 5, 2,           // 510 - mtbike
			90, 90, 68, 66, 60, 97, 51, 51,        // 511 - beagle
			39, 123, 112, 88, 71, 67, 96, 96,      // 512 - cropdust
			51, 36, 34, 34, 34, 20, 18, 6,         // 513 - stunt
			1, 1, 1, 1, 1, 1, 1, 1,                // 514 - petro
			76, 77, 78, 76, 77, 78, 76, 77,        // 515 - rdtrain
			1, 1, 1, 1, 1, 1, 1, 1,                // 516 - nebula
			36, 36, 36, 41, 41, 72, 75, 84,        // 517 - majestic
			39, 39, 1, 1, 0, 0, 29, 29,            // 518 - buccanee
			1,                                     // 519 - shamal
			                                       // 520 - hydra
			74, 13, 118, 3, 118, 118, 0, 118,      // 521 - fcr900
			3, 8, 25, 79, 82, 105, 106, 118,       // 522 - nrg500
			                                       // 523 - copbike
			24, 27, 31, 61, 35, 61, 66, 64,        // 524 - cement
			1, 20, 20, 30, 43, 51, 54,             // 525 - towtruck
			39, 39, 1, 1, 0, 0, 29, 29,            // 526 - fortune
			1, 1, 1, 1, 1, 1, 1, 1,                // 527 - cadrona
			                                       // 528 - fbitruck
			37, 42, 53, 62, 7, 10, 11, 15,         // 529 - willard
			1, 1, 1, 1, 1, 1, 1, 1,                // 530 - forklift
			35, 2, 53, 2, 22, 35,                  // 531 - tractor
			                                       // 532 - combine
			1, 1, 1, 1, 1, 1, 1, 1,                // 533 - feltzer
			37, 42, 53, 62, 7, 10, 11, 15,         // 534 - remingtn
			1, 1, 1, 1, 1, 1, 1, 1,                // 535 - slamvan
			1, 1, 96, 96, 1, 1, 96, 96,            // 536 - blade
			1,                                     // 537 - freight
			1,                                     // 538 - streak
			67, 70, 74, 86, 98, 75, 91,            // 539 - vortex
			37, 42, 53, 62, 7, 10, 11, 15,         // 540 - vincent
			1, 8, 1, 8, 1, 8, 1, 8,                // 541 - bullet
			118, 118, 93, 92, 92, 92, 113, 113,    // 542 - clover
			8, 8, 8, 8, 11, 90, 2, 13,             // 543 - sadler
			1,                                     // 544 - firela
			1, 1, 96, 96, 1, 1, 96, 96,            // 545 - hustler
			37, 38, 62, 87, 78, 78, 62, 78,        // 546 - intruder
			1, 1, 1, 1, 1, 1, 1, 1,                // 547 - primo
			1,                                     // 548 - cargobob
			39, 39, 39, 39, 36, 36, 35, 35,        // 549 - tampa
			37, 42, 53, 62, 7, 10, 11, 15,         // 550 - sunrise
			1, 1, 1, 1, 1, 1, 1, 1,                // 551 - merit
			56, 49, 124,                           // 552 - utility
			9, 23, 74, 87, 87, 114, 119, 3,        // 553 - nevada
			32, 32, 32, 30, 32, 32, 32, 32,        // 554 - yosemite
			1, 1, 1, 1, 1, 1, 1, 1,                // 555 - windsor
			1,                                     // 556 - monstera
			1,                                     // 557 - monsterb
			1, 1, 1, 1, 1, 1, 1, 1,                // 558 - uranus
			1, 8, 1, 8, 1, 8, 1, 8,                // 559 - jester
			39, 39, 1, 1, 0, 0, 29, 29,            // 560 - sultan
			8, 17, 21, 38, 8, 78, 79, 78,          // 561 - stratum
			1, 1, 1, 1, 1, 1, 1, 1,                // 562 - elegy
			6,                                     // 563 - raindanc
			                                       // 564 - rctiger
			37, 42, 53, 62, 7, 10, 11, 15,         // 565 - flash
			1, 8, 1, 8, 1, 8, 1, 8,                // 566 - tahoma
			96, 64, 96, 64, 96, 81, 114, 1,        // 567 - savanna
			39, 39, 1, 1, 0, 0, 29, 29,            // 568 - bandito
			                                       // 569 - freiflat
			1,                                     // 570 - streakc
			35, 2, 53, 2, 22, 35,                  // 571 - kart
			1, 1, 1, 1, 1, 1, 1, 1,                // 572 - mower
			38, 43, 6, 7, 8, 18, 18, 24,           // 573 - duneride
			26,                                    // 574 - sweeper
			1, 96, 64, 96, 1, 96, 1, 96,           // 575 - broadway
			1, 96, 1, 8, 96, 8, 1, 96,             // 576 - tornado
			3, 7, 10, 16, 31, 44,                  // 577 - at400
			1,                                     // 578 - dft30
			37, 42, 53, 62, 7, 10, 11, 15,         // 579 - huntley
			92, 81, 67, 66, 61, 53, 51, 47, 43,    // 580 - stafford
			1, 1, 1, 1, 1, 1, 1, 1,                // 581 - bf400
			10, 20, 11, 123, 113, 116, 118, 101,   // 582 - newsvan
			1,                                     // 583 - tug
			1,                                     // 584 - petrotr
			37, 42, 53, 62, 7, 10, 11, 15,         // 585 - emperor
			1, 1, 1, 1, 1, 1, 1, 1,                // 586 - wayfarer
			1, 1, 1, 1, 1, 1, 1, 1,                // 587 - euros
			1,                                     // 588 - hotdog
			37, 31, 23, 22, 7, 124, 114, 112,      // 589 - club
			                                       // 590 - freibox
			1,                                     // 591 - artict3
			1,                                     // 592 - androm
			1, 8, 1, 8, 1, 8, 1, 8,                // 593 - dodo
			                                       // 594 - rccam
			20,                                    // 595 - launch
			1,                                     // 596 - copcarla
			1,                                     // 597 - copcarsf
			1,                                     // 598 - copcarvg
			1,                                     // 599 - copcarru
			8, 8, 8, 8, 11, 90, 2, 13,             // 600 - picador
			1,                                     // 601 - swatvan
			1, 1, 77, 1, 1, 45, 1, 1,              // 602 - alpha
			1, 1, 77, 1, 1, 45, 1, 1,              // 603 - phoenix
			76, 76, 76, 76, 76, 76, 76, 88,        // 604 - glenshit
			8, 8, 8, 8, 11, 90, 2, 13,             // 605 - sadlshit
			                                       // 606 - bagboxa
			                                       // 607 - bagboxb
			1,                                     // 608 - tugstair
			36                                     // 609 - boxburg
			                                       // 610 - farmtr1
			                                       // 611 - utiltr1
		},
#endif
	/**
	 * <remarks>
	 * The vehicle colours are in a flat array.  These are the offsets for each
	 * model type.  N+1 so there's a final end-point.
	 * </remarks>
	 */
#if FIX_CreateVehicle || FIX_API
	FIXES_gscVehicleIndexes[212 + 1] =
		{
			   0,                                  // 400 - landstal
			   8,                                  // 401 - bravura
			  16,                                  // 402 - buffalo
			  24,                                  // 403 - linerun
			  32,                                  // 404 - peren
			  40,                                  // 405 - sentinel
			  48,                                  // 406 - dumper
			  49,                                  // 407 - firetruk
			  50,                                  // 408 - trash
			  51,                                  // 409 - stretch
			  52,                                  // 410 - manana
			  60,                                  // 411 - infernus
			  68,                                  // 412 - voodoo
			  76,                                  // 413 - pony
			  84,                                  // 414 - mule
			  92,                                  // 415 - cheetah
			 100,                                  // 416 - ambulan
			 101,                                  // 417 - leviathn
			 101,                                  // 418 - moonbeam
			 109,                                  // 419 - esperant
			 117,                                  // 420 - taxi
			 118,                                  // 421 - washing
			 126,                                  // 422 - bobcat
			 133,                                  // 423 - mrwhoop
			 139,                                  // 424 - bfinject
			 147,                                  // 425 - hunter
			 148,                                  // 426 - premier
			 156,                                  // 427 - enforcer
			 157,                                  // 428 - securica
			 158,                                  // 429 - banshee
			 166,                                  // 430 - predator
			 167,                                  // 431 - bus
			 175,                                  // 432 - rhino
			 176,                                  // 433 - barracks
			 177,                                  // 434 - hotknife
			 184,                                  // 435 - artict1
			 185,                                  // 436 - previon
			 192,                                  // 437 - coach
			 200,                                  // 438 - cabbie
			 201,                                  // 439 - stallion
			 209,                                  // 440 - rumpo
			 217,                                  // 441 - rcbandit
			 225,                                  // 442 - romero
			 233,                                  // 443 - packer
			 241,                                  // 444 - monster
			 247,                                  // 445 - admiral
			 255,                                  // 446 - squalo
			 263,                                  // 447 - seaspar
			 264,                                  // 448 - pizzaboy
			 265,                                  // 449 - tram
			 266,                                  // 450 - artict2
			 267,                                  // 451 - turismo
			 275,                                  // 452 - speeder
			 283,                                  // 453 - reefer
			 284,                                  // 454 - tropic
			 285,                                  // 455 - flatbed
			 293,                                  // 456 - yankee
			 301,                                  // 457 - caddy
			 309,                                  // 458 - solair
			 317,                                  // 459 - topfun
			 325,                                  // 460 - skimmer
			 333,                                  // 461 - pcj600
			 341,                                  // 462 - faggio
			 349,                                  // 463 - freeway
			 357,                                  // 464 - rcbaron
			 358,                                  // 465 - rcraider
			 359,                                  // 466 - glendale
			 367,                                  // 467 - oceanic
			 375,                                  // 468 - sanchez
			 379,                                  // 469 - sparrow
			 380,                                  // 470 - patriot
			 381,                                  // 471 - quad
			 389,                                  // 472 - coastg
			 391,                                  // 473 - dinghy
			 393,                                  // 474 - hermes
			 401,                                  // 475 - sabre
			 409,                                  // 476 - rustler
			 417,                                  // 477 - zr350
			 425,                                  // 478 - walton
			 433,                                  // 479 - regina
			 441,                                  // 480 - comet
			 448,                                  // 481 - bmx
			 456,                                  // 482 - burrito
			 464,                                  // 483 - camper
			 472,                                  // 484 - marquis
			 476,                                  // 485 - baggage
			 483,                                  // 486 - dozer
			 484,                                  // 487 - maverick
			 492,                                  // 488 - vcnmav
			 494,                                  // 489 - rancher
			 500,                                  // 490 - fbiranch
			 501,                                  // 491 - virgo
			 507,                                  // 492 - greenwoo
			 515,                                  // 493 - jetmax
			 516,                                  // 494 - hotring
			 524,                                  // 495 - sandking
			 532,                                  // 496 - blistac
			 540,                                  // 497 - polmav
			 541,                                  // 498 - boxville
			 549,                                  // 499 - benson
			 557,                                  // 500 - mesa
			 565,                                  // 501 - rcgoblin
			 566,                                  // 502 - hotrina
			 574,                                  // 503 - hotrinb
			 582,                                  // 504 - bloodra
			 590,                                  // 505 - rnchlure
			 596,                                  // 506 - supergt
			 601,                                  // 507 - elegant
			 609,                                  // 508 - journey
			 610,                                  // 509 - bike
			 618,                                  // 510 - mtbike
			 626,                                  // 511 - beagle
			 634,                                  // 512 - cropdust
			 642,                                  // 513 - stunt
			 650,                                  // 514 - petro
			 658,                                  // 515 - rdtrain
			 666,                                  // 516 - nebula
			 674,                                  // 517 - majestic
			 682,                                  // 518 - buccanee
			 690,                                  // 519 - shamal
			 691,                                  // 520 - hydra
			 691,                                  // 521 - fcr900
			 699,                                  // 522 - nrg500
			 707,                                  // 523 - copbike
			 707,                                  // 524 - cement
			 715,                                  // 525 - towtruck
			 722,                                  // 526 - fortune
			 730,                                  // 527 - cadrona
			 738,                                  // 528 - fbitruck
			 738,                                  // 529 - willard
			 746,                                  // 530 - forklift
			 754,                                  // 531 - tractor
			 760,                                  // 532 - combine
			 760,                                  // 533 - feltzer
			 768,                                  // 534 - remingtn
			 776,                                  // 535 - slamvan
			 784,                                  // 536 - blade
			 792,                                  // 537 - freight
			 793,                                  // 538 - streak
			 794,                                  // 539 - vortex
			 801,                                  // 540 - vincent
			 809,                                  // 541 - bullet
			 817,                                  // 542 - clover
			 825,                                  // 543 - sadler
			 833,                                  // 544 - firela
			 834,                                  // 545 - hustler
			 842,                                  // 546 - intruder
			 850,                                  // 547 - primo
			 858,                                  // 548 - cargobob
			 859,                                  // 549 - tampa
			 867,                                  // 550 - sunrise
			 875,                                  // 551 - merit
			 883,                                  // 552 - utility
			 886,                                  // 553 - nevada
			 894,                                  // 554 - yosemite
			 902,                                  // 555 - windsor
			 910,                                  // 556 - monstera
			 911,                                  // 557 - monsterb
			 912,                                  // 558 - uranus
			 920,                                  // 559 - jester
			 928,                                  // 560 - sultan
			 936,                                  // 561 - stratum
			 944,                                  // 562 - elegy
			 952,                                  // 563 - raindanc
			 953,                                  // 564 - rctiger
			 953,                                  // 565 - flash
			 961,                                  // 566 - tahoma
			 969,                                  // 567 - savanna
			 977,                                  // 568 - bandito
			 985,                                  // 569 - freiflat
			 985,                                  // 570 - streakc
			 986,                                  // 571 - kart
			 992,                                  // 572 - mower
			1000,                                  // 573 - duneride
			1008,                                  // 574 - sweeper
			1009,                                  // 575 - broadway
			1017,                                  // 576 - tornado
			1025,                                  // 577 - at400
			1031,                                  // 578 - dft30
			1032,                                  // 579 - huntley
			1040,                                  // 580 - stafford
			1049,                                  // 581 - bf400
			1057,                                  // 582 - newsvan
			1065,                                  // 583 - tug
			1066,                                  // 584 - petrotr
			1067,                                  // 585 - emperor
			1075,                                  // 586 - wayfarer
			1083,                                  // 587 - euros
			1091,                                  // 588 - hotdog
			1092,                                  // 589 - club
			1100,                                  // 590 - freibox
			1100,                                  // 591 - artict3
			1101,                                  // 592 - androm
			1102,                                  // 593 - dodo
			1110,                                  // 594 - rccam
			1110,                                  // 595 - launch
			1111,                                  // 596 - copcarla
			1112,                                  // 597 - copcarsf
			1113,                                  // 598 - copcarvg
			1114,                                  // 599 - copcarru
			1115,                                  // 600 - picador
			1123,                                  // 601 - swatvan
			1124,                                  // 602 - alpha
			1132,                                  // 603 - phoenix
			1140,                                  // 604 - glenshit
			1148,                                  // 605 - sadlshit
			1156,                                  // 606 - bagboxa
			1156,                                  // 607 - bagboxb
			1156,                                  // 608 - tugstair
			1157,                                  // 609 - boxburg
			1158,                                  // 610 - farmtr1
			1158,                                  // 611 - utiltr1
			1158
		},
#endif
	/**
	 * <remarks>
	 * Three vehicles have 4 colours.  It's easier to just hard-code them.
	 * </remarks>
	 */
#if FIX_CreateVehicle || FIX_API
	FIXES_gscColour3Camper[8 char] = {0x01010300, 0x03030878}, // 483
	FIXES_gscColour3Cement[8 char] = {0x177B1F1E, 0x173E4040}, // 524
	FIXES_gscColour3Squalo[8 char] = {0x00010001, 0x01010101}, // 446
	FIXES_gscColour4Camper[8 char] = {0x00000000, 0x00000000}, // 483
	FIXES_gscColour4Cement[8 char] = {0x00000000, 0x00000000}, // 524
	FIXES_gscColour4Squalo[8 char] = {0x01010101, 0x01010101}, // 446
#endif
	/**
	 * <remarks>
	 * Three vehicles have 4 colours.  It's easier to just hard-code them.
	 * </remarks>
	 */
#if FIX_API
	FIXES_gscVehicleColours[256] =
		{
			0x00000000, 0xF5F5F500, 0x2A77A100, 0x84041000, 0x26373900, 0x86446E00, 0xD78E1000, 0x4C75B700,
			0xBDBEC600, 0x5E707200, 0x46597A00, 0x656A7900, 0x5D7E8D00, 0x58595A00, 0xD6DAD600, 0x9CA1A300,
			0x335F3F00, 0x730E1A00, 0x7B0A2A00, 0x9F9D9400, 0x3B4E7800, 0x732E3E00, 0x691E3B00, 0x96918C00,
			0x51545900, 0x3F3E4500, 0xA5A9A700, 0x635C5A00, 0x3D4A6800, 0x97959200, 0x421F2100, 0x5F272B00,
			0x8494AB00, 0x767B7C00, 0x64646400, 0x5A575200, 0x25252700, 0x2D3A3500, 0x93A39600, 0x6D7A8800,
			0x22191800, 0x6F675F00, 0x7C1C2A00, 0x5F0A1500, 0x19382600, 0x5D1B2000, 0x9D987200, 0x7A756000,
			0x98958600, 0xADB0B000, 0x84898800, 0x304F4500, 0x4D626800, 0x16224800, 0x272F4B00, 0x7D625600,
			0x9EA4AB00, 0x9C8D7100, 0x6D182200, 0x4E688100, 0x9C9C9800, 0x91734700, 0x661C2600, 0x949D9F00,
			0xA4A7A500, 0x8E8C4600, 0x341A1E00, 0x6A7A8C00, 0xAAAD8E00, 0xAB988F00, 0x851F2E00, 0x6F829700,
			0x58585300, 0x9AA79000, 0x601A2300, 0x20202C00, 0xA4A09600, 0xAA9D8400, 0x78222B00, 0x0E316D00,
			0x722A3F00, 0x7B715E00, 0x741D2800, 0x1E2E3200, 0x4D322F00, 0x7C1B4400, 0x2E5B2000, 0x395A8300,
			0x6D283700, 0xA7A28F00, 0xAFB1B100, 0x36415500, 0x6D6C6E00, 0x0F6A8900, 0x204B6B00, 0x2B3E5700,
			0x9B9F9D00, 0x6C849500, 0x4D849500, 0xAE9B7F00, 0x406C8F00, 0x1F253B00, 0xAB927600, 0x13457300,
			0x96816C00, 0x64686A00, 0x10508200, 0xA1998300, 0x38569400, 0x52566100, 0x7F695600, 0x8C929A00,
			0x596E8700, 0x47353200, 0x44624F00, 0x730A2700, 0x22345700, 0x640D1B00, 0xA3ADC600, 0x69585300,
			0x9B8B8000, 0x620B1C00, 0x5B5D5E00, 0x62442800, 0x73182700, 0x1B376D00, 0xEC6AAE00, 0x00000000,
			0x17751700, 0x21060600, 0x12547800, 0x452A0D00, 0x571E1E00, 0x01070100, 0x25225A00, 0x2C89AA00,
			0x8A4DBD00, 0x35963A00, 0xB7B7B700, 0x464C8D00, 0x84888C00, 0x81786700, 0x817A2600, 0x6A506F00,
			0x583E6F00, 0x8CB97200, 0x824F7800, 0x6D276A00, 0x1E1D1300, 0x1E130600, 0x1F251800, 0x2C453100,
			0x1E4C9900, 0x2E5F4300, 0x1E994800, 0x1E999900, 0x99997600, 0x7C849900, 0x992E1E00, 0x2C1E0800,
			0x14240700, 0x993E4D00, 0x1E4C9900, 0x19818100, 0x1A292A00, 0x16616F00, 0x1B668700, 0x6C3F9900,
			0x481A0E00, 0x7A739900, 0x746D9900, 0x53387E00, 0x22240700, 0x3E190C00, 0x46210E00, 0x991E1E00,
			0x8D4C8D00, 0x805B8000, 0x7B3E7E00, 0x3C173700, 0x73351700, 0x78181800, 0x83341A00, 0x8E2F1C00,
			0x7E3E5300, 0x7C6D7C00, 0x020C0200, 0x07240700, 0x16301200, 0x16301B00, 0x642B4F00, 0x36845200,
			0x99959000, 0x818D9600, 0x99991E00, 0x7F994C00, 0x83929200, 0x78822200, 0x2B3C9900, 0x3A3A0B00,
			0x8A794E00, 0x0E1F4900, 0x15371C00, 0x15273A00, 0x37577500, 0x06082000, 0x07132600, 0x20394B00,
			0x2C508900, 0x15426C00, 0x10325000, 0x24166300, 0x69201500, 0x8C8D9400, 0x51601300, 0x090F0200,
			0x8C573A00, 0x52888E00, 0x995C5200, 0x99581E00, 0x993A6300, 0x998F4E00, 0x99311E00, 0x0D184200,
			0x521E1E00, 0x42420D00, 0x4C991E00, 0x082A1D00, 0x96821D00, 0x197F1900, 0x3B141F00, 0x74521700,
			0x893F8D00, 0x7E1A6C00, 0x0B370B00, 0x27450D00, 0x071F2400, 0x78457300, 0x8A653A00, 0x73261700,
			0x31949000, 0x56941D00, 0x59163D00, 0x1B8A2F00, 0x38160B00, 0x04180400, 0x355D8E00, 0x2E3F5B00,
			0x561A2800, 0x4E0E2700, 0x706C6700, 0x3B3E4200, 0x2E2D3300, 0x7B7E7D00, 0x4A444200, 0x28344E00
		},
#endif
	/**
	 * <remarks>
	 * Name of the pvar in which to store the player's race checkpoint state.
	 * </remarks>
	 */
#if !FIXES_Single && FIX_SetPlayerRaceCheckpoint
	FIXES_pvarPlayerRaceCheckpoint[] = "FIXES_pvarPlayerRaceCheckpoint",
#endif
	/**
	 * <remarks>
	 * NULL.  This is stored as a global string to reduce memory usage.
	 * </remarks>
	 */
	FIXES_gscNULL[] = "\1",
	/**
	 * <remarks>
	 * (null).  This is stored as a global string to reduce memory usage.
	 * </remarks>
	 */
	FIXES_gscNull[] = "(null)",
	/**
	 * <remarks>
	 * A single re-usable new line.
	 * </remarks>
	 */
	FIXES_gscLF[] = "\n",
	/**
	 * <remarks>
	 * There are only 100 colours used by default, with SA:MP looping through
	 * them repeatedly.
	 * </remarks>
	 */
#if FIX_GetPlayerColour || FIX_API
	FIXES_gscPlayerColours[100] =
		{
			0xFF8C13FF, 0xC715FFFF, 0x20B2AAFF, 0xDC143CFF, 0x6495EDFF,
			0xF0E68CFF, 0x778899FF, 0xFF1493FF, 0xF4A460FF, 0xEE82EEFF,
			0xFFD720FF, 0x8B4513FF, 0x4949A0FF, 0x148B8BFF, 0x14FF7FFF,
			0x556B2FFF, 0x0FD9FAFF, 0x10DC29FF, 0x534081FF, 0x0495CDFF,
			0xEF6CE8FF, 0xBD34DAFF, 0x247C1BFF, 0x0C8E5DFF, 0x635B03FF,
			0xCB7ED3FF, 0x65ADEBFF, 0x5C1ACCFF, 0xF2F853FF, 0x11F891FF,
			0x7B39AAFF, 0x53EB10FF, 0x54137DFF, 0x275222FF, 0xF09F5BFF,
			0x3D0A4FFF, 0x22F767FF, 0xD63034FF, 0x9A6980FF, 0xDFB935FF,
			0x3793FAFF, 0x90239DFF, 0xE9AB2FFF, 0xAF2FF3FF, 0x057F94FF,
			0xB98519FF, 0x388EEAFF, 0x028151FF, 0xA55043FF, 0x0DE018FF,
			0x93AB1CFF, 0x95BAF0FF, 0x369976FF, 0x18F71FFF, 0x4B8987FF,
			0x491B9EFF, 0x829DC7FF, 0xBCE635FF, 0xCEA6DFFF, 0x20D4ADFF,
			0x2D74FDFF, 0x3C1C0DFF, 0x12D6D4FF, 0x48C000FF, 0x2A51E2FF,
			0xE3AC12FF, 0xFC42A8FF, 0x2FC827FF, 0x1A30BFFF, 0xB740C2FF,
			0x42ACF5FF, 0x2FD9DEFF, 0xFAFB71FF, 0x05D1CDFF, 0xC471BDFF,
			0x94436EFF, 0xC1F7ECFF, 0xCE79EEFF, 0xBD1EF2FF, 0x93B7E4FF,
			0x3214AAFF, 0x184D3BFF, 0xAE4B99FF, 0x7E49D7FF, 0x4C436EFF,
			0xFA24CCFF, 0xCE76BEFF, 0xA04E0AFF, 0x9F945CFF, 0xDCDE3DFF,
			0x10C9C5FF, 0x70524DFF, 0x0BE472FF, 0x8A2CD7FF, 0x6152C2FF,
			0xCF72A9FF, 0xE59338FF, 0xEEDC2DFF, 0xD8C762FF, 0xD8C762FF
		},
#endif
	/**
	 * <remarks>
	 * This is a compressed (4-bit) list of the maximum number of passengers in
	 * any vehicle, confirmed by a number of sources. "F" (15) means invalid
	 * vehicle.
	 * </remarks>
	 */
#if FIX_OnPlayerEnterVehicle || FIX_API
	FIXES_gscMaxPassengers[] =
		{
			0x10331113, 0x11311131, 0x11331313, 0x80133301, 0x1381F110, 0x10311103, 0x10001F10, 0x11113311, 0x13113311,
			0x31101100, 0x30002301, 0x11031311, 0x11111331, 0x10013111, 0x01131100, 0x11111110, 0x11100031, 0x11130111,
			0x33113311, 0x11111101, 0x33101133, 0x10100510, 0x03133111, 0xFF11113F, 0x13330111, 0xFF131111, 0x0000FF3F
		},
#endif
	/**
	 * <remarks>
	 * This is a bit array of all the valid mods (-1000) for all vehicles (-400)
	 * EXCEPT for vehicle 576 (Tornado), which has just TWO extra mods on it,
	 * that should spill over in to an extra cell of data (requiring an extra
	 * 848 bytes of data total to make the array work).  Instead this (hopefully
	 * rare) case is handled explicitly in "OnVehicleMod".  It seems that most
	 * vehicles are:
	 *
	 *   0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	 *
	 * I don't know yet if this can be used to our advantage to improve the code
	 * somehow - it seems like that would require more explicit model handling.
	 * </remarks>
	 */
#if FIX_OnVehicleMod || FIX_API
	FIXES_gscVehicleMods[] =
		{
			0x033C2700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x021A27FA, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x023B2785, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02BC4703, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x03BA278A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x028E078A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02310744, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x0228073A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02BD4701, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x023A2780, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x0228077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x027A27CA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x0282278A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x023E07C0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x03703730, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x031D2775, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02BE4788, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02010771, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x029A0FCE, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x03382700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x023F8795, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x029F078C, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x029627EA, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x0236C782, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x029E1FCA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0xFC000437, 0x00000000, 0x021C0000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x03FE6007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00001B87, 0x00000001, 0x01E00000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x039E07D2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x023CC700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00030000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x038E07D6, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x023D0709, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x029E1F8A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x029C077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02BD076C, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0xFFFFFE00, 0x00000007, 0x00000000, 0x000001F8,
			0x02000700, 0x00000000, 0x00FFFFFE, 0x00000007, 0xC0000000, 0x00002007,
			0xFE000700, 0x00000003, 0x00FFFE00, 0x00000007, 0x00003C00, 0x00000600,
			0xCE000700, 0xFF800000, 0x00FFFE01, 0x00000007, 0x3C000000, 0x00000000,
			0x02000700, 0x000003FC, 0x00FFFE00, 0x00000007, 0x003C0000, 0x00001800,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x007FE000, 0x00FFFE00, 0x00000007, 0x03C00000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000047, 0x0000003E, 0x3C000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00001C00, 0x00FFFE00, 0x0000000F, 0x00000000, 0x0003C000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x000003C0, 0xC0000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x029607C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x03FFE7CF, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x031727F1, 0x00000000, 0x00FFFE00, 0x00000007, 0x00030000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x025627F0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x039E07C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
			0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000
		},
#endif
	/**
	 * <remarks>
	 * Which index each letter starts at.  Sometimes crashes the compiler...
	 * </remarks>
	 */
#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2 || FIX_API
	FIXES_gscAnimIndexes[24] =
		{
			0, 2, 21, 35, 42, 42, 53, 62, 64, 67, 68, 71, 75, 81, 82, 84, 94, 96, 104, 122, 127, 128, 131, 135
		},
#endif
	/**
	 * <remarks>
	 * List of valid animation libraries.
	 * </remarks>
	 */
#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2 || FIX_API
	FIXES_gscAnimLib[135][] =
		{
			"AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
			"BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
			"BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
			"BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
			"BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
			"CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
			"COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
			"DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
			"DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
			"FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
			"FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
			"GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
			"GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
			"INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
			"KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
			"MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
			"MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
			"PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
			"POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
			"QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
			"ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SAMP",
			"SCRATCHING",   "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",
			"SILENCED",     "SKATE",        "SMOKING",      "SNIPER",       "SNM",
			"SPRAYCAN",     "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",
			"SWIM",         "SWORD",        "TANK",         "TATTOOS",      "TEC",
			"TRAIN",        "TRUCK",        "UZI",          "VAN",          "VENDING",
			"VORTEX",       "WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
		},
#endif
	/**
	 * <remarks>
	 * ".".
	 * </remarks>
	 */
	FIXES_gscDot[] = ".",
	/**
	 * <remarks>
	 * Specifier <c></c>.
	 * </remarks>
	 */
	FIXES_gscSpec@[] = "",
	/**
	 * <remarks>
	 * Specifier <c>i</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@i[] = "i",
	/**
	 * <remarks>
	 * Specifier <c>ii</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@ii[] = "ii",
	/**
	 * <remarks>
	 * Specifier <c>ai</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@ai[] = "ai",
	/**
	 * <remarks>
	 * Specifier <c>is</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@is[] = "is",
	/**
	 * <remarks>
	 * Specifier <c>iii</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iii[] = "iii",
	/**
	 * <remarks>
	 * Specifier <c>isii</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@isii[] = "isii",
	/**
	 * <remarks>
	 * Specifier <c>ifff</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@ifff[] = "ifff",
	/**
	 * <remarks>
	 * Specifier <c>iifff</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iifff[] = "iifff",
	/**
	 * <remarks>
	 * Specifier <c>iifffi</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iifffi[] = "iifffi",
	/**
	 * <remarks>
	 * Specifier <c>iifffffff</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iifffffff[] = "iifffffff",
	/**
	 * <remarks>
	 * Specifier <c>iffff</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iffff[] = "iffff",
	/**
	 * <remarks>
	 * Specifier <c>iiiis</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iiiis[] = "iiiis",
	/**
	 * <remarks>
	 * Specifier <c>iiiii</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iiiii[] = "iiiii",
	/**
	 * <remarks>
	 * Specifier <c>iiiiii</c>.
	 * </remarks>
	 */
	FIXES_gscSpec@iiiiii[] = "iiiiii",
	/**
	 * <remarks>
	 * The temporary name to give when renaming people.
	 * </remarks>
	 */
	FIXES_gscTempName[] = "FIXES_TEMP_NAME",
	/**
	 * <remarks>
	 * The property to check for script ordering.
	 * </remarks>
	 */
	FIXES_gscOrderProperty[] = "FIXES_gscOrderProperty",
	/**
	 * <remarks>
	 * Call <symbolref name="_FIXES_DetermineOrder" /> in the GM or not?
	 * </remarks>
	 */
	FIXES_gscNoGMProperty[] = "FIXES_gscNoGMProperty",
	/**
	 * <remarks>
	 * Name of the ordering callback.
	 * </remarks>
	 */
	FIXES_gscDetermineOrder[] = "_FIXES_DetermineOrder",
	/**
	 * <remarks>
	 * Name of the remote set player menu function.
	 * </remarks>
	 */
	FIXES_gscSetPlayerMenu[] = "_FIXES_SetPlayerMenu",
	/**
	 * <remarks>
	 * Name of the remote function to clear a player's menu set.
	 * </remarks>
	 */
	FIXES_gscClearPlayerMenu[] = "_FIXES_ClearPlayerMenu",
	/**
	 * <remarks>
	 * Name of the remote allow teleport function.
	 * </remarks>
	 */
	FIXES_gscAllowTeleport[] = "_FIXES_AllowTeleport",
	/**
	 * <remarks>
	 * Name of the remote vehicle entry function.
	 * </remarks>
	 */
	FIXES_gscPutPlayerInVehicle[] = "_FIXES_PutPlayerInVehicle",
	/**
	 * <remarks>
	 * Name of the remote interior weapons function.
	 * </remarks>
	 */
	FIXES_gscAllowInteriorWeapons[] = "_FIXES_AllowInteriorWeapons",
	/**
	 * <remarks>
	 * Name of the remote player toggle function.
	 * </remarks>
	 */
	FIXES_gscTogglePlayerControl[] = "_FIXES_TogglePlayerControllable",
	/**
	 * <remarks>
	 * Name of the remote player clock function.
	 * </remarks>
	 */
	FIXES_gscTogglePlayerClock[] = "_FIXES_TogglePlayerClock",
	/**
	 * <remarks>
	 * Name of the remote player clock function.
	 * </remarks>
	 */
	FIXES_gscGetWeather[] = "_FIXES_GetWeather",
	/**
	 * <remarks>
	 * Name of the remote world bounds function.
	 * </remarks>
	 */
	FIXES_gscSetPlayerWorldBounds[] = "_FIXES_SetPlayerWorldBounds",
	/**
	 * <remarks>
	 * Name of the remote GameText show function.
	 * </remarks>
	 */
	FIXES_gscGameTextShow[] = "_FIXES_GameTextShow",
	/**
	 * <remarks>
	 * Name of the remote block update function.
	 * </remarks>
	 */
	FIXES_gscBlockUpdate[] = "@FIXES_BlockUpdate",
	/**
	 * <remarks>
	 * The property for accurate returns.
	 * </remarks>
	 */
	FIXES_gscReturnProperty[] = "FIXES_gscReturnProperty",
	/**
	 * <remarks>
	 * The property for checking this is the only running script with fixes in.
	 * </remarks>
	 */
	FIXES_gscSingleProperty[] = "FIXES_gscSingleProperty",
	/**
	 * <remarks>
	 * The property for a player's current menu.
	 * </remarks>
	 */
	FIXES_gscMenuProperty[] = "FIXES_gscMenuProperty",
	/**
	 * <remarks>
	 * The property for a player's current menu.
	 * </remarks>
	 */
	FIXES_gscRconFixFS[] = "callbackfix.amx",
	/**
	 * <remarks>
	 * The property AND command to check for RCON fix presence.
	 * </remarks>
	 */
	FIXES_gscOnClientCheckResponse[] = !"FIXES_OnClientCheckResponse",
	/**
	 * <remarks>
	 * Error shown when multiple scripts are detected with <c>FIXES_SINGLE</c>.
	 * </remarks>
	 */
	FIXES_gscMultiScriptError[] = "\7\7\7\7\7"                                             \
		"*** fixes.inc error: Running multiple scripts compiled with \"fixes.inc\"...\n"   \
		"***                  Please compile your modes with \"#define FIXES_Single 0\"\n" \
		"***                  at the top, as this setting is no longer the default (to\n"  \
		"***                  improve the more common case).\n"                            \
		"***";

/*

    888b      88                       88                                      
    8888b     88                ,d     ""                                      
    88 `8b    88                88                                             
    88  `8b   88  ,adPPYYba,  MM88MMM  88  8b       d8   ,adPPYba,  ,adPPYba,  
    88   `8b  88  ""     `Y8    88     88  `8b     d8'  a8P_____88  I8[    ""  
    88    `8b 88  ,adPPPPP88    88     88   `8b   d8'   8PP"""""""   `"Y8ba,   
    88     `8888  88,    ,88    88,    88    `8b,d8'    "8b,   ,aa  aa    ]8I  
    88      `888  `"8bbdP"Y8    "Y888  88      "8"       `"Ybbd8"'  `"YbbdP"'  



*/

/**
 * <remarks>
 * <c>IsValidVehicle</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

native BAD_IsValidVehicle(vehicleid) = IsValidVehicle;
#if FIX_IsValidVehicle
	native IsValidVehicle(vehicleid);
#endif

/**
 * <remarks>
 * <c>GetGravity</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

native Float:BAD_GetGravity() = GetGravity;
#if FIX_GetGravity
	native Float:GetGravity();
#endif

/**
 * <remarks>
 * <c>gpci</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

native BAD_gpci(playerid, serial[], maxlen) = gpci;
#if FIX_gpci
	native gpci(playerid, serial[], maxlen);
#endif

/**
 * <remarks>
 * <c>const</c>
 *
 * Better const-correctness on native functions.
 * </remarks>
 */

#if FIX_const
	// a_actor
	#if _FIXES_SAMP && defined _ALS_ApplyActorAnimation
		#error _ALS_ApplyActorAnimation defined
	#endif
	native CST_ApplyActorAnimation(actorid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time) = ApplyActorAnimation;
	native BAD_ApplyActorAnimation(actorid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time) = ApplyActorAnimation;
	#define _ALS_ApplyActorAnimation
	#define ApplyActorAnimation( CST_ApplyActorAnimation(

	// a_http
	// Try very hard to include it!  The first one should be enough.  Shame that
	// include has no include guard in it, making it harder to use with Zeex's
	// compiler.
	#if !defined HTTP_ERROR_MALFORMED_RESPONSE
		#tryinclude <a_http>
	#endif
	#if !defined HTTP_ERROR_MALFORMED_RESPONSE
		#tryinclude "a_http"
	#endif
	#if !defined HTTP_ERROR_MALFORMED_RESPONSE
		#tryinclude "..\a_http"
	#endif
	#if defined HTTP_ERROR_MALFORMED_RESPONSE
		#if _FIXES_SAMP && defined _ALS_HTTP
			#error _ALS_HTTP defined
		#endif
		native CST_HTTP(index, type, const url[], const data[], const callback[]) = HTTP;
		#define _ALS_HTTP
		#define HTTP( CST_HTTP(
		// Because a_http can be included multiple times (on one compiler),
		// ensure that multiple definitions don't break (too quickly - there's
		// nothing we can do if it gets included a load of times, but that's an
		// issue you would get with the new compiler anyway).
		#define CST_HTTP(%0,%1,%2[],%3[],%4[]); a_http_included_too_many_times(%0,%1,%2[],%3[],%4[]) = HTTP;
	#endif

	// a_npc
	//
	//   native CONST_SetTimer(const funcname[], interval, repeating) = SetTimer;
	//   native CONST_SendChat(const msg[]) = SendChat;
	//   native CONST_SendCommand(const commandtext[]) = SendCommand;
	//   native CONST_StartRecordingPlayback(playbacktype, const recordname[]) = StartRecordingPlayback;
	//

	// a_objects
	#if _FIXES_SAMP && defined _ALS_SetObjectMaterial
		#error _ALS_SetObjectMaterial defined
	#endif
	native CST_SetObjectMaterial(objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor=0) = SetObjectMaterial;
	#define _ALS_SetObjectMaterial
	#define SetObjectMaterial( CST_SetObjectMaterial(
	#if _FIXES_SAMP && defined _ALS_SetPlayerObjectMaterial
		#error _ALS_SetPlayerObjectMaterial defined
	#endif
	native CST_SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor=0) = SetPlayerObjectMaterial;
	#define _ALS_SetPlayerObjectMaterial
	#define SetPlayerObjectMaterial( CST_SetPlayerObjectMaterial(
	#if _FIXES_SAMP && defined _ALS_SetObjectMaterialText
		#error _ALS_SetObjectMaterialText defined
	#endif
	native CST_SetObjectMaterialText(objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetObjectMaterialText;
	#define _ALS_SetObjectMaterialText
	#define SetObjectMaterialText( CST_SetObjectMaterialText(
	#if _FIXES_SAMP && defined _ALS_SetPlayerObjMaterialText
		#error _ALS_SetPlayerObjMaterialText defined
	#endif
	native CST_SetPlayerObjectMaterialText(playerid, objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetPlayerObjectMaterialText;
	#define _ALS_SetPlayerObjMaterialText
	#define SetPlayerObjectMaterialText( CST_SetPlayerObjectMaterialText(

	// a_players
	#if _FIXES_SAMP && defined _ALS_PlayAudioStreamForPlayer
		#error _ALS_PlayAudioStreamForPlayer defined
	#endif
	native CST_PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0) = PlayAudioStreamForPlayer;
	#define _ALS_PlayAudioStreamForPlayer
	#define PlayAudioStreamForPlayer( CST_PlayAudioStreamForPlayer(
	#if _FIXES_SAMP && defined _ALS_SetPlayerShopName
		#error _ALS_SetPlayerShopName defined
	#endif
	native CST_SetPlayerShopName(playerid, const shopname[]) = SetPlayerShopName;
	#define _ALS_SetPlayerShopName
	#define SetPlayerShopName( CST_SetPlayerShopName(
	#if _FIXES_SAMP && defined _ALS_CreatePlayerTextDraw
		#error _ALS_CreatePlayerTextDraw defined
	#endif
	native PlayerText:CST_CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
	native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
	#define _ALS_CreatePlayerTextDraw
	#define CreatePlayerTextDraw( CST_CreatePlayerTextDraw(
	#if _FIXES_SAMP && defined _ALS_PlayerTextDrawSetString
		#error _ALS_PlayerTextDrawSetString defined
	#endif
	native CST_PlayerTextDrawSetString(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
	native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
	#define _ALS_PlayerTextDrawSetString
	#define PlayerTextDrawSetString( CST_PlayerTextDrawSetString(
	#if _FIXES_SAMP && defined _ALS_SetPVarInt
		#error _ALS_SetPVarInt defined
	#endif
	native CST_SetPVarInt(playerid, const varname[], int_value) = SetPVarInt;
	#define _ALS_SetPVarInt
	#define SetPVarInt( CST_SetPVarInt(
	#if _FIXES_SAMP && defined _ALS_GetPVarInt
		#error _ALS_GetPVarInt defined
	#endif
	native CST_GetPVarInt(playerid, const varname[]) = GetPVarInt;
	#define _ALS_GetPVarInt
	#define GetPVarInt( CST_GetPVarInt(
	#if _FIXES_SAMP && defined _ALS_SetPVarString
		#error _ALS_SetPVarString defined
	#endif
	native CST_SetPVarString(playerid, const varname[], const string_value[]) = SetPVarString;
	#define _ALS_SetPVarString
	#define SetPVarString( CST_SetPVarString(
	#if _FIXES_SAMP && defined _ALS_GetPVarString
		#error _ALS_GetPVarString defined
	#endif
	native CST_GetPVarString(playerid, const varname[], string_return[], len) = GetPVarString;
	native BAD_GetPVarString(playerid, varname[], string_return[], len) = GetPVarString;
	#define _ALS_GetPVarString
	#define GetPVarString( CST_GetPVarString(
	#if _FIXES_SAMP && defined _ALS_SetPVarFloat
		#error _ALS_SetPVarFloat defined
	#endif
	native CST_SetPVarFloat(playerid, const varname[], Float:float_value) = SetPVarFloat;
	#define _ALS_SetPVarFloat
	#define SetPVarFloat( CST_SetPVarFloat(
	#if _FIXES_SAMP && defined _ALS_GetPVarFloat
		#error _ALS_GetPVarFloat defined
	#endif
	native Float:CST_GetPVarFloat(playerid, const varname[]) = GetPVarFloat;
	#define _ALS_GetPVarFloat
	#define GetPVarFloat( CST_GetPVarFloat(
	#if _FIXES_SAMP && defined _ALS_DeletePVar
		#error _ALS_DeletePVar defined
	#endif
	native CST_DeletePVar(playerid, const varname[]) = DeletePVar;
	#define _ALS_DeletePVar
	#define DeletePVar( CST_DeletePVar(
	#if _FIXES_SAMP && defined _ALS_GetPVarType
		#error _ALS_GetPVarType defined
	#endif
	native PLAYER_VARTYPE:CST_GetPVarType(playerid, const varname[]) = GetPVarType;
	#define _ALS_GetPVarType
	#define GetPVarType( CST_GetPVarType(
	#if _FIXES_SAMP && defined _ALS_SetPlayerChatBubble
		#error _ALS_SetPlayerChatBubble defined
	#endif
	native CST_SetPlayerChatBubble(playerid, const text[], color, Float:drawdistance, expiretime) = SetPlayerChatBubble;
	#define _ALS_SetPlayerChatBubble
	#define SetPlayerChatBubble( CST_SetPlayerChatBubble(
	#if _FIXES_SAMP && defined _ALS_ApplyAnimation
		#error _ALS_ApplyAnimation defined
	#endif
	native CST_ApplyAnimation(playerid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
	native BAD_ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
	#define _ALS_ApplyAnimation
	#define ApplyAnimation( CST_ApplyAnimation(
	#if _FIXES_SAMP && defined _ALS_StartRecordingPlayerData
		#error _ALS_StartRecordingPlayerData defined
	#endif
	native CST_StartRecordingPlayerData(playerid, recordtype, const recordname[]) = StartRecordingPlayerData;
	#define _ALS_StartRecordingPlayerData
	#define StartRecordingPlayerData( CST_StartRecordingPlayerData(

	// a_samp
	#if _FIXES_SAMP && defined _ALS_SetTimer
		#error _ALS_SetTimer defined
	#endif
	native CST_SetTimer(const funcname[], interval, repeating) = SetTimer;
	native BAD_SetTimer(const funcname[], interval, repeating) = SetTimer;
	#define _ALS_SetTimer
	#define SetTimer( CST_SetTimer(
	#if _FIXES_SAMP && defined _ALS_SetTimerEx
		#error _ALS_SetTimerEx defined
	#endif
	native CST_SetTimerEx(const funcname[], interval, repeating, const format[], {Float,_}:...) = SetTimerEx;
	native BAD_SetTimerEx(const funcname[], interval, repeating, const format[], {Float,_}:...) = SetTimerEx;
	#define _ALS_SetTimerEx
	#define SetTimerEx( CST_SetTimerEx(
	#if _FIXES_SAMP && defined _ALS_SHA256_PassHash
		#error _ALS_SHA256_PassHash defined
	#endif
	native CST_SHA256_PassHash(const password[], const salt[], ret_hash[], ret_hash_len) = SHA256_PassHash;
	#define _ALS_SHA256_PassHash // SHA256 for password hashing
	#define SHA256_PassHash( CST_SHA256_PassHash(
	#if _FIXES_SAMP && defined _ALS_SetSVarInt
		#error _ALS_SetSVarInt defined
	#endif
	native CST_SetSVarInt(const varname[], int_value) = SetSVarInt;
	#define _ALS_SetSVarInt
	#define SetSVarInt( CST_SetSVarInt(
	#if _FIXES_SAMP && defined _ALS_GetSVarInt
		#error _ALS_GetSVarInt defined
	#endif
	native CST_GetSVarInt(const varname[]) = GetSVarInt;
	#define _ALS_GetSVarInt
	#define GetSVarInt( CST_GetSVarInt(
	#if _FIXES_SAMP && defined _ALS_SetSVarString
		#error _ALS_SetSVarString defined
	#endif
	native CST_SetSVarString(const varname[], const string_value[]) = SetSVarString;
	#define _ALS_SetSVarString
	#define SetSVarString( CST_SetSVarString(
	#if _FIXES_SAMP && defined _ALS_GetSVarString
		#error _ALS_GetSVarString defined
	#endif
	native CST_GetSVarString(const varname[], string_return[], len) = GetSVarString;
	native BAD_GetSVarString(varname[], string_return[], len) = GetSVarString;
	#define _ALS_GetSVarString
	#define GetSVarString( CST_GetSVarString(
	#if _FIXES_SAMP && defined _ALS_SetSVarFloat
		#error _ALS_SetSVarFloat defined
	#endif
	native CST_SetSVarFloat(const varname[], Float:float_value) = SetSVarFloat;
	#define _ALS_SetSVarFloat
	#define SetSVarFloat( CST_SetSVarFloat(
	#if _FIXES_SAMP && defined _ALS_GetSVarFloat
		#error _ALS_GetSVarFloat defined
	#endif
	native Float:CST_GetSVarFloat(const varname[]) = GetSVarFloat;
	#define _ALS_GetSVarFloat
	#define GetSVarFloat( CST_GetSVarFloat(
	#if _FIXES_SAMP && defined _ALS_DeleteSVar
		#error _ALS_DeleteSVar defined
	#endif
	native CST_DeleteSVar(const varname[]) = DeleteSVar;
	#define _ALS_DeleteSVar
	#define DeleteSVar( CST_DeleteSVar(
	#if _FIXES_SAMP && defined _ALS_GetSVarType
		#error _ALS_GetSVarType defined
	#endif
	native CST_GetSVarType(const varname[]) = GetSVarType;
	#define _ALS_GetSVarType
	#define GetSVarType( CST_GetSVarType(
	#if _FIXES_SAMP && defined _ALS_ConnectNPC
		#error _ALS_ConnectNPC defined
	#endif
	native CST_ConnectNPC(const name[], const script[]) = ConnectNPC;
	#define _ALS_ConnectNPC
	#define ConnectNPC( CST_ConnectNPC(
	#if _FIXES_SAMP && defined _ALS_SendRconCommand
		#error _ALS_SendRconCommand defined
	#endif
	native CST_SendRconCommand(const command[]) = SendRconCommand;
	#define _ALS_SendRconCommand
	#define SendRconCommand( CST_SendRconCommand(
	// This is the only case where a variable is "const" but shouldn't be.
	#if _FIXES_SAMP && defined _ALS_GetPlayerVersion
		#error _ALS_GetPlayerVersion defined
	#endif
	native CST_GetPlayerVersion(playerid, version[], len) = GetPlayerVersion;
	#define _ALS_GetPlayerVersion
	#define GetPlayerVersion( CST_GetPlayerVersion(
	#if _FIXES_SAMP && defined _ALS_BlockIpAddress
		#error _ALS_BlockIpAddress defined
	#endif
	native CST_BlockIpAddress(const ip_address[], timems) = BlockIpAddress;
	#define _ALS_BlockIpAddress
	#define BlockIpAddress( CST_BlockIpAddress(
	#if _FIXES_SAMP && defined _ALS_UnBlockIpAddress
		#error _ALS_UnBlockIpAddress defined
	#endif
	native CST_UnBlockIpAddress(const ip_address[]) = UnBlockIpAddress;
	#define _ALS_UnBlockIpAddress
	#define UnBlockIpAddress( CST_UnBlockIpAddress(
	#if _FIXES_SAMP && defined _ALS_TextDrawCreate
		#error _ALS_TextDrawCreate defined
	#endif
	native Text:CST_TextDrawCreate(Float:x, Float:y, const text[]) = TextDrawCreate;
	native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
	#define _ALS_TextDrawCreate
	#define TextDrawCreate( CST_TextDrawCreate(
	#if _FIXES_SAMP && defined _ALS_TextDrawSetString
		#error _ALS_TextDrawSetString defined
	#endif
	native CST_TextDrawSetString(Text:text, const string[]) = TextDrawSetString;
	native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
	#define _ALS_TextDrawSetString
	#define TextDrawSetString( CST_TextDrawSetString(
	#if _FIXES_SAMP && defined _ALS_Create3DTextLabel
		#error _ALS_Create3DTextLabel defined
	#endif
	native Text3D:CST_Create3DTextLabel(const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0) = Create3DTextLabel;
	#define _ALS_Create3DTextLabel
	#define Create3DTextLabel( CST_Create3DTextLabel(
	#if _FIXES_SAMP && defined _ALS_Update3DTextLabelText
		#error _ALS_Update3DTextLabelText defined
	#endif
	native CST_Update3DTextLabelText(Text3D:id, color, const text[]) = Update3DTextLabelText;
	#define _ALS_Update3DTextLabelText
	#define Update3DTextLabelText( CST_Update3DTextLabelText(
	#if _FIXES_SAMP && defined _ALS_CreatePlayer3DTextLabel
		#error _ALS_CreatePlayer3DTextLabel defined
	#endif
	native PlayerText3D:CST_CreatePlayer3DTextLabel(playerid, const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer=INVALID_PLAYER_ID, attachedvehicle=INVALID_VEHICLE_ID, testLOS=0) = CreatePlayer3DTextLabel;
	#define _ALS_CreatePlayer3DTextLabel
	#define CreatePlayer3DTextLabel( CST_CreatePlayer3DTextLabel(
	#if _FIXES_SAMP && defined _ALS_UpdPlayer3DTextLabelText
		#error _ALS_UpdPlayer3DTextLabelText defined
	#endif
	native CST_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:id, color, const text[]) = UpdatePlayer3DTextLabelText;
	#define _ALS_UpdPlayer3DTextLabelText
	#define UpdatePlayer3DTextLabelText( CST_UpdatePlayer3DTextLabelText(
	#if _FIXES_SAMP && defined _ALS_ShowPlayerDialog
		#error _ALS_ShowPlayerDialog defined
	#endif
	native CST_ShowPlayerDialog(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
	native BAD_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[]) = ShowPlayerDialog;
	#define _ALS_ShowPlayerDialog
	#define ShowPlayerDialog( CST_ShowPlayerDialog(

	// a_sampdb
	#if _FIXES_SAMP && defined _ALS_db_open
		#error _ALS_db_open defined
	#endif
	native DB:CST_db_open(const name[]) = db_open;
	#define _ALS_db_open
	#define db_open( CST_db_open(
	#if _FIXES_SAMP && defined _ALS_db_query
		#error _ALS_db_query defined
	#endif
	native DBResult:CST_db_query(DB:db, const query[]) = db_query;
	#define _ALS_db_query
	#define db_query( CST_db_query(

	// a_vehicles
	#if _FIXES_SAMP && defined _ALS_SetVehicleNumberPlate
		#error _ALS_SetVehicleNumberPlate defined
	#endif
	native CST_SetVehicleNumberPlate(vehicleid, const numberplate[]) = SetVehicleNumberPlate;
	#define _ALS_SetVehicleNumberPlate
	#define SetVehicleNumberPlate( CST_SetVehicleNumberPlate(

	#define _FIXES_MAYBE_CONST const
#else
	#define _FIXES_MAYBE_CONST
#endif

// All SA:MP natives, copied here for posterity?  No, because then we can
// control the names and keep them fairly well hidden.  Basically we're
// bypassing all the assurances of fixes.inc to get direct access to the
// underlying implementations.

#if defined SAMP_BYPASS_NATIVES
	// Do nothing
#elseif _FIXES_NPC
	// Declare variants of all NPC natives.
	native SetTimer__(const funcname[], interval, repeating) = SetTimer;
	native KillTimer__(timerid) = KillTimer;
	native GetTickCount__() = GetTickCount;
	native Float:asin__(Float:value) = asin;
	native Float:acos__(Float:value) = acos;
	native Float:atan__(Float:value) = atan;
	native Float:atan2__(Float:x, Float:y) = atan2;
	native SendChat__(const msg[]) = SendChat;
	native SendCommand__(const commandtext[]) = SendCommand;
	native PLAYER_STATE:GetPlayerState__(playerid) = GetPlayerState;
	native GetPlayerPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
	native GetPlayerVehicleID__(playerid) = GetPlayerVehicleID;
	native GetPlayerArmedWeapon__(playerid) = GetPlayerArmedWeapon;
	native GetPlayerHealth__(playerid) = GetPlayerHealth;
	native GetPlayerArmour__(playerid) = GetPlayerArmour;
	native SPECIAL_ACTION:GetPlayerSpecialAction__(playerid) = GetPlayerSpecialAction;
	native IsPlayerStreamedIn__(playerid) = IsPlayerStreamedIn;
	native IsVehicleStreamedIn__(vehicleid) = IsVehicleStreamedIn;
	native GetPlayerKeys__(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
	native GetPlayerFacingAngle__(playerid, &Float:ang) = GetPlayerFacingAngle;
	native GetMyPos__(&Float:x, &Float:y, &Float:z) = GetMyPos;
	native SetMyPos__(Float:x, Float:y, Float:z) = SetMyPos;
	native GetMyFacingAngle__(&Float:ang) = GetMyFacingAngle;
	native SetMyFacingAngle__(Float:ang) = SetMyFacingAngle;
	native GetDistanceFromMeToPoint__(Float:X, Float:Y, Float:Z, &Float:Distance) = GetDistanceFromMeToPoint;
	native IsPlayerInRangeOfPoint__(playerid, Float:range, Float:X, Float:Y, Float:Z) = IsPlayerInRangeOfPoint;
	native GetPlayerName__(playerid, name[], len) = GetPlayerName;
	native IsPlayerConnected__(playerid) = IsPlayerConnected;
#else
	native SendClientMessage__(playerid, color, const message[]) = SendClientMessage;
	native SendClientMessageToAll__(color, const message[]) = SendClientMessageToAll;
	native SendPlayerMessageToPlayer__(playerid, senderid, const message[]) = SendPlayerMessageToPlayer;
	native SendPlayerMessageToAll__(senderid, const message[]) = SendPlayerMessageToAll;
	native SendDeathMessage__(killer, killee, weapon) = SendDeathMessage;
	native SendDeathMessageToPlayer__(playerid, killer, killee, weapon) = SendDeathMessageToPlayer;
	native GameTextForAll__(const string[], time, style) = GameTextForAll;
	native GameTextForPlayer__(playerid, const string[], time, style) = GameTextForPlayer;
	native SetTimer__(const funcname[], interval, repeating) = SetTimer;
	native SetTimerEx__(const funcname[], interval, repeating, const format[], {Float,_}:...) = SetTimerEx;
	native KillTimer__(timerid) = KillTimer;
	native GetTickCount__() = GetTickCount;
	native GetMaxPlayers__() = GetMaxPlayers;
	native CallRemoteFunction__(const function[], const format[], {Float,_}:...) = CallRemoteFunction;
	native CallLocalFunction__(const function[], const format[], {Float,_}:...) = CallLocalFunction;
	native Float:VectorSize__(Float:x, Float:y, Float:z) = VectorSize;
	native Float:asin__(Float:value) = asin;
	native Float:acos__(Float:value) = acos;
	native Float:atan__(Float:value) = atan;
	native Float:atan2__(Float:y, Float:x) = atan2;
	native GetPlayerPoolSize__() = GetPlayerPoolSize;
	native GetVehiclePoolSize__() = GetVehiclePoolSize;
	native GetActorPoolSize__() = GetActorPoolSize;
	native SHA256_PassHash__(const password[], const salt[], ret_hash[], ret_hash_len = sizeof ret_hash) = SHA256_PassHash;
	native SetSVarInt__(const varname[], int_value) = SetSVarInt;
	native GetSVarInt__(const varname[]) = GetSVarInt;
	native SetSVarString__(const varname[], const string_value[]) = SetSVarString;
	native GetSVarString__(const varname[], string_return[], len = sizeof string_return) = GetSVarString;
	native SetSVarFloat__(const varname[], Float:float_value) = SetSVarFloat;
	native Float:GetSVarFloat__(const varname[]) = GetSVarFloat;
	native DeleteSVar__(const varname[]) = DeleteSVar;
	native GetSVarsUpperIndex__() = GetSVarsUpperIndex;
	native GetSVarNameAtIndex__(index, ret_varname[], ret_len = sizeof ret_varname) = GetSVarNameAtIndex;
	native GetSVarType__(const varname[]) = GetSVarType;
	native SetGameModeText__(const string[]) = SetGameModeText;
	native SetTeamCount__(count) = SetTeamCount;
	native AddPlayerClass__(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClass;
	native AddPlayerClassEx__(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClassEx;
	native AddStaticVehicle__(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2) = AddStaticVehicle;
	native AddStaticVehicleEx__(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren = 0) = AddStaticVehicleEx;
	native AddStaticPickup__(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0) = AddStaticPickup;
	native CreatePickup__(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0) = CreatePickup;
	native DestroyPickup__(pickup) = DestroyPickup;
	native ShowNameTags__(show) = ShowNameTags;
	native ShowPlayerMarkers__(mode) = ShowPlayerMarkers;
	native GameModeExit__() = GameModeExit;
	native SetWorldTime__(hour) = SetWorldTime;
	native GetWeaponName__(weaponid, weapon[], len = sizeof weapon) = GetWeaponName;
	native EnableTirePopping__(enable) = EnableTirePopping;
	native EnableVehicleFriendlyFire__() = EnableVehicleFriendlyFire;
	native AllowInteriorWeapons__(allow) = AllowInteriorWeapons;
	native SetWeather__(weatherid) = SetWeather;
	native Float:GetGravity__() = GetGravity;
	native SetGravity__(Float:gravity) = SetGravity;
	native AllowAdminTeleport__(allow) = AllowAdminTeleport;
	native SetDeathDropAmount__(amount) = SetDeathDropAmount;
	native CreateExplosion__(Float:X, Float:Y, Float:Z, type, Float:Radius) = CreateExplosion;
	native EnableZoneNames__(enable) = EnableZoneNames;
	native UsePlayerPedAnims__() = UsePlayerPedAnims;
	native DisableInteriorEnterExits__() = DisableInteriorEnterExits; 
	native SetNameTagDrawDistance__(Float:distance) = SetNameTagDrawDistance;
	native DisableNameTagLOS__() = DisableNameTagLOS;
	native LimitGlobalChatRadius__(Float:chat_radius) = LimitGlobalChatRadius;
	native LimitPlayerMarkerRadius__(Float:marker_radius) = LimitPlayerMarkerRadius;
	native ConnectNPC__(const name[], const script[]) = ConnectNPC;
	native IsPlayerNPC__(playerid) = IsPlayerNPC;
	native AddSimpleModel__(virtualworld, baseid, newid, const dffname[], const txdname[]) = AddSimpleModel;
	native AddSimpleModelTimed__(virtualworld, baseid, newid, const dffname[], const txdname[], timeon, timeoff) = AddSimpleModelTimed;
	native FindModelFileNameFromCRC__(crc, retstr[], retstr_size = sizeof retstr) = FindModelFileNameFromCRC;
	native FindTextureFileNameFromCRC__(crc, retstr[], retstr_size = sizeof retstr) = FindTextureFileNameFromCRC;
	native RedirectDownload__(playerid, const url[]) = RedirectDownload;
	native IsPlayerAdmin__(playerid) = IsPlayerAdmin;
	native Kick__(playerid) = Kick;
	native Ban__(playerid) = Ban;
	native BanEx__(playerid, const reason[]) = BanEx;
	native SendRconCommand__(const command[]) = SendRconCommand;
	native GetPlayerNetworkStats__(playerid, retstr[], retstr_size = sizeof retstr) = GetPlayerNetworkStats;
	native GetNetworkStats__(retstr[], retstr_size = sizeof retstr) = GetNetworkStats;
	native GetPlayerVersion__(playerid, version[], len = sizeof version) = GetPlayerVersion;
	native BlockIpAddress__(const ip_address[], timems) = BlockIpAddress;
	native UnBlockIpAddress__(const ip_address[]) = UnBlockIpAddress;
	native GetServerVarAsString__(const varname[], buffer[], len = sizeof buffer) = GetServerVarAsString;
	native GetServerVarAsInt__(const varname[]) = GetServerVarAsInt;
	native GetServerVarAsBool__(const varname[]) = GetServerVarAsBool;
	native GetConsoleVarAsString__(const varname[], buffer[], len = sizeof buffer) = GetConsoleVarAsString;
	native GetConsoleVarAsInt__(const varname[]) = GetConsoleVarAsInt;
	native GetConsoleVarAsBool__(const varname[]) = GetConsoleVarAsBool;
	native GetServerTickRate__() = GetServerTickRate;
	native NetStats_GetConnectedTime__(playerid) = NetStats_GetConnectedTime;
	native NetStats_MessagesReceived__(playerid) = NetStats_MessagesReceived;
	native NetStats_BytesReceived__(playerid) = NetStats_BytesReceived;
	native NetStats_MessagesSent__(playerid) = NetStats_MessagesSent;
	native NetStats_BytesSent__(playerid) = NetStats_BytesSent;
	native NetStats_MsgsRecvPerSecond__(playerid) = NetStats_MessagesRecvPerSecond;
	native Float:NetStats_PacketLossPercent__(playerid) = NetStats_PacketLossPercent;
	native NetStats_ConnectionStatus__(playerid) = NetStats_ConnectionStatus;
	native NetStats_GetIpPort__(playerid, ip_port[], ip_port_len = sizeof ip_port) = NetStats_GetIpPort;
	native Menu:CreateMenu__(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;
	native DestroyMenu__(Menu:menuid) = DestroyMenu;
	native AddMenuItem__(Menu:menuid, column, const menutext[]) = AddMenuItem;
	native SetMenuColumnHeader__(Menu:menuid, column, const columnheader[]) = SetMenuColumnHeader;
	native ShowMenuForPlayer__(Menu:menuid, playerid) = ShowMenuForPlayer;
	native HideMenuForPlayer__(Menu:menuid, playerid) = HideMenuForPlayer;
	native IsValidMenu__(Menu:menuid) = IsValidMenu;
	native DisableMenu__(Menu:menuid) = DisableMenu;
	native DisableMenuRow__(Menu:menuid, row) = DisableMenuRow;
	native Menu:GetPlayerMenu__(playerid) = GetPlayerMenu;
	native Text:TextDrawCreate__(Float:x, Float:y, const text[]) = TextDrawCreate;
	native TextDrawDestroy__(Text:text) = TextDrawDestroy;
	native TextDrawLetterSize__(Text:text, Float:x, Float:y) = TextDrawLetterSize;
	native TextDrawTextSize__(Text:text, Float:x, Float:y) = TextDrawTextSize;
	native TextDrawAlignment__(Text:text, alignment) = TextDrawAlignment;
	native TextDrawColor__(Text:text, color) = TextDrawColor;
	native TextDrawUseBox__(Text:text, use) = TextDrawUseBox;
	native TextDrawBoxColor__(Text:text, color) = TextDrawBoxColor;
	native TextDrawSetShadow__(Text:text, size) = TextDrawSetShadow;
	native TextDrawSetOutline__(Text:text, size) = TextDrawSetOutline;
	native TextDrawBackgroundColor__(Text:text, color) = TextDrawBackgroundColor;
	native TextDrawFont__(Text:text, font) = TextDrawFont;
	native TextDrawSetProportional__(Text:text, set) = TextDrawSetProportional;
	native TextDrawSetSelectable__(Text:text, set) = TextDrawSetSelectable;
	native TextDrawShowForPlayer__(playerid, Text:text) = TextDrawShowForPlayer;
	native TextDrawHideForPlayer__(playerid, Text:text) = TextDrawHideForPlayer;
	native TextDrawShowForAll__(Text:text) = TextDrawShowForAll;
	native TextDrawHideForAll__(Text:text) = TextDrawHideForAll;
	native TextDrawSetString__(Text:text, const string[]) = TextDrawSetString;
	native TextDrawSetPreviewModel__(Text:text, modelindex) = TextDrawSetPreviewModel;
	native TextDrawSetPreviewRot__(Text:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0) = TextDrawSetPreviewRot;
	native TextDrawSetPreviewVehCol__(Text:text, color1, color2) = TextDrawSetPreviewVehCol;
	native GangZoneCreate__(Float:minx, Float:miny, Float:maxx, Float:maxy) = GangZoneCreate;
	native GangZoneDestroy__(zone) = GangZoneDestroy;
	native GangZoneShowForPlayer__(playerid, zone, color) = GangZoneShowForPlayer;
	native GangZoneShowForAll__(zone, color) = GangZoneShowForAll;
	native GangZoneHideForPlayer__(playerid, zone) = GangZoneHideForPlayer;
	native GangZoneHideForAll__(zone) = GangZoneHideForAll;
	native GangZoneFlashForPlayer__(playerid, zone, flashcolor) = GangZoneFlashForPlayer;
	native GangZoneFlashForAll__(zone, flashcolor) = GangZoneFlashForAll;
	native GangZoneStopFlashForPlayer__(playerid, zone) = GangZoneStopFlashForPlayer;
	native GangZoneStopFlashForAll__(zone) = GangZoneStopFlashForAll;
	native Text3D:Create3DTextLabel__(const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS = 0) = Create3DTextLabel;
	native Delete3DTextLabel__(Text3D:id) = Delete3DTextLabel;
	native Attach3DTextLabelToPlayer__(Text3D:id, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ) = Attach3DTextLabelToPlayer;
	native Attach3DTextLabelToVehicle__(Text3D:id, vehicleid, Float:OffsetX, Float:OffsetY, Float:OffsetZ) = Attach3DTextLabelToVehicle;
	native Update3DTextLabelText__(Text3D:id, color, const text[]) = Update3DTextLabelText;
	native PlayerText3D:CreatePlayer3DTextLabel__(playerid, const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testLOS = 0) = CreatePlayer3DTextLabel;
	native DeletePlayer3DTextLabel__(playerid, PlayerText3D:id) = DeletePlayer3DTextLabel;
	native UpdatePlayer3DTextLabelText__(playerid, PlayerText3D:id, color, const text[]) = UpdatePlayer3DTextLabelText;
	native ShowPlayerDialog__(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
	native gpci__(playerid, serial[], maxlen) = gpci;
	native CreateVehicle__(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren = 0) = CreateVehicle;
	native DestroyVehicle__(vehicleid) = DestroyVehicle;
	native IsVehicleStreamedIn__(vehicleid, forplayerid) = IsVehicleStreamedIn;
	native GetVehiclePos__(vehicleid, &Float:x, &Float:y, &Float:z) = GetVehiclePos;
	native SetVehiclePos__(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos;
	native GetVehicleZAngle__(vehicleid, &Float:z_angle) = GetVehicleZAngle;
	native GetVehicleRotationQuat__(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z) = GetVehicleRotationQuat;
	native Float:GetVehicleDistanceFromPoint__(vehicleid, Float:X, Float:Y, Float:Z) = GetVehicleDistanceFromPoint;
	native SetVehicleZAngle__(vehicleid, Float:z_angle) = SetVehicleZAngle;
	native SetVehicleParamsForPlayer__(vehicleid, playerid, objective, doorslocked) = SetVehicleParamsForPlayer;
	native ManualVehicleEngineAndLights__() = ManualVehicleEngineAndLights;
	native SetVehicleParamsEx__(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;
	native GetVehicleParamsEx__(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;
	native GetVehicleParamsSirenState__(vehicleid) = GetVehicleParamsSirenState;
	native SetVehicleParamsCarDoors__(vehicleid, driver, passenger, backleft, backright) = SetVehicleParamsCarDoors;
	native GetVehicleParamsCarDoors__(vehicleid, &driver, &passenger, &backleft, &backright) = GetVehicleParamsCarDoors;
	native SetVehicleParamsCarWindows__(vehicleid, driver, passenger, backleft, backright) = SetVehicleParamsCarWindows;
	native GetVehicleParamsCarWindows__(vehicleid, &driver, &passenger, &backleft, &backright) = GetVehicleParamsCarWindows;
	native SetVehicleToRespawn__(vehicleid) = SetVehicleToRespawn;
	native LinkVehicleToInterior__(vehicleid, interiorid) = LinkVehicleToInterior;
	native AddVehicleComponent__(vehicleid, componentid) = AddVehicleComponent;
	native RemoveVehicleComponent__(vehicleid, componentid) = RemoveVehicleComponent;
	native ChangeVehicleColor__(vehicleid, color1, color2) = ChangeVehicleColor;
	native ChangeVehiclePaintjob__(vehicleid, paintjobid) = ChangeVehiclePaintjob;
	native SetVehicleHealth__(vehicleid, Float:health) = SetVehicleHealth;
	native GetVehicleHealth__(vehicleid, &Float:health) = GetVehicleHealth;
	native AttachTrailerToVehicle__(trailerid, vehicleid) = AttachTrailerToVehicle;
	native DetachTrailerFromVehicle__(vehicleid) = DetachTrailerFromVehicle;
	native IsTrailerAttachedToVehicle__(vehicleid) = IsTrailerAttachedToVehicle;
	native GetVehicleTrailer__(vehicleid) = GetVehicleTrailer;
	native SetVehicleNumberPlate__(vehicleid, const numberplate[]) = SetVehicleNumberPlate;
	native GetVehicleModel__(vehicleid) = GetVehicleModel;
	native GetVehicleComponentInSlot__(vehicleid, slot) = GetVehicleComponentInSlot;
	native GetVehicleComponentType__(component) = GetVehicleComponentType;
	native RepairVehicle__(vehicleid) = RepairVehicle;
	native GetVehicleVelocity__(vehicleid, &Float:X, &Float:Y, &Float:Z) = GetVehicleVelocity;
	native SetVehicleVelocity__(vehicleid, Float:X, Float:Y, Float:Z) = SetVehicleVelocity;
	native SetVehicleAngularVelocity__(vehicleid, Float:X, Float:Y, Float:Z) = SetVehicleAngularVelocity;
	native GetVehicleDamageStatus__(vehicleid, &panels, &doors, &lights, &tires) = GetVehicleDamageStatus;
	native UpdateVehicleDamageStatus__(vehicleid, panels, doors, lights, tires) = UpdateVehicleDamageStatus;
	native GetVehicleModelInfo__(vehiclemodel, infotype, &Float:X, &Float:Y, &Float:Z) = GetVehicleModelInfo;
	native SetVehicleVirtualWorld__(vehicleid, worldid) = SetVehicleVirtualWorld;
	native GetVehicleVirtualWorld__(vehicleid) = GetVehicleVirtualWorld;
	native bool:IsValidVehicle__(vehicleid) = IsValidVehicle;
	native DB:db_open__(const name[]) = db_open;
	native db_close__(DB:db) = db_close;
	native DBResult:db_query__(DB:db, const query[]) = db_query;
	native db_free_result__(DBResult:dbresult) = db_free_result;
	native db_num_rows__(DBResult:dbresult) = db_num_rows;
	native db_next_row__(DBResult:dbresult) = db_next_row;
	native db_num_fields__(DBResult:dbresult) = db_num_fields;
	native db_field_name__(DBResult:dbresult, field, result[], maxlength = sizeof result) = db_field_name;
	native db_get_field__(DBResult:dbresult, field, result[], maxlength = sizeof result) = db_get_field;
	native db_get_field_int__(DBResult:result, field = 0) = db_get_field_int;
	native Float:db_get_field_float__(DBResult:result, field = 0) = db_get_field_float;
	native db_get_field_assoc__(DBResult:dbresult, const field[], result[], maxlength = sizeof result) = db_get_field_assoc;
	native db_get_field_assoc_int__(DBResult:result, const field[]) = db_get_field_assoc_int;
	native Float:db_get_field_assoc_float__(DBResult:result, const field[]) = db_get_field_assoc_float;
	native db_get_mem_handle__(DB:db) = db_get_mem_handle;
	native db_get_result_mem_handle__(DBResult:result) = db_get_result_mem_handle;
	native db_debug_openresults__() = db_debug_openresults;
	native CreateActor__(modelid, Float:X, Float:Y, Float:Z, Float:Rotation) = CreateActor;
	native DestroyActor__(actorid) = DestroyActor;
	native IsActorStreamedIn__(actorid, forplayerid) = IsActorStreamedIn;
	native SetActorVirtualWorld__(actorid, vworld) = SetActorVirtualWorld;
	native GetActorVirtualWorld__(actorid) = GetActorVirtualWorld;
	native ApplyActorAnimation__(actorid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time) = ApplyActorAnimation;
	native ClearActorAnimations__(actorid) = ClearActorAnimations;
	native SetActorPos__(actorid, Float:X, Float:Y, Float:Z) = SetActorPos;
	native GetActorPos__(actorid, &Float:X, &Float:Y, &Float:Z) = GetActorPos;
	native SetActorFacingAngle__(actorid, Float:ang) = SetActorFacingAngle;
	native GetActorFacingAngle__(actorid, &Float:ang) = GetActorFacingAngle;
	native SetActorHealth__(actorid, Float:health) = SetActorHealth;
	native GetActorHealth__(actorid, &Float:health) = GetActorHealth;
	native SetActorInvulnerable__(actorid, invulnerable = true) = SetActorInvulnerable;
	native IsActorInvulnerable__(actorid) = IsActorInvulnerable;
	native IsValidActor__(actorid) = IsValidActor;
	native HTTP__(index, type, const url[], const data[], const callback[]) = HTTP;
	native CreateObject__(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0) = CreateObject;
	native AttachObjectToVehicle__(objectid, vehicleid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ) = AttachObjectToVehicle;
	native AttachObjectToObject__(objectid, attachtoid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ, SyncRotation = 1) = AttachObjectToObject;
	native AttachObjectToPlayer__(objectid, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ) = AttachObjectToPlayer;
	native SetObjectPos__(objectid, Float:X, Float:Y, Float:Z) = SetObjectPos;
	native GetObjectPos__(objectid, &Float:X, &Float:Y, &Float:Z) = GetObjectPos;
	native SetObjectRot__(objectid, Float:RotX, Float:RotY, Float:RotZ) = SetObjectRot;
	native GetObjectRot__(objectid, &Float:RotX, &Float:RotY, &Float:RotZ) = GetObjectRot;
	native GetObjectModel__(objectid) = GetObjectModel;
	native SetObjectNoCameraCol__(objectid) = SetObjectNoCameraCol;
	native IsValidObject__(objectid) = IsValidObject;
	native DestroyObject__(objectid) = DestroyObject;
	native MoveObject__(objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0) = MoveObject;
	native StopObject__(objectid) = StopObject;
	native IsObjectMoving__(objectid) = IsObjectMoving;
	native EditObject__(playerid, objectid) = EditObject;
	native EditPlayerObject__(playerid, objectid) = EditPlayerObject;
	native SelectObject__(playerid) = SelectObject;
	native CancelEdit__(playerid) = CancelEdit;
	native CreatePlayerObject__(playerid, modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0) = CreatePlayerObject;
	native AttachPlayerObjectToVehicle__(playerid, objectid, vehicleid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:RotZ) = AttachPlayerObjectToVehicle;
	native SetPlayerObjectPos__(playerid, objectid, Float:X, Float:Y, Float:Z) = SetPlayerObjectPos;
	native GetPlayerObjectPos__(playerid, objectid, &Float:X, &Float:Y, &Float:Z) = GetPlayerObjectPos;
	native SetPlayerObjectRot__(playerid, objectid, Float:RotX, Float:RotY, Float:RotZ) = SetPlayerObjectRot;
	native GetPlayerObjectRot__(playerid, objectid, &Float:RotX, &Float:RotY, &Float:RotZ) = GetPlayerObjectRot;
	native GetPlayerObjectModel__(playerid, objectid) = GetPlayerObjectModel;
	native SetPlayerObjectNoCameraCol__(playerid, objectid) = SetPlayerObjectNoCameraCol;
	native IsValidPlayerObject__(playerid, objectid) = IsValidPlayerObject;
	native DestroyPlayerObject__(playerid, objectid) = DestroyPlayerObject;
	native MovePlayerObject__(playerid, objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0) = MovePlayerObject;
	native StopPlayerObject__(playerid, objectid) = StopPlayerObject;
	native IsPlayerObjectMoving__(playerid, objectid) = IsPlayerObjectMoving;
	native AttachPlayerObjectToPlayer__(objectplayer, objectid, attachplayer, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:rX, Float:rY, Float:rZ) = AttachPlayerObjectToPlayer;
	native SetObjectMaterial__(objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor = 0) = SetObjectMaterial;
	native SetPlayerObjectMaterial__(playerid, objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor = 0) = SetPlayerObjectMaterial;
	native SetObjectMaterialText__(objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetObjectMaterialText;
	native SetPlayerObjectMaterialText__(playerid, objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetPlayerObjectMaterialText;
	native SetObjectsDefaultCameraCol__(disable) = SetObjectsDefaultCameraCol;
	native SetSpawnInfo__(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = SetSpawnInfo;
	native SpawnPlayer__(playerid) = SpawnPlayer;
	native SetPlayerPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;
	native SetPlayerPosFindZ__(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;
	native GetPlayerPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerPos;
	native SetPlayerFacingAngle__(playerid, Float:ang) = SetPlayerFacingAngle;
	native GetPlayerFacingAngle__(playerid, &Float:ang) = GetPlayerFacingAngle;
	native IsPlayerInRangeOfPoint__(playerid, Float:range, Float:x, Float:y, Float:z) = IsPlayerInRangeOfPoint;
	native Float:GetPlayerDistanceFromPoint__(playerid, Float:X, Float:Y, Float:Z) = GetPlayerDistanceFromPoint;
	native IsPlayerStreamedIn__(playerid, forplayerid) = IsPlayerStreamedIn;
	native SetPlayerInterior__(playerid, interiorid) = SetPlayerInterior;
	native GetPlayerInterior__(playerid) = GetPlayerInterior;
	native SetPlayerHealth__(playerid, Float:health) = SetPlayerHealth;
	native GetPlayerHealth__(playerid, &Float:health) = GetPlayerHealth;
	native SetPlayerArmour__(playerid, Float:armour) = SetPlayerArmour;
	native GetPlayerArmour__(playerid, &Float:armour) = GetPlayerArmour;
	native SetPlayerAmmo__(playerid, weaponslot, ammo) = SetPlayerAmmo;
	native GetPlayerAmmo__(playerid) = GetPlayerAmmo;
	native GetPlayerWeaponState__(playerid) = GetPlayerWeaponState;
	native GetPlayerTargetPlayer__(playerid) = GetPlayerTargetPlayer;
	native GetPlayerTargetActor__(playerid) = GetPlayerTargetActor;
	native SetPlayerTeam__(playerid, teamid) = SetPlayerTeam;
	native GetPlayerTeam__(playerid) = GetPlayerTeam;
	native SetPlayerScore__(playerid, score) = SetPlayerScore;
	native GetPlayerScore__(playerid) = GetPlayerScore;
	native GetPlayerDrunkLevel__(playerid) = GetPlayerDrunkLevel;
	native SetPlayerDrunkLevel__(playerid, level) = SetPlayerDrunkLevel;
	native SetPlayerColor__(playerid, color) = SetPlayerColor;
	native GetPlayerColor__(playerid) = GetPlayerColor;
	native SetPlayerSkin__(playerid, skinid) = SetPlayerSkin;
	native GetPlayerSkin__(playerid) = GetPlayerSkin;
	native GivePlayerWeapon__(playerid, weaponid, ammo) = GivePlayerWeapon;
	native ResetPlayerWeapons__(playerid) = ResetPlayerWeapons;
	native SetPlayerArmedWeapon__(playerid, weaponid) = SetPlayerArmedWeapon;
	native GetPlayerWeaponData__(playerid, slot, &weapons, &ammo) = GetPlayerWeaponData;
	native GivePlayerMoney__(playerid, money) = GivePlayerMoney;
	native ResetPlayerMoney__(playerid) = ResetPlayerMoney;
	native SetPlayerName__(playerid, const name[]) = SetPlayerName;
	native GetPlayerMoney__(playerid) = GetPlayerMoney;
	native PLAYER_STATE:GetPlayerState__(playerid) = GetPlayerState;
	native GetPlayerIp__(playerid, ip[], len = sizeof ip) = GetPlayerIp;
	native GetPlayerPing__(playerid) = GetPlayerPing;
	native GetPlayerWeapon__(playerid) = GetPlayerWeapon;
	native GetPlayerKeys__(playerid, &KEY:keys, &KEY:updown, &KEY:leftright) = GetPlayerKeys;
	native GetPlayerName__(playerid, name[], len = sizeof name) = GetPlayerName;
	native SetPlayerTime__(playerid, hour, minute) = SetPlayerTime;
	native GetPlayerTime__(playerid, &hour, &minute) = GetPlayerTime;
	native TogglePlayerClock__(playerid, toggle) = TogglePlayerClock;
	native SetPlayerWeather__(playerid, weather) = SetPlayerWeather;
	native ForceClassSelection__(playerid) = ForceClassSelection;
	native SetPlayerWantedLevel__(playerid, level) = SetPlayerWantedLevel;
	native GetPlayerWantedLevel__(playerid) = GetPlayerWantedLevel;
	native SetPlayerFightingStyle__(playerid, style) = SetPlayerFightingStyle;
	native GetPlayerFightingStyle__(playerid) = GetPlayerFightingStyle;
	native SetPlayerVelocity__(playerid, Float:X, Float:Y, Float:Z) = SetPlayerVelocity;
	native GetPlayerVelocity__( playerid, &Float:X, &Float:Y, &Float:Z ) = GetPlayerVelocity;
	native PlayCrimeReportForPlayer__(playerid, suspectid, crime) = PlayCrimeReportForPlayer;
	native PlayAudioStreamForPlayer__(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0) = PlayAudioStreamForPlayer;
	native StopAudioStreamForPlayer__(playerid) = StopAudioStreamForPlayer;
	native SetPlayerShopName__(playerid, const shopname[]) = SetPlayerShopName;
	native SetPlayerSkillLevel__(playerid, skill, level) = SetPlayerSkillLevel;
	native GetPlayerSurfingVehicleID__(playerid) = GetPlayerSurfingVehicleID;
	native GetPlayerSurfingObjectID__(playerid) = GetPlayerSurfingObjectID;
	native RemoveBuildingForPlayer__(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius) = RemoveBuildingForPlayer;
	native GetPlayerLastShotVectors__(playerid, &Float:fOriginX, &Float:fOriginY, &Float:fOriginZ, &Float:fHitPosX, &Float:fHitPosY, &Float:fHitPosZ) = GetPlayerLastShotVectors;
	native SetPlayerAttachedObject__(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0) = SetPlayerAttachedObject;
	native RemovePlayerAttachedObject__(playerid, index) = RemovePlayerAttachedObject;
	native IsPlayerAttachedSlotUsed__(playerid, index) = IsPlayerAttachedObjectSlotUsed;
	native EditAttachedObject__(playerid, index) = EditAttachedObject;
	native PlayerText:CreatePlayerTextDraw__(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
	native PlayerTextDrawDestroy__(playerid, PlayerText:text) = PlayerTextDrawDestroy;
	native PlayerTextDrawLetterSize__(playerid, PlayerText:text, Float:x, Float:y) = PlayerTextDrawLetterSize;
	native PlayerTextDrawTextSize__(playerid, PlayerText:text, Float:x, Float:y) = PlayerTextDrawTextSize;
	native PlayerTextDrawAlignment__(playerid, PlayerText:text, alignment) = PlayerTextDrawAlignment;
	native PlayerTextDrawColor__(playerid, PlayerText:text, color) = PlayerTextDrawColor;
	native PlayerTextDrawUseBox__(playerid, PlayerText:text, use) = PlayerTextDrawUseBox;
	native PlayerTextDrawBoxColor__(playerid, PlayerText:text, color) = PlayerTextDrawBoxColor;
	native PlayerTextDrawSetShadow__(playerid, PlayerText:text, size) = PlayerTextDrawSetShadow;
	native PlayerTextDrawSetOutline__(playerid, PlayerText:text, size) = PlayerTextDrawSetOutline;
	native PlayerTextDrawBackgroundColor__(playerid, PlayerText:text, color) = PlayerTextDrawBackgroundColor;
	native PlayerTextDrawFont__(playerid, PlayerText:text, font) = PlayerTextDrawFont;
	native PlayerTextDrawSetProportional__(playerid, PlayerText:text, set) = PlayerTextDrawSetProportional;
	native PlayerTextDrawSetSelectable__(playerid, PlayerText:text, set) = PlayerTextDrawSetSelectable;
	native PlayerTextDrawShow__(playerid, PlayerText:text) = PlayerTextDrawShow;
	native PlayerTextDrawHide__(playerid, PlayerText:text) = PlayerTextDrawHide;
	native PlayerTextDrawSetString__(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
	native PlayerTextDrawSetPreviewModel__(playerid, PlayerText:text, modelindex) = PlayerTextDrawSetPreviewModel;
	native PlayerTextDrawSetPreviewRot__(playerid, PlayerText:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0) = PlayerTextDrawSetPreviewRot;
	native PlayerTDSetPreviewVehCol__(playerid, PlayerText:text, color1, color2) = PlayerTextDrawSetPreviewVehCol;
	native SetPVarInt__(playerid, const varname[], int_value) = SetPVarInt;
	native GetPVarInt__(playerid, const varname[]) = GetPVarInt;
	native SetPVarString__(playerid, const varname[], const string_value[]) = SetPVarString;
	native GetPVarString__(playerid, const varname[], string_return[], len = sizeof string_return) = GetPVarString;
	native SetPVarFloat__(playerid, const varname[], Float:float_value) = SetPVarFloat;
	native Float:GetPVarFloat__(playerid, const varname[]) = GetPVarFloat;
	native DeletePVar__(playerid, const varname[]) = DeletePVar;
	native GetPVarsUpperIndex__(playerid) = GetPVarsUpperIndex;
	native GetPVarNameAtIndex__(playerid, index, ret_varname[], ret_len = sizeof ret_varname) = GetPVarNameAtIndex;
	native PLAYER_VARTYPE:GetPVarType__(playerid, const varname[]) = GetPVarType;
	native SetPlayerChatBubble__(playerid, const text[], color, Float:drawdistance, expiretime) = SetPlayerChatBubble;
	native PutPlayerInVehicle__(playerid, vehicleid, seatid) = PutPlayerInVehicle;
	native GetPlayerVehicleID__(playerid) = GetPlayerVehicleID;
	native GetPlayerVehicleSeat__(playerid) = GetPlayerVehicleSeat;
	native RemovePlayerFromVehicle__(playerid) = RemovePlayerFromVehicle;
	native TogglePlayerControllable__(playerid, toggle) = TogglePlayerControllable;
	native PlayerPlaySound__(playerid, soundid, Float:x, Float:y, Float:z) = PlayerPlaySound;
	native ApplyAnimation__(playerid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
	native ClearAnimations__(playerid, forcesync = 0) = ClearAnimations;
	native GetPlayerAnimationIndex__(playerid) = GetPlayerAnimationIndex;
	native GetAnimationName__(index, animlib[], len1 = sizeof animlib, animname[], len2 = sizeof animname) = GetAnimationName;
	native SPECIAL_ACTION:GetPlayerSpecialAction__(playerid) = GetPlayerSpecialAction;
	native SetPlayerSpecialAction__(playerid, actionid) = SetPlayerSpecialAction;
	native DisableRemoteVehicleCols__(playerid, disable) = DisableRemoteVehicleCollisions;
	native SetPlayerCheckpoint__(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
	native DisablePlayerCheckpoint__(playerid) = DisablePlayerCheckpoint;
	native SetPlayerRaceCheckpoint__(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size) = SetPlayerRaceCheckpoint;
	native DisablePlayerRaceCheckpoint__(playerid) = DisablePlayerRaceCheckpoint;
	native SetPlayerWorldBounds__(playerid, Float:x_max,Float:x_min,Float:y_max,Float:y_min) = SetPlayerWorldBounds;
	native SetPlayerMarkerForPlayer__(playerid, showplayerid, color) = SetPlayerMarkerForPlayer;
	native ShowPlayerNameTagForPlayer__(playerid, showplayerid, show) = ShowPlayerNameTagForPlayer;
	native SetPlayerMapIcon__(playerid, iconid, Float:x, Float:y, Float:z, markertype, color, style = MAPICON_LOCAL) = SetPlayerMapIcon;
	native RemovePlayerMapIcon__(playerid, iconid) = RemovePlayerMapIcon;
	native AllowPlayerTeleport__(playerid, allow) = AllowPlayerTeleport;
	native SetPlayerCameraPos__(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;
	native SetPlayerCameraLookAt__(playerid, Float:x, Float:y, Float:z, cut = CAMERA_CUT) = SetPlayerCameraLookAt;
	native SetCameraBehindPlayer__(playerid) = SetCameraBehindPlayer;
	native GetPlayerCameraPos__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraPos;
	native GetPlayerCameraFrontVector__(playerid, &Float:x, &Float:y, &Float:z) = GetPlayerCameraFrontVector;
	native GetPlayerCameraMode__(playerid) = GetPlayerCameraMode;
	native EnablePlayerCameraTarget__(playerid, enable) = EnablePlayerCameraTarget;
	native GetPlayerCameraTargetObject__(playerid) = GetPlayerCameraTargetObject;
	native GetPlayerCameraTargetVehicle__(playerid) = GetPlayerCameraTargetVehicle;
	native GetPlayerCameraTargetPlayer__(playerid) = GetPlayerCameraTargetPlayer;
	native GetPlayerCameraTargetActor__(playerid) = GetPlayerCameraTargetActor;
	native Float:GetPlayerCameraAspectRatio__(playerid) = GetPlayerCameraAspectRatio;
	native Float:GetPlayerCameraZoom__(playerid) = GetPlayerCameraZoom;
	native AttachCameraToObject__(playerid, objectid) = AttachCameraToObject;
	native AttachCameraToPlayerObject__(playerid, playerobjectid) = AttachCameraToPlayerObject;
	native InterpolateCameraPos__(playerid, Float:FromX, Float:FromY, Float:FromZ, Float:ToX, Float:ToY, Float:ToZ, time, cut = CAMERA_CUT) = InterpolateCameraPos;
	native InterpolateCameraLookAt__(playerid, Float:FromX, Float:FromY, Float:FromZ, Float:ToX, Float:ToY, Float:ToZ, time, cut = CAMERA_CUT) = InterpolateCameraLookAt;
	native IsPlayerConnected__(playerid) = IsPlayerConnected;
	native IsPlayerInVehicle__(playerid, vehicleid) = IsPlayerInVehicle;
	native IsPlayerInAnyVehicle__(playerid) = IsPlayerInAnyVehicle;
	native IsPlayerInCheckpoint__(playerid) = IsPlayerInCheckpoint;
	native IsPlayerInRaceCheckpoint__(playerid) = IsPlayerInRaceCheckpoint;
	native SetPlayerVirtualWorld__(playerid, worldid) = SetPlayerVirtualWorld;
	native GetPlayerVirtualWorld__(playerid) = GetPlayerVirtualWorld;
	native EnableStuntBonusForPlayer__(playerid, enable) = EnableStuntBonusForPlayer;
	native EnableStuntBonusForAll__(enable) = EnableStuntBonusForAll;
	native TogglePlayerSpectating__(playerid, toggle) = TogglePlayerSpectating;
	native PlayerSpectatePlayer__(playerid, targetplayerid, mode = SPECTATE_MODE_NORMAL) = PlayerSpectatePlayer;
	native PlayerSpectateVehicle__(playerid, targetvehicleid, mode = SPECTATE_MODE_NORMAL) = PlayerSpectateVehicle;
	native StartRecordingPlayerData__(playerid, recordtype, const recordname[]) = StartRecordingPlayerData;
	native StopRecordingPlayerData__(playerid) = StopRecordingPlayerData;
	native SelectTextDraw__(playerid, hovercolor) = SelectTextDraw;
	native CancelSelectTextDraw__(playerid) = CancelSelectTextDraw;	// cancel textdraw selection with the mouse
	native CreateExplosionForPlayer__(playerid, Float:X, Float:Y, Float:Z, type, Float:Radius) = CreateExplosionForPlayer;
	native SendClientCheck__(playerid, type, memAddr, memOffset, byteCount) = SendClientCheck;
#endif

/*

      ,ad8888ba,                                                                                                 
     d8"'    `"8b                                                      ,d                                        
    d8'        `8b                                                     88                                        
    88          88  8b,dPPYba,    ,adPPYba,  8b,dPPYba,  ,adPPYYba,  MM88MMM  ,adPPYba,   8b,dPPYba,  ,adPPYba,  
    88          88  88P'    "8a  a8P_____88  88P'   "Y8  ""     `Y8    88    a8"     "8a  88P'   "Y8  I8[    ""  
    Y8,        ,8P  88       d8  8PP"""""""  88          ,adPPPPP88    88    8b       d8  88           `"Y8ba,   
     Y8a.    .a8P   88b,   ,a8"  "8b,   ,aa  88          88,    ,88    88,   "8a,   ,a8"  88          aa    ]8I  
      `"Y8888Y"'    88`YbbdP"'    `"Ybbd8"'  88          `"8bbdP"Y8    "Y888  `"YbbdP"'   88          `"YbbdP"'  
                    88                                                                                           
                    88                                                                                           

*/

/**
 * <remarks>
 * File operators
 *
 * Forwards for operators that shouldn't exist, so they won't exist.
 * </remarks>
 */

#if FIX_FileMaths
	forward File:operator++(File:a);
	forward File:operator--(File:a);
	forward File:operator-(File:a);
	forward File:operator+(File:a, File:b);
	forward File:operator+(File:a, _:b);
	forward File:operator-(File:a, File:b);
	forward File:operator-(_:a, File:b);
	forward File:operator-(File:a, _:b);
	forward File:operator*(File:a, File:b);
	forward File:operator*(File:a, _:b);
	forward File:operator/(File:a, File:b);
	forward File:operator/(_:a, File:b);
	forward File:operator/(File:a, _:b);
	forward File:operator%(File:a, File:b);
	forward File:operator%(_:a, File:b);
	forward File:operator%(File:a, _:b);
	forward bool:operator<(File:a, File:b);
	forward bool:operator<(_:a, File:b);
	forward bool:operator<(File:a, _:b);
	forward bool:operator<=(File:a, File:b);
	forward bool:operator<=(_:a, File:b);
	forward bool:operator<=(File:a, _:b);
	forward bool:operator>(File:a, File:b);
	forward bool:operator>(_:a, File:b);
	forward bool:operator>(File:a, _:b);
	forward bool:operator>=(File:a, File:b);
	forward bool:operator>=(_:a, File:b);
	forward bool:operator>=(File:a, _:b);
#endif

/*

    88                                                                       88  
    88                ,d                                                     88  
    88                88                                                     88  
    88  8b,dPPYba,  MM88MMM  ,adPPYba,  8b,dPPYba,  8b,dPPYba,   ,adPPYYba,  88  
    88  88P'   `"8a   88    a8P_____88  88P'   "Y8  88P'   `"8a  ""     `Y8  88  
    88  88       88   88    8PP"""""""  88          88       88  ,adPPPPP88  88  
    88  88       88   88,   "8b,   ,aa  88          88       88  88,    ,88  88  
    88  88       88   "Y888  `"Ybbd8"'  88          88       88  `"8bbdP"Y8  88  



*/

/**
 * <remarks>
 * Figure out what OS this is running on.
 * </remarks>
 * <fixes>IS_WINDOWS</fixes>
 * <fixes>IS_LINUX</fixes>
 */
static stock _FIXES_DetermineOS()
{
	if (FIXES_gsKnownOS)
	{
		return;
	}
	FIXES_gsKnownOS = true;
	new
		val;
	// The code at address 0 is always `HALT`.
	#emit LCTRL                0
	#emit MOVE.alt
	#emit LCTRL                1
	#emit SUB.alt
	#emit STOR.S.pri           val
	#emit LREF.S.alt           val
	#emit STOR.S.alt           val
	_FIXES_gIsWindows = (val == 120);
}

#if !FIX_OS
	// Disable this call when not using the fix, but without putting the
	// assembly in a conditional block.
	#define _FIXES_DetermineOS();
#endif

/*
 * _FIXES_Bernstein()
 *
 * Convert a string to a number (hash it).
 *
 * FIXES:
 *    GetServerVarAsString
 *    GetServerVarAsBool
 *    GetServerVarAsInt
 */

static stock _FIXES_Bernstein(const name[])
{
	new
		i = -1,
		ch,
		hash = 5381;
	// In carcols.dat the vehicle names end at ",".  That makes this code
	// very specific to a few use-cases.  It also works for hashing server vars,
	// since they don't have commas.  Now case-insensitive.  Why does this
	// mention `carcols.dat` in the comments?  Were we planning a vehicle colour
	// fix that never got implemented?
	while ((ch = name[++i]) >= '0')
	{
		hash = (hash * 33) ^ (ch | 0x20);
	}
	return hash;
}

/**
 * <remarks>
 * Modify a constant reference.
 * </remarks>
 */

#if _FIXES_NEW_COMPILER
	#pragma warning push
	#pragma warning disable 238
#endif

static stock _FIXES_ConstMod(const &target, chr)
{
	#pragma unused target, chr
	#emit LOAD.S.pri chr
	#emit SREF.S.pri target
}

#if _FIXES_NEW_COMPILER
	#pragma warning pop
#endif

/**
 * <remarks>
 * Removes whitespace from the right side of a string.  Modifies <c>const</c>
 * strings to make it appear that nothing changes, so needs some tricky playing
 * to make it work.
 * </remarks>
 */

static stock _FIXES_RTrim(const string[])
{
	new
		length = strlen(string);
	while (length--)
	{
		if (string[length] > ' ')
			break;
	}
	FIXES_gsTrimPos = length + 1,
	FIXES_gsTrimChr = string[FIXES_gsTrimPos],
	_FIXES_ConstMod(string[FIXES_gsTrimPos], '\0');
}

/**
 * <remarks>
 * Puts whitespace back on the right side of a string.  Makes certain functions
 * appear <c>const</c> because the string ends up the same as it started.
 * </remarks>
 */

static stock _FIXES_UnTrim(const string[])
{
	_FIXES_ConstMod(string[FIXES_gsTrimPos], FIXES_gsTrimChr);
}

/**
 * <remarks>
 * Add something to an internal linked list.
 * </remarks>
 */

static stock _FIXES_AddInternal(array[], value, size)
{
	if (array[value] <= value)
	{
		new
			last = size,
			next = array[last];
		while (next < value)
		{
			last = next,
			next = array[last];
		}
		array[next - 1] = value + 1,
		array[(value - 1) % (size + 1)] = (last + 1) % (size + 1),
		array[last] = value,
		array[value] = next;
	}
}

/**
 * <remarks>
 * Remove something from an internal linked list.
 * </remarks>
 */

static stock _FIXES_RemoveInternal(array[], value, size)
{
	if (array[value] > value)
	{
		static
			last;
		// Adjustment for easier "mod"ing.
		++size,
		last = (array[(value - 1) % size] - 1) % size,
		// Store the reverse value here as well as in the previous slot.
		array[value] =
			// Copy the next value to the last value.
			array[(array[last] = array[value]) - 1] =
				// Set the reverse iterator value.
				(last + 1) % size;
	}
}

/**
 * <remarks>
 * Figure out which script is called first by callbacks.
 * </remarks>
 */

#if !FIXES_Single
	forward _FIXES_DetermineOrder();

	static FIXES_DetermineOrder()
	{
		deleteproperty(5, FIXES_gscOrderProperty),
		// Called in the Game Mode first (thus needs correcting).
		setproperty(5, FIXES_gscNoGMProperty, 1),
		CallRemoteFunction__(FIXES_gscDetermineOrder, FIXES_gscSpec@),
		deleteproperty(5, FIXES_gscNoGMProperty),
		CallRemoteFunction__(FIXES_gscDetermineOrder, FIXES_gscSpec@);
	}
#endif

/**
 * <remarks>
 * Check if files outside <c>scriptfiles</c> can be accessed via
 * <c>DANGEROUS_SERVER_ROOT</c>.
 * </remarks>
 */

#if FIX_GetConsoleVarAsString || FIX_GetConsoleVarAsFloat || FIX_GetConsoleVarAsInt || FIX_GetConsoleVarAsBool
	static stock _FIXES_CheckServerRoot()
	{
		FIXES_gsServerCFG = fopen("DANGEROUS_SERVER_ROOT/server.cfg", io_read);
		#if FIXES_ServerVarMsg
			if (!FIXES_gsServerCFG)
			{
				print(_FIXES_gIsFilterscript ? FIXES_gscPrintFFS : FIXES_gscPrintFGM);
				print(" ");
				print("********************************************************************************");
				print("* Could not open \"DANGEROUS_SERVER_ROOT/server.cfg\".  Make sure your server is *");
				print("* configured to allow server root access.  Either via:                         *");
				print("*                                                                              *");
				print("*     https://github.com/Misiur/YSI/raw/master/links.rar                       *");
				print("*                                                                              *");
				print("* Or (Windows - CMD):                                                          *");
				print("*                                                                              *");
				print("*     cd scriptfiles                                                           *");
				print("*     mklink /J DANGEROUS_SERVER_ROOT ..                                       *");
				print("*                                                                              *");
				print("* Or (Windows - PowerShell):                                                   *");
				print("*                                                                              *");
				print("*     cd scriptfiles                                                           *");
				print("*     cmd /c mklink /J DANGEROUS_SERVER_ROOT ..                                *");
				print("*                                                                              *");
				print("* Or (Linux):                                                                  *");
				print("*                                                                              *");
				print("*     cd scriptfiles                                                           *");
				print("*     ln -s .. DANGEROUS_SERVER_ROOT                                           *");
				print("*                                                                              *");
				print("* If you're not able to, or just don't want to make these changes you can      *");
				print("* suppress the warning by defining this at the top of your mode:               *");
				print("*                                                                              *");
				print("*     #define FIXES_ServerVarMsg 0                                             *");
				print("*                                                                              *");
				print("* Or (preferably) disable the relevant fixes with:                             *");
				print("*                                                                              *");
				print("*     #define FIX_GetConsoleVarAsString 0                                      *");
				print("*     #define FIX_GetConsoleVarAsFloat  0                                      *");
				print("*     #define FIX_GetConsoleVarAsInt    0                                      *");
				print("*     #define FIX_GetConsoleVarAsBool   0                                      *");
				print("*                                                                              *");
				print("********************************************************************************");
				print(" ");
			}
		#endif
	}
#else
	#define _FIXES_CheckServerRoot();
#endif

/**
 * <remarks>
 * Check if <c>MAX_PLAYERS</c> equals <c>GetMaxPlayers</c>, for efficiency. 
 * </remarks>
 */

static stock _FIXES_CheckMaxPlayers()
{
		_FIXES_gsMaxPlayers = GetMaxPlayers__();
		// Check max players match.
		if (_FIXES_gsMaxPlayers > MAX_PLAYERS)
		{
			#if FIXES_GetMaxPlayersMsg
				printf("\7\7\7\7\7*** fixes.inc error: Server var `maxplayers` (%d) > `MAX_PLAYERS` (%d), may", _FIXES_gsMaxPlayers, MAX_PLAYERS),
				print(           "***                  cause OOBs with many players.  Recompile your mode with a"),
				print(           "***                  higher `MAX_PLAYERS` to ensure sufficient array space."),
				print(FIXES_gscThreeStars),
				print(           "***                  Disable this message with:"),
				print(FIXES_gscThreeStars),
				print(           "***                      #define FIXES_GetMaxPlayersMsg 0"),
				print(FIXES_gscThreeStars);
			#endif
			_FIXES_gsMaxPlayers = MAX_PLAYERS;
		}
	#if FIXES_GetMaxPlayersMsg
		else if (_FIXES_gsMaxPlayers < MAX_PLAYERS)
		{
			printf("\7\7\7*** fixes.inc warning: Server var `maxplayers` (%d) < `MAX_PLAYERS` (%d), wasting memory.", _FIXES_gsMaxPlayers, MAX_PLAYERS),
			print(FIXES_gscThreeStars),
			print(       "***                    Disable this message with:"),
			print(FIXES_gscThreeStars),
			print(       "***                        #define FIXES_GetMaxPlayersMsg 0"),
			print(FIXES_gscThreeStars);
		}
	#endif
}

/**
 * <remarks>
 * Create the text draws used to replicate game texts.
 * </remarks>
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	static _FIXES_CreateGameTextDraws(const playerid)
	{
		if (playerid == INVALID_PLAYER_ID)
		{
				new
					Text:t;

			#if FIX_GameTextStyles

				// Global style 7 (vehicle name).
				t = FIXES_gsGTStyle[7] = TextDrawCreate__(608.0, 344.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 1.0, 3.0),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0x36682CFF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 10.0, 200.0);

				// Global style 8 (location name).
				t = FIXES_gsGTStyle[8] = TextDrawCreate__(608.0, 385.8, FIXES_gsSpace),
				TextDrawLetterSize__(t, 1.2, 3.8),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0xACCBF1FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 0),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 10.0, 200.0);

				// Global style 9 (radio name).
				t = FIXES_gsGTStyle[9] = TextDrawCreate__(320.0, 22.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.6, 1.8),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0x906210FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 1),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 10 (radio switch).
				t = FIXES_gsGTStyle[10] = TextDrawCreate__(320.0, 22.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.6, 1.8),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0x969696FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 1),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 11 (positive money).
				t = FIXES_gsGTStyle[11] = TextDrawCreate__(608.0, 77.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.55, 2.2),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0x36682CFF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, false),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 10.0, 200.0);

				// Global style 12 (negative money).
				t = FIXES_gsGTStyle[12] = TextDrawCreate__(608.0, 77.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.55, 2.2),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0xB4191DFF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, false),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 10.0, 200.0);

				// Global style 13 (stunt).
				t = FIXES_gsGTStyle[13] = TextDrawCreate__(380.0, 341.15, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.58, 2.42),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0xDDDDDBFF),
				TextDrawSetShadow__(t, 2),
				TextDrawSetOutline__(t, 0),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 1),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 40.0, 460.0);

				// Global style 14 (clock).
				t = FIXES_gsGTStyle[14] = TextDrawCreate__(608.0, 22.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.55, 2.2),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0xE1E1E1FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, false),
				TextDrawUseBox__(t, false),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 400.0, 20.0);

				// Global style 15 (popup).
				t = FIXES_gsGTStyle[15] = TextDrawCreate__(34.0, 28.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.52, 2.2),
				TextDrawAlignment__(t, 1),
				TextDrawColor__(t, 0xFFFFFF96),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 0),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 1),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000080),
				TextDrawTextSize__(t, 230.5, 200.0);

			#endif

				// Global style 0.
				t = FIXES_gsGTStyle[0] = TextDrawCreate__(320.0, 214.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 1.3, 3.6),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0x906210FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 1.
				t = FIXES_gsGTStyle[1] = TextDrawCreate__(620.0, 310.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 1.0, 2.6),
				TextDrawAlignment__(t, 3),
				TextDrawColor__(t, 0x906210FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 10.0, 200.0);

				// Global style 2.
				t = FIXES_gsGTStyle[2] = TextDrawCreate__(320.0, 156.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 2.1, 4.2),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0xE1E1E1FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 3),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 0),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 3.
				t = FIXES_gsGTStyle[3] = TextDrawCreate__(320.0, 154.5, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.6, 2.75),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0x906210FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 4.
				t = FIXES_gsGTStyle[4] = TextDrawCreate__(320.0, 115.5, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.6, 2.75),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0x906210FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 5.
				t = FIXES_gsGTStyle[5] = TextDrawCreate__(320.0, 217.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 0.6, 2.75),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0xE1E1E1FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 2),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);

				// Global style 6.
				t = FIXES_gsGTStyle[6] = TextDrawCreate__(320.0, 60.0, FIXES_gsSpace),
				TextDrawLetterSize__(t, 1.0, 3.6),
				TextDrawAlignment__(t, 2),
				TextDrawColor__(t, 0xACCBF1FF),
				TextDrawSetShadow__(t, 0),
				TextDrawSetOutline__(t, 2),
				TextDrawBackgroundColor__(t, 0x000000AA),
				TextDrawFont__(t, 3),
				TextDrawSetProportional__(t, true),
				TextDrawUseBox__(t, true),
				TextDrawBoxColor__(t, 0x00000000),
				TextDrawTextSize__(t, 200.0, 620.0);
		}
		else
		{
				new
					PlayerText:t;

			#if FIX_GameTextStyles

				// Global style 7 (playerid, vehicle name).
				t = FIXES_gsPGTStyle[playerid][7] = CreatePlayerTextDraw__(playerid, 608.0, 344.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 1.0, 3.0),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0x36682CFF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 10.0, 200.0);

				// Global style 8 (playerid, location name).
				t = FIXES_gsPGTStyle[playerid][8] = CreatePlayerTextDraw__(playerid, 608.0, 385.8, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 1.2, 3.8),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0xACCBF1FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 0),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 10.0, 200.0);

				// Global style 9 (playerid, radio name).
				t = FIXES_gsPGTStyle[playerid][9] = CreatePlayerTextDraw__(playerid, 320.0, 22.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.6, 1.8),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 1),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 10 (playerid, radio switch).
				t = FIXES_gsPGTStyle[playerid][10] = CreatePlayerTextDraw__(playerid, 320.0, 22.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.6, 1.8),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0x969696FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 1),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 11 (playerid, positive money).
				t = FIXES_gsPGTStyle[playerid][11] = CreatePlayerTextDraw__(playerid, 608.0, 77.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.55, 2.2),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0x36682CFF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, false),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 10.0, 200.0);

				// Global style 12 (playerid, negative money).
				t = FIXES_gsPGTStyle[playerid][12] = CreatePlayerTextDraw__(playerid, 608.0, 77.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.55, 2.2),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0xB4191DFF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, false),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 10.0, 200.0);

				// Global style 13 (playerid, stunt).
				t = FIXES_gsPGTStyle[playerid][13] = CreatePlayerTextDraw__(playerid, 380.0, 341.15, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.58, 2.42),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0xDDDDDBFF),
				PlayerTextDrawSetShadow__(playerid, t, 2),
				PlayerTextDrawSetOutline__(playerid, t, 0),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 1),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 40.0, 460.0);

				// Global style 14 (clock).
				t = FIXES_gsPGTStyle[playerid][14] = CreatePlayerTextDraw__(playerid, 608.0, 22.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.55, 2.2),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0xE1E1E1FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, false),
				PlayerTextDrawUseBox__(playerid, t, false),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 400.0, 20.0);

				// Global style 15 (playerid, popup).
				t = FIXES_gsPGTStyle[playerid][15] = CreatePlayerTextDraw__(playerid, 34.0, 28.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.52, 2.2),
				PlayerTextDrawAlignment__(playerid, t, 1),
				PlayerTextDrawColor__(playerid, t, 0xFFFFFF96),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 0),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 1),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000080),
				PlayerTextDrawTextSize__(playerid, t, 230.5, 200.0);

			#endif

				// Global style 0.
				t = FIXES_gsPGTStyle[playerid][0] = CreatePlayerTextDraw__(playerid, 320.0, 214.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 1.3, 3.6),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 1.
				t = FIXES_gsPGTStyle[playerid][1] = CreatePlayerTextDraw__(playerid, 620.0, 310.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 1.0, 2.6),
				PlayerTextDrawAlignment__(playerid, t, 3),
				PlayerTextDrawColor__(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 10.0, 200.0);

				// Global style 2.
				t = FIXES_gsPGTStyle[playerid][2] = CreatePlayerTextDraw__(playerid, 320.0, 156.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 2.1, 4.2),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0xE1E1E1FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 3),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 0),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 3.
				t = FIXES_gsPGTStyle[playerid][3] = CreatePlayerTextDraw__(playerid, 320.0, 154.5, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.6, 2.75),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 4.
				t = FIXES_gsPGTStyle[playerid][4] = CreatePlayerTextDraw__(playerid, 320.0, 115.5, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.6, 2.75),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 5.
				t = FIXES_gsPGTStyle[playerid][5] = CreatePlayerTextDraw__(playerid, 320.0, 217.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 0.6, 2.75),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0xE1E1E1FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 2),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);

				// Global style 6.
				t = FIXES_gsPGTStyle[playerid][6] = CreatePlayerTextDraw__(playerid, 320.0, 60.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize__(playerid, t, 1.0, 3.6),
				PlayerTextDrawAlignment__(playerid, t, 2),
				PlayerTextDrawColor__(playerid, t, 0xACCBF1FF),
				PlayerTextDrawSetShadow__(playerid, t, 0),
				PlayerTextDrawSetOutline__(playerid, t, 2),
				PlayerTextDrawBackgroundColor__(playerid, t, 0x000000AA),
				PlayerTextDrawFont__(playerid, t, 3),
				PlayerTextDrawSetProportional__(playerid, t, true),
				PlayerTextDrawUseBox__(playerid, t, true),
				PlayerTextDrawBoxColor__(playerid, t, 0x00000000),
				PlayerTextDrawTextSize__(playerid, t, 200.0, 620.0);
		}
	}
#endif

/**
 * <fixes>ApplyAnimation</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 * <fixes>ApplyActorAnimation</fixes>
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2 || FIX_API
	#if !FIX_API
	static
	#endif
	stock _FIXES_GetAnimLibIndex(const animlib[])
	{
		new
			diff,
			idx = animlib[0] & ~0x20;
		// Uses a sort of optimised binary search.  The code first identifies the area in the array
		// in which libraries with this first letter are, then does a binary search using only that
		// subset of the array.  This used to use an N-ary search that just went linearly through
		// the identified subset of the array, and that was 5x faster than a simple linear loop over
		// the whole array.  This new version is 50% faster than even that was.  "E" has no
		// libraries, but we don't check for that explicitly as it would slow down the more common
		// code path - and it ends fairly quickly anyway as "upper == lower".
		if (_FIXES_IN_RANGE(idx, 'A', 'W' + 1))
		{
			new
				upper = FIXES_gscAnimIndexes[idx - ('A' - 1)],
				lower = FIXES_gscAnimIndexes[idx - 'A'];
			while (upper != lower)
			{
				idx = (upper - lower) / 2 + lower;
				if ((diff = strcmp(FIXES_gscAnimLib[idx], animlib, true)))
				{
					if (diff > 0) upper = idx;
					else lower = idx + 1;
				}
				else
				{
					return idx;
				}
			}
		}

		return -1;
	}
#endif

#if FIX_CreateVehicle || FIX_API
	#if !FIX_API
	static
	#endif
	stock bool:_FIXES_GetRandomCarColPair(modelid, &colour1, &colour2, &colour3 = 0, &colour4 = 0)
	{
		modelid -= 400;
		if (_FIXES_IN_RANGE(modelid, 0, 211 + 1))
		{
			new
				start = FIXES_gscVehicleIndexes[modelid],
				end = FIXES_gscVehicleIndexes[modelid + 1];

			if (start == end)
			{
				// Has no paint options.
				return
					colour1 = 0,
					colour2 = 0,
					colour3 = 0,
					colour4 = 0,
					true;
			}
			// Get a random number in the given range.
			end = random(end - start) + start,
			colour1 = FIXES_gscVehiclePrimary[end],
			colour2 = FIXES_gscVehicleSecondary[end];

			// Three vehicles have four colours, not two.
			switch (modelid)
			{
			case 83:
			{
				colour3 = FIXES_gscColour3Camper{end},
				colour4 = FIXES_gscColour4Camper{end};
			}
			case 124:
			{
				colour3 = FIXES_gscColour3Cement{end},
				colour4 = FIXES_gscColour4Cement{end};
			}
			case 46:
			{
				colour3 = FIXES_gscColour3Squalo{end},
				colour4 = FIXES_gscColour4Squalo{end};
			}
			default:
			{
				colour3 = 0,
				colour4 = 0;
			}
			}

			// This vehicle was valid.
			return true;
		}
		return false;
	}
#endif

/*

    88888888888  88                                     
    88           ""                                     
    88                                                  
    88aaaaa      88  8b,     ,d8  ,adPPYba,  ,adPPYba,  
    88"""""      88   `Y8, ,8P'  a8P_____88  I8[    ""  
    88           88     )888(    8PP"""""""   `"Y8ba,   
    88           88   ,d8" "8b,  "8b,   ,aa  aa    ]8I  
    88           88  8P'     `Y8  `"Ybbd8"'  `"YbbdP"'  



*/

/**
 * <fixes>IsPlayerConnected</fixes>
 */

#if _FIXES_SAMP && defined _ALS_IsPlayerConnected
	#error _ALS_IsPlayerConnected defined
#endif
native BAD_IsPlayerConnected(playerid) = IsPlayerConnected;

/**
 * <fixes>IsPlayerConnected</fixes>
 */

#if FIX_IsPlayerConnected
	stock FIXES_IsPlayerConnected(playerid)
	{
		return _FIXES_IS_PLAYER_CONNECTED(playerid);
	}

	#if _FIXES_SAMP
		#define _ALS_IsPlayerConnected
		#define IsPlayerConnected( FIXES_IsPlayerConnected(
	#endif

	#define _ALS_IsPlayerConnected__
	#define IsPlayerConnected__( FIXES_IsPlayerConnected(
#endif

/**
 * <remarks>
 * Set "IS_JIT" to true.
 * </remarks>
 * <fixes>IS_JIT</fixes>
 */

forward OnJITCompile();

public OnJITCompile()
{
	state _ALS : _ALS_go;
	_FIXES_gIsJIT = true;
	_FIXES_DetermineOS();

	return FIXES_OnJITCompile();
}

#if defined _ALS_OnJITCompile
	#error _ALS_OnJITCompile defined
#endif
#define _ALS_OnJITCompile
#define OnJITCompile(%0) FIXES_OnJITCompile(%0) <_ALS : _ALS_go>

_FIXES_FORWARD FIXES_OnJITCompile();

/**
 * <remarks>
 * Set <symbolref name="IS_FILTERSCRIPT" /> to true as this callback is ONLY called if this script
 * is actually a FilterScript.  Then call <symbolref name="FIXES_OnScriptInit" />.
 * </remarks>
 * <fixes>IS_FILTERSCRIPT</fixes>
 * <fixes>OnPlayerConnect</fixes>
 * <fixes>GameText</fixes>
 */

public OnFilterScriptInit()
{
	// It is possible for this to be the only thing done in this function!
	state _ALS : _ALS_go;
	_FIXES_gIsFilterscript = true;
	_FIXES_DetermineOS();
	_FIXES_CheckServerRoot();
	#if FIXES_Single && FIXES_SingleMsg
		// Check this really IS the only script running.
		if (existproperty(5, FIXES_gscSingleProperty))
		{
			print(FIXES_gscMultiScriptError);
		}
		else
		{
			FIXES_gsSettings &= ~e_FIXES_SETTINGS_SECOND_USE,
			setproperty(5, FIXES_gscSingleProperty, 1);
		}
	#endif

	// ======================
	//  BEGIN: GetMaxPlayers
	// ======================
	#if FIX_GetMaxPlayers
		_FIXES_CheckMaxPlayers();
	#endif
	// ======================
	//  END:   GetMaxPlayers
	// ======================

	// =================
	//  BEGIN: GameText
	// =================
	#if FIX_GameText
		for (new i = 0; i != sizeof (FIXES_gsPlayerPGTShown); ++i)
		{
			FIXES_gsPlayerPGTShown[i][MAX_PLAYERS] = MAX_PLAYERS;
		}
	#endif
	#if FIXES_Single
		#if FIX_GameText
			_FIXES_CreateGameTextDraws(INVALID_PLAYER_ID);
		#endif
		// =================
		//  END:   GameText
		// =================
	#else
		FIXES_DetermineOrder(),
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_DROP_ALL_DATA;
	#endif

	#if !FIXES_Single && FIX_GameText && FIX_OnPlayerConnect
		FIXES_gsSettings |= e_FIXES_SETTINGS_NO_GAME_TEXT;
	#endif
	// These are all the fixes that use "_FIXES_FOREACH".
	#if FIX_OnPlayerConnect || _FIX_Menus || FIX_GetPlayerMenu || FIX_OnPlayerDisconnect || FIX_GameText || FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable
		for (new playerid = 0; playerid != MAX_PLAYERS; ++playerid)
		{
			if (BAD_IsPlayerConnected(playerid))
			{
				// No "defined" checks - if you don't want this fix because
				// you don't have an "OnPlayerConnect", just don't use it!
				// Of course, it helps that the copy of "OnPlayerConnect"
				// in this include is almost always called!
				#if FIX_OnPlayerConnect
					// ========================
					//  BEGIN: OnPlayerConnect
					// ========================
					OnPlayerConnect(playerid);
					// ========================
					//  END:   OnPlayerConnect
					// ========================
				#else
					_FIXES_AddInternal(FIXES_gsPlayersIterator, playerid, MAX_PLAYERS);

					#if FIX_GameText
						// =================
						//  BEGIN: GameText
						// =================
						_FIXES_IS_IN_CHARGE()
						{
							_FIXES_CreateGameTextDraws(playerid);
						}
						// =================
						//  END:   GameText
						// =================
					#endif
				#endif
			}
		}
	#endif
	#if !FIXES_Single && FIX_GameText && FIX_OnPlayerConnect
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_NO_GAME_TEXT;
	#endif

	return FIXES_OnFilterScriptInit();
}

#if defined _ALS_OnFilterScriptInit
	#error _ALS_OnFilterScriptInit defined
#endif
#define _ALS_OnFilterScriptInit
#define OnFilterScriptInit(%0) FIXES_OnFilterScriptInit(%0) <_ALS : _ALS_go>

_FIXES_FORWARD FIXES_OnFilterScriptInit();

/**
 * <remarks>
 * Call <symbolref name="FIXES_OnScriptInit" /> if this is not a FilterScript.
 * </remarks>
 * <fixes>IS_FILTERSCRIPT</fixes>
 * <fixes>AllowInteriorWeapons</fixes>
 * <fixes>AllowTeleport</fixes>
 */

public OnGameModeInit()
{
	state _ALS : _ALS_go;
	_FIXES_DetermineOS();

	#if FIXES_Single && FIXES_SingleMsg
		// Check this really IS the only script running.  Properties reset when
		// a gamemode restarts, so we don't have to worry about filterscipts
		// detecting themselves.
		if (FIXES_gsSettings & e_FIXES_SETTINGS_SECOND_USE)
		{
			if (existproperty(5, FIXES_gscSingleProperty))
			{
				print(FIXES_gscMultiScriptError);
			}
			else
			{
				setproperty(5, FIXES_gscSingleProperty, 1);
			}
		}
		else
		{
			// When the server starts, we need to allow an FS to load with a GM
			// that doesn't use fixes.inc.  This is the only case where a
			// property can be set while a ganemode isn't running.  This will
			// mean that the FS won't complain if they are both using fixes, but
			// the GM still will, so all is good.
			FIXES_gsSettings |= e_FIXES_SETTINGS_SECOND_USE;
		}
	#endif

	// =============================
	//  BEGIN: AllowInteriorWeapons
	// =============================
	// ======================
	//  BEGIN: AllowTeleport
	// ======================
	#if FIX_AllowInteriorWeapons && FIX_AllowTeleport && !defined FILTERSCRIPT
		FIXES_gsSettings &= ~(e_FIXES_SETTINGS_INTERIOR | e_FIXES_SETTINGS_ADMIN_TELEPORT);
	#elseif FIX_AllowInteriorWeapons
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_INTERIOR;
	#elseif FIX_AllowTeleport && !defined FILTERSCRIPT
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_ADMIN_TELEPORT;
	#endif
	// ======================
	//  END:   AllowTeleport
	// ======================
	// ===========================
	//  END: AllowInteriorWeapons
	// ===========================
	if (!_FIXES_gIsFilterscript)
	{
		_FIXES_CheckServerRoot();

		// ======================
		//  BEGIN: GetMaxPlayers
		// ======================
		#if FIX_GetMaxPlayers
			_FIXES_CheckMaxPlayers();
		#endif
		// ======================
		//  END:   GetMaxPlayers
		// ======================

		// =================
		//  BEGIN: GameText
		// =================
		#if FIX_GameText
				for (new i = 0; i != sizeof (FIXES_gsPlayerPGTShown); ++i)
				{
					FIXES_gsPlayerPGTShown[i][MAX_PLAYERS] = MAX_PLAYERS;
				}
			#if FIXES_Single
				_FIXES_CreateGameTextDraws(INVALID_PLAYER_ID);
			#endif
		#endif
		// =================
		//  END:   GameText
		// =================
		#if !FIXES_Single
			FIXES_DetermineOrder();
		#endif
		// ======================
		//  BEGIN: OnRconCommand
		// ======================
		#if FIX_OnRconCommand || FIX_OnClientCheckResponse
			// First, test if the fix has already been loaded.
			setproperty(27, FIXES_gscOnClientCheckResponse, 0),
			SendRconCommand(FIXES_gscOnClientCheckResponse);
			if (getproperty(27, FIXES_gscOnClientCheckResponse) != 27)
			{
				if (!fexist(FIXES_gscRconFixFS))
				{
					/*
						// Minimise code size.
						#pragma option -d0
						#pragma option -O1

						// Declare some natives for use.
						native CallRemoteFunction(const function[], const format[], ...);
						native setproperty(id = 0, const name[] = "", value = cellmin, const string[] = "");
						native strcmp(const string1[], const string2[], bool:ignorecase = false, length = cellmax);

						// Use the same string for everything, so we only need one.  And pack it.
						new const FIXES_OnClientCheckResponse[] = !"FIXES_OnClientCheckResponse";

						forward OnRconCommand(const cmd[]);

						// This callback just needs to exist in one filterscript.
						public OnRconCommand(const cmd[])
						{
							// The smallest I could make the assembly without `#emit`.
							if (strcmp(cmd, FIXES_OnClientCheckResponse, true) == 0)
							{
								// Add 2 cells of padding here to make the AMX a nice size.
								return !setproperty(27, FIXES_OnClientCheckResponse, 27, "\0\0");
							}
							return 0;
						}

						forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

						// This callback needs to invoke a different callback in GMs.
						public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
						{
							// Invoke the global callback.
							return CallRemoteFunction(FIXES_OnClientCheckResponse, !"iiii", playerid, actionid, memaddr, retndata);
						}
					*/
					static
						lRCFixCode[] = {
							0x00000120, 0x0808F1E0, 0x00080014, 0x000000AC, 0x00000190, 0x000001C0, 0x000041C0, 0xFFFFFFFF,
							0x00000038, 0x00000048, 0x00000060, 0x00000060, 0x00000060, 0x00000060, 0x00000094, 0x00000062,
							0x00000008, 0x00000078, 0x00000000, 0x00000086, 0x00000000, 0x0000008D, 0x00000000, 0x00000099,
							0x6E4F001F, 0x65696C43, 0x6843746E, 0x526B6365, 0x6F707365, 0x0065736E, 0x63526E4F, 0x6F436E6F,
							0x6E616D6D, 0x74730064, 0x706D6372, 0x74657300, 0x706F7270, 0x79747265, 0x6C614300, 0x6D65526C,
							0x4665746F, 0x74636E75, 0x006E6F69, 0x2E007880, 0xFFFF8727, 0x01277FFF, 0x0C290027, 0x7B801027,
							0x36142C00, 0x1C270C81, 0x00271B27, 0x10271B27, 0x2C017B80, 0x30548014, 0x2E305980, 0x81180581,
							0x05811405, 0x0C058110, 0x00272827, 0x7B801827, 0x301C2C02, 0xB0A5B284, 0xFD9A8545, 0x9B846E9E,
							0x8665D2B1, 0x6886D1F3, 0xD68DAB86, 0xCDAB8652, 0xF3866FE0, 0x0000CACD, 0xCB860000, 0x0069D2A5
						};
					new
						File:fs = fopen(FIXES_gscRconFixFS, io_write);
					if (fs)
					{
						fblockwrite(fs, lRCFixCode);
						fclose(fs);
					}
				}
				if (fexist(FIXES_gscRconFixFS))
				{
					SendRconCommand__("loadfs ../scriptfiles/callbackfix");
					#if FIX_OnClientCheckResponse
						state OnClientCheckResponse : OnClientCheckResponse_GM;
					#endif
				}
				else
				{
					print("\7\7\7\7\7*** fixes.inc warning: Could not load RconCommand/ClientCheckResponse fix FS."),
					print(          "***                    Ignore this error if the FS already loaded.");
				}
			}
		#endif
		// ======================
		//  END:   OnRconCommand
		// ======================
	}
	#if !FIXES_Single
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_DROP_ALL_DATA;
	#endif
	return FIXES_OnGameModeInit();
}

#if defined _ALS_OnGameModeInit
	#error _ALS_OnGameModeInit defined
#endif
#define _ALS_OnGameModeInit
#define OnGameModeInit(%0) FIXES_OnGameModeInit(%0) <_ALS : _ALS_go>

_FIXES_FORWARD FIXES_OnGameModeInit();

/**
 * <remarks>
 * Allow <c>OnClientCheckResponse</c> to be called in gamemodes.
 * </remarks>
 * <fixes>OnClientCheckResponse</fixes>
 */

#if FIX_OnClientCheckResponse
	forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);
	public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
	{
		// Enable, then disable, the call in to the real version (if it exists).
		state OnClientCheckResponse : OnClientCheckResponse_GM;
		new
			ret = FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
		state OnClientCheckResponse : OnClientCheckResponse_FS;
		return ret;
	}

	forward FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
	public FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata) <OnClientCheckResponse : OnClientCheckResponse_FS>
	{
		return 0;
	}

	public FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata) <>
	{
		return 0;
	}

	static stock _FIXES_OnClientCheckResponse() <OnClientCheckResponse : OnClientCheckResponse_GM, OnClientCheckResponse : OnClientCheckResponse_FS>
	{
		// Define states only.
	}

	#if defined _ALS_OnClientCheckResponse
		#error _ALS_OnClientCheckResponse defined
	#endif
	#define _ALS_OnClientCheckResponse
	#define OnClientCheckResponse(%0) FIXES_OnClientCheckResponse(%0) <OnClientCheckResponse : OnClientCheckResponse_GM>
#endif

/**
 * <remarks>
 * Fast way of detecting not to retain any data.
 * </remarks>
 */

#if !FIXES_Single || FIX_PlayerDialogResponse
	public OnGameModeExit()
	{
		#if !FIXES_Single
			FIXES_gsSettings |= e_FIXES_SETTINGS_DROP_ALL_DATA;
			if (!_FIXES_gIsFilterscript && FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE)
			{
				FIXES_gsSettings |= e_FIXES_SETTINGS_ENDING,
				FIXES_DetermineOrder();
			}
		#endif

		// =============================
		//  BEGIN: PlayerDialogResponse
		// =============================
		#if FIX_PlayerDialogResponse
			for (new playerid = 0; playerid != MAX_PLAYERS; ++playerid)
			{
				ShowPlayerDialog__(playerid, -1, 0, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace);
			}
		#endif
		// =============================
		//  END:   PlayerDialogResponse
		// =============================

		return FIXES_OnGameModeExit();
	}

	#if defined _ALS_OnGameModeExit
		#error _ALS_OnGameModeExit defined
	#endif
	#define _ALS_OnGameModeExit
	#define OnGameModeExit(%0) FIXES_OnGameModeExit(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnGameModeExit();
#endif

/**
 * <remarks>
 * Fast way of detecting not to retain any data.
 * </remarks>
 */

#if !FIXES_Single || FIX_GameText || FIX_OnPlayerDisconnect
	public OnFilterScriptExit()
	{
		#if FIX_OnPlayerDisconnect
			// Removal safe loop.
			for (new next, playerid = FIXES_gsPlayersIterator[MAX_PLAYERS]; playerid != MAX_PLAYERS; playerid = next)
			{
				next = FIXES_gsPlayersIterator[playerid],
				OnPlayerDisconnect(playerid, 4);
				#if FIXES_Single
					// =================
					//  BEGIN: GameText
					// =================
					#if FIX_GameText
						#if FIX_GameTextStyles
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][0]);
					#endif
				#endif
			}
		#endif
		#if FIXES_Single
			// =================
			//  BEGIN: GameText
			// =================
			#if FIX_GameText
				#if defined FIXES_OnFilterScriptExit
					FIXES_OnFilterScriptExit();
				#endif
				#if !FIX_OnPlayerDisconnect
					_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
					{
						#if FIX_GameTextStyles
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][0]);
					}
				#endif
					return
						#if FIX_GameTextStyles
							TextDrawDestroy__(FIXES_gsGTStyle[13]),
							TextDrawDestroy__(FIXES_gsGTStyle[12]),
							TextDrawDestroy__(FIXES_gsGTStyle[11]),
							TextDrawDestroy__(FIXES_gsGTStyle[10]),
							TextDrawDestroy__(FIXES_gsGTStyle[9]),
							TextDrawDestroy__(FIXES_gsGTStyle[8]),
							TextDrawDestroy__(FIXES_gsGTStyle[7]),
						#endif
							TextDrawDestroy__(FIXES_gsGTStyle[6]),
							TextDrawDestroy__(FIXES_gsGTStyle[5]),
							TextDrawDestroy__(FIXES_gsGTStyle[4]),
							TextDrawDestroy__(FIXES_gsGTStyle[3]),
							TextDrawDestroy__(FIXES_gsGTStyle[2]),
							TextDrawDestroy__(FIXES_gsGTStyle[1]),
							TextDrawDestroy__(FIXES_gsGTStyle[0]);
			#else
					return FIXES_OnFilterScriptExit();
			#endif
			// =================
			//  END:   GameText
			// =================
		#else
			if (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE)
			{
				FIXES_gsSettings |= e_FIXES_SETTINGS_ENDING,
				FIXES_DetermineOrder();
			}
			return FIXES_OnFilterScriptExit();
		#endif
	}

	#if defined _ALS_OnFilterScriptExit
		#error _ALS_OnFilterScriptExit defined
	#endif
	#define _ALS_OnFilterScriptExit
	#define OnFilterScriptExit(%0) FIXES_OnFilterScriptExit(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnFilterScriptExit();
#endif

/**
 * <remarks>
 * Almost every fix uses this callback for initialisation.  It is only
 * explicitly referenced for those fixes where this is all the code.  The
 * inclusion code was approaching the 512 line length limit, so I shrank it.
 * </remarks>
 * <fixes>TogglePlayerControllable</fixes>
 * <fixes>SetPlayerWorldBounds</fixes>
 * <fixes>GetPlayerColor</fixes>
 * <fixes>SetPlayerName</fixes>
 * <fixes>GetPlayerSkin</fixes>
 * <fixes>IsPlayerInCheckpoint</fixes>
 * <fixes>IsPlayerInRaceCheckpoint</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>PutPlayerInVehicle</fixes>
 * <fixes>OnPlayerEnterVehicle</fixes>
 * <fixes>AllowTeleport</fixes>
 * <fixes>OnDialogResponse</fixes>
 * <fixes>SetSpawnInfo</fixes>
 * <fixes>AllowInteriorWeapons</fixes>
 * <fixes>TrainExit</fixes>
 * <fixes>Kick</fixes>
 * <fixes>OnPlayerEnterVehicle_2</fixes>
 * <fixes>PlayerDialogResponse</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 */

#if     FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_SetPlayerName            || FIX_GetPlayerColour
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_GetPlayerSkin        || FIX_IsPlayerInCheckpoint     || FIX_IsPlayerInRaceCheckpoint || FIX_GetPlayerWeapon
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_PutPlayerInVehicle   || FIX_OnPlayerEnterVehicle     || FIX_AllowTeleport            || FIX_OnDialogResponse
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_GetPlayerDialog      || FIX_SetSpawnInfo             || FIX_AllowInteriorWeapons     || FIX_TrainExit
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_Kick                 || FIX_OnPlayerEnterVehicle_2   || FIX_PlayerDialogResponse     || FIX_GetPlayerInterior
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_OnPlayerSpawn        || FIX_ApplyAnimation_2         || FIX_GameText                 || _FIX_Menus
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_GetPlayerMenu        || FIX_OnPlayerDisconnect       || FIX_OnPlayerConnect          || FIX_SetPlayerTime
	#define _FIXES_ON_PLAYER_CONNECT
#elseif FIX_SetPlayerColour      || FIX_GetPlayerWorldBounds
	#define _FIXES_ON_PLAYER_CONNECT
#endif

#if defined _FIXES_ON_PLAYER_CONNECT
	public OnPlayerConnect(playerid)
	{
		// ==================================
		//  BEGIN: ApplyAnimation_2
		// ==================================
		#if FIX_ApplyAnimation_2
			FIXES_gsPlayerAnimLibs[playerid][0] =
				FIXES_gsPlayerAnimLibs[playerid][1] =
					FIXES_gsPlayerAnimLibs[playerid][2] =
						FIXES_gsPlayerAnimLibs[playerid][3] =
							FIXES_gsPlayerAnimLibs[playerid][4] = -1;
		#endif
		// ================================
		//  END: ApplyAnimation_2
		// ================================

		#if _FIX_Menus || FIX_GetPlayerMenu || FIX_OnPlayerDisconnect || FIX_GameText || FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable
			_FIXES_AddInternal(FIXES_gsPlayersIterator, playerid, MAX_PLAYERS);
		#endif

		FIXES_PRINTF("FIXES_OnPlayerConnect: %d", playerid);
			// This is only reset when the Game Mode changes or when a new
		#if FIX_Kick || FIX_TogglePlayerControllable || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_AllowTeleport || FIX_AllowInteriorWeapons || FIX_TrainExit || FIX_OnPlayerEnterVehicle_2 || FIX_SetPlayerColour
			// player connects, which is what we want.  The other items are the
			// same, but must be done only once.  This variable will tend to
			// hold data relevant only in the master script (the first
			// filterscript).
			#if FIX_Kick || FIX_SetPlayerTime || FIX_SetPlayerColour
				FIXES_gsPlayerBools[playerid] = e_FIXES_BOOLS_ON_PLAYER_CONNECT;
			#else
				FIXES_gsPlayerBools[playerid] = e_FIXES_BOOLS_NONE;
			#endif
		#endif

		// =================
		//  BEGIN: GameText
		// =================
		#if FIX_GameText
			#if !FIXES_Single
				if (FIXES_gsSettings & (e_FIXES_SETTINGS_NO_GAME_TEXT | e_FIXES_SETTINGS_IN_CHARGE) == e_FIXES_SETTINGS_IN_CHARGE)
			#endif
				{
					_FIXES_CreateGameTextDraws(playerid);
				}
		#endif
		// =================
		//  END:   GameText
		// =================

		#if !FIXES_Single
			if (!GetPVarInt__(playerid, FIXES_pvarNotNewPlayer))
		#endif
			{
				FIXES_PRINTF("FIXES_OnPlayerConnect: First (%d)", FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE);
				// ======================
				//  BEGIN: SetPlayerName
				// ======================
				#if FIX_SetPlayerName
					new
						name[MAX_PLAYER_NAME + 1];
					GetPlayerName__(playerid, name, MAX_PLAYER_NAME + 1);
					if (strcmp(name, FIXES_gscTempName) == 0)
					{
						Kick__(playerid);
					}
				#endif
				// ======================
				//  END:   SetPlayerName
				// ======================

				// =============================
				//  BEGIN: SetPlayerWorldBounds
				// =============================
				#if FIX_SetPlayerWorldBounds || FIX_GetPlayerWorldBounds
					FIXES_gsWorldbounds_UX[playerid] = FIXES_gsWorldbounds_UY[playerid] = _FIXES_MAX_WORLDBOUNDS,
					FIXES_gsWorldbounds_LX[playerid] = FIXES_gsWorldbounds_LY[playerid] = _FIXES_MIN_WORLDBOUNDS;
				#endif
				// =============================
				//  END:   SetPlayerWorldBounds
				// =============================

				// =======================
				//  BEGIN: GetPlayerColor
				// =======================
				#if FIX_GetPlayerColour
					SetPlayerColor__(playerid, FIXES_gscPlayerColours[playerid % sizeof (FIXES_gscPlayerColours)]);
				#endif
				// =======================
				//  END:   GetPlayerColor
				// =======================

				// ======================
				//  BEGIN: GetPlayerSkin
				// ======================
				#if FIX_GetPlayerSkin
					FIXES_SET(PlayerSkin, playerid, 0);
				#endif
				// ======================
				//  END:   GetPlayerSkin
				// ======================

				// =============================
				//  BEGIN: IsPlayerInCheckpoint
				// =============================
				#if FIX_IsPlayerInCheckpoint
					DisablePlayerCheckpoint__(playerid);
				#endif
				// =============================
				//  END:   IsPlayerInCheckpoint
				// =============================

				// =================================
				//  BEGIN: IsPlayerInRaceCheckpoint
				// =================================
				#if FIX_IsPlayerInRaceCheckpoint
					DisablePlayerRaceCheckpoint__(playerid);
				#endif
				// =================================
				//  END:   IsPlayerInRaceCheckpoint
				// =================================

				// ========================
				//  BEGIN: GetPlayerWeapon
				// ========================
				#if FIX_GetPlayerWeapon
					FIXES_SET(PlayerWeapon, playerid, -1);
				#endif
				// ========================
				//  END:   GetPlayerWeapon
				// ========================

				// ==========================
				//  BEGIN: GetPlayerInterior
				// ==========================
				#if FIX_GetPlayerInterior
					FIXES_SET(PlayerInterior, playerid, 0);
				#endif
				// ==========================
				//  END:   GetPlayerInterior
				// ==========================

				// =========================
				//  BEGIN: OnDialogResponse
				// =========================
				#if FIX_OnDialogResponse || FIX_GetPlayerDialog
					FIXES_SET(PlayerDialog, playerid, INVALID_DIALOG_ID);
				#endif
				// =========================
				//  END:   OnDialogResponse
				// =========================

				// =============================
				//  BEGIN: PlayerDialogResponse
				// =============================
				#if FIX_PlayerDialogResponse
					ShowPlayerDialog__(playerid, -1, 0, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace);
				#endif
				// =============================
				//  END:   PlayerDialogResponse
				// =============================

				// =====================
				//  BEGIN: SetSpawnInfo
				// =====================
				#if FIX_SetSpawnInfo
					SetSpawnInfo__(playerid, NO_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
				#endif
				// =====================
				//  END:   SetSpawnInfo
				// =====================

				// ======================
				//  BEGIN: OnPlayerSpawn
				// ======================
				#if FIX_OnPlayerSpawn
					FIXES_SET(PlayerLastCash, playerid, 0);
				#endif
				// ======================
				//  END:   OnPlayerSpawn
				// ======================

				// =========================
				//  BEGIN: GetPlayerWeather
				// =========================
				#if FIX_GetPlayerWeather
					FIXES_SET(PlayerWeather, playerid, FIXES_gsServerWeather);
				#endif
				// =========================
				//  END:   GetPlayerWeather
				// =========================

				#if !FIXES_Single
					// No longer their first time.
					SetPVarInt__(playerid, FIXES_pvarNotNewPlayer, 1);
				#endif
			}
		// =============
		//  BEGIN: Kick
		// =============
		#if FIX_Kick || FIX_SetPlayerTime || FIX_SetPlayerColour
			new
				ret = FIXES_OnPlayerConnect(playerid);
			FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_ON_PLAYER_CONNECT;
			return ret;
		#else
			return FIXES_OnPlayerConnect(playerid);
		#endif
		// =============
		//  END:   Kick
		// =============
	}

	#if defined _ALS_OnPlayerConnect
		#error _ALS_OnPlayerConnect defined
	#endif
	#define _ALS_OnPlayerConnect
	#define OnPlayerConnect(%0) FIXES_OnPlayerConnect(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerConnect(playerid);
#endif

/**
 * <fixes>SetPlayerAttachedObject</fixes>
 * <fixes>IsPlayerAttachedObjectSlotUsed</fixes>
 * <fixes>Kick</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_Kick || FIX_SilentTeleport || (FIXES_SilentKick && (FIX_OnVehicleMod || FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2)) || FIX_OnPlayerEnterVehicle_3 || FIX_GetPlayerMenu || _FIX_Menus || FIX_OnPlayerDisconnect || FIX_GameText || FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable || FIX_ApplyAnimation_2
	public OnPlayerDisconnect(playerid, reason)
	{
		new
			ret = FIXES_OnPlayerDisconnect(playerid, reason);

		// =========================
		// BEGIN: SilentTeleport
		// =========================
		#if FIX_SilentTeleport
			FIXES_gsJackedId[playerid] = INVALID_PLAYER_ID;
		#endif
		// =========================
		// END: SilentTeleport
		// =========================

		// =========================
		//  BEGIN: ApplyAnimation_2
		// =========================
		#if FIX_ApplyAnimation_2
			if (FIXES_gsPlayerAnimTimer[playerid])
			{
				KillTimer__(FIXES_gsPlayerAnimTimer[playerid]),
				FIXES_gsPlayerAnimTimer[playerid] = 0;
			}
		#endif
		// =======================
		//  END: ApplyAnimation_2
		// =======================

		// ======================
		//  BEGIN: GetPlayerMenu
		// ======================
		#if FIX_GetPlayerMenu
			FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
		#endif
		// ======================
		//  END:   GetPlayerMenu
		// ======================

		// ==========================
		//  BEGIN: FIXES_SilentKick
		// ==========================
		#if FIXES_SilentKick && (FIX_OnVehicleMod || FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2)
			new
				shift = FIXES_gsPlayerIP[playerid];
			if (~shift) // != -1
			{
				// Unban the IP (timed out).
				new
					ip[16];
				format(ip, sizeof (ip), "unbanip %d.%d.%d.%d", shift >>> 24, (shift >>> 16) & 0xFF, (shift >>> 8) & 0xFF, shift & 0xFF),
				FIXES_gsPlayerIP[playerid] = -1;
			}
		#endif
		// ==========================
		//  END:   FIXES_SilentKick
		// ==========================

		// ================================
		//  BEGIN: SetPlayerAttachedObject
		// ================================
		#if FIX_SetPlayerAttachedObject
			for (new i = 0; i != MAX_PLAYER_ATTACHED_OBJECTS; ++i)
			{
				if (IsPlayerAttachedSlotUsed__(playerid, i))
				{
					RemovePlayerAttachedObject__(playerid, i);
				}
			}
		#endif
		// ================================
		//  END:   SetPlayerAttachedObject
		// ================================

		// =============
		//  BEGIN: Kick
		// =============
		#if FIX_Kick
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_KICKED)
			{
				// Stop the timer if it is still running.
				KillTimer__(GetPVarInt__(playerid, FIXES_pvarKick));
			}
		#endif
		// =============
		//  END:   Kick
		// =============

		// ===============================
		//  BEGIN: OnPlayerEnterVehicle_3
		// ===============================
		#if FIX_OnPlayerEnterVehicle_3
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_VEH_ENTER)
			{
				_FIXES_StopPlayerEnterVehicle(playerid);
			}
		#endif
		// ===============================
		//  END:   OnPlayerEnterVehicle_3
		// ===============================

		#if _FIX_Menus || FIX_GetPlayerMenu || FIX_OnPlayerDisconnect || FIX_GameText || FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable
			_FIXES_RemoveInternal(FIXES_gsPlayersIterator, playerid, MAX_PLAYERS);
		#endif

		return ret;
	}

	#if defined _ALS_OnPlayerDisconnect
		#error _ALS_OnPlayerDisconnect defined
	#endif
	#define _ALS_OnPlayerDisconnect
	#define OnPlayerDisconnect(%0) FIXES_OnPlayerDisconnect(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerDisconnect(playerid, reason);
#endif

/**
 * <fixes>main</fixes>
 */

#if FIX_main
	main()
#else
	static stock _FIXES_main()
#endif
	{
		// Set the default return value.
		#emit ZERO.pri
		#if defined FIXES_main
			FIXES_main();
		#endif
		// Implicitly return the value of the previous call.  This means we can
		// call `main` and return it's return value, without requiring it to
		// have a `return` statement.  It might, but the most common uses don't.
		#emit RETN
		// Return 0, just in case.
		return 0;
	}

#if FIX_main
	#if defined _ALS_main
		#undef main
	#else
		#define _ALS_main
	#endif
	#if defined FIXES_main
		forward FIXES_main();
	#endif
	#define main( public FIXES_main(
#endif

/**
 * <fixes>OnPlayerDeath</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 */

#if FIX_OnPlayerDeath || FIX_OnPlayerSpawn || FIX_GameText
	public OnPlayerDeath(playerid, killerid, reason)
	{
		_FIXES_IS_IN_CHARGE()
		{
			// =================
			//  BEGIN: GameText
			// =================
			#if FIX_GameText
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_DIED_TO_SPAWN;
			#endif
			// =================
			//  END:   GameText
			// =================

			// ======================
			//  BEGIN: OnPlayerDeath
			// ======================
			#if FIX_OnPlayerDeath
				static
					sAnimlib[32],
					sAnimname[32];
				GetAnimationName__(FIXES_gsLastAnimation[playerid], sAnimlib, sizeof (sAnimlib), sAnimname, sizeof (sAnimname));
				if (strcmp(sAnimlib, "PED", true))
				{
					ClearAnimations__(playerid);
				}
			#endif
			// ======================
			//  END:   OnPlayerDeath
			// ======================
		}

		// ======================
		//  BEGIN: OnPlayerSpawn
		// ======================
		#if FIX_OnPlayerSpawn
			new
				ret = FIXES_OnPlayerDeath(playerid, killerid, reason);

			FIXES_SET(PlayerLastCash, playerid, GetPlayerMoney__(playerid));

			return ret;
		#else
			return FIXES_OnPlayerDeath(playerid, killerid, reason);
		#endif
		// ======================
		//  END:   OnPlayerSpawn
		// ======================
	}

	#if defined _ALS_OnPlayerDeath
		#error _ALS_OnPlayerDeath defined
	#endif
	#define _ALS_OnPlayerDeath
	#define OnPlayerDeath(%0) FIXES_OnPlayerDeath(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerDeath(playerid, killerid, reason);
#endif

/**
 * <fixes>SilentTeleport</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetVehiclePos
	#error _ALS_SetVehiclePos defined 
#endif 
native BAD_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) = SetVehiclePos; 

/**
 * <fixes>SilentTeleport</fixes>
 */

#if FIX_SilentTeleport
	stock FIXES_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
	{
		// Validity check to prevent array out of bounds.
		if (SetVehiclePos__(vehicleid, x, y, z))
		{
			_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
			{
				if (GetPlayerState__(i) == PLAYER_STATE_DRIVER && GetPlayerVehicleID__(i) == vehicleid)
				{
					if (FIXES_gsJackedId[i] != INVALID_PLAYER_ID)
					{
						ClearAnimations__(FIXES_gsJackedId[i]);
						break;
					}
				}
			}
			return 1;
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetVehiclePos
		#define SetVehiclePos( FIXES_SetVehiclePos(
	#endif

	#define _ALS_SetVehiclePos__
	#define SetVehiclePos__( FIXES_SetVehiclePos(
#endif

/**
 * <fixes>SpawnPlayer</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SpawnPlayer
	#error _ALS_SpawnPlayer defined
#endif
native BAD_SpawnPlayer(playerid) = SpawnPlayer;

/**
 * <fixes>SpawnPlayer</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 */

#if FIX_SpawnPlayer || FIX_OnPlayerSpawn
	stock FIXES_SpawnPlayer(playerid)
	{
		// ======================
		//  BEGIN: SpawnPlayer
		// ======================
		#if FIX_SpawnPlayer
			// Valid "playerid" check inside "GetPlayerVehicleID".
			new
				vid = GetPlayerVehicleID__(playerid);
			if (vid)
			{
				new
					Float:x,
					Float:y,
					Float:z;
				// Remove them without the animation.
				GetVehiclePos__(vid, x, y, z),
				SetPlayerPos__(playerid, x, y, z);
			}
		#endif
		// ======================
		//  END:   SpawnPlayer
		// ======================

		// ======================
		//  BEGIN: OnPlayerSpawn
		// ======================
		#if FIX_OnPlayerSpawn
			FIXES_SET(PlayerLastCash, playerid, GetPlayerMoney__(playerid));
		#endif
		// ======================
		//  END:   OnPlayerSpawn
		// ======================

		return SpawnPlayer__(playerid);
	}

	#if _FIXES_SAMP
		#define _ALS_SpawnPlayer
		#define SpawnPlayer( FIXES_SpawnPlayer(
	#endif

	#define _ALS_SpawnPlayer__
	#define SpawnPlayer__( FIXES_SpawnPlayer(
#endif

/**
 * <fixes>SetPlayerName</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerName
	#error _ALS_SetPlayerName defined
#endif
native BAD_SetPlayerName(playerid, const name[]) = SetPlayerName;

/**
 * <fixes>SetPlayerName</fixes>
 */

#if FIX_SetPlayerName
	stock FIXES_SetPlayerName(playerid, const name[])
	{
		if (_FIXES_NO_RANGE(strlen(name), 3, MAX_PLAYER_NAME + 1))
		{
			return 0;
		}
		static
			sOldName[MAX_PLAYER_NAME + 1];
		GetPlayerName__(playerid, sOldName, sizeof (sOldName));
		if (!strcmp(name, sOldName, true))
		{
			if (strcmp(name, sOldName, false))
			{
				SetPlayerName__(playerid, FIXES_gscTempName);
				if (SetPlayerName__(playerid, name) == -1)
				{
					SetPlayerName__(playerid, sOldName);
					return -1;
				}
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return SetPlayerName__(playerid, name);
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerName
		#define SetPlayerName( FIXES_SetPlayerName(
	#endif

	#define _ALS_SetPlayerName__
	#define SetPlayerName__( FIXES_SetPlayerName(
#endif

/**
 * <fixes>OnPlayerRequestClass</fixes>
 */

#if FIX_OnPlayerRequestClass || FIX_GameText
	public OnPlayerRequestClass(playerid, classid)
	{
		// =================
		//  BEGIN: GameText
		// =================
		#if FIX_GameText
			FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_DIED_TO_SPAWN;
		#endif
		// =================
		//  END:   GameText
		// =================

		// =============================
		//  BEGIN: OnPlayerRequestClass
		// =============================
		#if FIX_OnPlayerRequestClass
			new
				Float:x,
				Float:y,
				Float:z;
			GetPlayerPos__(playerid, x, y, z),
			RemoveBuildingForPlayer__(playerid, 1484, x, y, z, 10.0),
			RemoveBuildingForPlayer__(playerid, 1485, x, y, z, 10.0),
			RemoveBuildingForPlayer__(playerid, 1486, x, y, z, 10.0);
		#endif
		// ===========================
		//  END: OnPlayerRequestClass
		// ===========================
		return FIXES_OnPlayerRequestClass(playerid, classid);
	}

	#if defined _ALS_OnPlayerRequestClass
		#error _ALS_OnPlayerRequestClass defined
	#endif
	#define _ALS_OnPlayerRequestClass
	#define OnPlayerRequestClass(%0) FIXES_OnPlayerRequestClass(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerRequestClass(playerid, classid);
#endif

/**
 * <fixes>GetPlayerSkin</fixes>
 * <fixes>TogglePlayerControllable</fixes>
 * <fixes>GetPlayerInterior</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 * <fixes>GameText</fixes>
 * <fixes>SetSpawnInfo_2</fixes>
 */

#if FIX_GetPlayerSkin || FIX_SilentTeleport || FIX_TogglePlayerControllable || FIX_GetPlayerInterior || FIX_OnPlayerSpawn || FIX_GameText || FIX_SetSpawnInfo_2
	public OnPlayerSpawn(playerid)
	{
		_FIXES_IS_IN_CHARGE()
		{
			// ======================
			//  BEGIN: OnPlayerSpawn
			// ======================
			#if FIX_OnPlayerSpawn
				ResetPlayerMoney__(playerid);
				GivePlayerMoney__(playerid, FIXES_GET(PlayerLastCash, playerid));
				FIXES_SET(PlayerLastCash, playerid, 0);
			#endif
			// ======================
			//  END:   OnPlayerSpawn
			// ======================

			// ==========================
			//  BEGIN: GetPlayerInterior
			// ==========================
			#if FIX_GetPlayerInterior
				FIXES_SET(PlayerInterior, playerid, 0);
			#endif
			// ==========================
			//  END:   GetPlayerInterior
			// ==========================

			// =================
			//  BEGIN: GameText
			// =================
			#if FIX_GameText

				if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DIED_TO_SPAWN)
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_DIED_TO_SPAWN;
					#define _FIXES_PER_PLAYER_GT(%0) if (FIXES_gsPlayerPGTShown[%0][playerid] > playerid) PlayerTextDrawHide__(playerid, FIXES_gsPGTStyle[playerid][%0]), _FIXES_RemoveInternal(FIXES_gsPlayerPGTShown[%0], playerid, MAX_PLAYERS)

					// Per-player GTs.
					#if FIX_GameTextStyles
						_FIXES_PER_PLAYER_GT(13);
						_FIXES_PER_PLAYER_GT(12);
						_FIXES_PER_PLAYER_GT(11);
						_FIXES_PER_PLAYER_GT(10);
						_FIXES_PER_PLAYER_GT(9);
						_FIXES_PER_PLAYER_GT(8);
						_FIXES_PER_PLAYER_GT(7);
					#endif
						_FIXES_PER_PLAYER_GT(6);
						_FIXES_PER_PLAYER_GT(5);
						_FIXES_PER_PLAYER_GT(4);
						_FIXES_PER_PLAYER_GT(3);
						_FIXES_PER_PLAYER_GT(2);
						_FIXES_PER_PLAYER_GT(1);
						_FIXES_PER_PLAYER_GT(0);

					#undef _FIXES_PER_PLAYER_GT

					// Global GTs.
					#if FIX_GameTextStyles
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[13]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[12]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[11]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[10]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[9]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[8]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[7]);
					#endif
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[6]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[5]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[4]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[3]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[2]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[1]),
						TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[0]);
				}

			#endif
			// =================
			//  END:   GameText
			// =================

			// ======================
			//  BEGIN: GetPlayerSkin
			// ======================
			#if FIX_GetPlayerSkin
				FIXES_SET(PlayerSkin, playerid, GetPlayerSkin__(playerid));
			#endif
			// ======================
			//  END:   GetPlayerSkin
			// ======================

			// =======================
			//  BEGIN: SetSpawnInfo_2
			// =======================
			#if FIX_SetSpawnInfo_2
				SetPlayerTeam__(playerid, GetPlayerTeam__(playerid));
			#endif
			// =======================
			//  END:   SetSpawnInfo_2
			// =======================
		}

		// =================================
		//  BEGIN: TogglePlayerControllable
		// =================================
		#if FIX_TogglePlayerControllable
			FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_UNCONTROLLABLE;
		#endif
		// =================================
		//  END:   TogglePlayerControllable
		// =================================

		// =========================
		// BEGIN: SilentTeleport
		// =========================
		#if FIX_SilentTeleport
			FIXES_gsJackedId[playerid] = INVALID_PLAYER_ID;
		#endif
		// =========================
		// END: SilentTeleport
		// =========================

		return FIXES_OnPlayerSpawn(playerid);
	}

	#if defined _ALS_OnPlayerSpawn
		#error _ALS_OnPlayerSpawn defined
	#endif
	#define _ALS_OnPlayerSpawn
	#define OnPlayerSpawn(%0) FIXES_OnPlayerSpawn(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerSpawn(playerid);
#endif

/**
 * <fixes>OnVehicleMod</fixes>
 */

#if FIX_OnVehicleMod || FIX_GetVehicleComponentInSlot
	public OnVehicleMod(playerid, vehicleid, componentid)
	{
		#if !FIXES_Single
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
			{
				return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
			}
		#endif

		// ==================================
		//  BEGIN: GetVehicleComponentInSlot
		// ==================================
		#if FIX_GetVehicleComponentInSlot
			#if !FIXES_Single
				new componentstring[8];
			#endif
			switch (FIXES_GetVehicleComponentType(componentid))
			{
				#if FIXES_Single
					case CARMODTYPE_STEREO:
					{
						FIXES_gsStereo[vehicleid] = componentid;
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						FIXES_gsFrontBumper[vehicleid] = componentid;
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						FIXES_gsRearBumper[vehicleid] = componentid;
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						FIXES_gsFrontBullbar[vehicleid] = componentid;
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						FIXES_gsRearBullbar[vehicleid] = componentid;
					}
				#else 
					case CARMODTYPE_STEREO:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_STEREO + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_FRONT_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_REAR_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_FRONT_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_REAR_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
				#endif
			}
		#endif
		// ================================
		//  END: GetVehicleComponentInSlot
		// ================================

		// =====================
		//  BEGIN: OnVehicleMod
		// =====================
		#if FIX_OnVehicleMod
		new
			modelid = GetVehicleModel__(vehicleid);
		if (_FIXES_IN_RANGE(modelid, 400, 611 + 1))
		{
			if (_FIXES_IN_RANGE(componentid, 1000, 1191 + 1))
			{
				if (FIXES_gscVehicleMods[(modelid - 400) * 6 + (componentid - 1000 >>> 5)] & 1 << (componentid - 1000 & 0b00011111))
				{
					return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
				}
			}
			else if (componentid == 1192 || componentid == 1193)
			{
				if (modelid == 576)
				{
					// This save a whole cell off EVERY other vehicle!  This
					// is the ONLY vehicle with any mods over "6 * 32 + 999"
					// (1191), the highest value you can fit in 6 cells of a
					// bit array (minus 1000).
					return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
				}
			}
		}
		// Desync the player entirely.
		return FIXES_BlockUpdate(playerid);
		#else
			return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
		#endif
		// =====================
		//  END:   OnVehicleMod
		// =====================
	}

	#if defined _ALS_OnVehicleMod
		#error _ALS_OnVehicleMod defined
	#endif
	#define _ALS_OnVehicleMod
	#define OnVehicleMod(%0) FIXES_OnVehicleMod(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnVehicleMod(playerid, vehicleid, componentid);
#endif

/**
 * <fixes>GetPlayerSkin</fixes>
 * <fixes>SetPlayerSkin</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerSkin
	#error _ALS_SetPlayerSkin defined
#endif
native BAD_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;

/**
 * <fixes>GetPlayerSkin</fixes>
 * <fixes>SetPlayerSkin</fixes>
 */

#if FIX_GetPlayerSkin || FIX_SetPlayerSkin
	stock FIXES_SetPlayerSkin(playerid, skinid)
	{
		// ======================
		//  BEGIN: SetPlayerSkin
		// ======================
		#if FIX_SetPlayerSkin
			new
				vehicleid = GetPlayerVehicleID__(playerid);
			if (vehicleid)
			{
				new
					seat = GetPlayerVehicleSeat__(playerid);
				ClearAnimations__(playerid, 1);
				new
					ret = SetPlayerSkin__(playerid, skinid);
				PutPlayerInVehicle__(playerid, vehicleid, seat);

				// ===============================
				//  BEGIN: DriveBy
				// ===============================
				#if FIX_DriveBy
					_FIXES_HideDriveByWeapon(playerid);
				#endif
				// ======================
				//  END:   DriveBy
				// ======================

				// ======================
				//  BEGIN: GetPlayerSkin
				// ======================
				#if FIX_GetPlayerSkin
					FIXES_SET(PlayerSkin, playerid, skinid);
				#endif
				// ======================
				//  END:   GetPlayerSkin
				// ======================

				return ret;
			}

			// ======================
			//  BEGIN: GetPlayerSkin
			// ======================
			#if FIX_GetPlayerSkin
				else
			#endif
			// ======================
			//  END:   GetPlayerSkin
			// ======================
		#endif
		// ======================
		//  END:   SetPlayerSkin
		// ======================

		// ======================
		//  BEGIN: GetPlayerSkin
		// ======================
		#if FIX_GetPlayerSkin
			// Watch fot the "else" above if this code ever changes.
			FIXES_SET(PlayerSkin, playerid, skinid);
		#endif
		// ======================
		//  END:   GetPlayerSkin
		// ======================

		return SetPlayerSkin__(playerid, skinid);
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerSkin
		#define SetPlayerSkin( FIXES_SetPlayerSkin(
	#endif

	#define _ALS_SetPlayerSkin__
	#define SetPlayerSkin__( FIXES_SetPlayerSkin(
#endif

/**
 * <fixes>GetPlayerSkin</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerSkin
	#error _ALS_GetPlayerSkin defined
#endif
native BAD_GetPlayerSkin(playerid) = GetPlayerSkin;

/**
 * <fixes>GetPlayerSkin</fixes>
 */

#if FIX_GetPlayerSkin
	stock FIXES_GetPlayerSkin(playerid)
	{
		return FIXES_GET(PlayerSkin, playerid);
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerSkin
		#define GetPlayerSkin( FIXES_GetPlayerSkin(
	#endif

	#define _ALS_GetPlayerSkin__
	#define GetPlayerSkin__( FIXES_GetPlayerSkin(
#endif

/**
 * <fixes>GetWeaponName</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetWeaponName
	#error _ALS_GetWeaponName defined
#endif
native BAD_GetWeaponName(weaponid, weapon[], len) = GetWeaponName;

/**
 * <fixes>GetWeaponName</fixes>
 */

#if FIX_GetWeaponName
	stock FIXES_GetWeaponName(weaponid, weapon[], len)
	{
		switch (weaponid)
		{
			case 18:
			{
				return
					weapon[0] = 0,
					strcat(weapon, "Molotov Cocktail", len),
					1;
			}
			case 44:
			{
				return
					weapon[0] = 0,
					strcat(weapon, "Night Vision Goggles", len),
					1;
			}
			case 45:
			{
				return
					weapon[0] = 0,
					strcat(weapon, "Thermal Goggles", len),
					1;
			}
			default:
			{
				return GetWeaponName__(weaponid, weapon, len);
			}
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetWeaponName
		#define GetWeaponName( FIXES_GetWeaponName(
	#endif

	#define _ALS_GetWeaponName__
	#define GetWeaponName__( FIXES_GetWeaponName(
#endif

/**
 * <fixes>BypassDialog</fixes>
 */

#if FIX_BypassDialog
	public OnPlayerCommandText(playerid, cmdtext[])
	{
		// Just return 1, don't acknowldege anything!
		return
			_FIXES_IS_VALID_PLAYER(playerid) && (
				(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_BLOCK)
				|| FIXES_OnPlayerCommandText(playerid, cmdtext)
			);
	}

	#if defined _ALS_OnPlayerCommandText
		#error _ALS_OnPlayerCommandText defined
	#endif
	#define _ALS_OnPlayerCommandText
	#define OnPlayerCommandText(%0) FIXES_OnPlayerCommandText(%0) <_ALS : _ALS_go>

	forward FIXES_OnPlayerCommandText(playerid, cmdtext[]);
	public FIXES_OnPlayerCommandText(playerid, cmdtext[]) <_ALS : _ALS_x0, _ALS : _ALS_x1> { return 0; }
	public FIXES_OnPlayerCommandText(playerid, cmdtext[]) <> { return 0; }
#endif

/**
 * <fixes>BypassDialog</fixes>
 */

#if FIX_BypassDialog
	public OnPlayerText(playerid, text[])
	{
		// Just return 1, don't acknowldege anything!
		return
			_FIXES_IS_VALID_PLAYER(playerid) &&
			!(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_BLOCK) &&
			FIXES_OnPlayerText(playerid, text);
	}

	#if defined _ALS_OnPlayerText
		#error _ALS_OnPlayerText defined
	#endif
	#define _ALS_OnPlayerText
	#define OnPlayerText(%0) FIXES_OnPlayerText(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerText(playerid, text[]);
#endif

/**
 * <fixes>SetPlayerWorldBounds</fixes>
 * <fixes>TogglePlayerControllable</fixes>
 * <fixes>AllowInteriorWeapons</fixes>
 * <fixes>OnPlayerDeath</fixes>
 * <fixes>Kick</fixes>
 * <fixes>OnVehicleMod</fixes>
 * <fixes>OnPlayerEnterVehicle</fixes>
 * <fixes>OnPlayerEnterVehicle_2</fixes>
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 * <fixes>PassengerSeating</fixes>
 * <fixes>GogglesSync</fixes>
 * <fixes>BypassDialog</fixes>
 */

#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_AllowInteriorWeapons || FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2 || FIX_OnPlayerEnterVehicle_3 || FIX_OnPlayerDeath || FIX_Kick || FIX_OnVehicleMod || FIX_PassengerSeating || FIX_GogglesSync || FIX_BypassDialog
	public OnPlayerUpdate(playerid)
	{
		// =============================
		//  BEGIN: OnPlayerEnterVehicle
		// =============================
		#if FIX_OnPlayerEnterVehicle || FIX_Kick || FIX_OnVehicleMod || FIX_OnPlayerEnterVehicle_2 || FIX_BypassDialog
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_BLOCK)
			{
				return 0;
			}
		#endif
		// =============================
		//  END:   OnPlayerEnterVehicle
		// =============================

		// ===============================
		//  BEGIN: OnPlayerEnterVehicle_3
		// ===============================
		#if FIX_OnPlayerEnterVehicle_3
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_VEH_ENTER)
			{
				if (GetTickCount__() - FIXES_gsPlayerVehicleTickCount[playerid] >= 4000)
				{
					_FIXES_StopPlayerEnterVehicle(playerid);
				}
				else
				{
					if (1020 <= GetPlayerAnimationIndex__(playerid) <= 1021)
					{
						FIXES_gsPlayerBools[playerid] |= ~e_FIXES_BOOLS_VEH_ENTER_ANIM;
					}
					else if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_VEH_ENTER_ANIM)
					{
						_FIXES_StopPlayerEnterVehicle(playerid);
					}
				}
			}
		#endif
		// ===============================
		//  END:   OnPlayerEnterVehicle_3
		// ==============================

		#if !FIXES_Single
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
			{
				return FIXES_OnPlayerUpdate(playerid);
			}
		#endif

		#if FIX_AllowInteriorWeapons || FIX_TogglePlayerControllable
			new
				e_FIXES_BOOLS:pbools = FIXES_gsPlayerBools[playerid];
		#endif

		// =============================
		//  BEGIN: AllowInteriorWeapons
		// =============================
		#if FIX_AllowInteriorWeapons
			if (pbools & e_FIXES_BOOLS_INTERIOR)
			{
				SetPlayerArmedWeapon__(playerid, 0);
			}
		#endif
		// ============================
		//  END: AllowInteriorWeapons
		// ============================

		#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_GogglesSync
			new
				KEY:ud,
				KEY:lr,
				KEY:keys;
			GetPlayerKeys__(playerid, keys, ud, lr);
		#endif

		#if (FIX_SetPlayerWorldBounds || FIX_GogglesSync) && !FIX_TogglePlayerControllable
			#pragma unused ud, lr
		#endif

		// =============================
		//  BEGIN: SetPlayerWorldBounds
		// =============================
		#if FIX_SetPlayerWorldBounds
			if (keys & _FIXES_KEY_AIM)
			{
				new
					Float:x,
					Float:y,
					Float:z;
				GetPlayerPos__(playerid, x, y, z);
				if (FIXES_gsWorldbounds_LX[playerid] < x < FIXES_gsWorldbounds_UX[playerid] && FIXES_gsWorldbounds_LY[playerid] < y < FIXES_gsWorldbounds_UY[playerid])
				{
					FIXES_gsWorldbounds_PX[playerid] = x,
					FIXES_gsWorldbounds_PY[playerid] = y,
					FIXES_gsWorldbounds_PZ[playerid] = z;
				}
				else
				{
					SetPlayerPos__(playerid, FIXES_gsWorldbounds_PX[playerid], FIXES_gsWorldbounds_PY[playerid], FIXES_gsWorldbounds_PZ[playerid]);
				}
			}
		#endif
		// =============================
		//  END:   SetPlayerWorldBounds
		// =============================

		// ======================
		//  BEGIN: OnPlayerDeath
		// ======================
		#if FIX_OnPlayerDeath
			FIXES_gsLastAnimation[playerid] = GetPlayerAnimationIndex__(playerid);
		#endif
		// ======================
		//  END:   OnPlayerDeath
		// ======================

		// =================================
		//  BEGIN: TogglePlayerControllable
		// =================================
		#if FIX_TogglePlayerControllable
			// MUST come last.
			if (pbools & e_FIXES_BOOLS_UNCONTROLLABLE)
			{
				// Keys based sync blocking, modified based on a post by Slice:
				// http://forum.sa-mp.com/showpost.php?p=876854  Use "playerid"
				// here as it's a variable that already exists, but note that
				// after this point, you CANNOT use "playerid" as it has been
				// "clobbered" (and yes, that's the technical term).  This is
				// just to avoid "statement has no effect" warnings.  ALWAYS
				// return 0 in this case, regardless of what other callbacks
				// return.
				playerid = FIXES_OnPlayerUpdate(playerid);
				if (keys || ud || lr)
				{
					return 0;
				}
				else
				{
					return playerid;
				}
			}
		#endif
		// =================================
		//  END:   TogglePlayerControllable
		// =================================

		// =================================
		//  BEGIN: PassengerSeating
		// =================================
		#if FIX_PassengerSeating
			if (FIXES_gsPSTimer[playerid] != 0 && GetTickCount__() - FIXES_gsPSTimer[playerid] > 0)
			{
				if (GetPlayerSpecialAction__(playerid) == SPECIAL_ACTION_ENTER_VEHICLE)
				{
					#if !FIX_OnPlayerDeath
						new
							animation = GetPlayerAnimationIndex__(playerid);
					#else
						new
							animation = FIXES_gsLastAnimation[playerid];
					#endif

					if (_FIXES_NO_RANGE(animation, 1007, 1060 + 1) && _FIXES_NO_RANGE(animation, 225, 233 + 1))
					{
						ClearAnimations__(playerid, 1);
						FIXES_gsPSTimer[playerid] = 0;
					}
				}
				else
				{
					FIXES_gsPSTimer[playerid] = 0;
				}
			}
		#endif
		// =================================
		//  END:   PassengerSeating
		// =================================

		// =================================
		//  BEGIN: GogglesSync
		// =================================
		#if FIX_GogglesSync
			switch (GetPlayerWeapon__(playerid))
			{
				case _FIXES_WEAPON_NIGHT_VIS_GOGGLES, _FIXES_WEAPON_THERMAL_GOGGLES:
				{
					if ((keys & KEY_FIRE) && GetPlayerState__(playerid) == PLAYER_STATE_ONFOOT)
					{
						return 0;
					}
				}
			}
		#endif
		// =================================
		//  END:   GogglesSync
		// =================================

		return FIXES_OnPlayerUpdate(playerid);
	}

	#if defined _ALS_OnPlayerUpdate
		#error _ALS_OnPlayerUpdate defined
	#endif
	#define _ALS_OnPlayerUpdate
	#define OnPlayerUpdate(%0) FIXES_OnPlayerUpdate(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerUpdate(playerid);
#endif

/**
 * <remarks>
 * TODO: Modify this to remove aim animations when they get to the boundaries.
 * </remarks>
 * <fixes>SetPlayerWorldBounds</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerWorldBounds
	#error _ALS_SetPlayerWorldBounds defined
#endif
native BAD_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min) = SetPlayerWorldBounds;

/**
 * <remarks>
 * TODO: Modify this to remove aim animations when they get to the boundaries.
 * </remarks>
 * <fixes>SetPlayerWorldBounds</fixes>
 */

#if FIX_SetPlayerWorldBounds || FIX_GetPlayerWorldBounds
	#if FIXES_Single
		stock FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				FIXES_PRINTF("Call SetPlayerWorldBounds");
				if (x_max == x_min || y_max == y_min)
				{
					// Impossibly small area, disable checks entirely.
					return
						FIXES_gsWorldbounds_UX[playerid] = FIXES_gsWorldbounds_UY[playerid] = _FIXES_MAX_WORLDBOUNDS,
						FIXES_gsWorldbounds_LX[playerid] = FIXES_gsWorldbounds_LY[playerid] = _FIXES_MIN_WORLDBOUNDS,
						SetPlayerWorldBounds__(playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS);
				}
				// This code could do with a way to mostly remove the checks.  Maybe
				// when setting everything to FIXES_INFINITY (with default
				// parameters).
				new
					Float:tmp;
				if (x_max < x_min)
				{
					tmp = x_min,
					x_min = x_max,
					x_max = tmp;
				}
				if (y_max < y_min)
				{
					tmp = y_min,
					y_min = y_max,
					y_max = tmp;
				}
				// Give a little leway so this fix isn't noticed if you're not
				// trying to break through the world bounds.  Leway removed in
				// favour of keys.
				return
					FIXES_gsWorldbounds_LX[playerid] = x_min,
					FIXES_gsWorldbounds_UX[playerid] = x_max,

					FIXES_gsWorldbounds_LY[playerid] = y_min,
					FIXES_gsWorldbounds_UY[playerid] = y_max,

					GetPlayerPos__(playerid, tmp, tmp, tmp),
					FIXES_gsWorldbounds_PX[playerid] = (x_max - x_min) / 2 + x_min,
					FIXES_gsWorldbounds_PY[playerid] = (y_max - y_min) / 2 + y_min,
					FIXES_gsWorldbounds_PZ[playerid] = tmp,

					SetPlayerWorldBounds__(playerid, x_max, x_min, y_max, y_min);
			}
			return 0;
		}
	#else
		forward _FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min);

		stock FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				FIXES_PRINTF("Call SetPlayerWorldBounds");
				// Impossibly small area, disable checks entirely.
				if (x_max == x_min || y_max == y_min)
					return
						CallRemoteFunction__(FIXES_gscSetPlayerWorldBounds, FIXES_gscSpec@iffff, playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS),
						getproperty(5, FIXES_gscReturnProperty);
				new
					Float:tmp;
				if (x_max < x_min)
				{
					tmp = x_min,
					x_min = x_max,
					x_max = tmp;
				}
				if (y_max < y_min)
				{
					tmp = y_min,
					y_min = y_max,
					y_max = tmp;
				}
				return
					CallRemoteFunction__(FIXES_gscSetPlayerWorldBounds, FIXES_gscSpec@iffff, playerid, x_max, x_min, y_max, y_min),
					getproperty(5, FIXES_gscReturnProperty);
			}
			return 0;
		}

		public _FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
		{
			FIXES_PRINTF("_FIXES_SetPlayerWorldBounds: %d %.2f %.2f %.2f %.2f", playerid, x_max, x_min, y_max, y_min);
			FIXES_gsWorldbounds_LX[playerid] = x_min,
			FIXES_gsWorldbounds_UX[playerid] = x_max,

			FIXES_gsWorldbounds_LY[playerid] = y_min,
			FIXES_gsWorldbounds_UY[playerid] = y_max;

			new
				Float:tmp;
			GetPlayerPos__(playerid, tmp, tmp, tmp),
			FIXES_gsWorldbounds_PX[playerid] = (x_max - x_min) / 2 + x_min,
			FIXES_gsWorldbounds_PY[playerid] = (y_max - y_min) / 2 + y_min,
			FIXES_gsWorldbounds_PZ[playerid] = tmp;

			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscReturnProperty, SetPlayerWorldBounds__(playerid, x_max, x_min, y_max, y_min));
			}
			return 0;
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_SetPlayerWorldBounds
		#define SetPlayerWorldBounds( FIXES_SetPlayerWorldBounds(
	#endif

	#define _ALS_SetPlayerWorldBounds__
	#define SetPlayerWorldBounds__( FIXES_SetPlayerWorldBounds(
#endif

#if FIX_GetPlayerWorldBounds
	stock FIXES_GetPlayerWorldBounds(playerid, &Float:x_max, &Float:x_min, &Float:y_max, &Float:y_min)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			x_min = FIXES_gsWorldbounds_LX[playerid],
			x_max = FIXES_gsWorldbounds_UX[playerid],
			y_min = FIXES_gsWorldbounds_LY[playerid],
			y_max = FIXES_gsWorldbounds_UY[playerid];
		}
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerWorldBounds
		#define GetPlayerWorldBounds( FIXES_GetPlayerWorldBounds(
	#endif

	#define _ALS_GetPlayerWorldBounds__
	#define GetPlayerWorldBounds__( FIXES_GetPlayerWorldBounds(
#endif

#if FIX_ClearPlayerWorldBounds
	stock FIXES_ClearPlayerWorldBounds(playerid)
	{
		SetPlayerWorldBounds__(playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS);
	}

	#if _FIXES_SAMP
		#define _ALS_ClearPlayerWorldBounds
		#define ClearPlayerWorldBounds( FIXES_ClearPlayerWorldBounds(
	#endif

	#define _ALS_ClearPlayerWorldBounds__
	#define ClearPlayerWorldBounds__( FIXES_ClearPlayerWorldBounds(
#endif

/**
 * <fixes>TogglePlayerControllable</fixes>
 */

#if _FIXES_SAMP && defined _ALS_TogglePlayerControllable
	#error _ALS_TogglePlayerControllable defined
#endif
native BAD_TogglePlayerControllable(playerid, toggle) = TogglePlayerControllable;

/**
 * <fixes>TogglePlayerControllable</fixes>
 */

#if FIX_TogglePlayerControllable
	#if FIXES_Single
		stock FIXES_TogglePlayerControllable(playerid, toggle)
		{
			if (TogglePlayerControllable__(playerid, toggle))
			{
				if (toggle)
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_UNCONTROLLABLE;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_UNCONTROLLABLE;
				}
				return 1;
			}
			return 0;
		}
	#else
		forward _FIXES_TogglePlayerControllable(playerid, toggle);

		stock FIXES_TogglePlayerControllable(playerid, toggle)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				return
					CallRemoteFunction__(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, playerid, toggle),
					getproperty(5, FIXES_gscReturnProperty);
			}
			return 0;
		}

		public _FIXES_TogglePlayerControllable(playerid, toggle)
		{
			_FIXES_IS_IN_CHARGE()
			{
				if (toggle)
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_UNCONTROLLABLE;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_UNCONTROLLABLE;
				}
				setproperty(5, FIXES_gscReturnProperty, TogglePlayerControllable__(playerid, toggle));
			}
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_TogglePlayerControllable
		#define TogglePlayerControllable( FIXES_TogglePlayerControllable(
	#endif

	#define _ALS_TogglePlayerControllable__
	#define TogglePlayerControllable__( FIXES_TogglePlayerControllable(
#endif

/**
 * <fixes>AllowInteriorWeapons</fixes>
 * <fixes>GetPlayerInterior</fixes>
 */

#if FIX_AllowInteriorWeapons || FIX_GetPlayerInterior || FIX_SilentTeleport
	public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
	{

		// =============================
		//  BEGIN: SilentTeleport
		// =============================
		#if FIX_SilentTeleport
			if (GetPlayerState__(playerid) == PLAYER_STATE_DRIVER && FIXES_gsJackedId[playerid] != INVALID_PLAYER_ID)
			{
				ClearAnimations__(FIXES_gsJackedId[playerid]);
			}
		#endif
		// =============================
		//  END: SilentTeleport
		// =============================
		
		// ==========================
		//  BEGIN: GetPlayerInterior
		// ==========================
		#if FIX_GetPlayerInterior
			_FIXES_IS_IN_CHARGE()
			{
				FIXES_SET(PlayerInterior, playerid, newinteriorid);
			}
		#endif
		// ==========================
		//  END:   GetPlayerInterior
		// ==========================

		// =============================
		//  BEGIN: AllowInteriorWeapons
		// =============================
		#if FIX_AllowInteriorWeapons
			if (newinteriorid)
			{
				if (FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR)
				{
					// This only needs doing here if "GetPlayerWeapon" is set.
					// If it isn't, even though "AllowInteriorWeapons" can use
					// this code on its own, it doesn't as "OnPlayerUpdate"
					// takes care of it all.
					// TODO: Rewrite this code to use a single bit to indicate
					// if a player can have a weapon or not, and just use the in
					// the "OnPlayerUpdate" callback, instead of several checks.
					// DONE!
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_INTERIOR;
					_FIXES_IS_IN_CHARGE()
					{
						SetPlayerArmedWeapon__(playerid, 0);
						#if FIX_GetPlayerWeapon
							if (IsPlayerInAnyVehicle__(playerid))
							{
								FIXES_SET(PlayerWeapon, playerid, 0);
							}
						#endif
					}
				}
			}
			else
			{
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_INTERIOR;
			}
		#endif
		// ===========================
		//  END: AllowInteriorWeapons
		// ===========================
		return FIXES_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
	}

	#if defined _ALS_OnPlayerInteriorChange
		#error _ALS_OnPlayerInteriorChange defined
	#endif
	#define _ALS_OnPlayerInteriorChange
	#define OnPlayerInteriorChange(%0) FIXES_OnPlayerInteriorChange(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
#endif

/**
 * <fixes>SetTimer</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_SetTimer
		#error _ALS_SetTimer defined
	#endif

	#if _FIXES_SAMP && defined _ALS_SetTimerEx
		#error _ALS_SetTimerEx defined
	#endif
	native BAD_SetTimer(const funcname[], interval, repeating) = SetTimer;
	native BAD_SetTimerEx(const funcname[], interval, repeating, const format[], {Float,_}:...) = SetTimerEx;
#endif

#if !FIX_SetTimer
	static
#endif
	stock FIXES_SetTimer(const funcname[], interval, repeating)
	{
		new
			ret = SetTimer__(funcname, interval, repeating);
		if (ret == 0)
		{
			// Got a timer ID of 0, which is actually valid.
			// Make a new version.
			ret = SetTimer__(funcname, interval, repeating);
			// Kill the old version.
			KillTimer__(0);
			// If this is still 0 there was probably a problem, so go with it.
		}
		return ret;
	}

#if FIX_SetTimer
	#if _FIXES_SAMP
		#if defined _ALS_SetTimer
			#undef SetTimer
		#else
			#define _ALS_SetTimer
		#endif
		#define SetTimer( FIXES_SetTimer(
	#endif
	#define _ALS_SetTimer__
	#define SetTimer__( FIXES_SetTimer(
#endif

#if !FIX_SetTimer
	static
#endif
	stock FIXES_SetTimerEx(const funcname[], interval, repeating, const format[], {Float,_}:...)
	{
		#pragma unused funcname, interval, repeating, format

		static
			sAddress, // Return address.
			sFrame,   // Caller frame.
			sTimer;   // Timer return value.

		// Get the function preamble off the stack.
		#emit POP.pri
		#emit POP.alt
		#emit STOR.pri     sFrame
		#emit STOR.alt     sAddress

		// We can now just call `SetTimerEx` directly - the stack is correct for
		// this call.
		#emit SYSREQ.C     SetTimerEx
		#emit STOR.pri     sTimer

		// At this point we have NOT restored the function header to the stack,
		// but it's unneeded.
		if (sTimer == 0)
		{
			// Call it again.
			#emit SYSREQ.C     SetTimerEx
			#emit STOR.pri     sTimer

			// Kill the original.
			#emit PUSH.C       0
			#emit PUSH.C       4
			#emit SYSREQ.C     KillTimer
			#emit STACK        8
		}

		// Compiler bug fix.
		{}

		// Now we can put the stack back, after one or two calls.
		#emit PUSH         sAddress
		#emit PUSH         sFrame

		// And return the stored timer ID.
		return sTimer;
	}

#if FIX_SetTimer
	#if _FIXES_SAMP
		#if defined _ALS_SetTimerEx
			#undef SetTimerEx
		#else
			#define _ALS_SetTimerEx
		#endif
		#define SetTimerEx( FIXES_SetTimerEx(
	#endif
	#define _ALS_SetTimerEx__
	#define SetTimerEx__( FIXES_SetTimerEx(
#endif

/**
 * <fixes>DriveBy</fixes>
 */

#if FIX_DriveBy
	forward _FIXES_DriveBy(playerid);

	public  _FIXES_DriveBy(playerid)
	{
		if (GetPlayerState__(playerid) == PLAYER_STATE_PASSENGER)
		{
			SetPlayerArmedWeapon__(playerid, FIXES_gsDriveByWeapon[playerid]);
		}
		return FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_DRIVE_BY;
	}

	static stock _FIXES_HideDriveByWeapon(playerid)
	{
		FIXES_gsDriveByWeapon[playerid] = GetPlayerWeapon__(playerid),
		FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_DRIVE_BY,
		SetPlayerArmedWeapon__(playerid, 0),
		ApplyAnimation__(playerid, "PED", "CAR_GETIN_RHS", 4.1, 0, 0, 0, 0, 1, 1),
		SetTimerEx__(FIXES_gscDriveBy, 500, 0, FIXES_gscSpec@i, playerid);
	}
#endif

/**
 * <fixes>DriveBy</fixes>
 */

#if FIX_DriveBy
	public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
	{
		// ===============================
		//  BEGIN: DriveBy
		// ===============================
		#if FIX_DriveBy
			#if !FIXES_Single
				if (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE)
			#endif
				{
					if ((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH) && GetPlayerState__(playerid) == PLAYER_STATE_PASSENGER && GetPlayerCameraMode__(playerid) == 55 && !(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DRIVE_BY))
					{
						_FIXES_HideDriveByWeapon(playerid);
					}
				}
		#endif
		// =============================
		//  END: DriveBy
		// =============================

		return FIXES_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	}

	#if defined _ALS_OnPlayerKeyStateChange
		#error _ALS_OnPlayerKeyStateChange defined
	#endif
	#define _ALS_OnPlayerKeyStateChange
	#define OnPlayerKeyStateChange(%0) FIXES_OnPlayerKeyStateChange(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys);
#endif

/**
 * <remarks>
 * Declare the function to reset the car-jacked player id to invalid id.
 * </remarks>
 */
 
#if FIX_SilentTeleport
	forward FIXES_RemoveJackedId(playerid);
	public FIXES_RemoveJackedId(playerid) return FIXES_gsJackedId[playerid] = INVALID_PLAYER_ID;
#endif

/**
 * <fixes>OnPlayerEnterVehicle_2</fixes>
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 * <fixes>PassengerSeating</fixes>
 */

#if FIX_OnPlayerEnterVehicle_2 || FIX_OnPlayerEnterVehicle_3 || FIX_PassengerSeating || FIX_SilentTeleport
	public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
	{
		// ===============================
		//  BEGIN: OnPlayerEnterVehicle_2
		// ===============================
		#if FIX_OnPlayerEnterVehicle_2
			if (!(0 < vehicleid < MAX_VEHICLES))
			{
				return FIXES_BlockUpdate(playerid);
			}
		#endif
		// =============================
		//  END: OnPlayerEnterVehicle_2
		// =============================

		// ===============================
		//  BEGIN: OnPlayerEnterVehicle_3
		// ===============================
		#if FIX_OnPlayerEnterVehicle_3
			if (FIXES_gsVehicleIsLocked[vehicleid])
			{
				new
					VEHICLE_PARAMS:engine,
					VEHICLE_PARAMS:lights,
					VEHICLE_PARAMS:alarm,
					VEHICLE_PARAMS:doors,
					VEHICLE_PARAMS:bonnet,
					VEHICLE_PARAMS:boot,
					VEHICLE_PARAMS:objective;
				GetVehicleParamsEx__(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx__(vehicleid, engine, lights, alarm, VEHICLE_PARAMS_ON, bonnet, boot, objective);

				FIXES_gsPlayerBools[playerid] |= ~e_FIXES_BOOLS_VEH_ENTER;
				FIXES_gsPlayerVehicleID[playerid] = vehicleid;
				FIXES_gsPlayerVehicleTickCount[playerid] = GetTickCount__();
			}
		#endif
		// =============================
		//  END: OnPlayerEnterVehicle_3
		// =============================

		// =============================
		//  BEGIN: PassengerSeating
		// =============================
		#if FIX_PassengerSeating
			if (ispassenger)
			{
				new
					model = GetVehicleModel__(vehicleid);

				FIXES_gsPSTimer[playerid] = GetTickCount__() + ((model == 431 || model == 437) ? 8000 : 2800);
			}
		#endif
		// =============================
		//  END: PassengerSeating
		// =============================

		// =============================
		//  BEGIN: SilentTeleport
		// =============================
		#if FIX_SilentTeleport
			if (!ispassenger)
			{
				_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
				{
					if (GetPlayerVehicleID__(i) == vehicleid && GetPlayerState__(i) == PLAYER_STATE_DRIVER)
					{
						FIXES_gsJackedId[i] = playerid;
						SetTimerEx__("FIXES_RemoveJackedId", 5000, false, "d", i);
						break;
					}
				}
			}
		#endif
		// =============================
		//  END: SilentTeleport
		// =============================

		return FIXES_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	}

	#if defined _ALS_OnPlayerEnterVehicle
		#error _ALS_OnPlayerEnterVehicle defined
	#endif
	#define _ALS_OnPlayerEnterVehicle
	#define OnPlayerEnterVehicle(%0) FIXES_OnPlayerEnterVehicle(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

/**
 * <fixes>OnPlayerEnterVehicle_2</fixes>
 */

#if FIX_OnPlayerEnterVehicle_2
	public OnPlayerExitVehicle(playerid, vehicleid)
	{
		// ===============================
		//  BEGIN: OnPlayerEnterVehicle_2
		// ===============================
		#if FIX_OnPlayerEnterVehicle_2
			if (_FIXES_IN_RANGE(vehicleid, 1, MAX_VEHICLES))
			{
				return FIXES_OnPlayerExitVehicle(playerid, vehicleid);
			}
			return FIXES_BlockUpdate(playerid);
		#endif
		// =============================
		//  END: OnPlayerEnterVehicle_2
		// =============================
	}

	#if defined _ALS_OnPlayerExitVehicle
		#error _ALS_OnPlayerExitVehicle defined
	#endif
	#define _ALS_OnPlayerExitVehicle
	#define OnPlayerExitVehicle(%0) FIXES_OnPlayerExitVehicle(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerExitVehicle(playerid, vehicleid);
#endif

/**
 * <remarks>
 * Block a player from using <symbolref name="OnPlayerUpdate" /> at all.
 * </remarks>
 */

#if FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2 || FIX_Kick || FIX_OnVehicleMod || FIX_BypassDialog
	static stock FIXES_BlockUpdate(playerid, bool:kick = true, e_FIXES_BOOLS:type = e_FIXES_BOOLS_FORCE_BLOCK)
	{
		if (type == e_FIXES_BOOLS_FORCE_BLOCK)
		{
			// Replace temporary dialog blocks with permanant blocks.
			FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_DIALOG_BLOCK;
		}
		if (kick)
		{
			#if FIXES_SilentKick
				new
					ip[22];
				GetPlayerIp__(playerid, ip, sizeof (ip)),
				format(ip, sizeof (ip), "banip %s", ip),
				SendRconCommand__(ip),
				// Just re-using an existing variable, so override the tags.
				FIXES_gsPlayerIP[playerid] = strval(ip[_:kick]) << 24,
				kick = bool:(strfind(ip, FIXES_gscDot, false, _:kick) + 1),
				FIXES_gsPlayerIP[playerid] |= strval(ip[_:kick]) << 16,
				kick = bool:(strfind(ip, FIXES_gscDot, false, _:kick) + 1),
				FIXES_gsPlayerIP[playerid] |= strval(ip[_:kick]) << 8,
				kick = bool:(strfind(ip, FIXES_gscDot, false, _:kick) + 1),
				FIXES_gsPlayerIP[playerid] |= strval(ip[_:kick]);
			#else
				Kick__(playerid);
			#endif
		}
		// Always return `0`.
		if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_FORCE_BLOCK)
		{
			return 0;
		}
		return
			FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_BLOCK | type,
			0;
	}
#endif

/**
 * <remarks>
 * Unblock a player's updates after they close a dialog.
 * </remarks>
 */

#if FIX_BypassDialog
	#if !FIXES_Single
		forward @FIXES_BlockUpdate(playerid, bool:block);
		
		public @FIXES_BlockUpdate(playerid, bool:block)
		{
			if (block)
			{
				FIXES_BlockUpdate(playerid, false, e_FIXES_BOOLS_DIALOG_BLOCK);
			}
			else if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DIALOG_BLOCK)
			{
				FIXES_gsPlayerBools[playerid] &= ~(e_FIXES_BOOLS_BLOCK | e_FIXES_BOOLS_DIALOG_BLOCK);
			}
		}
	#endif
#endif

/**
 * <remarks>
 * Block a player from entering a vehicle after the animation for a locked
 * driver door
 * </remarks>
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3
	static stock _FIXES_StopPlayerEnterVehicle(playerid)
	{
		FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_VEH_ENTER;
		FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_VEH_ENTER_ANIM;

		new
			vehicleid = FIXES_gsPlayerVehicleID[playerid],
			VEHICLE_PARAMS:engine,
			VEHICLE_PARAMS:lights,
			VEHICLE_PARAMS:alarm,
			VEHICLE_PARAMS:doors,
			VEHICLE_PARAMS:bonnet,
			VEHICLE_PARAMS:boot,
			VEHICLE_PARAMS:objective;

		GetVehicleParamsEx__(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx__(vehicleid, engine, lights, alarm, VEHICLE_PARAMS_OFF, bonnet, boot, objective);

		ClearAnimations__(playerid);
	}
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu
	public OnPlayerSelectedMenuRow(playerid, row)
	{
		// ======================
		//  BEGIN: GetPlayerMenu
		// ======================
		#if FIXES_Single
			FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
			new
				ret = FIXES_OnPlayerSelectedMenuRow(playerid, row);
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
			{
				FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
			}
			return ret;
		#else
			new
				Menu:cur = FIXES_gsCurrentMenu[playerid];
			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscMenuProperty, _:cur);
				CallRemoteFunction__(FIXES_gscClearPlayerMenu, FIXES_gscSpec@i, playerid);
				FIXES_gsCurrentMenu[playerid] = cur;
				new
					ret = FIXES_OnPlayerSelectedMenuRow(playerid, row);
				if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
				{
					FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
				}
				return ret;
			}
			else
			{
				FIXES_gsCurrentMenu[playerid] = Menu:getproperty(5, FIXES_gscMenuProperty);
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
				new
					ret = FIXES_OnPlayerSelectedMenuRow(playerid, row);
				if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
				{
					FIXES_gsCurrentMenu[playerid] = cur;
				}
				return ret;
			}
		#endif
		// ======================
		//  END:   GetPlayerMenu
		// ======================
	}

	#if defined _ALS_OnPlayerSelectedMenuRow
		#error _ALS_OnPlayerSelectedMenuRow defined
	#endif
	#define _ALS_OnPlayerSelectedMenuRow
	#define OnPlayerSelectedMenuRow(%0) FIXES_OnPlayerSelectedMenuRow(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerSelectedMenuRow(playerid, row);
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu
	public OnPlayerExitedMenu(playerid)
	{
		// ======================
		//  BEGIN: GetPlayerMenu
		// ======================
		#if FIXES_Single
			FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
			new
				ret = FIXES_OnPlayerExitedMenu(playerid);
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
			{
				FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
			}
			return ret;
		#else
			new
				Menu:cur = FIXES_gsCurrentMenu[playerid];
			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscMenuProperty, _:cur);
				CallRemoteFunction__(FIXES_gscClearPlayerMenu, FIXES_gscSpec@i, playerid);
				FIXES_gsCurrentMenu[playerid] = cur;
				new
					ret = FIXES_OnPlayerExitedMenu(playerid);
				if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
				{
					FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
				}
				return ret;
			}
			else
			{
				FIXES_gsCurrentMenu[playerid] = Menu:getproperty(5, FIXES_gscMenuProperty);
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
				new
					ret = FIXES_OnPlayerExitedMenu(playerid);
				if (!(FIXES_gsSettings & e_FIXES_SETTINGS_MENU_SET))
				{
					FIXES_gsCurrentMenu[playerid] = cur;
				}
				return ret;
			}
		#endif
		// ======================
		//  END:   GetPlayerMenu
		// ======================
	}

	#if defined _ALS_OnPlayerExitedMenu
		#error _ALS_OnPlayerExitedMenu defined
	#endif
	#define _ALS_OnPlayerExitedMenu
	#define OnPlayerExitedMenu(%0) FIXES_OnPlayerExitedMenu(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerExitedMenu(playerid);
#endif

/**
 * <fixes>Menus</fixes>
 */

#if _FIX_Menus || FIX_API
	#define FIXES_IS_VALID_MENU(%0) (_FIXES_IN_RANGE(_:(%0), 0, MAX_MENUS) && (FIXES_gsValidMenus[_:(%0) >>> 5] & (1 << (_:(%0) & 0x1F))))
#endif

/**
 * <fixes>Menus</fixes>
 */

#if _FIXES_SAMP && defined _ALS_CreateMenu
	#error _ALS_CreateMenu defined
#endif
native Menu:BAD_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;

#if _FIX_Menus || FIX_API
	#if !FIXES_Single
		forward _FIXES_CreateMenu(ret);

		public _FIXES_CreateMenu(ret)
		{
			FIXES_gsValidMenus[ret >>> 5] |= 1 << (ret & 0x1F);
		}
	#endif

	stock Menu:FIXES_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0)
	{
		new
			Menu:ret = CreateMenu__(title, columns, x, y, col1width, col2width);
		if (_FIXES_IN_RANGE(_:ret, 0, MAX_MENUS))
		{
			#if FIXES_Single
				FIXES_gsValidMenus[_:ret >>> 5] |= 1 << (_:ret & 0x1F);
			#else
				CallRemoteFunction__("_FIXES_CreateMenu", FIXES_gscSpec@i, _:ret);
			#endif
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_CreateMenu
		#define CreateMenu( FIXES_CreateMenu(
	#endif

	#define _ALS_CreateMenu__
	#define CreateMenu__( FIXES_CreateMenu(
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu && !FIXES_Single
	forward _FIXES_SetPlayerMenu(playerid, Menu:menuid);

	public _FIXES_SetPlayerMenu(playerid, Menu:menuid)
	{
		FIXES_gsSettings |= e_FIXES_SETTINGS_MENU_SET;
		FIXES_gsCurrentMenu[playerid] = menuid;
	}
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu && !FIXES_Single
	forward _FIXES_ClearPlayerMenu(playerid);

	public _FIXES_ClearPlayerMenu(playerid)
	{
		FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
		FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
	}
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DestroyMenu
	#error _ALS_DestroyMenu defined
#endif
native BAD_DestroyMenu(Menu:menuid) = DestroyMenu;

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIX_Menus || FIX_GetPlayerMenu || FIX_API
	#if (_FIX_Menus || FIX_API) && !FIXES_Single
		forward _FIXES_DestroyMenu(ret);

		public _FIXES_DestroyMenu(ret)
		{
			FIXES_gsValidMenus[ret >>> 5] &= ~(1 << (ret & 0x1F));
		}
	#endif

	stock FIXES_DestroyMenu(Menu:menuid)
	{
		#if _FIX_Menus
			if (FIXES_IS_VALID_MENU(menuid))
		#endif
			{
				if (DestroyMenu__(Menu:menuid))
				{
					#if _FIX_Menus || FIX_API
						#if FIXES_Single
							FIXES_gsValidMenus[_:menuid >>> 5] &= ~(1 << (_:menuid & 0x1F));
						#else
							CallRemoteFunction__("_FIXES_DestroyMenu", FIXES_gscSpec@i, _:menuid);
						#endif
					#endif
					_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
					{
						if (FIXES_gsCurrentMenu[playerid] == menuid)
						{
							if (HideMenuForPlayer__(menuid, playerid))
							{
								#if FIXES_Single
									FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET,
									FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
								#else
									CallRemoteFunction__(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, _:INVALID_MENU);
								#endif
							}
						}
					}
					return 1;
				}
			}
			return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_DestroyMenu
		#define DestroyMenu( FIXES_DestroyMenu(
	#endif

	#define _ALS_DestroyMenu__
	#define DestroyMenu__( FIXES_DestroyMenu(
#endif

/**
 * <fixes>AddMenuItem</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AddMenuItem
	#error _ALS_AddMenuItem defined
#endif
native BAD_AddMenuItem(Menu:menuid, column, const menutext[]) = AddMenuItem;

/**
 * <fixes>AddMenuItem</fixes>
 */

#if FIX_AddMenuItem
	stock FIXES_AddMenuItem(Menu:menuid, column, const menutext[])
	{
		if (FIXES_IS_VALID_MENU(menuid))
		{
			return AddMenuItem__(menuid, column, menutext);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_AddMenuItem
		#define AddMenuItem( FIXES_AddMenuItem(
	#endif

	#define _ALS_AddMenuItem__
	#define AddMenuItem__( FIXES_AddMenuItem(
#endif

/**
 * <fixes>SetMenuColumnHeader</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetMenuColumnHeader
	#error _ALS_SetMenuColumnHeader defined
#endif
native BAD_SetMenuColumnHeader(Menu:menuid, column, const columnheader[]) = SetMenuColumnHeader;

/**
 * <fixes>SetMenuColumnHeader</fixes>
 */

#if FIX_SetMenuColumnHeader
	stock FIXES_SetMenuColumnHeader(Menu:menuid, column, const columnheader[])
	{
		if (FIXES_IS_VALID_MENU(menuid))
		{
			return SetMenuColumnHeader__(menuid, column, columnheader);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetMenuColumnHeader
		#define SetMenuColumnHeader( FIXES_SetMenuColumnHeader(
	#endif

	#define _ALS_SetMenuColumnHeader__
	#define SetMenuColumnHeader__( FIXES_SetMenuColumnHeader(
#endif

/**
 * <fixes>ShowMenuForPlayer</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIXES_SAMP && defined _ALS_ShowMenuForPlayer
	#error _ALS_ShowMenuForPlayer defined
#endif
native BAD_ShowMenuForPlayer(Menu:menuid, playerid) = ShowMenuForPlayer;

/**
 * <fixes>ShowMenuForPlayer</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_ShowMenuForPlayer || FIX_GetPlayerMenu
	stock FIXES_ShowMenuForPlayer(Menu:menuid, playerid)
	{
		#if FIX_ShowMenuForPlayer
			if (FIXES_IS_VALID_MENU(menuid))
		#endif
			{
				#if FIX_GetPlayerMenu
					if (ShowMenuForPlayer__(menuid, playerid))
					{
						#if FIXES_Single
							FIXES_gsSettings |= e_FIXES_SETTINGS_MENU_SET,
							FIXES_gsCurrentMenu[playerid] = menuid;
						#else
							CallRemoteFunction__(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, _:menuid);
						#endif
							return 1;
					}
				#else
					return ShowMenuForPlayer__(menuid, playerid);
				#endif
			}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_ShowMenuForPlayer
		#define ShowMenuForPlayer( FIXES_ShowMenuForPlayer(
	#endif

	#define _ALS_ShowMenuForPlayer__
	#define ShowMenuForPlayer__( FIXES_ShowMenuForPlayer(
#endif

/**
 * <fixes>HideMenuForPlayer</fixes>
 * <fixes>HideMenuForPlayer_2</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIXES_SAMP && defined _ALS_HideMenuForPlayer
	#error _ALS_HideMenuForPlayer defined
#endif
native BAD_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;

/**
 * <fixes>HideMenuForPlayer</fixes>
 * <fixes>HideMenuForPlayer_2</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_HideMenuForPlayer || FIX_GetPlayerMenu
	stock FIXES_HideMenuForPlayer(Menu:menuid, playerid)
	{
		#if FIX_HideMenuForPlayer
			if (FIXES_IS_VALID_MENU(menuid))
		#endif
			{
				#if FIX_GetPlayerMenu
					#if FIX_HideMenuForPlayer_2
						if (_FIXES_IS_VALID_PLAYER(playerid) && FIXES_gsCurrentMenu[playerid] == menuid)
					#else
						if (FIXES_gsCurrentMenu[playerid] == menuid && HideMenuForPlayer__(menuid, playerid))
					#endif
						{
							#if FIXES_Single
								FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET,
								FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
							#else
								CallRemoteFunction__(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, _:INVALID_MENU);
							#endif
							#if FIX_HideMenuForPlayer_2
								return HideMenuForPlayer__(menuid, playerid);
							#else
								return 1;
							#endif
						}
				#else
					return HideMenuForPlayer__(menuid, playerid);
				#endif
			}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_HideMenuForPlayer
		#define HideMenuForPlayer( FIXES_HideMenuForPlayer(
	#endif

	#define _ALS_HideMenuForPlayer__
	#define HideMenuForPlayer__( FIXES_HideMenuForPlayer(
#endif

/**
 * <fixes>DisableMenu</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DisableMenu
	#error _ALS_DisableMenu defined
#endif
native BAD_DisableMenu(Menu:menuid) = DisableMenu;

/**
 * <fixes>DisableMenu</fixes>
 */

#if FIX_DisableMenu
	stock FIXES_DisableMenu(Menu:menuid)
	{
		if (FIXES_IS_VALID_MENU(menuid))
		{
			return DisableMenu__(menuid);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_DisableMenu
		#define DisableMenu( FIXES_DisableMenu(
	#endif

	#define _ALS_DisableMenu__
	#define DisableMenu__( FIXES_DisableMenu(
#endif

/**
 * <fixes>DisableMenuRow</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DisableMenuRow
	#error _ALS_DisableMenuRow defined
#endif
native BAD_DisableMenuRow(Menu:menuid, row) = DisableMenuRow;

/**
 * <fixes>DisableMenuRow</fixes>
 */

#if FIX_DisableMenuRow
	stock FIXES_DisableMenuRow(Menu:menuid, row)
	{
		if (FIXES_IS_VALID_MENU(menuid))
		{
			return DisableMenuRow__(menuid, row);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_DisableMenuRow
		#define DisableMenuRow( FIXES_DisableMenuRow(
	#endif

	#define _ALS_DisableMenuRow__
	#define DisableMenuRow__( FIXES_DisableMenuRow(
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerMenu
	#error _ALS_GetPlayerMenu defined
#endif
native BAD_GetPlayerMenu(playerid) = GetPlayerMenu;

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu
	stock Menu:FIXES_GetPlayerMenu(playerid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			return FIXES_gsCurrentMenu[playerid];
		}
		return Menu:INVALID_MENU;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerMenu
		#define GetPlayerMenu( FIXES_GetPlayerMenu(
	#endif

	#define _ALS_GetPlayerMenu__
	#define GetPlayerMenu__( FIXES_GetPlayerMenu(
#endif

/**
 * <fixes>HydraSniper</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>PutPlayerInVehicle</fixes>
 * <fixes>TrainExit</fixes>
 */

#if FIX_HydraSniper || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_TrainExit
	public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
	{
		#if !FIXES_Single
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
			{
				return FIXES_OnPlayerStateChange(playerid, newstate, oldstate);
			}
		#endif

		// =============================
		//  BEGIN: OnPlayerEnterVehicle
		// =============================
		#if FIX_OnPlayerEnterVehicle
				if (newstate == PLAYER_STATE_PASSENGER)
				{
					new
						model = GetVehicleModel__(GetPlayerVehicleID__(playerid)) - 400;
					if (_FIXES_IN_RANGE(model, 0, 211 + 1))
					{
						model = (FIXES_gscMaxPassengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
						if (model == 0 || model == 15)
						{
							// Shouldn't be in this vehicle at all.
							FIXES_BlockUpdate(playerid);
						}
						else
						{
							// Slower with "_FIXES_NO_RANGE".
							if (!(0 < GetPlayerVehicleSeat__(playerid) <= model))
							{
								// In an out of range seat.
								FIXES_BlockUpdate(playerid);
							}
						}
					}
					else
					{
						FIXES_BlockUpdate(playerid);
					}
				}
				else if (newstate == PLAYER_STATE_DRIVER)
				{
					new
						model = GetVehicleModel__(GetPlayerVehicleID__(playerid)) - 400;
					if (GetPlayerVehicleSeat__(playerid) == 0)
					{
						if (_FIXES_NO_RANGE(model, 0, 211 + 1) || FIXES_gscMaxPassengers[model >>> 3] >>> ((model & 7) << 2) & 0xF == 15)
						{
							// In an invalid vehicle (one you can't drive).
							FIXES_BlockUpdate(playerid);
						}
					}
					else
					{
						// They are a driver, but not in the driver's seat.
						FIXES_BlockUpdate(playerid);
					}
			#if !FIX_HydraSniper && !FIX_GetPlayerWeapon
				}
			#endif
		#endif
		// =============================
		//  END:   OnPlayerEnterVehicle
		// =============================

		// ====================
		//  BEGIN: HydraSniper
		// ====================
		#if FIX_HydraSniper
			#if !FIX_OnPlayerEnterVehicle
				// Only called if the same check above isn't called.
				if (newstate == PLAYER_STATE_DRIVER)
				{
					new
						model = GetVehicleModel__(GetPlayerVehicleID__(playerid)) - 400;
			#endif
					if (GetPlayerWeapon__(playerid) == 34 && (model == 120 || model == 25))
					{
						SetPlayerArmedWeapon__(playerid, 0);
						#if FIX_GetPlayerWeapon
							// This is the first cross-dependednt fix.
							FIXES_SET(PlayerWeapon, playerid, 0);
						#endif
					}
			#if !FIX_GetPlayerWeapon
				}
			#endif
		#endif
		// ====================
		//  END:   HydraSniper
		// ====================

		// ========================
		//  BEGIN: GetPlayerWeapon
		// ========================
		#if FIX_GetPlayerWeapon
			#if !FIX_OnPlayerEnterVehicle && !FIX_HydraSniper
				// Only called if the same check above isn't called.
				if (newstate == PLAYER_STATE_DRIVER)
				{
					new
						model,
						ammo;
			#else
					new
						ammo;
			#endif
					// It's a shame `weaponid` is set before `ammo` since we
					// don't actually read ammo.  Were they done the other way
					// around we could do:
					//
					//   GetPlayerWeaponData__(playerid, 4, model, model);
					//
					// And have the weapon data clobber the ammo data, thus
					// avoiding a variable allocation (wow, a whole ONE
					// instruction...).
					GetPlayerWeaponData__(playerid, 4, model, ammo);
					if (model)
					{
						SetPlayerArmedWeapon__(playerid, model);
						FIXES_SET(PlayerWeapon, playerid, model);
					}
				}
		#endif
		// ========================
		//  END:   GetPlayerWeapon
		// ========================

		#if FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_TrainExit
			#if PLAYER_STATE_PASSENGER != PLAYER_STATE_DRIVER + PLAYER_STATE:1
				#error FIX_GetPlayerWeapon/FIX_PutPlayerInVehicle/FIX_TrainExit state assertation failed.
			#endif
			if (_FIXES_IN_RANGE(oldstate, PLAYER_STATE_DRIVER, PLAYER_STATE_PASSENGER + PLAYER_STATE:1))
			{
				#if FIX_PutPlayerInVehicle || FIX_TrainExit
					new
						e_FIXES_BOOLS:bools = FIXES_gsPlayerBools[playerid];
				#endif

				// ========================
				//  BEGIN: GetPlayerWeapon
				// ========================
				#if FIX_GetPlayerWeapon
					FIXES_SET(PlayerWeapon, playerid, -1);
				#endif
				// ========================
				//  END:   GetPlayerWeapon
				// ========================

				// ==================
				//  BEGIN: TrainExit
				// ==================
				#if FIX_TrainExit
					FIXES_PRINTF("train exit");
					if (bools & e_FIXES_BOOLS_PUT_IN_TRAIN)
					{
						FIXES_PRINTF("OK");
						SetCameraBehindPlayer__(playerid),
						bools &= ~e_FIXES_BOOLS_PUT_IN_TRAIN;
					}
				#endif
				// ==================
				//  END:   TrainExit
				// ==================

				// ===========================
				//  BEGIN: PutPlayerInVehicle
				// ===========================
				#if FIX_PutPlayerInVehicle
					// Update their vehicle once we KNOW the client has done the
					// removal from the vehicle.
					if (bools & e_FIXES_BOOLS_PUT_IN_VEHICLE)
					{
						new
							vid = FIXES_gsVehicleSeatData[playerid] & 0x00FFFFFF;
						// Limited to "only" 16777216 vehicles and 256 seats.
						PutPlayerInVehicle__(playerid, vid, FIXES_gsVehicleSeatData[playerid] >>> 24),
						bools &= ~e_FIXES_BOOLS_PUT_IN_VEHICLE;
						#if FIX_TrainExit
							switch (GetVehicleModel__(vid))
							{
								case 449, 537, 538:
								{
									bools |= e_FIXES_BOOLS_PUT_IN_TRAIN;
								}
							}
						#endif
					}
				#endif
				// ===========================
				//  END:   PutPlayerInVehicle
				// ===========================

				#if FIX_PutPlayerInVehicle || FIX_TrainExit
					FIXES_gsPlayerBools[playerid] = bools;
				#endif
			}
		#endif

		// =================================
		//  BEGIN: PassengerSeating
		// =================================
		#if FIX_PassengerSeating
			if (newstate == PLAYER_STATE_PASSENGER && FIXES_gsPSTimer[playerid] != 0)
			{
				FIXES_gsPSTimer[playerid] = 0;
			}
		#endif
		// =================================
		//  END:   PassengerSeating
		// =================================

		return FIXES_OnPlayerStateChange(playerid, newstate, oldstate);
	}

	#if defined _ALS_OnPlayerStateChange
		#error _ALS_OnPlayerStateChange defined
	#endif
	#define _ALS_OnPlayerStateChange
	#define OnPlayerStateChange(%0) FIXES_OnPlayerStateChange(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
#endif

/**
 * <fixes>HydraSniper</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>GetPlayerAmmo</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GivePlayerWeapon
	#error _ALS_GivePlayerWeapon defined
#endif
native BAD_GivePlayerWeapon(playerid, weaponid, ammo) = GivePlayerWeapon;

/**
 * <fixes>HydraSniper</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>GetPlayerAmmo</fixes>
 */

#if FIX_HydraSniper || FIX_GetPlayerWeapon || FIX_GetPlayerAmmo
	stock FIXES_GivePlayerWeapon(playerid, weaponid, ammo)
	{
		#if FIX_GetPlayerAmmo
			new
				currentAmmo = GetPlayerAmmo__(playerid);
			if (currentAmmo + ammo > 32767)
			{
				ammo = 32767 - currentAmmo;
			}
			else if (currentAmmo + ammo < 0)
			{
				ammo = -currentAmmo;
			}
		#endif

		new
			vid = GetPlayerVehicleID__(playerid);
		if (vid)
		{
			#if FIX_HydraSniper
				vid = GetVehicleModel__(vid);
				if (weaponid == 34 && (vid == 520 || vid == 425))
				{
					vid = GivePlayerWeapon__(playerid, weaponid, ammo),
					SetPlayerArmedWeapon__(playerid, 0);
					#if FIX_GetPlayerWeapon
						FIXES_SET(PlayerWeapon, playerid, 0);
					#endif
					return vid;
				}
			#endif

			#if FIX_GetPlayerWeapon
				FIXES_SET(PlayerWeapon, playerid, weaponid);
			#endif
		}
		return GivePlayerWeapon__(playerid, weaponid, ammo);
	}

	#if _FIXES_SAMP
		#define _ALS_GivePlayerWeapon
		#define GivePlayerWeapon( FIXES_GivePlayerWeapon(
	#endif

	#define _ALS_GivePlayerWeapon__
	#define GivePlayerWeapon__( FIXES_GivePlayerWeapon(
#endif


/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if _FIXES_SAMP && defined _ALS_ResetPlayerWeapons
	#error _ALS_ResetPlayerWeapons defined
#endif
native BAD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;


/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if FIX_GetPlayerWeapon
	stock FIXES_ResetPlayerWeapons(playerid)
	{
		if (IsPlayerInAnyVehicle__(playerid))
		{
			FIXES_SET(PlayerWeapon, playerid, 0);
		}
		return ResetPlayerWeapons__(playerid);
	}

	#if _FIXES_SAMP
		#define _ALS_ResetPlayerWeapons
		#define ResetPlayerWeapons( FIXES_ResetPlayerWeapons(
	#endif

	#define _ALS_ResetPlayerWeapons__
	#define ResetPlayerWeapons__( FIXES_ResetPlayerWeapons(
#endif

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerArmedWeapon
	#error _ALS_SetPlayerArmedWeapon defined
#endif
native BAD_SetPlayerArmedWeapon(playerid, weaponid) = SetPlayerArmedWeapon;

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if FIX_GetPlayerWeapon || FIX_AllowInteriorWeapons || FIX_HydraSniper
	stock FIXES_SetPlayerArmedWeapon(playerid, weaponid)
	{
		#if FIX_AllowInteriorWeapons
			if (FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR && GetPlayerInterior__(playerid))
			{
				// Not allowed weapons.
				return 0;
			}
		#endif
		new
			vid = GetPlayerVehicleID__(playerid);
		if (vid)
		{
			#if FIX_HydraSniper
				vid = GetVehicleModel__(vid);
				if (weaponid == 34 && (vid == 520 || vid == 425))
				{
					return 0;
				}
			#endif

			#if FIX_GetPlayerWeapon
				FIXES_SET(PlayerWeapon, playerid, weaponid);
			#endif
		}
		return SetPlayerArmedWeapon__(playerid, weaponid);
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerArmedWeapon
		#define SetPlayerArmedWeapon( FIXES_SetPlayerArmedWeapon(
	#endif

	#define _ALS_SetPlayerArmedWeapon__
	#define SetPlayerArmedWeapon__( FIXES_SetPlayerArmedWeapon(
#endif

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerWeapon
	#error _ALS_GetPlayerWeapon defined
#endif
native BAD_GetPlayerWeapon(playerid) = GetPlayerWeapon;

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if FIX_GetPlayerWeapon
	stock FIXES_GetPlayerWeapon(playerid)
	{
		new
			ret = FIXES_GET(PlayerWeapon, playerid);
		if (ret == -1)
		{
			return GetPlayerWeapon__(playerid);
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerWeapon
		#define GetPlayerWeapon( FIXES_GetPlayerWeapon(
	#endif

	#define _ALS_GetPlayerWeapon__
	#define GetPlayerWeapon__( FIXES_GetPlayerWeapon(
#endif

/**
 * <fixes>PutPlayerInVehicle</fixes>
 */

#if _FIXES_SAMP && defined _ALS_PutPlayerInVehicle
	#error _ALS_PutPlayerInVehicle defined
#endif
native BAD_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;

/**
 * <fixes>PutPlayerInVehicle</fixes>
 */

#if FIX_PutPlayerInVehicle || FIX_TrainExit
	#if FIXES_Single
		stock FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid)
		{
			// ==================
			//  BEGIN: TrainExit
			// ==================
			#if FIX_TrainExit
				FIXES_PRINTF("TrainExit %d", GetVehicleModel__(vehicleid));
				switch (GetVehicleModel__(vehicleid))
				{
					case 449, 537, 538:
					{
						FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_TRAIN;
					}
				}
			#endif
			// ==================
			//  END:   TrainExit
			// ==================

			// ===========================
			//  BEGIN: PutPlayerInVehicle
			// ===========================
			#if FIX_PutPlayerInVehicle
				new
					vid = GetPlayerVehicleID__(playerid);
				if (vid)
				{
					new
						Float:x,
						Float:y,
						Float:z;
					// Remove them without the animation.
					return
						GetVehiclePos__(vid, x, y, z),
						SetPlayerPos__(playerid, x, y, z),
						FIXES_gsVehicleSeatData[playerid] = seatid << 24 | vehicleid,
						FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_VEHICLE,
						1;
				}
			#endif
			// ===========================
			//  END:   PutPlayerInVehicle
			// ===========================
			return PutPlayerInVehicle__(playerid, vehicleid, seatid);
		}
	#else
		forward _FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid, from, data);

		stock FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid)
		{
			FIXES_PRINTF("NOT SINGLE");
			// ===========================
			//  BEGIN: PutPlayerInVehicle
			// ===========================
			#if FIX_PutPlayerInVehicle
				new
					vid = GetPlayerVehicleID__(playerid);
				if (vid)
				{
					new
						Float:x,
						Float:y,
						Float:z;
					// Remove them without the animation.
					return
						GetVehiclePos__(vid, x, y, z),
						SetPlayerPos__(playerid, x, y, z),
						CallRemoteFunction__(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iiiii, playerid, vehicleid, seatid, 1, vid),
						1;
				}
			#endif
			// ===========================
			//  END:   PutPlayerInVehicle
			// ===========================

			// ==================
			//  BEGIN: TrainExit
			// ==================
			#if FIX_TrainExit
				new
					model = GetVehicleModel__(vehicleid);
				switch (model)
				{
					case 449, 537, 538:
					{
						CallRemoteFunction__(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iiiii, playerid, vehicleid, seatid, 0, model);
						//FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_TRAIN;
					}
				}
			#endif
			// ==================
			//  END:   TrainExit
			// ==================
			return PutPlayerInVehicle__(playerid, vehicleid, seatid);
		}

		public _FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid, from, data)
		{
			FIXES_PRINTF("IN CHARGE: %d", (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE));
			_FIXES_IS_IN_CHARGE()
			{
				// ===========================
				//  BEGIN: PutPlayerInVehicle
				// ===========================
				#if FIX_PutPlayerInVehicle
					if (from)
					{
						FIXES_gsVehicleSeatData[playerid] = seatid << 24 | vehicleid,
						FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_VEHICLE;
					}
				#endif
				// ===========================
				//  END:   PutPlayerInVehicle
				// ===========================

				// ==================
				//  BEGIN: TrainExit
				// ==================
				#if FIX_TrainExit
					#if FIX_PutPlayerInVehicle
						else
					#else
						if (!from)
					#endif
						{
							switch (data)
							{
								case 449, 537, 538:
								{
									FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_TRAIN;
								}
							}
						}
				#endif
				// ==================
				//  END:   TrainExit
				// ==================
			}
			return 1;
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_PutPlayerInVehicle
		#define PutPlayerInVehicle( FIXES_PutPlayerInVehicle(
	#endif

	#define _ALS_PutPlayerInVehicle__
	#define PutPlayerInVehicle__( FIXES_PutPlayerInVehicle(
#endif

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if FIX_SetPlayerCheckpoint
	forward _FIXES_SetCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size);

	public _FIXES_SetCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
	{
		#if FIXES_Single
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_CP_DELAYED)
		#else
			if (GetPVarInt__(playerid, FIXES_pvarPlayerCheckpoint))
		#endif
			{
				return
					#if FIXES_Single
						FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CP_DELAYED,
					#else
						DeletePVar__(playerid, FIXES_pvarPlayerCheckpoint),
					#endif
						SetPlayerCheckpoint__(playerid, x, y, z, size);
			}
			return 0;
	}
#endif

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerCheckpoint
	#error _ALS_SetPlayerCheckpoint defined
#endif
native BAD_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if FIX_SetPlayerCheckpoint
	stock FIXES_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
	{
		return
			#if FIXES_Single
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_CP_DELAYED,
			#else
				SetPVarInt__(playerid, FIXES_pvarPlayerCheckpoint, 1),
			#endif
				DisablePlayerCheckpoint__(playerid),
				SetTimerEx__(FIXES_gscSetCheckpoint, 50, 0, FIXES_gscSpec@iffff, playerid, x, y, z, size),
				1;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerCheckpoint
		#define SetPlayerCheckpoint( FIXES_SetPlayerCheckpoint(
	#endif

	#define _ALS_SetPlayerCheckpoint__
	#define SetPlayerCheckpoint__( FIXES_SetPlayerCheckpoint(
#endif

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DisablePlayerCheckpoint
	#error _ALS_DisablePlayerCheckpoint defined
#endif
native BAD_DisablePlayerCheckpoint(playerid) = DisablePlayerCheckpoint;

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if FIX_SetPlayerCheckpoint
	stock FIXES_DisablePlayerCheckpoint(playerid)
	{
		return
			#if FIXES_Single
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CP_DELAYED,
			#else
				DeletePVar__(playerid, FIXES_pvarPlayerCheckpoint),
			#endif
				DisablePlayerCheckpoint__(playerid);
	}

	#if _FIXES_SAMP
		#define _ALS_DisablePlayerCheckpoint
		#define DisablePlayerCheckpoint( FIXES_DisablePlayerCheckpoint(
	#endif

	#define _ALS_DisablePlayerCheckpoint__
	#define DisablePlayerCheckpoint__( FIXES_DisablePlayerCheckpoint(
#endif

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if FIX_SetPlayerRaceCheckpoint
	forward _FIXES_SetRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size);

	public _FIXES_SetRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
	{
		#if FIXES_Single
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_RACE_CP_DELAYED)
		#else
			if (GetPVarInt__(playerid, FIXES_pvarPlayerRaceCheckpoint))
		#endif
			{
				return
					#if FIXES_Single
						FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_RACE_CP_DELAYED,
					#else
						DeletePVar__(playerid, FIXES_pvarPlayerRaceCheckpoint),
					#endif
						SetPlayerRaceCheckpoint__(playerid, type, x, y, z, nextx, nexty, nextz, size);
			}
			return 0;
	}
#endif

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerRaceCheckpoint
	#error _ALS_SetPlayerRaceCheckpoint defined
#endif
native BAD_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size) = SetPlayerRaceCheckpoint;

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if FIX_SetPlayerRaceCheckpoint
	stock FIXES_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
	{
		return
			#if FIXES_Single
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_RACE_CP_DELAYED,
			#else
				SetPVarInt__(playerid, FIXES_pvarPlayerRaceCheckpoint, 1),
			#endif
				DisablePlayerRaceCheckpoint__(playerid),
				SetTimerEx__(FIXES_gscSetRaceCheckpoint, 50, 0, FIXES_gscSpec@iifffffff, playerid, type, x, y, z, nextx, nexty, nextz, size),
				1;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerRaceCheckpoint
		#define SetPlayerRaceCheckpoint( FIXES_SetPlayerRaceCheckpoint(
	#endif

	#define _ALS_SetPlayerRaceCheckpoint__
	#define SetPlayerRaceCheckpoint__( FIXES_SetPlayerRaceCheckpoint(
#endif

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DisablePlayerRaceCP
	#error _ALS_DisablePlayerRaceCP defined
#endif
native BAD_DisablePlayerRaceCheckpoint(playerid) = DisablePlayerRaceCheckpoint;

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if FIX_SetPlayerRaceCheckpoint
	stock FIXES_DisablePlayerRaceCP(playerid)
	{
		return
			#if FIXES_Single
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_RACE_CP_DELAYED,
			#else
				DeletePVar__(playerid, FIXES_pvarPlayerRaceCheckpoint),
			#endif
				DisablePlayerRaceCheckpoint__(playerid);
	}

	#define _ALS_DisablePlayerRaceCP
	#define DisablePlayerRaceCheckpoint( FIXES_DisablePlayerRaceCP(
#endif

/**
 * <remarks>
 * Hides a GameText style for one or more players, and accounts for the fact
 * that they may have different messages being shown.
 * </remarks>
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	static stock _FIXES_HideGameTextForPlayer(playerid, style, parr[], timers[])
	{
		if (playerid == MAX_PLAYERS)
		{
			// Remove the global GameText for everyone that can see it.
			if (timers[MAX_PLAYERS] != 0)
				KillTimer__(timers[MAX_PLAYERS]);
			timers[MAX_PLAYERS] = 0,
			TextDrawHideForAll__(FIXES_gsGTStyle[style]);
		}
		else if (playerid == INVALID_PLAYER_ID)
		{
			// Remove all GameTexts of this style for everyone.
			if (timers[MAX_PLAYERS] != 0)
				KillTimer__(timers[MAX_PLAYERS]);
			timers[MAX_PLAYERS] = 0,
			TextDrawHideForAll__(FIXES_gsGTStyle[style]),
			playerid = parr[MAX_PLAYERS],
			parr[MAX_PLAYERS] = MAX_PLAYERS;
			for (new next; playerid != MAX_PLAYERS; playerid = next)
			{
				if (timers[playerid] != 0)
					KillTimer__(timers[playerid]);
				PlayerTextDrawHide__(playerid, FIXES_gsPGTStyle[playerid][style]),
				next = parr[playerid],
				timers[playerid] = parr[playerid] = 0;
			}
		}
		else //if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			// Remove.
			if (timers[playerid] != 0)
				KillTimer__(timers[playerid]);
			timers[playerid] = 0,
			TextDrawHideForPlayer__(playerid, FIXES_gsGTStyle[style]),
			PlayerTextDrawHide__(playerid, FIXES_gsPGTStyle[playerid][style]),
			_FIXES_RemoveInternal(parr, playerid, MAX_PLAYERS);
		}
		return 1;
	}
#endif

/**
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	forward _FIXES_HideGameTextTimer(playerid, style);

	public _FIXES_HideGameTextTimer(playerid, style)
	{
		return _FIXES_HideGameTextForPlayer(playerid, style, FIXES_gsPlayerPGTShown[style], FIXES_gsGTTimer[style]);
	}
#endif

/**
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	forward _FIXES_GameTextShow(playerid, const string[], time, style);

	public _FIXES_GameTextShow(playerid, const string[], time, style)
	{
		_FIXES_IS_IN_CHARGE()
		{
			if (playerid == MAX_PLAYERS)
			{
				_FIXES_HideGameTextForPlayer(INVALID_PLAYER_ID, style, FIXES_gsPlayerPGTShown[style], FIXES_gsGTTimer[style]),
				TextDrawSetString__(FIXES_gsGTStyle[style], string),
				TextDrawShowForAll__(FIXES_gsGTStyle[style]);
			}
			else
			{
				_FIXES_HideGameTextForPlayer(playerid, style, FIXES_gsPlayerPGTShown[style], FIXES_gsGTTimer[style]),
				PlayerTextDrawSetString__(playerid, FIXES_gsPGTStyle[playerid][style], string),
				PlayerTextDrawShow__(playerid, FIXES_gsPGTStyle[playerid][style]),
				_FIXES_AddInternal(FIXES_gsPlayerPGTShown[style], playerid, MAX_PLAYERS);
			}
			if (time)
				FIXES_gsGTTimer[style][playerid] = SetTimerEx__(FIXES_gscHideGameTextTimer, time, false, FIXES_gscSpec@ii, playerid, style);
		}
		return 1;
	}
#endif

/**
 * <fixes>GameText</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GameTextForAll
	#error _ALS_GameTextForAll defined
#endif
native BAD_GameTextForAll(const string[], time, style) = GameTextForAll;

/**
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	stock FIXES_GameTextForAll(const string[], time, style)
	{
		if (_FIXES_IN_RANGE(style, 0, FIXES_GT_STYLE_COUNT))
		{
			// FINALLY come up with a better _FIXES_IS_NULL check!
			if (_FIXES_IS_NULL(string))
			{
				#if FIXES_Single
					return _FIXES_HideGameTextTimer(INVALID_PLAYER_ID, style);
				#else
					return CallRemoteFunction__(FIXES_gscHideGameTextTimer, FIXES_gscSpec@ii, INVALID_PLAYER_ID, style);
				#endif
			}
			else
			{
				#if FIXES_Single
					return _FIXES_GameTextShow(MAX_PLAYERS, string, time, style);
				#else
					return CallRemoteFunction__(FIXES_gscGameTextShow, FIXES_gscSpec@isii, MAX_PLAYERS, string, time, style);
				#endif
			}
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GameTextForAll
		#define GameTextForAll( FIXES_GameTextForAll(
	#endif

	#define _ALS_GameTextForAll__
	#define GameTextForAll__( FIXES_GameTextForAll(
#endif

/**
 * <fixes>GameText</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GameTextForPlayer
	#error _ALS_GameTextForPlayer defined
#endif
native BAD_GameTextForPlayer(playerid, const string[], time, style) = GameTextForPlayer;

/**
 * <fixes>GameText</fixes>
 */

#if FIX_GameText
	stock FIXES_GameTextForPlayer(playerid, const string[], time, style)
	{
		if (_FIXES_IN_RANGE(style, 0, FIXES_GT_STYLE_COUNT) && _FIXES_IS_PLAYER_CONNECTED(playerid))
		{
			if (_FIXES_IS_NULL(string))
			{
				#if FIXES_Single
					return _FIXES_HideGameTextTimer(playerid, style);
				#else
					return CallRemoteFunction__(FIXES_gscHideGameTextTimer, FIXES_gscSpec@ii, playerid, style);
				#endif
			}
			else
			{
				#if FIXES_Single
					return _FIXES_GameTextShow(playerid, string, time, style);
				#else
					return CallRemoteFunction__(FIXES_gscGameTextShow, FIXES_gscSpec@isii, playerid, string, time, style);
				#endif
			}
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GameTextForPlayer
		#define GameTextForPlayer( FIXES_GameTextForPlayer(
	#endif

	#define _ALS_GameTextForPlayer__
	#define GameTextForPlayer__( FIXES_GameTextForPlayer(
#endif

/**
 * <fixes>HideGameText</fixes>
 */

#if _FIXES_SAMP && defined _ALS_HideGameTextForAll
	#error _ALS_HideGameTextForAll defined
#endif

#if FIX_HideGameText
	//stock FIXES_HideGameTextForAll(style)
	//{
	//	if (FIXES_gsGTTimer[style][MAX_PLAYERS] != 0)
	//	{
	//		KillTimer__(FIXES_gsGTTimer[style][MAX_PLAYERS]);
	//		FIXES_gsGTTimer[style][MAX_PLAYERS] = 0;
	//	}
	//	return GameTextForAll__(FIXES_gcSpace, 0, style);
	//}

	#define _ALS_HideGameTextForAll
	#define HideGameTextForAll(%0) GameTextForAll(FIXES_gcNull, 0, (%0))
#endif

/**
 * <fixes>HideGameText</fixes>
 */

#if _FIXES_SAMP && defined _ALS_HideGameTextForPlayer
	#error _ALS_HideGameTextForPlayer defined
#endif

#if FIX_HideGameText
	//stock FIXES_HideGameTextForPlayer(playerid, style)
	//{
	//	if (_FIXES_IS_VALID_PLAYER(playerid))
	//	{
	//		if (FIXES_gsGTTimer[style][playerid] != 0)
	//		{
	//			KillTimer__(FIXES_gsGTTimer[style][playerid]);
	//			FIXES_gsGTTimer[style][playerid] = 0;
	//		}
	//		return GameTextForPlayer__(playerid, FIXES_gcSpace, 0, style);
	//	}
	//	return 0;
	//}

	#define _ALS_HideGameTextForPlayer
	#define HideGameTextForPlayer(%0,%1) GameTextForPlayer((%0), FIXES_gcNull, 0, (%1))
#endif

/**
 * <fixes>CreatePlayerTextDraw</fixes>
 * <fixes>CreatePlayerTextDraw_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_CreatePlayerTextDraw
		#error _ALS_CreatePlayerTextDraw defined
	#endif
	native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
#endif

#if FIX_CreatePlayerTextDraw || FIX_CreatePlayerTextDraw_2

	#if FIX_CreatePlayerTextDraw
		#define _FIXES_PASS_STRING(%0(%1,%2,%3,%4)) (_FIXES_IS_NULL(%4) ? %0(%1,%2,%3,FIXES_gsSpace) : %0(%1,%2,%3,%4))
	#else
		#define _FIXES_PASS_STRING(%0) %0
	#endif
	#if FIX_CreatePlayerTextDraw_2
		#define _FIXES_RETURN_STRING(%0) new PlayerText:ret = _FIXES_PASS_STRING(%0)
	#else
		#define _FIXES_RETURN_STRING(%0) return _FIXES_PASS_STRING(%0)
	#endif

	stock PlayerText:FIXES_CreatePlayerTextDraw(playerid, Float:x, Float:y, _FIXES_MAYBE_CONST text[])
	{
		#if FIX_CreatePlayerTextDraw_2
			_FIXES_RTrim(text);
		#endif
			_FIXES_RETURN_STRING(CreatePlayerTextDraw__(playerid, x, y, text));
		#if FIX_CreatePlayerTextDraw_2
			_FIXES_UnTrim(text);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if _FIXES_SAMP
	#if defined _ALS_CreatePlayerTextDraw
		#undef CreatePlayerTextDraw
	#else
		#define _ALS_CreatePlayerTextDraw
	#endif
	#define CreatePlayerTextDraw( FIXES_CreatePlayerTextDraw(
#endif
	#define _ALS_CreatePlayerTextDraw__
	#define CreatePlayerTextDraw__( FIXES_CreatePlayerTextDraw(
#endif

/**
 * <fixes>PlayerTextDrawSetString</fixes>
 * <fixes>PlayerTextDrawSetString_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_PlayerTextDrawSetString
		#error _ALS_PlayerTextDrawSetString defined
	#endif
	native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
#endif

/**
 * <fixes>PlayerTextDrawSetString</fixes>
 * <fixes>PlayerTextDrawSetString_2</fixes>
 */

#if FIX_PlayerTextDrawSetString || FIX_PlayerTextDrawSetString_2

	#if FIX_PlayerTextDrawSetString
		#define _FIXES_PASS_STRING(%0(%2,%3,%4)) (_FIXES_IS_NULL(%4) ? %0(%2,%3,FIXES_gsSpace) : %0(%2,%3,%4))
	#else
		#define _FIXES_PASS_STRING(%0) %0
	#endif
	#if FIX_PlayerTextDrawSetString_2
		#define _FIXES_RETURN_STRING(%0) new ret = _FIXES_PASS_STRING(%0)
	#else
		#define _FIXES_RETURN_STRING(%0) return _FIXES_PASS_STRING(%0)
	#endif

	stock FIXES_PlayerTextDrawSetString(playerid, PlayerText:text, _FIXES_MAYBE_CONST string[])
	{
		#if FIX_PlayerTextDrawSetString_2
			_FIXES_RTrim(string);
		#endif
			_FIXES_RETURN_STRING(PlayerTextDrawSetString__(playerid, text, string));
		#if FIX_PlayerTextDrawSetString_2
			_FIXES_UnTrim(string);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if _FIXES_SAMP
	#if defined _ALS_PlayerTextDrawSetString
		#undef PlayerTextDrawSetString
	#else
		#define _ALS_PlayerTextDrawSetString
	#endif
	#define PlayerTextDrawSetString( FIXES_PlayerTextDrawSetString(
#endif
	#define _ALS_PlayerTextDrawSetString__
	#define PlayerTextDrawSetString__( FIXES_PlayerTextDrawSetString(
#endif

/**
 * <fixes>TextDrawCreate</fixes>
 * <fixes>TextDrawCreate_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_TextDrawCreate
		#error _ALS_TextDrawCreate defined
	#endif
	native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
#endif

#if FIX_TextDrawCreate || FIX_TextDrawCreate_2

	#if FIX_TextDrawCreate
		#define _FIXES_PASS_STRING(%0(%2,%3,%4)) (_FIXES_IS_NULL(%4) ? %0(%2,%3,FIXES_gsSpace) : %0(%2,%3,%4))
	#else
		#define _FIXES_PASS_STRING(%0) %0
	#endif
	#if FIX_TextDrawCreate_2
		#define _FIXES_RETURN_STRING(%0) new Text:ret = _FIXES_PASS_STRING(%0)
	#else
		#define _FIXES_RETURN_STRING(%0) return _FIXES_PASS_STRING(%0)
	#endif

	stock Text:FIXES_TextDrawCreate(Float:x, Float:y, _FIXES_MAYBE_CONST text[])
	{
		#if FIX_TextDrawCreate_2
			_FIXES_RTrim(text);
		#endif
			_FIXES_RETURN_STRING(TextDrawCreate__(x, y, text));
		#if FIX_TextDrawCreate_2
			_FIXES_UnTrim(text);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if _FIXES_SAMP
	#if defined _ALS_TextDrawCreate
		#undef TextDrawCreate
	#else
		#define _ALS_TextDrawCreate
	#endif
	#define TextDrawCreate( FIXES_TextDrawCreate(
#endif
	#define _ALS_TextDrawCreate__
	#define TextDrawCreate__( FIXES_TextDrawCreate(
#endif

/**
 * <fixes>TextDrawSetString</fixes>
 * <fixes>TextDrawSetString_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_TextDrawSetString
		#error _ALS_TextDrawSetString defined
	#endif
	native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
#endif

/**
 * <fixes>TextDrawSetString</fixes>
 * <fixes>TextDrawSetString_2</fixes>
 */

#if FIX_TextDrawSetString || FIX_TextDrawSetString_2

	#if FIX_TextDrawSetString
		#define _FIXES_PASS_STRING(%0(%3,%4)) (_FIXES_IS_NULL(%4) ? %0(%3,FIXES_gsSpace) : %0(%3,%4))
	#else
		#define _FIXES_PASS_STRING(%0) %0
	#endif
	#if FIX_TextDrawSetString_2
		#define _FIXES_RETURN_STRING(%0) new ret = _FIXES_PASS_STRING(%0)
	#else
		#define _FIXES_RETURN_STRING(%0) return _FIXES_PASS_STRING(%0)
	#endif

	stock FIXES_TextDrawSetString(Text:text, _FIXES_MAYBE_CONST string[])
	{
		#if FIX_TextDrawSetString_2
			_FIXES_RTrim(string);
		#endif
			_FIXES_RETURN_STRING(TextDrawSetString__(text, string));
		#if FIX_TextDrawSetString_2
			_FIXES_UnTrim(string);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if _FIXES_SAMP
	#if defined _ALS_TextDrawSetString
		#undef TextDrawSetString
	#else
		#define _ALS_TextDrawSetString
	#endif
	#define TextDrawSetString( FIXES_TextDrawSetString(
#endif
	#define _ALS_TextDrawSetString__
	#define TextDrawSetString__( FIXES_TextDrawSetString(
#endif

/**
 * <fixes>AllowInteriorWeapons</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AllowInteriorWeapons
	#error _ALS_AllowInteriorWeapons defined
#endif
native BAD_AllowInteriorWeapons(allow) = AllowInteriorWeapons;

/**
 * <fixes>AllowInteriorWeapons</fixes>
 */

#if FIX_AllowInteriorWeapons
	#if FIXES_Single
		stock FIXES_AllowInteriorWeapons(allow)
		{
			if (allow)
			{
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_INTERIOR;
				_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
				{
					FIXES_gsPlayerBools[i] &= ~e_FIXES_BOOLS_INTERIOR;
				}
			}
			else
			{
				FIXES_gsSettings |= e_FIXES_SETTINGS_INTERIOR;
				_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
				{
					if (GetPlayerInterior__(i))
					{
						FIXES_gsPlayerBools[i] |= e_FIXES_BOOLS_INTERIOR;
					}
				}
			}
			return allow;
		}
	#else
		forward _FIXES_AllowInteriorWeapons(allow);

		stock FIXES_AllowInteriorWeapons(allow)
		{
			CallRemoteFunction__(FIXES_gscAllowInteriorWeapons, FIXES_gscSpec@i, allow);
			return allow;
		}

		public _FIXES_AllowInteriorWeapons(allow)
		{
			if (allow)
			{
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_INTERIOR;
				_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
				{
					FIXES_gsPlayerBools[i] &= ~e_FIXES_BOOLS_INTERIOR;
				}
			}
			else
			{
				FIXES_gsSettings |= e_FIXES_SETTINGS_INTERIOR;
				_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
				{
					if (GetPlayerInterior__(i))
					{
						FIXES_gsPlayerBools[i] |= e_FIXES_BOOLS_INTERIOR;
					}
				}
			}
			return allow;
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_AllowInteriorWeapons
		#define AllowInteriorWeapons( FIXES_AllowInteriorWeapons(
	#endif

	#define _ALS_AllowInteriorWeapons__
	#define AllowInteriorWeapons__( FIXES_AllowInteriorWeapons(
#endif

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerInterior
	#error _ALS_GetPlayerInterior defined
#endif
native BAD_GetPlayerInterior(playerid) = GetPlayerInterior;

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if FIX_GetPlayerInterior
	stock FIXES_GetPlayerInterior(playerid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			return FIXES_GET(PlayerInterior, playerid);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerInterior
		#define GetPlayerInterior( FIXES_GetPlayerInterior(
	#endif

	#define _ALS_GetPlayerInterior__
	#define GetPlayerInterior__( FIXES_GetPlayerInterior(
#endif

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerInterior
	#error _ALS_SetPlayerInterior defined
#endif
native BAD_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if FIX_GetPlayerInterior
	stock FIXES_SetPlayerInterior(playerid, interiorid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			FIXES_SET(PlayerInterior, playerid, interiorid);
			return SetPlayerInterior__(playerid, interiorid);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerInterior
		#define SetPlayerInterior( FIXES_SetPlayerInterior(
	#endif

	#define _ALS_SetPlayerInterior__
	#define SetPlayerInterior__( FIXES_SetPlayerInterior(
#endif

/**
 * <fixes>AllowTeleport</fixes>
 */

#if FIX_AllowTeleport && !defined FILTERSCRIPT
	forward _FIXES_AllowTeleport(playerid, allow);

	public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
	{
		// ======================
		//  BEGIN: AllowTeleport
		// ======================
		#if FIX_AllowTeleport
			if (!_FIXES_gIsFilterscript)
			{
				// Unusually, the call order here is always Game Mode first -
				// most callbacks are Filter Script first.
				if ((FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_TELEPORT) || ((FIXES_gsSettings & e_FIXES_SETTINGS_ADMIN_TELEPORT) && (IsPlayerAdmin__(playerid))))
				{
					SetPlayerPosFindZ__(playerid, fX, fY, fZ);
				}
			}
		#endif
		// ======================
		//  END:   AllowTeleport
		// ======================
		return FIXES_OnPlayerClickMap(playerid, fX, fY, fZ);
	}

	#if defined _ALS_OnPlayerClickMap
		#error _ALS_OnPlayerClickMap defined
	#endif
	#define _ALS_OnPlayerClickMap
	#define OnPlayerClickMap(%0) FIXES_OnPlayerClickMap(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
#endif

/**
 * <fixes>AllowTeleport</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AllowPlayerTeleport
	#error _ALS_AllowPlayerTeleport defined
#endif
native BAD_AllowPlayerTeleport(playerid, allow) = AllowPlayerTeleport;

/**
 * <fixes>AllowTeleport</fixes>
 */

#if FIX_AllowTeleport
	#if FIXES_Single
		stock FIXES_AllowPlayerTeleport(playerid, allow)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				if (allow)
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_TELEPORT;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_TELEPORT;
				}
			}
			return 0;
		}
	#else
		stock FIXES_AllowPlayerTeleport(playerid, allow)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				CallRemoteFunction__(FIXES_gscAllowTeleport, FIXES_gscSpec@ii, playerid, allow);
			}
			return 0;
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_AllowPlayerTeleport
		#define AllowPlayerTeleport( FIXES_AllowPlayerTeleport(
	#endif

	#define _ALS_AllowPlayerTeleport__
	#define AllowPlayerTeleport__( FIXES_AllowPlayerTeleport(
#endif

/**
 * <fixes>AllowTeleport</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AllowAdminTeleport
	#error _ALS_AllowAdminTeleport defined
#endif
native BAD_AllowAdminTeleport(allow) = AllowAdminTeleport;

/**
 * <fixes>AllowTeleport</fixes>
 */

#if FIX_AllowTeleport
	#if FIXES_Single
		stock FIXES_AllowAdminTeleport(allow)
		{
			if (allow)
			{
				FIXES_gsSettings |= e_FIXES_SETTINGS_ADMIN_TELEPORT;
			}
			else
			{
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_ADMIN_TELEPORT;
			}
			return allow;
		}
	#else
		stock FIXES_AllowAdminTeleport(allow)
		{
			return
				CallRemoteFunction__(FIXES_gscAllowTeleport, FIXES_gscSpec@ii, INVALID_PLAYER_ID, allow),
				allow;
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_AllowAdminTeleport
		#define AllowAdminTeleport( FIXES_AllowAdminTeleport(
	#endif

	#define _ALS_AllowAdminTeleport__
	#define AllowAdminTeleport__( FIXES_AllowAdminTeleport(
#endif

/**
 * <fixes>AllowTeleport</fixes>
 */

#if FIX_AllowTeleport && !defined FILTERSCRIPT && !FIXES_Single
	public _FIXES_AllowTeleport(playerid, allow)
	{
		if (!_FIXES_gIsFilterscript)
		{
			if (playerid == INVALID_PLAYER_ID)
			{
				if (allow)
				{
					FIXES_gsSettings |= e_FIXES_SETTINGS_ADMIN_TELEPORT;
				}
				else
				{
					FIXES_gsSettings &= ~e_FIXES_SETTINGS_ADMIN_TELEPORT;
				}
			}
			else
			{
				if (allow)
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_TELEPORT;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_TELEPORT;
				}
			}
		}
	}
#endif

/**
 * <fixes>SetPlayerSpecialAction</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerSpecialAction
	#error _ALS_SetPlayerSpecialAction defined
#endif
native BAD_SetPlayerSpecialAction(playerid, actionid) = SetPlayerSpecialAction;

/**
 * <fixes>SetPlayerSpecialAction</fixes>
 */

#if FIX_SetPlayerSpecialAction
	stock FIXES_SetPlayerSpecialAction(playerid, actionid)
	{
		if (GetPlayerSpecialAction__(playerid) == SPECIAL_ACTION_USEJETPACK)
		{
			ClearAnimations__(playerid);
		}
		SetPlayerSpecialAction__(playerid, actionid);
		return 1;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerSpecialAction
		#define SetPlayerSpecialAction( FIXES_SetPlayerSpecialAction(
	#endif

	#define _ALS_SetPlayerSpecialAction__
	#define SetPlayerSpecialAction__( FIXES_SetPlayerSpecialAction(
#endif

/**
 * <fixes>ClearAnimations</fixes>
 */

#if _FIXES_SAMP && defined _ALS_ClearAnimations
	#error _ALS_ClearAnimations defined
#endif
native BAD_ClearAnimations(playerid, forcesync = 0) = ClearAnimations;

/**
 * <fixes>ClearAnimations</fixes>
 */

#if FIX_ClearAnimations || FIX_ClearAnimations_2
	stock FIXES_ClearAnimations(playerid, forcesync = 0)
	{
		#if FIX_ClearAnimations || FIX_ClearAnimations_2
			if (IsPlayerInAnyVehicle__(playerid))
		#endif
		#if FIX_ClearAnimations
			{
				return ApplyAnimation__(playerid, "PED", "CAR_SIT", 4.0, 0, 0, 0, 0, 1, forcesync);
			}
		#endif
		#if FIX_ClearAnimations + FIX_ClearAnimations_2 == 1 // XOR
			{
				return ClearAnimations__(playerid, forcesync);
			}
		#endif
		#if FIX_ClearAnimations_2
			new
				ret = ClearAnimations__(playerid, forcesync);
			ApplyAnimation__(playerid, "PED", "IDLE_STANCE", 4.0, 0, 0, 0, 0, 1, forcesync);
			ApplyAnimation__(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 1, forcesync);
			ApplyAnimation__(playerid, "PED", "WALK_PLAYER", 4.0, 0, 0, 0, 0, 1, forcesync);
			return ret;
		#endif
	}

	#if _FIXES_SAMP
		#define _ALS_ClearAnimations
		#define ClearAnimations( FIXES_ClearAnimations(
	#endif

	#define _ALS_ClearAnimations__
	#define ClearAnimations__( FIXES_ClearAnimations(
#endif

/**
 * <fixes>GangZoneCreate</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GangZoneCreate
	#error _ALS_GangZoneCreate defined
#endif
native BAD_GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy) = GangZoneCreate;

/**
 * <fixes>GangZoneCreate</fixes>
 */

#if FIX_GangZoneCreate
	stock FIXES_GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy)
	{
		return GangZoneCreate__(floatsub(minx, floatfract(minx)), floatsub(miny, floatfract(miny)), floatsub(maxx, floatfract(maxx)), floatsub(maxy, floatfract(maxy)));
	}

	#if _FIXES_SAMP
		#define _ALS_GangZoneCreate
		#define GangZoneCreate( FIXES_GangZoneCreate(
	#endif

	#define _ALS_GangZoneCreate__
	#define GangZoneCreate__( FIXES_GangZoneCreate(
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_ShowPlayerDialog
		#error _ALS_ShowPlayerDialog defined
	#endif
	native BAD_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[]) = ShowPlayerDialog;
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if FIX_OnDialogResponse || FIX_GetPlayerDialog || FIX_BypassDialog
	stock FIXES_ShowPlayerDialog(playerid, dialog, style, _FIXES_MAYBE_CONST title[], _FIXES_MAYBE_CONST caption[], _FIXES_MAYBE_CONST button1[], _FIXES_MAYBE_CONST button2[])
	{
		#if FIX_OnDialogResponse || FIX_GetPlayerDialog
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			FIXES_SET(PlayerDialog, playerid, dialog);
		#endif
		#if FIX_BypassDialog
			#if FIXES_Single
				FIXES_BlockUpdate(playerid, false, e_FIXES_BOOLS_DIALOG_BLOCK);
			#else
				CallRemoteFunction__(FIXES_gscBlockUpdate, FIXES_gscSpec@ii, playerid, true);
			#endif
		#endif
				return ShowPlayerDialog__(playerid, dialog, style, title, caption, button1, button2);
		#if FIX_OnDialogResponse || FIX_GetPlayerDialog
		}
		return 0;
		#endif
	}

	#if _FIXES_SAMP
	#if defined _ALS_ShowPlayerDialog
		#undef ShowPlayerDialog
	#else
		#define _ALS_ShowPlayerDialog
	#endif
	#define ShowPlayerDialog( FIXES_ShowPlayerDialog(
#endif
	#define _ALS_ShowPlayerDialog__
	#define ShowPlayerDialog__( FIXES_ShowPlayerDialog(
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if FIX_OnDialogResponse || FIX_GetPlayerDialog || FIX_BypassDialog
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
	{
		// =========================
		//  BEGIN: OnDialogResponse
		// =========================
		#if FIX_OnDialogResponse || FIX_GetPlayerDialog || FIX_BypassDialog
			#if FIXES_Single
				#if FIX_OnDialogResponse
					dialogid = FIXES_gsPlayerDialog[playerid];
				#endif
				#if FIX_OnDialogResponse || FIX_GetPlayerDialog
				FIXES_gsPlayerDialog[playerid] = INVALID_DIALOG_ID;
				#endif
				#if FIX_BypassDialog
					if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DIALOG_BLOCK)
					{
						FIXES_gsPlayerBools[playerid] &= ~(e_FIXES_BOOLS_BLOCK | e_FIXES_BOOLS_DIALOG_BLOCK);
					}
					else
					{
						return 0;
					}
				#endif
			#else
				#if FIX_OnDialogResponse || FIX_BypassDialog
				_FIXES_IS_IN_CHARGE()
				{
						#if FIX_BypassDialog
							if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DIALOG_BLOCK)
							{
								CallRemoteFunction__(FIXES_gscBlockUpdate, FIXES_gscSpec@ii, playerid, false);
							}
							else
							{
								return 0;
							}
						#endif
						#if FIX_OnDialogResponse
					// If there are multiple scripts, we can't just wipe the
					// current dialog data or subsequent scripts will display
					// the wrong value.
							dialogid = GetPVarInt__(playerid, FIXES_pvarPlayerDialog),
							SetPVarInt__(playerid, FIXES_pvarCurrentDialog, dialogid),
							SetPVarInt__(playerid, FIXES_pvarPlayerDialog, INVALID_DIALOG_ID);
				}
				else
				{
							dialogid = GetPVarInt__(playerid, FIXES_pvarCurrentDialog);
						#endif
				}
			#endif
				#if !FIX_OnDialogResponse && FIX_GetPlayerDialog
					SetPVarInt__(playerid, FIXES_pvarPlayerDialog, INVALID_DIALOG_ID);
				#endif
			#endif
			return FIXES_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
		#endif
		// =========================
		//  END:   OnDialogResponse
		// =========================
	}

	#if defined _ALS_OnDialogResponse
		#error _ALS_OnDialogResponse defined
	#endif
	#define _ALS_OnDialogResponse
	#define OnDialogResponse(%0) FIXES_OnDialogResponse(%0) <_ALS : _ALS_go>

	_FIXES_FORWARD FIXES_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

/**
 * <fixes>GetPlayerDialog</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerDialog
	#error _ALS_GetPlayerDialog defined
#endif

#if FIX_GetPlayerDialog
	stock FIXES_GetPlayerDialog(playerid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			return FIXES_GET(PlayerDialog, playerid);
		}
		return INVALID_DIALOG_ID;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerDialog
		#define GetPlayerDialog( FIXES_GetPlayerDialog(
	#endif

	#define _ALS_GetPlayerDialog__
	#define GetPlayerDialog__( FIXES_GetPlayerDialog(
#endif

/**
 * <fixes>valstr</fixes>
 */

#if _FIXES_SAMP && defined _ALS_valstr
	#error _ALS_valstr defined
#endif
native BAD_valstr(dest[], value, bool:pack = false) = valstr;

/**
 * <fixes>valstr</fixes>
 */

#if FIX_valstr
	stock FIXES_valstr(dest[], value, bool:pack = false)
	{
		// "format" can't handle cellmin properly.
		static const
			sc_szCellmin[] = !"-2147483648";
		if (value == cellmin)
		{
			pack && strpack(dest, sc_szCellmin, 12) || strunpack(dest, sc_szCellmin, 12);
		}
		else
		{
			format(dest, 12, "%d", value),
			pack && strpack(dest, dest, 12);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_valstr
		#define valstr( FIXES_valstr(
	#endif

	#define _ALS_valstr__
	#define valstr__( FIXES_valstr(
#endif

/**
 * <fixes>fclose</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fclose
	#error _ALS_fclose defined
#endif
native BAD_fclose(File:handle) = fclose;

/**
 * <fixes>fclose</fixes>
 */

#if FIX_fclose
	stock bool:FIXES_fclose(File:handle)
	{
		return handle && fclose(handle);
	}

	#if _FIXES_SAMP
		#define _ALS_fclose
		#define fclose( FIXES_fclose(
	#endif

	#define _ALS_fclose__
	#define fclose__( FIXES_fclose(
#endif

/**
 * <fixes>fwrite</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fwrite
	#error _ALS_fwrite defined
#endif
native BAD_fwrite(File:handle, const string[]) = fwrite;

/**
 * <fixes>fwrite</fixes>
 */

#if FIX_fwrite
	stock FIXES_fwrite(File:handle, const string[])
	{
		return handle ? fwrite(handle, string) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_fwrite
		#define fwrite( FIXES_fwrite(
	#endif

	#define _ALS_fwrite__
	#define fwrite__( FIXES_fwrite(
#endif

/**
 * <fixes>fread</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fread
	#error _ALS_fread defined
#endif
native BAD_fread(File:handle, string[], size = sizeof (string), bool:pack = false) = fread;

/**
 * <fixes>fread</fixes>
 */

#if FIX_fread
	stock FIXES_fread(File:handle, string[], size = sizeof (string), bool:pack = false)
	{
		return handle ? fread(handle, string, size, pack) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_fread
		#define fread( FIXES_fread(
	#endif

	#define _ALS_fread__
	#define fread__( FIXES_fread(
#endif

/**
 * <fixes>fputchar</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fputchar
	#error _ALS_fputchar defined
#endif
native BAD_fputchar(File:handle, value, bool:utf8 = true) = fputchar;

/**
 * <fixes>fputchar</fixes>
 */

#if FIX_fputchar
	stock bool:FIXES_fputchar(File:handle, value, bool:utf8 = true)
	{
		return handle && fputchar(handle, value, utf8);
	}

	#if _FIXES_SAMP
		#define _ALS_fputchar
		#define fputchar( FIXES_fputchar(
	#endif

	#define _ALS_fputchar__
	#define fputchar__( FIXES_fputchar(
#endif

/**
 * <fixes>fgetchar</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fgetchar
	#error _ALS_fgetchar defined
#endif
native BAD_fgetchar(File:handle, value, bool:utf8 = true) = fgetchar;

/**
 * <fixes>fgetchar</fixes>
 */

#if FIX_fgetchar
	stock FIXES_fgetchar(File:handle, value, bool:utf8 = true)
	{
		return handle ? fgetchar(handle, value, utf8) : '\0';
	}

	#if _FIXES_SAMP
		#define _ALS_fgetchar
		#define fgetchar( FIXES_fgetchar(
	#endif

	#define _ALS_fgetchar__
	#define fgetchar__( FIXES_fgetchar(
#endif

/**
 * <fixes>fblockwrite</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fblockwrite
	#error _ALS_fblockwrite defined
#endif
native BAD_fblockwrite(File:handle, const buffer[], size = sizeof (buffer)) = fblockwrite;

/**
 * <fixes>fblockwrite</fixes>
 */

#if FIX_fblockwrite
	stock FIXES_fblockwrite(File:handle, const buffer[], size = sizeof (buffer))
	{
		return handle ? fblockwrite(handle, buffer, size) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_fblockwrite
		#define fblockwrite( FIXES_fblockwrite(
	#endif

	#define _ALS_fblockwrite__
	#define fblockwrite__( FIXES_fblockwrite(
#endif

/**
 * <fixes>fblockread</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fblockread
	#error _ALS_fblockread defined
#endif
native BAD_fblockread(File:handle, buffer[], size = sizeof (buffer)) = fblockread;

/**
 * <fixes>fblockread</fixes>
 */

#if FIX_fblockread
	stock FIXES_fblockread(File:handle, buffer[], size = sizeof (buffer))
	{
		return handle ? fblockread(handle, buffer, size) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_fblockread
		#define fblockread( FIXES_fblockread(
	#endif

	#define _ALS_fblockread__
	#define fblockread__( FIXES_fblockread(
#endif

/**
 * <fixes>fseek</fixes>
 */

#if _FIXES_SAMP && defined _ALS_fseek
	#error _ALS_fseek defined
#endif
native BAD_fseek(File:handle, position = 0, seek_whence:whence = seek_start) = fseek;

/**
 * <fixes>fseek</fixes>
 */

#if FIX_fseek
	stock FIXES_fseek(File:handle, position = 0, seek_whence:whence = seek_start)
	{
		return handle ? fseek(handle, position, whence) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_fseek
		#define fseek( FIXES_fseek(
	#endif

	#define _ALS_fseek__
	#define fseek__( FIXES_fseek(
#endif

/**
 * <fixes>flength</fixes>
 */

#if _FIXES_SAMP && defined _ALS_flength
	#error _ALS_flength defined
#endif
native BAD_flength(File:handle) = flength;

/**
 * <fixes>flength</fixes>
 */

#if FIX_flength
	stock FIXES_flength(File:handle)
	{
		return handle ? flength(handle) : 0;
	}

	#if _FIXES_SAMP
		#define _ALS_flength
		#define flength( FIXES_flength(
	#endif

	#define _ALS_flength__
	#define flength__( FIXES_flength(
#endif

/**
 * <fixes>Kick</fixes>
 */

#if _FIXES_SAMP && defined _ALS_Kick
	#error _ALS_Kick defined
#endif
native BAD_Kick(playerid) = Kick;

/**
 * <fixes>Kick</fixes>
 */

#if FIX_Kick
	forward _FIXES_Kick(playerid);

	public _FIXES_Kick(playerid)
	{
		FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_KICKED,
		Kick__(playerid);
	}

	#if !FIXES_Single
		forward @FIXES_Kick(playerid);

		public @FIXES_Kick(playerid)
		{
			FIXES_BlockUpdate(playerid, false);
		}
	#endif

	stock FIXES_Kick(playerid)
	{
		if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_ON_PLAYER_CONNECT)
		{
			// Disable as much of the server as possible quickly.
			return
				#if FIXES_Single
					FIXES_BlockUpdate(playerid, false),
				#else
					CallRemoteFunction__("@FIXES_Kick", "i", playerid),
				#endif
					TogglePlayerSpectating__(playerid, true),
					TogglePlayerControllable__(playerid, false),
					SetPVarInt__(playerid, FIXES_pvarKick, SetTimerEx__(FIXES_gscKick, 1000, 0, FIXES_gscSpec@i, playerid)),
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_KICKED,
					1;
		}
		else
		{
			return Kick__(playerid);
		}
	}

	#if _FIXES_SAMP
		#define _ALS_Kick
		#define Kick( FIXES_Kick(
	#endif

	#define _ALS_Kick__
	#define Kick__( FIXES_Kick(
#endif

/**
 * <remarks>
 * Figure out which the first filterscript to be called is so that it can do the
 * majority of the work.  More detail:  Several pieces of code for some fixes
 * rely on things like blocking <symbolref name="OnPlayerUpdate" />.  This
 * should be done in the first script in which
 * <symbolref name="OnPlayerUpdate" /> is called only, so we need to find out
 * in advance which script will be called first (at least out of all the fixed
 * scripts).
 * </remarks>
 */

#if !FIXES_Single
	public _FIXES_DetermineOrder()
	{
		// TODO: Graceful handoff.  I thought I was past all this rubbish!
		if (!_FIXES_gIsFilterscript)
		{
			if (existproperty(5, FIXES_gscNoGMProperty))
			{
				return 0;
			}
			// Make sure certain data is synced with what the GM thinks it is.
			// =============================
			//  BEGIN: AllowInteriorWeapons
			// =============================
			#if FIX_AllowInteriorWeapons
				CallRemoteFunction__(FIXES_gscAllowInteriorWeapons, FIXES_gscSpec@i, !(FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR));
			#endif
			// =============================
			//  END: AllowInteriorWeapons
			// =============================
		}
		if (existproperty(5, FIXES_gscOrderProperty))
		{
			// Either this is a Filter Script (1) and we don't want gamemodes
			// (1) or this isn't a filterscript (0) and we do want gamemodes
			// (0).  All other cases return here due to a logic mismatch.  This
			// is to rectify the difference in call orders between
			// "CallRemoteFunction" and normal callbacks.  Now DOESN'T end on
			// the second time round for filterscripts to correctly pass on the
			// data to GameModes.
			if (!existproperty(5, FIXES_gscNoGMProperty) && _FIXES_gIsFilterscript == bool:getproperty(5, FIXES_gscOrderProperty))
			{
				// The game mode is not in charge, which means we are checking
				// the filterscripts a second time and shouldn't be.
				return 0;
			}
			// If this script was previously the owner, and we are not ending
			// the game mode (in which case discard all data), and if we are
			// only dealing with filterscripts or the gamemode is now the
			// master.
			if (FIXES_gsSettings & (e_FIXES_SETTINGS_IN_CHARGE | e_FIXES_SETTINGS_DROP_ALL_DATA) == e_FIXES_SETTINGS_IN_CHARGE)
			{
				FIXES_PRINTF("_FIXES_DetermineOrder: Was in charge");
				// This script is currently in charge, but a new script has
				// usurped it!  Pass all relevant data over to the new script.
				// Also, this wasn't triggered by a game mode change (where we
				// just want to dump and reset all data).  There is no need to
				// reset the admin teleport data as that is always handled by
				// the Game Mode, so it will either be correct, or it will be
				// blank.
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_IN_CHARGE;
				#if FIX_PutPlayerInVehicle || FIX_GameText || FIX_TogglePlayerControllable
					_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
					{
						// =================
						//  BEGIN: GameText
						// =================
						#if FIX_GameText
							for (new j = 0; j != FIXES_GT_STYLE_COUNT; ++j)
							{
								PlayerTextDrawDestroy__(i, FIXES_gsPGTStyle[i][j]);
							}
						#endif
						// =================
						//  END:   GameText
						// =================

						// =================================
						//  BEGIN: TogglePlayerControllable
						// =================================
						#if FIX_TogglePlayerControllable
							CallRemoteFunction__(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, i, !(FIXES_gsPlayerBools[i] & e_FIXES_BOOLS_UNCONTROLLABLE));
						#endif
						// =================================
						//  END:   TogglePlayerControllable
						// =================================

						// ===========================
						//  BEGIN: PutPlayerInVehicle
						// ===========================
						#if FIX_PutPlayerInVehicle
							if (FIXES_gsPlayerBools[i] & e_FIXES_BOOLS_PUT_IN_VEHICLE)
							{
								CallRemoteFunction__(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iii, i, FIXES_gsVehicleSeatData[i] & 0x00FFFFFF, FIXES_gsVehicleSeatData[i] >>> 24);
							}
						#endif
						// ===========================
						//  END:   PutPlayerInVehicle
						// ===========================
					}
				#endif

				// =================
				//  BEGIN: GameText
				// =================
				#if FIX_GameText
					#if FIX_GameTextStyles
						TextDrawDestroy__(FIXES_gsGTStyle[13]),
						TextDrawDestroy__(FIXES_gsGTStyle[12]),
						TextDrawDestroy__(FIXES_gsGTStyle[11]),
						TextDrawDestroy__(FIXES_gsGTStyle[10]),
						TextDrawDestroy__(FIXES_gsGTStyle[9]),
						TextDrawDestroy__(FIXES_gsGTStyle[8]),
						TextDrawDestroy__(FIXES_gsGTStyle[7]),
					#endif
						TextDrawDestroy__(FIXES_gsGTStyle[6]),
						TextDrawDestroy__(FIXES_gsGTStyle[5]),
						TextDrawDestroy__(FIXES_gsGTStyle[4]),
						TextDrawDestroy__(FIXES_gsGTStyle[3]),
						TextDrawDestroy__(FIXES_gsGTStyle[2]),
						TextDrawDestroy__(FIXES_gsGTStyle[1]),
						TextDrawDestroy__(FIXES_gsGTStyle[0]);
				#endif
				// =================
				//  END:   GameText
				// =================

				FIXES_PRINTF("_FIXES_DetermineOrder: Not in charge");
				return 0;
			}
			else
			{
				FIXES_gsSettings &= ~e_FIXES_SETTINGS_IN_CHARGE;
				FIXES_PRINTF("_FIXES_DetermineOrder: Not in charge");
				return 0;
			}
		}
		else if (!(FIXES_gsSettings & e_FIXES_SETTINGS_ENDING))
		{
			setproperty(5, FIXES_gscOrderProperty, _FIXES_gIsFilterscript);
			#if FIXES_Debug
				if (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE)
				{
					FIXES_PRINTF("_FIXES_DetermineOrder: Already in charge");
				}
			#endif
			FIXES_gsSettings |= e_FIXES_SETTINGS_IN_CHARGE;
			FIXES_PRINTF("_FIXES_DetermineOrder: Now in charge");

			// =================
			//  BEGIN: GameText
			// =================
			#if FIX_GameText
				// Create all the relevant TextDraws.
				_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
				{
					_FIXES_CreateGameTextDraws(playerid);
				}
				_FIXES_CreateGameTextDraws(INVALID_PLAYER_ID);
			#endif
			// =================
			//  END:   GameText
			// =================
			return 1;
		}
		else if (!(FIXES_gsSettings & e_FIXES_SETTINGS_ENDED))
		{
			// Only called when a filterscript that is currently master (and
			// thus called first by "CallRemoteFunction") ends.  This doesn't
			// get triggered when a gamemode is master, but that doesn't matter
			// because in that case all the textdraws are destroyed anyway.

			// =================
			//  BEGIN: GameText
			// =================
			#if FIX_GameText
					// Destroy all the relevant TextDraws.
					_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
					{
						#if FIX_GameTextStyles
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy__(playerid, FIXES_gsPGTStyle[playerid][0]);
					}
				#if FIX_GameTextStyles
					TextDrawDestroy__(FIXES_gsGTStyle[13]),
					TextDrawDestroy__(FIXES_gsGTStyle[12]),
					TextDrawDestroy__(FIXES_gsGTStyle[11]),
					TextDrawDestroy__(FIXES_gsGTStyle[10]),
					TextDrawDestroy__(FIXES_gsGTStyle[9]),
					TextDrawDestroy__(FIXES_gsGTStyle[8]),
					TextDrawDestroy__(FIXES_gsGTStyle[7]),
				#endif
					TextDrawDestroy__(FIXES_gsGTStyle[6]),
					TextDrawDestroy__(FIXES_gsGTStyle[5]),
					TextDrawDestroy__(FIXES_gsGTStyle[4]),
					TextDrawDestroy__(FIXES_gsGTStyle[3]),
					TextDrawDestroy__(FIXES_gsGTStyle[2]),
					TextDrawDestroy__(FIXES_gsGTStyle[1]),
					TextDrawDestroy__(FIXES_gsGTStyle[0]);
			#endif
			// =================
			//  END:   GameText
			// =================

			#if FIXES_Debug
				FIXES_PRINTF("_FIXES_DetermineOrder: Ending");
			#endif

			FIXES_gsSettings |= e_FIXES_SETTINGS_ENDED;
		}
		return 0;
	}
#endif

/**
 * <fixes>strins</fixes>
 */

#if _FIXES_SAMP && defined _ALS_strins
	#error _ALS_strins defined
#endif
native BAD_strins(string[], const substr[], pos, maxlength = sizeof string) = strins;

/**
 * <fixes>strins</fixes>
 */

#if FIX_strins
	stock FIXES_strins(string[], const substr[], pos, maxlength = sizeof string)
	{
		if (string[0] > 255)
		{
			new
				strlength = strlen(string),
				sublength = strlen(substr),
				m4 = maxlength * 4;
			// Packed - format doesn't like these strings.
			if (strlength + sublength >= m4)
			{
				if (pos + sublength >= m4)
				{
					return
						string{pos} = '\0',
						// Hopefully this doesn't ignore maxlength and does packed.
						strcat(string, substr, maxlength);
				}
				else
				{
					// pos + sublength is less than maxlength, so this sum MUST
					// be positive and gte than "pos", so there's no need for
					// additional checks.
					string{maxlength - sublength - 1} = '\0';
				}
			}
			return strins(string, substr, pos, maxlength);
		}
		else if (substr[0] > 255)
		{
			new
				strlength = strlen(string),
				sublength = strlen(substr);
			// Packed - format doesn't like these strings.
			if (strlength + sublength >= maxlength)
			{
				if (pos + sublength >= maxlength)
				{
					return
						string[pos] = '\0',
						// Hopefully this doesn't ignore maxlength and does packed.
						strcat(string, substr, maxlength);
				}
				else
				{
					// pos + sublength is less than maxlength, so this sum MUST
					// be positive and gte than "pos", so there's no need for
					// additional checks.
					string[maxlength - sublength - 1] = '\0';
				}
			}
			return strins(string, substr, pos, maxlength);
		}
		else
		{
			return format(string, maxlength, "%.*s%s%s", pos, string, substr, string[pos]);
		}
	}

	#if _FIXES_SAMP
		#define _ALS_strins
		#define strins( FIXES_strins(
	#endif

	#define _ALS_strins__
	#define strins__( FIXES_strins(
#endif

/**
 * <fixes>ApplyAnimation_2</fixes>
 */

#if FIX_ApplyAnimation_2
	static stock _FIXES_ApplyAnimationDelay(const animname[], playerid, idx, Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0)
	{
		if (FIXES_gsPlayerAnimTimer[playerid])
		{
			KillTimer__(FIXES_gsPlayerAnimTimer[playerid]),
			FIXES_gsPlayerAnimTimer[playerid] = 0;
		}
		if (FIXES_gsPlayerAnimLibs[playerid][idx >>> 5] & (1 << (idx & 0x1F)))
		{
			FIXES_gsPlayerAnimLibs[playerid][idx >>> 5] &= ~(1 << (idx & 0x1F)),
			FIXES_gsPlayerAnimName[playerid << 6] = '\0',
			strcat(FIXES_gsPlayerAnimName[playerid << 6], animname, 64),
			FIXES_gsPlayerAnimTimer[playerid] = SetTimerEx__("_FIXES_ApplyAnimation", 350, false, "ddfdddddd", playerid, idx, fDelta, loop, lockx, locky, freeze, time, forcesync);
		}
	}
#endif

/**
 * <fixes>ApplyAnimation_2</fixes>
 */

#if FIX_ApplyAnimation_2
	forward _FIXES_ApplyAnimation(playerid, animlib, Float:fDelta, loop, lockx, locky, freeze, time, forcesync);

	public _FIXES_ApplyAnimation(playerid, animlib, Float:fDelta, loop, lockx, locky, freeze, time, forcesync)
	{
		ApplyAnimation__(playerid, FIXES_gscAnimLib[animlib], FIXES_gsPlayerAnimName[playerid << 6], fDelta, loop, lockx, locky, freeze, time, forcesync),
		FIXES_gsPlayerAnimTimer[playerid] = 0;
	}
#endif

/**
 * <fixes>ApplyAnimation</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_ApplyAnimation
		#error _ALS_ApplyAnimation defined
	#endif
	native BAD_ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
#endif

/**
 * <fixes>ApplyAnimation</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 */

#if FIX_ApplyAnimation || FIX_ApplyAnimation_2
	stock FIXES_ApplyAnimation(playerid, _FIXES_MAYBE_CONST animlib[], _FIXES_MAYBE_CONST animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0)
	{
		new
			idx = _FIXES_GetAnimLibIndex(animlib);

		if (~idx) // != -1
		{
			#if FIX_ApplyAnimation_2
				_FIXES_ApplyAnimationDelay(animname, playerid, idx, fDelta, loop, lockx, locky, freeze, time, forcesync);
			#endif
				return ApplyAnimation__(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
		}

		return 0;
	}

	#if _FIXES_SAMP
	#if defined _ALS_ApplyAnimation
		#undef ApplyAnimation
	#else
		#define _ALS_ApplyAnimation
	#endif
	#define ApplyAnimation( FIXES_ApplyAnimation(
#endif
	#define _ALS_ApplyAnimation__
	#define ApplyAnimation__( FIXES_ApplyAnimation(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation_2
	static stock _FIXES_ApplyActorAnimationDelay(const animname[], actorid, idx, Float:fDelta, loop, lockx, locky, freeze, time)
	{
		if (FIXES_gsActorAnimTimer[actorid])
		{
			KillTimer__(FIXES_gsActorAnimTimer[actorid]),
			FIXES_gsActorAnimTimer[actorid] = 0;
		}
		if (FIXES_gsActorAnimLibs[actorid][idx >>> 5] & (1 << (idx & 0x1F)))
		{
			FIXES_gsActorAnimLibs[actorid][idx >>> 5] &= ~(1 << (idx & 0x1F)),
			FIXES_gsActorAnimName[actorid << 6] = '\0',
			strcat(FIXES_gsActorAnimName[actorid << 6], animname, 64),
			FIXES_gsActorAnimTimer[actorid] = SetTimerEx__("_FIXES_ApplyActorAnimation", 350, false, "ddfdddddd", actorid, idx, fDelta, loop, lockx, locky, freeze, time);
		}
	}
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation_2
	forward _FIXES_ApplyActorAnimation(actorid, animlib, Float:fDelta, loop, lockx, locky, freeze, time);

	public _FIXES_ApplyActorAnimation(actorid, animlib, Float:fDelta, loop, lockx, locky, freeze, time)
	{
		ApplyActorAnimation__(actorid, FIXES_gscAnimLib[animlib], FIXES_gsActorAnimName[actorid << 6], fDelta, loop, lockx, locky, freeze, time),
		FIXES_gsActorAnimTimer[actorid] = 0;
	}
#endif

/**
 * <fixes>ApplyActorAnimation</fixes>
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_ApplyActorAnimation
		#error _ALS_ApplyActorAnimation defined
	#endif
	native BAD_ApplyActorAnimation(actorid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time) = ApplyActorAnimation;
#endif

/**
 * <fixes>ApplyActorAnimation</fixes>
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2
	stock FIXES_ApplyActorAnimation(actorid, _FIXES_MAYBE_CONST animlib[], _FIXES_MAYBE_CONST animname[], Float:fDelta, loop, lockx, locky, freeze, time)
	{
		new
			idx = _FIXES_GetAnimLibIndex(animlib);

		if (~idx) // != -1
		{
			#if FIX_ApplyActorAnimation_2
				_FIXES_ApplyActorAnimationDelay(animname, actorid, idx, fDelta, loop, lockx, locky, freeze, time);
			#endif
				return ApplyActorAnimation__(actorid, animlib, animname, fDelta, loop, lockx, locky, freeze, time);
		}

		return 0;
	}

	#if _FIXES_SAMP
	#if defined _ALS_ApplyActorAnimation
		#undef ApplyActorAnimation
	#else
		#define _ALS_ApplyActorAnimation
	#endif
	#define ApplyActorAnimation( FIXES_ApplyActorAnimation(
#endif
	#define _ALS_ApplyActorAnimation__
	#define ApplyActorAnimation__( FIXES_ApplyActorAnimation(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if _FIXES_SAMP && defined _ALS_CreateActor
	#error _ALS_CreateActor defined
#endif
native BAD_CreateActor(modelid, Float:X, Float:Y, Float:Z, Float:Rotation) = CreateActor;

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation_2
	stock FIXES_CreateActor(modelid, Float:X, Float:Y, Float:Z, Float:Rotation)
	{
		new
			actorid;

		actorid = CreateActor__(modelid, X, Y, Z, Rotation);

		if (actorid == INVALID_ACTOR_ID)
		{
			return INVALID_ACTOR_ID;
		}

		FIXES_gsActorAnimLibs[actorid][0] =
			FIXES_gsActorAnimLibs[actorid][1] =
				FIXES_gsActorAnimLibs[actorid][2] =
					FIXES_gsActorAnimLibs[actorid][3] =
						FIXES_gsActorAnimLibs[actorid][4] = -1;

		return actorid;
	}

	#if _FIXES_SAMP
		#define _ALS_CreateActor
		#define CreateActor( FIXES_CreateActor(
	#endif

	#define _ALS_CreateActor__
	#define CreateActor__( FIXES_CreateActor(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DestroyActor
	#error _ALS_DestroyActor defined
#endif
native BAD_DestroyActor(actorid) = DestroyActor;

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation_2
	stock FIXES_DestroyActor(actorid)
	{
		if (FIXES_gsActorAnimTimer[actorid])
		{
			KillTimer__(FIXES_gsActorAnimTimer[actorid]),
			FIXES_gsActorAnimTimer[actorid] = 0;
		}

		return DestroyActor__(actorid);
	}

	#if _FIXES_SAMP
		#define _ALS_DestroyActor
		#define DestroyActor( FIXES_DestroyActor(
	#endif

	#define _ALS_DestroyActor__
	#define DestroyActor__( FIXES_DestroyActor(
#endif

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetVehicleComponentInSlot
	#error _ALS_GetVehicleComponentInSlot defined
#endif
native BAD_GetVehicleComponentInSlot(vehicleid, slot) = GetVehicleComponentInSlot;

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if FIX_GetVehicleComponentInSlot
	stock FIXES_GetVehicleComponentType(componentid)
	{
		if (componentid == 1100 || componentid == 1115 || componentid == 1116 || componentid == 1123 || componentid == 1125)
		{
			return CARMODTYPE_FRONT_BULLBAR;
		}
		else if (componentid == 1109 || componentid == 1110)
		{
			return CARMODTYPE_REAR_BULLBAR;
		}
		return GetVehicleComponentType__(componentid);
	}

	#if _FIXES_SAMP
		#define _ALS_GetVehicleComponentType
		#define GetVehicleComponentType( FIXES_GetVehicleComponentType(
	#endif

	#define _ALS_GetVehicleComponentType__
	#define GetVehicleComponentType__( FIXES_GetVehicleComponentType(
#endif

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if _FIXES_SAMP && defined _ALS_DestroyVehicle
	#error _ALS_DestroyVehicle defined
#endif
native BAD_DestroyVehicle(vehicleid) = DestroyVehicle;

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if FIX_GetVehicleComponentInSlot
	stock FIXES_DestroyVehicle(vehicleid)
	{
		new ret = DestroyVehicle__(vehicleid);
		if (ret) 
		{
			#if FIXES_Single		
				FIXES_gsStereo[vehicleid] = 0,
				FIXES_gsFrontBumper[vehicleid] = 0,
				FIXES_gsRearBumper[vehicleid] = 0,
				FIXES_gsFrontBullbar[vehicleid] = 0,
				FIXES_gsRearBullbar[vehicleid] = 0;
			#else
				setproperty(CARMODTYPE_STEREO + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0"),
				setproperty(CARMODTYPE_FRONT_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0"),
				setproperty(CARMODTYPE_REAR_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0"),
				setproperty(CARMODTYPE_FRONT_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0"),
				setproperty(CARMODTYPE_REAR_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
			#endif
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_DestroyVehicle
		#define DestroyVehicle( FIXES_DestroyVehicle(
	#endif

	#define _ALS_DestroyVehicle__
	#define DestroyVehicle__( FIXES_DestroyVehicle(
#endif

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AddVehicleComponent
	#error _ALS_AddVehicleComponent defined
#endif
native BAD_AddVehicleComponent(vehicleid, componentid) = AddVehicleComponent;

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if FIX_GetVehicleComponentInSlot
	stock FIXES_AddVehicleComponent(vehicleid, componentid)
	{
		new
			#if !FIXES_Single
				componentstring[8],
			#endif
				ret = AddVehicleComponent__(vehicleid, componentid);
		if (ret) 
		{
			switch (FIXES_GetVehicleComponentType(componentid))
			{
				#if FIXES_Single
					case CARMODTYPE_STEREO:
					{
						FIXES_gsStereo[vehicleid] = componentid;
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						FIXES_gsFrontBumper[vehicleid] = componentid;
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						FIXES_gsRearBumper[vehicleid] = componentid;
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						FIXES_gsFrontBullbar[vehicleid] = componentid;
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						FIXES_gsRearBullbar[vehicleid] = componentid;
					}
				#else
					case CARMODTYPE_STEREO:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_STEREO + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_FRONT_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_REAR_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_FRONT_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						valstr(componentstring, componentid);
						setproperty(CARMODTYPE_REAR_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					}
				#endif
			}
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_AddVehicleComponent
		#define AddVehicleComponent( FIXES_AddVehicleComponent(
	#endif

	#define _ALS_AddVehicleComponent__
	#define AddVehicleComponent__( FIXES_AddVehicleComponent(
#endif

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if _FIXES_SAMP && defined _ALS_RemoveVehicleComponent
	#error _ALS_RemoveVehicleComponent defined
#endif
native BAD_RemoveVehicleComponent(vehicleid, componentid) = RemoveVehicleComponent;

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if FIX_GetVehicleComponentInSlot
	stock FIXES_RemoveVehicleComponent(vehicleid, componentid)
	{
		new ret = RemoveVehicleComponent__(vehicleid, componentid);
		if (ret)
		{
			switch (FIXES_GetVehicleComponentType(componentid))
			{
				#if FIXES_Single
					case CARMODTYPE_STEREO:
					{
						FIXES_gsStereo[vehicleid] = 0;
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						FIXES_gsFrontBumper[vehicleid] = 0;
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						FIXES_gsRearBumper[vehicleid] = 0;
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						FIXES_gsFrontBullbar[vehicleid] = 0;
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						FIXES_gsRearBullbar[vehicleid] = 0;
					}
				#else
					case CARMODTYPE_STEREO:
					{
						setproperty(CARMODTYPE_STEREO + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
					}
					case CARMODTYPE_FRONT_BUMPER:
					{
						setproperty(CARMODTYPE_FRONT_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
					}
					case CARMODTYPE_REAR_BUMPER:
					{
						setproperty(CARMODTYPE_REAR_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
					}
					case CARMODTYPE_FRONT_BULLBAR:
					{
						setproperty(CARMODTYPE_FRONT_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
					}
					case CARMODTYPE_REAR_BULLBAR:
					{
						setproperty(CARMODTYPE_REAR_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, "0");
					}
				#endif
			}
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_RemoveVehicleComponent
		#define RemoveVehicleComponent( FIXES_RemoveVehicleComponent(
	#endif

	#define _ALS_RemoveVehicleComponent__
	#define RemoveVehicleComponent__( FIXES_RemoveVehicleComponent(
#endif

/**
 * <fixes>GetVehicleComponentInSlot</fixes>
 */

#if FIX_GetVehicleComponentInSlot
	stock FIXES_GetVehicleComponentInSlot(vehicleid, slot)
	{
		#if !FIXES_Single
			new componentstring[8];
		#endif
		switch (slot)
		{
			#if FIXES_Single
				case CARMODTYPE_STEREO:
				{
					return FIXES_gsStereo[vehicleid];
				}
				case CARMODTYPE_FRONT_BUMPER:
				{
					return FIXES_gsFrontBumper[vehicleid];
				}
				case CARMODTYPE_REAR_BUMPER:
				{
					return FIXES_gsRearBumper[vehicleid];
				}
				case CARMODTYPE_FRONT_BULLBAR:
				{
					return FIXES_gsFrontBullbar[vehicleid];
				}
				case CARMODTYPE_REAR_BULLBAR:
				{
					return FIXES_gsRearBullbar[vehicleid];
				}
			#else 
				case CARMODTYPE_STEREO:
				{
					getproperty(CARMODTYPE_STEREO + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					strunpack(componentstring, componentstring);
					return strval(componentstring);
				}
				case CARMODTYPE_FRONT_BUMPER:
				{
					getproperty(CARMODTYPE_FRONT_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					strunpack(componentstring, componentstring);
					return strval(componentstring);
				}
				case CARMODTYPE_REAR_BUMPER:
				{
					getproperty(CARMODTYPE_REAR_BUMPER + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					strunpack(componentstring, componentstring);
					return strval(componentstring);
				}
				case CARMODTYPE_FRONT_BULLBAR:
				{
					getproperty(CARMODTYPE_FRONT_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					strunpack(componentstring, componentstring);
					return strval(componentstring);
				}
				case CARMODTYPE_REAR_BULLBAR:
				{
					getproperty(CARMODTYPE_REAR_BULLBAR + _FIXES_PROPERTY_OFFSET, "", vehicleid, componentstring);
					strunpack(componentstring, componentstring);
					return strval(componentstring);
				}
			#endif
				default:
				{
					return GetVehicleComponentInSlot__(vehicleid, slot);
				}
		}
		return 1;
	}

	#if _FIXES_SAMP
		#define _ALS_GetVehicleComponentInSlot
		#define GetVehicleComponentInSlot( FIXES_GetVehicleComponentInSlot(
	#endif

	#define _ALS_GetVehicleComponentInSlot__
	#define GetVehicleComponentInSlot__( FIXES_GetVehicleComponentInSlot(
#endif


/**
 * <fixes>AttachTrailerToVehicle</fixes>
 */

#if _FIXES_SAMP && defined _ALS_AttachTrailerToVehicle
	#error _ALS_AttachTrailerToVehicle defined
#endif
native BAD_AttachTrailerToVehicle(trailerid, vehicleid) = AttachTrailerToVehicle;

#if FIX_AttachTrailerToVehicle
	stock FIXES_AttachTrailerToVehicle(trailerid, vehicleid)
	{
		if(trailerid == vehicleid)
		{
			return 0;
		}
		return AttachTrailerToVehicle__(trailerid, vehicleid);
	}
	#if _FIXES_SAMP
		#define _ALS_AttachTrailerToVehicle
		#define AttachTrailerToVehicle( FIXES_AttachTrailerToVehicle(
	#endif

	#define _ALS_AttachTrailerToVehicle__
	#define AttachTrailerToVehicle__( FIXES_AttachTrailerToVehicle(
#endif



/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetVehicleParamsEx
	#error _ALS_SetVehicleParamsEx defined
#endif
native BAD_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective) = SetVehicleParamsEx;

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3
	stock FIXES_SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective)
	{
		FIXES_gsVehicleIsLocked[vehicleid] = doors == VEHICLE_PARAMS_ON;
		return SetVehicleParamsEx__(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	}

	#if _FIXES_SAMP
		#define _ALS_SetVehicleParamsEx
		#define SetVehicleParamsEx( FIXES_SetVehicleParamsEx(
	#endif

	#define _ALS_SetVehicleParamsEx__
	#define SetVehicleParamsEx__( FIXES_SetVehicleParamsEx(
#endif

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetVehicleParamsEx
	#error _ALS_GetVehicleParamsEx defined
#endif
native BAD_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective) = GetVehicleParamsEx;

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3
	stock FIXES_GetVehicleParamsEx(vehicleid, &VEHICLE_PARAMS:engine, &VEHICLE_PARAMS:lights, &VEHICLE_PARAMS:alarm, &VEHICLE_PARAMS:doors, &VEHICLE_PARAMS:bonnet, &VEHICLE_PARAMS:boot, &VEHICLE_PARAMS:objective)
	{
		new
			ret = GetVehicleParamsEx__(vehicleid, VEHICLE_PARAMS:engine, VEHICLE_PARAMS:lights, VEHICLE_PARAMS:alarm, VEHICLE_PARAMS:doors, VEHICLE_PARAMS:bonnet, VEHICLE_PARAMS:boot, VEHICLE_PARAMS:objective);
		#if FIXES_Single
			doors = FIXES_gsVehicleIsLocked[vehicleid] ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
		#else
			#if !defined FILTERSCRIPT
				doors = _FIXES_GetVehicleDoorsEx(vehicleid) ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
			#else
				doors = CallRemoteFunction__("_FIXES_GetVehicleDoorsEx", "i", vehicleid) ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
			#endif
		#endif
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_GetVehicleParamsEx
		#define GetVehicleParamsEx( FIXES_GetVehicleParamsEx(
	#endif

	#define _ALS_GetVehicleParamsEx__
	#define GetVehicleParamsEx__( FIXES_GetVehicleParamsEx(
#endif

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3 && !FIXES_Single && !defined FILTERSCRIPT
	forward _FIXES_GetVehicleDoorsEx(vehicleid);

	public _FIXES_GetVehicleDoorsEx(vehicleid)
	{
		return FIXES_gsVehicleIsLocked[vehicleid];
	}
#endif

/**
 * <fixes>random</fixes>
 */

#if _FIXES_SAMP && defined _ALS_random
	#error _ALS_random defined
#endif
native BAD_random(max) = random;

/**
 * <fixes>random</fixes>
 */

#if FIX_random
	stock FIXES_random(max)
	{
		if (max < 0)
		{
			return -random(-max);
		}
		else
		{
			return random(max);
		}
	}

	#if _FIXES_SAMP
		#define _ALS_random
		#define random( FIXES_random(
	#endif

	#define _ALS_random__
	#define random__( FIXES_random(
#endif

/**
 * <fixes>sleep</fixes>
 */

// Uses a little trick to consume part of the line and thus not match
// our hooked version.
#if _FIXES_SAMP && defined _ALS_sleep
	#error _ALS_sleep defined
#endif
#define BAD_sleep%0\n%9 sleep%0

#if FIX_sleep
	stock FIXES_sleep(ms)
	{
		// Call a native function that does very little, but saves the current
		// heap pointer.  Then return to save the accurate stack pointer.
		return heapspace(), ms;
	}

	#define _ALS_sleep

	#define sleep%0\n%9 sleep FIXES_sleep(%0)
	// This fixes another BIZZARE bug.  Just doing:
	//
	//  #define FIXES_sleep(%0;) FIXES_sleep(%0)
	//
	// Results in:
	//
	//  FIXES_sleep(n));
	//
	// Which clearly it shouldn't.  I've stepped through the compilation and that
	// extra bracket comes from nowhere!
	#define FIXES_sleep(%0;) FIXES_sleep _FIXES_SLEEP_BRACKET %0);
	#define _FIXES_SLEEP_BRACKET (
#endif

/**
 * <remarks>
 * _FIXES_SetCamera
 * </remarks>
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	forward _FIXES_SetCamera(playerid, type, Float:x, Float:y, Float:z, cut);

	public _FIXES_SetCamera(playerid, type, Float:x, Float:y, Float:z, cut)
	{
		if (type)
		{
			SetPlayerCameraPos__(playerid, x, y, z);
		}
		else
		{
			SetPlayerCameraLookAt__(playerid, x, y, z, cut);
		}
		return 0;
	}
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerCameraPos
	#error _ALS_SetPlayerCameraPos defined
#endif
native BAD_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			#if FIXES_Single
				if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_SPECTATING || GetPlayerState__(playerid) == PLAYER_STATE_SPECTATING)
			#else
				if (GetPVarInt__(playerid, FIXES_pvarPlayerSpectate) || GetPlayerState__(playerid) == PLAYER_STATE_SPECTATING)
			#endif
				{
					SetTimerEx__(FIXES_gscSetCamera, 300, 0, FIXES_gscSpec@iifff, playerid, 1, x, y, z);
				}
				else
				{
					SetPlayerCameraPos__(playerid, x, y, z);
				}
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerCameraPos
		#define SetPlayerCameraPos( FIXES_SetPlayerCameraPos(
	#endif

	#define _ALS_SetPlayerCameraPos__
	#define SetPlayerCameraPos__( FIXES_SetPlayerCameraPos(
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerCameraLookAt
	#error _ALS_SetPlayerCameraLookAt defined
#endif
native BAD_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraLookAt;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, cut = CAMERA_CUT)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			#if FIXES_Single
				if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_SPECTATING || GetPlayerState__(playerid) == PLAYER_STATE_SPECTATING)
			#else
				if (GetPVarInt__(playerid, FIXES_pvarPlayerSpectate) || GetPlayerState__(playerid) == PLAYER_STATE_SPECTATING)
			#endif
				{
					SetTimerEx__(FIXES_gscSetCamera, 300, 0, FIXES_gscSpec@iifffi, playerid, 0, x, y, z, cut);
				}
				else
				{
					SetPlayerCameraLookAt__(playerid, x, y, z, cut);
				}
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerCameraLookAt
		#define SetPlayerCameraLookAt( FIXES_SetPlayerCameraLookAt(
	#endif

	#define _ALS_SetPlayerCameraLookAt__
	#define SetPlayerCameraLookAt__( FIXES_SetPlayerCameraLookAt(
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if _FIXES_SAMP && defined _ALS_TogglePlayerSpectating
	#error _ALS_TogglePlayerSpectating defined
#endif
native BAD_TogglePlayerSpectating(playerid, toggle) = TogglePlayerSpectating;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_TogglePlayerSpectating(playerid, toggle)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			if (toggle)
			{
				#if FIXES_Single
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_SPECTATING;
				#else
					SetPVarInt__(playerid, FIXES_pvarPlayerSpectate, 1);
				#endif
			}
			else
			{
				#if FIXES_Single
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_SPECTATING;
				#else
					DeletePVar__(playerid, FIXES_pvarPlayerSpectate);
				#endif
			}
			return TogglePlayerSpectating__(playerid, toggle);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_TogglePlayerSpectating
		#define TogglePlayerSpectating( FIXES_TogglePlayerSpectating(
	#endif

	#define _ALS_TogglePlayerSpectating__
	#define TogglePlayerSpectating__( FIXES_TogglePlayerSpectating(
#endif

/**
 * <fixes>SetPlayerTime</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerTime
	#error _ALS_SetPlayerTime defined
#endif
native BAD_SetPlayerTime(playerid, hour, minute) = SetPlayerTime;

/**
 * <fixes>SetPlayerTime</fixes>
 */

#if FIX_SetPlayerTime
	forward _FIXES_SetTime(playerid, hour, minute);

	public _FIXES_SetTime(playerid, hour, minute)
	{
		return SetPlayerTime__(playerid, hour, minute);
	}

	stock FIXES_SetPlayerTime(playerid, hour, minute)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_ON_PLAYER_CONNECT)
			{
				return SetTimerEx__(FIXES_gscSetTime, 250, 0, FIXES_gscSpec@iii, playerid, hour, minute);
			}
			return SetPlayerTime__(playerid, hour, minute);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerTime
		#define SetPlayerTime( FIXES_SetPlayerTime(
	#endif

	#define _ALS_SetPlayerTime__
	#define SetPlayerTime__( FIXES_SetPlayerTime(
#endif

/**
 * <fixes>SetPlayerColor</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerColor
	#error _ALS_SetPlayerColor defined
#endif
native BAD_SetPlayerColor(playerid, color) = SetPlayerColor;

/**
 * <fixes>SetPlayerColor</fixes>
 */

#if FIX_SetPlayerColour
	forward _FIXES_SetColor(playerid, color);

	public _FIXES_SetColor(playerid, color)
	{
		return SetPlayerColor__(playerid, color);
	}

	stock FIXES_SetPlayerColor(playerid, color)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_ON_PLAYER_CONNECT)
			{
				return SetTimerEx__(FIXES_gscSetColor, 300, 0, FIXES_gscSpec@ii, playerid, color);
			}
			return SetPlayerColor__(playerid, color);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerColor
		#define SetPlayerColor( FIXES_SetPlayerColor(
	#endif

	#define _ALS_SetPlayerColor__
	#define SetPlayerColor__( FIXES_SetPlayerColor(
#endif

/**
 * <fixes>GetPlayerWeaponData</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerWeaponData
	#error _ALS_GetPlayerWeaponData defined
#endif
native BAD_GetPlayerWeaponData(playerid, slot, &weapons, &ammo) = GetPlayerWeaponData;

/**
 * <fixes>GetPlayerWeaponData</fixes>
 */

#if FIX_GetPlayerWeaponData
	stock FIXES_GetPlayerWeaponData(playerid, slot, &weapons, &ammo)
	{
		// This reuses the "slot" variable so we don't have to declare a new one
		// and can put all the code in a single statement.
		return
			slot = GetPlayerWeaponData__(playerid, slot, weapons, ammo),
			weapons = ammo ? weapons : 0,
			slot;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerWeaponData
		#define GetPlayerWeaponData( FIXES_GetPlayerWeaponData(
	#endif

	#define _ALS_GetPlayerWeaponData__
	#define GetPlayerWeaponData__( FIXES_GetPlayerWeaponData(
#endif

/**
 * <fixes>strcmp</fixes>
 */

#if _FIXES_SAMP && defined _ALS_strcmp
	#error _ALS_strcmp defined
#endif
native BAD_strcmp(const string1[], const string2[], bool:ignorecase=false, length=cellmax) = strcmp;

/**
 * <fixes>strcmp</fixes>
 */

#if FIX_strcmp
	stock FIXES_strcmp(const string1[], const string2[], bool:ignorecase=false, length=cellmax)
	{
		if (length == 0)
			return 0;
		if (string1[0])
		{
			if (string2[0])
			{
				return clamp(strcmp(string1, string2, ignorecase, length), -1, 1);
			}
			else
			{
				// Positive as st1 is greater (strcmp spec).
				return 1;
			}
		}
		else
		{
			if (string2[0])
			{
				// Negative as str2 is greater.
				return -1;
			}
			else
			{
				// The strings are the same (empty).
				return 0;
			}
		}
	}

	#if _FIXES_SAMP
		#define _ALS_strcmp
		#define strcmp( FIXES_strcmp(
	#endif

	#define _ALS_strcmp__
	#define strcmp__( FIXES_strcmp(
#endif

/**
 * <fixes>GetPVarString</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_GetPVarString
		#error _ALS_GetPVarString defined
	#endif
	native BAD_GetPVarString(playerid, varname[], string_return[], len) = GetPVarString;
#endif

/**
 * <fixes>GetPVarString</fixes>
 */

#if FIX_GetPVarString
	stock FIXES_GetPVarString(playerid, _FIXES_MAYBE_CONST varname[], string_return[], len)
	{
		len = GetPVarString__(playerid, varname, string_return, len);
		static i; i = -1;
		do {} while ((string_return[++i] &= 0xFF) != '\0');
		return len;
	}

	#if _FIXES_SAMP
	#if defined _ALS_GetPVarString
		#undef GetPVarString
	#else
		#define _ALS_GetPVarString
	#endif
	#define GetPVarString( FIXES_GetPVarString(
#endif
	#define _ALS_GetPVarString__
	#define GetPVarString__( FIXES_GetPVarString(
#endif

/**
 * <fixes>GetSVarString</fixes>
 */

#if !FIX_const
	#if _FIXES_SAMP && defined _ALS_GetSVarString
		#error _ALS_GetSVarString defined
	#endif
	native BAD_GetSVarString(varname[], string_return[], len) = GetSVarString;
#endif

/**
 * <fixes>GetSVarString</fixes>
 */

#if FIX_GetSVarString
	stock FIXES_GetSVarString(_FIXES_MAYBE_CONST varname[], string_return[], len)
	{
		len = GetSVarString__(varname, string_return, len);
		static i; i = -1;
		do {} while ((string_return[++i] &= 0xFF) != '\0');
		return len;
	}

	#if _FIXES_SAMP
	#if defined _ALS_GetSVarString
		#undef GetSVarString
	#else
		#define _ALS_GetSVarString
	#endif
	#define GetSVarString( FIXES_GetSVarString(
#endif
	#define _ALS_GetSVarString__
	#define GetSVarString__( FIXES_GetSVarString(
#endif

/**
 * <fixes>toupper</fixes>
 */

#if _FIXES_SAMP && defined _ALS_toupper
	#error _ALS_toupper defined
#endif
native BAD_toupper(c) = toupper;

/**
 * <fixes>toupper</fixes>
 */

#if FIX_toupper
	stock FIXES_toupper(c)
	{
		switch (c)
		{
			case 'a'..'z', 224..255:
			{
				return c - 32;
			}
			case 168:
			{
				return c - 16;
			}
		}
		return c;
	}

	#if _FIXES_SAMP
		#define _ALS_toupper
		#define toupper( FIXES_toupper(
	#endif

	#define _ALS_toupper__
	#define toupper__( FIXES_toupper(
#endif

/**
 * <fixes>tolower</fixes>
 */

#if _FIXES_SAMP && defined _ALS_tolower
	#error _ALS_tolower defined
#endif
native BAD_tolower(c) = tolower;

/**
 * <fixes>tolower</fixes>
 */

#if FIX_tolower
	stock FIXES_tolower(c)
	{
		switch (c)
		{
			case 'A'..'Z', 192..223:
			{
				return c + 32;
			}
			case 184:
			{
				return c + 16;
			}
		}
		return c;
	}

	#if _FIXES_SAMP
		#define _ALS_tolower
		#define tolower( FIXES_tolower(
	#endif

	#define _ALS_tolower__
	#define tolower__( FIXES_tolower(
#endif

/**
 * <fixes>ispacked</fixes>
 */

#if _FIXES_SAMP && defined _ALS_ispacked
	#error _ALS_ispacked defined
#endif
native bool:BAD_ispacked(const string[]) = ispacked;

/**
 * <fixes>ispacked</fixes>
 */

#if FIX_ispacked
	#if _FIXES_SAMP
	#define _ALS_ispacked
		#define ispacked(%0) (((%0)[0] & ~0xFF) != 0)
#endif
	#define _ALS_ispacked__
	#define ispacked__(%0) (((%0)[0] & ~0xFF) != 0)
#endif

/**
 * <fixes>GetPlayerPoolSize</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerPoolSize
	#error _ALS_GetPlayerPoolSize defined
#endif
native BAD_GetPlayerPoolSize() = GetPlayerPoolSize;

/**
 * <fixes>GetPlayerPoolSize</fixes>
 */

#if FIX_GetPlayerPoolSize
	stock FIXES_GetPlayerPoolSize()
	{
		new
			size = GetPlayerPoolSize__();
		return
			size == 0 && !IsPlayerConnected__(0) ? -1 :
			size >= MAX_PLAYERS ? MAX_PLAYERS - 1 :
			size;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerPoolSize
		#define GetPlayerPoolSize( FIXES_GetPlayerPoolSize(
	#endif

	#define _ALS_GetPlayerPoolSize__
	#define GetPlayerPoolSize__( FIXES_GetPlayerPoolSize(
#endif

/**
 * <fixes>SetPlayerPos</fixes>
 * <fixes>* NOTE:</fixes>
 * <fixes>"PARACHUTE", "FALL_skyDive", 958</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_Accel", 959</fixes>
 * <fixes>"PARACHUTE", "FALL_skyDive_DIE", 960</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_L", 961</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_R", 962</fixes>
 * <fixes>"ped", "FALL_skyDive", 1134</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerPos
	#error _ALS_SetPlayerPos defined
#endif
native BAD_SetPlayerPos(playerid, Float:x, Float:y, Float:z) = SetPlayerPos;

/**
 * <fixes>SetPlayerPos</fixes>
 * <fixes>* NOTE:</fixes>
 * <fixes>"PARACHUTE", "FALL_skyDive", 958</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_Accel", 959</fixes>
 * <fixes>"PARACHUTE", "FALL_skyDive_DIE", 960</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_L", 961</fixes>
 * <fixes>"PARACHUTE", "FALL_SkyDive_R", 962</fixes>
 * <fixes>"ped", "FALL_skyDive", 1134</fixes>
 */

#if FIX_SetPlayerPos
	stock FIXES_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
	{
		new
			ret = SetPlayerPos__(playerid, x, y, z);
		if (ret)
		{
			_FIXES_RemoveFlyingParachute(playerid);
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerPos
		#define SetPlayerPos( FIXES_SetPlayerPos(
	#endif

	#define _ALS_SetPlayerPos__
	#define SetPlayerPos__( FIXES_SetPlayerPos(
#endif

/**
 * <fixes>SetPlayerPos</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerPosFindZ
	#error _ALS_SetPlayerPosFindZ defined
#endif
native BAD_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) = SetPlayerPosFindZ;

/**
 * <fixes>SetPlayerPos</fixes>
 */

#if FIX_SetPlayerPos
	stock FIXES_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z)
	{
		new
			ret = SetPlayerPosFindZ__(playerid, x, y, z);
		if (ret)
		{
			_FIXES_RemoveFlyingParachute(playerid);
		}
		return ret;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerPosFindZ
		#define SetPlayerPosFindZ( FIXES_SetPlayerPosFindZ(
	#endif

	#define _ALS_SetPlayerPosFindZ__
	#define SetPlayerPosFindZ__( FIXES_SetPlayerPosFindZ(
#endif

/**
 * <fixes>SetPlayerPos</fixes>
 */

#if FIX_SetPlayerPos
	static stock _FIXES_RemoveFlyingParachute(playerid)
	{
		#if FIX_OnPlayerDeath
			switch (FIXES_gsLastAnimation[playerid])
		#else
			switch (GetPlayerAnimationIndex__(playerid))
		#endif
			{
				case 958, 959, 960, 961, 962, 1134:
				{
					new
						slot,
						weapons[_FIXES_WEAPON_SLOTS][2];
					for (slot = 0; slot < sizeof(weapons); slot++)
					{
						GetPlayerWeaponData__(playerid, slot, weapons[slot][0], weapons[slot][1]);
					}
					weapons[11][0] = 0;
					ResetPlayerWeapons__(playerid);
					for (slot = 0; slot < sizeof(weapons); slot++)
					{
						GivePlayerWeapon__(playerid, weapons[slot][0], weapons[slot][1]);
					}
				}
			}
	}
#endif

/**
 * <fixes>GetPlayerAmmo</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerAmmo
	#error _ALS_SetPlayerAmmo defined
#endif
native BAD_SetPlayerAmmo(playerid, weaponid, ammo) = SetPlayerAmmo;

/**
 * <fixes>GetPlayerAmmo</fixes>
 */

#if FIX_GetPlayerAmmo
	#if _FIXES_SAMP
	#define _ALS_SetPlayerAmmo
		#define SetPlayerAmmo(%0,%1,%2) BAD_SetPlayerAmmo((%0),(%1),clamp((%2),0,32767))
#endif
	#define _ALS_SetPlayerAmmo__
	#define SetPlayerAmmo__(%0,%1,%2) BAD_SetPlayerAmmo((%0),(%1),clamp((%2),0,32767))
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetPlayerWeather
	#error _ALS_GetPlayerWeather defined
#endif

#if FIX_GetPlayerWeather
	stock FIXES_GetPlayerWeather(playerid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid) && !(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_CLOCK_ENABLED))
		{
			return FIXES_GET(PlayerWeather, playerid);
		}
		return -1;
	}

	#if _FIXES_SAMP
		#define _ALS_GetPlayerWeather
		#define GetPlayerWeather( FIXES_GetPlayerWeather(
	#endif

	#define _ALS_GetPlayerWeather__
	#define GetPlayerWeather__( FIXES_GetPlayerWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetPlayerWeather
	#error _ALS_SetPlayerWeather defined
#endif
native BAD_SetPlayerWeather(playerid, weather) = SetPlayerWeather;

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if FIX_GetPlayerWeather
	stock FIXES_SetPlayerWeather(playerid, weather)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
		{
			FIXES_SET(PlayerWeather, playerid, weather);
			return SetPlayerWeather__(playerid, weather);
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_SetPlayerWeather
	#define SetPlayerWeather( FIXES_SetPlayerWeather(
#endif
	#define _ALS_SetPlayerWeather__
	#define SetPlayerWeather__( FIXES_SetPlayerWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if _FIXES_SAMP && defined _ALS_TogglePlayerClock
	#error _ALS_TogglePlayerClock defined
#endif
native BAD_TogglePlayerClock(playerid, toggle) = TogglePlayerClock;

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if FIX_GetPlayerWeather || FIX_API
	#if FIXES_Single
		stock FIXES_TogglePlayerClock(playerid, toggle)
		{
			if (TogglePlayerClock__(playerid, toggle))
			{
				if (toggle)
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CLOCK_ENABLED;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_CLOCK_ENABLED;
				}
				return 1;
			}
			return 0;
		}
	#else
		forward _FIXES_TogglePlayerClock(playerid, toggle);

		stock FIXES_TogglePlayerClock(playerid, toggle)
		{
			if (_FIXES_IS_VALID_PLAYER(playerid))
			{
				return
					CallRemoteFunction__(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, playerid, toggle),
					getproperty(5, FIXES_gscReturnProperty);
			}
			return 0;
		}

		public _FIXES_TogglePlayerClock(playerid, toggle)
		{
			if (toggle)
			{
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CLOCK_ENABLED;
			}
			else
			{
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_CLOCK_ENABLED;
			}
			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscReturnProperty, TogglePlayerClock__(playerid, toggle));
			}
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_TogglePlayerClock
	#define TogglePlayerClock( FIXES_TogglePlayerClock(
#endif
	#define _ALS_TogglePlayerClock__
	#define TogglePlayerClock__( FIXES_TogglePlayerClock(
#endif

/**
 * <fixes>GetWeather</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetWeather
	#error _ALS_GetWeather defined
#endif

#if FIX_GetWeather
	#if FIXES_Single
		stock FIXES_GetWeather()
		{
			return FIXES_gsServerWeather;
		}
	#else
		forward _FIXES_GetWeather();

		stock FIXES_GetWeather()
		{
			return
				CallRemoteFunction__(FIXES_gscGetWeather, FIXES_gscSpec@),
				getproperty(5, FIXES_gscReturnProperty);
		}

		public _FIXES_GetWeather()
		{
			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscReturnProperty, FIXES_gsServerWeather);
			}
		}
	#endif

	#if _FIXES_SAMP
		#define _ALS_GetWeather
		#define GetWeather( FIXES_GetWeather(
	#endif

	#define _ALS_GetWeather__
	#define GetWeather__( FIXES_GetWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetWeather
	#error _ALS_SetWeather defined
#endif
native BAD_SetWeather(weather) = SetWeather;

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if FIX_GetWeather
	stock FIXES_SetWeather(weather)
	{
		FIXES_gsServerWeather = weather;
		#if FIX_GetPlayerWeather
			_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
			{
				FIXES_SET(PlayerWeather, playerid, weather);
			}
		#endif
		return SetWeather__(weather);
	}

	#if _FIXES_SAMP
		#define _ALS_SetWeather
	#define SetWeather( FIXES_SetWeather(
#endif
	#define _ALS_SetWeather__
	#define SetWeather__( FIXES_SetWeather(
#endif

/**
 * <fixes>GetWorldTime</fixes>
 */

#if _FIXES_SAMP && defined _ALS_SetWorldTime
	#error _ALS_SetWorldTime defined
#endif
native BAD_SetWorldTime(hour) = SetWorldTime;

/**
 * <fixes>GetWorldTime</fixes>
 */

#if FIX_GetWorldTime
	#if _FIXES_SAMP
		#define _ALS_SetWorldTime
		#define SetWorldTime(%0) BAD_SetWorldTime((_FIXES_gsWorldTime=(%0)))
	#endif
	#define _ALS_SetWorldTime__
	#define SetWorldTime__(%0) BAD_SetWorldTime((_FIXES_gsWorldTime=(%0)))
#endif

/**
 * <fixes>GetWorldTime</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetWorldTime
	#error _ALS_GetWorldTime defined
#endif

#if FIX_GetWorldTime
	#if _FIXES_SAMP
	#define _ALS_GetWorldTime
		#define GetWorldTime() (_FIXES_gsWorldTime)
#endif
	#define _ALS_GetWorldTime__
	#define GetWorldTime__() (_FIXES_gsWorldTime)
#endif

/**
 * <fixes>GetMaxPlayers</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetMaxPlayers
	#error _ALS_GetMaxPlayers defined
#endif

#if FIX_GetMaxPlayers
	#if _FIXES_SAMP
		#define _ALS_GetMaxPlayers
		#define GetMaxPlayers() (_FIXES_gsMaxPlayers)
	#endif
	#define _ALS_GetMaxPlayers__
	#define GetMaxPlayers__() (_FIXES_gsMaxPlayers)
#endif

/**
 * <fixes>GetServerVarAsString</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetConsoleVarAsString
	#error _ALS_GetConsoleVarAsString defined
#endif
native BAD_GetConsoleVarAsString(const varname[], buffer[], len) = GetConsoleVarAsString;

#if _FIXES_SAMP && defined _ALS_GetServerVarAsString
	#error _ALS_GetServerVarAsString defined
#endif
native BAD_GetServerVarAsString(const varname[], buffer[], len) = GetServerVarAsString;

/**
 * <fixes>GetServerVarAsString</fixes>
 */

#if FIX_GetConsoleVarAsString || FIX_GetConsoleVarAsFloat || FIX_GetConsoleVarAsInt || FIX_GetConsoleVarAsBool
	stock bool:FIXES_GetConsoleVarAsString(const varname[], buffer[], len = sizeof (buffer))
	{
		buffer[0] = '\0';
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0x6A7D4118, // gamemode0
		     0x6A7D4119, // gamemode1
		     0x6A7D411A, // gamemode2
		     0x6A7D411B, // gamemode3
		     0x6A7D411C, // gamemode4
		     0x6A7D411D, // gamemode5
		     0x6A7D411E, // gamemode6
		     0x6A7D411F, // gamemode7
		     0x6A7D4110, // gamemode8
		     0x6A7D4111, // gamemode9
		     0xBA256409, // gamemode10
		     0xBA256408, // gamemode11
		     0xBA25640B, // gamemode12
		     0xBA25640A, // gamemode13
		     0xBA25640D, // gamemode14
		     0xBA25640C, // gamemode15
		     0x740D30D2, // worldtime
		     0x2FB2D3BF, // version
		     0xFBE0D5FE, // lagcomp
		     0x19BECDF7, // logtimeformat
		     0x62420997, // nosign
		     0x9D57983F, // plugins
		     0x3AFFC879, // filterscripts
		     0xD93377B5, // gamemodetext
		     0x74C01C1D, // weather
		     0xB605A0C3, // gravity
		     0x8FED0775, // rcon_password
		     0x77E7547E, // weburl
		     0x40736C5E, // mapname
		     0x672924D7, // language
		     0x0E9495C2, // hostname
		     0x5D876F9A, // password
		     0x7C706484: // bind
			return bool:GetConsoleVarAsString__(varname, buffer, len);
		default:
			return false;
		}
		fseek(FIXES_gsServerCFG, 0, seek_start);
		// Read the file line-by-line.  Take care of very long lines.
		new
			cmpLen = strlen(varname),
			readOffset,
			line[128],
			lineLen,
			lineState = 0;
		while ((lineLen = fread(FIXES_gsServerCFG, line)))
		{
			// Start of line, do a normal check.
			if (lineState == 0)
			{
				// There is no explicit comments (#) check, since a commented
				// line simply won't match the parameter varname.
				if (lineLen < cmpLen || strcmp(line, varname, true, cmpLen) || line[cmpLen] > ' ')
					lineState = 2; // The varname didn't match exactly.
				else
				{
					readOffset = cmpLen;
					// Skip whitespace.
					while ('\0' < line[readOffset] <= ' ')
						++readOffset;
					lineState = 1;
				}
			}
			else if (lineState == 1)
				readOffset = 0;
			if (lineState == 1)
			{
				while (lineLen && (line[lineLen - 1] == '\r' || line[lineLen - 1] == '\n'))
				{
					line[--lineLen] = '\0';
					lineState = 3;
				}
				// The read offset start is found be skipping all whitespace.
				// Then the new lines are removed.  If there was only
				// whitespace, the read offset will actually be beyond the new
				// end of the string, but we know that it will also point to a
				// NULL, so that's fine.
				strcat(buffer, line[readOffset], len);
				if (lineState == 3)
					return true;
			}
			else if (line[lineLen - 1] == '\r' || line[lineLen - 1] == '\n')
				lineState = 0; // Ignored line ended with a line feed.
		}
		return true;
	}
#endif

#if FIX_GetConsoleVarAsString
	#if _FIXES_SAMP
		#define _ALS_GetConsoleVarAsString
		#define GetConsoleVarAsString( FIXES_GetConsoleVarAsString(
	#endif

	#define _ALS_GetConsoleVarAsString__
	#define GetConsoleVarAsString__( FIXES_GetConsoleVarAsString(
	
	#pragma deprecated Use `GetConsoleVarAsString`
	stock bool:FIXES_GetServerVarAsString(const varname[], buffer[], len = sizeof (buffer))
	{
		return FIXES_GetConsoleVarAsString(varname, buffer, len);
	}

	#if _FIXES_SAMP
		#define _ALS_GetServerVarAsString
		#define GetServerVarAsString( FIXES_GetServerVarAsString(
	#endif

	#define _ALS_GetServerVarAsString__
	#define GetServerVarAsString__( FIXES_GetServerVarAsString(
#endif

/**
 * <fixes>GetConsoleVarAsInt</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetConsoleVarAsInt
	#error _ALS_GetConsoleVarAsInt defined
#endif
native BAD_GetConsoleVarAsInt(const varname[]) = GetConsoleVarAsInt;

#if _FIXES_SAMP && defined _ALS_GetServerVarAsInt
	#error _ALS_GetServerVarAsInt defined
#endif
native BAD_GetServerVarAsInt(const varname[]) = GetServerVarAsInt;

/**
 * <fixes>GetConsoleVarAsInt</fixes>
 */

#if FIX_GetConsoleVarAsInt
	stock FIXES_GetConsoleVarAsInt(const varname[])
	{
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0xF59D7562, // cookielogging
		     0x5DD3AB50, // concookies
		     0x24DF3EEB, // db_log_queries
		     0xD8FC2F7F, // db_logging
		     0xCEF27485, // conseedtime
		     0x0C43D2DD, // lagcompmode
		     0xB3AAF0EC, // minconnectiontime
		     0x2E17DD8D, // playertimeout
		     0xED02304A, // ackslimit
		     0x55A5C0C8, // messageslimit
		     0xBD012555, // messageholelimit
		     0x16C6DD58, // chatlogging
		     0x9420F5BA, // weapon_rate
		     0x5C8B384F, // incar_rate
		     0x01F89DEB, // onfoot_rate
		     0x57452FAC, // maxnpc
		     0x0BAD27EA, // sleep
		     0x0A9910C4, // stream_rate
		     0xE20F31D1: // maxplayers
			return GetConsoleVarAsInt__(varname);
		default:
			return 0;
		}
		new
			buffer[16];
		if (FIXES_GetConsoleVarAsString(varname, buffer, sizeof (buffer)))
			return strval(buffer);
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetConsoleVarAsInt
		#define GetConsoleVarAsInt( FIXES_GetConsoleVarAsInt(
	#endif

	#define _ALS_GetConsoleVarAsInt__
	#define GetConsoleVarAsInt__( FIXES_GetConsoleVarAsInt(
	
	#pragma deprecated Use `GetConsoleVarAsInt`
	stock FIXES_GetServerVarAsInt(const varname[])
	{
		return FIXES_GetConsoleVarAsInt(varname);
	}

	#if _FIXES_SAMP
		#define _ALS_GetServerVarAsInt
		#define GetServerVarAsInt( FIXES_GetServerVarAsInt(
	#endif

	#define _ALS_GetServerVarAsInt__
	#define GetServerVarAsInt__( FIXES_GetServerVarAsInt(
#endif

/**
 * <fixes>GetConsoleVarAsBool</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetConsoleVarAsBool
	#error _ALS_GetConsoleVarAsBool defined
#endif
native BAD_GetConsoleVarAsBool(const varname[]) = GetConsoleVarAsBool;

#if _FIXES_SAMP && defined _ALS_GetServerVarAsBool
	#error _ALS_GetServerVarAsBool defined
#endif
native BAD_GetServerVarAsBool(const varname[]) = GetServerVarAsBool;

/**
 * <fixes>GetConsoleVarAsBool</fixes>
 */

#if FIX_GetConsoleVarAsBool
	stock bool:FIXES_GetConsoleVarAsBool(const varname[])
	{
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0x5F92A936, // announce
		     0xFB6572C5, // lanmode
		     0x0B3513EF, // query
		     0x7C78F2F5, // rcon
		     0xA300A7ED, // logqueries
		     0x97EABC6B, // timestamp
		     0x57CBE04F: // myriad
			return bool:GetConsoleVarAsBool__(varname);
		default:
			return false;
		}
		new
			buffer[16];
		if (FIXES_GetConsoleVarAsString(varname, buffer, sizeof (buffer)))
			return strval(buffer) != 0;
		return false;
	}

	#if _FIXES_SAMP
		#define _ALS_GetConsoleVarAsBool
		#define GetConsoleVarAsBool( FIXES_GetConsoleVarAsBool(
	#endif

	#define _ALS_GetConsoleVarAsBool__
	#define GetConsoleVarAsBool__( FIXES_GetConsoleVarAsBool(
	
	#pragma deprecated Use `GetConsoleVarAsBool`
	stock bool:FIXES_GetServerVarAsBool(const varname[])
	{
		return FIXES_GetConsoleVarAsBool(varname);
	}

	#if _FIXES_SAMP
		#define _ALS_GetServerVarAsBool
		#define GetServerVarAsBool( FIXES_GetServerVarAsBool(
	#endif

	#define _ALS_GetServerVarAsBool__
	#define GetServerVarAsBool__( FIXES_GetServerVarAsBool(
#endif

/**
 * <fixes>GetConsoleVarAsFloat</fixes>
 */

#if _FIXES_SAMP && defined _ALS_GetConsoleVarAsFloat
	#error _ALS_GetConsoleVarAsFloat defined
#endif
#if defined GetConsoleVarAsFloat
	native BAD_GetConsoleVarAsFloat(const varname[]) = GetConsoleVarAsFloat;
#endif

#if _FIXES_SAMP && defined _ALS_GetServerVarAsFloat
	#error _ALS_GetServerVarAsFloat defined
#endif
#if defined GetServerVarAsFloat
	native BAD_GetServerVarAsFloat(const varname[]) = GetServerVarAsFloat;
#endif

/**
 * <fixes>GetConsoleVarAsFloat</fixes>
 */

#if FIX_GetConsoleVarAsFloat
	stock Float:FIXES_GetConsoleVarAsFloat(const varname[])
	{
		if (!FIXES_gsServerCFG) // 0x03A253F3 = stream_distance.
			return 0.0;
		new
			buffer[16];
		if (FIXES_GetConsoleVarAsString(varname, buffer, sizeof (buffer)))
			return floatstr(buffer);
		return 0.0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetConsoleVarAsFloat
		#define GetConsoleVarAsFloat( FIXES_GetConsoleVarAsFloat(
	#endif

	#define _ALS_GetConsoleVarAsFloat__
	#define GetConsoleVarAsFloat__( FIXES_GetConsoleVarAsFloat(
	
	#pragma deprecated Use `GetConsoleVarAsFloat`
	stock Float:FIXES_GetServerVarAsFloat(const varname[])
	{
		return FIXES_GetConsoleVarAsFloat(varname);
	}

	#if _FIXES_SAMP
		#define _ALS_GetServerVarAsFloat
		#define GetServerVarAsFloat( FIXES_GetServerVarAsFloat(
	#endif

	#define _ALS_GetServerVarAsFloat__
	#define GetServerVarAsFloat__( FIXES_GetServerVarAsFloat(
#endif

/*

           db         88888888ba   88  
          d88b        88      "8b  88  
         d8'`8b       88      ,8P  88  
        d8'  `8b      88aaaaaa8P'  88  
       d8YaaaaY8b     88""""""'    88  
      d8""""""""8b    88           88  
     d8'        `8b   88           88  
    d8'          `8b  88           88  



*/

/**
 * <remarks>
 * Get the default colour for a given playerid.  They don't need to be
 * connected.  Relies on <c>FIX_GetPlayerColour</c>.  Provides an alias for
 * those people that can't spell <c>colour</c> correctly.
 * </remarks>
 */

#if FIX_API
	stock FIXES_GetDefaultPlayerColour(playerid)
	{
		if (_FIXES_IS_VALID_PLAYER(playerid))
			return FIXES_gscPlayerColours[playerid % sizeof (FIXES_gscPlayerColours)];
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetDefaultPlayerColour
		#define GetDefaultPlayerColour( FIXES_GetDefaultPlayerColour(
	#endif

	#define _ALS_GetDefaultPlayerColour__
	#define GetDefaultPlayerColour__( FIXES_GetDefaultPlayerColour(

	#if _FIXES_SAMP
		#define _ALS_GetDefaultPlayerColor
		#define GetDefaultPlayerColor( FIXES_GetDefaultPlayerColour(
	#endif

	#define _ALS_GetDefaultPlayerColor__
	#define GetDefaultPlayerColor__( FIXES_GetDefaultPlayerColour(
#endif

/**
 * <remarks>
 * Get the number of seats in a given vehicle.
 * </remarks>
 */

#if FIX_API
	stock FIXES_GetVehicleSeats(modelid)
	{
		modelid -= 400;
		if (_FIXES_IN_RANGE(modelid, 0, 211 + 1))
		{
			modelid = (FIXES_gscMaxPassengers[modelid >>> 3] >>> ((modelid & 7) << 2)) & 0xF;
			if (modelid != 15)
				return modelid + 1;
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_GetVehicleSeats
		#define GetVehicleSeats( FIXES_GetVehicleSeats(
	#endif

	#define _ALS_GetVehicleSeats__
	#define GetVehicleSeats__( FIXES_GetVehicleSeats(
#endif

/**
 * <remarks>
 * Check if a given vehicle can use a given mod component.
 * </remarks>
 */

#if FIX_API
	stock bool:FIXES_VehicleCanHaveComponent(modelid, componentid)
	{
		if (_FIXES_IN_RANGE(modelid, 400, 611 + 1))
		{
			componentid -= 1000;
			if (_FIXES_IN_RANGE(componentid, 0, 191 + 1))
			{
				if (FIXES_gscVehicleMods[(modelid - 400) * 6 + (componentid >>> 5)] & 1 << (componentid & 0b00011111))
				{
					return true;
				}
			}
			else if (componentid == 192 || componentid == 193)
			{
				if (modelid == 576)
				{
					// This save a whole cell off EVERY other vehicle!  This
					// is the ONLY vehicle with any mods over "6 * 32 + 999"
					// (1191), the highest value you can fit in 6 cells of a
					// bit array (minus 1000).
					return true;
				}
			}
		}
		return false;
	}

	#if _FIXES_SAMP
		#define _ALS_VehicleCanHaveComponent
		#define VehicleCanHaveComponent( FIXES_VehicleCanHaveComponent(
	#endif

	#define _ALS_VehicleCanHaveComponent__
	#define VehicleCanHaveComponent__( FIXES_VehicleCanHaveComponent(
#endif

/**
 * <remarks>
 * Check if a given animation library name is actually valid and in SA:MP.
 * </remarks>
 */

#if FIX_API
	#define FIXES_IsValidAnimationLibrary(%0) (_FIXES_GetAnimLibIndex(%0) != -1)

	#if _FIXES_SAMP
		#define _ALS_IsValidAnimationLibrary
		#define IsValidAnimationLibrary( FIXES_IsValidAnimationLibrary(
	#endif

	#define _ALS_IsValidAnimationLibrary__
	#define IsValidAnimationLibrary__( FIXES_IsValidAnimationLibrary(
#endif

/**
 * <remarks>
 * Get random colours that are valid for the given vehicle model.
 * </remarks>
 */

#if FIX_API
	#define FIXES_GetRandomCarColPair( _FIXES_GetRandomCarColPair(

	#if _FIXES_SAMP
		#define _ALS_GetRandomCarColPair
		#define GetRandomCarColPair( _FIXES_GetRandomCarColPair(
	#endif

	#define _ALS_GetRandomCarColPair__
	#define GetRandomCarColPair__( _FIXES_GetRandomCarColPair(
#endif

/**
 * <remarks>
 * Convert a car colour index to a HEX colour (RGBA).
 * </remarks>
 */

#if FIX_API
	stock FIXES_CarColIndexToColour(index, alpha = 0xFF)
	{
		if (_FIXES_IN_RANGE(index, 0, 256))
		{
			return FIXES_gscVehicleColours[index] | alpha;
		}
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_CarColIndexToColour
		#define CarColIndexToColour( FIXES_CarColIndexToColour(
	#endif

	#define _ALS_CarColIndexToColour__
	#define CarColIndexToColour__( FIXES_CarColIndexToColour(

	#if _FIXES_SAMP
		#define _ALS_CarColIndexToColor
		#define CarColIndexToColor( FIXES_CarColIndexToColour(
	#endif

	#define _ALS_CarColIndexToColor__
	#define CarColIndexToColor__( FIXES_CarColIndexToColour(
#endif

/**
 * <remarks>
 * Does this player have the global clock enabled?
 * </remarks>
 */

#if FIX_API
	stock bool:FIXES_PlayerHasClockEnabled(playerid)
	{
		return (_FIXES_IS_VALID_PLAYER(playerid) && (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_CLOCK_ENABLED));
	}

	#if _FIXES_SAMP
		#define _ALS_PlayerHasClockEnabled
		#define PlayerHasClockEnabled( FIXES_PlayerHasClockEnabled(
	#endif

	#define _ALS_PlayerHasClockEnabled__
	#define PlayerHasClockEnabled__( FIXES_PlayerHasClockEnabled(
#endif

/**
 * <remarks>
 * Is this menu valid?
 * </remarks>
 */

#if FIX_API
	stock bool:FIXES_IsMenuValid(Menu:menuid)
	{
		return FIXES_IS_VALID_MENU(menuid);
	}

	#if _FIXES_SAMP
		#define _ALS_IsMenuValid
		#define IsMenuValid( FIXES_IsMenuValid(
	#endif

	#define _ALS_IsMenuValid__
	#define IsMenuValid__( FIXES_IsMenuValid(
#endif

/*

    88888888888                                                       
    88                                  ,d                            
    88                                  88                            
    88aaaaa   ,adPPYba,    ,adPPYba,  MM88MMM  ,adPPYba,  8b,dPPYba,  
    88"""""  a8"     "8a  a8"     "8a   88    a8P_____88  88P'   "Y8  
    88       8b       d8  8b       d8   88    8PP"""""""  88          
    88       "8a,   ,a8"  "8a,   ,a8"   88,   "8b,   ,aa  88          
    88        `"YbbdP"'    `"YbbdP"'    "Y888  `"Ybbd8"'  88          



*/

// Clean up all internal defines.
#undef _FIXES_CEILDIV
#undef _FIXES_INFINITY
#undef _FIXES_N_INFINITY
#undef _FIXES_MIN_WORLDBOUNDS
#undef _FIXES_MAX_WORLDBOUNDS
#undef _FIXES_PROPERTY_OFFSET
#undef _FIXES_ATTACHMENTS
#undef _FIXES_FOREACH
#undef _FIXES_IS_UNSET
#undef _FIXES_IS_IN_CHARGE
#undef _FIXES_IS_VALID_PLAYER
#undef _FIXES_IN_RANGE
#undef _FIXES_NO_RANGE
#undef _FIXES_FORWARD
#undef _FIXES_IS_PLAYER_CONNECTED
#undef _FIXES_ENUM
#undef FIXES_PRINTF
#undef _FIXES_DEFAULT
#undef _FIXES_STOCK
#undef _FIXES_IS_NULL
#undef FIXES_SET
#undef FIXES_GET
#undef _FIXES_NEW_COMPILER

#endinput

// Fix documentation template.

/**
 * <fix name="" disabled="true" fixed="">
 *     <problem>
 *         A description of the problem.
 *     </problem>
 *     <solution>
 *         A description of the solution.
 *     </solution>
 *     <see>FIXES_FunctionWithFixIn</see>
 *     <author    href="github.com/account">Name</author>
 *     <post      href="burgershot.gg/post" />
 * </fix>
 */

// Fix inclusion template.

#if !defined FIX_NameOfFixHere
	_FIXES_STOCK FIX_NameOfFixHere = _FIXES_DEFAULT;
	#define FIX_NameOfFixHere                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_NameOfFixHere)
	#undef FIX_NameOfFixHere
	#define FIX_NameOfFixHere                    (2)
#endif

// Fix function template.

/**
 * <remarks>Information about fix here</remarks>
 * <fixes>NameOfFixHere</fixes>
 */

#if _FIXES_SAMP && defined _ALS_NameOfFixHere
	#error _ALS_NameOfFixHere defined
#endif
native BAD_NameOfFixHere(params) = NameOfFixHere;

/**
 * <remarks>Information about fix here</remarks>
 * <fixes>NameOfFixHere</fixes>
 */

#if FIX_NameOfFixHere
	stock FIXES_NameOfFixHere(params)
	{
		return 0;
	}

	// The trailing `(` is VERY important to keep future `native X() = Y;`s working.
	#if _FIXES_SAMP
		#define _ALS_NameOfFixHere
		#define NameOfFixHere( FIXES_NameOfFixHere(
	#endif

	#define _ALS_NameOfFixHere__
	#define NameOfFixHere__( FIXES_NameOfFixHere(
#else
	_FIXES_HIDE_PAWNDOC(FIXES_NameOfFixHere);
#endif

// Added API function template.

/**
 * <remarks>
 * 
 * </remarks>
 */

#if FIX_API
	stock FIXES_XXX(playerid)
	{
		return 0;
	}

	#if _FIXES_SAMP
		#define _ALS_XXX
		#define XXX( FIXES_XXX(
	#endif

	#define _ALS_XXX__
	#define XXX__( FIXES_XXX(
#else
	_FIXES_HIDE_PAWNDOC(FIXES_XXX);
#endif

