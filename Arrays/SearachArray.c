#include <stdio.h>
#include <stdlib.h>
#include "Headers/Types.h"
#include "Headers/EleOpsArray.h"
#include "Headers/ValidArray.h"
#include "Headers/SortArray.h"
#include "Headers/AlocateArray.h"
#include "Headers/StatArray.h"

//Searching Algorthims
//Linear Search
int LinearSearch( Array *arr, int item)
{
    // Loop Through Elements
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == item)
        {
            // Swap if Found(Better For Performance )
            SwapEle(arr, arr->A[i - 1], arr->A[i]);
            printf("Element Found At Index: %d\n", i - 1);
            return i - 1;
        }
    }
    return -1;
}

//Binary Search
int BinSearch( Array *arr, int key)
{
    int low=0;
    int high=arr->length-1;

    if (IsArraySorted(arr))
        BubleSort(arr);

    while (low <= high)
    {
        // Split Array into Half
        int mid = (low + high) / 2;
        // Is Mid = Key
        if (arr->A[mid] == key)
            return mid;
        // Move high index To Left Side Of Mid
        else if (key < arr->A[mid])
            high = mid - 1;
        // Move Low index To Right Side Of Mid
        else
            low = mid + 1;
    }
    puts("Key Not Found");
    return -1;
}

//Recursive Binary Search
int RBinSearch( Array *arr, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (key < arr->A[mid])
            return RBinSearch(arr, low, mid - 1, key);
        else
            return RBinSearch(arr, mid + 1, high, key);
    }
    else
    {
        puts("Key Not Found");
        return -1;
    }
}

//Find Missing Elements in a array method 1
 Array *FindMissingEle( Array *arr)
{
    if (IsArraySorted(arr) == 0)
        BubleSort(arr);

     Array *misEles = HeapArray(0, 0);
    int diff = arr->A[0] - 0;

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] - i != diff)
        {
            for (; diff < arr->A[i] - i; diff++)
                misEles->A[misEles->length++] = (diff + i);
        }
    }

    misEles->size = misEles->length;
    return misEles;
}


//Find Missing Elements in a array method 2
 Array *FindMissingEle2( Array *arr)
{
    int bignum = Max(arr);
     Array *misEles = HeapArray(bignum, 0);
     Array *tmpo = HeapArray(bignum, 0);

    for (int i = 0; i < arr->length; i++)
    {
        tmpo->A[arr->A[i]]++;
    }
    for (int i = 1; i < bignum; i++)
    {
        if (tmpo->A[i] == 0)
            AppendEle(misEles, i);
    }

    free(tmpo);
    misEles->size = misEles->length + 1;
    return misEles;
}