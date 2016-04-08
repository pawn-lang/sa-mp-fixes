# fixes.inc

Community written solutions to SA:MP bugs.

# Introduction

SA:MP is beta software written by a small team in their spare time, thus it has bugs (as does all software). Some of these have been known for a long time but are low priority due to their minor effects, others go undiscovered for a long time. Many of these bugs have solutions which can be implemented in PAWN (and this may be simpler than implementing them in the SA:MP source code). This include aims to collect fixes for as many of these bugs as possible from the community (i.e. anyone who has a fix) together in to one easy to use place for everyone's benefit.

# Use

To use this, simply include it after the default SA:MP functions, but before third party includes:
```Pawn
#include <a_samp>
// Any default re-definitions should go here.
//#undef MAX_PLAYERS
//#define MAX_PLAYERS 10
#include <fixes>
#include <other>
```

To disable any fix for whatever reason simply do:
```Pawn
#define FIX_<name> 0
```

For example, to disable all the file.inc fixes if you always correctly check the file handle, do:
```Pawn
#include <a_samp>
#define FIX_file_inc 0
#include <fixes>
#include <other>
```

All the names of the fixes are single words, and are all listed with their fix descriptions below.

If you only have one script running on your server (i.e. no Filter Scripts), you can use this define to improve the fixes.inc code:
```Pawn
#include <a_samp>
#define FIXES_Single 1
#include <fixes>
#include <other>
```

