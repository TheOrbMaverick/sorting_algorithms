#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order
 *               using the Merge Sort algorithm (top-down).
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Allocate temporary space for merging */
	int *temp_array = malloc(sizeof(int) * size);

	if (temp_array == NULL)
		return;

	/* Call the recursive merge_sort function */
	merge_sort_recursive(array, temp_array, 0, size - 1);

	/* Free the temporary array */
	free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 *
 * @array: The array to be sorted
 * @temp_array: Temporary array for merging
 * @left: Left index of the sub-array
 * @right: Right index of the sub-array
 */

void merge_sort_recursive(int *array, int *temp_array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		/* Recursive calls for the left and right halves */
		merge_sort_recursive(array, temp_array, left, middle);
		merge_sort_recursive(array, temp_array, middle + 1, right);

		/* Merge the two halves */
		merge_arrays(array, temp_array, left, middle, right);
	}
}

/**
 * merge_arrays - Merge two sorted arrays into a single sorted array
 *
 * @array: The array containing both halves
 * @temp_array: Temporary array for merging
 * @left: Left index of the sub-array
 * @middle: Middle index of the sub-array
 * @right: Right index of the sub-array
 */

void merge_arrays(int *array, int *temp_array, size_t left, size_t middle, size_t right)
{
	size_t i, j, k;

	/* Copy data to temporary arrays temp_left and temp_right */
	for (i = left; i <= right; i++)
		temp_array[i] = array[i];

	i = left;       /* Initial index of first sub-array */
	j = middle + 1; /* Initial index of second sub-array */
	k = left;       /* Initial index of merged array */

	/* Merge the two halves back into the original array */
	while (i <= middle && j <= right)
	{
		if (temp_array[i] <= temp_array[j])
		{
			array[k] = temp_array[i];
			i++;
		}
		else
		{
			array[k] = temp_array[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of temp_left, if any */
	while (i <= middle)
	{
		array[k] = temp_array[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of temp_right, if any */
	while (j <= right)
	{
		array[k] = temp_array[j];
		j++;
		k++;
	}
}
