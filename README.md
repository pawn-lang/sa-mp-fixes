
# fixes.inc

### Community patches for buggy SA:MP functions.

## Introduction

SA:MP is beta software written by a small team in their spare time, thus it has bugs (as does all software). Some of these have been known for a long time but are low priority due to their minor effects, others go undiscovered for a long time. Many of these bugs have solutions which can be implemented in PAWN (and this may be simpler than implementing them in the SA:MP source code). This include aims to collect fixes for as many of these bugs as possible from the community (i.e. anyone who has a fix) together in to one easy to use place for everyone's benefit.

## Use

This library is a single-file include.  The only required part is:

https://raw.githubusercontent.com/pawn-lang/sa-mp-fixes/master/fixes.inc

Save this file as `pawno/include/fixes.inc` then include it after the default SA:MP functions, but before third party includes:

```pawn
#include <a_samp>
// Any default re-definitions should go here.
//#undef MAX_PLAYERS
//#define MAX_PLAYERS 10
#include <fixes>

#include <other>
```

To disable any fix for whatever reason simply do:

```pawn
#define FIX_<name> 0
```

For example, to disable all the file.inc fixes if you always correctly check the file handle, do:

```pawn
#include <a_samp>
#define FIX_file_inc 0
#include <fixes>
#include <other>
```

All the names of the fixes are single words, and are all listed with their fix descriptions below.

If you only have one script running on your server (i.e. no FilterScripts), you can use this define to improve the fixes.inc code:

```pawn
#include <a_samp>
#define FIXES_Single 1
#include <fixes>
#include <other>
```

See below for more configuration settings.

If you use sampctl the inclusion path to go under dependencies is:

```
"pawn-lang/sa-mp-fixes"
```

You can also download the entire repo using *git*, and will get a more complete experience, including better warnings and this documentation.

## Fix Options

