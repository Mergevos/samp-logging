/*
	* Library: Samp Logging (logging.inc)
	* Author: Mergevos
	* Date: 1. Novembre 2020.
	* Copyright: (C) 2020
	* Credits: 
        Southclaws - discord discussions and looping through arguments
*/


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

#if !defined __PawnBuild
	#error I think it's time for you to use community compiler. Get it from https://github.com/pawn-lang/compiler
#endif
#define Log_Debug(%0,%1,%2) __debug_PP(__file, __line, "DEBUG", %0, %1, Logging_Field:%2)
#define Log_Info(%0,%1,%2) __debug_PP(__file, __line, "INFO", %0, %1, Logging_Field:%2)
#define Log_Error(%0,%1,%2) __debug_PP(__file, __line, "ERROR", %0, %1, Logging_Field:%2)
#define Log_Usage(%0,%1,%2) __debug_PP(__file, __line, "INCORECT PARAMS", %0, %1, Logging_Field:%2)
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
    format(field, sizeof(field), "[%s = \"%s\"]", field_name, data);
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
    format(field, sizeof(field), "[%s = %f]", field_name, data);
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
    format(field, sizeof(field), "[%s = %d]", field_name, data);
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
    format(field, sizeof(field), "[%s = %b]", field_name, data);
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
    format(field, sizeof(field), "[%s = %x]", field_name, data);
    return Logging_Field: field;
}


//------------------------------------------------------------------
/*
 * <summary> Logs a debug message</summary>
 * <param name=handle[]> Debug handle</param>
 * <param name=message[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=Logging_Field:...> Logging fields</param>
 */

stock __debug_PP(const filename[], line, const level[], const handle[], const message[], Logging_Field: ...)
{

    new 
        fieldstring[256],
        date_Info[3],
        time_Info[3];

    if(numargs() == 5 || !Log_GetHandleStatus(handle)) {
        return;
    }

    for(new args = 5; args < numargs() && args < MAX_FIELDS; ++args) {
		new 
            field[MAX_FIELD_SIZE];
		for(new idx; idx < MAX_FIELD_SIZE; ++idx) {
			field[idx] = getarg(args, idx);
			if(field[idx] == EOS) {
                strcat(fieldstring, " | ");
				strcat(fieldstring, field);
				break;
			}
		}
	}
    getdate(date_Info[2], date_Info[1], date_Info[0]);
    gettime(time_Info[2], time_Info[1], time_Info[0]);
    printf("%s[%s] | %s LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s%s", filename, handle, level, line, date_Info[0], date_Info[1], date_Info[2], time_Info[2], time_Info[1], time_Info[0], message, fieldstring);
    
}
