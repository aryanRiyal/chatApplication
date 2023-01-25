#include"header.h"

void serverExitClient(int socketfdDel) {
    int i = 0;
    int index = 0;
    for(i=0;i<=server.totalClient;i++) {
        if(server.clientList[i].fileDes == socketfdDel) {
            for(index = i; index< server.totalClient;index++ ) {
                server.clientList[index] = server.clientList[index+1];
            }
            break;
        }
    }
    server.totalClient--;
    printf("Socket deleted  = [%d], totalclient = [%d]\n",socketfdDel,server.totalClient);
    close(socketfdDel);
}


