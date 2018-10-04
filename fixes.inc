/*
            ========================================================
             fixes.inc - Community patch for buggy SA:MP functions.
            ========================================================
*//**
<!--
<transition target[^/]+/>

:::::::: README ::::::::

To read the generated XML output, copy `pawndoc.xsl` to `pawno/xml/`.

This information goes very close to the top of the generated XML documentation
(because of include dependency orders), but doesn't appear in the visual output.

There is a bug in the compiler related to outputting documentation on state
transitions (<a href="https://github.com/Zeex/pawn/issues/184" />).  So after
generation of the XML file, you should clean it up with the following RegEx
replacement:

Search: <transition target[^/]+/>
Replace: (nothing)

This works 99% of the time, though you may get one where the corrupted target
includes the character `/`, in which case you should manually delete them.  Note
that YSI now includes manual documentation for transitions, but these all
include the parameter `keep="true"`, which exists simply to not match that
RegEx.  I also put the search at the top of this block so it is easier to find
in the output code.
-->
*//**
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
 *         #if defined _ALS_NameOfFixHere                                       <br /><indent />
 *             #error _ALS_NameOfFixHere defined                                <br />
 *         #endif                                                               <br />
 *         native BAD_NameOfFixHere(params) = NameOfFixHere;                    <br />
 *                                                                              <br />
 *         #if FIX_NameOfFixHere                                                <br /><indent />
 *             stock FIXES_NameOfFixHere(params)                                <br /><indent />
 *             {                                                                <br /><indent /><indent />
 *                 return 0;                                                    <br /><indent />
 *             }                                                                <br />
 *                                                                              <br /><indent />
 *             #define _ALS_NameOfFixHere                                       <br /><indent />
 *             #define NameOfFixHere( FIXES_NameOfFixHere(                      <br />
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

#if ((__Pawn & 0x0F) >= 0x0A) || ((__Pawn & 0xF0) >= 0xA0)
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
	#pragma warning disable 238
#endif

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

#define _FIXES_IS_UNSET(%0) ((2*%0-1+1)==-1)

#if !defined FIXES_EnableAll
	#define FIXES_EnableAll                      (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableAll)
	#undef FIXES_EnableAll
	#define FIXES_EnableAll                      (2)
#endif

#if !defined FIXES_EnableDeprecated
	#define FIXES_EnableDeprecated               (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableDeprecated)
	#undef FIXES_EnableDeprecated
	#define FIXES_EnableDeprecated               (2)
#endif

// We can add server version compiler code here to only compile fixes that apply
// to the version of the includes for which the user is compiling.
#if !defined FIX_GetPlayerColour
	#if defined FIX_GetPlayerColor
		#if _FIXES_IS_UNSET(FIX_GetPlayerColor)
			#define FIX_GetPlayerColour          (2)
		#else
			#define FIX_GetPlayerColour          (FIX_GetPlayerColor)
		#endif
	#else
		#define FIX_GetPlayerColour              (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerColour)
	#undef FIX_GetPlayerColour
	#define FIX_GetPlayerColour                  (2)
#endif

#if !defined FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT                     (1)
#elseif _FIXES_IS_UNSET(FIX_FILTERSCRIPT)
	#undef FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT                     (2)
#endif

#if !defined FIX_SpawnPlayer
	#define FIX_SpawnPlayer                      (1)
#elseif _FIXES_IS_UNSET(FIX_SpawnPlayer)
	#undef FIX_SpawnPlayer
	#define FIX_SpawnPlayer                      (2)
#endif

#if !defined FIX_SetPlayerName
	#define FIX_SetPlayerName                    (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerName)
	#undef FIX_SetPlayerName
	#define FIX_SetPlayerName                    (2)
#endif

#if !defined FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin                    (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerSkin)
	#undef FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin                    (2)
#endif

#if !defined FIX_GetWeaponName
	#if defined GetVehicleParamsSirenState
		#define FIX_GetWeaponName                (FIXES_EnableDeprecated)
	#else
		#define FIX_GetWeaponName                (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWeaponName)
	#undef FIX_GetWeaponName
	#define FIX_GetWeaponName                    (2)
#endif

#if !defined FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds             (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerWorldBounds)
	#undef FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds             (2)
#endif

#if !defined FIX_TogglePlayerControllable
	#if defined SetObjectMaterial
		#define FIX_TogglePlayerControllable     (FIXES_EnableDeprecated)
	#else
		#define FIX_TogglePlayerControllable     (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
	#undef FIX_TogglePlayerControllable
	#define FIX_TogglePlayerControllable         (2)
#endif

#if !defined FIX_HydraSniper
	#define FIX_HydraSniper                      (1)
#elseif _FIXES_IS_UNSET(FIX_HydraSniper)
	#undef FIX_HydraSniper
	#define FIX_HydraSniper                      (2)
#endif

#if !defined FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint             (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInCheckpoint)
	#undef FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint             (2)
#endif

#if !defined FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint         (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInRaceCheckpoint)
	#undef FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint         (2)
#endif

#if !defined FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon                  (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeapon)
	#undef FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon                  (2)
#endif

#if !defined FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle               (1)
#elseif _FIXES_IS_UNSET(FIX_PutPlayerInVehicle)
	#undef FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle               (2)
#endif

#if !defined FIX_KEY_AIM
	#if defined KEY_AIM
		#define FIX_KEY_AIM                      (FIXES_EnableDeprecated)
	#else
		#define FIX_KEY_AIM                      (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_KEY_AIM)
	#undef FIX_KEY_AIM
	#define FIX_KEY_AIM                          (2)
#endif

#if !defined FIX_SPECIAL_ACTION_PISSING
	#if defined SPECIAL_ACTION_PISSING
		#define FIX_SPECIAL_ACTION_PISSING       (FIXES_EnableDeprecated)
	#else
		#define FIX_SPECIAL_ACTION_PISSING       (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SPECIAL_ACTION_PISSING)
	#undef FIX_SPECIAL_ACTION_PISSING
	#define FIX_SPECIAL_ACTION_PISSING           (2)
#endif

#if !defined FIX_Natives
	#define FIX_Natives                          (1)
#elseif _FIXES_IS_UNSET(FIX_Natives)
	#undef FIX_Natives
	#define FIX_Natives                          (2)
#endif

#if !defined FIX_IsValidVehicle
	#if defined IsValidVehicle
		#define FIX_IsValidVehicle               (FIXES_EnableDeprecated)
	#else
		#define FIX_IsValidVehicle               (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_IsValidVehicle)
	#undef FIX_IsValidVehicle
	#define FIX_IsValidVehicle                   (2)
#endif

#if !defined FIX_GetGravity
	#if defined GetGravity
		#define FIX_GetGravity                   (FIXES_EnableDeprecated)
	#else
		#define FIX_GetGravity                   (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetGravity)
	#undef FIX_GetGravity
	#define FIX_GetGravity                       (2)
#endif

#if !defined FIX_gpci
	#if defined gpci
		#define FIX_gpci                         (FIXES_EnableDeprecated)
	#else
		#define FIX_gpci                         (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_gpci)
	#undef FIX_gpci
	#define FIX_gpci                             (2)
#endif

#if !defined FIX_WEAPONS
	#if defined WEAPON_FIST
		#define FIX_WEAPONS                      (FIXES_EnableDeprecated)
	#else
		#define FIX_WEAPONS                      (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_WEAPONS)
	#undef FIX_WEAPONS
	#define FIX_WEAPONS                          (2)
#endif

#if !defined FIX_BODYPARTS
	#if defined BODY_PART_LEFT_ARM
		#define FIX_BODYPARTS                    (FIXES_EnableDeprecated)
	#else
		#define FIX_BODYPARTS                    (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_BODYPARTS)
	#undef FIX_BODYPARTS
	#define FIX_BODYPARTS                        (2)
#endif

#if !defined FIX_CAMERAMODES
	#if defined CAM_MODE_NONE
		#define FIX_CAMERAMODES                  (FIXES_EnableDeprecated)
	#else
		#define FIX_CAMERAMODES                  (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_CAMERAMODES)
	#undef FIX_CAMERAMODES
	#define FIX_CAMERAMODES                      (2)
#endif

#if !defined FIX_DriveBy
	#define FIX_DriveBy                          (1)
#elseif _FIXES_IS_UNSET(FIX_DriveBy)
	#undef FIX_DriveBy
	#define FIX_DriveBy                          (2)
#endif

#if !defined FIX_SilentTeleport
    #define FIX_SilentTeleport                          (1)
#elseif _FIXES_IS_UNSET(FIX_SilentTeleport)
    #undef FIX_SilentTeleport
    #define FIX_SilentTeleport                          (2)
#endif

#if !defined FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint              (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCheckpoint)
	#undef FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint              (2)
#endif

#if !defined FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint          (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerRaceCheckpoint)
	#undef FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint          (2)
#endif

#if !defined FIX_TextDrawCreate
	#define FIX_TextDrawCreate                   (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate)
	#undef FIX_TextDrawCreate
	#define FIX_TextDrawCreate                   (2)
#endif

#if !defined FIX_TextDrawCreate_2
	#define FIX_TextDrawCreate_2                 (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate_2)
	#undef FIX_TextDrawCreate_2
	#define FIX_TextDrawCreate_2                 (2)
#endif

#if !defined FIX_TextDrawSetString
	#define FIX_TextDrawSetString                (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString)
	#undef FIX_TextDrawSetString
	#define FIX_TextDrawSetString                (2)
#endif

#if !defined FIX_TextDrawSetString_2
	#define FIX_TextDrawSetString_2              (1)
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString_2)
	#undef FIX_TextDrawSetString_2
	#define FIX_TextDrawSetString_2              (2)
#endif

#if !defined FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons             (1)
#elseif _FIXES_IS_UNSET(FIX_AllowInteriorWeapons)
	#undef FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons             (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle
	#if defined OnPlayerClickMap
		#define FIX_OnPlayerEnterVehicle         (FIXES_EnableDeprecated)
	#else
		#define FIX_OnPlayerEnterVehicle         (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle)
	#undef FIX_OnPlayerEnterVehicle
	#define FIX_OnPlayerEnterVehicle             (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle_2
	#define FIX_OnPlayerEnterVehicle_2           (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_2)
	#undef FIX_OnPlayerEnterVehicle_2
	#define FIX_OnPlayerEnterVehicle_2           (2)
#endif

#if !defined FIX_OnPlayerEnterVehicle_3
	#define FIX_OnPlayerEnterVehicle_3           (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_3)
	#undef FIX_OnPlayerEnterVehicle_3
	#define FIX_OnPlayerEnterVehicle_3           (2)
#endif

#if !defined FIX_AllowTeleport
	#if defined OnPlayerClickMap
		#define FIX_AllowTeleport                (1)
	#else
		#define FIX_AllowTeleport                (FIXES_EnableDeprecated)
	#endif
#elseif _FIXES_IS_UNSET(FIX_AllowTeleport)
	#undef FIX_AllowTeleport
	#define FIX_AllowTeleport                    (2)
#endif

#if !defined FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction           (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSpecialAction)
	#undef FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction           (2)
#endif

#if !defined FIX_ClearAnimations
	#define FIX_ClearAnimations                  (1)
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations)
	#undef FIX_ClearAnimations
	#define FIX_ClearAnimations                  (2)
#endif

#if !defined FIX_ClearAnimations_2
	#define FIX_ClearAnimations_2                (1)
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations_2)
	#undef FIX_ClearAnimations_2
	#define FIX_ClearAnimations_2                (2)
#endif

#if !defined FIX_GangZoneCreate
	#define FIX_GangZoneCreate                   (1)
#elseif _FIXES_IS_UNSET(FIX_GangZoneCreate)
	#undef FIX_GangZoneCreate
	#define FIX_GangZoneCreate                   (2)
#endif

#if !defined FIX_OnDialogResponse
	#if defined GetVehicleModelInfo
		#define FIX_OnDialogResponse             (FIXES_EnableDeprecated)
	#else
		#define FIX_OnDialogResponse             (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnDialogResponse)
	#undef FIX_OnDialogResponse
	#define FIX_OnDialogResponse                 (2)
#endif

#if !defined FIX_GetPlayerDialog
	#if defined GetPlayerDialog
		#define FIX_GetPlayerDialog              (FIXES_EnableDeprecated)
	#else
		#define FIX_GetPlayerDialog              (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerDialog)
	#undef FIX_GetPlayerDialog
	#define FIX_GetPlayerDialog                  (2)
#endif

#if !defined FIX_PlayerDialogResponse
	#define FIX_PlayerDialogResponse             (1)
#elseif _FIXES_IS_UNSET(FIX_PlayerDialogResponse)
	#undef FIX_PlayerDialogResponse
	#define FIX_PlayerDialogResponse             (2)
#endif

#if !defined FIX_SetSpawnInfo
	#if defined GetPlayerVersion
		#define FIX_SetSpawnInfo                 (FIXES_EnableDeprecated)
	#else
		#define FIX_SetSpawnInfo                 (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo)
	#undef FIX_SetSpawnInfo
	#define FIX_SetSpawnInfo                     (2)
#endif

#if !defined FIX_SetSpawnInfo_2
	#define FIX_SetSpawnInfo_2                   (1)
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo_2)
	#undef FIX_SetSpawnInfo_2
	#define FIX_SetSpawnInfo_2                   (2)
#endif

#if !defined FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin                    (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSkin)
	#undef FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin                    (2)
#endif

#if !defined FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (1)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (2)
#endif

#if !defined FIX_valstr
	#define FIX_valstr                           (1)
#elseif _FIXES_IS_UNSET(FIX_valstr)
	#undef FIX_valstr
	#define FIX_valstr                           (2)
#endif

#if !defined FIX_file_inc
	#define FIX_file_inc                         (FIXES_EnableAll)
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
	#define FIX_SetPlayerAttachedObject          (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerAttachedObject)
	#undef FIX_SetPlayerAttachedObject
	#define FIX_SetPlayerAttachedObject          (2)
#endif

#if !defined FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath                    (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDeath)
	#undef FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath                    (2)
#endif

#if !defined FIX_strins
	#define FIX_strins                           (1)
#elseif _FIXES_IS_UNSET(FIX_strins)
	#undef FIX_strins
	#define FIX_strins                           (2)
#endif

#if !defined FIX_IsPlayerConnected
	#define FIX_IsPlayerConnected                (1)
#elseif _FIXES_IS_UNSET(FIX_IsPlayerConnected)
	#undef FIX_IsPlayerConnected
	#define FIX_IsPlayerConnected                (2)
#endif

#if !defined FIX_TrainExit
	#define FIX_TrainExit                        (1)
#elseif _FIXES_IS_UNSET(FIX_TrainExit)
	#undef FIX_TrainExit
	#define FIX_TrainExit                        (2)
#endif

#if !defined FIX_Kick
	#if defined EnableVehicleFriendlyFire
		#define FIX_Kick                         (FIXES_EnableDeprecated)
	#else
		#define FIX_Kick                         (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_Kick)
	#undef FIX_Kick
	#define FIX_Kick                             (2)
#endif

#if !defined FIX_OnVehicleMod
	#define FIX_OnVehicleMod                     (1)
#elseif _FIXES_IS_UNSET(FIX_OnVehicleMod)
	#undef FIX_OnVehicleMod
	#define FIX_OnVehicleMod                     (2)
#endif

#if !defined FIX_random
	#define FIX_random                           (FIXES_EnableAll)
#elseif _FIXES_IS_UNSET(FIX_random)
	#undef FIX_random
	#define FIX_random                           (2)
#endif

#if !defined FIX_sleep
	#define FIX_sleep                            (1)
#elseif _FIXES_IS_UNSET(FIX_sleep)
	#undef FIX_sleep
	#define FIX_sleep                            (2)
#endif

#if !defined FIX_Menus
	#define FIX_Menus                            (1)
#elseif _FIXES_IS_UNSET(FIX_Menus)
	#undef FIX_Menus
	#define FIX_Menus                            (2)
#endif

#if !defined FIX_AddMenuItem
	#define FIX_AddMenuItem                      (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_AddMenuItem)
	#undef FIX_AddMenuItem
	#define FIX_AddMenuItem                      (2)
#endif

#if !defined FIX_SetMenuColumnHeader
	#define FIX_SetMenuColumnHeader              (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_SetMenuColumnHeader)
	#undef FIX_SetMenuColumnHeader
	#define FIX_SetMenuColumnHeader              (2)
#endif

#if !defined FIX_ShowMenuForPlayer
	#define FIX_ShowMenuForPlayer                (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_ShowMenuForPlayer)
	#undef FIX_ShowMenuForPlayer
	#define FIX_ShowMenuForPlayer                (2)
#endif

#if !defined FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer                (2)
#endif

#if !defined FIX_GetPlayerMenu
	#define FIX_GetPlayerMenu                    (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerMenu)
	#undef FIX_GetPlayerMenu
	#define FIX_GetPlayerMenu                    (2)
#endif

#if !defined FIX_HideMenuForPlayer_2
	#define FIX_HideMenuForPlayer_2              (FIXES_EnableAll)
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer_2)
	#undef FIX_HideMenuForPlayer_2
	#define FIX_HideMenuForPlayer_2              (2)
#elseif FIX_HideMenuForPlayer_2 && !FIX_GetPlayerMenu
	#error FIX_HideMenuForPlayer_2 requires FIX_GetPlayerMenu
#endif

#if !defined FIX_DisableMenu
	#define FIX_DisableMenu                      (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_DisableMenu)
	#undef FIX_DisableMenu
	#define FIX_DisableMenu                      (2)
#endif

#if !defined FIX_DisableMenuRow
	#define FIX_DisableMenuRow                   (FIX_Menus)
#elseif _FIXES_IS_UNSET(FIX_DisableMenuRow)
	#undef FIX_DisableMenuRow
	#define FIX_DisableMenuRow                   (2)
#endif

#if FIX_Menus || FIX_AddMenuItem || FIX_SetMenuColumnHeader || FIX_ShowMenuForPlayer || FIX_HideMenuForPlayer || FIX_DisableMenu || FIX_DisableMenuRow
	#define _FIX_Menus                           (1)
#else
	#define _FIX_Menus                           (2)
#endif

#if !defined FIX_GetPlayerInterior
	#define FIX_GetPlayerInterior                (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerInterior)
	#undef FIX_GetPlayerInterior
	#define FIX_GetPlayerInterior                (2)
#endif

#if !defined FIX_ApplyAnimation
	#define FIX_ApplyAnimation                   (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation)
	#undef FIX_ApplyAnimation
	#define FIX_ApplyAnimation                   (2)
#endif

#if !defined FIX_ApplyAnimation_2
	#define FIX_ApplyAnimation_2                 (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation_2)
	#undef FIX_ApplyAnimation_2
	#define FIX_ApplyAnimation_2                 (2)
#endif

#if !defined FIX_ApplyActorAnimation
	#define FIX_ApplyActorAnimation              (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation)
	#undef FIX_ApplyActorAnimation
	#define FIX_ApplyActorAnimation              (2)
#endif

#if !defined FIX_ApplyActorAnimation_2
	#define FIX_ApplyActorAnimation_2            (1)
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation_2)
	#undef FIX_ApplyActorAnimation_2
	#define FIX_ApplyActorAnimation_2            (2)
#endif

#if !defined FIX_OnPlayerSpawn
	#define FIX_OnPlayerSpawn                    (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerSpawn)
	#undef FIX_OnPlayerSpawn
	#define FIX_OnPlayerSpawn                    (2)
#endif

#if !defined FIX_GameText
	#define FIX_GameText                         (1)
#elseif _FIXES_IS_UNSET(FIX_GameText)
	#undef FIX_GameText
	#define FIX_GameText                         (2)
#endif

#if !defined FIX_HideGameText
	#if defined HideGameText
		#define FIX_HideGameText                 (FIXES_EnableDeprecated)
	#else
		#define FIX_HideGameText                 (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_HideGameText)
	#undef FIX_HideGameText
	#define FIX_HideGameText                     (2)
#endif

#if !defined FIX_GetPlayerWorldBounds
	#if defined GetPlayerWorldBounds
		#define FIX_GetPlayerWorldBounds         (FIXES_EnableDeprecated)
	#else
		#define FIX_GetPlayerWorldBounds         (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWorldBounds)
	#undef FIX_GetPlayerWorldBounds
	#define FIX_GetPlayerWorldBounds             (2)
#endif

#if !defined FIX_ClearPlayerWorldBounds
	#if defined ClearPlayerWorldBounds
		#define FIX_ClearPlayerWorldBounds       (FIXES_EnableDeprecated)
	#else
		#define FIX_ClearPlayerWorldBounds       (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_ClearPlayerWorldBounds)
	#undef FIX_ClearPlayerWorldBounds
	#define FIX_ClearPlayerWorldBounds           (2)
#endif

#if !defined FIX_GameTextStyles
	#define FIX_GameTextStyles                   (FIXES_EnableAll)
#elseif _FIXES_IS_UNSET(FIX_GameTextStyles)
	#undef FIX_GameTextStyles
	#define FIX_GameTextStyles                   (2)
#elseif FIX_GameTextStyles && !FIX_GameText
	#error FIX_GameTextStyles requires FIX_GameText
#endif

#if !defined FIX_OnPlayerConnect
	#define FIX_OnPlayerConnect                  (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerConnect)
	#undef FIX_OnPlayerConnect
	#define FIX_OnPlayerConnect                  (2)
#endif

#if !defined FIX_OnPlayerDisconnect
	#define FIX_OnPlayerDisconnect               (1)
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDisconnect)
	#undef FIX_OnPlayerDisconnect
	#define FIX_OnPlayerDisconnect               (2)
#endif

#if !defined FIX_CreatePlayerTextDraw
	#define FIX_CreatePlayerTextDraw             (1)
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw)
	#undef FIX_CreatePlayerTextDraw
	#define FIX_CreatePlayerTextDraw             (2)
#endif

#if !defined FIX_CreatePlayerTextDraw_2
	#define FIX_CreatePlayerTextDraw_2           (1)
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw_2)
	#undef FIX_CreatePlayerTextDraw_2
	#define FIX_CreatePlayerTextDraw_2           (2)
#endif

#if !defined FIX_PlayerTextDrawSetString
	#define FIX_PlayerTextDrawSetString          (1)
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString)
	#undef FIX_PlayerTextDrawSetString
	#define FIX_PlayerTextDrawSetString          (2)
#endif

#if !defined FIX_PlayerTextDrawSetString_2
	#define FIX_PlayerTextDrawSetString_2        (1)
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString_2)
	#undef FIX_PlayerTextDrawSetString_2
	#define FIX_PlayerTextDrawSetString_2        (2)
#endif

#if !defined FIX_SetPlayerCamera
	#define FIX_SetPlayerCamera                  (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCamera)
	#undef FIX_SetPlayerCamera
	#define FIX_SetPlayerCamera                  (2)
#endif

#if !defined FIX_SetPlayerTime
	#define FIX_SetPlayerTime                    (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerTime)
	#undef FIX_SetPlayerTime
	#define FIX_SetPlayerTime                    (2)
#endif

#if !defined FIX_OnPlayerRequestClass
	#define FIX_OnPlayerRequestClass             (1)
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
		#define FIX_SetPlayerColour              (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetPlayerColour)
	#undef FIX_SetPlayerColour
	#define FIX_SetPlayerColour                  (2)
#endif

#if !defined FIX_FileMaths
	#define FIX_FileMaths                        (1)
#elseif _FIXES_IS_UNSET(FIX_FileMaths)
	#undef FIX_FileMaths
	#define FIX_FileMaths                        (2)
#endif

#if !defined FIX_GetPlayerWeaponData
	#define FIX_GetPlayerWeaponData              (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeaponData)
	#undef FIX_GetPlayerWeaponData
	#define FIX_GetPlayerWeaponData              (2)
#endif

#if !defined FIX_strcmp
	#define FIX_strcmp                           (1)
#elseif _FIXES_IS_UNSET(FIX_strcmp)
	#undef FIX_strcmp
	#define FIX_strcmp                           (2)
#endif

#if !defined FIX_GetPVarString
	#define FIX_GetPVarString                    (FIXES_EnableAll)
#elseif _FIXES_IS_UNSET(FIX_GetPVarString)
	#undef FIX_GetPVarString
	#define FIX_GetPVarString                    (2)
#endif

#if !defined FIX_GetSVarString
	#define FIX_GetSVarString                    (FIXES_EnableAll)
#elseif _FIXES_IS_UNSET(FIX_GetSVarString)
	#undef FIX_GetSVarString
	#define FIX_GetSVarString                    (2)
#endif

#if !defined FIX_toupper
	#define FIX_toupper                          (1)
#elseif _FIXES_IS_UNSET(FIX_toupper)
	#undef FIX_toupper
	#define FIX_toupper                          (2)
#endif

#if !defined FIX_tolower
	#define FIX_tolower                          (1)
#elseif _FIXES_IS_UNSET(FIX_tolower)
	#undef FIX_tolower
	#define FIX_tolower                          (2)
#endif

#if !defined FIX_ispacked
	#define FIX_ispacked                         (1)
#elseif _FIXES_IS_UNSET(FIX_ispacked)
	#undef FIX_ispacked
	#define FIX_ispacked                         (2)
#endif

#if !defined FIX_PassengerSeating
	#define FIX_PassengerSeating                 (1)
#elseif _FIXES_IS_UNSET(FIX_PassengerSeating)
	#undef FIX_PassengerSeating
	#define FIX_PassengerSeating                 (2)
#endif

#if !defined FIX_GogglesSync
	#define FIX_GogglesSync                      (1)
#elseif _FIXES_IS_UNSET(FIX_GogglesSync)
	#undef FIX_GogglesSync
	#define FIX_GogglesSync                      (2)
#endif

#if !defined FIX_GetPlayerPoolSize
	#define FIX_GetPlayerPoolSize                (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerPoolSize)
	#undef FIX_GetPlayerPoolSize
	#define FIX_GetPlayerPoolSize                (2)
#endif

#if !defined FIX_SetPlayerPos
	#define FIX_SetPlayerPos                     (1)
#elseif _FIXES_IS_UNSET(FIX_SetPlayerPos)
	#undef FIX_SetPlayerPos
	#define FIX_SetPlayerPos                     (2)
#endif

#if !defined FIX_GetPlayerAmmo
	#define FIX_GetPlayerAmmo                    (1)
#elseif _FIXES_IS_UNSET(FIX_GetPlayerAmmo)
	#undef FIX_GetPlayerAmmo
	#define FIX_GetPlayerAmmo                    (2)
#endif

#if !defined FIX_JIT
	#define FIX_JIT                              (1)
#elseif _FIXES_IS_UNSET(FIX_JIT)
	#undef FIX_JIT
	#define FIX_JIT                              (2)
#endif

#if !defined FIX_OS
	#define FIX_OS                               (1)
#elseif _FIXES_IS_UNSET(FIX_OS)
	#undef FIX_OS
	#define FIX_OS                               (2)
#endif

#if !defined FIX_const
	#define FIX_const                            (1)
#elseif _FIXES_IS_UNSET(FIX_const)
	#undef FIX_const
	#define FIX_const                            (2)
#endif

#if !defined FIX_VEHICLES
	#if defined VEHICLE_INFERNUS
		#define FIX_VEHICLES                     (FIXES_EnableDeprecated)
	#else
		#define FIX_VEHICLES                     (1)
	#endif
#elseif _FIXES_IS_UNSET(FIX_VEHICLES)
	#undef FIX_VEHICLES
	#define FIX_VEHICLES                         (2)
#endif

#if !defined FIX_GetPlayerWeather
	#if defined GetPlayerWeather
		#define FIX_GetPlayerWeather             (FIXES_EnableDeprecated)
	#else
		#define FIX_GetPlayerWeather             (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeather)
	#undef FIX_GetPlayerWeather
	#define FIX_GetPlayerWeather                 (2)
#endif

#if !defined FIX_GetWeather
	#if defined GetWeather
		#define FIX_GetWeather                   (FIXES_EnableDeprecated)
	#else
		#define FIX_GetWeather                   (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWeather)
	#undef FIX_GetWeather
	#define FIX_GetWeather                       (2)
#endif

#if !defined FIX_GetWorldTime
	#if defined GetWorldTime
		#define FIX_GetWorldTime                 (FIXES_EnableDeprecated)
	#else
		#define FIX_GetWorldTime                 (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWorldTime)
	#undef FIX_GetWorldTime
	#define FIX_GetWorldTime                     (2)
#endif

#if !defined FIX_GetServerVarAsString
	#define FIX_GetServerVarAsString             (1)
#elseif _FIXES_IS_UNSET(FIX_GetServerVarAsString)
	#undef FIX_GetServerVarAsString
	#define FIX_GetServerVarAsString             (2)
#endif

#if !defined FIX_GetServerVarAsInt
	#define FIX_GetServerVarAsInt                (1)
#elseif _FIXES_IS_UNSET(FIX_GetServerVarAsInt)
	#undef FIX_GetServerVarAsInt
	#define FIX_GetServerVarAsInt                (2)
#endif

#if !defined FIX_GetServerVarAsBool
	#define FIX_GetServerVarAsBool               (1)
#elseif _FIXES_IS_UNSET(FIX_GetServerVarAsBool)
	#undef FIX_GetServerVarAsBool
	#define FIX_GetServerVarAsBool               (2)
#endif

#if !defined FIX_GetServerVarAsFloat
	#if defined GetServerVarAsFloat
		#if FIX_GetServerVarAsString
			#define FIX_GetServerVarAsFloat      (1)
		#else
			#define FIX_GetServerVarAsFloat      (FIXES_EnableDeprecated)
		#endif
	#else
		#define FIX_GetServerVarAsFloat          (FIX_Natives)
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetServerVarAsFloat)
	#undef FIX_GetServerVarAsFloat
	#define FIX_GetServerVarAsFloat              (2)
#endif

#if !defined FIX_tabsize
	#define FIX_tabsize                          (1)
#elseif _FIXES_IS_UNSET(FIX_tabsize)
	#undef FIX_tabsize
	#define FIX_tabsize                          (2)
#endif

#if !defined FIX_Callbacks
	#define FIX_Callbacks                        (1)
#elseif _FIXES_IS_UNSET(FIX_Callbacks)
	#undef FIX_Callbacks
	#define FIX_Callbacks                        (2)
#endif

#if !defined FIX_OnRconCommand
	#define FIX_OnRconCommand                    (FIX_Callbacks)
#elseif _FIXES_IS_UNSET(FIX_OnRconCommand)
	#undef FIX_OnRconCommand
	#define FIX_OnRconCommand                    (2)
#endif

#if !defined FIX_OnClientCheckResponse
	#define FIX_OnClientCheckResponse            (FIX_Callbacks)
#elseif _FIXES_IS_UNSET(FIX_OnClientCheckResponse)
	#undef FIX_OnClientCheckResponse
	#define FIX_OnClientCheckResponse            (2)
#endif

/**
 * <remarks>
 * tabsize
 *
 * Breaks `#pragma tabsize 0` in such a way that the compiler gives the
 * following error:
 *
 *     error 017: undefined symbol "do_not_use_tabsize_0"
 *
 * There is ZERO reason to use it.  There are ocassionally times when an
 * indentation reset is required, usually because of macros containing code that
 * would otherwise appear correct.  For example:
 *
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
 *
 * Even that can be fixed without `tabsize 0`, simply by restating the correct
 * indentation level, which resets the internal depth tracking:
 *
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
 *
 * There is just no excuse.
 * </remarks>
 */

