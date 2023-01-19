#include"header.h"

/* send() */
int Send( int sockfd, const void *buff, size_t length, int flags){
    int n = send( sockfd, buff, length, flags);
    if(n < 0){
        fprintf( stderr,"[-]send() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}

/* recv() */
int Recv( int sockfd, void *buff, size_t length, int flags){
    int n = recv( sockfd, buff, length, flags);
    if(n < 0){
        fprintf( stderr,"[-]recv() error with error number : %d\n", errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}

void serverRecv( int listenfd, char *buff){
    int readBytes = 0;
    memset( buff, '\0', sizeof(buff));

    readBytes = Recv( listenfd, buff, sizeof(buff), 0);
    // processRecvData();
}

void serverSend( int listenfd, char *buff){
    int writeBytes = 0;
    memset( buff, '\0', sizeof(buff));

    writeBytes = Send( listenfd, buff, sizeof(buff), 0);
    // processRecvData();
    printf("\n[CLIENT : %d] || Wrote [%d] number of bytes || BYTES = [%s]\n", listenfd, writeBytes, buff);
}
