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

/**\n * <remarks>The original declaration as in the basic SA:MP includes.</remarks>.\n */\n




\n\n\n\n

native (\w+:)?(\w+)(.*);\n
/**\n * <remarks>\n *   The original declaration as in the basic SA:MP includes.\n * </remarks>\n */\nnative \1BAD_\2\3 = atan2;\n/**\n * <remarks>\n *   An optionally improved declaration with <c>const</c> and <c>bool:</c>.\n * </remarks>\n */\nnative \1CST_\2\3 = atan2;\n/**\n * <remarks>\n *   The best declaration with all fixes aways applied.\n * </remarks>\n */\nnative \1\2__\3 = atan2;\n#if defined _ALS_\2\n	// Previous hook.\n	#define _ALS_\2__\n	#define \2__\( \2\(\n#endif\n


