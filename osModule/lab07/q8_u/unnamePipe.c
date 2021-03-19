#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
/*The examples we seen at the shell command line are unnamed. 
They are created, used and destroyed within the life a set of processes.
 Each end of the pipe has it’s own file descriptor. 
 One end is for reading and one end is for writing. 
 When you are done with a pipe, it is closed like any other file.*/
#define READ 0

/* The index of the “read” end of the pipe */

#define WRITE 1

/* The index of the “write” end of the pipe */

char *phrase = "Stuff this in your pipe and smoke it";

int main()

{
    int fd[2], bytesRead;

    char message[100]; /* Parent process’s message buffer */

    pipe(fd); /*Create an unnamed pipe*/

    if (fork() == 0) /* Child Writer */

    {

        close(fd[READ]); /* Close unused end*/

        write(fd[WRITE], phrase, strlen(phrase) + 1); /* include NULL*/

        close(fd[WRITE]); /* Close used end*/
    }

    else /* Parent Reader */

    {

        close(fd[WRITE]); /* Close unused end*/
        bytesRead = read(fd[READ], message, 100);

        printf("Read %d bytes: %s\n", bytesRead, message);

        close(fd[READ]); /* Close used end */
    }
}