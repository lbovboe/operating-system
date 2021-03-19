#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
// terminate child
int val = 10;
void handler(int sig)
{
    val += 5;
}
int main()
{
    pid_t pid;
    signal(SIGCHLD, handler);
    if ((pid = fork()) == 0)
    {
        val -= 3;
        exit(0);
    }
    waitpid(pid, NULL, 0);
    printf("val = %d\n", val);
    exit(0);
}
v