all:rbtree-tst yao	

CFLAGS=-g -O0 -Wall

rbtree-tst:rbtree-tst.o rbtree.o

yao: yao.o rbtree.o

rbtree.o:rbtree.h rbtree.c

rbtree-tst.o:rbtree-tst.c

yao.o:yao.c

.PHONY:clean

clean:
	rm *.o rbtree-tst
