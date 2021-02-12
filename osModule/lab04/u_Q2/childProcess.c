#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    pid_t pid;
    
    printf("Just one process now , before forcking\n");
    
    pid = fork(); // making a child here
    
    if(pid == 0){
        printf("It's a child, it's pid = %d\n",pid);
        printf("My own pid is: %d\n",getpid());
        printf("My parent pid =%d\n",getppid()); 
        // if parent start first and terminate first the parent pid will be different
    }else if(pid >0 ){
        wait(NULL);
        printf("it's the parent, pid for child is = %d\n",pid);
        printf("My own pid is: %d\n",getpid());
        
    }else{
        printf("failed");
    }
    
    exit(0);
}
