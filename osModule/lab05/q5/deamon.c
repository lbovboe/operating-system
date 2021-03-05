#include <sys/types.h>

#include <stdlib.h>

#include <unistd.h>
#include <stdio.h>

#define logfile "/tmp/useless.log"

// include daemon_init here
int daemon_init(void);
int daemon_init(void)

{

    pid_t pid;

    if ((pid = fork()) < 0)
        return (-1);

    else if (pid != 0)
    {

        printf("server pid=%d\n", pid);

        exit(0);
    }

    /* child continues */

    setsid(); /* become sssession leader */

    chdir("/"); /* change current directory */

    umask(0); /* clear umask */

    return (0);
}
int main()

{

    FILE *log;

    pid_t pid;

    // create a log file

    log = fopen(logfile, "w+");

    if (!log)
    {

        fprintf(stderr,

                "cannot create log file %s\n", logfile);

        exit(1);
    }

    // turn the process into a daemon

    daemon_init();

    // log daemon pid

    pid = getpid();

    fprintf(log, "My pid is %d\n", pid);

    fflush(log);

    // pretend to do something

    while (1)
    {

        sleep(100);
        fprintf(log, "Who says that I am useless?\n");
        fflush(log);
    }
}