PROGS = foo bar

loop1:
	@for f in $(wildcard *.c) ; do \
		echo $$f ; \
		echo $${f%.c}; \
		gcc $$f -o $${f%.c}; \
	done

loop2:
	$(foreach f, $(wildcard *.c), \
		echo $f; \
		echo $(basename $f);)

loop3:
	$(foreach f, $(wildcard *.c), \
		$(info $f) \
		$(info $(basename $f)))

clean:
	rm $(PROGS)

all: ${PROGS}
