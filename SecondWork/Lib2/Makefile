all: mainPLT.c plus.c min.c div.c mult.c
	gcc -fPIC -c plus.c
	gcc -fPIC -c min.c
	gcc -fPIC -c div.c
	gcc -fPIC -c mult.c
	gcc -shared plus.o -o libplus.so
	gcc -shared min.o -o libmin.so
	gcc -shared div.o -o libdiv.so
	gcc -shared mult.o -o libmult.so
	gcc mainPLT.c -o test -ldl
	./test
	rm libplus.so libmin.so libdiv.so libmult.so \
	plus.o min.o div.o mult.o \
	test
 
