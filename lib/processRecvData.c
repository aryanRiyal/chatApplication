#include "header.h"
//processing the received data from clients

//find index of the client data structure from client socket
int findClientIndexList( int socket) {
    int index = 0;
    for(int i = 0; i<server.totalClient; i++) {
           if(server.clientList[i].fileDes == socket) {
               index =i;
           }
    }
    return index;
}

//find index of the client data structure from client name
int findClientIndexName( char *name) {
    int index = 0;
    for(int i = 0; i<server.totalClient; i++) {
           if(strcmp(server.clientList[i].cname,name) == 0) {
               index =i;
           }
    }
    return index;
}

int processRecvData( int socket, char *buffer) {
    char connectedClient[MB];
    char bufferSend[MB] = {0};
    int indexSender = 0;
    int indexReceiver = 0;
    int len = 0;
    indexSender = findClientIndexList(socket);

    //MENU
    if(strncmp( buffer, "LIST", 4) ==0) {
         memset( buffer, 0, sizeof(buffer));
         for(int i=0;i<server.totalClient;i++) {
             strcat( buffer, server.clientList[i].cname);
             strcat( buffer,"; ");
         }
        serverSend( socket, buffer);
        return 0;
    }
    if(strncmp(buffer, "CONNECT",7) == 0) {
        
        sscanf(buffer,"%*[^:]:%s", connectedClient);
        strcpy(server.clientList[indexSender].chatWith, connectedClient);
       
        indexReceiver = findClientIndexName( server.clientList[indexSender].chatwith);
        server.clientList[indexSender].chatwithfd = server.clientList[indexReceiver].fileDes;
        serverSend( server.clientList[indexSender].fileDes, CONNECTED);
        return 0;
    }

    if(strlen( server.clientList[indexSender].chatwith) != 0){
        snprintf( bufferSend, sizeof(bufferSend),"[%s] : %s", server.clientList[indexSender].cname, buffer);
        printf( "Buffer  =%s\n",bufferSend);
        serverSend( server.clientList[indexSender].chatwithfd, bufferSend);
    }
    return 0;
}
