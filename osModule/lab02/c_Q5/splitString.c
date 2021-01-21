#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int date;
    char month[30];
    int year;

    printf("Please enter the date in the form of date-short_month-year, ");
    printf(" such as 8-Aug-2006, where a month is written in exactly three letters: ");
    scanf("%d-%3s-%d", &date, month, &year);
    printf("the date you entered was:  %d-%s-%d\n", date, month, year);

    // testing split by space
    char str[] = "hello world people";
    char* tok = strtok(str," ");
    while (tok != NULL){
        printf("%s\n",tok);
        tok = strtok(NULL," ");
    }
    // testing split by - for date
    char str2[] = "30-Aug-2000";
    char* tok2 = strtok(str2,"-");
    while(tok2 != NULL){
        printf("%s\n",tok2);
        tok2 = strtok(NULL,"-");
    }

    return 0;
}

