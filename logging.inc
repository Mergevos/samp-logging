// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_logging
    #undef _inc_logging
#endif
// custom include-guard to ensure we don't duplicate
#if defined _@logging_included
    #endinput
#endif
#define _@logging_included

#include <a_samp>

#if !defined MAX_FIELDS 
    #define MAX_FIELDS 64
#endif

#if !defined MAX_FIELD_SIZE
    #define MAX_FIELD_SIZE 128
#endif
// --------------------------------------

/* 
 * <summary> Used to toggle debug handle state</summary>
 * <param name="debug[]">Debug to turn off or on</param>
 * <param name="bool: on"> State to turn on or off</param>
 */

stock Log_ToggleHandle(const dbg[], bool: on)
{
    return (on != false) ? SetSVarInt(dbg, 1) : SetSVarInt(dbg, 0);
}

/* 
 * <summary>Used to get debug handle state</summary>
 * <param name="debug[]">Debug</param>
 */ 

stock bool: Log_GetHandleStatus(const dbg[])
{
    return GetSVarInt(dbg) != 0 ? true : false;
}

//-----------------------------------
/*
 * <summary> Field representing string</summary>
 * <param name=field[]> Log field</param>
 * <param name=data[]> data of field</param>
 */

stock Logging_Field: Log_Field_s(const field_name[], const data[])
{
    static 
        field[MAX_FIELD_SIZE];
    format(field, sizeof(field), "Field: %s = \"%s\"", field_name, data);
    return Logging_Field: field;
}

/*
 * <summary> Field representing float</summary>
 * <param name=field[]> Log field</param>
 * <param name=data> data of field</param>
 */

stock Logging_Field: Log_Field_f(const field_name[], Float: data)
{
    static 
        field[MAX_FIELD_SIZE];
    format(field, sizeof(field), "Field: %s = %f", field_name, data);
    return Logging_Field: field;
}

/*
 * <summary> Field representing integer</summary>
 * <param name=field[]> Log field</param>
 * <param name=data> data of field</param>
 */

stock Logging_Field: Log_Field_i(const field_name[], data)
{
    static 
        field[MAX_FIELD_SIZE];
    format(field, sizeof(field), "%s = %d", field_name, data);
    return Logging_Field: field;
}

/*
 * <summary> Field representing binary</summary>
 * <param name=field[]> Log field</param>
 * <param name=data> data of field</param>
 */

stock Logging_Field: Log_Field_b(const field_name[], data)
{
    static 
        field[MAX_FIELD_SIZE];
    format(field, sizeof(field), "%s = %b", field_name, data);
    return Logging_Field: field;
}

/*
 * <summary> Field representing hex</summary>
 * <param name=field_name[]> Log field</param>
 * <param name=data> data of field</param>
 */

stock Logging_Field: Log_Field_x(const field_name[], data)
{
    static 
        field[MAX_FIELD_SIZE];
    format(field, sizeof(field), "%s = %x", field_name, data);
    return Logging_Field: field;
}


//------------------------------------------------------------------
/*
 * <summary> Logs a debug message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=Logging_Field:...> Logging fields</param>
 */

stock Log_Debug(const handle[], const fmt[], const filename[], line, Logging_Field: ...)
{

    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];

    if(numargs() == 4 || !Log_GetHandleStatus(handle)) {
        return;
    }

    for(new args = 4; args < numargs() && args < MAX_FIELDS; ++args) {
		new 
            field[MAX_FIELD_SIZE];
		for(new idx; idx < MAX_FIELD_SIZE; ++idx) {
			field[idx] = getarg(args, idx);
			if(field[idx] == EOS) {
                strcat(Str, " | ");
				strcat(Str, field);
				break;
			}
		}
	}

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s [%s] | DEBUG LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s%s", filename, handle, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], fmt, Str);
        
}

/*
 * <summary> Logs an info message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=Logging_Field:...> Logging fields</param>
 */

stock Log_Info(const handle[], const fmt[], const filename[], line, Logging_Field: ...)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];

    if(numargs() == 4 || !Log_GetHandleStatus(handle)) {
        return;
    }

    for(new args = 4; args < numargs() && args < MAX_FIELDS; ++args) {
		new 
            field[MAX_FIELD_SIZE];
		for(new idx; idx < MAX_FIELD_SIZE; ++idx) {
			field[idx] = getarg(args, idx);
			if(field[idx] == EOS) {
                strcat(Str, " | ");
				strcat(Str, field);
				break;
			}
		}
	}

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s [%s] | DEBUG LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s%s", filename, handle, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], fmt, Str);
     
}

/*
 * <summary> Logs an error message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=Logging_Field:...> Logging fields</param>
 */

stock Log_Error(const handle[], const fmt[], const filename[], line, Logging_Field: ...)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];

    if(numargs() == 4 || !Log_GetHandleStatus(handle)) {
        return;
    }

    for(new args = 4; args < numargs() && args < MAX_FIELDS; ++args) {
		new 
            field[MAX_FIELD_SIZE];
		for(new idx; idx < MAX_FIELD_SIZE; ++idx) {
			field[idx] = getarg(args, idx);
			if(field[idx] == EOS) {
                strcat(Str, " | ");
				strcat(Str, field);
				break;
			}
		}
	}

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s [%s] | ERROR LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s%s", filename, handle, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], fmt, Str);
}

/*
 * <summary> Logs an usage message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=Logging_Field:...> Logging fields</param>
 */

stock Log_Usage(const handle[], const fmt[], const filename[], line, Logging_Field: ...)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];

    if(numargs() == 4 || !Log_GetHandleStatus(handle)) {
        return;
    }

    for(new args = 4; args < numargs() && args < MAX_FIELDS; ++args) {
		new 
            field[MAX_FIELD_SIZE];
		for(new idx; idx < MAX_FIELD_SIZE; ++idx) {
			field[idx] = getarg(args, idx);
			if(field[idx] == EOS) {
                strcat(Str, " | ");
				strcat(Str, field);
				break;
			}
		}
	}

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s [%s] | INCORRECT PARAMS LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s%s", filename, handle, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], fmt, Str);
}

