//Header
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/errno.h>
#include<fcntl.h>

//Macros
#define MB 1024
#define MAXLINE 4096
#define MAXBUFF 8192
#define SERVER_PORT 9999
#define BACKLOG 10
#define MAX_NAME_SIZE 20
#define NO_OF_CLIENTS 10
#define CONNECTED "Connection Established..."

#define SA struct sockaddr

//Data Structure
struct client {
    char cname[MAX_NAME_SIZE];
    char chatWith[MAX_NAME_SIZE];
    int chatWithfd;
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
// ssize_t Write( int sockfd, sockaddr_invoid *buff, size_t count);
// ssize_t Read( int sockfd, void *buff, size_t count);
int Send( int sockfd, const void *buff, size_t length, int flags);
int Recv( int sockfd, void *buff, size_t length, int flags);
void createServerSocket( int *listenfd);
void createClientSocket( int *sockfd, char *IP);
void clientHandle( int listenfd, int *newSocketfd);
// void exitClient( char *buff);
void serverRecv( int listenfd, char *buff);
void serverSend( int listenfd, char *buff);
int processRecvData(int socket,char *buffer);
int findClientIndexName( char *name);
int findClientIndexList( int socket);
void serverSelect(int maxfd,int listenfd,fd_set *readset,fd_set *writeset);
int clientSelect(int maxfd,int sockfd,fd_set *readset,fd_set *writeset);
void addNewClient(struct sockaddr_in clientInfo,int newSocketfd);
void Select(int maxfd,fd_set *readset,fd_set *writeset,fd_set *exceptset,struct timeval *timeout);
void clientRecv( int listenfd, char *buff);
void clientSend( int listenfd, char *buff);
int clientBuildfdsets( int listenfd,fd_set *readset, fd_set *writeset, fd_set *exceptset);
int serverBuildfdsets( int listenfd,fd_set *readset, fd_set *writeset, fd_set *exceptset);
