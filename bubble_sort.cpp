#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 5

void SwapValues    (int* value1, int* value2);

void PrintMatrix   (int* matrix, int length);

void BubbleSort    (int* nums, int length);


int main(void)
{
    int nums[SIZE] = {20, 30, 10, 50, 40};

    BubbleSort(nums, SIZE);

    PrintMatrix(nums, SIZE);

    return EXIT_SUCCESS;
}


void SwapValues(int* value1, int* value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void BubbleSort(int* nums, int length)
{
    for (int nPass = 0; nPass < length - 1; nPass++)
    {
        bool swapped = false;

        for (int i = 0; i < length - nPass - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                SwapValues(&nums[i], &nums[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void PrintMatrix(int* matrix, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", matrix[i]);
    printf("\n");
}

