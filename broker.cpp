//
// Created by marce on 22.09.2017.
//

#ifdef linux
    #include "broker.h"
    #include <iostream>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <errno.h>
    #include <stdlib.h>

    using namespace std;

    broker::TunnelManager::TunnelManager(const char * nspaceL) {
        nspace = nspaceL;
    }

    int broker::TunnelManager::initialize() {
        printf("Prepare Routing");

        char * prerouting_chain = (char *) printf("L2TP_PREROUTING_%s", nspace);
        char * postrouting_chain  = (char *) printf("L2TP_POSTROUTING_%s", nspace);

        pid_t pid;
        int status;
        pid_t ret;
        char *const args[3] = {"iptables", "--version", NULL};
        char **env;
        extern char **environ;

        /* ... Sanitize arguments ... */

        pid = fork();
        if (pid == -1) {
            /* Handle error */
        } else if (pid != 0) {
            while ((ret = waitpid(pid, &status, 0)) == -1) {
                if (errno != EINTR) {
                    /* Handle error */
                    break;
                }
            }
            if ((ret != -1) &&
                (!WIFEXITED(status) || !WEXITSTATUS(status)) ) {
                /* Report unexpected child status */
            }
        } else {
            if (execve("iptables", args, env) == -1) {
                /* Handle error */
                _Exit(127);
            }
        }

        return 0;
    }
#endif