$(CC) = gcc
$(LIBPATH) = ../lib/
$(LIB) = createClientSocket.o  clientRecvSend.o        
$(HEADER) = $(LIBPATH)header.h

runC: client.o $(LIB)
	$(CC) client.o $(LIB) -o runC

client.o: client.c $(HEADER)
	$(CC) -c client.c

createClientSocket.o: $(LIBPATH)createClientSocket.c $(HEADER)  
        $(CC) -c $(LIBPATH)createClientSocket.c

serverRecvSend.o: $(LIBPATH)serverRecvSend.c $(HEADER)                	      $(CC) -c $(LIBPATH)serverRecvSend.c

clean: 
	rm $(LIB) client.o
