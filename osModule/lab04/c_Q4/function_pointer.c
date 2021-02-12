#include <stdio.h>

int square(int n);
int main(int argc, char const *argv[])
{
    int (*fp)(int);
    int n;
    fp = &square;
    n = square(10);
    printf("%d \n",n);
    n = fp(10);
    printf("%d \n",n);
    printf("%p is the address \n",fp);
    
    if(fp == &square){
        printf("same");
    }
    
    return 0;
}

int square(int n)
{
    return n*n;
}
