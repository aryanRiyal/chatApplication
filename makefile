runS: server.o
	gcc server.o -o runS

server.o: server.c
	gcc -c server.c @flag

runC: client.o
	gcc server.o -o runC

client.o: client.c
	gcc -c client.c @flag

clean:
	rm *.o runS runC
