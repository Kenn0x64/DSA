#include <malloc.h>
#include "Headers/Types.h"

//Function For Alocating On Heap

//Alocate Array on heap
 Array *HeapArray(int size, int length)
{
     Array *x = ( Array *)malloc(sizeof( Array));
    x->size = size;
    x->length = length;
    
    for (int i = 0; i < x->size; i++)
    x->A[i]=0;
    
    return x;
}

//Fun To Assign Values To Array
int AssignToArr( Array *ToArr,int values[])
{ 
    for (int i = 0; i < ToArr->length; i++)
        ToArr->A[i]=values[i];
    return 0;
}