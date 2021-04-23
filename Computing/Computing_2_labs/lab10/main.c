//-----------------------------------------------------------------------------
// Course: 91.102 Computing II
// Author: Krishnan Seetharaman
// Lab10: valgrind to detect memory leaks etc.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------------------------------------
void f1(char *s)
//-----------------------------------------------------------------------------
{
    char *p;
    int j = 0;

    // copy string and omit spaces;
    while (p != NULL) {
        if (*p != ' ') {
            s[j++] = *p;
        }
        p++;
    }
    s[j] = 0;
}

//-----------------------------------------------------------------------------
void f2(char* s)
//-----------------------------------------------------------------------------
{
    char *p;
    int i;
    int j = 0;
    size_t len;

    len = strlen(s);
    p = (char*)malloc(sizeof(char) * len + 1);

    // copy string and omit spaces;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            p[j++] = s[i];
        }
    }
    p[j] = 0;

    strcpy(s, p);
}

//-----------------------------------------------------------------------------
char* f3(char* s)
//-----------------------------------------------------------------------------
{
    char *p;
    int i;
    int j = 0;
    size_t len;

    len = strlen(s);
    p = (char*)malloc(sizeof(char) * len + 1);

    // copy string and omit spaces;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            p[j++] = s[i];
        }
    }
    p[j] = 0;

    strcpy(s, p);
    free(p);

    return p;
}

//-----------------------------------------------------------------------------
void f4(char* s)
//-----------------------------------------------------------------------------
{
    char *p;
    int i;
    int j = 0;
    size_t len;

    len = strlen(s);
    p = (char*)malloc(sizeof(char) * len + 1);

    // copy string and omit spaces;
    for (i = 0; i <= len; i++) {
        if (s[i] == ' ') {
            p[j++] = s[i];
        }
    }
    p[j] = 0;

    strcpy(s, p);
}

//-----------------------------------------------------------------------------
void f5(char* s)
//-----------------------------------------------------------------------------
{
    char *p;
    int i;
    int j = 0;
    size_t len;

    len = strlen(s);
    p = (char*)malloc(sizeof(char) * len + 1);

    // copy string and omit spaces;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            p[j++] = s[i];
        }
    }
    p[j] = 0;

    strcpy(s, p);
    free(p);
    free(p);
}

//-----------------------------------------------------------------------------
void f6(char* s)
//-----------------------------------------------------------------------------
{
    char *p;
    int i;
    int j = 0;
    size_t len;

    len = strlen(s);
    p = (char*)malloc(sizeof(char) * len + 1);

    // copy string and omit spaces;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            p[j++] = s[i];
        }
    }
    p[j] = 0;

    strcpy(s, p);

    // uncomment line below and use g++ to compile
    //delete [] p;
}

//-----------------------------------------------------------------------------
int main(int argc, char *argv[])
//-----------------------------------------------------------------------------
{
    char s[256];

    strcpy(s, "This is a test");
    f2(s);
    f3(s);
    f4(s);
    f5(s);
    f6(s);
    f1(s);

    exit(0);
}


