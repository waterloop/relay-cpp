#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>


int main() { 
    int sockfd, new_sockfd;
    struct sockaddr_in server;
    char *msg = "Hello from server!\n";

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int flag = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

    // bind socket port > 1023
    server.sin_family = AF_INET;
    server.sin_port = htons(2410);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sockfd, (struct sockaddr *)&server, sizeof(server)); 

    // listen for connect() requests
    listen(sockfd, 0);

    while (1) {
        // accept client connection don't fill in there address information
        new_sockfd = accept(sockfd, NULL, NULL);

        // send msg to client
        send(new_sockfd, msg, strlen(msg), 0);

        // close the client socket (connected socket)
        close(new_sockfd);
    }
    
    // close the server socket
    close(sockfd);
}