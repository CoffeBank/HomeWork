#include <stdio.h>

int main ()
{
__pid_t pid;
char com[10];
printf ("Введите комманду: (/bin/комманда)");
scanf("%s", &com);
pid = fork();
if (pid == 0)
{
    execl(com, com, NULL);
    
} else 
{
    wait();
    printf ("stop\n");
    return 0;
}
return 0;
}