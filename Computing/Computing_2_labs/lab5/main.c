/**********************************************************************
Program: lab5
Author: Albara Mehene
Date: 10/18/2015
Time spent: 2 hours
Purpose: Print out the book like ba2 but using a struct.
10/18/2015
2hours
Partner: Christohper and Rafaeel
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
void main() {

pBook temp;

char fileName[30];
    printf("What is the file name ? ");
    scanf(" %s",fileName);
    temp = loadBookInfo(fileName);
    destroyBookInfo(&temp);
    printf("%p\n", temp);
}
