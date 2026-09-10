#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define SIZE 10

void  PrintArray            (double* nums, int length);

int   IsGreater             (void* a, void* b);

void  SwapValues            (void* value1, void* value2, size_t N);

void* GetShift              (void* first, size_t elem_size, int shift);

int   MyDivideByEnd         (void* nums, int left, int right, size_t elem_size, int (*comparator)(void*, void*));

void  Myqsort               (void* arr, int left, int right, size_t elem_size, int (*comp)(void*, void*));




int main(void)
{
    // printf("Starting in main()...\n");
    // printf("int = %d\n", sizeof(int));
    double arr[10] = {3.14, 2.71, 1.41, 0.57, 1.73, 9.81, 0.0, -1.5, 42.0, 10.25};

    // Myqsort(arr, 0, SIZE - 1, sizeof(int), IsIntGreater);

    Myqsort(arr, 0, SIZE - 1, sizeof(double), IsGreater);

    PrintArray(arr, SIZE);

    return EXIT_SUCCESS;
}

void PrintArray(double* nums, int length)
{
    assert(nums);

    for (int i = 0; i < length; i++)
        printf("%lf ", nums[i]);
    printf("\n");
}

void SwapValues(void* value1, void* value2, size_t N)
{
    assert(value1);
    assert(value2);

    char temp[N];

    memcpy(temp, value1, N);
    memcpy(value1, value2, N);
    memcpy(value2, temp, N);
}


int MyDivideByEnd(void* nums, int left, int right, size_t elem_size, int (*comparator)(void*, void*))
{
    assert(nums);

    void* main_elem = GetShift(nums, elem_size, right);

    // printf("main_elem = %d\n", *(int*)main_elem);
    // printf("elem_size = %d\n", elem_size);

    int less_nums_index = left;

    void* curr_elem = NULL;

    for (int i = left; i <= right; i++)
    {
        curr_elem = GetShift(nums, elem_size, i);
        //printf("curr_elem = %d\n", *(int*)curr_elem);
        // printf("&curr_elem = %d\n", curr_elem);

        if (comparator(curr_elem, main_elem) != 1)
        {
            // printf("I made it to the if statement...\n");
            SwapValues(curr_elem, GetShift(nums, elem_size, less_nums_index), elem_size);
            less_nums_index++;
        }
    }
    // PrintArray((int*)nums, SIZE);


    return less_nums_index - 1;
}


void Myqsort(void* nums, int left, int right, size_t elem_size, int (*comp)(void*, void*))
{
    // printf("Executing Myqsort() with left = %d, right = %d...\n", left, right);
    // printf("elem_size = %d\n", elem_size);
    assert(nums);

    if (left < right)
    {
        int division = MyDivideByEnd(nums, left, right, elem_size, comp);
        // printf("division = %d\n", division);

        Myqsort(nums, left, division - 1, elem_size, comp);
        Myqsort(nums, division + 1, right, elem_size, comp);
    }
}

int IsGreater(void* a, void* b)
{
    double c = *(double*)a;
    double d = *(double*)b;

    if (c > d)
        return 1;
    else if (c < d)
        return -1;
    return 0;
}

void* GetShift(void* first, size_t elem_size, int shift)
{
    return (void*)((char*)first + elem_size * shift);
}
