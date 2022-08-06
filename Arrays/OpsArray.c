#include <stdio.h>
#include <malloc.h>
#include "Headers/Types.h"
#include "Headers/EleOpsArray.h"
#include "Headers/ValidArray.h"
#include "Headers/SortArray.h"
#include "Headers/AlocateArray.h"

// Array Operations
// Compare Array
int CompareArr( Array *arr1,  Array *arr2)
{
    if (arr1->length != arr2->length)
    {
        puts("Both Array Must Have The Same Length");
        return -1;
    }

    for (int i = 0; i < arr1->length; i++)
        if (arr1->A[i] != arr2->A[i])
            return 0;

    return 1;
}

// Copy Array
int CopyArr( Array *From,  Array *To)
{
    for (int i = 0; i < From->length; i++)
        To->A[To->length++] = From->A[i];

    return 0;
}

// Copy Array elemnts With Out Duplicts
int CopyArrNoDuplicts( Array *From,  Array *To)
{
    for (int i = 0; i < From->length; i++)
        if (IndexOf(To, From->A[i]) == -1)
            To->A[To->length++] = From->A[i];

    return 0;
}

// Remove Duplicts Elements In a Array
int RemoveDuplicts( Array *arr)
{
    if (IsThereDuplicts(arr) == 0)
        return -1;

    for (int i = 0; i < arr->length; i++)
    {
        for (int j = 1; j < arr->length && i != j; j++)
        {
            if (arr->A[i] == arr->A[j])
            {
                DeleteEleAtIndex(arr, j);
            }
        }
    }

    return 0;
}

// Shift Elements to Left
void LeftShift( Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
}

// Rotate Elements to Left
void LeftRotation( Array *arr)
{
    int r = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = r;
}

// Shift Elements to Right
void RightShift( Array *arr)
{
    for (int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
}
// Rotate Elements to Right
void RightRotation( Array *arr)
{
    int r = arr->A[arr->length - 1];
    for (int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
    arr->A[0] = r;
}

// Merge Arrays
 Array *MergeArr( Array *arr1,  Array *arr2)
{
    // Make New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    // Sort If They Are Not Sorted
    if (IsArraySorted(arr1) == 0)
        BubleSort(arr1);

    if (IsArraySorted(arr2) == 0)
        BubleSort(arr2);

    int i = 0, j = 0;

    // Check For Smaller Element
    // If Smaller Found Add to arr
    // increce the index which we found The element in
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[arr3->length++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[arr3->length++] = arr2->A[j++];
        else
        {
            arr3->A[arr3->length++] = arr1->A[i++];
            j++;
        }
    }

    // Print Rest Of The Elements
    for (; i < arr1->length; i++)
        arr3->A[arr3->length++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[arr3->length++] = arr2->A[j];

    // Free HeapMemory
    free(arr1);
    free(arr2);

    // Return Address
    return arr3 == NULL ? NULL : arr3;
}

// Concat Arrays
 Array *ConcatArr( Array *arr1,  Array *arr2)
{
    // New Arr
     Array *arr3 = HeapArray((arr1->size + arr2->size), 0);

    // // Move Elements Of First Arr
    CopyArr(arr1, arr3);
    // Move Elements Of Second Arr
    CopyArr(arr2, arr3);

    // Free Memeory
    free(arr1);
    free(arr2);

    // Return Address
    return arr3 == NULL ? NULL : arr3;
}

// Reverse Array
 Array *ReverseArray( Array *arr)
{
    // New Arr
     Array *arrx = HeapArray(arr->size, arr->length);

    int i2 = 0;

    // Copy Elements Reversvily
    for (int i = arrx->length - 1; i >= 0; i--)
    {
        arrx->A[i2] = arr->A[i];
        i2++;
    }

    // Free Memory
    free(arr);
    return arrx == NULL ? NULL : arrx;
}
