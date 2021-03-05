#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;

int main()

{

    int i = 0;

    while (environ[i] != NULL)

    {

        printf("%s\n", environ[i]);

        i++;
    }
    char *s,*w;

    if ((s = getenv("USER")) != NULL)
        printf("The user is %s\n", s);
        
    if ((w = getenv("PWD")) != NULL)
        printf("The woking dir is %s\n",w);
}