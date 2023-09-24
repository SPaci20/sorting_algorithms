#include "sort.h"

/**
 * bubble_sort -Sorts an array of integers in ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;  /* Initialize the swapped flag */

		for (j = 0; j < size - i - 1; j++)
		{
			/* If the current is greater than the next swap them */
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Set the swapped flag to true */
				swapped = 1;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
		/* If no two elements swaps in inner loop,it's already sorted */
		if (swapped == 0)
			break;
	}
}
