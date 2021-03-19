#include <signal.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>
// interrupt the foreground 
// processes (CTRL-C)
void catch (int signo)
{
    printf("Signal no % d is caught.\n", signo);
}
int main()
{
    signal(SIGINT, catch);
    for (int i = 0; i < 100; ++i)
    {
        printf("Sleep call % d\n", i);
        sleep(1);
    }
    printf("Exiting.\n");
    exit(0);
}