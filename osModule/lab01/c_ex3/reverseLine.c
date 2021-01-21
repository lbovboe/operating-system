#include <stdio.h>
#include <string.h>
int main(){
    char name[100];
    printf("Type in the Line: ");
    fgets(name,100,stdin);
    for( int i = 0; i<= strlen(name);i++){
        printf("%d ",name[i]);
    }
    printf("\n");
    printf("Your line is: %s", name);

    // remove the new line 
    int length = strlen(name);
    printf("the current char length is %d",length);
    printf("\n");

    if(name[length-1] == '\n'){
        name[length-1] = '\0';
    }

    for( int i = 0; i<= strlen(name);i++){
        printf("%d ",name[i]);
    }
    printf("\n");
    printf("Your line is: %s", name);
    printf("\n");
    int length2 = strlen(name);
    printf("the char length without new line is %d",length2);
    printf("\n");

    // reverse Line
    printf("Reverse Line : ");

    for (int i = strlen(name)-1;i >= 0 ; i--){
        printf("%c",name[i]);
    }
}