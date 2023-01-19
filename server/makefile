CC = gcc 
LIBPATH = ../lib/
LIB = createServerSocket.o  serverRecvSend.o clientHandle.o
HEADER = $(LIBPATH)header.h

runS: server.o $(LIB)
	$(CC) -o runS server.o $(LIB)

server.o: server.c $(HEADER)
	$(CC) -c server.c

createServerSocket.o: $(LIBPATH)createServerSocket.c $(HEADER)
	$(CC) -c $(LIBPATH)createServerSocket.c

serverRecvSend.o: $(LIBPATH)serverRecvSend.c $(HEADER)  
	$(CC) -c $(LIBPATH)serverRecvSend.c

clientHandle.o: $(LIBPATH)clientHandle.c  $(HEADER)         
	$(CC) -c $(LIBPATH)clientHandle.c

clean: 
	rm $(LIB) server.o runS



