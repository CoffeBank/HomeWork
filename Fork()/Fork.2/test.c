#include <stdio.h>
#include <unistd.h>

//#include <process.h>
//6 процессов 
int main()
{
printf ("pid основного процесса:%d\n\n", getpid());
__pid_t pid1;
__pid_t pid2;
__pid_t pid3;
__pid_t pid4;
int flag = 0;
pid1 = fork();
if (pid1==0)
{
    printf ("мой pid:%d pid родителя:%d\n", getpid(),getppid());
    pid4 = fork();
        if (pid4==0)
        {
            printf ("мой pid:%d pid родителя:%d\n", getpid(),getppid());
            flag = 1;
        }
        else wait();
} else 
{
    printf ("мой pid:%d pid родителя:%d\n", getpid(),getppid());
    wait();
}
if(flag == 0)
{
    pid2 = fork();
if (pid2==0)
{
    printf ("мой pid:%d pid родителя:%d\n", getpid(),getppid());
    if (pid1!=0)
    {
        pid3 = fork();
        if (pid3==0)
        {
            printf ("мой pid:%d pid родителя:%d\n", getpid(),getppid());
        }
        else wait();
    }
    
} else 
{
    wait();
}
}
return 0;
}