#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void merge(int *array, size_t size, int *left,
size_t left_size, int *right, size_t right_size);
void merge_sort(int *array, size_t size);

/**
 * merge - Merge two subarrays into one sorted array
 * @array: Pointer to the original array
 * @size: Size of the original array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */

void merge(int *array, size_t size, int *left,
size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged_array = malloc(size * sizeof(int));

	if (merged_array == NULL)
	{
		free(merged_array);
		return;
	}

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged_array[k] = left[i];
			i++;
		}
		else
		{
			merged_array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		merged_array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		merged_array[k] = right[j];
		j++;
		k++;
	}

	for (k = 0; k < size; k++)
		array[k] = merged_array[k];

	printf("[Done]: ");
	print_array(merged_array, size);

	free(merged_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t middle = size / 2;
		int *left = array;
		int *right = array + middle;
		size_t left_size = middle;
		size_t right_size = size - middle;

		printf("Splitting...\n[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, size, left, left_size, right, right_size);
	}
}
