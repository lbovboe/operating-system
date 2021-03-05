#include<stdio.h>
#include <string.h>
#include "token.h"


int main(int argc, char const *argv[])
{
    char input[100];
    char * token[100];
    char * ans;
    printf("Type in your input: ");
    fgets(input, 100, stdin);

    int n = tokenise(input, token);
    
    for (int i =0; i<n;i++){
        printf("%s\n",token[i]);
    }
    return 0;
}
