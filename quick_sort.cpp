#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 9

void  PrintArray            (int* matrix, int length);

void  SwapValues            (int* value1, int* value2);

int   DivideByEnd           (int *nums, int left, int right);

void  QuickSort             (int* nums, int left, int right);

int   ReverseDivideByEnd    (int *nums, int left, int right);

void  ReversedQuickSort      (int* nums, int left, int right);


int main(void)
{
    int nums[SIZE] = {-9};


    QuickSort(nums, 0, SIZE - 1);

    PrintArray(nums, SIZE);

    ReversedQuickSort(nums, 0, SIZE - 1);

    PrintArray(nums, SIZE);

    return EXIT_SUCCESS;

}


void PrintArray(int* matrix, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", matrix[i]);
    printf("\n");
}


void SwapValues(int* value1, int* value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}


int DivideByEnd(int *nums, int left, int right)
{
    int main_elem = nums[right];

    int less_nums_index = left;

    for (int i = left; i <= right; i++)
    {
        if (nums[i] <= main_elem)
        {
            SwapValues(&nums[i], &nums[less_nums_index]);
            less_nums_index++;
        }
    }
    return less_nums_index - 1;
}

int ReverseDivideByEnd(int *nums, int left, int right)
{
    int main_elem = nums[right];

    int less_nums_index = left;

    for (int i = left; i <= right; i++)
    {
        if (nums[i] >= main_elem)
        {
            SwapValues(&nums[i], &nums[less_nums_index]);
            less_nums_index++;
        }
    }
    return less_nums_index - 1;
}

void QuickSort(int* nums, int left, int right)  // takes pointers on the part of the array "nums" that should be sorted
{

    if (left < right)
    {
        int division = DivideByEnd(nums, left, right);

        QuickSort(nums, left, division - 1);
        QuickSort(nums, division + 1, right);
    }
}

void ReversedQuickSort(int* nums, int left, int right)
{
    if (left < right)
    {
        int division = ReverseDivideByEnd(nums, left, right);
        ReverseQuickSort(nums, left, division - 1);
        ReversedQuickSort(nums, division + 1, right);
    }
}


