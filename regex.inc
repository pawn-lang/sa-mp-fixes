#if defined _ALS_CreateActor
	#error _ALS_CreateActor defined
#endif
native BAD_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
native CreateActor__(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
native FIXES_CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle) = CreateActor;
#define _ALS_CreateActor
#define CreateActor( FIXES_CreateActor(

native CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle);

native (\w+:)?(\w+)(.*)\);\n


#if defined _ALS_\2\n\t#error _ALS_\2 defined\n#endif\nnative \1BAD_\2\3\) = \2;\nnative \1FIXES_\2\3\) = \2;\nnative \1\2__\3\) = \2;\n#define _ALS_\2\n#define \2( FIXES_\2(\n\n

