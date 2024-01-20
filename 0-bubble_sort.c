#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort-function
 * @array:input
 * @size:input
 * Return: void
 **/

void bubble_sort(int *array, size_t size)
{
	size_t temp;
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				for (k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
