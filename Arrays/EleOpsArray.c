#include <stdio.h>
#include "Headers/Types.h"
#include "Headers/ValidArray.h"

// Array Element Operations

// Getting Index Of a Element
int IndexOf( Array *arr, int item)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] == item)
            return i;
    return -1;
}

// Append A  Element To End Of The Array
int AppendEle( Array *arr, int num)
{
    /*Checking For Size*/
    if (IsThereSpcae(arr) == -1)
    {
        printf("Array If Full\n");
        return -1;
    }

    arr->A[arr->length++] = num;
    return 0;
}

// Insert a Element At a Index
int InsertEle( Array *arr, int num, int index)
{
    /*Checking For Size*/
    if (IsThereSpcae(arr) == -1)
        return -1;

    /*Index==length?*/
    if (index >= arr->length)
    {
        AppendEle(arr, num);
        return 0;
    }

    /*Check For Index range*/
    if (IsIndexInRange(arr, index) == -1)
        return -1;

    /*Shift Elements*/
    for (int i = arr->length; i > index; i--)
        arr->A[i] = arr->A[i - 1];

    /*Insert Element*/
    arr->A[index] = num;
    arr->length++;
    printf("Element Inserted At %i\n", index);
    return 0;
}

// Delete First Acurance Of a Element
int DeleteEle( Array *arr, int item)
{
    int index = IndexOf(arr, item);

    if (index == -1)
    {
        puts("Item Does Not Exist!");
        return -1;
    }

    /*Index==length?*/
    if (index != arr->length - 1)
    {
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
    }
    else
    {
        arr->A[index] = 0;
    }

    arr->length--;
    return 0;
}

// Delete Element at a index
int DeleteEleAtIndex( Array *arr, int index)
{
    if (IsIndexInRange(arr, index))
    {
        puts("Index Is Out Of Range!");
        return -1;
    }

    /*Index==length?*/
    if (index != arr->length - 1)
    {
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
    }
    else
    {
        arr->A[index] = 0;
    }

    arr->length--;
    return 0;
}
// Set Element at a index
int SetEleAt( Array *arr, int index, int item2)
{

    if (IsIndexInRange(arr, index) == -1)
        return -1;
    arr->A[index] = item2;
    return 0;
}
// Swap Elements
void SwapEle( Array *arr, int item1, int item2)
{
    // Get Index
    int inOfItem1 = IndexOf(arr, item1);
    int inOfItem2 = IndexOf(arr, item2);

    // Check If Item Found Or Not
    if (inOfItem1 == -1 || inOfItem2 == -1)
    {
        printf("%d", item2);
        puts("Element Cant Be Found!");
        return;
    }

    // Swap
    int x = arr->A[inOfItem1];
    arr->A[inOfItem1] = arr->A[inOfItem2];
    arr->A[inOfItem2] = x;
}