#ifndef INOTIFY_H
#define INOTIFY_H
// usar sempre snake case para nomear as variaveis
#include <memory>
#include <sys/inotify.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <memory>
#include <cstring>
using namespace std;

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUFFER_LEN (1024*(EVENT_SIZE+16))

class Inotify{
    const char *folder_path;
    int file_descriptor;
    int watch_descriptor;
    public:
        Inotify(const char *folder_path);
        int get_file_descriptor();
        int get_watch_descriptor();
        void read_event();
        void closeInotify();
    };
#endif