#if FIX_tabsize
	#define tabsize%00%0\10;%0 _DUMMY_do_not_use_tabsize_0
#endif

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

/**
 * <remarks>
 * The number of GameText styles recreated using TextDraw functions.  This is 4
 * by default, but can be extended to 6 if you want location and vehicle styles.
 * </remarks>
 */

#if FIX_GameText
	#if FIX_GameTextStyles
		#define FIXES_GT_STYLE_COUNT (14)
	#else
		#define FIXES_GT_STYLE_COUNT (7)
	#endif
#endif

/**
 * <remarks>
 * If this define is set to 1, then players will not be given a message when
 * they are kicked for cheats, instead they will just loose connection to the
 * server.
 * </remarks>
 */

#if !defined FIXES_SilentKick
	#define FIXES_SilentKick 0
#elseif _FIXES_IS_UNSET(FIXES_SilentKick)
	#undef FIXES_SilentKick
	#define FIXES_SilentKick 2
#endif

/**
 * <remarks>
 * If this define is set to 1, then debug printing is turned on for any
 * functions which may use it.  Otherwise, the compiler entirely removes the
 * code to print anything, leaving 0 run-time overhead.
 * </remarks>
 */

#if defined FIXES_Debug
	#if _FIXES_IS_UNSET(FIXES_Debug)
		#undef FIXES_Debug
	#elseif FIXES_Debug == 1
		#define FIXES_PRINTF(%0); print(_FIXES_gIsFilterscript ? ("* FIXES_PRINTF (FS):") : ("* FIXES_PRINTF (GM):")),printf("*** " %0);
	#else
		#undef FIXES_Debug
	#endif
#endif

/**
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>GetServerVarAsString</see> and related functions are used without a
 * valid directory redirect.
 * </remarks>
 */

#if !defined FIXES_ServerVarMsg
	#define FIXES_ServerVarMsg 1
#elseif _FIXES_IS_UNSET(FIXES_ServerVarMsg)
	#undef FIXES_ServerVarMsg
	#define FIXES_ServerVarMsg 2
#endif

/**
 * <remarks>
 * A marker to indicate that this version of fixes.inc uses state-based hooks.
 * </remarks>
 */
#define FIXES_UseStateHooks

/**
 * <remarks>
 * A special "printf" function only compiled when "FIXES_Debug" is set.
 * </remarks>
 */

#if !defined FIXES_PRINTF
	#define FIXES_Debug 0
	#define FIXES_PRINTF(%0);
#endif

/**
 * <remarks>
 * INVALID_DIALOG_ID
 *
 * Set when a player can't see a dialog.
 * </remarks>
 */

#if !defined INVALID_DIALOG_ID
	#define INVALID_DIALOG_ID (-1)
#endif

/**
 * <remarks>
 * If this define is set to 1, then the old style include is used, with no
 * support for multiple scripts running at the same time on the server (i.e. no
 * gamemodes and filter scripts at the same time).  You can only have one or the
 * other or bugs.
 * </remarks>
 */

#if !defined FIXES_Single
	#define FIXES_Single (1)
#elseif _FIXES_IS_UNSET(FIXES_Single)
	#undef FIXES_Single
	#define FIXES_Single (2)
#endif

/**
 * <remarks>
 * _FIXES_IS_IN_CHARGE
 *
 * Test to see if this script is in command or not (master).
 * </remarks>
 */

#if FIXES_Single
	#define _FIXES_IS_IN_CHARGE(%0)
#else
	#define _FIXES_IS_IN_CHARGE(%0) if (%0(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
#endif

/**
 */

#if FIXES_Single
	#define FIXES_SET(%0,%1,%2) (FIXES_gs%0[%1] = %2)
#else
	#define FIXES_SET(%0,%1,%2) SetPVarInt(%1, FIXES_pvar%0, %2)
#endif

/**
 */

#if FIXES_Single
	#define FIXES_GET(%0,%1) (FIXES_gs%0[%1])
#else
	#define FIXES_GET(%0,%1) GetPVarInt(%1, FIXES_pvar%0)
#endif

/**
 * <remarks>
 * isnull
 *
 * Pretty standard.
 * </remarks>
 */

#define isnull(%0) ((%0[(%0[0])=='\1'])=='\0')

/**
 * <remarks>
 * E_FIXES_WORLDBOUND_DATA
 *
 * Store data for each player on their worldbound data.
 * </remarks>
 */
_FIXES_ENUM E_FIXES_WORLDBOUND_DATA
{
	// "Previous".
	Float:E_FIXES_WORLDBOUND_DATA_PX,
	Float:E_FIXES_WORLDBOUND_DATA_PY,
	Float:E_FIXES_WORLDBOUND_DATA_PZ,
	// "Lower".
	Float:E_FIXES_WORLDBOUND_DATA_LX,
	Float:E_FIXES_WORLDBOUND_DATA_LY,
	// "Upper".
	Float:E_FIXES_WORLDBOUND_DATA_UX,
	Float:E_FIXES_WORLDBOUND_DATA_UY
}

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

/**
 * <remarks>
 * _FIXES_CEILDIV
 *
 * Do a ceiling division of the first number by the second number.
 * </remarks>
 */
#define _FIXES_CEILDIV(%0,%1) (((%0) + (%1) - 1) / (%1))

/**
 * <remarks>
 * _FIXES_MIN_WORLDBOUNDS
 *
 * Default worldbound range.
 * </remarks>
 */
#define _FIXES_MIN_WORLDBOUNDS (-20000.0)

/**
 * <remarks>
 * _FIXES_MAX_WORLDBOUNDS
 *
 * Default worldbound range.
 * </remarks>
 */
#define _FIXES_MAX_WORLDBOUNDS (20000.0)

/**
 * <remarks>
 * _FIXES_INFINITY
 *
 * IEEE 754 definition of infinity.
 * </remarks>
 */
#define _FIXES_INFINITY (Float:0x7F800000)

/**
 * <remarks>
 * _FIXES_N_INFINITY
 *
 * IEEE 754 definition of negative infinity.
 * </remarks>
 */
#define _FIXES_N_INFINITY (Float:0xFF800000)

/**
 * <remarks>
 * _FIXES_ATTACHMENTS
 *
 * The number of players whose attachment data (10-bits) can be stored in one
 * cell.
 * </remarks>
 */
#define _FIXES_ATTACHMENTS (cellbits / MAX_PLAYER_ATTACHED_OBJECTS)

/**
 * <remarks>
 * _FIXES_FOREACH
 *
 * A new version of "foreach", but just for this library.
 * </remarks>
 */
#define _FIXES_FOREACH(%1,%0) for (new %0 = MAX_PLAYERS; (%0 = %1[%0]) != MAX_PLAYERS; )

/**
 * <remarks>
 * _FIXES_IN_RANGE
 *
 * Checks if the first parameter is between the other two: %1 &lt;= %0 &lt;%2 (but
 * faster).
 * </remarks>
 */
#define _FIXES_IN_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) < ((%2) - ((%1) + cellmin)))

/**
 * <remarks>
 * _FIXES_NO_RANGE
 *
 * Checks if the first parameter is not between the other two:
 * <c>!(%1 &lt;= %0 &lt; %2)</c>(but faster).
 * </remarks>
 */
#define _FIXES_NO_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) >= ((%2) - ((%1) + cellmin)))

/**
 * <remarks>
 * _FIXES_FORWARD
 *
 * Forwards a hooked callbacks, and defines the default state implementations.
 * </remarks>
 */
