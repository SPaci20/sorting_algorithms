#include <stdio.h>
#include "sort.h"

void sift_down(int *array, size_t size, size_t index, size_t max_size);
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size <= 1)
		return;

	i = size / 2 - 1;
	while (1)
	{
		if (i >= size)
			break;
		sift_down(array, size, i, size);
		if (i == 0)
			break;
		i--;
	}
	i = size - 1;
	while (1)
	{
		if (i == 0)
			break;
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i);
		i--;
	}
}

/**
 * sift_down - Helper function to sift down an element in the heap
 * @array: Array to be sorted
 * @size: Size of the array
 * @index: Index of the element to be sifted down
 * @max_size: Size of the heap to consider
 */
void sift_down(int *array, size_t size, size_t index, size_t max_size)
{
	int temp;

	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < max_size && array[left] > array[largest])
		largest = left;

	if (right < max_size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, max_size);
	}
}
