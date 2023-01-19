#include "header.h"

int clientSelect(int maxfd, int listenfd, fd_set *readset, fd_set *writeset){
    char buff[MB];
    
    int action = select( maxfd+1, readset, writeset, NULL, NULL);

    if( action == -1 || action == 0) {
        perror("clientSelect() ERROR");
        exit(0);
    }

    memset( buff, '\0', sizeof(buff));
    if(FD_ISSET(listenfd, readset)){
        clientRecv( listenfd, buff);
    }

    if(FD_ISSET(STDIN_FILENO, readset)){
	    if(read(0,buff,sizeof(buff)) > 0){
        	clientSend( listenfd, buff);
		}
    }

    return 0;
}
