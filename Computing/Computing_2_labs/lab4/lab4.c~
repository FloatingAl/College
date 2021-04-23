//-----------------------------------------------------------------------------
// Course: 91.102 Computing II
// Author: Krishnan Seetharaman
// Lab4: Debugging
//-----------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "findCity.h"


//-----------------------------------------------------------------------------
int die(char* msg)
// exit routine;
//-----------------------------------------------------------------------------
{
    printf("ERROR: %s\n", msg);
    exit(1);
}

//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {
//-----------------------------------------------------------------------------
    int a[8] = { 9, 8, 1, 3, 2, 5, 4, 7 };
    int nitems = sizeof(a) / sizeof(int);
    int* sorted;
    City cities[5] = {{1234, "Boston"}, {5678, "LA"}, {67, "Worcester"}, {25, "Lowell"}, {876, "Cambridge"}};
    char city[MAX_LENGTH];

    int idx;

    nitems = sizeof(cities)/sizeof(City);
    strcpy(city, "Lowell");
    idx = findCity(cities, nitems, city);
    if (idx != -1) {
        printf("Found City: %s Position: %d\n", city, idx);
    }
    else {
        printf("NOT Found City: %s Position: %d\n", city, idx);
    }

    strcpy(city, "Tyngsboro");
    idx = findCity(cities, nitems, city);
    if (idx != -1) {
        printf("Found City: %s Position: %d\n", city, idx);
    }
    else {
        printf("NOT Found City: %s Position: %d\n", city, idx);
    }

    strcpy(city, "Newton Upper Falls");
    idx = findCity2(cities, nitems, city);
    if (idx != -1) {
        printf("Found City: %s Position: %d\n", city, idx);
    }
    else {
        printf("NOT Found City: %s Position: %d\n", city, idx);
    }

    exit(0);
}




