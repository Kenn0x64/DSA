#include <stdio.h>
#include <malloc.h>
#include "Headers/Random.h"

// Function For Alocating On Heap
struct Array *HeapArray(int size, int length)
{
    struct Array *x = (struct Array *)malloc(sizeof(struct Array));
    x->size = size;
    x->length = length;
    return x;
}

void Display(struct Array *arr)
{
    if (arr == NULL)
        return;

    if (arr->length - 1 == -1)
    {
        puts("Nothing To Print!");
        return;
    }

    printf("\n\nSet Size: %i", arr->size);
    printf("\nSet Length: %i", arr->length - 1);
    printf("\nSet Has: %i Element\n", arr->length);

    for (int i = 0; i < arr->length; i++)
        printf("%d ----> %d\n", arr->A[i], i);
}
void DisplayAll(struct Array *arr)
{
    if (arr == NULL)
        return;

    if (arr->length - 1 == -1)
    {
        puts("Nothing To Print!");
        return;
    }

    printf("\nSet Size: %i", arr->size);
    printf("\nSet Length: %i", arr->length - 1);
    printf("\nSet Has: %i Element\n", arr->length);

    for (int i = 0; i < arr->size; i++)
        printf("%d ----> %d\n", arr->A[i], i);
}

int IsThereSpcae(struct Array *arr)
{
    /*Checking For Size*/
    if (arr->length >= arr->size)
        return -1;
    return 0;
};

int IsIndexInRange(struct Array *arr, int index)
{
    /*Check For Index range*/
    if (index < 0 || index > arr->size)
        return -1;
    return 0;
};

int IsThereDuplicts(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        for (int j = i + 1; j < arr->length; j++)
            if (arr->A[i] == arr->A[j])
                return 1;
    return 0;
}

int IsArraySorted(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > arr->A[i + 1])
            return 0;
    return 1;
}

int IsThereNegativeNums(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] < 0)
        {
            puts("Negative Number Found!");
            return 1;
        }
    return 0;
}

int Max(struct Array *arr)
{
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        if (arr->A[i] > max)
            max = arr->A[i];
    return max;
}

int Min(struct Array *arr)
{
    int min = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        if (arr->A[i] < min)
            min = arr->A[i];

    return min;
}

int Min2(struct Array *arr, int x)
{
    int min = arr->A[x];
    for (int i = x + 1; i < arr->length; i++)
        if (min >= arr->A[i])
            min = arr->A[i];

    return min;
}

int Sum(struct Array *arr)
{
    long int total = 0;
    for (int i = 0; i < arr->length; i++)
        total = total + arr->A[i];

    printf("%ld\n", total);
    return total;
}

int RSum(struct Array *arr)
{
    static int i = 0;
    if (i == arr->length)
        return 0;
    return arr->A[i++] + RSum(arr);
}

double Avg(struct Array *arr)
{
    return (double)Sum(arr) / (arr->length - 1);
}

// Array Operations
int IndexOf(struct Array *arr, int item)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] == item)
            return i;
    return -1;
}

int AppendEle(struct Array *arr, int num)
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

int InsertEle(struct Array *arr, int num, int index)
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

int DeleteEle(struct Array *arr, int item)
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

int DeleteEleAtIndex(struct Array *arr, int index)
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

int SetEleAt(struct Array *arr, int index, int item2)
{

    if (IsIndexInRange(arr, index) == -1)
        return -1;
    arr->A[index] = item2;
    return 0;
}

void SwapEle(struct Array *arr, int item1, int item2)
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

int CompareArr(struct Array *arr1, struct Array *arr2)
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

int CopyArr(struct Array *From, struct Array *To)
{
    for (int i = 0; i < From->length; i++)
        To->A[To->length++] = From->A[i];

    return 0;
}
int CopyArrNoDuplicts(struct Array *From, struct Array *To)
{
    for (int i = 0; i < From->length; i++)
        if (IndexOf(To, From->A[i]) == -1)
            To->A[To->length++] = From->A[i];

    return 0;
}

int RemoveDuplicts(struct Array *arr)
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

void LeftShift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
}

void LeftRotation(struct Array *arr)
{
    int r = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = r;
}

void RightShift(struct Array *arr)
{
    for (int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
}

void RightRotation(struct Array *arr)
{
    int r = arr->A[arr->length - 1];
    for (int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
    arr->A[0] = r;
}

void BubleSort(struct Array *arr);
struct Array *MergeArr(struct Array *arr1, struct Array *arr2)
{
    // Make New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

struct Array *ConcatArr(struct Array *arr1, struct Array *arr2)
{
    // New Arr
    struct Array *arr3 = HeapArray((arr1->size + arr2->size), 0);

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

struct Array *ReverseArray(struct Array *arr)
{
    // New Arr
    struct Array *arrx = HeapArray(arr->size, arr->length);

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



// Sorting
void BubleSort(struct Array *arr)
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

void SelectionSort(struct Array *arr)
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

struct Array *CountSort(struct Array *arr)
{
    if (IsThereNegativeNums(arr))
        return NULL;

    struct Array *PofD = HeapArray(Max(arr) + 1, Max(arr) + 1);
    struct Array *arrx = HeapArray(arr->size, arr->length);

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

struct Array *ArrUnion1F(struct Array *arr1, struct Array *arr2)
{
    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

// Copy The Elements That Are Member of Both Arrays But WithOut Second Copy
struct Array *ArrUnion2F(struct Array *arr1, struct Array *arr2)
{
    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

// Copy The Elements That Are Member of Both Arrays But WithOut Second Copy
struct Array *ArrUnionW(struct Array *arr1, struct Array *arr2)
{
    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

// Copy The Elements That Memebers In Both Arrays
struct Array *ArrIntersection1F(struct Array *arr1, struct Array *arr2)
{
    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

    for (int i = 0; i < arr1->length; i++)
        if (IndexOf(arr2, arr1->A[i]) != -1 && IndexOf(arr3, arr1->A[i]) == -1)
            AppendEle(arr3, arr1->A[i]);

    // Free Mem
    free(arr1);
    free(arr2);
    return arr3 == NULL ? NULL : arr3;
}

struct Array *ArrIntersection2F(struct Array *arr1, struct Array *arr2)
{
    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

// Copy The Elements That Are Only In The First Array
struct Array *ArrDifference(struct Array *arr1, struct Array *arr2)
{

    // New Array
    struct Array *arr3 = HeapArray(arr1->size + arr2->size, 0);

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

// Searching Algorthims

int LinearSearch(struct Array *arr, int item)
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

int BinSearch(struct Array *arr, int key)
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

int RBinSearch(struct Array *arr, int low, int high, int key)
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

struct Array *FindMissingEle(struct Array *arr)
{
    if (IsArraySorted(arr) == 0)
        BubleSort(arr);

    struct Array *misEles = HeapArray(0, 0);
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

struct Array *FindMissingEle2(struct Array *arr)
{
    int bignum = Max(arr);
    struct Array *misEles = HeapArray(bignum, 0);
    struct Array *tmpo = HeapArray(bignum, 0);

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
