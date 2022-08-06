#include <stdio.h>
#include "Headers/Types.h"
#include "Headers/ValidArray.h"
#include "Headers/AlocateArray.h"

// Statistics Functions

// Find Max in Array
int Max( Array *arr)
{
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        if (arr->A[i] > max)
            max = arr->A[i];
    return max;
}

// Find Min in Array
int Min( Array *arr)
{
    int min = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        if (arr->A[i] < min)
            min = arr->A[i];

    return min;
}

// Dont Use
int Min2( Array *arr, int x)
{
    int min = arr->A[x];
    for (int i = x + 1; i < arr->length; i++)
        if (min >= arr->A[i])
            min = arr->A[i];

    return min;
}

// Find Sum Of Array
int Sum( Array *arr)
{
    long int total = 0;
    for (int i = 0; i < arr->length; i++)
        total = total + arr->A[i];

    printf("%ld\n", total);
    return total;
}

// Find Sum Of Array Using Recurstion
int RSum( Array *arr)
{
    static int i = 0;
    if (i == arr->length)
        return 0;
    return arr->A[i++] + RSum(arr);
}

// Find Avg Of Array
double Avg( Array *arr)
{
    return (double)Sum(arr) / (arr->length - 1);
}

// Get Min & Max In A Array
 Array *MinMax( Array *arr)
{
     Array *minmax = HeapArray(2, 2);
    minmax->A[0] = arr->A[0];

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] < minmax->A[0])
        {
            minmax->A[0] = arr->A[i];
        }
        else if (arr->A[i] > minmax->A[1])
        {
            minmax->A[1] = arr->A[i];
        }
    }

    return minmax;
}