# Fixes
Name | Bug | Author | Post | Officially Fixed?
---- | ---- | ---- | ---- | ----
GetPlayerColor | Returns "0" if "SetPlayerColor" has never been called. | KoczkaHUN |  |
FILTERSCRIPT | Despite the fact that is in every new script, many people don't define "FILTERSCRIPT" where appropriate. | [Y_Less](https://github.com/Y-Less/) |  |
SpawnPlayer | Kills the player if they are in a vehicle. | [Y_Less](https://github.com/Y-Less/) |  |
SetPlayerName | Using "SetPlayerName" when the new name only differs from the old name in case does not alter the name at all. | [Y_Less](https://github.com/Y-Less/)/[simonepri](https://github.com/simonepri/) |  |
GetPlayerSkin | Returns the new skin after "SetSpawnInfo" is called but before the player actually respawns to get the new skin. | [Y_Less](https://github.com/Y-Less/) |  |
GetWeaponName | Returns nothing for 18, 44, and 45. | [Y_Less](https://github.com/Y-Less/) |  | 0.3.7
SetPlayerWorldBounds | Aiming can bypass the edge. | [Y_Less](https://github.com/Y-Less/) |  |
TogglePlayerControllable | Other players see you moving on the spot. | [Slice](https://github.com/oscar-broman/) | [Link](http://forum.sa-mp.com/showpost.php?p=876854) |
HydraSniper | Entring military aircraft with a sniper rifle messes up vies. | funky1234 | [Link](http://forum.sa-mp.com/showpost.php?p=965644) |
IsPlayerInCheckpoint | Function returns an undefined value if it is called before any other checkpoint functions are called to initialise the value. | [Y_Less](https://github.com/Y-Less/) |  |
IsPlayerInRaceCheckpoint | Function returns an undefined value if it is called before any other race checkpoint functions are called to initialise the value. | [Y_Less](https://github.com/Y-Less/) |  |
GetPlayerWeapon | Returns the old value after using "SetPlayerArmedWeapon" when they are in a vehicle. | [Y_Less](https://github.com/Y-Less/) |  |
PutPlayerInVehicle | If this is used on a passenger the driver of their old vehicle doesn't see them in their new vehicle. | leong124/[Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1265965) |
KEY_AIM | "KEY_AIM" isn't defined by default. | [Y_Less](https://github.com/Y-Less/) |  |
SetPlayerCheckpoint | If a checkpoint is already set it will use the size of that checkpoint instead of the new one. | [ziggi](https://github.com/ziggi/) |  |
SetPlayerRaceCheckpoint | If a checkpoint is already set it will use the size of that checkpoint instead of the new one. | [ziggi](https://github.com/ziggi/) |  |
TextDrawCreate | Crashes on a blank string. | wups |  |
TextDrawSetString | Crashes on a blank string and size greater than 1024. | TomTrox |  |
AllowInteriorWeapons | Does nothing. | KoczkaHUN |  |
OnPlayerEnterVehicle | Crashes other players when people enter an invalid seat. | RyDeR`/[Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1410296) |
OnPlayerEnterVehicle_2 | Crashes the server when hacks enter an invalid vehicle. | im/[Y_Less](https://github.com/Y-Less/) |  |
AllowTeleport | 0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in favour of "OnPlayerClickMap". Some scripts used the old code and. | [Y_Less](https://github.com/Y-Less/) |  |
SetPlayerSpecialAction | Removing jetpacks from players by setting their special action to 0 causes the sound to stay until death. | MP2 |  |
OnDialogResponse | Cheaters can spoof the dialogid they are using to respond to ones they can't actually see. | [Y_Less](https://github.com/Y-Less/) |  | 0.3e RC6
GetPlayerDialog (Disabled) | This function doesn't exist. | [Y_Less](https://github.com/Y-Less/)/[simonepri](https://github.com/simonepri/) |  |  |
PlayerDialogResponse | A player's dialog doesn't hide when the gamemode restarts, causing the server to print "Warning: PlayerDialogResponse PlayerId: 0 dialog ID doesn't match last sent dialog ID". | [simonepri](https://github.com/simonepri/) |  |  |
SetSpawnInfo | Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo". | [Y_Less](https://github.com/Y-Less/) |  |
SetPlayerSkin | Breaks sitting on bikes. | CyNiC | [Link](http://forum.sa-mp.com/showpost.php?p=1756094) |
HideMenuForPlayer | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1787297) |
valstr | Crashes on large numbers. | [Slice](https://github.com/oscar-broman/) |  |
fclose (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fwrite (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fread (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fputchar (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fgetchar (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fblockwrite (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fblockread (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
fseek (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
flength (Disabled) | Crashes on an invalid handle. | [Slice](https://github.com/oscar-broman/) |  |
file_inc (Disabled) | Includes or excludes all the file function fixes together (can cause major overhead). | [Y_Less](https://github.com/Y-Less/) |  |
IsPlayerAttachedObjectSlotUsed | Doesn't work in OnPlayerDisconnect. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1794167) |
SetPlayerAttachedObject | Doesn't remove objects when the mode ends. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1794167) |
OnPlayerDeath | Clients get stuck when they die with an animation applied. | h02 | [Link](http://forum.sa-mp.com/showpost.php?p=1641144) |
strins | Ignores the "maxlength" parameter causing possible crashes. | [Slice](https://github.com/oscar-broman/) | |
IsPlayerConnected | Only uses the lower two bytes of a passed ID. | [Slice](https://github.com/oscar-broman/) |  |
OnPlayerCommandText | Can crash ZCMD when passed a null string. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1909511) |
TrainExit | When getting out of a train entered by "PutPlayerInVehicle", the camera does not reset properly. | Terminator3/[Y_Less](https://github.com/Y-Less/) |  |
Kick | Calling "Kick" in "OnPlayerConnect" doesn't work properly. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1989453) | 0.3x
OnVehicleMod | Crashes other players when invalid mods are applied. | [JernejL](https://github.com/JernejL/)/[Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1671500) |
random (Disabled) | Doesn't work with negative numbers. | [simonepri](https://github.com/simonepri/) |  |
sleep | Leaks bytes from the stack. | [Y_Less](https://github.com/Y-Less/) |  |
AddMenuItem | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) |  |
SetMenuColumnHeader | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) |  |
ShowMenuForPlayer | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) |  |
HideMenuForPlayer | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showpost.php?p=1787297) |
HideMenuForPlayer_2 (Disabled) | Ignores the "menuid" parameter. | [Y_Less](https://github.com/Y-Less/) |  |
DisableMenu | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) |  |
DisableMenuRow | Crashes when passed an invalid menu ID. | [Y_Less](https://github.com/Y-Less/) |  |
Menus | All menu function fixes are included separately for major overhead. | [Y_Less](https://github.com/Y-Less/) |  |
GetPlayerMenu | Returns previous menu when none is displayed. | [Y_Less](https://github.com/Y-Less/) |  |
GetPlayerInterior | Always returns 0 for NPCs. | [Y_Less](https://github.com/Y-Less/)/[simonepri](https://github.com/simonepri/) |  |
ClearAnimations | Use ClearAnimation while you are in a vehicle cause the player exit from it. | [simonepri](https://github.com/simonepri/) |  |
ClearAnimations_2 | ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in ApplyAnimation. | [simonepri](https://github.com/simonepri/) |  |
KEY_CROUCH | If you press KEY_CROUCH while you're passenger and if you are armed, the player start to aim; if you repress KEY_CROUCH the player don't return in vehicle. | [simonepri](https://github.com/simonepri/) |  |
GangZoneCreate | Gang zones bug on the main map for players at certain angles relative to them. | [simonepri](https://github.com/simonepri/)/[Y_Less](https://github.com/Y-Less/) |  |
SPECIAL_ACTION_PISSING | Define it. | [simonepri](https://github.com/simonepri/) |  |
IsValidVehicle | "IsValidVehicle" isn't defined by default. | [simonepri](https://github.com/simonepri/) |  |
ApplyAnimation | Passing an invalid animation library in ApplyAnimation causes a client crash for streamed in players. | [simonepri](https://github.com/simonepri/) |  |
ApplyAnimation_2 | When ApplyAnimation was called the first time next the player spawn, it don't work. | [simonepri](https://github.com/simonepri/) |  |
OnPlayerSpawn | San Andreas deducts $100 from players. | [Y_Less](https://github.com/Y-Less/) |  |
GetGravity | "GetGravity" isn't defined by default. | [Whitetiger](https://github.com/Whitetigerswt/) | [Link](http://forum.sa-mp.com/showpost.php?p=1706447) |
gpci | "gpci" isn't defined by default. | [simonepri](https://github.com/simonepri/) | [Link](http://pastebin.com/VQSGpbSm) |
Natives | Several natives are included by default, this enables or disables them all. Therefore this is an umbrella fix for several fixes. | [Y_Less](https://github.com/Y-Less/) |  |
OnPlayerConnect | This function isn't called for players when a filterscript starts. | [Y_Less](https://github.com/Y-Less/) |  |
OnPlayerDisconnect | This function isn't called for players when a filterscript ends. | [Y_Less](https://github.com/Y-Less/) |  |
GameText | Several styles do not display for the time specified. | [Y_Less](https://github.com/Y-Less/) |  |
GameTextStyles | San Andreas has fixed styles for area and vehicle names, but they are not included in the GameText styles list. | [Y_Less](https://github.com/Y-Less/) |  |
HideGameText | There is no "HideGameTextForXYZ" function. | [Y_Less](https://github.com/Y-Less/) |  |
BODYPARTS | The bodyparts to be used in OnPlayer(Take/Give)Damage are not defined by default | [Whitetiger](https://github.com/Whitetigerswt/) |  |
CAMERAMODES | The camera modes for GetPlayerCameraMode are not defined by default. | [Whitetiger](https://github.com/Whitetigerswt/) | [Link](http://forum.sa-mp.com/showpost.php?p=1309730) |  |
SetPlayerCamera | Using the camera functions directly after enabling spectator mode doesn't work. | [Emmet_](https://github.com/emmet-jones/) |  |
SetPlayerTime | Using this function under "OnPlayerConnect" doesn't work. | [Emmet_](https://github.com/emmet-jones/) |  |
OnPlayerRequestClass | Random blunts and bottles sometimes appear in class selection. | [Y_Less](https://github.com/Y-Less/) |  |
SetPlayerColor | If used under OnPlayerConnect, the affecting player will not see the color in the TAB menu. | [Emmet_](https://github.com/emmet-jones/) | [Link](http://forum.sa-mp.com/showthread.php?t=452407) |  |
FileMaths | You can write gibberish like "File:a; ++a;". | [Y_Less](https://github.com/Y-Less/) |  |
GetPlayerWeaponData | Old weapons with no ammo left are still returned. | [Y_Less](https://github.com/Y-Less/) | [Link](http://forum.sa-mp.com/showthread.php?t=567400) |  |

# Options

There are a few options for improved execution of this script. Define these symbols as "1" before you include fixes.inc (remove them or set them to 0 to disable them):
- FIXES_Single - You only have one script running (no filterscripts), simplify the code.
- FIXES_SilentKick - When a player is kicked for illegal mods/vehicles, don't send them a message.
- FIXES_Debug - Additional information in the server console.

A few fixes are disabled by default, to enable them all do:
```Pawn
#define FIX_GetPlayerDialog 1 // Adds a new function, not really the point of this include.
#define FIX_random 1 // I don't think negative numbers not working is a bug.
#define FIX_file_inc 1 // This will enable all the "fwhatever" fixes.
#define FIX_HideMenuForPlayer_2 1 // Hide a specific menu, not just whatever the current one is.
```

# Expansion

The file is fairly well documented, with a list of the currently (hopefully) fixed bugs at the top. If you know of others, or have solutions for others, it would be greatly appreciated if you could post them in this topic (following the structure already laid out). The fixes also need extensive testing to find bugs in the fixes.

Again, this is a community project, merely managed by [Y_Less](https://github.com/Y-Less/) - if anyone has comments, contributions, criticisms etc. please post them in this topic. This includes additions to source code, documentation, presentation, translations (mainly of this post - multiple versions of the include should be avoided to reduce fragmentation), or any other related area you can think of.

# Other Fixes

There are a few other includes which aim to fix issues too large to be included here:

- [Fixes2](http://forum.sa-mp.com/showthread.php?t=571505) - [Y_Less](https://github.com/Y-Less/) fixes to make "SetTimer" and "SetTimerEx" and other.
- [SQLitei](http://forum.sa-mp.com/showthread.php?t=303682) - [Slice](https://github.com/oscar-broman/)'s fixes and improvements for many SQLite functions
- [Timer Fix](http://forum.sa-mp.com/showthread.php?t=289675) - [Slice](https://github.com/oscar-broman/)'s fixes to make "SetTimer" and "SetTimerEx" vastly more accurate in their delays.

# Bugs

*Originally Posted by [Y_Less](https://github.com/Y-Less/):*
> [This] is beta software written by a small team in their spare time, thus it has bugs (as does all software).
This software is explicitly designed to solve bugs, not cause them, but there may still be bugs.

The most likely cause of bugs is certain combinations of disabled fixes. Some fixes are inter-mixed and while they SHOULD work when the fixes they are combined with are disabled, not every combination has been tested. There are literally billions of possible combinations - if you find one that doesn't compile or work, please tell us.
