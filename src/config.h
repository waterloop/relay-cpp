#ifndef CONFIG_H
#define CONFIG_H

#include <netinet/in. h>

struct config {
    int tcp_sockfd;
    struct sockaddr_in tcp_address;
};

struct config default();

struct config from_args(char *args[]);

#endif // CONFIG_H