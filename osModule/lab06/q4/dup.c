#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    // fd = 0 ---> stdin fd =1 ---> stdout
    // fd = 2--->stderr
    // these 3 fd are default
    int file = open("result.txt",O_WRONLY | O_CREAT,0777);
    if (file == -1){
        return 2;
    }
    int file2 = dup2(file,1);
    execlp("ls","ls","-lt",(char *)NULL);
    
    
    return 0;
}
