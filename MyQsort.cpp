#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 10

void  PrintArray            (int* matrix, int length);

void  SwapValues            (int* value1, int* value2);

int   DivideByEnd           (int* nums, int left, int right);

void  QuickSort             (int* nums, int left, int right);

int   ReverseDivideByEnd    (int* nums, int left, int right);

void  ReversedQuickSort     (int* nums, int left, int right);

int   IsGreater             (int a, int b);

int   IsLess                (int a, int b);

int   IsAbsGreater          (int a, int b);

int   IsAbsLess             (int a, int b);

int   MyDivideByEnd         (int* nums, int left, int right, int (*comparator)(int, int));

void  MyQsort               (int* nums, int left, int right, int (*comparator)(int, int));


int main(void)
{
    int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    MyQsort(nums, 0, SIZE - 1, IsAbsGreater);

    PrintArray(nums, SIZE);

    return EXIT_SUCCESS;
}


void PrintArray(int* nums, int length)
{
    assert(nums);

    for (int i = 0; i < length; i++)
        printf("%d ", nums[i]);
    printf("\n");
}


void SwapValues(int* value1, int* value2)
{
    assert(value1);
    assert(value2);

    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}


int MyDivideByEnd(int* nums, int left, int right, int (*comparator)(int, int))
{
    assert(nums);

    int main_elem = nums[right];

    int less_nums_index = left;

    for (int i = left; i <= right; i++)
    {
        if (comparator(nums[i], main_elem) != 1)
        {
            SwapValues(&nums[i], &nums[less_nums_index]);
            less_nums_index++;
        }
    }
    return less_nums_index - 1;
}

void MyQsort(int* nums, int left, int right, int (*comparator)(int, int)) // sorts nums so that for any i: comparator(nums[i + 1], nums[i]) is 1 or 0
{
    assert(nums);

    if (left < right)
    {
        int division = MyDivideByEnd(nums, left, right, comparator);

        MyQsort(nums, left, division - 1, comparator);
        MyQsort(nums, division + 1, right, comparator);
    }
}

int IsGreater(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

int IsLess(int a, int b)
{
    if (a < b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

int IsAbsGreater(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

int IsAbsLess(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a < b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}
