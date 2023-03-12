#include "run_threads.h"
#include <unistd.h>
#include <string.h>

void run(struct config c) { 
    int new_sockfd;
    char *msg = "Hello from relay server!\n";
    listen(c.sockfd, 0);
    while (1) {        
        new_sockfd = accept(c.sockfd, NULL, NULL);
        send(new_sockfd, msg, strlen(msg), 0);
        close(new_sockfd);
    }
    close(c.sockfd);
}