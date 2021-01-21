#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *fname = "test.txt";
    FILE  *fstr;

    fstr = fopen(fname, "w+");
    if ( fstr == NULL ) {
        fprintf(stderr, "Cannot open file %s, terminate program\n", fname);
        exit(1);
    }

    fprintf(fstr, "Adding data to %s\n", fname);
    return 0;
}
