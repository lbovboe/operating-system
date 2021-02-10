#include <stdio.h>

void fillArray(int array[], int arraySize);
void fillArrayPointer(int *array, int arraySize);
int main(int argc, char const *argv[])
{
    int ai[10];
    int *pi;
    pi = ai;
    printf("For array as parameter: ");
    fillArray(ai,10);
    printf("\nFor pointer as parameter: \n");
    fillArrayPointer(pi, 10);
    return 0;
}

void fillArray(int array[], int arraySize)
{
    int number;
    for (int i = 0; i < arraySize; i++)
    {
        printf("Enter the number %d: ", i + 1);
        scanf("%d", &number);
        array[i] = number;
        printf("array[%d] = %d ", i, array[i]);
    }
}
void fillArrayPointer(int *array, int arraySize)
{
    int number;
    for (int i = 0; i < arraySize; i++, array++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &number);
        *array = number;
        printf("array[%d] = %d ", i, *array);
    }
}
