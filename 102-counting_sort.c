#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 *                  order using Counting Sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
       	int max;
	int *count, *temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Create a counting array and initialize it to 0 */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= (size_t)max; i++) /* Cast max to size_t */
		count[i] = 0;

	/* Count the occurrences of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the count array with cumulative sums */
	for (i = 1; i <= (size_t)max; i++) /* Cast max to size_t */
		count[i] += count[i - 1];

	/* Create a temporary array to store the sorted elements */
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		free(count);
		return;
	}

	/* Build the sorted array */
	for (i = size - 1; i < size; i--) /* Fixed loop condition */
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	/* Print the counting array (optional) */
	print_array(count, max + 1);

	/* Free dynamically allocated memory */
	free(temp);
	free(count);
}
