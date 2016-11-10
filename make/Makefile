PROGS = foo bar

all: ${PROGS}

loop:
	for f in $(wildcard *.c) ; do \
		echo $$f ; \
		echo $(basename $$f); \
	done

clean:
	rm $(PROGS)

# base:
#   echo $(basename foo.c)