#define _FIXES_FORWARD%0(%1); \
	forward%0(%1); \
	public%0(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> { return 1; } \
	public%0(%1) <> { return 1; }

/**
 * <remarks>
 * _FIXES_IS_PLAYER_CONNECTED
 *
 * Always valid "IsPlayerConnected" check.
 * </remarks>
 */
#define _FIXES_IS_PLAYER_CONNECTED(%0) (_FIXES_IN_RANGE((%0), 0, MAX_PLAYERS) && IsPlayerConnected((%0)))

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

stock const
	/**
	 * <remarks>
	 * A single re-usable null string.  Const not static because it is used in
	 * macros `HideGameTextForAll` and `HideGameTextForPlayer`.
	 * </remarks>
	 */
	FIXES_gcNull[] = "\1";

#if FIXES_Debug
new
#else
static stock
#endif
	/**
	 * <remarks>
	 * A single re-usable space.  Static not const because it is used in this
	 * file in functions that don't take `const` strings.
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
	FIXES_gsValidMenus[_FIXES_CEILDIV(MAX_MENUS, cellbits)],
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
	 * is currently trying to enter
	 * </remarks>
	 */
#if FIX_OnPlayerEnterVehicle_3
	FIXES_gsPlayerVehicleID[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Stores the server tick when the player started
	 * trying to enter the locked vehicle
	 * </remarks>
	 */
	FIXES_gsPlayerVehicleTickCount[MAX_PLAYERS],
	/**
	 * <remarks>
	 * Boolean: Stores if a certain vehicle is 'locked' or not
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
	 * </remarks>
	 */
#if FIX_SetPlayerWorldBounds || FIX_GetPlayerWorldBounds
	FIXES_gsWorldbounds[MAX_PLAYERS][E_FIXES_WORLDBOUND_DATA],
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
	 * Stores the ID of the server weather.
	 * </remarks>
	 */
#if FIX_GetWorldTime
	FIXES_gsWorldTime = 12,
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
	FIXES_gsPlayerAnimName[MAX_PLAYERS][60],
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
	FIXES_gsActorAnimName[MAX_ACTORS][60],
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
	 * The position of the character right-trimmed from a "const" string.
	 * </remarks>
	 */
	FIXES_gsTrimPos,
	/**
	 * <remarks>
	 * The character right-trimmed from a "const" string.
	 * </remarks>
	 */
	FIXES_gsTrimChr,
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
	 * The timers used to prevent players seating.
	 * </remarks>
	 */
#if FIX_PassengerSeating
	FIXES_gsPSTimer[MAX_PLAYERS],
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
	FIXES_gscNULL[] = "\1";

static stock const
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
#if FIX_GetPlayerColour
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
#if FIX_OnPlayerEnterVehicle
	FIXES_gscMaxPassengers[] =
		{
			0x10331113, 0x11311131, 0x11331313, 0x80133301, 0x1381F110, 0x10311103, 0x10001F10, 0x11113311, 0x13113311,
			0x31101100, 0x30002301, 0x11031311, 0x11111331, 0x10013111, 0x01131100, 0x11111110, 0x11100031, 0x11130221,
			0x33113311, 0x11111101, 0x33101133, 0x10100550, 0x03133111, 0xFF11113F, 0x13330111, 0xFF131111, 0x0000FF3F
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
#if FIX_OnVehicleMod
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
#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2
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
#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2
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
	 * Error shown when multiple scripts are detected with <c>FIXES_SINGLE</c>.
	 * </remarks>
	 */
	FIXES_gscMultiScriptError[] = "\7\7\7\7\7"                                               "\n"   \
		"*** fixes.inc error: Running multiple scripts compiled with \"fixes.inc\"..."       "\n"   \
		"***     Please compile your modes with \"#define FIXES_Single 0\" at the top, as"   "\n"   \
		"***     this setting is no longer the default (to improve the more common case)."          ;

/**
 * <remarks>
 * <c>_FIXES_KEY_AIM</c>
 * <c>KEY_AIM</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

#define _FIXES_KEY_AIM                   (128)
#if FIX_KEY_AIM
	#define KEY_AIM                      _FIXES_KEY_AIM
#endif

/**
 * <remarks>
 * <c>_FIXES_SPECIAL_ACTION_PISSING</c>
 * <c>SPECIAL_ACTION_PISSING</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

#define _FIXES_SPECIAL_ACTION_PISSING    (68)
#if FIX_SPECIAL_ACTION_PISSING
	#define SPECIAL_ACTION_PISSING       _FIXES_SPECIAL_ACTION_PISSING
#endif

/**
 * <remarks>
 * <c>IsValidVehicle</c>
 *
 * Because the default SA:MP includes missed this one.
 * </remarks>
 */

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
	#if defined _ALS_ApplyActorAnimation
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
		#if defined _ALS_HTTP
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
	#if defined _ALS_SetObjectMaterial
		#error _ALS_SetObjectMaterial defined
	#endif
	native CST_SetObjectMaterial(objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor=0) = SetObjectMaterial;
	#define _ALS_SetObjectMaterial
	#define SetObjectMaterial( CST_SetObjectMaterial(
	#if defined _ALS_SetPlayerObjectMaterial
		#error _ALS_SetPlayerObjectMaterial defined
	#endif
	native CST_SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor=0) = SetPlayerObjectMaterial;
	#define _ALS_SetPlayerObjectMaterial
	#define SetPlayerObjectMaterial( CST_SetPlayerObjectMaterial(
	#if defined _ALS_SetObjectMaterialText
		#error _ALS_SetObjectMaterialText defined
	#endif
	native CST_SetObjectMaterialText(objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetObjectMaterialText;
	#define _ALS_SetObjectMaterialText
	#define SetObjectMaterialText( CST_SetObjectMaterialText(
	#if defined _ALS_SetPlayerObjMaterialText
		#error _ALS_SetPlayerObjMaterialText defined
	#endif
	native CST_SetPlayerObjectMaterialText(playerid, objectid, const text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0) = SetPlayerObjectMaterialText;
	#define _ALS_SetPlayerObjMaterialText
	#define SetPlayerObjectMaterialText( CST_SetPlayerObjectMaterialText(

	// a_players
	#if defined _ALS_PlayAudioStreamForPlayer
		#error _ALS_PlayAudioStreamForPlayer defined
	#endif
	native CST_PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0) = PlayAudioStreamForPlayer;
	#define _ALS_PlayAudioStreamForPlayer
	#define PlayAudioStreamForPlayer( CST_PlayAudioStreamForPlayer(
	#if defined _ALS_SetPlayerShopName
		#error _ALS_SetPlayerShopName defined
	#endif
	native CST_SetPlayerShopName(playerid, const shopname[]) = SetPlayerShopName;
	#define _ALS_SetPlayerShopName
	#define SetPlayerShopName( CST_SetPlayerShopName(
	#if defined _ALS_CreatePlayerTextDraw
		#error _ALS_CreatePlayerTextDraw defined
	#endif
	native PlayerText:CST_CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[]) = CreatePlayerTextDraw;
	native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
	#define _ALS_CreatePlayerTextDraw
	#define CreatePlayerTextDraw( CST_CreatePlayerTextDraw(
	#if defined _ALS_PlayerTextDrawSetString
		#error _ALS_PlayerTextDrawSetString defined
	#endif
	native CST_PlayerTextDrawSetString(playerid, PlayerText:text, const string[]) = PlayerTextDrawSetString;
	native BAD_PlayerTextDrawSetString(playerid, PlayerText:text, string[]) = PlayerTextDrawSetString;
	#define _ALS_PlayerTextDrawSetString
	#define PlayerTextDrawSetString( CST_PlayerTextDrawSetString(
	#if defined _ALS_SetPVarInt
		#error _ALS_SetPVarInt defined
	#endif
	native CST_SetPVarInt(playerid, const varname[], int_value) = SetPVarInt;
	#define _ALS_SetPVarInt
	#define SetPVarInt( CST_SetPVarInt(
	#if defined _ALS_GetPVarInt
		#error _ALS_GetPVarInt defined
	#endif
	native CST_GetPVarInt(playerid, const varname[]) = GetPVarInt;
	#define _ALS_GetPVarInt
	#define GetPVarInt( CST_GetPVarInt(
	#if defined _ALS_SetPVarString
		#error _ALS_SetPVarString defined
	#endif
	native CST_SetPVarString(playerid, const varname[], const string_value[]) = SetPVarString;
	#define _ALS_SetPVarString
	#define SetPVarString( CST_SetPVarString(
	#if defined _ALS_GetPVarString
		#error _ALS_GetPVarString defined
	#endif
	native CST_GetPVarString(playerid, const varname[], string_return[], len) = GetPVarString;
	native BAD_GetPVarString(playerid, varname[], string_return[], len) = GetPVarString;
	#define _ALS_GetPVarString
	#define GetPVarString( CST_GetPVarString(
	#if defined _ALS_SetPVarFloat
		#error _ALS_SetPVarFloat defined
	#endif
	native CST_SetPVarFloat(playerid, const varname[], Float:float_value) = SetPVarFloat;
	#define _ALS_SetPVarFloat
	#define SetPVarFloat( CST_SetPVarFloat(
	#if defined _ALS_GetPVarFloat
		#error _ALS_GetPVarFloat defined
	#endif
	native Float:CST_GetPVarFloat(playerid, const varname[]) = GetPVarFloat;
	#define _ALS_GetPVarFloat
	#define GetPVarFloat( CST_GetPVarFloat(
	#if defined _ALS_DeletePVar
		#error _ALS_DeletePVar defined
	#endif
	native CST_DeletePVar(playerid, const varname[]) = DeletePVar;
	#define _ALS_DeletePVar
	#define DeletePVar( CST_DeletePVar(
	#if defined _ALS_GetPVarType
		#error _ALS_GetPVarType defined
	#endif
	native CST_GetPVarType(playerid, const varname[]) = GetPVarType;
	#define _ALS_GetPVarType
	#define GetPVarType( CST_GetPVarType(
	#if defined _ALS_SetPlayerChatBubble
		#error _ALS_SetPlayerChatBubble defined
	#endif
	native CST_SetPlayerChatBubble(playerid, const text[], color, Float:drawdistance, expiretime) = SetPlayerChatBubble;
	#define _ALS_SetPlayerChatBubble
	#define SetPlayerChatBubble( CST_SetPlayerChatBubble(
	#if defined _ALS_ApplyAnimation
		#error _ALS_ApplyAnimation defined
	#endif
	native CST_ApplyAnimation(playerid, const animlib[], const animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
	native BAD_ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0) = ApplyAnimation;
	#define _ALS_ApplyAnimation
	#define ApplyAnimation( CST_ApplyAnimation(
	#if defined _ALS_StartRecordingPlayerData
		#error _ALS_StartRecordingPlayerData defined
	#endif
	native CST_StartRecordingPlayerData(playerid, recordtype, const recordname[]) = StartRecordingPlayerData;
	#define _ALS_StartRecordingPlayerData
	#define StartRecordingPlayerData( CST_StartRecordingPlayerData(

	// a_samp
	#if defined _ALS_SetTimer
		#error _ALS_SetTimer defined
	#endif
	native CST_SetTimer(const funcname[], interval, repeating) = SetTimer;
	#define _ALS_SetTimer
	#define SetTimer( CST_SetTimer(
	#if defined _ALS_SetTimerEx
		#error _ALS_SetTimerEx defined
	#endif
	native CST_SetTimerEx(const funcname[], interval, repeating, const format[], {Float,_}:...) = SetTimerEx;
	#define _ALS_SetTimerEx
	#define SetTimerEx( CST_SetTimerEx(
	#if defined _ALS_SHA256_PassHash
		#error _ALS_SHA256_PassHash defined
	#endif
	native CST_SHA256_PassHash(const password[], const salt[], ret_hash[], ret_hash_len) = SHA256_PassHash;
	#define _ALS_SHA256_PassHash // SHA256 for password hashing
	#define SHA256_PassHash( CST_SHA256_PassHash(
	#if defined _ALS_SetSVarInt
		#error _ALS_SetSVarInt defined
	#endif
	native CST_SetSVarInt(const varname[], int_value) = SetSVarInt;
	#define _ALS_SetSVarInt
	#define SetSVarInt( CST_SetSVarInt(
	#if defined _ALS_GetSVarInt
		#error _ALS_GetSVarInt defined
	#endif
	native CST_GetSVarInt(const varname[]) = GetSVarInt;
	#define _ALS_GetSVarInt
	#define GetSVarInt( CST_GetSVarInt(
	#if defined _ALS_SetSVarString
		#error _ALS_SetSVarString defined
	#endif
	native CST_SetSVarString(const varname[], const string_value[]) = SetSVarString;
	#define _ALS_SetSVarString
	#define SetSVarString( CST_SetSVarString(
	#if defined _ALS_GetSVarString
		#error _ALS_GetSVarString defined
	#endif
	native CST_GetSVarString(const varname[], string_return[], len) = GetSVarString;
	native BAD_GetSVarString(varname[], string_return[], len) = GetSVarString;
	#define _ALS_GetSVarString
	#define GetSVarString( CST_GetSVarString(
	#if defined _ALS_SetSVarFloat
		#error _ALS_SetSVarFloat defined
	#endif
	native CST_SetSVarFloat(const varname[], Float:float_value) = SetSVarFloat;
	#define _ALS_SetSVarFloat
	#define SetSVarFloat( CST_SetSVarFloat(
	#if defined _ALS_GetSVarFloat
		#error _ALS_GetSVarFloat defined
	#endif
	native Float:CST_GetSVarFloat(const varname[]) = GetSVarFloat;
	#define _ALS_GetSVarFloat
	#define GetSVarFloat( CST_GetSVarFloat(
	#if defined _ALS_DeleteSVar
		#error _ALS_DeleteSVar defined
	#endif
	native CST_DeleteSVar(const varname[]) = DeleteSVar;
	#define _ALS_DeleteSVar
	#define DeleteSVar( CST_DeleteSVar(
	#if defined _ALS_GetSVarType
		#error _ALS_GetSVarType defined
	#endif
	native CST_GetSVarType(const varname[]) = GetSVarType;
	#define _ALS_GetSVarType
	#define GetSVarType( CST_GetSVarType(
	#if defined _ALS_ConnectNPC
		#error _ALS_ConnectNPC defined
	#endif
	native CST_ConnectNPC(const name[], const script[]) = ConnectNPC;
	#define _ALS_ConnectNPC
	#define ConnectNPC( CST_ConnectNPC(
	#if defined _ALS_SendRconCommand
		#error _ALS_SendRconCommand defined
	#endif
	native CST_SendRconCommand(const command[]) = SendRconCommand;
	#define _ALS_SendRconCommand
	#define SendRconCommand( CST_SendRconCommand(
	// This is the only case where a variable is "const" but shouldn't be.
	#if defined _ALS_GetPlayerVersion
		#error _ALS_GetPlayerVersion defined
	#endif
	native CST_GetPlayerVersion(playerid, version[], len) = GetPlayerVersion;
	#define _ALS_GetPlayerVersion
	#define GetPlayerVersion( CST_GetPlayerVersion(
	#if defined _ALS_BlockIpAddress
		#error _ALS_BlockIpAddress defined
	#endif
	native CST_BlockIpAddress(const ip_address[], timems) = BlockIpAddress;
	#define _ALS_BlockIpAddress
	#define BlockIpAddress( CST_BlockIpAddress(
	#if defined _ALS_UnBlockIpAddress
		#error _ALS_UnBlockIpAddress defined
	#endif
	native CST_UnBlockIpAddress(const ip_address[]) = UnBlockIpAddress;
	#define _ALS_UnBlockIpAddress
	#define UnBlockIpAddress( CST_UnBlockIpAddress(
	#if defined _ALS_TextDrawCreate
		#error _ALS_TextDrawCreate defined
	#endif
	native Text:CST_TextDrawCreate(Float:x, Float:y, const text[]) = TextDrawCreate;
	native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
	#define _ALS_TextDrawCreate
	#define TextDrawCreate( CST_TextDrawCreate(
	#if defined _ALS_TextDrawSetString
		#error _ALS_TextDrawSetString defined
	#endif
	native CST_TextDrawSetString(Text:text, const string[]) = TextDrawSetString;
	native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
	#define _ALS_TextDrawSetString
	#define TextDrawSetString( CST_TextDrawSetString(
	#if defined _ALS_Create3DTextLabel
		#error _ALS_Create3DTextLabel defined
	#endif
	native Text3D:CST_Create3DTextLabel(const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0) = Create3DTextLabel;
	#define _ALS_Create3DTextLabel
	#define Create3DTextLabel( CST_Create3DTextLabel(
	#if defined _ALS_Update3DTextLabelText
		#error _ALS_Update3DTextLabelText defined
	#endif
	native CST_Update3DTextLabelText(Text3D:id, color, const text[]) = Update3DTextLabelText;
	#define _ALS_Update3DTextLabelText
	#define Update3DTextLabelText( CST_Update3DTextLabelText(
	#if defined _ALS_CreatePlayer3DTextLabel
		#error _ALS_CreatePlayer3DTextLabel defined
	#endif
	native PlayerText3D:CST_CreatePlayer3DTextLabel(playerid, const text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer=INVALID_PLAYER_ID, attachedvehicle=INVALID_VEHICLE_ID, testLOS=0) = CreatePlayer3DTextLabel;
	#define _ALS_CreatePlayer3DTextLabel
	#define CreatePlayer3DTextLabel( CST_CreatePlayer3DTextLabel(
	#if defined _ALS_UpdPlayer3DTextLabelText
		#error _ALS_UpdPlayer3DTextLabelText defined
	#endif
	native CST_UpdatePlayer3DTextLabelText(playerid, PlayerText3D:id, color, const text[]) = UpdatePlayer3DTextLabelText;
	#define _ALS_UpdPlayer3DTextLabelText
	#define UpdatePlayer3DTextLabelText( CST_UpdatePlayer3DTextLabelText(
	#if defined _ALS_ShowPlayerDialog
		#error _ALS_ShowPlayerDialog defined
	#endif
	native CST_ShowPlayerDialog(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]) = ShowPlayerDialog;
	native BAD_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[]) = ShowPlayerDialog;
	#define _ALS_ShowPlayerDialog
	#define ShowPlayerDialog( CST_ShowPlayerDialog(

	// a_sampdb
	#if defined _ALS_db_open
		#error _ALS_db_open defined
	#endif
	native DB:CST_db_open(const name[]) = db_open;
	#define _ALS_db_open
	#define db_open( CST_db_open(
	#if defined _ALS_db_query
		#error _ALS_db_query defined
	#endif
	native DBResult:CST_db_query(DB:db, const query[]) = db_query;
	#define _ALS_db_query
	#define db_query( CST_db_query(

	// a_vehicles
	#if defined _ALS_SetVehicleNumberPlate
		#error _ALS_SetVehicleNumberPlate defined
	#endif
	native CST_SetVehicleNumberPlate(vehicleid, const numberplate[]) = SetVehicleNumberPlate;
	#define _ALS_SetVehicleNumberPlate
	#define SetVehicleNumberPlate( CST_SetVehicleNumberPlate(

	#define _FIXES_MAYBE_CONST const
#else
	#define _FIXES_MAYBE_CONST
#endif

/**
 * <remarks>
 * <c>WEAPONS</c>
 *
 * Because the default SA:MP includes missed some of these.
 * </remarks>
 */

#define _FIXES_WEAPON_FIST                      (0)
#define _FIXES_WEAPON_NIGHT_VIS_GOGGLES         (44)
#define _FIXES_WEAPON_THERMAL_GOGGLES           (45)

#if FIX_WEAPONS
	#define WEAPON_FIST               _FIXES_WEAPON_FIST
	#define WEAPON_NIGHTSTICK         WEAPON_NITESTICK
	#define WEAPON_MOLOTOV            WEAPON_MOLTOV
	#define WEAPON_NIGHT_VIS_GOGGLES  _FIXES_WEAPON_NIGHT_VIS_GOGGLES
	#define WEAPON_THERMAL_GOGGLES    _FIXES_WEAPON_THERMAL_GOGGLES
#endif

#define _FIXES_WEAPON_SLOTS                     (13)

/**
 * <remarks>
 * <c>BODYPARTS</c>
 *
 * Because the default SA:MP includes missed these.
 * </remarks>
 */

#if FIX_BODYPARTS
	#define BODY_PART_TORSO                     (3)
	#define BODY_PART_GROIN                     (4)
	#define BODY_PART_LEFT_ARM                  (5)
	#define BODY_PART_RIGHT_ARM                 (6)
	#define BODY_PART_LEFT_LEG                  (7)
	#define BODY_PART_RIGHT_LEG                 (8)
	#define BODY_PART_HEAD                      (9)
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
	#define VEHICLE_LANDSTALKER                 (400)
	#define VEHICLE_BRAVURA                     (401)
	#define VEHICLE_BUFFALO                     (402)
	#define VEHICLE_LINERUNNER                  (403)
	#define VEHICLE_PERRENIAL                   (404)
	#define VEHICLE_SENTINEL                    (405)
	#define VEHICLE_DUMPER                      (406)
	#define VEHICLE_FIRETRUCK                   (407)
	#define VEHICLE_TRASHMASTER                 (408)
	#define VEHICLE_STRETCH                     (409)
	#define VEHICLE_MANANA                      (410)
	#define VEHICLE_INFERNUS                    (411)
	#define VEHICLE_VOODOO                      (412)
	#define VEHICLE_PONY                        (413)
	#define VEHICLE_MULE                        (414)
	#define VEHICLE_CHEETAH                     (415)
	#define VEHICLE_AMBULANCE                   (416)
	#define VEHICLE_LEVIATHAN                   (417)
	#define VEHICLE_MOONBEAM                    (418)
	#define VEHICLE_ESPERANTO                   (419)
	#define VEHICLE_TAXI                        (420)
	#define VEHICLE_WASHINGTON                  (421)
	#define VEHICLE_BOBCAT                      (422)
	#define VEHICLE_MRWHOOPEE                   (423)
	#define VEHICLE_BFINJECTION                 (424)
	#define VEHICLE_HUNTER                      (425)
	#define VEHICLE_PREMIER                     (426)
	#define VEHICLE_ENFORCER                    (427)
	#define VEHICLE_SECURICAR                   (428)
	#define VEHICLE_BANSHEE                     (429)
	#define VEHICLE_PREDATOR                    (430)
	#define VEHICLE_BUS                         (431)
	#define VEHICLE_RHINO                       (432)
	#define VEHICLE_BARRACKS                    (433)
	#define VEHICLE_HOTKNIFE                    (434)
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
	#define VEHICLE_SEASPARROW                  (447)
	#define VEHICLE_PIZZABOY                    (448)
	#define VEHICLE_TRAM                        (449)
	#define VEHICLE_ARTICLETRAILER2             (450)
	#define VEHICLE_TURISMO                     (451)
	#define VEHICLE_SPEEDER                     (452)
	#define VEHICLE_REEFER                      (453)
	#define VEHICLE_TROPIC                      (454)
	#define VEHICLE_FLATBED                     (455)
	#define VEHICLE_YANKEE                      (456)
	#define VEHICLE_CADDY                       (457)
	#define VEHICLE_SOLAIR                      (458)
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
	#define VEHICLE_SANNEWSMAVERICK             (488)
	#define VEHICLE_RANCHER                     (489)
	#define VEHICLE_FBIRANCHER                  (490)
	#define VEHICLE_VIRGO                       (491)
	#define VEHICLE_GREENWOOD                   (492)
	#define VEHICLE_JETMAX                      (493)
	#define VEHICLE_HOTRINGRACER                (494)
	#define VEHICLE_SANDKING                    (495)
	#define VEHICLE_BLISTACOMPACT               (496)
	#define VEHICLE_POLICEMAVERICK              (497)
	#define VEHICLE_BOXVILLE                    (498)
	#define VEHICLE_BENSON                      (499)
	#define VEHICLE_MESA                        (500)
	#define VEHICLE_RCGOBLIN                    (501)
	#define VEHICLE_HOTRINGRACERA               (502)
	#define VEHICLE_HOTRINGRACERB               (503)
	#define VEHICLE_BLOODRINGBANGER             (504)
	#define VEHICLE_RANCHERLURE                 (505)
	#define VEHICLE_SUPERGT                     (506)
	#define VEHICLE_ELEGANT                     (507)
	#define VEHICLE_JOURNEY                     (508)
	#define VEHICLE_BIKE                        (509)
	#define VEHICLE_MOUNTAINBIKE                (510)
	#define VEHICLE_BEAGLE                      (511)
	#define VEHICLE_CROPDUST                    (512)
	#define VEHICLE_STUNTPLANE                  (513)
	#define VEHICLE_TANKER                      (514)
	#define VEHICLE_ROADTRAIN                   (515)
	#define VEHICLE_NEBULA                      (516)
	#define VEHICLE_MAJESTIC                    (517)
	#define VEHICLE_BUCCANEER                   (518)
	#define VEHICLE_SHAMAL                      (519)
	#define VEHICLE_HYDRA                       (520)
	#define VEHICLE_FCR900                      (521)
	#define VEHICLE_NRG500                      (522)
	#define VEHICLE_HPV1000                     (523)
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
	#define VEHICLE_REMINGTON                   (534)
	#define VEHICLE_SLAMVAN                     (535)
	#define VEHICLE_BLADE                       (536)
	#define VEHICLE_FREIGHT                     (537)
	#define VEHICLE_BROWNSTREAK                 (538)
	#define VEHICLE_VORTEX                      (539)
	#define VEHICLE_VINCENT                     (540)
	#define VEHICLE_BULLET                      (541)
	#define VEHICLE_CLOVER                      (542)
	#define VEHICLE_SADLER                      (543)
	#define VEHICLE_FIRETRUCKLA                 (544)
	#define VEHICLE_HUSTLER                     (545)
	#define VEHICLE_INTRUDER                    (546)
	#define VEHICLE_PRIMO                       (547)
	#define VEHICLE_CARGOBOB                    (548)
	#define VEHICLE_TAMPA                       (549)
	#define VEHICLE_SUNRISE                     (550)
	#define VEHICLE_MERIT                       (551)
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
	#define VEHICLE_RAINDANCE                   (563)
	#define VEHICLE_RCTIGER                     (564)
	#define VEHICLE_FLASH                       (565)
	#define VEHICLE_TAHOMA                      (566)
	#define VEHICLE_SAVANNA                     (567)
	#define VEHICLE_BANDITO                     (568)
	#define VEHICLE_FREIGHTFLATTRAILER          (569)
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
	#define VEHICLE_PETROLTRAILER               (584)
	#define VEHICLE_EMPEROR                     (585)
	#define VEHICLE_WAYFARER                    (586)
	#define VEHICLE_EUROS                       (587)
	#define VEHICLE_HOTDOG                      (588)
	#define VEHICLE_CLUB                        (589)
	#define VEHICLE_FREIGHTBOXTRAILER           (590)
	#define VEHICLE_ARTICLETRAILER3             (591)
	#define VEHICLE_ANDROMADA                   (592)
	#define VEHICLE_DODO                        (593)
	#define VEHICLE_RCCAM                       (594)
	#define VEHICLE_LAUNCH                      (595)
	#define VEHICLE_POLICECARLSPD               (596)
	#define VEHICLE_POLICECARSFPD               (597)
	#define VEHICLE_POLICECARLVPD               (598)
	#define VEHICLE_POLICERANGER                (599)
	#define VEHICLE_PICADOR                     (600)
	#define VEHICLE_SWAT                        (601)
	#define VEHICLE_ALPHA                       (602)
	#define VEHICLE_PHOENIX                     (603)
	#define VEHICLE_GLENDALESHIT                (604)
	#define VEHICLE_SADLERSHIT                  (605)
	#define VEHICLE_BAGGAGETRAILERA             (606)
	#define VEHICLE_BAGGAGETRAILERB             (607)
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
	#define IS_JIT (_FIXES_gIsJIT)
