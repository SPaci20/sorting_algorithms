#include "sort.h"

/**
 * bitonic_sort_recursive - Recursively sorts a Bitonic sequence
 * @array: Array of integers
 * @size: Size of the array
 * @dir: 1 for ascending order, 0 for descending order
 * @bitonic_size: Size of the Bitonic sequence to be sorted
 */
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t bitonic_size) {
	(void) dir;

    if (bitonic_size > 1) {
        size_t middle = size / 2;

        bitonic_sort_recursive(array, middle, 1, middle);
        bitonic_sort_recursive(array + middle, middle, 0, middle);

        merge(array, (int *) (array + middle), (int *) (array + size), bitonic_size);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Array of integers
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    bitonic_sort_recursive(array, size, 1, size);
}

