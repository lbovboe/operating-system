#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    // path for folder, argv[0] argr[1]
    execlp("ls","ls","-lt",(char *)NULL);
    //execlp("ls", "ls", "-l", NULL);
    //execlp("date", "date", NULL);
    return 0;
}
