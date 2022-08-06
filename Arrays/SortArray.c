#include <stdlib.h>
#include "Headers/Types.h"
#include "Headers/OpsArray.h"
#include "Headers/ValidArray.h"
#include "Headers/EleOpsArray.h"
#include "Headers/AlocateArray.h"
#include "Headers/StatArray.h"
#include "Headers/Random.h"



// Sorting Algorthims

// BubleSort
void BubleSort( Array *arr)
{
    // Check For Duplicts
    RemoveDuplicts(arr);

    // First Loop For The Pases
    for (int i = 0; i < arr->length; i++)
    {
        if (IsArraySorted(arr))
            return;

        // Second Loop For The Comperation
        // arr->length-i Because Of The Pases We Did
        // Mines One So that It Wont go out of the range
        for (int j = 0; j < arr->length - i - 1; j++)
            if (arr->A[j] > arr->A[j + 1])
                SwapEle(arr, arr->A[j], arr->A[j + 1]);
    }
}


// SelectionSort
void SelectionSort( Array *arr)
{
    // Check For Duplicts
    RemoveDuplicts(arr);

    for (int i = 0; i < arr->length; i++)
    {
        if (IsArraySorted(arr))
            return;
        SwapEle(arr, arr->A[i], Min2(arr, i));
    }
}

// CountSort
 Array *CountSort( Array *arr)
{
    if (IsThereNegativeNums(arr))
        return NULL;

     Array *PofD = HeapArray(Max(arr) + 1, Max(arr) + 1);
     Array *arrx = HeapArray(arr->size, arr->length);

    // Increment Counter For Each Element
    for (int i = 0; i < arr->length; i++)
        PofD->A[arr->A[i]]++;

    // Adding Each Number To The One Next To It
    for (int i = 0; i < PofD->length; i++)
        PofD->A[i + 1] += PofD->A[i];

    // RightShifting
    RightShift(PofD);

    // Inserting The Elements Into The New Array
    // Incrementing The Postion
    for (int i = 0; i < arr->length; i++)
    {
        arrx->A[PofD->A[arr->A[i]]] = arr->A[i];
        PofD->A[arr->A[i]]++;
    }
    free(arr);
    return arrx == NULL ? NULL : arrx;
}