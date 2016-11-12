PROGS = getenvaddr myecho execve listenv classic
all: ${PROGS}

getenvaddr: getenvaddr.c
	gcc $< -o $@

myecho: myecho.c
	gcc $< -o $@

execve: execve.c
	gcc $< -o $@

listenv: listenv.c
	gcc $< -o $@
	cp $@ o

classic: classic.c
	gcc -g -fno-stack-protector -z execstack $< -o $@

clean:
	rm ${PROGS}
