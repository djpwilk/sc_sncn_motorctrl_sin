

typedef struct S_CMD_VAR {
	int iMotCommand[16];
	int varx;
	int var1;
} cmd_data;



#ifdef __XC__
int input_cmd( cmd_data &d );
#endif
