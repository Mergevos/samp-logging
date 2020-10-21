#include <a_samp>
#include <logging>

main()
{
    Log_Info("Main", "test.pwn", 6);
}

public OnGameModeInit()
{
    Log_Debug("Started On GameMode tetku", "test.pwn", 11);
    Log_DebugEx("Started On GameMode tetku u guz", "test.pwn", 12, "TestDebugLog.txt");
    Log_Error("Just for test", "test.pwn", 13);
    Log_Usage("[Just for test] Command usage /%s [playerid]", "test.pwn", 14, "testcommand");
    Log_DebugEx("Started On GameMode tetku u guz", "test.pwn", 15, "TestDebugLog.txt");
    return 1;
}