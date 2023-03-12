#include "config.h"
#include <sys/socket.h>

struct Config config_default(void) { 
    struct Config c = {
        .tcp_sockfd = socket(AF_INET, SOCK_STREAM, 0),
        .tcp_address = {
            .sin_family = AF_INET,
            .sin_port = htons(8080),
            .sin_addr.s_addr = htonl(INADDR_ANY)
        }
    };
    // int flag = 1;
    // setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    bind(c.tcp_sockfd, (struct sockaddr *)&c.tcp_address, sizeof(c.tcp_address));
    return c;
}

