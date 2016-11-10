all: getenvaddr myecho execve listenv

getenvaddr: getenvaddr.c
	gcc $< -o $@

myecho: myecho.c
	gcc $< -o $@

execve: execve.c
	gcc $< -o $@

listenv: listenv.c
	gcc $< -o $@
	cp $@ o
