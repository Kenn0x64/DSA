#include "Random.h"



/*
1-Change Variable Names
2-Add Missing Input Validation 
3-Add Exception
4-Adding Fun Description
5-Handling Null-Void Pointers 
*/


//Function For Alocating On Heap
struct Array *HeapArray(int size, int length);

//Functions For Printing Array Elements
void Display(struct Array *arr);
void DisplayAll(struct Array *arr);

//Array Check Functions
int IsThereSpcae(struct Array *arr);
int IsIndexInRange(struct Array *arr,int index);
int IsArraySorted(struct Array *arr);
int IsThereDuplicts(struct Array *arr);
int IsThereNegativeNums(struct Array *arr);

//Array Statistics Functions
int Max(struct Array *arr);
int Min(struct Array *arr);
int Min2(struct Array *arr, int x);
int Sum(struct Array *arr);
int RSum(struct Array *arr);
double Avg(struct Array *arr);

//Array Element Operations
int IndexOf(struct Array *arr, int item);
int AppendEle(struct Array *arr, int num);
int InsertEle(struct Array *arr, int  num, int index);
int DeleteEle(struct Array *arr, int item);
int DeleteEleAtIndex(struct Array *arr, int index);
int SetEleAt(struct Array *arr, int index,int item2);
void SwapEle(struct Array *arr, int item1,int item2);


//Array Operations
int CompareArr(struct Array *arr1,struct Array *arr2);
int CopyArr(struct Array *From, struct Array *To);
int CopyArrNoDuplicts(struct Array *From, struct Array *To);
int RemoveDuplicts(struct Array *arr);
void LeftShift(struct Array *arr);
void LeftRotation(struct Array *arr);
void RightShift(struct Array *arr);
void RightRotation(struct Array *arr);
struct Array* MergeArr(struct Array *arr1,struct Array *arr2);
struct Array* ConcatArr(struct Array *arr1,struct Array *arr2);
struct Array* ReverseArray(struct Array *arr);


//Sorting Algorthims
void BubleSort(struct Array *arr);
void SelectionSort(struct Array *arr);
struct Array *CountSort(struct Array *arr);



//Set Operations
struct Array *ArrUnion1F(struct Array *arr1, struct Array *arr2);
struct Array *ArrUnion2F(struct Array *arr1, struct Array *arr2);
struct Array *ArrUnionW(struct Array *arr1, struct Array *arr2);
struct Array *ArrIntersection1F(struct Array *arr1, struct Array *arr2);
struct Array *ArrIntersection2F(struct Array *arr1, struct Array *arr2);
struct Array *ArrDifference(struct Array *arr1, struct Array *arr2);


//Searching Algorthims
int LinearSearch(struct Array *arr, int item);
int BinSearch(struct Array *arr,int key );
int RBinSearch(struct Array *arr,int key );
struct Array FindMissingEle(struct Array *arr);
struct Array *FindMissingEle2(struct Array *arr);