#endif

/**
 * <remarks>
 * <c>IS_FILTERSCRIPT</c>
 *
 * "FILTERSCRIPT" can't always be relied on to be set.  This is not a pre-
 * processor macro, but may be better than nothing (also used internally).
 * </remarks>
 */

#if FIX_FILTERSCRIPT
	#define IS_FILTERSCRIPT (_FIXES_gIsFilterscript)
#endif

/**
 * <remarks>
 * <c>IS_WINDOWS</c>
 *
 * True when the code is running on Windows.  NOT a pre-processor macro, since
 * the OS you are running the code on can't be determined at compile-time.
 *
 * <c>IS_LINUX</c>
 *
 * True when the code is running on Linux.  NOT a pre-processor macro, since the
 * OS you are running the code on can't be determined at compile-time.
 * </remarks>
 */

#if FIX_OS
	#define IS_WINDOWS (_FIXES_gIsWindows)
	#define IS_LINUX (!_FIXES_gIsWindows)
#endif

/**
 * <remarks>
 * Figure out what OS this is running on.
 * </remarks>
 * <fixes>IS_WINDOWS</fixes>
 * <fixes>IS_LINUX</fixes>
 */

static _FIXES_DetermineOS()
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
 * <fixes>SilentTeleport</fixes>
 */
#if defined _ALS_SetVehiclePos
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
		if (!SetVehiclePos(vehicleid, x, y, z))
		{
			return 0;
		}
		
		_FIXES_FOREACH(FIXES_gsPlayersIterator, i)
		{
			if (GetPlayerState(i) == PLAYER_STATE_DRIVER && GetPlayerVehicleID(i) == vehicleid)
			{
				if (FIXES_gsJackedId[i] != INVALID_PLAYER_ID)
				{
					ClearAnimations(FIXES_gsJackedId[i]);
					break;
				}
			}
		}
		return 1;
	}

	#define _ALS_SetVehiclePos
	#define SetVehiclePos( FIXES_SetVehiclePos( 
#endif 

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
		CallRemoteFunction(FIXES_gscDetermineOrder, FIXES_gscSpec@),
		deleteproperty(5, FIXES_gscNoGMProperty),
		CallRemoteFunction(FIXES_gscDetermineOrder, FIXES_gscSpec@);
	}
#endif

/**
 * <fixes>IsPlayerConnected</fixes>
 */

#if defined _ALS_IsPlayerConnected
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

	#define _ALS_IsPlayerConnected
	#define IsPlayerConnected( FIXES_IsPlayerConnected(
#endif

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
				t = FIXES_gsGTStyle[7] = TextDrawCreate(608.000000, 344.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 1.000000, 3.000000),
				TextDrawAlignment(t, 3),
				TextDrawColor(t, 0x36682CFF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 10.0, 200.0);

				// Global style 8 (location name).
				t = FIXES_gsGTStyle[8] = TextDrawCreate(608.000000, 385.800000, FIXES_gsSpace),
				TextDrawLetterSize(t, 1.200000, 3.799998),
				TextDrawAlignment(t, 3),
				TextDrawColor(t, 0xACCBF1FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 0),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 10.0, 200.0);

				// Global style 9 (radio name).
				t = FIXES_gsGTStyle[9] = TextDrawCreate(320.000000, 22.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.600000, 1.799999),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0x906210FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 1),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 10 (radio switch).
				t = FIXES_gsGTStyle[10] = TextDrawCreate(320.000000, 22.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.600000, 1.799999),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0x969696FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 1),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 11 (positive money).
				t = FIXES_gsGTStyle[11] = TextDrawCreate(607.000000, 78.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.550000, 2.150000),
				TextDrawAlignment(t, 3),
				TextDrawColor(t, 0x36682CFF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000FF),
				TextDrawFont(t, 3),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 10.0, 200.0);

				// Global style 12 (negative money).
				t = FIXES_gsGTStyle[12] = TextDrawCreate(607.000000, 78.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.550000, 2.150000),
				TextDrawAlignment(t, 3),
				TextDrawColor(t, 0xB4191DFF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000FF),
				TextDrawFont(t, 3),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 10.0, 200.0);

				// Global style 13 (stunt).
				t = FIXES_gsGTStyle[13] = TextDrawCreate(380.000000, 341.150000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.579999, 2.420000),
				TextDrawTextSize(t, 40.000000, 460.000000),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0xDDDDDBFF),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0),
				TextDrawSetShadow(t, 2),
				TextDrawSetOutline(t, 0),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 1),
				TextDrawSetProportional(t, 1),

			#endif

				// Global style 0.
				t = FIXES_gsGTStyle[0] = TextDrawCreate(320.0, 214.0, FIXES_gsSpace),
				TextDrawLetterSize(t, 1.3, 3.6),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0x906210FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 3),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 1.
				t = FIXES_gsGTStyle[1] = TextDrawCreate(620.0, 310.0, FIXES_gsSpace),
				TextDrawLetterSize(t, 1.0, 2.6),
				TextDrawAlignment(t, 3),
				TextDrawColor(t, 0x906210FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 3),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 10.0, 200.0);

				// Global style 2.
				t = FIXES_gsGTStyle[2] = TextDrawCreate(320.0, 156.0, FIXES_gsSpace),
				TextDrawLetterSize(t, 2.1, 4.2),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0xE1E1E1FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 3),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 0),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 3.
				t = FIXES_gsGTStyle[3] = TextDrawCreate(320.000000, 154.500000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.600000, 2.750000),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0x906210FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 4.
				t = FIXES_gsGTStyle[4] = TextDrawCreate(320.000000, 115.500000, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.600000, 2.750000),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0x906210FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 5.
				t = FIXES_gsGTStyle[5] = TextDrawCreate(320.0, 217.0, FIXES_gsSpace),
				TextDrawLetterSize(t, 0.6, 2.75),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0xE1E1E1FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 2),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);

				// Global style 6.
				t = FIXES_gsGTStyle[6] = TextDrawCreate(320.000000, 60.000000, FIXES_gsSpace),
				TextDrawLetterSize(t, 1.000000, 3.599998),
				TextDrawAlignment(t, 2),
				TextDrawColor(t, 0xACCBF1FF),
				TextDrawSetShadow(t, 0),
				TextDrawSetOutline(t, 2),
				TextDrawBackgroundColor(t, 0x000000AA),
				TextDrawFont(t, 3),
				TextDrawSetProportional(t, 1),
				TextDrawUseBox(t, true),
				TextDrawBoxColor(t, 0x00000000),
				TextDrawTextSize(t, 200.0, 620.0);
		}
		else
		{
				new
					PlayerText:t;

			#if FIX_GameTextStyles

				// Global style 7 (playerid, vehicle name).
				t = FIXES_gsPGTStyle[playerid][7] = CreatePlayerTextDraw(playerid, 608.000000, 344.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 1.000000, 3.000000),
				PlayerTextDrawAlignment(playerid, t, 3),
				PlayerTextDrawColor(playerid, t, 0x36682CFF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 10.0, 200.0);

				// Global style 8 (playerid, location name).
				t = FIXES_gsPGTStyle[playerid][8] = CreatePlayerTextDraw(playerid, 608.000000, 385.800000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 1.200000, 3.799998),
				PlayerTextDrawAlignment(playerid, t, 3),
				PlayerTextDrawColor(playerid, t, 0xACCBF1FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 0),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 10.0, 200.0);

				// Global style 9 (playerid, radio name).
				t = FIXES_gsPGTStyle[playerid][9] = CreatePlayerTextDraw(playerid, 320.000000, 22.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.600000, 1.799999),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 1),
				PlayerTextDrawBackgroundColor(playerid, t, 170),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 10 (playerid, radio switch).
				t = FIXES_gsPGTStyle[playerid][10] = CreatePlayerTextDraw(playerid, 320.000000, 22.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.600000, 1.799999),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0x969696FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 1),
				PlayerTextDrawBackgroundColor(playerid, t, 170),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 11 (playerid, positive money).
				t = FIXES_gsPGTStyle[playerid][11] = CreatePlayerTextDraw(playerid, 607.000000, 78.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.550000, 2.150000),
				PlayerTextDrawAlignment(playerid, t, 3),
				PlayerTextDrawColor(playerid, t, 0x36682CFF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000FF),
				PlayerTextDrawFont(playerid, t, 3),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 10.0, 200.0);

				// Global style 12 (playerid, negative money).
				t = FIXES_gsPGTStyle[playerid][12] = CreatePlayerTextDraw(playerid, 607.000000, 78.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.550000, 2.150000),
				PlayerTextDrawAlignment(playerid, t, 3),
				PlayerTextDrawColor(playerid, t, 0xB4191DFF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000FF),
				PlayerTextDrawFont(playerid, t, 3),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 10.0, 200.0);

				// Global style 13 (playerid, stunt).
				t = FIXES_gsPGTStyle[playerid][13] = CreatePlayerTextDraw(playerid, 380.000000, 341.150000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.579999, 2.420000),
				PlayerTextDrawTextSize(playerid, t, 40.000000, 460.000000),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0xDDDDDBFF),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0),
				PlayerTextDrawSetShadow(playerid, t, 2),
				PlayerTextDrawSetOutline(playerid, t, 0),
				PlayerTextDrawBackgroundColor(playerid, t, 170),
				PlayerTextDrawFont(playerid, t, 1),
				PlayerTextDrawSetProportional(playerid, t, 1);

			#endif

				// Global style 0.
				t = FIXES_gsPGTStyle[playerid][0] = CreatePlayerTextDraw(playerid, 320.0, 214.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 1.3, 3.6),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 3),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 1.
				t = FIXES_gsPGTStyle[playerid][1] = CreatePlayerTextDraw(playerid, 620.0, 310.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 1.0, 2.6),
				PlayerTextDrawAlignment(playerid, t, 3),
				PlayerTextDrawColor(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 3),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 10.0, 200.0);

				// Global style 2.
				t = FIXES_gsPGTStyle[playerid][2] = CreatePlayerTextDraw(playerid, 320.0, 156.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 2.1, 4.2),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0xE1E1E1FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 3),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 0),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 3.
				t = FIXES_gsPGTStyle[playerid][3] = CreatePlayerTextDraw(playerid, 320.000000, 154.500000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.600000, 2.750000),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 4.
				t = FIXES_gsPGTStyle[playerid][4] = CreatePlayerTextDraw(playerid, 320.000000, 115.500000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.600000, 2.750000),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0x906210FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 5.
				t = FIXES_gsPGTStyle[playerid][5] = CreatePlayerTextDraw(playerid, 320.0, 217.0, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 0.6, 2.75),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0xE1E1E1FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 2),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);

				// Global style 6.
				t = FIXES_gsPGTStyle[playerid][6] = CreatePlayerTextDraw(playerid, 320.000000, 60.000000, FIXES_gsSpace),
				PlayerTextDrawLetterSize(playerid, t, 1.000000, 3.599998),
				PlayerTextDrawAlignment(playerid, t, 2),
				PlayerTextDrawColor(playerid, t, 0xACCBF1FF),
				PlayerTextDrawSetShadow(playerid, t, 0),
				PlayerTextDrawSetOutline(playerid, t, 2),
				PlayerTextDrawBackgroundColor(playerid, t, 0x000000AA),
				PlayerTextDrawFont(playerid, t, 3),
				PlayerTextDrawSetProportional(playerid, t, 1),
				PlayerTextDrawUseBox(playerid, t, true),
				PlayerTextDrawBoxColor(playerid, t, 0x00000000),
				PlayerTextDrawTextSize(playerid, t, 200.0, 620.0);
		}
	}
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

static stock _FIXES_CheckServerRoot()
{
	#if FIX_GetServerVarAsString || FIX_GetServerVarAsFloat || FIX_GetServerVarAsInt || FIX_GetServerVarAsBool
		FIXES_gsServerCFG = fopen("DANGEROUS_SERVER_ROOT/server.cfg", io_read);
		#if FIXES_ServerVarMsg
			if (!FIXES_gsServerCFG)
			{
				print(_FIXES_gIsFilterscript ? ("* FIXES_PRINTF (FS):") : ("* FIXES_PRINTF (GM):"));
				print(" ");
				print("********************************************************************************");
				print("* Could not open \"DANGEROUS_SERVER_ROOT/server.cfg\".  Make sure your server is *");
				print("* configured to allow server root access.  Either via:                         *");
				print("*                                                                              *");
				print("*     https://github.com/Misiur/YSI/raw/master/links.rar                       *");
				print("*                                                                              *");
				print("* Or (Windows - CMD):                                                          *");
				print("*                                                                              *");
				print("*     mklink /J DANGEROUS_SERVER_ROOT ..                                       *");
				print("*                                                                              *");
				print("* Or (Windows - PowerShell):                                                   *");
				print("*                                                                              *");
				print("*     cmd /c mklink /J DANGEROUS_SERVER_ROOT ..                                *");
				print("*                                                                              *");
				print("* Or (Linux):                                                                  *");
				print("*                                                                              *");
				print("*     ln -s .. DANGEROUS_SERVER_ROOT                                           *");
				print("*                                                                              *");
				print("* If you not able or just doesn't want to make these changes then add this     *");
				print("* \"#define FIXES_ServerVarMsg 0\" before \"#include <fixes>\"                     *");
				print("********************************************************************************");
				print(" ");
			}
		#endif
	#endif
}

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
	#if FIXES_Single
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

	#if FIXES_Single
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
			// It is.  Create the file.
			if (!fexist(FIXES_gscRconFixFS))
			{
				/*
					native CallRemoteFunction(const function[], const format[], {Float,_}:...);

					forward OnRconCommand(const cmd[]);
					public OnRconCommand(const cmd[]) return 0;

					forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);
					public OnClientCheckResponse(playerid, actionid, memaddr, retndata) return CallRemoteFunction("FIXES_OnClientCheckResponse\0\0\0", "iiii", playerid, actionid, memaddr, retndata);
				*/
				static
					lRCFixCode[] = {
						0x000000F0, 0x0808F1E0, 0x00080014, 0x0000008C,
						0x000000F0, 0x00000180, 0x00004180, 0xFFFFFFFF,
						0x00000038, 0x00000048, 0x00000050, 0x00000050,
						0x00000050, 0x00000050, 0x00000014, 0x00000052,
						0x00000008, 0x00000068, 0x00000000, 0x00000076,
						0x6E4F001F, 0x65696C43, 0x6843746E, 0x526B6365,
						0x6F707365, 0x0065736E, 0x63526E4F, 0x6F436E6F,
						0x6E616D6D, 0x61430064, 0x65526C6C, 0x65746F6D,
						0x636E7546, 0x6E6F6974, 0x00000000, 0x2E007880,
						0x2E305980, 0x81180581, 0x05811405, 0x0C058110,
						0x277C8027, 0x80182700, 0x1C2C007B, 0x80468030,
						0x80588049, 0x80538045, 0x804F805F, 0x8043806E,
						0x8069806C, 0x806E8065, 0x80438074, 0x80658068,
						0x806B8063, 0x80658052, 0x80708073, 0x806E806F,
						0x00658073, 0x80000000, 0x80698069, 0x00698069
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
					SendRconCommand("loadfs ../scriptfiles/callbackfix");
				#if FIX_OnClientCheckResponse
					state OnClientCheckResponse : OnClientCheckResponse_GM;
				#endif
			}
			else
				print("\7\7\7\7\7*** fixes.inc error: Could not load RconCommand/ClientCheckResponse fix FS.");
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
				ShowPlayerDialog(playerid, -1, 0, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace);
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
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][0]);
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
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][0]);
					}
				#endif
					return
						#if FIX_GameTextStyles
							TextDrawDestroy(FIXES_gsGTStyle[13]),
							TextDrawDestroy(FIXES_gsGTStyle[12]),
							TextDrawDestroy(FIXES_gsGTStyle[11]),
							TextDrawDestroy(FIXES_gsGTStyle[10]),
							TextDrawDestroy(FIXES_gsGTStyle[9]),
							TextDrawDestroy(FIXES_gsGTStyle[8]),
							TextDrawDestroy(FIXES_gsGTStyle[7]),
						#endif
							TextDrawDestroy(FIXES_gsGTStyle[6]),
							TextDrawDestroy(FIXES_gsGTStyle[5]),
							TextDrawDestroy(FIXES_gsGTStyle[4]),
							TextDrawDestroy(FIXES_gsGTStyle[3]),
							TextDrawDestroy(FIXES_gsGTStyle[2]),
							TextDrawDestroy(FIXES_gsGTStyle[1]),
							TextDrawDestroy(FIXES_gsGTStyle[0]);
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
			if (!GetPVarInt(playerid, FIXES_pvarNotNewPlayer))
		#endif
			{
				FIXES_PRINTF("FIXES_OnPlayerConnect: First (%d)", FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE);
				// ======================
				//  BEGIN: SetPlayerName
				// ======================
				#if FIX_SetPlayerName
					new
						name[MAX_PLAYER_NAME];
					GetPlayerName(playerid, name, MAX_PLAYER_NAME);
					if (strcmp(name, FIXES_gscTempName) == 0)
					{
						Kick(playerid);
					}
				#endif
				// ======================
				//  END:   SetPlayerName
				// ======================

				// =============================
				//  BEGIN: SetPlayerWorldBounds
				// =============================
				#if FIX_SetPlayerWorldBounds || FIX_GetPlayerWorldBounds
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY] = _FIXES_MAX_WORLDBOUNDS,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] = _FIXES_MIN_WORLDBOUNDS;
				#endif
				// =============================
				//  END:   SetPlayerWorldBounds
				// =============================

				// =======================
				//  BEGIN: GetPlayerColor
				// =======================
				#if FIX_GetPlayerColour
					SetPlayerColor(playerid, FIXES_gscPlayerColours[playerid % 100]);
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
					DisablePlayerCheckpoint(playerid);
				#endif
				// =============================
				//  END:   IsPlayerInCheckpoint
				// =============================

				// =================================
				//  BEGIN: IsPlayerInRaceCheckpoint
				// =================================
				#if FIX_IsPlayerInRaceCheckpoint
					DisablePlayerRaceCheckpoint(playerid);
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
					ShowPlayerDialog(playerid, -1, 0, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace, FIXES_gsSpace);
				#endif
				// =============================
				//  END:   PlayerDialogResponse
				// =============================

				// =====================
				//  BEGIN: SetSpawnInfo
				// =====================
				#if FIX_SetSpawnInfo
					SetSpawnInfo(playerid, NO_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
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
					SetPVarInt(playerid, FIXES_pvarNotNewPlayer, 1);
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
				KillTimer(FIXES_gsPlayerAnimTimer[playerid]),
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
			if (shift != -1)
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
				if (IsPlayerAttachedObjectSlotUsed(playerid, i))
				{
					RemovePlayerAttachedObject(playerid, i);
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
				KillTimer(GetPVarInt(playerid, FIXES_pvarKick));
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
				GetAnimationName(FIXES_gsLastAnimation[playerid], sAnimlib, sizeof (sAnimlib), sAnimname, sizeof (sAnimname));
				if (strcmp(sAnimlib, "PED", true))
				{
					ClearAnimations(playerid);
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

			FIXES_SET(PlayerLastCash, playerid, GetPlayerMoney(playerid));

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
 * <fixes>SpawnPlayer</fixes>
 * <fixes>OnPlayerSpawn</fixes>
 */

#if defined _ALS_SpawnPlayer
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
				vid = GetPlayerVehicleID(playerid);
			if (vid)
			{
				new
					Float:x,
					Float:y,
					Float:z;
				// Remove them without the animation.
				GetVehiclePos(vid, x, y, z),
				SetPlayerPos(playerid, x, y, z);
			}
		#endif
		// ======================
		//  END:   SpawnPlayer
		// ======================

		// ======================
		//  BEGIN: OnPlayerSpawn
		// ======================
		#if FIX_OnPlayerSpawn
			FIXES_SET(PlayerLastCash, playerid, GetPlayerMoney(playerid));
		#endif
		// ======================
		//  END:   OnPlayerSpawn
		// ======================

		return SpawnPlayer(playerid);
	}

	#define _ALS_SpawnPlayer
	#define SpawnPlayer( FIXES_SpawnPlayer(
#endif

/**
 * <fixes>SetPlayerName</fixes>
 */

#if defined _ALS_SetPlayerName
	#error _ALS_SetPlayerName defined
#endif
native BAD_SetPlayerName(playerid, const name[]) = SetPlayerName;

/**
 * <fixes>SetPlayerName</fixes>
 */

#if FIX_SetPlayerName
	stock FIXES_SetPlayerName(playerid, const name[])
	{
		static
			sOldName[MAX_PLAYER_NAME];
		GetPlayerName(playerid, sOldName, sizeof (sOldName));
		if (!strcmp(name, sOldName, true))
		{
			if (strcmp(name, sOldName, false))
			{
				SetPlayerName(playerid, FIXES_gscTempName);
				if (SetPlayerName(playerid, name) == -1)
				{
					SetPlayerName(playerid, sOldName);
					return -1;
				}
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return SetPlayerName(playerid, name);
	}

	#define _ALS_SetPlayerName
	#define SetPlayerName( FIXES_SetPlayerName(
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
			GetPlayerPos(playerid, x, y, z),
			RemoveBuildingForPlayer(playerid, 1484, x, y, z, 10.0),
			RemoveBuildingForPlayer(playerid, 1485, x, y, z, 10.0),
			RemoveBuildingForPlayer(playerid, 1486, x, y, z, 10.0);
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
				ResetPlayerMoney(playerid);
				GivePlayerMoney(playerid, FIXES_GET(PlayerLastCash, playerid));
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
					#define _FIXES_PER_PLAYER_GT(%0) if (FIXES_gsPlayerPGTShown[%0][playerid] > playerid) PlayerTextDrawHide(playerid, FIXES_gsPGTStyle[playerid][%0]), _FIXES_RemoveInternal(FIXES_gsPlayerPGTShown[%0], playerid, MAX_PLAYERS)

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
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[13]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[12]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[11]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[10]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[9]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[8]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[7]);
					#endif
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[6]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[5]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[4]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[3]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[2]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[1]),
						TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[0]);
				}

			#endif
			// =================
			//  END:   GameText
			// =================

			// ======================
			//  BEGIN: GetPlayerSkin
			// ======================
			#if FIX_GetPlayerSkin
				FIXES_SET(PlayerSkin, playerid, GetPlayerSkin(playerid));
			#endif
			// ======================
			//  END:   GetPlayerSkin
			// ======================

			// =======================
			//  BEGIN: SetSpawnInfo_2
			// =======================
			#if FIX_SetSpawnInfo_2
				SetPlayerTeam(playerid, GetPlayerTeam(playerid));
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

