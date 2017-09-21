#include <iostream>
using namespace std;

int main() {
    #ifdef linux
        int uid=getuid(), euid=geteuid();
        if (uid<0 || uid!=euid) {
            /* We might have elevated privileges beyond that of the user who invoked
             * the program, due to suid bit. Be very careful about trusting any data! */
        } else {
            /* Anything goes. */
        }
    #endif

    #ifdef _WIN32
        printf("You currently have to use Linux to run this. Windows support might eventually come in the future. :)\n");
    #endif

    return 0;
}