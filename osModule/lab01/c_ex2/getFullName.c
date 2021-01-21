#include <stdio.h>
#include <string.h>
int main(){
    char name[100];
    printf("Type in your full name: ");
    fgets(name,100,stdin);
    for( int i = 0; i<= strlen(name);i++){
        printf("%d ",name[i]);
    }

    printf("Your full name is: %s", name);

    // remove the new line 
    int length = strlen(name);
    printf("the length is %d",length);
    printf("\n");

    if(name[length-1] == '\n'){
        name[length-1] = '\0';
    }

    for( int i = 0; i<= strlen(name);i++){
        printf("%d ",name[i]);
    }

    printf("Your full name is: %s", name);
    printf("\n");
    int length2 = strlen(name);
    printf("the length is %d",length2);
}