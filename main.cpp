#ifdef linux
    #include <unistd.h>
    #include "libs/INIReader.h"
    #include "broker.h"
#endif
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    #ifdef linux
        string configFile= "../l2tp_broker.cfg.example";
        if (argc > 1) {
            if (string(argv[1]) != "") {
                configFile = argv[1];
            }else{
                std::cout << "Using example config" << endl;
            }
        }else{
            std::cout << "Using example config" << endl;
        }
        INIReader reader(configFile);

        if (reader.ParseError() < 0) {
            std::cout << "Can't load '"<< configFile << "'" << reader.ParseError() << endl;
            return 1;
        }
        std::cout << "Config loaded from '"<< configFile << "': address="
                  << reader.Get("broker", "address", "UNKNOWN") << ", port="
                  << reader.Get("broker", "port", "UNKNOWN") << endl;
        int uid=getuid(), euid=geteuid();
        if (uid<0 || uid!=euid) {
            /* We might have elevated privileges beyond that of the user who invoked
             * the program, due to suid bit. Be very careful about trusting any data! */

            broker::TunnelManager tunnelManager(c_str(reader.Get("broker", "namespace", "l2tp")));
            tunnelManager.initialize();
        } else {
            /* Anything goes. */
        }
        return 0;
    #else
        printf("You currently have to use Linux to run this. Other System support might eventually come in the future. :)\n");
        return 1;
    #endif
}