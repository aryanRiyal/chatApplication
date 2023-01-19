$(CC) = gcc 

runS: server.o createServerSocket.o serverRecvSend.o clientHandle.o
    $(CC) -o runS server.o createServerSocket.o serverRecvSend.o clientHandle.o

server.o: server.c
    $(CC) -c server.c

createServerSocket.o: ../lib/createServerSocket.c ../lib/header.h
    $(CC) -c ../lib/createServerSocket.c

serverRecvSend.o: ../lib/serverRecvSend.c ../lib/header.h  
    $(CC) -c ../lib/serverRecvSend.c

clientHandle.o: ../lib/clientHandle.c  ../lib/header.h         
    $(CC) -c ../lib/clientHandle.c

.phony: clean

clean: 
	rm *.o
