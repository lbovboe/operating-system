#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    /* code */
    int i;

   printf("There are %d command line arguments.\n", argc);
   printf("They are:\n");
   for (i=0; i < argc; ++i) 
       printf("%dth argument: %s\n", i, argv[i]);     

   exit(0);
    
}
//gcc -o main arguments.c