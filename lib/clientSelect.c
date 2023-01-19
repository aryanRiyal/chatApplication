#include "header.h"

int clientSelect(int maxfd, int listenfd, fd_set *readset, fd_Set writeset){
    char buff[MB];
    memset( buff, '\0', sizeof(buff));
    
    int action = select( maxfd+1, readset, writeset, NULL, NULL);

    if( action == -1 || action == 0) {
        perror("clientSelect() ERROR");
        exit(0);
    }

    if(FD_ISSET(listenfd, readset)){
        clientRecv( listenfd, buff);
    }

    if(FD_ISSET(listenfd, readset)){
        clientSend( listenfd, buff);
    }

    return 0;
}
