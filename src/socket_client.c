#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void main() {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // enable quick re-use of server port
    int flag = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

    // bind socket to port 2410 (any port > 1023 is okay)
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(2410),
        .sin_addr.s_addr = htonl(INADDR_ANY)};

    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    // listen for connect() requests, backlog = default
    listen(sockfd, 0);

    // accept connect() request (don't care about client address)
    int newsockfd = accept(sockfd, NULL, NULL);
    // get client message
    uint8_t message[256] = { 0 };
    int n = recv(newsockfd, message, sizeof(message)-1, 0);
    printf("client said: %s\n", message);
    // reply
    char reply[] = "goodbye";
    n = send(newsockfd, reply, sizeof(reply), 0);
    close(newsockfd);
    close(sockfd);

    return;
}