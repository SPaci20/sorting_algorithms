#include "sort.h"

/**
 * swap - swap two elements in an array
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Partition the array using the Hoare scheme
 * @array: Array of integers
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (j);
		}
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursive function for quick sort
 * @array: Array of integers
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		quick_sort_hoare_recursive(array, low, pivot_index, size);
		quick_sort_hoare_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                       order using Quick sort
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare_recursive(array, 0, size - 1, size);
}

