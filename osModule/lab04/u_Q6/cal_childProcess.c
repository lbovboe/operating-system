#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    pid_t pid;
    pid_t pid2;
    int n=2; // number of forks
    pid = fork(); // making a child here
    pid2 = fork();
    
    if(pid > 0 && pid2 >0){
        wait(NULL);
        printf("Total number processes: %d\n",2*n);
        printf("Total number of child process : %d\n",2*n - 1);
    }
    exit(0);
}
