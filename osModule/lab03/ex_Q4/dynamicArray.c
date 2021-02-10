#include <stdio.h>
#include <stdlib.h>

int *getArray(int arraySize);
int main(int argc, char *argv[])
{
    int i;

    int *p; // We uses this reference variable to access
               // dynamically created array elements
    int n; // number of elements

    putchar('\n');
    printf("Enter the new number of elements: ");
    scanf("%d",&n);
    p = getArray(n);
    for (i = 0; i < n; i++)
        printf("*(p + %d) = %d\n", i, *(p + i));
    
    free(p);
    
}

int *getArray(int arraySize){
    int i;
    int *array;
    array = calloc(arraySize, sizeof(int)); // Make a NEW int array of n elements

    // ***** Notice that the array size has CHANGED !!! ****

    for (i = 0; i < arraySize; i++)
        *(array + i) = i; // put value i in array element i
    
    return array;
}