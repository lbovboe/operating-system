#include <stdio.h>

// Note, in C, the array name, such as ai represents the start address of the array.
// That address is same as &ai[0]. The statement pi = ai; 
// assigns the start address of the array to pointer pi, 
// so that it now points to the start of the array. 
// In our next for loop, we print each array ai[i] via this pointer.
int main(int argc, char const *argv[])
{
    // The code int *pi; declares a pointer variable that can hold an address of an integer. 
    // The pointer variable is allocated, however it does not contain any legitimate address yet.
    int ai[10];
    int *pi;
    int i;

    for (i = 0; i < 10; ++i)
        ai[i] = i + 100; // initialise each array element

    pi = ai; // let pi point to the array
             // alternatively, pi = &ai[0];

    for (i = 0; i < 10; ++i, ++pi)
        printf("a[%d]=%d\n", i, *pi); // print each array element
                                      // alternatively, printf("a[%d]=%d\n", i, ai[i]);
    return 0;
}
