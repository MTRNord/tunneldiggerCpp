//
// Created by marce on 22.09.2017.
//

#ifndef TUNNELDIGGER_BROKER_BROKER_H
#define TUNNELDIGGER_BROKER_BROKER_H


class broker {
    public:
        class TunnelManager {
            public:
                TunnelManager(char * nspaceL);
                int initialize();
            private:
                //Namespace is a taken var name in C++ so I use nspace isntead
                char * nspace;
        };
};


#endif //TUNNELDIGGER_BROKER_BROKER_H
