#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void waiting(char *name){
    const int num = 5;
    for (int i = 0; i<num; i++){
        sleep(10);
        printf("Done pass %d for %s\n",i,name);
    }
}
int main(int argc, char const *argv[])
{
    pid_t pid;
    pid_t pid2;
    int n=2; // number of forks
    pid = fork(); // making a child here
    pid2 = fork();
    
    if(pid == 0 || pid2 ==0){
        printf("It's a child, it's pid = %d\n",pid);
        printf("My own pid is: %d\n",getpid());
        printf("My parent pid =%d\n",getppid()); 
        waiting("child");
        exit(0);
        // if parent start first and terminate first the parent pid will be different
    }else if(pid >0 || pid2 >0){
        wait(NULL);
        printf("it's the parent, pid for child is = %d\n",pid);
        printf("My own pid is: %d\n",getpid());
        waiting("parent");
        
    }
    printf("Total number of child process : %d\n",2*n - 1);
    // if(pid > 0 && pid2 >0){
    //     wait(NULL);
    //     printf("Total number processes: %d\n",2*n);
    //     printf("Total number of child process : %d\n",2*n - 1);
    // }
    return 0;
}
