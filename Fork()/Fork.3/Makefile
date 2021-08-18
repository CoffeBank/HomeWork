CFLAGS:=-g
CFLAGS:=-MM
bin:=test
obj:=$(bin).o
src:=$(bin).c

all: $(obj)
	gcc $(src) -o $(bin)
	./test
	