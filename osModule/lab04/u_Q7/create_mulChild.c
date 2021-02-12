#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i;
    int n=2; // number of forks
    pid_t pid;
    for (i = 0; i < n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("It's a child number %d, it's pid = %d\n",i+1, pid);
            printf("My own pid is: %d\n", getpid());
            printf("My parent pid =%d\n", getppid());
            printf("---------------------------------\n");
            sleep((i+1)*2);
            // if parent start first and terminate first the parent pid will be different
        }
        else if (pid > 0)
        {
            
            printf("it's the parent, pid for child is = %d\n", pid);
            printf("My own pid is: %d\n", getpid());
            printf("---------------------------------\n");
        }
        else
        {
            printf("failed");
        }
    }
    return 0;
}
