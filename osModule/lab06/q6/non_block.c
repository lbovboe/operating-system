#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s[1000];
    int num;
    num = 1;
    char name[100];
    while (num == 1)
    {
        printf("Type in your input: ");
        fgets(name, 100, stdin);
        printf("Printing index for char before removing n \n");
        for (int i = 0; i <= strlen(name); i++)
        {
            printf("%d ", name[i]);
        }
        int length = strlen(name);
        printf("the length is %d", length);
        printf("\n");
        if (name[length - 1] == '\n')
        {
            name[length - 1] = '\0';
        }
        printf("The input is : %s \n",name);
        printf("Printing index for char after removing n \n");
        for (int i = 0; i <= strlen(name); i++)
        {
            printf("%d ", name[i]);
        }
        printf("\n");
        if(strcmp(name,"\0") == 0){
            printf("going to break\n");
            break;
        }
    }
    return 0;
}
