#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <cstring>
#include <regex>
#include <memory>

#include "models.hpp"
#include "../../common/session/models.hpp"


Connection::Connection(char *address, int port, int channel) {
    this->address = (char *)malloc(strlen(address) * sizeof(char));
    strcpy(this->address, address);
    this->port = port;
    this->channel = channel;
}

Connection::~Connection(void) {
    free(this->address);
}

void Connection::set_thread_id(pthread_t *thread_id) {
    this->thread_id = thread_id;
}

void Connection::set_session_type(SessionType session_type) {
    this->session_type = session_type;
}

string Connection::get_full_address() {
    ostringstream oss;
    oss << this->address << ":" << this->port;
    std::string conn_info = oss.str();
    return conn_info;
}