Name | Problem | Solution | Author(s) | Post(s) | Notes
---- | ---- | ---- | ---- | ---- | ----
GetPlayerColor | Returns "0" if "SetPlayerColor" has never been called. | Call "SetPlayerColor" in "OnPlayerConnect". | KoczkaHUN | |
FILTERSCRIPT | Despite the fact that is in every new script, many people dont' define "FILTERSCRIPT" where appropriate. | Provide an "IS_FILTERSCRIPT" variable (note the naming to match the original macro). | [Y_Less](https://github.com/Y-Less/) | |
SpawnPlayer | Kills the player if they are in a vehicle. | Remove player from the vehicle. | [Y_Less](https://github.com/Y-Less/) | |
SetPlayerName | Using "SetPlayerName" when the new name only differs from the old name in case does not alter the name at all. | Change their name twice - once to "_FIXES TEMP NAME" and then to the actual required name. | [Y_Less](https://github.com/Y-Less/) [Slice](https://github.com/oscar-broman/) [simonepri](https://github.com/simonepri/) | |
GetPlayerSkin | Returns the new skin after "SetSpawnInfo" is called but before the player actually respawns to get the new skin. | Record the skin in "OnPlayerSpawn" and always return that one. | [Y_Less](https://github.com/Y-Less/) | |
GetWeaponName | Returns nothing for 18, 44, and 45. | Return the correct names (`Molotov Cocktail`, `Thermal Goggles`, and `Night vision Goggles`). | [Y_Less](https://github.com/Y-Less/) | | **Fixed in 0.3.7**
SetPlayerWorldBounds | Aiming can bypass the edge. | Check for the player leaving the area and reset them to their last good position if they leave the area (aiming or not). | [Y_Less](https://github.com/Y-Less/) | |
TogglePlayerControllable | Other players see you moving on the spot. | Return 0 in OnPlayerUpdate. | [Slice](https://github.com/oscar-broman/) | [Link](https://sampforum.blast.hk/showthread.php?tid=184118&pid=876854#pid876854) |
HydraSniper | Entering military aircraft with a sniper rifle messes up views. | Set their armed weapon to fists. | funky1234 | [Link](https://sampforum.blast.hk/showthread.php?tid=151670&pid=965644#pid965644) |
IsPlayerInCheckpoint | Function returns an undefined value if it is called before any other checkpoint functions are called to initialise the value. | Call "DisablePlayerCheckpoint" when they connect. | [Y_Less](https://github.com/Y-Less/) | |
IsPlayerInRaceCheckpoint | Function returns an undefined value if it is called before any other race checkpoint functions are called to initialise the value. | Call "DisablePlayerRaceCheckpoint" when they connect. | [Y_Less](https://github.com/Y-Less/) | |
GetPlayerWeapon | Returns the old value after entering in a vehicle. | If "SetPlayerArmedWeapon" and other similar functions is called in a vehicle, store the new value and return that instead. | [Y_Less](https://github.com/Y-Less/) [ronixtey](https://github.com/ronixtey/) | |
PutPlayerInVehicle | If this is used on a passenger the driver of their old vehicle doesn't see them in their new vehicle. | Remove them from the vehicle first. | leong124 [Y_Less](https://github.com/Y-Less/) | [Link](http://web-old.archive.org/web/20190415184628/https://forum.sa-mp.com/showpost.php?p=1265965) |
KEY_AIM | "KEY_AIM" isn't defined by default. | Define it. | [Y_Less](https://github.com/Y-Less/) | |
SetPlayerCheckpoint | If a checkpoint is already set it will use the size of that checkpoint instead of the new one. | Call "DisablePlayerCheckpoint" before setting the checkpoint. | [ziggi](https://github.com/ziggi/) | |
SetPlayerRaceCheckpoint | If a checkpoint is already set it will use the size of that checkpoint instead of the new one. | Call "DisablePlayerRaceCheckpoint" before setting the checkpoint. | [ziggi](https://github.com/ziggi/) | |
TextDrawCreate | Crashes on a blank string. | Intercept blank strings. | wups | |
TextDrawCreate_2 | If the last character in the text is a space (" "), the text will all be blank. | Remove space characters from the end of the string. | [ziggi](https://github.com/ziggi/) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/55) |
TextDrawSetString | Crashes on a blank string and size greater than 1024. | Intercept blank strings and truncate long strings. | TomTrox | |
TextDrawSetString_2 | If the last character in the text is a space (" "), the text will all be blank. | Remove space characters from the end of the string. | [ziggi](https://github.com/ziggi/) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/55) |
CreatePlayerTextDraw | Crashes on a blank string. | Intercept blank strings. | wups [Y_Less](https://github.com/Y-Less/) | |
CreatePlayerTextDraw_2 | If the last character in the text is a space (" "), the text will all be blank. | Remove space characters from the end of the string. | [ziggi](https://github.com/ziggi/) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/55) |
PlayerTextDrawSetString | Crashes on a blank string and size greater than 1024. | Intercept blank strings and truncate long strings. | TomTrox [Y_Less](https://github.com/Y-Less/) | |
PlayerTextDrawSetString_2 | If the last character in the text is a space (" "), the text will all be blank. | Remove space characters from the end of the string. | [ziggi](https://github.com/ziggi/) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/55) |
AllowInteriorWeapons | Does nothing. | Set the player's weapon to fists in an interior. | KoczkaHUN | |
OnPlayerEnterVehicle | Crashes other players when people enter an invalid seat. | Desync the people with invalid seats. | RyDeR` [Y_Less](https://github.com/Y-Less/) | [Link](http://web-old.archive.org/web/20190415184630/https://forum.sa-mp.com/showpost.php?p=1410296) |
OnPlayerEnterVehicle_2 | Crashes the server when hacks enter an invalid vehicle. | Desync the people with invalid vehicles. | [Y_Less](https://github.com/Y-Less/) | |
OnPlayerEnterVehicle_3 | No player animation when trying to enter the driver door of a locked vehicle | Leave the door unlocked and activate an animation when the player attemps to enter a 'locked' vehicle. | [ziggi](https://github.com/ziggi) [rt-2](https://github.com/rt-2) | [Link](https://sampforum.blast.hk/showthread.php?tid=127762&pid=560019#pid560019) |
AllowTeleport | 0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in favour of "OnPlayerClickMap". Some scripts used the old code and. | Teleport the player in "OnPlayerClickMap". | [Y_Less](https://github.com/Y-Less/) | |
SetPlayerSpecialAction | Removing jetpacks from players by setting their special action to 0 causes the sound to stay until death. | Call "ClearAnimations" before "SetPlayerSpecialAction". | MP2 | |
OnDialogResponse | Cheaters can spoof the dialogid they are using to respond to ones they can't actually see. | Store the displayed dialogid and use that instead. | [Y_Less](https://github.com/Y-Less/) | | **Fixed in 0.3e RC6**
GetPlayerDialog | This function doesn't exist. Fixed for hidden dialogs. | Add it. | [Y_Less](https://github.com/Y-Less/) [simonepri](https://github.com/simonepri/) | | **Disabled By Default**
PlayerDialogResponse | A player's dialog doesn't hide when the gamemode restarts, causing the server to print "Warning: PlayerDialogResponse PlayerId: 0 dialog ID doesn't match last sent dialog ID". | Hide it. | [simonepri](https://github.com/simonepri/) | |
SetSpawnInfo | Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo". | Call "SetSpawnInfo" at least once. | [Y_Less](https://github.com/Y-Less/) | |
SetPlayerSkin | Breaks sitting on bikes. | Put them back in the vehicle after setting their skin. | CyNiC | [Link](http://web-old.archive.org/web/20190415184621/https://forum.sa-mp.com/showpost.php?p=1756094) |
HideMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | [Link](https://sampforum.blast.hk/showthread.php?tid=332944&pid=1787297#pid1787297) |
valstr | Crashes on large numbers. | Use "format" instead. | [Slice](https://github.com/oscar-broman/) | |
fclose | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fwrite | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fread | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fputchar | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fgetchar | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fblockwrite | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fblockread | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
fseek | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
flength | Crashes on an invalid handle. | Check for an invalid handle. | [Slice](https://github.com/oscar-broman/) | |
file_inc | Includes or excludes all the file function fixes together (can cause major overhead). | Optionally group them all under one define. | [Y_Less](https://github.com/Y-Less/) | | **Disabled By Default**
SetPlayerAttachedObject | Doesn't remove objects when the mode ends. | Remove them. | [Y_Less](https://github.com/Y-Less/) | |
OnPlayerDeath | Clients get stuck when they die with an animation applied. | Clear their animations. | h02 | [Link](https://sampforum.blast.hk/showthread.php?tid=312862&pid=1641144#pid1641144) |
strins | Ignores the "maxlength" parameter causing possible crashes. | Manually check the length. | [Slice](https://github.com/oscar-broman/) [Y_Less](https://github.com/Y-Less) | |
IsPlayerConnected | Only uses the lower two bytes of a passed ID. | Mask the numbers. | [Slice](https://github.com/oscar-broman/) | |
TrainExit | When getting out of a train entered by "PutPlayerInVehicle", the camera does not reset properly. | Reset the camera. | Terminator3 [Y_Less](https://github.com/Y-Less/) | |
Kick | Calling "Kick" in "OnPlayerConnect" doesn't work properly. | Defer it. | [Y_Less](https://github.com/Y-Less/) | [Link](http://web-old.archive.org/web/20190415184620/https://forum.sa-mp.com/showpost.php?p=1989453) | **Fixed in 0.3x**
OnVehicleMod | Crashes other players when invalid mods are applied. | Desync the player. | [JernejL](https://github.com/JernejL/) [Y_Less](https://github.com/Y-Less/) | [Link](https://sampforum.blast.hk/showthread.php?tid=317303&pid=1671500#pid1671500) |
random | Doesn't work with negative numbers. | Invert then reinvert. | [simonepri](https://github.com/simonepri/) | | **Disabled By Default**
sleep | Leaks bytes from the stack. | Call a function to store the correct value. | [Y_Less](https://github.com/Y-Less/) | |
AddMenuItem | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | |
SetMenuColumnHeader | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | |
ShowMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | |
HideMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | [Link](https://sampforum.blast.hk/showthread.php?tid=332944&pid=1787297#pid1787297) |
HideMenuForPlayer_2 | Ignores the "menuid" parameter. | Only hide the correct menu. | [Y_Less](https://github.com/Y-Less/) | | **Disabled By Default**
DisableMenu | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | |
DisableMenuRow | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | |
Menus | All menu function fixes are included separately for major overhead. | Optionally group them all under one define. | [Y_Less](https://github.com/Y-Less/) | |
GetPlayerMenu | Returns previous menu when none is displayed. | Return the correct value. | [Y_Less](https://github.com/Y-Less/) | |
GetPlayerInterior | Always returns 0 for NPCs. | Return the correct value. | [Y_Less](https://github.com/Y-Less/) [simonepri](https://github.com/simonepri/) | |
ClearAnimations | Use ClearAnimation while you are in a vehicle cause the player exit from it. | Apply an animation instead of clear animation. | [simonepri](https://github.com/simonepri/) | |
ClearAnimations_2 | ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in ApplyAnimation. | Apply an idle animation for stop and then use ClearAnimation. | [simonepri](https://github.com/simonepri/) | |
DriveBy | If you press KEY_CROUCH while you're passenger and if you are armed, the player start to aim; if you repress KEY_CROUCH the player don't return in vehicle. | Apply the animation to return the player in the vehicle. | [simonepri](https://github.com/simonepri/) | |
SilentTeleport | If a vehicle teleports either by SetVehiclePos or enters an original samp interior if someone tries to enter it he will teleport silently along. | Using 'ClearAnimation' to stop the player before the teleport happens. | [RogueDrifter](https://github.com/RogueDrifter/) | [Link](https://sampforum.blast.hk/showthread.php?tid=650422) |
GangZoneCreate | Gang zones bug on the main map for players at certain angles relative to them. | Set a non floating value for the gang zone co-ordinate. | [simonepri](https://github.com/simonepri/) [Y_Less](https://github.com/Y-Less/) | |
SPECIAL_ACTION_PISSING | "SPECIAL_ACTION_PISSING" isn't defined by default. | Define it. | [simonepri](https://github.com/simonepri/) | |
IsValidVehicle | "IsValidVehicle" isn't defined by default. | Define it. | [simonepri](https://github.com/simonepri/) | |
ApplyAnimation | Passing an invalid animation library in ApplyAnimation causes a client crash for streamed in players. | Block ApplyAnimation when an invalid library is passed. | [simonepri](https://github.com/simonepri/) | |
ApplyAnimation_2 | First time a library is used, it does nothing. | Apply animations twice when first using a library. | [simonepri](https://github.com/simonepri/) [Lordzy](https://github.com/Lordzy/) [Y_Less](https://github.com/Y-Less/) | |
ApplyActorAnimation | Passing an invalid animation library in ApplyAnimation causes a client crash for streamed in players. | Block ApplyActorAnimation when an invalid library is passed. | [simonepri](https://github.com/simonepri/) [ziggi](https://github.com/ziggi/) | |
ApplyActorAnimation_2 | First time a library is used, it does nothing. | Apply animations twice when first using a library. | [simonepri](https://github.com/simonepri/) [Lordzy](https://github.com/Lordzy/) [Y_Less](https://github.com/Y-Less/) [ziggi](https://github.com/ziggi/) | |
OnPlayerSpawn | San Andreas deducts $100 from players. | Give them it back. | [Y_Less](https://github.com/Y-Less/) | |
GetGravity | "GetGravity" isn't defined by default. | Define it. | [Whitetiger](https://github.com/Whitetigerswt) | [Link](http://web-old.archive.org/web/20190415184625/https://forum.sa-mp.com/showpost.php?p=1706447) |
gpci | "gpci" isn't defined by default. | Define it. | [simonepri](https://github.com/simonepri/) | [Link](http://pastebin.com/VQSGpbSm) |
Natives | Several natives are included by default, this enables or disables them all. Therefore this is an umbrella fix for several fixes. | Define them. | [Y_Less](https://github.com/Y-Less/) | |
OnPlayerConnect | This function isn't called for players when a filterscript starts. | Call it for all connected players. | [Y_Less](https://github.com/Y-Less/) | |
OnPlayerDisconnect | This function isn't called for players when a filterscript ends. | Call it for all connected players. | [Y_Less](https://github.com/Y-Less/) | |
GameText | Several styles do not display for the time specified. | Recreate the styles in Text Draws and use those instead. | [Y_Less](https://github.com/Y-Less/) | |
GameTextStyles | San Andreas has fixed styles for area and vehicle names, but they are not included in the GameText styles list. | Add them. | [Y_Less](https://github.com/Y-Less/) | | **Disabled By Default**
HideGameText | There is no "HideGameTextForXYZ" function. | Show a single space for a game text. | [Y_Less](https://github.com/Y-Less/) | |
ClearPlayerWorldBounds | There is no "ClearPlayerWorldBounds" function. | Put the world bounds back to the default. | [Y_Less](https://github.com/Y-Less/) | |
GetPlayerWorldBounds | There is no "GetPlayerWorldBounds" function. | Store them and retrieve them. | [Y_Less](https://github.com/Y-Less/) | |
WEAPONS | Some weapons are not defined by default. | Define it. | [ziggi](https://github.com/ziggi) | |
BODYPARTS | The bodyparts to be used in OnPlayer(Take/Give)Damage are not defined by default | Define it. | [Whitetiger](https://github.com/Whitetigerswt) | |
CAMERAMODES | The camera modes for GetPlayerCameraMode are not defined by default. | Define it. | [Whitetiger](https://github.com/Whitetigerswt) | [Link](https://sampforum.blast.hk/showthread.php?tid=271586&pid=1309730#pid1309730) |
SetPlayerCamera | Using the camera functions directly after enabling spectator mode doesn't work. | Defer them. | [Emmet_](https://github.com/emmet-jones) | |
SetPlayerTime | Using this function under "OnPlayerConnect" doesn't work. | Defer it. | [Emmet_](https://github.com/emmet-jones) | |
OnPlayerRequestClass | Random blunts and bottles sometimes appear in class selection. | Call "RemoveBuildingForPlayer". | [Y_Less](https://github.com/Y-Less/) | |
SetPlayerColor | If used under OnPlayerConnect, the affecting player will not see the color in the TAB menu. | Defer it. | [Emmet_](https://github.com/emmet-jones) | [Link](https://sampforum.blast.hk/showthread.php?tid=452407) |
FileMaths | You can write gibberish like "File:a; ++a;". | Remove the operators. | [Y_Less](https://github.com/Y-Less/) | |
GetPlayerWeaponData | Old weapons with no ammo left are still returned. | Set "weapons" to 0. | [Y_Less](https://github.com/Y-Less/) | [Link](https://sampforum.blast.hk/showthread.php?tid=567400) |
strcmp | Return 0 if anyone of the string is empty. | Add a check for empty string. | [Y_Less](https://github.com/Y-Less) | |
GetPVarString | Wrong symbol code for symbols with code 128 and above. | Use logical conjunction on symbol and 0xFF. | [ziggi](https://github.com/ziggi) [MuthaX](https://github.com/MuthaX) [Daniel_Cortez](https://github.com/Daniel-Cortez) | [Link](https://sampforum.blast.hk/showthread.php?tid=572724&page=2) [Link](http://pro-pawn.ru/showthread.php?13007) |
GetSVarString | Wrong symbol code for symbols with code 128 and above. | Use logical conjunction on symbol and 0xFF. | [ziggi](https://github.com/ziggi) [MuthaX](https://github.com/MuthaX) [Daniel_Cortez](https://github.com/Daniel-Cortez) | [Link](https://sampforum.blast.hk/showthread.php?tid=572724&page=2) [Link](http://pro-pawn.ru/showthread.php?13007) |
toupper | Not working on Linux for symbols with code 128 and above. | Recreate the function. | [ziggi](https://github.com/ziggi) | [Link](http://pro-pawn.ru/showthread.php?13466&p=72954#post72954) |
tolower | Not working on Linux for symbols with code 128 and above. | Recreate the function. | [ziggi](https://github.com/ziggi) | [Link](http://pro-pawn.ru/showthread.php?13466&p=72954#post72954) |
PassengerSeating | Teleporting player to passenger seat after delay. | Call ClearAnimation after some delay. | [ziggi](https://github.com/ziggi) | |
GogglesSync | Visual effects show for all players. | return 0 in OnPlayerUpdate after key pressed. | [ziggi](https://github.com/ziggi) | |
GetPlayerPoolSize | Returns "0" even if there are no players on the server. | Return "-1" if PlayerPoolsize is 0 but Player 0 is not connected. | [Bios-Marcel](https://github.com/Bios-Marcel) | |
SetPlayerPos | Using this function on skydiving players kills them. | Remove the parachute when the player is skydiving. | [Freaksken](https://github.com/WoutProvost) | |
GetPlayerAmmo | Returns erroneous values over 32767 and under -32768 due to overflow. | Prevent setting or adding ammo above 32767 and setting or removing ammo below 0. | [Freaksken](https://github.com/WoutProvost) | |
JIT | Can't easily determine if the script is JIT compiled. | Provide "IS_JIT" to the script for tests. | [Y_Less](https://github.com/Y-Less) | |
OS | Can't easily determine what OS the script is running on. | Provide "IS_WINDOWS" and "IS_LINUX" to the script for tests. | [Y_Less](https://github.com/Y-Less) | |
const | Some SA-MP natives don't use "const" when they could. | Redefine the natives. | [Y_Less](https://github.com/Y-Less) | |
VEHICLES | The vehicle models IDs are not defined by default. | Define them. | [stuntman](https://github.com/IstuntmanI) | |
GetPlayerWeather | This function doesn't exist. | Add it. | [IstuntmanI](https://github.com/IstuntmanI/) [ziggi](https://github.com/ziggi/) | | **Disabled By Default**
GetWeather | This function doesn't exist. | Add it. | [IstuntmanI](https://github.com/IstuntmanI/) [ziggi](https://github.com/ziggi/) | | **Disabled By Default**
GetWorldTime | This function doesn't exist. | Add it. | [ziggi](https://github.com/ziggi/) | | **Disabled By Default**
GetServerVarAsString | Crashes on unknown string variables. | Read the file manually. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/73) |
GetServerVarAsInt | Crashes on unknown int variables. | Read the file manually. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/73) |
GetServerVarAsBool | Crashes on unknown boolean variables. | Read the file manually. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/73) |
GetServerVarAsFloat | Doesn't even exist. | Read the file manually. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/Open-GTO/sa-mp-fixes/issues/73) |
tabsize | Some people still use `tabsize 0`. | Break the pragma. | [Y_Less](https://github.com/Y-Less) | [Link](http://forum.sa-mp.com/showpost.php?p=3929000) |
OnRconCommand | Is not called in the gamemode unless first called in a filterscript. | Load a minimal (embedded) FS to bootstrap it. | [Y_Less](https://github.com/Y-Less) | |
OnClientCheckResponse | Is not called in the gamemode ever. | Load a minimal (embedded) FS to bootstrap it. | [Y_Less](https://github.com/Y-Less) | |
GetMaxPlayers | If this is > MAX_PLAYERS, can cause OOBs in code. | Constrain it; but also warn because that doesn't really help. | [Y_Less](https://github.com/Y-Less) | |
BypassDialog | You can type commands and move while in dialogs. | Return 0. | [Y_Less](https://github.com/Y-Less) | |
SetTimer | Valid timers can return ID 0. | Recreate them and kill the original. | [Y_Less](https://github.com/Y-Less) | |
main | Gamemodes without this function give a console error. | Make a stub version. | [Y_Less](https://github.com/Y-Less) | |
OnVehicleSpawn | Colour `-1` isn't synced. | Manually control the colours. | [Y_Less](https://github.com/Y-Less) | |
AttachTrailerToVehicle | When trailerid is equal to vehicleid and passenger is in vehicleid, it starts spinning. | Check if trailerid and vehicleid are equal. | [Mergevos](https://github.com/Mergevos) | |
GetVehicleComponentInSlot | The function doesn't work for CARMODTYPE_STEREO. Both front bull bars and front bumper components are saved in the CARMODTYPE_FRONT_BUMPER slot. If a vehicle has both of them installed, this function will only return the one which was installed last. Both rear bull bars and rear bumper components are saved in the CARMODTYPE_REAR_BUMPER slot. If a vehicle has both of them installed, this function will only return the one which was installed last. | Hook functions and store components. This uses some code from vSync library. | [Mergevos](https://github.com/Mergevos) | |
API | fixes.inc isn't intended to extend the SA:MP API, but has a lot of information internally that can be useful to other scripts.  By not exposing this data, we complicate and bloat scripts by requiring them to re-implement said functionality. | Expose the data, behind a tightly controlled API. | [Y_Less](https://github.com/Y-Less) | |
floatfract | Incorrect on negative numbers. | Use floatround and subtraction. | [MuthaX](https://github.com/MuthaX) | [Link](https://github.com/pawn-lang/sa-mp-fixes/issues/150) |
strfind | The function is prone to OOB access when the search start index is negative. | Clamp it to 0. | [Daniel-Cortez](https://github.com/Daniel-Cortez) | [Link](https://github.com/pawn-lang/sa-mp-fixes/issues/91) |
strdel | The function is prone to OOB access when the index of the first character to remove is negative. | Clamp it to 0. | [Daniel-Cortez](https://github.com/Daniel-Cortez) | [Link](https://github.com/pawn-lang/sa-mp-fixes/issues/91) |
CallLocalFunction | Isn't defined in NPC modes. | Write a pawn version using `funcidx`. | [Y_Less](https://github.com/Y-Less) | |
deconst | Un-const-correct - uses `const` but shouldn't. | Redefine it without, plus a `len` default. | [Y_Less](https://github.com/Y-Less) | |
Streamer_RemoveIntData | Int data functions expect more parameters than they specify. | Pass a hidden fake one if the version is right. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/samp-incognito/samp-streamer-plugin/pull/380) |
Streamer_HasIntData | Int data functions expect more parameters than they specify. | Pass a hidden fake one if the version is right. | [Y_Less](https://github.com/Y-Less) | [Link](https://github.com/samp-incognito/samp-streamer-plugin/pull/380) |
default | Many functions are missing default values for string lengths. | Add them. | [Y_Less](https://github.com/Y-Less) | |
limit_tags | Some limits, like `MAX_MENUS` are untagged, so can't be used properly. | Redefine them with the tags added. | [Y_Less](https://github.com/Y-Less) | |
bool_tags | Many `true/false` parameters use `1/0` with no `bool:` tag. | Add the tag. | [Y_Less](https://github.com/Y-Less) | |
TEXT_DRAW_ALIGN | The alignment modes for `TextDrawAlignment` are not defined by default. | Define them. | [Y_Less](https://github.com/Y-Less) | |
TEXT_DRAW_FONT | The fonts for `TextDrawFont` are not defined by default. | Define them. | [Y_Less](https://github.com/Y-Less) | |
GetPlayerKeys | `GetPlayerKeys` and `OnPlayerKeyStateChange` don't actually deal with "keys", but "actions".  The defines don't correspond to real keyboard inputs, but bound game commands.  This is one of the biggest sources of confusion, even amongst intermediate coders. | Rename the functions to use `Action` instead of `Key` and deprecate the old ones. | [Y_Less](https://github.com/Y-Less) | |
FORCE_SYNC | The sync modes for `ApplyAnimation` are not defined by default. | Define them. | [Y_Less](https://github.com/Y-Less) | |
address_naught | When there are internal code errors that result in the wrong address being written to, more often than not that write clobbers whatever value is in address naught (`0x00000000`). | While we can't stop all the bad address writes there are two things we can do.  Enable the anonymous automata, which is always at address naught, and never use it so that bad writes don't break something else, and enable address naught write detection in crashdetect.  Note that this will have to be disabled if you use the anonymous automata. | [Y_Less](https://github.com/Y-Less) | |
main2 | `main` isn't used in filterscripts. | Call it. | [Y_Less](https://github.com/Y-Less) | |

A few fixes are disabled by default, to enable them all do:

```pawn
#define FIX_GetPlayerDialog 1
#define FIX_file_inc 1
#define FIX_random 1
#define FIX_HideMenuForPlayer_2 1
#define FIX_GameTextStyles 1
#define FIX_GetPlayerWeather 1
#define FIX_GetWeather 1
#define FIX_GetWorldTime 1
```

## Settings

There are a few settings for improved execution of this script. Define these symbols as `1` before you include fixes.inc to explicitly enable them, `0` to explicitly disable them.

* `FIXES_ExplicitSettings`: Require settings to be explicitly enabled or disabled, and show a warning for every setting not mentioned.  Default `0` for now.
* `FIXES_EnableAll`: Enable everything, even things that probably shouldn't be enabled.  Default `0`.
* `FIXES_EnableDeprecated`: Enable all deprecated fixes (those that are no longer needed because they were fixed in later server revisions).  Might causes errors and conflicts with newer SA:MP includes.  Default `0`.
* `FIXES_DefaultDisabled`: Disable all fixes by default, and require them to be individually enabled with `#define FIX_<name> 1`  Default `0`.
* `FIXES_ExplicitOptions`: Require fixes to be explicitly enabled or disabled, and show a warning for every fix not mentioned.  Useful in combination with `FIXES_DefaultDisabled`, so default `1` with that, `0` otherwise.
* `FIXES_SilentKick`: If this define is set to `1`, then players will not be given a message when they are kicked for cheats (mainly invalid vehicles and mods), instead they will just loose connection to the server.  Default `0`.
* `FIXES_Debug`: If this define is set to `1`, then debug printing is turned on for any functions which may use it.  Otherwise, the compiler entirely removes the code to print anything, leaving no run-time overhead.  Default `0`.
* `FIXES_Single`: If this define is set to 1, then the old style include is used, with no support for multiple scripts running at the same time on the server.  You only have one script that uses *fixes.inc* running (no other gamemodes or filterscripts).  Using this define will vastly simplify the code in that case, as no cross-script communication is required, but will cause bugs if there actually is another script running.  Default `1`.
* `FIXES_NoSingleMsg`: Hide a message at mode start if `FIXES_Single` is set, but this is NOT the only script running *fixes.inc*.  This will entirely disable the check, so should only be used if you are absolutely certain that no other scripts are running at the same time (gamemodes or filterscripts).  Default `1`.
* `FIXES_NoServerVarMsg`: If this define is set to `1`, then the server will not give a message when `GetServerVarAsString` and related functions are used without a valid directory redirect.  Default `1`.
* `FIXES_NoGetMaxPlayersMsg`: If this define is set to 1, then the server will not give a message when `GetMaxPlayers` doesn't match `MAX_PLAYERS`. Default `1`.
* `FIXES_NoPawndoc`: If this define is set to `1`, then compiling with `-r` will attempt to hide as many of the functions and variables in fixes.inc from the output XML as possible.  This will vastly simplify the generated documentation (at least the visible parts, this is done by embeddeding XML comments in the output, so all the data still exists, just hidden in the file).  Default `0`.
* `FIXES_CorrectInvalidTimerID`: You know that an invalid timer is ID `0`, not `-1`, so exclude the excess code designed to warn about/detect people using `-1`.  Default `0`.
* `FIXES_NoYSI`: fixes.inc doesn't need YSI.  YSI doesn't need fixes.inc.  However, they are both written to be aware of each other and adapt accordingly.  For example, fixes.inc uses a special type of ALS hooking which y_hooks can detect and use to call these callbacks in a better order (so-called "pre-hooks").  But if you don't have y_hooks the other version of ALS is very fractionally better.  This define can thus be used to guarantee to fixes.inc that YSI doesn't exist and not to use any of the adapted code.  However, if you're wrong the include probably just won't work, the overhead when not using YSI is absolutely tiny, and when using YSI its optimised out.  So, if in doubt - don't use this.  Default `0`.
* `FIXES_OneRandomVehicleColour`: Most vehicles are created with two explicit colours (say `5, 6`) or two random colours (`-1, -1`).  It is allowed, but rare, to create a vehicle with one random colour and one fixed colour (`-1, 5`, `9, -1` etc).  fixes.inc supports this, but it takes a lot more code to fix than the common case of all or nothing.  Thus, having only one random colour is only supported with this explicit setting enabled.  Default `0`.
* `FIXES_NoVehicleColourMsg`: Hide a message at vehicle creation if `FIXES_OneRandomVehicleColour` is set, but a vehicle is created with only one random colour.  Default `0`.
* `FIXES_CountFilterscripts`: Load several filterscripts until one fails, to determine the number of previously loaded filterscripts.  Default `1`.
* `FIXES_NoFilterscriptsMsg`: Hide the message about loading filterscripts and the ignorable errors.  Default `0`.

Note that `options` are which fixes to include, and `settings` are more over-arching customisations.

## Tags

Like the enhanced SA:MP includes (https://github.com/pawn-lang/samp-stdlib/tree/consistency-overhaul)
fixes.inc upgrades many natives and callbacks to use more tags for better compile-time errors.
These can be a little annoying to adapt your code to at first, but in the long run provide far more
safety and information.  Like the SA:MP includes there are `WEAK_TAGS` and `STRONG_TAGS`, but unlike
there the default is none, i.e. most tags will simply be `_:` unless you're using the consistency
overhaul includes as well.  The one major exception to this is `bool:`, which has been added by
default to many parameters which were previously `_:` but only accepted `0`/`1` and thus should have
been `false`/`true`.  This is the `bool_tags` fix and affects the following natives:

* `native SetTimer(const functionName[], interval, bool:repeating);`
* `native SetTimerEx(const functionName[], interval, bool:repeating, const format[] = "", {Float, _}:...);`
* `native AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false);`
* `native ShowNameTags(bool:show);`
* `native EnableTirePopping(bool:enable);`
* `native AllowInteriorWeapons(bool:allow);`
* `native AllowAdminTeleport(bool:allow);`
* `native EnableZoneNames(bool:enable);`
* `native bool:IsPlayerNPC(playerid);`
* `native bool:IsPlayerAdmin(playerid);`
* `native bool:GetServerVarAsBool(const cvar[]);`
* `native bool:GetConsoleVarAsBool(const cvar[]);`
* `native bool:IsValidMenu(Menu:menuid);`
* `native TextDrawUseBox(Text:text, bool:use);`
* `native TextDrawSetProportional(Text:text, bool:set);`
* `native TextDrawSetSelectable(Text:text, bool:set);`
* `native Text3D:Create3DTextLabel(const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, bool:testLOS = false);`
* `native PlayerText3D:CreatePlayer3DTextLabel(playerid, const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, bool:testLOS = false);`
* `native CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, colour1, colour2, respawnDelay, bool:addSiren = false);`
* `native bool:IsVehicleStreamedIn(vehicleid, playerid);`
* `native bool:IsTrailerAttachedToVehicle(vehicleid);`
* `native bool:IsValidVehicle(vehicleid);`
* `native bool:DB_Close(DB:db);`
* `native bool:DB_FreeResult(DBResult:result);`
* `native bool:DB_NextRow(DBResult:result);`
* `native bool:DB_FieldName(DBResult:result, field, output[], size = sizeof (output));`
* `native bool:DB_GetField(DBResult:result, field, output[], size = sizeof (output));`
* `native bool:DB_GetFieldAssoc(DBResult:result, const field[], output[], size = sizeof (output));`
* `native bool:IsActorStreamedIn(actorid, playerid);`
* `native ApplyActorAnimation(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time);`
* `native SetActorInvulnerable(actorid, bool:invulnerable = true);`
* `native bool:IsActorInvulnerable(actorid);`
* `native bool:IsValidActor(actorid);`
* `native AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotX, Float:rotY, Float:rotZ, bool:syncRotation = true);`
* `native bool:IsValidObject(objectid);`
* `native bool:IsObjectMoving(objectid);`
* `native bool:IsValidPlayerObject(playerid, objectid);`
* `native bool:IsPlayerObjectMoving(playerid, objectid);`
* `native SetObjectMaterialText(objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT);`
* `native SetPlayerObjectMaterialText(playerid, objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textalignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT);`
* `native SetObjectsDefaultCameraCol(bool:disable);`
* `native bool:IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z);`
* `native bool:IsPlayerStreamedIn(targetid, playerid);`
* `native TogglePlayerClock(playerid, bool:toggle);`
* `native PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false);`
* `native bool:IsPlayerAttachedSlotUsed(playerid, index);`
* `native PlayerTextDrawUseBox(playerid, PlayerText:text, bool:use);`
* `native PlayerTextDrawSetProportional(playerid, PlayerText:text, bool:set);`
* `native PlayerTextDrawSetSelectable(playerid, PlayerText:text, bool:set);`
* `native TogglePlayerControllable(playerid, bool:toggle);`
* `native ApplyAnimation(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, FORCE_SYNC:forceSync = _FIXES_FORCE_SYNC_NONE);`
* `native DisableRemoteVehCollisions(playerid, bool:disable);`
* `native ShowPlayerNameTagForPlayer(playerid, targetid, bool:show);`
* `native AllowPlayerTeleport(playerid, bool:allow);`
* `native EnablePlayerCameraTarget(playerid, bool:enable);`
* `native bool:IsPlayerConnected(playerid);`
* `native bool:IsPlayerInVehicle(playerid, vehicleid);`
* `native bool:IsPlayerInAnyVehicle(playerid);`
* `native bool:IsPlayerInCheckpoint(playerid);`
* `native bool:IsPlayerInRaceCheckpoint(playerid);`
* `native EnableStuntBonusForPlayer(playerid, bool:enable);`
* `native EnableStuntBonusForAll(bool:enable);`
* `native TogglePlayerSpectating(playerid, bool:toggle);`

You can also see several additional tags in those definitions, such as `OBJECT_MATERIAL_SIZE:` but
as stated they are optional.

If you are using `WEAK_TAGS` or `STRONG_TAGS` there is a minor problem - callbacks give an error:

```pawn
forward OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);

public OnPlayerStateChange(playerid, newstate, oldstate)
{
}
```

This gives an error, when it should be fine.  Fixing it in a mode is easy - just use the correct
tags on the variables in the callbacks.  Fixing it in a generic library needs a few extra lines to
define a default tag when one isn't found (i.e. the user isn't using the improved includes):

```pawn
#if !defined PLAYER_STATE
	// Use the default tag (none, `_:`) when the improved includes aren't found.
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
	return Hooked_OnPlayerStateChange(playerid, newstate, oldstate);
}

// Don't forget to use ALS as normal.
forward Hooked_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
```

## Keys And Actions

"Keys" have been renamed "Actions" because they aren't keys and the name constantly confused
everyone.  You can't detect "F" you can only detect "JUMP".  You can't make any assumptions about
which keys are bound to which actions.  You can't ask players to press a specific key (except when
using `"~k~"` in strings, which maps actions back to keys).  You can't detect specific keys.  No
matter how many times this is explained the follow-up questions are invariably, "OK, but how do I
detect this key?"  You can't, and never could.  Thus `GetPlayerKeys` has been replaced by
`GetPlayerActions`, `OnPlayerKeyStateChange` has been replaced by `OnPlayerActionStateChange`,
`newkeys` and `oldkeys` have been replaced by `newactions` and `oldactions`, and `KEY` has been
replaced by `ACTION` (leading to the interestingly named macro `ACTION_ACTION` from `KEY_ACTION`):

```pawn
// The `ACTION` tags are optional.
public OnPlayerActionStateChange(playerid, ACTION:newactions, ACTION:oldactions)
{
	new
		ACTION:actions,
		ACTION:updown,
		ACTION:leftright;
	GetPlayerActions(playerid, actions, updown, leftright);
	return 1;
}
```

## API

fixes.inc includes a lot of data and processing that is required for it to function, but could be
useful for other scripts - things like vehicle meta-data, current status of players, and more.
While new functions are not the primary goal of this include, it seems silly to keep this
information hidden when it can be used, forcing people to duplicate functionality just to do things
like get a player's current dialog ID for example.  The general rule is still not to add new
functions, there are many other libraries for that; but if the data already exists thanks to the
code being required for a fix, then it might as well be exposed.

Most of these additional functions are controlled by `FIX_API`, and can be tested for with
`FIXES_API`, but some older ones have their own `FIX_` definition (which now defaults to `FIX_API`).

### `GetDefaultPlayerColour(playerid)`

Gets the default colour assigned to a player when they first connect.  There are only 100 unique
colours, which are repeated:

```pawn
new colour = GetDefaultPlayerColour(playerid);
printf("The player's colour is %x", colour);
```

Note that you can also use the alias `GetDefaultPlayerColor`.

### `GetVehicleSeats(modelid)`

Get the number of seats in the given vehicle type (model).

```pawn
new seats = GetVehicleSeats(400);
printf("The landstalker has %d seats", seats);
```

### `bool:VehicleCanHaveComponent(modelid, componentid)`

Returns true if the given vehicle type (model) can use the given component (mod) type.

```pawn
if (VehicleCanHaveComponent(536, 1005))
{
	printf("The Blade can have the fury scoop");
}
else
{
	printf("The Blade cannot have the fury scoop");
}
```

### `bool:IsValidAnimationLibrary(const snimlib[])`

Returns true if the named animation library exists.

```pawn
if (IsValidAnimationLibrary("parkour")
{
	printf("`parkour` is a valid animation library");
}
else
{
	printf("`parkour` is not a valid animation library");
}
```

### `bool:GetRandomCarColPair(modelid, &colour1, &colour2, &colour3 = 0, &colour4 = 0)`

Gets a random pair of colours for a vehicle (three vehicles have four colours), according to the
predefined colour options in carcols.dat.  These are the colours selected from when `-1` is used as
the colour of a vehicle (but the colours chosen are not synced by default).

```pawn
new c1, c2;
GetRandomCarColPair(495, c1, c2);
printf("Colours chosen for the Sandking: %d, %d", c1, c2);
```

Note that the values returned are the COLOUR INDEXES, those passed to say `CreateVehicle`, they are
not the HEX codes for the given colours.

### `GetPlayerDialog(playerid)`

Get's the currently displayed dialog ID for a player.

```pawn
new dialogid = GetPlayerDialog(playerid);
printf("Player %d is viewing dialog %d", playerid, dialogid);
```

### `GetPlayerWeather(playerid)`

Get's the current weather ID for a player.

```pawn
new weatherid = GetPlayerWeather(playerid);
printf("Player %d currently has weather %d", playerid, weatherid);
```

### `GetWeather()`

Get's the current server global weather.

```pawn
new weatherid = GetWeather();
printf("The server currently has weather %d", weatherid);
```

### `GetWorldTime()`

Get's the current server global weather.

```pawn
new time = GetWorldTime();
printf("The time on the server is currently %02d:00", time);
```

### `ClearPlayerWorldBounds(playerid)`

Resets the world boundaries to their maximum, after using `SetPlayerWorldBounds`.

```pawn
ClearPlayerWorldBounds(playerid);
```

### `GetPlayerWorldBounds(playerid, &Float:x_max, &Float:x_min, &Float:y_max, &Float:y_min)`

Gets the world boundaries for a player, set by `SetPlayerWorldBounds`.

```pawn
new
	Float:x_max,
	Float:x_min,
	Float:y_max,
	Float:y_min;
GetPlayerWorldBounds(playerid, x_max, x_min, y_max, y_min);
printf("Player %d's world boundaries are at (%.2f, %.2f) - (%.2f, %.2f)", x_min, y_min, x_max, y_max);
```

### `HideGameTextForAll(style)`

Hide this type of gametext for all players.

```pawn
HideGameTextForAll(3);
```

### `HideGameTextForPlayer(playerid, style)`

Hide this type of gametext for one player.

```pawn
HideGameTextForPlayer(playerid, 3);
```

### `bool:PlayerHasClockEnabled(playerid)`

Does this player have auto-incrementing time enabled?

```pawn
if (PlayerHasClockEnabled(playerid))
{
	printf("Time might have changed.");
}
```

### `bool:IsMenuValid(Menu:menuid)`

Is the given menu ID valid?

```pawn
if (IsMenuValid(menuid))
{
	printf("The menu was created at some point.");
}
```

### `CarColIndexToColour(index, alpha = 0xFF)`

Convert from a vehicle colour index to an RGBA colour (with the specified alpha).

```pawn
new c1, c2;
GetRandomCarColPair(495, c1, c2);
printf("Colours chosen for the Sandking: %08x, %08x", CarColIndexToColour(c1), CarColIndexToColour(c2));
```

Note that you can also use the alias `CarColIndexToColor`.

## Tests

Other code and includes can test for certain fixes.inc symbols, to see what is defined and what isn't.  These all use basic `#if defined` checks, with no need to test the value:

* `FIXES_EXISTS`:  The include is used.
* `FIXES_API`:  The additional API functions (see above) were defined and can be used.
* `FIXES_USES_STATE_HOOKS`:  fixes.inc uses advanced state-based ALS hooks, not just regular ones.
* `FIXES_CONST_CORRECT`:  The include is fully const-correct (and backwards-compatible).
* `FIXES_TAG_CORRECT`:  The include is fully tag-correct (and backwards-compatible), i.e. optionally uses additional tags in callbacks such as `OnPlayerStateChange`.
* `FIXES_PAWNDOC`:  The include has methods of hiding unwanted pawndoc declarations.
* `FIXES_ID`:  The include defines the pubic variable `@_`, which is a unique ID for the current script.  This is also defined by YSI if it isn't defined here.

## Other Fixes

There are a few other includes which aim to fix issues too large to be included here:

* [Timerfix](https://sampforum.blast.hk/showthread.php?tid=435525) - [udan11 (Dan..)](https://github.com/udan11) 's fixes to make "SetTimer" and "SetTimerEx" vastly more accurate in their delays.
* [SQLitei](https://sampforum.blast.hk/showthread.php?tid=303682) - [Slice](https://github.com/oscar-broman/) 's fixes and improvements for many SQLite functions.

## New Features

fixes.inc is not intended to add new features; however, it does add a few and detractors think it is funny to point to those as a good reason why the library is bad.  The reason why is simple - they were added before the exact scope and definition of "fix" was determined.  New features are not added any more, but existing features that were already added (most notably the new game text styles) are left in because removing them is more breaking than having them.  Yes, they exist; no, they probably shouldn't; no, they wouldn't be added today; no, they won't be removed.

## Bugs

Originally Posted by [Y_Less](https://github.com/Y-Less/) :

**[This] is beta software written by a small team in their spare time, thus it has bugs (as does all software). This software is explicitly designed to solve bugs, not cause them, but there may still be bugs.**

The most likely cause of bugs is certain combinations of disabled fixes. Some fixes are inter-mixed and while they SHOULD work when the fixes they are combined with are disabled, not every combination has been tested. There are literally billions of possible combinations - if you find one that doesn't compile or work, please tell us.

## Expansion

The file is fairly well documented, with a list of the currently (hopefully) fixed bugs at the top. If you know of others, or have solutions for others, it would be greatly appreciated if you could post them as issues on this repository. The fixes also need extensive testing to find bugs in the fixes themselves.

Again, this is a community project, merely managed by Y_Less and others - if anyone has comments, contributions, criticisms etc. please again post them as issues on the repository. This includes additions to source code, documentation, presentation, translations (mainly of this documentation - multiple versions of the include should be avoided to reduce fragmentation), or any other related area you can think of.

## Style Rules

* All globals should be `static stock` whenever possible (so they can only be accessed from this one file).
* Statics must start with `FIXES_gs`, and all other globals with `FIXES_g`.
* All functions not overriding existing functions must start with `FIXES_`.
* Macros must be upper case, use underscores, and start `FIXES_`: `FIXES_LIKE_THIS`.
* Functions should be upper camel case (as the original functions are) `FIXES_LikeThis`.
* Globals (after the prefix) should be upper camel case `LikeThis`, and locals lower camel case `likeThis`.
* ALS should be used to hook functions and callbacks. See this topic for more details: https://sampforum.blast.hk/showthread.php?tid=570910
* The ALS prefix for chaining is `FIXES_`.
* When redefining a native, add a `BAD_` external name declaration with the `_ALS_` definition so that others may use the original native if they so desire (with the caveat that it may break all fixes). Note the `BAD_` name is meant to indicate the possibility of breaking the fix, not a comment on the original native function.
* The ALS hook defines used here are a little different to the normal ones as this file assumes that it is always first. The pattern is:

```pawn
/**
 * <remarks>Information about fix here</remarks>
 * <fixes>NameOfFixHere</fixes>
 */

// No other ALS hook of this function much exist before here.
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

	// This is not normal ALS, because fixes.inc must come first.
    #define _ALS_NameOfFixHere__
    #define NameOfFixHere__( FIXES_NameOfFixHere(
#endif
```

A copyable version of this pattern is at the end of the file.
* Enums start with `E_` or `e_` depending on type, then follow rules for macros.
* NO libraries should be included - not even the default SA:MP ones. Let the user do it.
* Due to the above rule, you cannot assume any third party libraries AT ALL, so do not use them. This can lead to some code duplication, but also means that the version of the code used here can be tailored for optimisations.
* Certain terms may be shortened when dealing with long callback names to avoid compile truncation warnings (max symbol length is 31). Current list:
* `Checkpoint`: `CP`
* `Update `: `Upd`
* `TextDraw `: `TD`
* `Object `: `Obj`
* `Player `: `P`
* Document all fixes at the top of the file, and highlight code.
* 4 space TABS - do not edit this file in PAWNO unless you know how to correct the indentation.
* All rules have exceptions, but they must be justifiable. For example `IS_FILTERSCRIPT` is a global variable, but is not called `FIXES_gIsFilterscript` to better match the `FILTERSCRIPT` macro it replaces. Now a macro for `_FIXES_gIsFilterscript`.
* Variables which need to be fully global (i.e. not `static`), but should not actually be used by other people (e.g. appear inside a macro) should be prefixed with `_FIXES` instead of `FIXES` to indicate their private use.
* No comments beyond the end of column 80 (where the line in `PAWNO` is).
* If a bug is fixed in some version of the server it can be conditionally included here. This is done by checking for the existance of a native function introduced in the same server version. For example `TogglePlayerControllable` was fixed in 0.3eRC6, the same time as the `SetObjectMaterial` native was introduced, thus the inclusion becomes:

```pawn
/**
 * <fix name="NameOfFixHere" disabled="true" fixed="version">
 *     <problem>
 *         A description of the problem.
 *     </problem>
 *     <solution>
 *         A description of the solution.
 *     </solution>
 *     <see>FIXES_FunctionWithFixIn</see>
 *     <author href="github.com/account">Name</author>
 *     <post href="burgershot.gg/post" />
 * </fix>
 */

#if !defined FIX_NameOfFixHere
	#if defined NativeInFixRelease
		#if FIXES_EnableDeprecated
			static _FIXES_STOCK FIX_NameOfFixHere = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_NameOfFixHere);
		#endif
		#define FIX_NameOfFixHere                FIXES_EnableDeprecated
	#else
		static _FIXES_STOCK FIX_NameOfFixHere = _FIXES_DEFAULT;
		#define FIX_NameOfFixHere                _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_NameOfFixHere)
	#undef FIX_NameOfFixHere
	static stock FIX_NameOfFixHere = 2;
	#define FIX_NameOfFixHere                    (2)
#elseif FIX_NameOfFixHere
	#undef FIX_NameOfFixHere
	static stock FIX_NameOfFixHere = 1;
	#define FIX_NameOfFixHere                    (1)
#else
	#undef FIX_NameOfFixHere
	static stock FIX_NameOfFixHere = 0;
	#define FIX_NameOfFixHere                    (0)
#endif
```

This only includes this fix if that native doesn't exist. A copyable version of this pattern is at the end of the file.
* To reduce general memory consumption, strings in this include are stored globally in constant arrays and referenced. This is EXACTLY as fast as using the string constants directly, but means that strings are not stored in the assembly multiple times (unless the string is only used once, in which case it's more work for no gain). See this post for more details: [http://forum.sa-mp.com/showpost.php?p=1795601](http://forum.sa-mp.com/showpost.php?p=1795601)
* DO NOT EDIT THIS FILE IN PAWNO OR ON GITHUB. Both mess up the spacing - GitHub in an almost irreversible way (except for the fact that nothing is irreversible in source control. Pawno spacing is less tricky to solve, and can be worked around if you know when it uses spaces and tabs - in short, always write code first THEN indent and you won't have a problem (in that editor at least, that is normally a bad way to write code).

## Documentation Explanation

The **fixes.inc** code itself now contains all of the documentation in its header, formatted using the compiler's natively supported pawn-doc, plus some custom XSL. Previously **README.md** and the header had to be kept in sync manually. Now you can just compile a script with `-r` and get a large amount of XML documentation, including all of this header in a `<library></library>` pair. The repository comes with a file called **markdown.xsl** that, when saved as **pawno/xml/pawndoc.xsl**, will transform that XML to markdown to keep **README.md** fully up-to-data almost automatically.

The descriptions of the fixes all look like:

```xml
<fix name="Short Name" disabled="true" fixed="Optional server version of official fix where applicable">
	<problem>
	Description of problem.
		</problem>
	<solution>
		Description of solution.
	</solution>
	<see>Relevant functions.</see>
	<author href="Optional address of their profile">Person who wrote the fix</author>
	<post href="Optional link to the original post where applicable." />
</fix>
```

## Thanks

A huge thanks to all the community members that have reported and fixed bugs, this include would not be anywhere near the level of quality it is right now without all of you.  Fix writers are all listed above by their contributions.  Fix reporters can be seen by browsing the github issues.  A special thanks also to [@ziggi](https://github.com/ziggi) for hosting this repo for a long time.

