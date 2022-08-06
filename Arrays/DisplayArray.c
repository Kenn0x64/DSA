#include <stdio.h>
#include "Headers/Types.h"

//Functions For Printing Array Elements
void Display( Array *arr)
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

//Functions For Printing All Array Elements
void DisplayAll( Array *arr)
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