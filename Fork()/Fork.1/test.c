#include <stdio.h>
//1 родитель пораждает потомка, они сообщают свои pid
int main()
{
__pid_t pid;
pid = fork();
if (pid == 0)
{
    printf ("Я потомок с pid:%d\n", getpid());
} else 
{
    printf ("Я родитель с pid:%d\n", getpid());
    wait();
}
    return 0;
}