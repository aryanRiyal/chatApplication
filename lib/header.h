//Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/un.h>
#include <time.h>
#include <errno.h>

//Macros
#define MB 1024
#define MAXLINE 4096
#define MAXBUFF 8192
#define SERVER_PORT 9999
#define BACKLOG 10
#define MAX_NAME_SIZE 20
#define NO_OF_CLIENTS 10

#define SA struct sockaddr

//Data Structure
struct client {
    char cname[MAX_NAME_SIZE];
    char cahtWith[MAX_NAME_SIZE];
    int chatWithFD;
    int fileDes;
    int port;
    char ip[INET_ADDRSTRLEN];
};

struct serverData {
    int totalClient;
    struct client clientList[NO_OF_CLIENTS];
};

struct serverData server;


//Function Declarations
int Socket( int family, int type, int protocol);
int Connect( int sockfd, SA *addr, socklen_t addrlen);
int Bind( int sockfd, SA *addr, socklen_t addrlen);
int Listen( int sockfd, int backlog);
int Accept( int sockfd, SA *addr, socklen_t *addrlen);
// ssize_t Write( int sockfd, void *buff, size_t count);
// ssize_t Read( int sockfd, void *buff, size_t count);
int Send( int sockfd, const void *buff, size_t length, int flags);
int Recv( int sockfd, void *buff, size_t length, int flags);
void createServerSocket( int *listenfd);
void createClientSocket( int *sockfd, char *IP);
void clientHandle( int listenfd, int *newSocketfd);
// void exitClient( char *buff);
void serverRecv( int listenfd, char *buff);
void serverSend( int listenfd, char *buff);
>>>>>>> 815011d6d58794298c690ac19861e4b3c4b8c543
