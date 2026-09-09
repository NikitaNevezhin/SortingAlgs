#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 10

void  PrintMatrix   (int* matrix, int length);

void  SwapValues    (int* value1, int* value2);

int   DivideByEnd   (int *nums, int left, int right);

void  QuickSort     (int* nums, int left, int right);


int main(void)
{
    int nums[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    QuickSort(nums, 0, SIZE);

    PrintMatrix(nums, SIZE);

    return EXIT_SUCCESS;

}


void PrintMatrix(int* matrix, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", matrix[i]);
    printf("\n");
}


int DivideByEnd(int *nums, int left, int right)
{
    int main_elem = nums[right - 1];

    int less_nums_index = left;

    for (int i = left; i < right; i++)
    {
        if (nums[i] <= main_elem)
        {
            SwapValues(&nums[i], &nums[less_nums_index]);
            less_nums_index++;
            // PrintMatrix(nums, 5);
        }
    }
    return less_nums_index - 1;
}

void QuickSort(int* nums, int left, int right)
{
    // printf("Executing QuickSort with left = %d, right = %d\n", left, right);
    if (left < right)
    {
        int division = DivideByEnd(nums, left, right);

        QuickSort(nums, left, division);
        QuickSort(nums, division + 1, right);
    }
}


void SwapValues(int* value1, int* value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}
