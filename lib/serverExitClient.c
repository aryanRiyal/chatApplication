#include"header.h"

void serverExitClient(int socketfdDel) {
    int i = 0;
    int index = 0;

    for(i=0;i<NO_OF_CLIENTS;i++) {
        if(server.clientList[i].fileDes == socketfdDel) {
            for(index = i; index<NO_OF_CLIENTS;index++ ) {
                server.clientList[index] = server.clientList[index+1];
            }
        }
    }

    server.totalClient--;
    printf("Socket deleted  = [%d]\n",socketfdDel);
    close(socketfdDel);
}


