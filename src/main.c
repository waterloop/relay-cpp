#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

void main()
{
    int sock = make_socket(2410, "");

    // listen for connect() requests, backlog = default
    listen(sock, 0);

    // accept connect() request (don't care about client address)
    int newsockfd = accept(sock, NULL, NULL);
    // get client message
    uint8_t message[256] = { 0 };
    int n = recv(newsockfd, message, sizeof(message)-1, 0);
    printf("client said: %s\n", message);
    // reply
    char reply[] = "goodbye";
    n = send(newsockfd, reply, sizeof(reply), 0);
    close(newsockfd);
    close(sock);
    return;
}

int make_socket(uint16_t port, char *hostname)
{
    int sock;
    struct sockaddr_in addr;

    /* create TCP socket */
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("socket");
      exit(EXIT_FAILURE);
    }

    /* Bind socket to port */
    if (hostname && !hostname[0]) init_sockaddr(&addr, port);
    else init_sockaddr_hostname(&addr, hostname, port);

    int bind_success = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_success < 0) {
      perror("bind");
      exit(EXIT_FAILURE);
    }

    return sock;
}

/*initalizes the sockaddr_in structure with port number, accepting any incomming message to the port*/
void init_sockaddr (struct sockaddr_in *addr,
               uint16_t port)
{
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = htonl(INADDR_ANY);
}

/*initalizes the sockaddr_in structure with hostname string and port number*/
void init_sockaddr_hostname (struct sockaddr_in *addr,
               const char *hostname,
               uint16_t port)
{
    struct hostent *hostinfo;

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "Unknown host %s.\n", hostname);
        exit (EXIT_FAILURE);
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr = *(struct in_addr *) hostinfo->h_addr_list[0];
}