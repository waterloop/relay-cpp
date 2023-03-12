#pragma once

#include <netinet/in.h>

struct config {
    int tcp_sockfd;
    struct sockaddr_in tcp_address;
};

struct config config_default(void);

struct config from_args(char *args[]);