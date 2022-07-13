#ifndef TOOLS
#define TOOLS
std::string get_os_name(void)
{
    /*return os name*/


    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
} 


void clear(void){

    /*wipe terminal screen*/

    std::string OS_NAME = get_os_name();

    if (OS_NAME=="Linux" || OS_NAME=="Unix" || OS_NAME=="Mac OSX" || OS_NAME=="FreeBSD"){
        // For all *nix machines.
        
        std::system("clear");
    }

    else if (OS_NAME=="Windows 32-bit" || OS_NAME=="Windows 64-bit"){

        std::system("cls");

    }

    else{
        // for all other os in the world.
        //std::system("your-command")

    }


}
#endif