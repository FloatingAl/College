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
int findCity(City* cities, int nitems, const char* name)
//-----------------------------------------------------------------------------
{
    int i = -1;
    int g;
    for (g = 0; g < nitems; g++) {
        if (strcmp(name, cities[g].name) == 0) {
         i=g;
            break;
        }
    }
    return i;
}

//-----------------------------------------------------------------------------
int findCity2(City* cities, int nitems, const char* name)
//-----------------------------------------------------------------------------
{
    int i = -1;
    int g;
 
for (g = 0; g < nitems; g++) {
        if (!strcmp(name, cities[g].name)) {
        i = g;    
	break;
        }
    }
    if (i >= nitems) {
        i = -1;
    }
    return i;
}


