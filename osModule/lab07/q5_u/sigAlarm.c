#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include<stdlib.h>
// Alarm clock expires
int alarm_expired = 0;                         // set it to 1 once the alarm has expired
void setflag(int signo) { alarm_expired = 1; } // signal handler
int main(int argc, char *argv[])
{
    int nsecs, j;
    pid_t pid;
    if (argc <= 2)
        fprintf(stderr, "Usage: %s #minutes message\n", argv[0]),
            exit(1);
    if ((nsecs = atoi(argv[1]) * 60) <= 0)
        fprintf(stderr, "%s: invalid time\n", argv[0]), exit(2);
    pid = fork();
    if (pid < 0)
        perror(" can't create process"), exit(3);
    else if (pid > 0) // parent to quit, print child pid
        printf("%s: process id=%d\n", argv[0], pid), exit(0);
    /* now only child left */
    signal(SIGALRM, setflag); //install signal handler
    /* turn on alarm clock */
    alarm(nsecs);
    /* pause until signal */
    pause();
    /* a signal arrived and signal handler executed */
    if (alarm_expired)
    {                              // check whether this signal is SIGALRM
        printf("\007\007\007");    // ring bells
        for (int i = 2; i < argc; ++i) // send the message to terminal
            printf("%s ", argv[i]);
        printf("\n");
    }
    exit(0);
}