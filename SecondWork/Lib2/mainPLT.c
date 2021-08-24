#include <stdio.h>
#include <dlfcn.h>
#include "plus.c"
#include "min.c"
#include "mult.c"
#include "div.c"
int main ()
{
char name[]="   ";
int a = 30,b = 6;
int stop = 1;
int point;
void *lib1,*lib2,*lib3,*lib4;
int (*powerfunc)(int x, int y);
lib1 = dlopen("/home/ed/progEd/HOME1.2/libplus.so",RTLD_LAZY);
lib2 = dlopen("/home/ed/progEd/HOME1.2/libmin.so",RTLD_LAZY);
lib3 = dlopen("/home/ed/progEd/HOME1.2/libmult.so",RTLD_LAZY);
lib4 = dlopen("/home/ed/progEd/HOME1.2/libdiv.so",RTLD_LAZY);

if (!lib1||!lib2||!lib3||!lib4){
	//если ошибка, то вывести ее на экран
	fprintf(stderr,"dlopen() error: %s\n", dlerror());
	return 1;
};

printf ("Enter you func pls:\n");
scanf ("%s", &name);
if ((powerfunc = dlsym(lib1, name)) != 0)
{
    printf("%s(%d,%d) = %d\n",name, a, b, (*powerfunc)(a,b));
    dlclose(lib1);
    return 0;
} 
else if ((powerfunc = dlsym(lib2, name)) != 0)
{
    printf("%s(%d,%d) = %d\n",name, a, b, (*powerfunc)(a,b));
    dlclose(lib2);
    return 0;
} 
else if ((powerfunc = dlsym(lib3, name)) != 0)
{
    printf("%s(%d,%d) = %d\n",name, a, b, (*powerfunc)(a,b));
    dlclose(lib3);
    return 0;
} 
else if ((powerfunc = dlsym(lib4, name)) != 0)
{
    printf("%s(%d,%d) = %d\n",name, a, b, (*powerfunc)(a,b));
    dlclose(lib4);
    return 0;
}

printf ("STOP_PROG!!!\n");
return 0;
}

