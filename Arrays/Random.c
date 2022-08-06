#include <stdio.h>
#include "Headers/Types.h"
#include "Headers/OpsArray.h"
#include "Headers/AlocateArray.h"

void SplitDigits( Array *arr, long int num)
{
    // Issue In Math Equation or C Language
    for (int i = 0; num > 0 && i < arr->size; i++)
    {
        if (i >= arr->length)
            arr->length++;

        arr->A[i] = num % 10;
        num = (num - arr->A[i]) / 10;
    }
}
int powOf(int base, int power)
{
    int newbase = 1;
    for (int i = 0; i < power; i++)
        newbase = newbase * base;
    return newbase;
}

int ByteToDecimal( Array *arr, long int num)
{
    int sum = 0;
    SplitDigits(arr, num);
    arr = ReverseArray(arr);

    if (arr->length > 8)
        return -1;

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] != 0 && arr->A[i] != 1)
        {
            puts("Number Conatins None Binary Digits");
            return -1;
        }
        sum = sum + (arr->A[i] * (i == 0 ? 1 : powOf(2, i)));
    }
    return sum;
}

// Fabonachi Seris
void FabonachiSeris(int num)
{

    long long int x;
    int x1 = 0;
    int x2 = 1;

    printf("%d\n", x1);
    printf("%d\n", x2);
    for (int i = 0; i < num; i++)
    {
        x = x1 + x2;
        x1 = x2;
        x2 = x;
        if (x <= 0)
            return;
        printf("%lld\n", x);
    }
}

// Tower Of honoi
void TowerOfHonoi(int n, int A, int B, int C)
{
    if (n <= 0)
        return;

    TowerOfHonoi(n - 1, A, C, B);
    printf("Move One Disk From Peg %d To Peg %d || %d -> %d\n", A, C, A, C);
    TowerOfHonoi(n - 1, B, A, C);
}

