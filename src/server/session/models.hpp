#ifndef SESSION_SRV_MODELS_H
#define SESSION_SRV_MODELS_H

#include "../../common/session/models.hpp"
#include <arpa/inet.h>
#include <memory>
#include <netinet/in.h>
#include <string>


using namespace std;

class UserStore;

class Connection {
public:
    SessionType session_type;
    string      address;
    int         port;
    pthread_t  *thread_id;
    int         channel;
    int         pipe_fd[2];

    Connection(char *address, int port, int channel, int *pipe_fd);
    void   set_thread_id(pthread_t *thread_id);
    string get_full_address();
    void   set_session_type(SessionType session_type);
    void   get_conection_info();
};

#endif