#if FIX_OnVehicleMod
	public OnVehicleMod(playerid, vehicleid, componentid)
	{
		#if !FIXES_Single
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
			{
				return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
			}
		#endif

		// =====================
		//  BEGIN: OnVehicleMod
		// =====================
		new
			modelid = GetVehicleModel(vehicleid);
		if (_FIXES_IN_RANGE(modelid, 400, 611 + 1))
		{
			switch (componentid)
			{
				case 1000 .. 1191:
				{
					if (FIXES_gscVehicleMods[(modelid - 400) * 6 + (componentid - 1000 >>> 5)] & 1 << (componentid - 1000 & 0b00011111))
					{
						return FIXES_OnVehicleMod(playerid, vehicleid, componentid);
					}
				}
				case 1192, 1193:
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
		}
		// Desync the player entirely.
		FIXES_BlockUpdate(playerid);
		return 0;
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

#if defined _ALS_SetPlayerSkin
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
				vehicleid = GetPlayerVehicleID(playerid);
			if (vehicleid)
			{
				new
					seat = GetPlayerVehicleSeat(playerid);
				ClearAnimations(playerid, 1);
				new
					ret = SetPlayerSkin(playerid, skinid);
				PutPlayerInVehicle(playerid, vehicleid, seat);

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

		return SetPlayerSkin(playerid, skinid);
	}

	#define _ALS_SetPlayerSkin
	#define SetPlayerSkin( FIXES_SetPlayerSkin(
#endif

/**
 * <fixes>GetPlayerSkin</fixes>
 */

#if defined _ALS_GetPlayerSkin
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

	#define _ALS_GetPlayerSkin
	#define GetPlayerSkin( FIXES_GetPlayerSkin(
#endif

/**
 * <fixes>GetWeaponName</fixes>
 */

#if defined _ALS_GetWeaponName
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
				return GetWeaponName(weaponid, weapon, len);
			}
		}
		return 0;
	}

	#define _ALS_GetWeaponName
	#define GetWeaponName( FIXES_GetWeaponName(
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
 */

#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_AllowInteriorWeapons || FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2 || FIX_OnPlayerEnterVehicle_3 || FIX_OnPlayerDeath || FIX_Kick || FIX_OnVehicleMod || FIX_PassengerSeating || FIX_GogglesSync
	public OnPlayerUpdate(playerid)
	{
		// =============================
		//  BEGIN: OnPlayerEnterVehicle
		// =============================
		#if FIX_OnPlayerEnterVehicle || FIX_Kick || FIX_OnVehicleMod || FIX_OnPlayerEnterVehicle_2
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
				if (GetTickCount() >= FIXES_gsPlayerVehicleTickCount[playerid] + 4000)
				{
					_FIXES_StopPlayerEnterVehicle(playerid);
				}
				else
				{
					if (1020 <= GetPlayerAnimationIndex(playerid) <= 1021)
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
				SetPlayerArmedWeapon(playerid, 0);
			}
		#endif
		// ============================
		//  END: AllowInteriorWeapons
		// ============================

		#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_GogglesSync
			new
				ud,
				lr,
				keys;
			GetPlayerKeys(playerid, keys, ud, lr);
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
				GetPlayerPos(playerid, x, y, z);
				if (FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] < x < FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] && FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] < y < FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY])
				{
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX] = x,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY] = y,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ] = z;
				}
				else
				{
					SetPlayerPos(playerid, FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX], FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY], FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ]);
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
			FIXES_gsLastAnimation[playerid] = GetPlayerAnimationIndex(playerid);
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
			if (FIXES_gsPSTimer[playerid] != 0 && GetTickCount() > FIXES_gsPSTimer[playerid])
			{
				if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_ENTER_VEHICLE)
				{
					#if !FIX_OnPlayerDeath
						new
							animation = GetPlayerAnimationIndex(playerid);
					#else
						new
							animation = FIXES_gsLastAnimation[playerid];
					#endif

					if (_FIXES_NO_RANGE(animation, 1007, 1060 + 1) && _FIXES_NO_RANGE(animation, 225, 233 + 1))
					{
						ClearAnimations(playerid, 1);
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
			switch (GetPlayerWeapon(playerid))
			{
				case _FIXES_WEAPON_NIGHT_VIS_GOGGLES, _FIXES_WEAPON_THERMAL_GOGGLES:
				{
					if ((keys & KEY_FIRE) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
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

#if defined _ALS_SetPlayerWorldBounds
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
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
			{
				FIXES_PRINTF("Call SetPlayerWorldBounds");
				if (x_max == x_min || y_max == y_min)
				{
					// Impossibly small area, disable checks entirely.
					return
						FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY] = _FIXES_MAX_WORLDBOUNDS,
						FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] = _FIXES_MIN_WORLDBOUNDS,
						SetPlayerWorldBounds(playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS);
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
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] = x_min,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] = x_max,

					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] = y_min,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY] = y_max,

					GetPlayerPos(playerid, tmp, tmp, tmp),
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX] = (x_max - x_min) / 2 + x_min,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY] = (y_max - y_min) / 2 + y_min,
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ] = tmp,

					SetPlayerWorldBounds(playerid, x_max, x_min, y_max, y_min);
			}
			return 0;
		}
	#else
		forward _FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min);

		stock FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
		{
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
			{
				FIXES_PRINTF("Call SetPlayerWorldBounds");
				// Impossibly small area, disable checks entirely.
				if (x_max == x_min || y_max == y_min)
					return
						CallRemoteFunction(FIXES_gscSetPlayerWorldBounds, FIXES_gscSpec@iffff, playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS),
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
					CallRemoteFunction(FIXES_gscSetPlayerWorldBounds, FIXES_gscSpec@iffff, playerid, x_max, x_min, y_max, y_min),
					getproperty(5, FIXES_gscReturnProperty);
			}
			return 0;
		}

		public _FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
		{
			FIXES_PRINTF("_FIXES_SetPlayerWorldBounds: %d %.2f %.2f %.2f %.2f", playerid, x_max, x_min, y_max, y_min);
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] = x_min,
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] = x_max,

			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] = y_min,
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY] = y_max;

			new
				Float:tmp;
			GetPlayerPos(playerid, tmp, tmp, tmp),
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX] = (x_max - x_min) / 2 + x_min,
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY] = (y_max - y_min) / 2 + y_min,
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ] = tmp;

			_FIXES_IS_IN_CHARGE()
			{
				setproperty(5, FIXES_gscReturnProperty, SetPlayerWorldBounds(playerid, x_max, x_min, y_max, y_min));
			}
			return 0;
		}
	#endif

	#define _ALS_SetPlayerWorldBounds
	#define SetPlayerWorldBounds( FIXES_SetPlayerWorldBounds(
#endif

#if FIX_GetPlayerWorldBounds
	stock FIXES_GetPlayerWorldBounds(playerid, &Float:x_max, &Float:x_min, &Float:y_max, &Float:y_min)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			x_min = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX],
			x_max = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX],
			y_min = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY],
			y_max = FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY];
		}
	}

	#define _ALS_GetPlayerWorldBounds
	#define GetPlayerWorldBounds( FIXES_GetPlayerWorldBounds(
#endif

#if FIX_ClearPlayerWorldBounds
	stock FIXES_ClearPlayerWorldBounds(playerid)
	{
		SetPlayerWorldBounds(playerid, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS, _FIXES_MAX_WORLDBOUNDS, _FIXES_MIN_WORLDBOUNDS);
	}

	#define _ALS_ClearPlayerWorldBounds
	#define ClearPlayerWorldBounds( FIXES_ClearPlayerWorldBounds(
#endif

/**
 * <fixes>TogglePlayerControllable</fixes>
 */

#if defined _ALS_TogglePlayerControllable
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
			if (TogglePlayerControllable(playerid, toggle))
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
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
			{
				return
					CallRemoteFunction(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, playerid, toggle),
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
				setproperty(5, FIXES_gscReturnProperty, TogglePlayerControllable(playerid, toggle));
			}
		}
	#endif

	#define _ALS_TogglePlayerControllable
	#define TogglePlayerControllable( FIXES_TogglePlayerControllable(
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
			if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && FIXES_gsJackedId[playerid] != INVALID_PLAYER_ID)
			{
				ClearAnimations(FIXES_gsJackedId[playerid]);
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
						SetPlayerArmedWeapon(playerid, 0);
						#if FIX_GetPlayerWeapon
							if (IsPlayerInAnyVehicle(playerid))
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
 * <fixes>DriveBy</fixes>
 */

#if FIX_DriveBy
	forward _FIXES_DriveBy(playerid);

	public  _FIXES_DriveBy(playerid)
	{
		if (GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
		{
			SetPlayerArmedWeapon(playerid, FIXES_gsDriveByWeapon[playerid]);
		}
		return FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_DRIVE_BY;
	}

	static stock _FIXES_HideDriveByWeapon(playerid)
	{
		FIXES_gsDriveByWeapon[playerid] = GetPlayerWeapon(playerid),
		FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_DRIVE_BY,
		SetPlayerArmedWeapon(playerid, 0),
		ApplyAnimation(playerid, "PED", "CAR_GETIN_RHS", 4.1, 0, 0, 0, 0, 1, 1),
		SetTimerEx(FIXES_gscDriveBy, 500, 0, FIXES_gscSpec@i, playerid);
	}
#endif

/**
 * <fixes>DriveBy</fixes>
 */

#if FIX_DriveBy
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
	{
		// ===============================
		//  BEGIN: DriveBy
		// ===============================
		#if FIX_DriveBy
			#if !FIXES_Single
				if (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE)
			#endif
				{
					if ((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH) && GetPlayerState(playerid) == PLAYER_STATE_PASSENGER && GetPlayerCameraMode(playerid) == 55 && !(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_DRIVE_BY))
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

	_FIXES_FORWARD FIXES_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
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
				FIXES_BlockUpdate(playerid);
				return 0;
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
				new engine, lights, alarm, doors, bonnet, boot, objective;
				GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, VEHICLE_PARAMS_ON, bonnet, boot, objective);

				FIXES_gsPlayerBools[playerid] |= ~e_FIXES_BOOLS_VEH_ENTER;
				FIXES_gsPlayerVehicleID[playerid] = vehicleid;
				FIXES_gsPlayerVehicleTickCount[playerid] = GetTickCount();
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
					model = GetVehicleModel(vehicleid);

				FIXES_gsPSTimer[playerid] = GetTickCount() + ((model == 431 || model == 437) ? 8000 : 2800);
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
					if (GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
					{
						FIXES_gsJackedId[i] = playerid;
						SetTimerEx("FIXES_RemoveJackedId", 5000, false, "d", i);
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
			FIXES_BlockUpdate(playerid);
			return 0;
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

#if FIX_OnPlayerEnterVehicle || FIX_OnPlayerEnterVehicle_2 || FIX_Kick || FIX_OnVehicleMod
	static stock FIXES_BlockUpdate(playerid, bool:kick = true)
	{
		if (kick)
		{
			#if FIXES_SilentKick
				new
					ip[22];
				GetPlayerIp(playerid, ip, sizeof (ip)),
				format(ip, sizeof (ip), "banip %s", ip),
				SendRconCommand(ip),
				FIXES_gsPlayerIP[playerid] = strval(ip[kick]) << 24,
				kick = strfind(ip, FIXES_gscDot, false, kick) + 1,
				FIXES_gsPlayerIP[playerid] |= strval(ip[kick]) << 16,
				kick = strfind(ip, FIXES_gscDot, false, kick) + 1,
				FIXES_gsPlayerIP[playerid] |= strval(ip[kick]) << 8,
				kick = strfind(ip, FIXES_gscDot, false, kick) + 1,
				FIXES_gsPlayerIP[playerid] |= strval(ip[kick]);
			#else
				Kick(playerid);
			#endif
		}
		return
			FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_BLOCK,
			0;
	}
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
			engine, lights, alarm, doors, bonnet, boot, objective;

		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(vehicleid, engine, lights, alarm, VEHICLE_PARAMS_OFF, bonnet, boot, objective);

		ClearAnimations(playerid);
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
				CallRemoteFunction(FIXES_gscClearPlayerMenu, FIXES_gscSpec@i, playerid);
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
				CallRemoteFunction(FIXES_gscClearPlayerMenu, FIXES_gscSpec@i, playerid);
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

#if _FIX_Menus
	#define FIXES_IS_VALID_MENU(%0) (_FIXES_IN_RANGE(_:(%0), 0, MAX_MENUS) && (FIXES_gsValidMenus[_:(%0) >>> 5] & (1 << (_:(%0) & 0x1F))))
#endif

/**
 * <fixes>Menus</fixes>
 */

#if defined _ALS_CreateMenu
	#error _ALS_CreateMenu defined
#endif
native Menu:BAD_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0) = CreateMenu;

#if _FIX_Menus
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
			Menu:ret = CreateMenu(title, columns, x, y, col1width, col2width);
		if (_FIXES_IN_RANGE(_:ret, 0, MAX_MENUS))
		{
			#if FIXES_Single
				FIXES_gsValidMenus[_:ret >>> 5] |= 1 << (_:ret & 0x1F);
			#else
				CallRemoteFunction("_FIXES_CreateMenu", FIXES_gscSpec@i, _:ret);
			#endif
		}
		return ret;
	}

	#define _ALS_CreateMenu
	#define CreateMenu( FIXES_CreateMenu(
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

#if defined _ALS_DestroyMenu
	#error _ALS_DestroyMenu defined
#endif
native BAD_DestroyMenu(Menu:menuid) = DestroyMenu;

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if _FIX_Menus || FIX_GetPlayerMenu
	#if _FIX_Menus && !FIXES_Single
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
				if (DestroyMenu(Menu:menuid))
				{
					#if _FIX_Menus
						#if FIXES_Single
							FIXES_gsValidMenus[_:menuid >>> 5] &= ~(1 << (_:menuid & 0x1F));
						#else
							CallRemoteFunction("_FIXES_DestroyMenu", FIXES_gscSpec@i, _:menuid);
						#endif
					#endif
					_FIXES_FOREACH(FIXES_gsPlayersIterator, playerid)
					{
						if (FIXES_gsCurrentMenu[playerid] == menuid)
						{
							if (HideMenuForPlayer(menuid, playerid))
							{
								#if FIXES_Single
									FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
									FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
								#else
									CallRemoteFunction(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, INVALID_MENU);
								#endif
							}
						}
					}
					return 1;
				}
			}
			return 0;
	}

	#define _ALS_DestroyMenu
	#define DestroyMenu( FIXES_DestroyMenu(
#endif

/**
 * <fixes>AddMenuItem</fixes>
 */

#if defined _ALS_AddMenuItem
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
			return AddMenuItem(menuid, column, menutext);
		}
		return 0;
	}

	#define _ALS_AddMenuItem
	#define AddMenuItem( FIXES_AddMenuItem(
#endif

/**
 * <fixes>SetMenuColumnHeader</fixes>
 */

#if defined _ALS_SetMenuColumnHeader
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
			return SetMenuColumnHeader(menuid, column, columnheader);
		}
		return 0;
	}

	#define _ALS_SetMenuColumnHeader
	#define SetMenuColumnHeader( FIXES_SetMenuColumnHeader(
#endif

/**
 * <fixes>ShowMenuForPlayer</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if defined _ALS_ShowMenuForPlayer
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
					if (ShowMenuForPlayer(menuid, playerid))
					{
						#if FIXES_Single
							FIXES_gsSettings |= e_FIXES_SETTINGS_MENU_SET;
							FIXES_gsCurrentMenu[playerid] = menuid;
						#else
							CallRemoteFunction(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, _:menuid);
						#endif
						return 1;
					}
				#else
					return ShowMenuForPlayer(menuid, playerid);
				#endif
			}
		return 0;
	}

	#define _ALS_ShowMenuForPlayer
	#define ShowMenuForPlayer( FIXES_ShowMenuForPlayer(
#endif

/**
 * <fixes>HideMenuForPlayer</fixes>
 * <fixes>HideMenuForPlayer_2</fixes>
 * <fixes>GetPlayerMenu</fixes>
 */

