#include <stdio.h>
#include "Headers/Types.h"

// Array Validation Functions

// Checking For Free Space
int IsThereSpcae( Array *arr)
{
    /*Checking For Size*/
    if (arr->length >= arr->size)
        return -1;
    return 0;
}
// Checking If The Index Is In Range
int IsIndexInRange( Array *arr, int index)
{
    /*Check For Index range*/
    if (index < 0 || index > arr->size)
        return -1;
    return 0;
}
// Checking If There Is Duplicts
int IsThereDuplicts( Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        for (int j = i + 1; j < arr->length; j++)
            if (arr->A[i] == arr->A[j])
                return 1;
    return 0;
}

// Checking If The Array Is Sorted
int IsArraySorted( Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > arr->A[i + 1])
            return 0;
    return 1;
}

// Checking If There Is Nagtive Numbers
int IsThereNegativeNums( Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] < 0)
        {
            puts("Negative Number Found!");
            return 1;
        }
    return 0;
}