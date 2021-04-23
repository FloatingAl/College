/**********************************************************************
Program: lab6
Author: Albara Mehene
Date: 10/23/2015
Time spent: 2.5 hours
Purpose: Making static libraries and shared libraries using makefil
Partner: Christohper and Rafaeel
Helper: Daniel Santoes
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "my_add.h"
#include "my_mult.h"

int main(int argc, char *argv[]) {

    int x = 1;
    int y = 2;
    int z = 3;

    int result;

    result = my_add(x, y);
    printf("x = %d y = %d my_add = %d\n", x, y, result);

    result = my_mult(y, z);
    printf("y = %d z = %d my_mult = %d\n", y, z, result);

    exit(0);
}


