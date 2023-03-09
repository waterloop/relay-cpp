/**
* Socket client. Connects to server, says "hello" and prints reply.
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <netdb.h> // getaddrinfo()
#include <sys/socket.h> // socket(), connect(), send(), recv()
#include <unistd.h> // close()

int main(int argc, char *argv[]) {
    // lookup server address
    struct addrinfo hints = {
    .ai_family = AF_INET,
    .ai_socktype = SOCK_STREAM };
    struct addrinfo *server;
    getaddrinfo("localhost", "2410", &hints, &server);

    // create socket
    int sockfd = socket(server->ai_family, server->ai_socktype,
    server->ai_protocol);

    // connect to server
    connect(sockfd, server->ai_addr, server->ai_addrlen);

    // send message to server
    char message[] = "hello";
    int n = send(sockfd, message, sizeof(message), 0);

    // receive reply from
    uint8_t reply[256] = { 0 };
    n = recv(sockfd, reply, sizeof(reply)-1, 0);
    printf("server replied: %s\n", reply);
    freeaddrinfo(server);
    close(sockfd);
    
    return 0;
}