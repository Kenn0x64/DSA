// Char Ops
#include "Headers/StrOps.h"
#include <stdio.h>
// Returns UpperCase Of The Char
int ToUpper(char x)
{
    if (x >= 'a' && x <= 'z')
        return x - 32;
    return x;
};

// Returns LowerCase Of The Char
int ToLower(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x + 32;
    return x;
};

// Swap Elements
void SwapEle(  char A[], char item1, char item2)
{
    // Get Index
    int inOfItem1 = IndexOf(A, item1);
    int inOfItem2 = IndexOf(A, item2);

    // Check If Item Found Or Not
    if (inOfItem1 == -1 || inOfItem2 == -1)
    {
        puts("Element Cant Be Found!");
        return;
    }

    // Swap
    char x = A[inOfItem1];
    A[inOfItem1] = A[inOfItem2];
    A[inOfItem2] = x;
}
