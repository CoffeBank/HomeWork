#include <stdio.h>
#include "func.c"
int main ()
{
int a = 30,b = 6;
int stop = 1;
int point;
while (stop)
{
    printf ("Enter code:\n");
    scanf ("%d", &point);
    switch(point)
    {
        case 1:
        printf ("res=%d\n",plus (a,b));
        break;
        case 2:
        printf ("res=%d\n",min (a,b));
        break;
        case 3:
        printf ("res=%d\n",mult (a,b));
        break;
        case 4:
        printf ("res=%d\n",div (a,b));
        break;
        case 5:
        stop = 0;
        break;
    } 
}
printf ("STOP_PROG\n");
return 0;
}

