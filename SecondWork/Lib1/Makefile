all: func.c mainPLT.c
	gcc func.c -c -fPIC
	gcc -shared func.o -o libfunc.so
	gcc mainPLT.c -o test -L. -lfunc
	./test
	rm libfunc.so test func.o
	gcc -c func.c -o func.o
	ar rc libfunc.a func.o
	ranlib libfunc.a
	gcc mainPLT.c libfunc.a
	./a.out
	rm libfunc.a func.o a.out 
	