#if defined _ALS_HideMenuForPlayer
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
						if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS) && FIXES_gsCurrentMenu[playerid] == menuid)
					#else
						if (FIXES_gsCurrentMenu[playerid] == menuid && HideMenuForPlayer(menuid, playerid))
					#endif
						{
							#if FIXES_Single
								FIXES_gsSettings &= ~e_FIXES_SETTINGS_MENU_SET;
								FIXES_gsCurrentMenu[playerid] = Menu:INVALID_MENU;
							#else
								CallRemoteFunction(FIXES_gscSetPlayerMenu, FIXES_gscSpec@ii, playerid, INVALID_MENU);
							#endif
							#if FIX_HideMenuForPlayer_2
								return HideMenuForPlayer(menuid, playerid);
							#else
								return 1;
							#endif
						}
				#else
					return HideMenuForPlayer(menuid, playerid);
				#endif
			}
		return 0;
	}

	#define _ALS_HideMenuForPlayer
	#define HideMenuForPlayer( FIXES_HideMenuForPlayer(
#endif

/**
 * <fixes>DisableMenu</fixes>
 */

#if defined _ALS_DisableMenu
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
			return DisableMenu(menuid);
		}
		return 0;
	}

	#define _ALS_DisableMenu
	#define DisableMenu( FIXES_DisableMenu(
#endif

/**
 * <fixes>DisableMenuRow</fixes>
 */

#if defined _ALS_DisableMenuRow
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
			return DisableMenuRow(menuid, row);
		}
		return 0;
	}

	#define _ALS_DisableMenuRow
	#define DisableMenuRow( FIXES_DisableMenuRow(
#endif

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if defined _ALS_GetPlayerMenu
	#error _ALS_GetPlayerMenu defined
#endif
native BAD_GetPlayerMenu(playerid) = GetPlayerMenu;

/**
 * <fixes>GetPlayerMenu</fixes>
 */

#if FIX_GetPlayerMenu
	stock Menu:FIXES_GetPlayerMenu(playerid)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			return FIXES_gsCurrentMenu[playerid];
		}
		return Menu:INVALID_MENU;
	}

	#define _ALS_GetPlayerMenu
	#define GetPlayerMenu( FIXES_GetPlayerMenu(
#endif

/**
 * <fixes>HydraSniper</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>PutPlayerInVehicle</fixes>
 * <fixes>TrainExit</fixes>
 */

#if FIX_HydraSniper || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_TrainExit
	public OnPlayerStateChange(playerid, newstate, oldstate)
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
						model = GetVehicleModel(GetPlayerVehicleID(playerid)) - 400;
					if (_FIXES_IN_RANGE(model, 0, 211 + 1))
					{
						new
							seat = GetPlayerVehicleSeat(playerid);
						if (seat != 128)
						{
							model = (FIXES_gscMaxPassengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
							if (model == 0 || model == 15)
							{
								// Shouldn't be in this vehicle at all.
								FIXES_BlockUpdate(playerid);
							}
							else if (!(0 < seat <= model)) // Slower with "_FIXES_NO_RANGE".
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
							model = GetPlayerVehicleSeat(playerid);
						if (model != 128)
						{
							if (model == 0)
							{
								model = GetVehicleModel(GetPlayerVehicleID(playerid)) - 400;
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
						}
					#if FIX_HydraSniper
						else
						{
							model = GetVehicleModel(GetPlayerVehicleID(playerid));
						}
					#endif
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
						model = GetVehicleModel(GetPlayerVehicleID(playerid));
			#endif
					if (GetPlayerWeapon(playerid) == 34 && (model == 520 || model == 425))
					{
						SetPlayerArmedWeapon(playerid, 0);
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
			#endif
					new
						weapon,
						ammo;
					GetPlayerWeaponData(playerid, 4, weapon, ammo);
					if (weapon)
					{
						SetPlayerArmedWeapon(playerid, weapon);
						FIXES_SET(PlayerWeapon, playerid, weapon);
					}
				}
		#endif
		// ========================
		//  END:   GetPlayerWeapon
		// ========================

		#if FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_TrainExit
			#if PLAYER_STATE_PASSENGER != PLAYER_STATE_DRIVER + 1
				#error FIX_GetPlayerWeapon/FIX_PutPlayerInVehicle/FIX_TrainExit state assertation failed.
			#endif
			if (_FIXES_IN_RANGE(oldstate, PLAYER_STATE_DRIVER, PLAYER_STATE_PASSENGER + 1))
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
						SetCameraBehindPlayer(playerid),
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
						PutPlayerInVehicle(playerid, vid, FIXES_gsVehicleSeatData[playerid] >>> 24),
						bools &= ~e_FIXES_BOOLS_PUT_IN_VEHICLE;
						#if FIX_TrainExit
							switch (GetVehicleModel(vid))
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

	_FIXES_FORWARD FIXES_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

/**
 * <fixes>HydraSniper</fixes>
 * <fixes>GetPlayerWeapon</fixes>
 * <fixes>GetPlayerAmmo</fixes>
 */

#if defined _ALS_GivePlayerWeapon
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
				currentAmmo = GetPlayerAmmo(playerid);
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
			vid = GetPlayerVehicleID(playerid);
		if (vid)
		{
			#if FIX_HydraSniper
				vid = GetVehicleModel(vid);
				if (weaponid == 34 && (vid == 520 || vid == 425))
				{
					vid = GivePlayerWeapon(playerid, weaponid, ammo),
					SetPlayerArmedWeapon(playerid, 0);
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
		return GivePlayerWeapon(playerid, weaponid, ammo);
	}

	#define _ALS_GivePlayerWeapon
	#define GivePlayerWeapon( FIXES_GivePlayerWeapon(
#endif


/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if defined _ALS_ResetPlayerWeapons
	#error _ALS_ResetPlayerWeapons defined
#endif
native BAD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;


/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if FIX_GetPlayerWeapon
	stock FIXES_ResetPlayerWeapons(playerid)
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			FIXES_SET(PlayerWeapon, playerid, 0);
		}
		return ResetPlayerWeapons(playerid);
	}

	#define _ALS_ResetPlayerWeapons
	#define ResetPlayerWeapons( FIXES_ResetPlayerWeapons(
#endif

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if defined _ALS_SetPlayerArmedWeapon
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
			if (FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR && GetPlayerInterior(playerid))
			{
				// Not allowed weapons.
				return 0;
			}
		#endif
		new
			vid = GetPlayerVehicleID(playerid);
		if (vid)
		{
			#if FIX_HydraSniper
				vid = GetVehicleModel(vid);
				if (weaponid == 34 && (vid == 520 || vid == 425))
				{
					return 0;
				}
			#endif

			#if FIX_GetPlayerWeapon
				FIXES_SET(PlayerWeapon, playerid, weaponid);
			#endif
		}
		return SetPlayerArmedWeapon(playerid, weaponid);
	}

	#define _ALS_SetPlayerArmedWeapon
	#define SetPlayerArmedWeapon( FIXES_SetPlayerArmedWeapon(
#endif

/**
 * <fixes>GetPlayerWeapon</fixes>
 */

#if defined _ALS_GetPlayerWeapon
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
			return GetPlayerWeapon(playerid);
		}
		return ret;
	}

	#define _ALS_GetPlayerWeapon
	#define GetPlayerWeapon( FIXES_GetPlayerWeapon(
#endif

/**
 * <fixes>PutPlayerInVehicle</fixes>
 */

#if defined _ALS_PutPlayerInVehicle
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
				FIXES_PRINTF("TrainExit %d", GetVehicleModel(vehicleid));
				switch (GetVehicleModel(vehicleid))
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
					vid = GetPlayerVehicleID(playerid);
				if (vid)
				{
					new
						Float:x,
						Float:y,
						Float:z;
					// Remove them without the animation.
					return
						GetVehiclePos(vid, x, y, z),
						SetPlayerPos(playerid, x, y, z),
						FIXES_gsVehicleSeatData[playerid] = seatid << 24 | vehicleid,
						FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_VEHICLE,
						1;
				}
			#endif
			// ===========================
			//  END:   PutPlayerInVehicle
			// ===========================
			return PutPlayerInVehicle(playerid, vehicleid, seatid);
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
					vid = GetPlayerVehicleID(playerid);
				if (vid)
				{
					new
						Float:x,
						Float:y,
						Float:z;
					// Remove them without the animation.
					return
						GetVehiclePos(vid, x, y, z),
						SetPlayerPos(playerid, x, y, z),
						CallRemoteFunction(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iiiii, playerid, vehicleid, seatid, 1, vid),
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
					model = GetVehicleModel(vehicleid);
				switch (model)
				{
					case 449, 537, 538:
					{
						CallRemoteFunction(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iiiii, playerid, vehicleid, seatid, 0, model);
						//FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_TRAIN;
					}
				}
			#endif
			// ==================
			//  END:   TrainExit
			// ==================
			return PutPlayerInVehicle(playerid, vehicleid, seatid);
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

	#define _ALS_PutPlayerInVehicle
	#define PutPlayerInVehicle( FIXES_PutPlayerInVehicle(
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
			if (GetPVarInt(playerid, FIXES_pvarPlayerCheckpoint))
		#endif
			{
				return
					#if FIXES_Single
						FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CP_DELAYED,
					#else
						DeletePVar(playerid, FIXES_pvarPlayerCheckpoint),
					#endif
						SetPlayerCheckpoint(playerid, x, y, z, size);
			}
			return 0;
	}
#endif

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if defined _ALS_SetPlayerCheckpoint
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
				SetPVarInt(playerid, FIXES_pvarPlayerCheckpoint, 1),
			#endif
				DisablePlayerCheckpoint(playerid),
				SetTimerEx(FIXES_gscSetCheckpoint, 50, 0, FIXES_gscSpec@iffff, playerid, x, y, z, size),
				1;
	}

	#define _ALS_SetPlayerCheckpoint
	#define SetPlayerCheckpoint( FIXES_SetPlayerCheckpoint(
#endif

/**
 * <fixes>SetPlayerCheckpoint</fixes>
 */

#if defined _ALS_DisablePlayerCheckpoint
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
				DeletePVar(playerid, FIXES_pvarPlayerCheckpoint),
			#endif
				DisablePlayerCheckpoint(playerid);
	}

	#define _ALS_DisablePlayerCheckpoint
	#define DisablePlayerCheckpoint( FIXES_DisablePlayerCheckpoint(
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
			if (GetPVarInt(playerid, FIXES_pvarPlayerRaceCheckpoint))
		#endif
			{
				return
					#if FIXES_Single
						FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_RACE_CP_DELAYED,
					#else
						DeletePVar(playerid, FIXES_pvarPlayerRaceCheckpoint),
					#endif
						SetPlayerRaceCheckpoint(playerid, type, x, y, z, nextx, nexty, nextz, size);
			}
			return 0;
	}
#endif

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if defined _ALS_SetPlayerRaceCheckpoint
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
				SetPVarInt(playerid, FIXES_pvarPlayerRaceCheckpoint, 1),
			#endif
				DisablePlayerRaceCheckpoint(playerid),
				SetTimerEx(FIXES_gscSetRaceCheckpoint, 50, 0, FIXES_gscSpec@iifffffff, playerid, type, x, y, z, nextx, nexty, nextz, size),
				1;
	}

	#define _ALS_SetPlayerRaceCheckpoint
	#define SetPlayerRaceCheckpoint( FIXES_SetPlayerRaceCheckpoint(
#endif

/**
 * <fixes>SetPlayerRaceCheckpoint</fixes>
 */

#if defined _ALS_DisablePlayerRaceCP
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
				DeletePVar(playerid, FIXES_pvarPlayerRaceCheckpoint),
			#endif
				DisablePlayerRaceCheckpoint(playerid);
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
				KillTimer(timers[MAX_PLAYERS]);
			timers[MAX_PLAYERS] = 0,
			TextDrawHideForAll(FIXES_gsGTStyle[style]);
		}
		else if (playerid == INVALID_PLAYER_ID)
		{
			// Remove all GameTexts of this style for everyone.
			if (timers[MAX_PLAYERS] != 0)
				KillTimer(timers[MAX_PLAYERS]);
			timers[MAX_PLAYERS] = 0,
			TextDrawHideForAll(FIXES_gsGTStyle[style]),
			playerid = parr[MAX_PLAYERS],
			parr[MAX_PLAYERS] = MAX_PLAYERS;
			for (new next; playerid != MAX_PLAYERS; playerid = next)
			{
				if (timers[playerid] != 0)
					KillTimer(timers[playerid]);
				PlayerTextDrawHide(playerid, FIXES_gsPGTStyle[playerid][style]),
				next = parr[playerid],
				timers[playerid] = parr[playerid] = 0;
			}
		}
		else //if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			// Remove.
			if (timers[playerid] != 0)
				KillTimer(timers[playerid]);
			timers[playerid] = 0,
			TextDrawHideForPlayer(playerid, FIXES_gsGTStyle[style]),
			PlayerTextDrawHide(playerid, FIXES_gsPGTStyle[playerid][style]),
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
				TextDrawSetString(FIXES_gsGTStyle[style], string),
				TextDrawShowForAll(FIXES_gsGTStyle[style]);
			}
			else
			{
				_FIXES_HideGameTextForPlayer(playerid, style, FIXES_gsPlayerPGTShown[style], FIXES_gsGTTimer[style]),
				PlayerTextDrawSetString(playerid, FIXES_gsPGTStyle[playerid][style], string),
				PlayerTextDrawShow(playerid, FIXES_gsPGTStyle[playerid][style]),
				_FIXES_AddInternal(FIXES_gsPlayerPGTShown[style], playerid, MAX_PLAYERS);
			}
			if (time)
				FIXES_gsGTTimer[style][playerid] = SetTimerEx(FIXES_gscHideGameTextTimer, time, false, FIXES_gscSpec@ii, playerid, style);
		}
		return 1;
	}
#endif

/**
 * <fixes>GameText</fixes>
 */

#if defined _ALS_GameTextForAll
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
			// FINALLY come up with a better IsNull check!
			if (isnull(string))
			{
				#if FIXES_Single
					return _FIXES_HideGameTextTimer(INVALID_PLAYER_ID, style);
				#else
					return CallRemoteFunction(FIXES_gscHideGameTextTimer, FIXES_gscSpec@ii, INVALID_PLAYER_ID, style);
				#endif
			}
			else
			{
				#if FIXES_Single
					return _FIXES_GameTextShow(MAX_PLAYERS, string, time, style);
				#else
					return CallRemoteFunction(FIXES_gscGameTextShow, FIXES_gscSpec@isii, MAX_PLAYERS, string, time, style);
				#endif
			}
		}
		return 0;
	}

	#define _ALS_GameTextForAll

	#define GameTextForAll( FIXES_GameTextForAll(
#endif

/**
 * <fixes>GameText</fixes>
 */

#if defined _ALS_GameTextForPlayer
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
			if (isnull(string))
			{
				#if FIXES_Single
					return _FIXES_HideGameTextTimer(playerid, style);
				#else
					return CallRemoteFunction(FIXES_gscHideGameTextTimer, FIXES_gscSpec@ii, playerid, style);
				#endif
			}
			else
			{
				#if FIXES_Single
					return _FIXES_GameTextShow(playerid, string, time, style);
				#else
					return CallRemoteFunction(FIXES_gscGameTextShow, FIXES_gscSpec@isii, playerid, string, time, style);
				#endif
			}
		}
		return 0;
	}

	#define _ALS_GameTextForPlayer

	#define GameTextForPlayer( FIXES_GameTextForPlayer(
#endif

/**
 * <fixes>HideGameText</fixes>
 */

#if defined _ALS_HideGameTextForAll
	#error _ALS_HideGameTextForAll defined
#endif

#if FIX_HideGameText
	//stock FIXES_HideGameTextForAll(style)
	//{
	//	if (FIXES_gsGTTimer[style][MAX_PLAYERS] != 0)
	//	{
	//		KillTimer(FIXES_gsGTTimer[style][MAX_PLAYERS]);
	//		FIXES_gsGTTimer[style][MAX_PLAYERS] = 0;
	//	}
	//	return GameTextForAll(FIXES_gcSpace, 0, style);
	//}

	#define _ALS_HideGameTextForAll
	#define HideGameTextForAll(%0) GameTextForAll(FIXES_gcNull, 0, (%0))
#endif

/**
 * <fixes>HideGameText</fixes>
 */

#if defined _ALS_HideGameTextForPlayer
	#error _ALS_HideGameTextForPlayer defined
#endif

#if FIX_HideGameText
	//stock FIXES_HideGameTextForPlayer(playerid, style)
	//{
	//	if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
	//	{
	//		if (FIXES_gsGTTimer[style][playerid] != 0)
	//		{
	//			KillTimer(FIXES_gsGTTimer[style][playerid]);
	//			FIXES_gsGTTimer[style][playerid] = 0;
	//		}
	//		return GameTextForPlayer(playerid, FIXES_gcSpace, 0, style);
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
	#if defined _ALS_CreatePlayerTextDraw
		#error _ALS_CreatePlayerTextDraw defined
	#endif
	native PlayerText:BAD_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]) = CreatePlayerTextDraw;
#endif

#if FIX_CreatePlayerTextDraw || FIX_CreatePlayerTextDraw_2

	#if FIX_CreatePlayerTextDraw
		#define _FIXES_PASS_STRING(%0(%1,%2,%3,%4)) (isnull(%4) ? %0(%1,%2,%3,FIXES_gsSpace) : %0(%1,%2,%3,%4))
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
			_FIXES_rtrim(text);
		#endif
			_FIXES_RETURN_STRING(CreatePlayerTextDraw(playerid, x, y, text));
		#if FIX_CreatePlayerTextDraw_2
			_FIXES_untrim(text);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if defined _ALS_CreatePlayerTextDraw
		#undef CreatePlayerTextDraw
	#else
		#define _ALS_CreatePlayerTextDraw
	#endif
	#define CreatePlayerTextDraw( FIXES_CreatePlayerTextDraw(
#endif

/**
 * <fixes>PlayerTextDrawSetString</fixes>
 * <fixes>PlayerTextDrawSetString_2</fixes>
 */

#if !FIX_const
	#if defined _ALS_PlayerTextDrawSetString
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
		#define _FIXES_PASS_STRING(%0(%2,%3,%4)) (isnull(%4) ? %0(%2,%3,FIXES_gsSpace) : %0(%2,%3,%4))
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
			_FIXES_rtrim(string);
		#endif
			_FIXES_RETURN_STRING(PlayerTextDrawSetString(playerid, text, string));
		#if FIX_PlayerTextDrawSetString_2
			_FIXES_untrim(string);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if defined _ALS_PlayerTextDrawSetString
		#undef PlayerTextDrawSetString
	#else
		#define _ALS_PlayerTextDrawSetString
	#endif
	#define PlayerTextDrawSetString( FIXES_PlayerTextDrawSetString(
#endif

/**
 * <fixes>TextDrawCreate</fixes>
 * <fixes>TextDrawCreate_2</fixes>
 */

#if !FIX_const
	#if defined _ALS_TextDrawCreate
		#error _ALS_TextDrawCreate defined
	#endif
	native Text:BAD_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
#endif

#if FIX_TextDrawCreate || FIX_TextDrawCreate_2

	#if FIX_TextDrawCreate
		#define _FIXES_PASS_STRING(%0(%2,%3,%4)) (isnull(%4) ? %0(%2,%3,FIXES_gsSpace) : %0(%2,%3,%4))
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
			_FIXES_rtrim(text);
		#endif
			_FIXES_RETURN_STRING(TextDrawCreate(x, y, text));
		#if FIX_TextDrawCreate_2
			_FIXES_untrim(text);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if defined _ALS_TextDrawCreate
		#undef TextDrawCreate
	#else
		#define _ALS_TextDrawCreate
	#endif
	#define TextDrawCreate( FIXES_TextDrawCreate(
#endif

/**
 * <fixes>TextDrawSetString</fixes>
 * <fixes>TextDrawSetString_2</fixes>
 */

#if !FIX_const
	#if defined _ALS_TextDrawSetString
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
		#define _FIXES_PASS_STRING(%0(%3,%4)) (isnull(%4) ? %0(%3,FIXES_gsSpace) : %0(%3,%4))
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
			_FIXES_rtrim(string);
		#endif
			_FIXES_RETURN_STRING(TextDrawSetString(text, string));
		#if FIX_TextDrawSetString_2
			_FIXES_untrim(string);
			return ret;
		#endif
	}

	#undef _FIXES_PASS_STRING
	#undef _FIXES_RETURN_STRING

	#if defined _ALS_TextDrawSetString
		#undef TextDrawSetString
	#else
		#define _ALS_TextDrawSetString
	#endif
	#define TextDrawSetString( FIXES_TextDrawSetString(
#endif

