#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using Shell Sort algorithm with Knuth sequence.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1;

    if (array == NULL || size < 2)
        return;

    while (interval <= size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        shell_sort_with_interval(array, size, interval);
        interval = (interval - 1) / 3;
    }
}

/**
 * shell_sort_with_interval - Sorts an array with a given interval using Shell Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @interval: The interval for the sorting
 */
void shell_sort_with_interval(int *array, size_t size, size_t interval)
{
    size_t i, j;
    int temp;

    for (i = interval; i < size; i++)
    {
        temp = array[i];

        for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
        {
            array[j] = array[j - interval];
        }

        array[j] = temp;
    }

    print_array(array, size);
}
