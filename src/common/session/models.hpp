#ifndef SESSION_CMN_MODELS_H
#define SESSION_CMN_MODELS_H

#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <netinet/in.h>

using namespace std;

enum SessionType {
    Unknown,
    FileExchange,
    CommandPublisher,
    CommandSubscriber,
    ServerSync,
};

static const map<SessionType, string> session_type_map = {
    {CommandPublisher, "subscriber"},
    {CommandSubscriber, "publisher"},
    {FileExchange, "file_exchange"},
    {ServerSync, "sync_backup"},
};

class SessionRequest {
public:
    SessionType type;
    string      username;
    uint16_t    uname_s;

    SessionRequest(uint8_t *bytes);
    SessionRequest(SessionType type, string username);
    size_t to_bytes(uint8_t **bytes_ptr);
};

#endif