/**
 * <fixes>AllowInteriorWeapons</fixes>
 */

#if defined _ALS_AllowInteriorWeapons
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
					if (GetPlayerInterior(i))
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
			CallRemoteFunction(FIXES_gscAllowInteriorWeapons, FIXES_gscSpec@i, allow);
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
					if (GetPlayerInterior(i))
					{
						FIXES_gsPlayerBools[i] |= e_FIXES_BOOLS_INTERIOR;
					}
				}
			}
			return allow;
		}
	#endif

	#define _ALS_AllowInteriorWeapons
	#define AllowInteriorWeapons( FIXES_AllowInteriorWeapons(
#endif

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if defined _ALS_GetPlayerInterior
	#error _ALS_GetPlayerInterior defined
#endif
native BAD_GetPlayerInterior(playerid) = GetPlayerInterior;

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if FIX_GetPlayerInterior
	stock FIXES_GetPlayerInterior(playerid)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			return FIXES_GET(PlayerInterior, playerid);
		}
		return 0;
	}

	#define _ALS_GetPlayerInterior
	#define GetPlayerInterior( FIXES_GetPlayerInterior(
#endif

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if defined _ALS_SetPlayerInterior
	#error _ALS_SetPlayerInterior defined
#endif
native BAD_SetPlayerInterior(playerid, interiorid) = SetPlayerInterior;

/**
 * <fixes>GetPlayerInterior</fixes>
 */

#if FIX_GetPlayerInterior
	stock FIXES_SetPlayerInterior(playerid, interiorid)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			FIXES_SET(PlayerInterior, playerid, interiorid);
			return SetPlayerInterior(playerid, interiorid);
		}
		return 0;
	}

	#define _ALS_SetPlayerInterior
	#define SetPlayerInterior( FIXES_SetPlayerInterior(
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
				if ((FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_TELEPORT) || ((FIXES_gsSettings & e_FIXES_SETTINGS_ADMIN_TELEPORT) && (IsPlayerAdmin(playerid))))
				{
					SetPlayerPosFindZ(playerid, fX, fY, fZ);
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

#if defined _ALS_AllowPlayerTeleport
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
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
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
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
			{
				CallRemoteFunction(FIXES_gscAllowTeleport, FIXES_gscSpec@ii, playerid, allow);
			}
			return 0;
		}
	#endif

	#define _ALS_AllowPlayerTeleport
	#define AllowPlayerTeleport( FIXES_AllowPlayerTeleport(
#endif

/**
 * <fixes>AllowTeleport</fixes>
 */

#if defined _ALS_AllowAdminTeleport
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
				CallRemoteFunction(FIXES_gscAllowTeleport, FIXES_gscSpec@ii, INVALID_PLAYER_ID, allow),
				allow;
		}
	#endif

	#define _ALS_AllowAdminTeleport
	#define AllowAdminTeleport( FIXES_AllowAdminTeleport(
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

#if defined _ALS_SetPlayerSpecialAction
	#error _ALS_SetPlayerSpecialAction defined
#endif
native BAD_SetPlayerSpecialAction(playerid, actionid) = SetPlayerSpecialAction;

/**
 * <fixes>SetPlayerSpecialAction</fixes>
 */

#if FIX_SetPlayerSpecialAction
	stock FIXES_SetPlayerSpecialAction(playerid, actionid)
	{
		if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
		{
			ClearAnimations(playerid);
		}
		SetPlayerSpecialAction(playerid, actionid);
		return 1;
	}

	#define _ALS_SetPlayerSpecialAction
	#define SetPlayerSpecialAction( FIXES_SetPlayerSpecialAction(
#endif

/**
 * <fixes>ClearAnimations</fixes>
 */

#if defined _ALS_ClearAnimations
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
			if (IsPlayerInAnyVehicle(playerid))
		#endif
		#if FIX_ClearAnimations
			{
				return ApplyAnimation(playerid, "PED", "CAR_SIT", 4.0, 0, 0, 0, 0, 1, forcesync);
			}
		#endif
		#if FIX_ClearAnimations + FIX_ClearAnimations_2 == 1 // XOR
			{
				return ClearAnimations(playerid, forcesync);
			}
		#endif
		#if FIX_ClearAnimations_2
			new
				ret = ClearAnimations(playerid, forcesync);
			ApplyAnimation(playerid, "PED", "IDLE_STANCE", 4.0, 0, 0, 0, 0, 1, forcesync);
			ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 1, forcesync);
			ApplyAnimation(playerid, "PED", "WALK_PLAYER", 4.0, 0, 0, 0, 0, 1, forcesync);
			return ret;
		#endif
	}

	#define _ALS_ClearAnimations
	#define ClearAnimations( FIXES_ClearAnimations(
#endif

/**
 * <fixes>GangZoneCreate</fixes>
 */

#if defined _ALS_GangZoneCreate
	#error _ALS_GangZoneCreate defined
#endif
native BAD_GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy) = GangZoneCreate;

/**
 * <fixes>GangZoneCreate</fixes>
 */

#if FIX_GangZoneCreate
	stock FIXES_GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy)
	{
		return GangZoneCreate(floatsub(minx, floatfract(minx)), floatsub(miny, floatfract(miny)), floatsub(maxx, floatfract(maxx)), floatsub(maxy, floatfract(maxy)));
	}

	#define _ALS_GangZoneCreate
	#define GangZoneCreate( FIXES_GangZoneCreate(
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if !FIX_const
	#if defined _ALS_ShowPlayerDialog
		#error _ALS_ShowPlayerDialog defined
	#endif
	native BAD_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[]) = ShowPlayerDialog;
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if FIX_OnDialogResponse || FIX_GetPlayerDialog
	stock FIXES_ShowPlayerDialog(playerid, dialog, style, _FIXES_MAYBE_CONST title[], _FIXES_MAYBE_CONST caption[], _FIXES_MAYBE_CONST button1[], _FIXES_MAYBE_CONST button2[])
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			FIXES_SET(PlayerDialog, playerid, dialog);
			return ShowPlayerDialog(playerid, dialog, style, title, caption, button1, button2);
		}
		return 0;
	}

	#if defined _ALS_ShowPlayerDialog
		#undef ShowPlayerDialog
	#else
		#define _ALS_ShowPlayerDialog
	#endif
	#define ShowPlayerDialog( FIXES_ShowPlayerDialog(
#endif

/**
 * <fixes>OnDialogResponse</fixes>
 * <fixes>GetPlayerDialog</fixes>
 */

#if FIX_OnDialogResponse || FIX_GetPlayerDialog
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
	{
		// =========================
		//  BEGIN: OnDialogResponse
		// =========================
		#if FIX_OnDialogResponse || FIX_GetPlayerDialog
			#if FIXES_Single
				#if FIX_OnDialogResponse
					dialogid = FIXES_gsPlayerDialog[playerid];
				#endif
				FIXES_gsPlayerDialog[playerid] = INVALID_DIALOG_ID;
			#elseif FIX_OnDialogResponse
				_FIXES_IS_IN_CHARGE()
				{
					// If there are multiple scripts, we can't just wipe the
					// current dialog data or subsequent scripts will display
					// the wrong value.
					dialogid = GetPVarInt(playerid, FIXES_pvarPlayerDialog),
					SetPVarInt(playerid, FIXES_pvarCurrentDialog, dialogid),
					SetPVarInt(playerid, FIXES_pvarPlayerDialog, INVALID_DIALOG_ID);
				}
				else
				{
					dialogid = GetPVarInt(playerid, FIXES_pvarCurrentDialog);
				}
			#else
				SetPVarInt(playerid, FIXES_pvarPlayerDialog, INVALID_DIALOG_ID);
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

#if defined _ALS_GetPlayerDialog
	#error _ALS_GetPlayerDialog defined
#endif

#if FIX_GetPlayerDialog
	stock FIXES_GetPlayerDialog(playerid)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			return FIXES_GET(PlayerDialog, playerid);
		}
		return -1;
	}

	#define _ALS_GetPlayerDialog
	#define GetPlayerDialog( FIXES_GetPlayerDialog(
#endif

/**
 * <fixes>valstr</fixes>
 */

#if defined _ALS_valstr
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

	#define _ALS_valstr
	#define valstr( FIXES_valstr(
#endif

/**
 * <fixes>fclose</fixes>
 */

#if defined _ALS_fclose
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

	#define _ALS_fclose
	#define fclose( FIXES_fclose(
#endif

/**
 * <fixes>fwrite</fixes>
 */

#if defined _ALS_fwrite
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

	#define _ALS_fwrite
	#define fwrite( FIXES_fwrite(
#endif

/**
 * <fixes>fread</fixes>
 */

#if defined _ALS_fread
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

	#define _ALS_fread
	#define fread( FIXES_fread(
#endif

/**
 * <fixes>fputchar</fixes>
 */

#if defined _ALS_fputchar
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

	#define _ALS_fputchar
	#define fputchar( FIXES_fputchar(
#endif

/**
 * <fixes>fgetchar</fixes>
 */

#if defined _ALS_fgetchar
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

	#define _ALS_fgetchar
	#define fgetchar( FIXES_fgetchar(
#endif

/**
 * <fixes>fblockwrite</fixes>
 */

#if defined _ALS_fblockwrite
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

	#define _ALS_fblockwrite
	#define fblockwrite( FIXES_fblockwrite(
#endif

/**
 * <fixes>fblockread</fixes>
 */

#if defined _ALS_fblockread
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

	#define _ALS_fblockread
	#define fblockread( FIXES_fblockread(
#endif

/**
 * <fixes>fseek</fixes>
 */

#if defined _ALS_fseek
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

	#define _ALS_fseek
	#define fseek( FIXES_fseek(
#endif

/**
 * <fixes>flength</fixes>
 */

#if defined _ALS_flength
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

	#define _ALS_flength
	#define flength( FIXES_flength(
#endif

/**
 * <fixes>Kick</fixes>
 */

#if defined _ALS_Kick
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
		Kick(playerid);
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
					CallRemoteFunction("@FIXES_Kick", "i", playerid),
				#endif
					TogglePlayerSpectating(playerid, true),
					TogglePlayerControllable(playerid, false),
					SetPVarInt(playerid, FIXES_pvarKick, SetTimerEx(FIXES_gscKick, 1000, 0, FIXES_gscSpec@i, playerid)),
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_KICKED,
					1;
		}
		else
		{
			return Kick(playerid);
		}
	}

	#define _ALS_Kick
	#define Kick( FIXES_Kick(
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
				CallRemoteFunction(FIXES_gscAllowInteriorWeapons, FIXES_gscSpec@i, !(FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR));
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
								PlayerTextDrawDestroy(i, FIXES_gsPGTStyle[i][j]);
							}
						#endif
						// =================
						//  END:   GameText
						// =================

						// =================================
						//  BEGIN: TogglePlayerControllable
						// =================================
						#if FIX_TogglePlayerControllable
							CallRemoteFunction(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, i, !(FIXES_gsPlayerBools[i] & e_FIXES_BOOLS_UNCONTROLLABLE));
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
								CallRemoteFunction(FIXES_gscPutPlayerInVehicle, FIXES_gscSpec@iii, i, FIXES_gsVehicleSeatData[i] & 0x00FFFFFF, FIXES_gsVehicleSeatData[i] >>> 24);
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
						TextDrawDestroy(FIXES_gsGTStyle[13]),
						TextDrawDestroy(FIXES_gsGTStyle[12]),
						TextDrawDestroy(FIXES_gsGTStyle[11]),
						TextDrawDestroy(FIXES_gsGTStyle[10]),
						TextDrawDestroy(FIXES_gsGTStyle[9]),
						TextDrawDestroy(FIXES_gsGTStyle[8]),
						TextDrawDestroy(FIXES_gsGTStyle[7]),
					#endif
						TextDrawDestroy(FIXES_gsGTStyle[6]),
						TextDrawDestroy(FIXES_gsGTStyle[5]),
						TextDrawDestroy(FIXES_gsGTStyle[4]),
						TextDrawDestroy(FIXES_gsGTStyle[3]),
						TextDrawDestroy(FIXES_gsGTStyle[2]),
						TextDrawDestroy(FIXES_gsGTStyle[1]),
						TextDrawDestroy(FIXES_gsGTStyle[0]);
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
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][13]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][12]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][11]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][10]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][9]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][8]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][7]),
						#endif
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][6]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][5]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][4]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][3]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][2]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][1]),
							PlayerTextDrawDestroy(playerid, FIXES_gsPGTStyle[playerid][0]);
					}
				#if FIX_GameTextStyles
					TextDrawDestroy(FIXES_gsGTStyle[13]),
					TextDrawDestroy(FIXES_gsGTStyle[12]),
					TextDrawDestroy(FIXES_gsGTStyle[11]),
					TextDrawDestroy(FIXES_gsGTStyle[10]),
					TextDrawDestroy(FIXES_gsGTStyle[9]),
					TextDrawDestroy(FIXES_gsGTStyle[8]),
					TextDrawDestroy(FIXES_gsGTStyle[7]),
				#endif
					TextDrawDestroy(FIXES_gsGTStyle[6]),
					TextDrawDestroy(FIXES_gsGTStyle[5]),
					TextDrawDestroy(FIXES_gsGTStyle[4]),
					TextDrawDestroy(FIXES_gsGTStyle[3]),
					TextDrawDestroy(FIXES_gsGTStyle[2]),
					TextDrawDestroy(FIXES_gsGTStyle[1]),
					TextDrawDestroy(FIXES_gsGTStyle[0]);
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

#if defined _ALS_strins
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

	#define _ALS_strins
	#define strins( FIXES_strins(
#endif

/**
 * <fixes>ApplyAnimation</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 * <fixes>ApplyActorAnimation</fixes>
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyAnimation || FIX_ApplyAnimation_2 || FIX_ApplyActorAnimation || FIX_ApplyActorAnimation_2
	static stock _FIXES_GetAnimLibIndex(const animlib[])
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

/**
 * <fixes>ApplyAnimation_2</fixes>
 */

#if FIX_ApplyAnimation_2
	static stock _FIXES_ApplyAnimationDelay(const animname[], playerid, idx, Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0)
	{
		if (FIXES_gsPlayerAnimTimer[playerid])
		{
			KillTimer(FIXES_gsPlayerAnimTimer[playerid]),
			FIXES_gsPlayerAnimTimer[playerid] = 0;
		}
		if (FIXES_gsPlayerAnimLibs[playerid][idx >>> 5] & (1 << (idx & 0x1F)))
		{
			FIXES_gsPlayerAnimLibs[playerid][idx >>> 5] &= ~(1 << (idx & 0x1F)),
			FIXES_gsPlayerAnimName[playerid][0] = '\0',
			strcat(FIXES_gsPlayerAnimName[playerid], animname),
			FIXES_gsPlayerAnimTimer[playerid] = SetTimerEx("_FIXES_ApplyAnimation", 350, false, "ddfdddddd", playerid, idx, fDelta, loop, lockx, locky, freeze, time, forcesync);
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
		ApplyAnimation(playerid, FIXES_gscAnimLib[animlib], FIXES_gsPlayerAnimName[playerid], fDelta, loop, lockx, locky, freeze, time, forcesync),
		FIXES_gsPlayerAnimTimer[playerid] = 0;
	}
#endif

/**
 * <fixes>ApplyAnimation</fixes>
 * <fixes>ApplyAnimation_2</fixes>
 */

#if !FIX_const
	#if defined _ALS_ApplyAnimation
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
			idx;

		idx = _FIXES_GetAnimLibIndex(animlib);

		if (idx != -1)
		{
			#if FIX_ApplyAnimation_2
				_FIXES_ApplyAnimationDelay(animname, playerid, idx, fDelta, loop, lockx, locky, freeze, time, forcesync);
			#endif
				return ApplyAnimation(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
		}

		return 0;
	}

	#if defined _ALS_ApplyAnimation
		#undef ApplyAnimation
	#else
		#define _ALS_ApplyAnimation
	#endif
	#define ApplyAnimation( FIXES_ApplyAnimation(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if FIX_ApplyActorAnimation_2
	static stock _FIXES_ApplyActorAnimationDelay(const animname[], actorid, idx, Float:fDelta, loop, lockx, locky, freeze, time)
	{
		if (FIXES_gsActorAnimTimer[actorid])
		{
			KillTimer(FIXES_gsActorAnimTimer[actorid]),
			FIXES_gsActorAnimTimer[actorid] = 0;
		}
		if (FIXES_gsActorAnimLibs[actorid][idx >>> 5] & (1 << (idx & 0x1F)))
		{
			FIXES_gsActorAnimLibs[actorid][idx >>> 5] &= ~(1 << (idx & 0x1F)),
			FIXES_gsActorAnimName[actorid][0] = '\0',
			strcat(FIXES_gsActorAnimName[actorid], animname),
			FIXES_gsActorAnimTimer[actorid] = SetTimerEx("_FIXES_ApplyActorAnimation", 350, false, "ddfdddddd", actorid, idx, fDelta, loop, lockx, locky, freeze, time);
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
		ApplyActorAnimation(actorid, FIXES_gscAnimLib[animlib], FIXES_gsActorAnimName[actorid], fDelta, loop, lockx, locky, freeze, time),
		FIXES_gsActorAnimTimer[actorid] = 0;
	}
#endif

/**
 * <fixes>ApplyActorAnimation</fixes>
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if !FIX_const
	#if defined _ALS_ApplyActorAnimation
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
			idx;

		idx = _FIXES_GetAnimLibIndex(animlib);

		if (idx != -1)
		{
			#if FIX_ApplyActorAnimation_2
				_FIXES_ApplyActorAnimationDelay(animname, actorid, idx, fDelta, loop, lockx, locky, freeze, time);
			#endif
				return ApplyActorAnimation(actorid, animlib, animname, fDelta, loop, lockx, locky, freeze, time);
		}

		return 0;
	}

	#if defined _ALS_ApplyActorAnimation
		#undef ApplyActorAnimation
	#else
		#define _ALS_ApplyActorAnimation
	#endif
	#define ApplyActorAnimation( FIXES_ApplyActorAnimation(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if defined _ALS_CreateActor
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

		actorid = CreateActor(modelid, X, Y, Z, Rotation);

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

	#define _ALS_CreateActor
	#define CreateActor( FIXES_CreateActor(
#endif

/**
 * <fixes>ApplyActorAnimation_2</fixes>
 */

#if defined _ALS_DestroyActor
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
			KillTimer(FIXES_gsActorAnimTimer[actorid]),
			FIXES_gsActorAnimTimer[actorid] = 0;
		}

		return DestroyActor(actorid);
	}

	#define _ALS_DestroyActor
	#define DestroyActor( FIXES_DestroyActor(
#endif

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if defined _ALS_SetVehicleParamsEx
	#error _ALS_SetVehicleParamsEx defined
#endif
native BAD_SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective) = SetVehicleParamsEx;

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3
	stock FIXES_SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective)
	{
		FIXES_gsVehicleIsLocked[vehicleid] = doors == VEHICLE_PARAMS_ON;
		return SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	}

	#define _ALS_SetVehicleParamsEx
	#define SetVehicleParamsEx( FIXES_SetVehicleParamsEx(
#endif

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if defined _ALS_GetVehicleParamsEx
	#error _ALS_GetVehicleParamsEx defined
#endif
native BAD_GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective) = GetVehicleParamsEx;

/**
 * <fixes>OnPlayerEnterVehicle_3</fixes>
 */

#if FIX_OnPlayerEnterVehicle_3
	stock FIXES_GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective)
	{
		new
			ret = GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
		#if FIXES_Single
			doors = FIXES_gsVehicleIsLocked[vehicleid] ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
		#else
			#if !defined FILTERSCRIPT
				doors = _FIXES_GetVehicleDoorsEx(vehicleid) ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
			#else
				doors = CallRemoteFunction("_FIXES_GetVehicleDoorsEx", "i", vehicleid) ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
			#endif
		#endif
		return ret;
	}

	#define _ALS_GetVehicleParamsEx
	#define GetVehicleParamsEx( FIXES_GetVehicleParamsEx(
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

#if defined _ALS_random
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

	#define _ALS_random
	#define random( FIXES_random(
#endif

/**
 * <fixes>sleep</fixes>
 */

// Uses a little trick to consume part of the line and thus not match
// our hooked version.
#if defined _ALS_sleep
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
			SetPlayerCameraPos(playerid, x, y, z);
		}
		else
		{
			SetPlayerCameraLookAt(playerid, x, y, z, cut);
		}
		return 0;
	}
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if defined _ALS_SetPlayerCameraPos
	#error _ALS_SetPlayerCameraPos defined
#endif
native BAD_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraPos;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			#if FIXES_Single
				if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_SPECTATING || GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
			#else
				if (GetPVarInt(playerid, FIXES_pvarPlayerSpectate) || GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
			#endif
				{
					SetTimerEx(FIXES_gscSetCamera, 300, 0, FIXES_gscSpec@iifff, playerid, 1, x, y, z);
				}
				else
				{
					SetPlayerCameraPos(playerid, x, y, z);
				}
		}
		return 0;
	}

	#define _ALS_SetPlayerCameraPos
	#define SetPlayerCameraPos( FIXES_SetPlayerCameraPos(
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if defined _ALS_SetPlayerCameraLookAt
	#error _ALS_SetPlayerCameraLookAt defined
