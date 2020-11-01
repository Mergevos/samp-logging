#include <a_samp>
#include "logging.inc"

main()
{
    return;
}

public OnGameModeInit()
{
    Log_ToggleHandle("test", true); // debug will print, handle on
    Log_Debug("test", "Started On GameMode tetku", "test.pwn", 11, Log_Field_s("Jebem mamu", "Kurac"), Log_Field_s("Karam prasad", "Pickom mojom"), Log_Field_f("Test Float Num", 54.4),
        Log_Field_i("Kurac integer", 33), Log_Field_i("Another int", 33223+43*2));
    
    Log_Info("test", "Started On GameMode tetku", "test.pwn", 11, Log_Field_s("Jebem mamu", "Kurac"), Log_Field_s("Karam prasad", "Pickom mojom"), Log_Field_f("Test Float Num", 54.4),
        Log_Field_i("Kurac integer", 33));
    
    Log_Error("test", "Started On GameMode tetku", "test.pwn", 11, Log_Field_s("Jebem mamu", "Kurac"), Log_Field_s("Karam prasad", "Pickom mojom"), Log_Field_f("Test Float Num", 54.4),
        Log_Field_i("Kurac integer", 33));

    Log_ToggleHandle("test", false); // debug will not print, handle off
    
    Log_Usage("test", "Started On GameMode tetku", "test.pwn", 11, Log_Field_s("Jebem mamu", "Kurac"), Log_Field_s("Karam prasad", "Pickom mojom"), Log_Field_f("Test Float Num", 54.4),
        Log_Field_i("Kurac integer", 33), Log_Field_b("Kurac bin", 0), Log_Field_x("Kurac bin", 388));
    return 1;
}