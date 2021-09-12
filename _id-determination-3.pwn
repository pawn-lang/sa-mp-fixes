#pragma option -O1
#pragma option -d0

native setproperty(id, const name[], value, const string[]);

forward OnFilterScriptInit();

new const ID[] = "3";

public OnFilterScriptInit()
{
	#emit PUSH.C       4
	#emit PUSH.C       1
	#emit PUSH.C       ID
	#emit PUSH.C       5
	#emit PUSH.C       10
	#emit SYSREQ.C     setproperty
	#emit STACK        14
}


