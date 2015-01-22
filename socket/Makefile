PROGS=server client byte_order my_client showip

all: ${PROGS}

my_client: my_client.o lib.o

server: server.o lib.o

client: client.o

my_client: my_client.o

byte_order: byte_order.o

showip: showip.o

clean:
	rm -f ${PROGS} *.o a.out
