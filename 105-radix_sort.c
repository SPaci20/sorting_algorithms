#include "sort.h"

/**
 * getMax - Find the maximum element in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum element in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * countingSort - Sort an array using counting sort based
 *                            on a significant digit
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Current significant digit to consider (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 *                    order using Radix sort (LSD)
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, max_val;
	size_t i;

	if (array == NULL || size <= 1)
	{
		return;
	}
	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		max_val = array[0];
		for (i = 1; i < size; i++)
		{
			if (array[i] > max_val)
			{
				max_val = array[i];
			}
		}
		max = max_val;

		countingSort(array, size, exp);
		print_array(array, size);
	}
}
