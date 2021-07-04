

# fixes.inc

### Community patches for buggy SA:MP functions.



## Introduction 


SA:MP is beta software written by a small team in their spare time, thus it has bugs (as does all software). Some of these have been known for a long time but are low priority due to their minor effects, others go undiscovered for a long time. Many of these bugs have solutions which can be implemented in PAWN (and this may be simpler than implementing them in the SA:MP source code). This include aims to collect fixes for as many of these bugs as possible from the community (i.e. anyone who has a fix) together in to one easy to use place for everyone's benefit.



## Use 


To use this, simply include it after the default SA:MP functions, but before third party includes:



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



## Fixes 


Name | Problem | Solution | Author(s) | Post(s) | Notes 
---- | ---- | ---- | ---- | ---- | ---- 
GetPlayerColor | Returns "0" if "SetPlayerColor" has never been called. | Call "SetPlayerColor" in "OnPlayerConnect". | KoczkaHUN | | 
FILTERSCRIPT | Despite the fact that is in every new script, many people dont' define "FILTERSCRIPT" where appropriate. | Provide an "IS_FILTERSCRIPT" variable (note the naming to match the original macro). | [Y_Less](https://github.com/Y-Less/) | | 
SpawnPlayer | Kills the player if they are in a vehicle. | Remove player from the vehicle. | [Y_Less](https://github.com/Y-Less/) | | 
SetPlayerName | Using "SetPlayerName" when the new name only differs from the old name in case does not alter the name at all. | Change their name twice - once to "_FIXES TEMP NAME" and then to the actual required name. | [Y_Less](https://github.com/Y-Less/) [Slice](https://github.com/oscar-broman/) [simonepri](https://github.com/simonepri/) | | 
GetPlayerSkin | Returns the new skin after "SetSpawnInfo" is called but before the player actually respawns to get the new skin. | Record the skin in "OnPlayerSpawn" and always return that one. | [Y_Less](https://github.com/Y-Less/) | | 
GetWeaponName | Returns nothing for 18, 44, and 45. | Return the correct names (`Molotov Cocktail`, `Thermal Goggles`, and `Night vision Goggles`). | [Y_Less](https://github.com/Y-Less/) | | **Fixed in 0.3.7** 
SetPlayerWorldBounds | Aiming can bypass the edge. | Check for the player leaving the area and reset them to their last good position if they leave the area (aiming or not). | [Y_Less](https://github.com/Y-Less/) | | 
TogglePlayerControllable | Other players see you moving on the spot. | Return 0 in OnPlayerUpdate. | [Slice](https://github.com/oscar-broman/) | [Link](http://forum.sa-mp.com/showpost.php?p=876854) | 
HydraSniper | Entering military aircraft with a sniper rifle messes up views. | Set their armed weapon to fists. | funky1234 | [Link](http://forum.sa-mp.com/showpost.php?p=965644) | 
IsPlayerInCheckpoint | Function returns an undefined value if it is called before any other checkpoint functions are called to initialise the value. | Call "DisablePlayerCheckpoint" when they connect. | [Y_Less](https://github.com/Y-Less/) | | 
IsPlayerInRaceCheckpoint | Function returns an undefined value if it is called before any other race checkpoint functions are called to initialise the value. | Call "DisablePlayerRaceCheckpoint" when they connect. | [Y_Less](https://github.com/Y-Less/) | | 
GetPlayerWeapon | Returns the old value after entering in a vehicle. | If "SetPlayerArmedWeapon" and other similar functions is called in a vehicle, store the new value and return that instead. | [Y_Less](https://github.com/Y-Less/) [ronixtey](https://github.com/ronixtey/) | | 
PutPlayerInVehicle | If this is used on a passenger the driver of their old vehicle doesn't see them in their new vehicle. | Remove them from the vehicle first. | leong124 [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1265965) | 
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
OnPlayerEnterVehicle | Crashes other players when people enter an invalid seat. | Desync the people with invalid seats. | RyDeR` [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1410296) | 
OnPlayerEnterVehicle_2 | Crashes the server when hacks enter an invalid vehicle. | Desync the people with invalid vehicles. | im [Y_Less](https://github.com/Y-Less/) | | 
OnPlayerEnterVehicle_3 | No player animation when trying to enter the driver door of a locked vehicle | Leave the door unlocked and activate an animation when the player attemps to enter a 'locked' vehicle. | [ziggi](https://github.com/ziggi) [rt-2](https://github.com/rt-2) | [Link](http://forum.sa-mp.com/showthread.php?t=560019) | 
AllowTeleport | 0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in favour of "OnPlayerClickMap". Some scripts used the old code and. | Teleport the player in "OnPlayerClickMap". | [Y_Less](https://github.com/Y-Less/) | | 
SetPlayerSpecialAction | Removing jetpacks from players by setting their special action to 0 causes the sound to stay until death. | Call "ClearAnimations" before "SetPlayerSpecialAction". | MP2 | | 
OnDialogResponse | Cheaters can spoof the dialogid they are using to respond to ones they can't actually see. | Store the displayed dialogid and use that instead. | [Y_Less](https://github.com/Y-Less/) | | **Fixed in 0.3e RC6** 
GetPlayerDialog | This function doesn't exist. Fixed for hidden dialogs. | Add it. | [Y_Less](https://github.com/Y-Less/) [simonepri](https://github.com/simonepri/) | | **Disabled By Default** 
PlayerDialogResponse | A player's dialog doesn't hide when the gamemode restarts, causing the server to print "Warning: PlayerDialogResponse PlayerId: 0 dialog ID doesn't match last sent dialog ID". | Hide it. | [simonepri](https://github.com/simonepri/) | | 
SetSpawnInfo | Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo". | Call "SetSpawnInfo" at least once. | [Y_Less](https://github.com/Y-Less/) | | 
SetPlayerSkin | Breaks sitting on bikes. | Put them back in the vehicle after setting their skin. | CyNiC | [Link](http://forum.sa-mp.com/showpost.php?p=1756094) | 
HideMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1787297) | 
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
OnPlayerDeath | Clients get stuck when they die with an animation applied. | Clear their animations. | h02 | [Link](http://forum.sa-mp.com/showpost.php?p=1641144) | 
strins | Ignores the "maxlength" parameter causing possible crashes. | Manually check the length. | [Slice](https://github.com/oscar-broman/) [Y_Less](https://github.com/Y-Less) | | 
IsPlayerConnected | Only uses the lower two bytes of a passed ID. | Mask the numbers. | [Slice](https://github.com/oscar-broman/) | | 
TrainExit | When getting out of a train entered by "PutPlayerInVehicle", the camera does not reset properly. | Reset the camera. | Terminator3 [Y_Less](https://github.com/Y-Less/) | | 
Kick | Calling "Kick" in "OnPlayerConnect" doesn't work properly. | Defer it. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1989453) | **Fixed in 0.3x** 
OnVehicleMod | Crashes other players when invalid mods are applied. | Desync the player. | [JernejL](https://github.com/JernejL/) [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1671500) | 
random | Doesn't work with negative numbers. | Invert then reinvert. | [simonepri](https://github.com/simonepri/) | | **Disabled By Default** 
sleep | Leaks bytes from the stack. | Call a function to store the correct value. | [Y_Less](https://github.com/Y-Less/) | | 
AddMenuItem | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | | 
SetMenuColumnHeader | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | | 
ShowMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | | 
HideMenuForPlayer | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1787297) | 
HideMenuForPlayer_2 | Ignores the "menuid" parameter. | Only hide the correct menu. | [Y_Less](https://github.com/Y-Less/) | | **Disabled By Default** 
DisableMenu | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | | 
DisableMenuRow | Crashes when passed an invalid menu ID. | Don't hide it when passed an invalid menu. | [Y_Less](https://github.com/Y-Less/) | | 
Menus | All menu function fixes are included separately for major overhead. | Optionally group them all under one define. | [Y_Less](https://github.com/Y-Less/) | | 
GetPlayerMenu | Returns previous menu when none is displayed. | Return the correct value. | [Y_Less](https://github.com/Y-Less/) | | 
GetPlayerInterior | Always returns 0 for NPCs. | Return the correct value. | [Y_Less](https://github.com/Y-Less/) [simonepri](https://github.com/simonepri/) | | 
ClearAnimations | Use ClearAnimation while you are in a vehicle cause the player exit from it. | Apply an animation instead of clear animation. | [simonepri](https://github.com/simonepri/) | | 
ClearAnimations_2 | ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in ApplyAnimation. | Apply an idle animation for stop and then use ClearAnimation. | [simonepri](https://github.com/simonepri/) | | 
DriveBy | If you press KEY_CROUCH while you're passenger and if you are armed, the player start to aim; if you repress KEY_CROUCH the player don't return in vehicle. | Apply the animation to return the player in the vehicle. | [simonepri](https://github.com/simonepri/) | | 
SilentTeleport | If a vehicle teleports either by SetVehiclePos or enters an original samp interior if someone tries to enter it he will teleport silently along. | Using 'ClearAnimation' to stop the player before the teleport happens. | [RogueDrifter](https://github.com/RogueDrifter/) | [Link](http://forum.sa-mp.com/showthread.php?t=650422) |
GangZoneCreate | Gang zones bug on the main map for players at certain angles relative to them. | Set a non floating value for the gang zone co-ordinate. | [simonepri](https://github.com/simonepri/) [Y_Less](https://github.com/Y-Less/) | | 
SPECIAL_ACTION_PISSING | "SPECIAL_ACTION_PISSING" isn't defined by default. | Define it. | [simonepri](https://github.com/simonepri/) | | 
IsValidVehicle | "IsValidVehicle" isn't defined by default. | Define it. | [simonepri](https://github.com/simonepri/) | | 
ApplyAnimation | Passing an invalid animation library in ApplyAnimation causes a client crash for streamed in players. | Block ApplyAnimation when an invalid library is passed. | [simonepri](https://github.com/simonepri/) | | 
ApplyAnimation_2 | First time a library is used, it does nothing. | Apply animations twice when first using a library. | [simonepri](https://github.com/simonepri/) [Lordzy](https://github.com/Lordzy/) [Y_Less](https://github.com/Y-Less/) | | 
ApplyActorAnimation | Passing an invalid animation library in ApplyAnimation causes a client crash for streamed in players. | Block ApplyActorAnimation when an invalid library is passed. | [simonepri](https://github.com/simonepri/) [ziggi](https://github.com/ziggi/) | | 
ApplyActorAnimation_2 | First time a library is used, it does nothing. | Apply animations twice when first using a library. | [simonepri](https://github.com/simonepri/) [Lordzy](https://github.com/Lordzy/) [Y_Less](https://github.com/Y-Less/) [ziggi](https://github.com/ziggi/) | | 
OnPlayerSpawn | San Andreas deducts $100 from players. | Give them it back. | [Y_Less](https://github.com/Y-Less/) | | 
GetGravity | "GetGravity" isn't defined by default. | Define it. | [Whitetiger](https://github.com/Whitetigerswt) | [Link](http://forum.sa-mp.com/showpost.php?p=1706447) | 
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
CAMERAMODES | The camera modes for GetPlayerCameraMode are not defined by default. | Define it. | [Whitetiger](https://github.com/Whitetigerswt) | [Link](http://forum.sa-mp.com/showpost.php?p=1309730) | 
SetPlayerCamera | Using the camera functions directly after enabling spectator mode doesn't work. | Defer them. | [Emmet_](https://github.com/emmet-jones) | | 
SetPlayerTime | Using this function under "OnPlayerConnect" doesn't work. | Defer it. | [Emmet_](https://github.com/emmet-jones) | | 
OnPlayerRequestClass | Random blunts and bottles sometimes appear in class selection. | Call "RemoveBuildingForPlayer". | [Y_Less](https://github.com/Y-Less/) | | 
SetPlayerColor | If used under OnPlayerConnect, the affecting player will not see the color in the TAB menu. | Defer it. | [Emmet_](https://github.com/emmet-jones) | [Link](http://forum.sa-mp.com/showthread.php?t=452407) | 
FileMaths | You can write gibberish like "File:a; ++a;". | Remove the operators. | [Y_Less](https://github.com/Y-Less/) | | 
GetPlayerWeaponData | Old weapons with no ammo left are still returned. | Set "weapons" to 0. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showthread.php?t=567400) | 
strcmp | Return 0 if anyone of the string is empty. | Add a check for empty string. | [Y_Less](https://github.com/Y-Less) | | 
GetPVarString | Wrong symbol code for symbols with code 128 and above. | Use logical conjunction on symbol and 0xFF. | [ziggi](https://github.com/ziggi) Mutha_X [Daniel_Cortez](https://github.com/Daniel-Cortez) | [Link](http://forum.sa-mp.com/showthread.php?t=572724&page=11) [Link](http://pro-pawn.ru/showthread.php?13007) | 
GetSVarString | Wrong symbol code for symbols with code 128 and above. | Use logical conjunction on symbol and 0xFF. | [ziggi](https://github.com/ziggi) Mutha_X [Daniel_Cortez](https://github.com/Daniel-Cortez) | [Link](http://forum.sa-mp.com/showthread.php?t=572724&page=11) [Link](http://pro-pawn.ru/showthread.php?13007) | 
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

## API

fixes.inc includes a lot of data and processing that is required for it to function, but could be
useful for other scripts - things like vehicle meta-data, current status of players, and more.
While new functions are not the primary goal of this include, it seems silly to keep this
information hidden when it can be used, forcing people to duplicate functionality just to do things
like get a player's current dialog ID for example.  The general rule is still not to add new
functions, there are many other libraries for that, but if the data already exists thanks to the
code required for a fix, then it might as well be exposed.


## Options 


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


* `FIXES_Single`: You only have one script that uses *fixes.inc* running (no other gamemodes or filterscripts).  Using this define will vastly simplify the code in that case, as no cross-script communication is required.  Default `1`.
* `FIXES_SilentKick`: When a player is kicked for illegal mods/vehicles, don't send them a message.  Default `0`.
* `FIXES_Debug`: Additional information in the server console.  Default `0`.
* `FIXES_SingleMsg`: Show a message at mode start if `FIXES_Single` is set, but this is NOT the only script running *fixes.inc*.  This will entirely disable the check, so should only be used if you are absolutely certain that no other scripts are running at the same time (gamemodes or filterscripts).  Default `1`.
* `FIXES_ServerVarMsg`: Show a message at mode start about server var fixes.  Default `1`.
* `FIXES_GetMaxPlayersMsg`: Show a message at mode start about max player fixes.  Default `1`.
* `FIXES_Debug`: Additional information in the server console.  Default `0`.
* `FIXES_EnableAll`: Enable all current and future default disabled fixes.  Default `0`.
* `FIXES_EnableDeprecated`: Enable all past (deprecated) fixes.  Might causes errors and conflicts with newer SA:MP includes.  Default `0`.
* `FIXES_DefaultDisabled`: Disable all fixes by default, and require them to be individually enabled with `FIX_<name> 1`  Default `0`.
* `FIXES_ExplicitOptions`: Require fixes to be explicitly enabled or disabled, and show a warning for every fix not mentioned.  Useful in combination with `FIXES_DefaultDisabled`, so default `1` with that, `0` otherwise.


Note that `options` are which fixes to include, and `settings` are more over-arching customisations.


## Tests


Other code and includes can test for certain fixes.inc symbols, to see what is defined and what isn't.  These all use basic `#if defined` checks, with no need to test the value:


* `FIXES_EXISTS`:  The include is used.
* `FIXES_API`:  The additional API functions (see above) were defined and can be used.
* `FIXES_USES_STATE_HOOKS`:  fixes.inc uses advanced state-based ALS hooks, not just regular ones.
* `FIXES_CONST_CORRECT`:  The include is fully const-correct (and backwards-compatible).
* `FIXES_TAG_CORRECT`:  The include is fully tag-correct (and backwards-compatible), i.e. optionally uses additional tags in callbacks such as `OnPlayerStateChange`.


## Expansion 


The file is fairly well documented, with a list of the currently (hopefully) fixed bugs at the top. If you know of others, or have solutions for others, it would be greatly appreciated if you could post them as issues on this repository. The fixes also need extensive testing to find bugs in the fixes themselves.



Again, this is a community project, merely managed by Y_Less and others - if anyone has comments, contributions, criticisms etc. please again post them as issues on the repository. This includes additions to source code, documentation, presentation, translations (mainly of this documentation - multiple versions of the include should be avoided to reduce fragmentation), or any other related area you can think of.



## Other Fixes 


There are a few other includes which aim to fix issues too large to be included here:


* [Timerfix](http://forum.sa-mp.com/showthread.php?t=435525) - [udan11 (Dan..)](https://github.com/udan11) 's fixes to make "SetTimer" and "SetTimerEx" vastly more accurate in their delays. 
* [SQLitei](http://forum.sa-mp.com/showthread.php?t=303682) - [Slice](https://github.com/oscar-broman/) 's fixes and improvements for many SQLite functions. 

## Bugs 


Originally Posted by [Y_Less](https://github.com/Y-Less/) :



**[This] is beta software written by a small team in their spare time, thus it has bugs (as does all software). This software is explicitly designed to solve bugs, not cause them, but there may still be bugs.**



The most likely cause of bugs is certain combinations of disabled fixes. Some fixes are inter-mixed and while they SHOULD work when the fixes they are combined with are disabled, not every combination has been tested. There are literally billions of possible combinations - if you find one that doesn't compile or work, please tell us.



## Style Rules 

* All globals should be `static stock` whenever possible (so they can only be accessed from this one file). 
* Statics must start with `FIXES_gs`, and all other globals with `FIXES_g`. 
* All functions not overriding existing functions must start with `FIXES_`. 
* Macros must be upper case, use underscores, and start `FIXES_`: `FIXES_LIKE_THIS`. 
* Functions should be upper camel case (as the original functions are) `FIXES_LikeThis`. 
* Globals (after the prefix) should be upper camel case `LikeThis`, and locals lower camel case `likeThis`. 
* ALS should be used to hook functions and callbacks. See this topic for more details: http://forum.sa-mp.com/showthread.php?t=570910 
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
#if !defined FIX_TogglePlayerControllable
	// This fix isn't specified.

	// Check for some native introduced in the same version as this was fixed.
	#if defined SetObjectMaterial
		// Is fixed, only include this fix if we want deprecated fixes.
		#define FIX_TogglePlayerControllable FIXES_EnableDeprecated
	#else 
		// Not fixed yet (use only this branch if there's no native fix).

		// Define a symbol of this name, to give warnings with `FIXES_ExplicitOptions`.
		_FIXES_STOCK FIX_TogglePlayerControllable = _FIXES_DEFAULT;

		// Enable or disable the fix according to `FIXES_DefaultDisabled`.
		#define FIX_TogglePlayerControllable _FIXES_DEFAULT
	#endif 
#elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
	// The fix is specified, but with no `0` or `1`.
	#undef FIX_TogglePlayerControllable 

	// Default to `2` (`1`, but special).
	#define FIX_TogglePlayerControllable (2) 
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

