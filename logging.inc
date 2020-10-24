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
#include <YSI_Coding\y_va>

/*
 * <summary> Logs a debug message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_Debug(const fmt[], const filename[], line, va_args<>)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];

    va_format(Str, sizeof(Str), fmt, va_start<3>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | DEBUG LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
}

/*
 * <summary> Logs an info message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_Info(const fmt[], const filename[], line, va_args<>)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];
    va_format(Str, sizeof(Str), fmt, va_start<3>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | INFO LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
}

/*
 * <summary> Logs an error message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_Error(const fmt[], const filename[], line, va_args<>)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];
    va_format(Str, sizeof(Str), fmt, va_start<3>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | ERROR LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
}

/*
 * <summary> Logs an usage message</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_Usage(const fmt[], const filename[], line, va_args<>)
{
    new 
        Str[256],
        Date_Info[3],
        Time_Info[3];
    va_format(Str, sizeof(Str), fmt, va_start<3>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | INCORRECT PARAMS LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
}

/*
 * <summary> Logs a debug message and outputs it in a file</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=file[]> Output file for log</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_DebugEx(const fmt[], const filename[], line, const file[], va_args<>)
{
    new 
        Str[256],
        FileStr[40],
        Date_Info[3],
        Time_Info[3],
        File: Log_File = fopen(file, io_append);
    
    va_format(Str, sizeof(Str), fmt, va_start<4>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | DEBUG LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    format(FileStr, sizeof(FileStr), "%s | DEBUG LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s\n", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    fwrite(Log_File, FileStr);
    fclose(Log_File);
}

/*
 * <summary> Logs an info message and outputs it in a file</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=file[]> Output file for log</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_InfoEx(const fmt[], const filename[], line, const file[], va_args<>)
{
    new 
        Str[256],
        FileStr[40],
        Date_Info[3],
        Time_Info[3],
        File: Log_File = fopen(file, io_append);
    
    va_format(Str, sizeof(Str), fmt, va_start<4>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | INFO LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    format(FileStr, sizeof(FileStr), "%s | INFO LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s\n", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    fwrite(Log_File, FileStr);
    fclose(Log_File);
}

/*
 * <summary> Logs an error message and outputs it in a file</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=file[]> Output file for log</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_ErrorEx(const fmt[], const filename[], line, const file[], va_args<>)
{
    new 
        Str[256],
        FileStr[40],
        Date_Info[3],
        Time_Info[3],
        File: Log_File = fopen(file, io_append);
    
    va_format(Str, sizeof(Str), fmt, va_start<4>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | ERROR LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    format(FileStr, sizeof(FileStr), "%s | ERROR LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s\n", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    fwrite(Log_File, FileStr);
    fclose(Log_File);
}

/*
 * <summary> Logs an usage message and outputs it in a file</summary>
 * <param name=fmt[]> Text to log</param>
 * <param name=filename[]> Name of the file being logged</param>
 * <param name=line> Line which is being logged</param>
 * <param name=file[]> Output file for log</param>
 * <param name=va_args> Other arguments</param>
 */

stock Log_UsageEx(const fmt[], const filename[], line, const file[], va_args<>)
{
    new 
        Str[256],
        FileStr[40],
        Date_Info[3],
        Time_Info[3],
        File: Log_File = fopen(file, io_append);
    
    va_format(Str, sizeof(Str), fmt, va_start<4>);

    getdate(Date_Info[2], Date_Info[1], Date_Info[0]);
    gettime(Time_Info[2], Time_Info[1], Time_Info[0]);
    printf("%s | INCORRECT PARAMS LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    format(FileStr, sizeof(FileStr), "%s | INCORRECT PARAMS LINE %d: %02d-%02d-%d %02d:%02d:%02d - %s\n", filename, line, Date_Info[0], Date_Info[1], Date_Info[2], Time_Info[2], Time_Info[1], Time_Info[0], Str);
    fwrite(Log_File, FileStr);
    fclose(Log_File);
}