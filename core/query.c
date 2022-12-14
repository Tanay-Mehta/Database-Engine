#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int search(string filename, int row_number){
    int u = row_number-1;
    int j, n;
    FILE *fptr = fopen(filename, "r");
    char c;
    for(j=0;j<10*u;j++){
        c = getc(fptr);
    }
    for(n=0;n<10;n++){
        c = getc(fptr);
        printf("%c", c);
    }
}