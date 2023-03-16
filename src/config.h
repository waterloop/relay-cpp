#pragma once

#include <netinet/in.h>

struct Config {
    int tcp_sockfd;
    struct sockaddr_in tcp_address;
};

struct Config config_default(void);

struct Config from_args(char *args[]);