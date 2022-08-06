#include <stdio.h>
#include <stdlib.h>
#include "Headers/Types.h"
#include "Headers/OpsArray.h"
#include "Headers/ValidArray.h"
#include "Headers/AlocateArray.h"
#include "Headers/EleOpsArray.h"



// Set Operations

// Array Union Using two for loop,Copy The Elements That Are Member of Both Arrays
 Array *ArrUnion1F( Array *arr1,  Array *arr2)
{
    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    if (IsThereDuplicts(arr1) || IsThereDuplicts(arr2))
        puts("Set Should Not Contain Duplict Values!!");

    // Copying Elements Of Arr
    CopyArrNoDuplicts(arr1, arr3);

    for (int i = 0; i < arr2->length; i++)
    {
        // Move To Next Index(i) if Found The Element
        if (IndexOf(arr3, arr2->A[i]) > -1)
            continue;
        // Else Append Element To End Of The Array
        AppendEle(arr3, arr2->A[i]);
    }

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

// Array Union Using two for loop,Copy The Elements That Are Member of Both Arrays But WithOut Second Copy
 Array *ArrUnion2F( Array *arr1,  Array *arr2)
{
    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    if (IsThereDuplicts(arr1) || IsThereDuplicts(arr2))
        puts("Set Should Not Contain Duplict Values!!");

    // Copying Elements Of Arr
    CopyArrNoDuplicts(arr1, arr3);

    for (int i = 0; i < arr2->length; i++)
    {
        for (int j = 0; j < arr3->length; j++)
        {
            // Move To Next Index(i) if Found The Element
            if (arr2->A[i] == arr3->A[j])
                break;
            // Else Append Element To End Of The Array
            else if (j == arr3->length - 1)
                AppendEle(arr3, arr2->A[i]);
        }
    }

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

// Array Union Using while loop,Copy The Elements That Are Member of Both Arrays But WithOut Second Copy
 Array *ArrUnionW( Array *arr1,  Array *arr2)
{
    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    if (IsThereDuplicts(arr1) || IsThereDuplicts(arr2))
        puts("Set Contain Duplict Values");

    // Copying Elements Of Arr
    CopyArrNoDuplicts(arr1, arr3);

    int i = 0, j = 0;

    while (i < arr2->length)
    {
        if (arr2->A[i] == arr3->A[j])
        {
            i++;
            j = 0;
            continue;
        }
        // Append Element To End Of The Array
        if (j == arr3->length - 1)
        {
            AppendEle(arr3, arr2->A[i]);
            j = 0;
            i++;
        }
        j++;
    }

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

//Array Intersection Using one for loop,Copy The Elements That Memebers In Both Arrays
 Array *ArrIntersection1F( Array *arr1,  Array *arr2)
{
    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    for (int i = 0; i < arr1->length; i++)
        if (IndexOf(arr2, arr1->A[i]) != -1 && IndexOf(arr3, arr1->A[i]) == -1)
            AppendEle(arr3, arr1->A[i]);

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

// Array Intersection Using two for loop,Copy The Elements That Memebers In Both Arrays
 Array *ArrIntersection2F( Array *arr1,  Array *arr2)
{
    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    for (int i = 0; i < arr1->length; i++)
    {
        for (int j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j] && IndexOf(arr3, arr1->A[i]) == -1)
                AppendEle(arr3, arr1->A[i]);
        }
    }

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

// Array Difference, Copy The Elements That Are Only In The First Array
 Array *ArrDifference( Array *arr1,  Array *arr2)
{

    // New Array
     Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    for (int i = 0; i < arr1->length; i++)
    {
        if (IndexOf(arr2, arr1->A[i]) == -1 && IndexOf(arr3, arr1->A[i]) == -1)
            AppendEle(arr3, arr1->A[i]);
    }

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}