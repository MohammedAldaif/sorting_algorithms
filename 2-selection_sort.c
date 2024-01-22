#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - function
 * @array:input
 * @size:input
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		size_t iMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[iMin])
				iMin = j;
		}

		temp = array[i];
		array[i] = array[iMin];
		array[iMin] = temp;
		/**
		 *for (k = 0; k < size; k++)
		 *{
		 *	printf("%d", array[k]);
		 *	if (k < size - 1)
		 *		printf(", ");
		 *	}
		 *	printf("\n");
		 */
		print_array(array, size);
	}
}