#endif
native BAD_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z) = SetPlayerCameraLookAt;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, cut = CAMERA_CUT)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			#if FIXES_Single
				if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_SPECTATING || GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
			#else
				if (GetPVarInt(playerid, FIXES_pvarPlayerSpectate) || GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
			#endif
				{
					SetTimerEx(FIXES_gscSetCamera, 300, 0, FIXES_gscSpec@iifffi, playerid, 0, x, y, z, cut);
				}
				else
				{
					SetPlayerCameraLookAt(playerid, x, y, z, cut);
				}
		}
		return 0;
	}

	#define _ALS_SetPlayerCameraLookAt
	#define SetPlayerCameraLookAt( FIXES_SetPlayerCameraLookAt(
#endif

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if defined _ALS_TogglePlayerSpectating
	#error _ALS_TogglePlayerSpectating defined
#endif
native BAD_TogglePlayerSpectating(playerid, toggle) = TogglePlayerSpectating;

/**
 * <fixes>SetPlayerCamera</fixes>
 */

#if FIX_SetPlayerCamera
	stock FIXES_TogglePlayerSpectating(playerid, toggle)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			if (toggle)
			{
				#if FIXES_Single
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_SPECTATING;
				#else
					SetPVarInt(playerid, FIXES_pvarPlayerSpectate, 1);
				#endif
			}
			else
			{
				#if FIXES_Single
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_SPECTATING;
				#else
					DeletePVar(playerid, FIXES_pvarPlayerSpectate);
				#endif
			}
			return TogglePlayerSpectating(playerid, toggle);
		}
		return 0;
	}

	#define _ALS_TogglePlayerSpectating
	#define TogglePlayerSpectating( FIXES_TogglePlayerSpectating(
#endif

/**
 * <fixes>SetPlayerTime</fixes>
 */

#if defined _ALS_SetPlayerTime
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
		return SetPlayerTime(playerid, hour, minute);
	}

	stock FIXES_SetPlayerTime(playerid, hour, minute)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_ON_PLAYER_CONNECT)
			{
				return SetTimerEx(FIXES_gscSetTime, 250, 0, FIXES_gscSpec@iii, playerid, hour, minute);
			}
			return SetPlayerTime(playerid, hour, minute);
		}
		return 0;
	}

	#define _ALS_SetPlayerTime
	#define SetPlayerTime( FIXES_SetPlayerTime(
#endif

/**
 * <fixes>SetPlayerColor</fixes>
 */

#if defined _ALS_SetPlayerColor
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
		return SetPlayerColor(playerid, color);
	}

	stock FIXES_SetPlayerColor(playerid, color)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_ON_PLAYER_CONNECT)
			{
				return SetTimerEx(FIXES_gscSetColor, 300, 0, FIXES_gscSpec@ii, playerid, color);
			}
			return SetPlayerColor(playerid, color);
		}
		return 0;
	}

	#define _ALS_SetPlayerColor
	#define SetPlayerColor( FIXES_SetPlayerColor(
#endif

/**
 * <fixes>GetPlayerWeaponData</fixes>
 */

#if defined _ALS_GetPlayerWeaponData
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
			slot = GetPlayerWeaponData(playerid, slot, weapons, ammo),
			weapons = ammo ? weapons : 0,
			slot;
	}

	#define _ALS_GetPlayerWeaponData
	#define GetPlayerWeaponData( FIXES_GetPlayerWeaponData(
#endif

/**
 * <fixes>strcmp</fixes>
 */

#if defined _ALS_strcmp
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

	#define _ALS_strcmp
	#define strcmp( FIXES_strcmp(
#endif

/**
 * <fixes>GetPVarString</fixes>
 */

#if !FIX_const
	#if defined _ALS_GetPVarString
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
		len = GetPVarString(playerid, varname, string_return, len);
		static i; i = -1;
		do {} while ((string_return[++i] &= 0xFF) != '\0');
		return len;
	}

	#if defined _ALS_GetPVarString
		#undef GetPVarString
	#else
		#define _ALS_GetPVarString
	#endif
	#define GetPVarString( FIXES_GetPVarString(
#endif

/**
 * <fixes>GetSVarString</fixes>
 */

#if !FIX_const
	#if defined _ALS_GetSVarString
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
		len = GetSVarString(varname, string_return, len);
		static i; i = -1;
		do {} while ((string_return[++i] &= 0xFF) != '\0');
		return len;
	}

	#if defined _ALS_GetSVarString
		#undef GetSVarString
	#else
		#define _ALS_GetSVarString
	#endif
	#define GetSVarString( FIXES_GetSVarString(
#endif

/**
 * <fixes>toupper</fixes>
 */

#if defined _ALS_toupper
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

	#define _ALS_toupper
	#define toupper( FIXES_toupper(
#endif

/**
 * <fixes>tolower</fixes>
 */

#if defined _ALS_tolower
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

	#define _ALS_tolower
	#define tolower( FIXES_tolower(
#endif

/**
 * <fixes>ispacked</fixes>
 */

#if defined _ALS_ispacked
	#error _ALS_ispacked defined
#endif
native bool:BAD_ispacked(const string[]) = ispacked;

/**
 * <fixes>ispacked</fixes>
 */

#if FIX_ispacked
	stock bool:FIXES_ispacked(const string[])
	{
		return (string[0] & ~0xFF) != 0;
	}

	#define _ALS_ispacked
	#define ispacked( FIXES_ispacked(
#endif

/**
 * <fixes>GetPlayerPoolSize</fixes>
 */

#if defined _ALS_GetPlayerPoolSize
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
			size = GetPlayerPoolSize();
		return size == 0 && !IsPlayerConnected(0) ? -1 : size;
	}

	#define _ALS_GetPlayerPoolSize
	#define GetPlayerPoolSize( FIXES_GetPlayerPoolSize(
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

#if defined _ALS_SetPlayerPos
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
			ret = SetPlayerPos(playerid, x, y, z);
		if (ret)
		{
			_FIXES_RemoveFlyingParachute(playerid);
		}
		return ret;
	}

	#define _ALS_SetPlayerPos
	#define SetPlayerPos( FIXES_SetPlayerPos(
#endif

/**
 * <fixes>SetPlayerPos</fixes>
 */

#if defined _ALS_SetPlayerPosFindZ
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
			ret = SetPlayerPosFindZ(playerid, x, y, z);
		if (ret)
		{
			_FIXES_RemoveFlyingParachute(playerid);
		}
		return ret;
	}

	#define _ALS_SetPlayerPosFindZ
	#define SetPlayerPosFindZ( FIXES_SetPlayerPosFindZ(
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
			switch (GetPlayerAnimationIndex(playerid))
		#endif
			{
				case 958, 959, 960, 961, 962, 1134:
				{
					new
						slot,
						weapons[_FIXES_WEAPON_SLOTS][2];
					for (slot = 0; slot < sizeof(weapons); slot++)
					{
						GetPlayerWeaponData(playerid, slot, weapons[slot][0], weapons[slot][1]);
					}
					weapons[11][0] = 0;
					ResetPlayerWeapons(playerid);
					for (slot = 0; slot < sizeof(weapons); slot++)
					{
						GivePlayerWeapon(playerid, weapons[slot][0], weapons[slot][1]);
					}
				}
			}
	}
#endif
/**
 * <fixes>GetPlayerAmmo</fixes>
 */

#if defined _ALS_SetPlayerAmmo
	#error _ALS_SetPlayerAmmo defined
#endif
native BAD_SetPlayerAmmo(playerid, weaponid, ammo) = SetPlayerAmmo;
/**
 * <fixes>GetPlayerAmmo</fixes>
 */

#if FIX_GetPlayerAmmo
	stock FIXES_SetPlayerAmmo(playerid, weaponid, ammo)
	{
		if (ammo > 32767)
		{
			ammo = 32767;
		}
		else if (ammo < 0)
		{
			ammo = 0;
		}
		return SetPlayerAmmo(playerid, weaponid, ammo);
	}

	#define _ALS_SetPlayerAmmo
	#define SetPlayerAmmo( FIXES_SetPlayerAmmo(
#endif

/*
 * _FIXES_Bernstein()
 *
 * Convert a string to a number (hash it).
 *
 * FIXES:
 *    ChangeVehicleColor
 *    GetServerVarAsString
 *    GetServerVarAsBool
 *    GetServerVarAsInt
 */

static stock _FIXES_Bernstein(const name[])
{
	new
		i = -1,
		ch,
		hash = -1;
	// In carcols.dat the vehicle names end at ",".  That makes this code
	// very specific to a few use-cases.  It also works for hashing server vars,
	// since they don't have commas.  Now case-insensitive.
	while ((ch = name[++i]) >= '0')
	{
		hash = (hash * 33) + (ch | 0x20);
	}
	return hash;
}

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if defined _ALS_GetPlayerWeather
	#error _ALS_GetPlayerWeather defined
#endif

#if FIX_GetPlayerWeather
	stock FIXES_GetPlayerWeather(playerid)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS) && !(FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_CLOCK_ENABLED))
		{
			return FIXES_GET(PlayerWeather, playerid);
		}
		return -1;
	}

	#define _ALS_GetPlayerWeather
	#define GetPlayerWeather( FIXES_GetPlayerWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if defined _ALS_SetPlayerWeather
	#error _ALS_SetPlayerWeather defined
#endif
native BAD_SetPlayerWeather(playerid, weather) = SetPlayerWeather;

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if FIX_GetPlayerWeather
	stock FIXES_SetPlayerWeather(playerid, weather)
	{
		if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
		{
			FIXES_SET(PlayerWeather, playerid, weather);
			return SetPlayerWeather(playerid, weather);
		}
		return 0;
	}

	#if defined _ALS_SetPlayerWeather
		#undef SetPlayerWeather
	#else
		#define _ALS_SetPlayerWeather
	#endif
	#define SetPlayerWeather( FIXES_SetPlayerWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if defined _ALS_TogglePlayerClock
	#error _ALS_TogglePlayerClock defined
#endif
native BAD_TogglePlayerClock(playerid, toggle) = TogglePlayerClock;

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if FIX_GetPlayerWeather
	#if FIXES_Single
		stock FIXES_TogglePlayerClock(playerid, toggle)
		{
			if (TogglePlayerClock(playerid, toggle))
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
			if (_FIXES_IN_RANGE(playerid, 0, MAX_PLAYERS))
			{
				return
					CallRemoteFunction(FIXES_gscTogglePlayerControl, FIXES_gscSpec@ii, playerid, toggle),
					getproperty(5, FIXES_gscReturnProperty);
			}
			return 0;
		}

		public _FIXES_TogglePlayerClock(playerid, toggle)
		{
			_FIXES_IS_IN_CHARGE()
			{
				if (toggle)
				{
					FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_CLOCK_ENABLED;
				}
				else
				{
					FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_CLOCK_ENABLED;
				}
				setproperty(5, FIXES_gscReturnProperty, TogglePlayerClock(playerid, toggle));
			}
		}
	#endif

	#if defined _ALS_TogglePlayerClock
		#undef TogglePlayerClock
	#else
		#define _ALS_TogglePlayerClock
	#endif
	#define TogglePlayerClock( FIXES_TogglePlayerClock(
#endif

/**
 * <fixes>GetWeather</fixes>
 */

#if defined _ALS_GetWeather
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
				CallRemoteFunction(FIXES_gscGetWeather, FIXES_gscSpec@),
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

	#define _ALS_GetWeather
	#define GetWeather( FIXES_GetWeather(
#endif

/**
 * <fixes>GetPlayerWeather</fixes>
 */

#if defined _ALS_SetWeather
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
		return SetWeather(weather);
	}

	#if defined _ALS_SetWeather
		#undef SetWeather
	#else
		#define _ALS_SetWeather
	#endif
	#define SetWeather( FIXES_SetWeather(
#endif

/**
 * <fixes>GetWorldTime</fixes>
 */

#if defined _ALS_SetWorldTime
	#error _ALS_SetWorldTime defined
#endif
native BAD_SetWorldTime(hour) = SetWorldTime;

/**
 * <fixes>GetWorldTime</fixes>
 */

#if FIX_GetWorldTime
	stock FIXES_SetWorldTime(hour)
	{
		FIXES_gsWorldTime = hour;
		return SetWorldTime(hour);
	}

	#if defined _ALS_SetWorldTime
		#undef SetWorldTime
	#else
		#define _ALS_SetWorldTime
	#endif
	#define SetWorldTime( FIXES_SetWorldTime(
#endif

/**
 * <fixes>GetWorldTime</fixes>
 */

#if defined _ALS_GetWorldTime
	#error _ALS_GetWorldTime defined
#endif

#if FIX_GetWorldTime
	stock FIXES_GetWorldTime()
	{
		return FIXES_gsWorldTime;
	}

	#define _ALS_GetWorldTime
	#define GetWorldTime( FIXES_GetWorldTime(
#endif

/**
 * <fixes>GetServerVarAsString</fixes>
 */
#if defined _ALS_GetServerVarAsString
	#error _ALS_GetServerVarAsString defined
#endif
native BAD_GetServerVarAsString(const varname[], buffer[], len) = GetServerVarAsString;

/**
 * <fixes>GetServerVarAsString</fixes>
 */
#if FIX_GetServerVarAsString || FIX_GetServerVarAsFloat || FIX_GetServerVarAsInt || FIX_GetServerVarAsBool
	stock bool:FIXES_GetServerVarAsString(const varname[], buffer[], len = sizeof (buffer))
	{
		buffer[0] = '\0';
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0x191078CE, // gamemode0
		     0x191078CF, // gamemode1
		     0x191078D0, // gamemode2
		     0x191078D1, // gamemode3
		     0x191078D2, // gamemode4
		     0x191078D3, // gamemode5
		     0x191078D4, // gamemode6
		     0x191078D5, // gamemode7
		     0x191078D6, // gamemode8
		     0x191078D7, // gamemode9
		     0x3B1F92DF, // gamemode10
		     0x3B1F92E0, // gamemode11
		     0x3B1F92E1, // gamemode12
		     0x3B1F92E2, // gamemode13
		     0x3B1F92E3, // gamemode14
		     0x3B1F92E4, // gamemode15
		     0xDD087136, // worldtime
		     0x82FEFA05, // version
		     0x77143DA2, // lagcomp
		     0xAB471B39, // logtimeformat
		     0xBBB6B44D, // nosign
		     0xC5A55EC1, // plugins
		     0x3E60E28D, // filterscripts
		     0x81757563, // gamemodetext
		     0xCEC61D0F, // weather
		     0x1D768025, // gravity
		     0x715D9343, // rcon_password
		     0xCFF70EF0, // weburl
		     0xC4B7237E, // mapname
		     0x6A3B86C3, // language
		     0xFB74B99E, // hostname
		     0x27C72132, // password
		     0x002571DC: // bind
			return bool:GetServerVarAsString(varname, buffer, len);
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

#if FIX_GetServerVarAsString
	#define _ALS_GetServerVarAsString
	#define GetServerVarAsString( FIXES_GetServerVarAsString(
#endif

/**
 * <fixes>GetServerVarAsInt</fixes>
 */
#if defined _ALS_GetServerVarAsInt
	#error _ALS_GetServerVarAsInt defined
#endif
native BAD_GetServerVarAsInt(const varname[]) = GetServerVarAsInt;

/**
 * <fixes>GetServerVarAsInt</fixes>
 */
#if FIX_GetServerVarAsInt
	stock FIXES_GetServerVarAsInt(const varname[])
	{
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0x2CAD71B6, // cookielogging
		     0x779863BF, // concookies
		     0x05E98D75, // db_log_queries
		     0x002E1E91, // db_logging
		     0xD24E879F, // conseedtime
		     0x65E02253, // lagcompmode
		     0xBA15F385, // minconnectiontime
		     0xB4A6E9E0, // playertimeout
		     0xE0BF17AC, // ackslimit
		     0xAF759823, // messageslimit
		     0xD6D5A0EB, // messageholelimit
		     0xA32CD2AF, // chatlogging
		     0x3C9BE967, // weapon_rate
		     0xBD571922, // incar_rate
		     0x9EC6E5F3, // onfoot_rate
		     0xBD480020, // maxnpc
		     0x3E1BBFD6, // sleep
		     0x4D50EBEB, // stream_rate
		     0xBB2D5AE6: // maxplayers
			return GetServerVarAsInt(varname);
		default:
			return 0;
		}
		new
			buffer[16];
		if (FIXES_GetServerVarAsString(varname, buffer, sizeof (buffer)))
			return strval(buffer);
		return 0;
	}

	#define _ALS_GetServerVarAsInt
	#define GetServerVarAsInt( FIXES_GetServerVarAsInt(
#endif

/**
 * <fixes>GetServerVarAsBool</fixes>
 */
#if defined _ALS_GetServerVarAsBool
	#error _ALS_GetServerVarAsBool defined
#endif
native BAD_GetServerVarAsBool(const varname[]) = GetServerVarAsBool;

/**
 * <fixes>GetServerVarAsBool</fixes>
 */
#if FIX_GetServerVarAsBool
	stock bool:FIXES_GetServerVarAsBool(const varname[])
	{
		if (!FIXES_gsServerCFG) switch (_FIXES_Bernstein(varname))
		{
		case 0x4D532D94, // announce
		     0xC99B1697, // lanmode
		     0xAEF7F19F, // query
		     0xB86708E6, // rcon
		     0x0608CD58, // logqueries
		     0xD1E9B9B6, // timestamp
		     0x0C5ACC88: // myriad
			return bool:GetServerVarAsBool(varname);
		default:
			return false;
		}
		new
			buffer[16];
		if (FIXES_GetServerVarAsString(varname, buffer, sizeof (buffer)))
			return strval(buffer) != 0;
		return false;
	}

	#define _ALS_GetServerVarAsBool
	#define GetServerVarAsBool( FIXES_GetServerVarAsBool(
#endif

/**
 * <fixes>GetServerVarAsFloat</fixes>
 */
#if defined _ALS_GetServerVarAsFloat
	#error _ALS_GetServerVarAsFloat defined
#endif
#if defined GetServerVarAsFloat
	native BAD_GetServerVarAsFloat(const varname[]) = GetServerVarAsFloat;
#endif

/**
 * <fixes>GetServerVarAsFloat</fixes>
 */
#if FIX_GetServerVarAsFloat
	stock Float:FIXES_GetServerVarAsFloat(const varname[])
	{
		if (!FIXES_gsServerCFG) // 0x03A253F3 = stream_distance.
			return 0.0;
		new
			buffer[16];
		if (FIXES_GetServerVarAsString(varname, buffer, sizeof (buffer)))
			return floatstr(buffer);
		return 0.0;
	}

	#define _ALS_GetServerVarAsFloat
	#define GetServerVarAsFloat( FIXES_GetServerVarAsFloat(
#endif

/**
 * <remarks>
 * Modify a constant reference.
 * </remarks>
 */

static stock _FIXES_ConstMod(const &target, chr)
{
	#pragma unused target, chr
	#emit LOAD.S.pri chr
	#emit SREF.S.pri target
}

/**
 * <remarks>
 * Removes whitespace from the right side of a string.  Modifies <c>const</c>
 * strings to make it appear that nothing changes, so needs some tricky playing
 * to make it work.
 * </remarks>
 */

static stock _FIXES_rtrim(const string[])
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

static stock _FIXES_untrim(const string[])
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

#undef _FIXES_CEILDIV
#undef _FIXES_INFINITY
#undef _FIXES_N_INFINITY
#undef _FIXES_MIN_WORLDBOUNDS
#undef _FIXES_MAX_WORLDBOUNDS
#undef _FIXES_ATTACHMENTS
#undef _FIXES_FOREACH
#undef _FIXES_IS_UNSET
#undef _FIXES_IS_IN_CHARGE
#undef _FIXES_IN_RANGE
#undef _FIXES_NO_RANGE
#undef _FIXES_FORWARD
#undef _FIXES_IS_PLAYER_CONNECTED
#undef _FIXES_ENUM
#undef FIXES_PRINTF

#endinput

// Fix documentation template.

/**
 * <fix name="" disabled="true" fixed="">
 *     <problem>
 *         problem
 *     </problem>
 *     <solution>
 *         solution
 *     </solution>
 *     <see></see>
 *     <author    href=""></author>
 *     <post      href="" />
 * </fix>
 */

// Fix inclusion template.

#if !defined FIX_NameOfFixHere
	#define FIX_NameOfFixHere            (1)
#elseif _FIXES_IS_UNSET(FIX_NameOfFixHere)
	#undef FIX_NameOfFixHere
	#define FIX_NameOfFixHere            (2)
#endif

// Fix function template.

/**
 * <remarks>Information about fix here</remarks>
 * <fixes>NameOfFixHere</fixes>
 */

#if defined _ALS_NameOfFixHere
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

	#define _ALS_NameOfFixHere
	#define NameOfFixHere( FIXES_NameOfFixHere(
#endif
