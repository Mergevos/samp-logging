#include <a_samp>
#include "logging.inc"

main()
{
    return;
}

public OnGameModeInit()
{

    Log_ToggleHandle("test", true); // debug will print, handle on
    Log_Debug("test","Jebem mamuuuuuu",Log_Field_i("Kurac integer", 33), Log_Field_i("Kurac integer", 222));
    Log_Info("test","Jebem mamuuuuuu",Log_Field_i("Kurac integer", 33), Log_Field_s("Kurac integer", "nonwoinononoi"));
    Log_Error("test","Jebem mamuuuuuu",Log_Field_x("Kurac hex integer", 33), Log_Field_s("Kurac integer", "nonwoinononoi"));
    Log_ToggleHandle("test", false); // debug will not print, handle off
    Log_Usage("test","Jebem mamuuuuuu",Log_Field_i("Kurac integer", 33), Log_Field_s("Kurac integer", "nonwoinononoi"));
    return 1;
}