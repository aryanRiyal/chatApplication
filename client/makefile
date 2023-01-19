CC = gcc
LIBPATH = ../lib/
LIB = createClientSocket.o send_recv.o clientSelect.o clientBuildfdsets.o processRecvData.o

HEADER = $(LIBPATH)header.h

runC: client.o $(LIB)
	$(CC) client.o $(LIB) -o runC

client.o: client.c $(HEADER)
	$(CC) -c client.c

createClientSocket.o: $(LIBPATH)createClientSocket.c $(HEADER)  
	$(CC) -c $(LIBPATH)createClientSocket.c

send_recv.o: $(LIBPATH)send_recv.c $(HEADER)
	$(CC) -c $(LIBPATH)send_recv.c

clientBuildfdsets.o: $(LIBPATH)clientBuildfdsets.c $(HEADER)
	$(CC) -c $(LIBPATH)clientBuildfdsets.c

clientSelect.o: $(LIBPATH)clientSelect.c $(HEADER)
	$(CC) -c $(LIBPATH)clientSelect.c

processRecvData.o: $(LIBPATH)processRecvData.c $(HEADER)
	$(CC) -c $(LIBPATH)processRecvData.c

clean: 
	rm $(LIB) client.o runC
