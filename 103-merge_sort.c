#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted array.
 * @array: The original array.
 * @left: The left subarray.
 * @right: The right subarray.
 * @size: The size of the original array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t mid = size / 2;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);
	free(temp);
}
/**
 * merge_sort - Sorts an array of integers in ascending
 *                    order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left;
	int *right;
	size_t left_size;
	size_t right_size;

	if (size < 2 || array == NULL)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;
	left_size = mid;
	right_size = size - mid;

	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, right, size);
}
