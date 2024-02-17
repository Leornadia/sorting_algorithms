#include "sort.h"

/**
 * bitonic_compare - Compares elements for Bitonic Sort, array in-place.
 * @array: Array to be sorted.
 * @start: Starting index of the subarray.
 * @size: Size of the subarray.
 * @direction: 1 for Ascending, 0 for Descending.
 */
void bitonic_compare(int *array, int start, int size, int direction)
{
	int i, distance = size / 2;

	for (i = start; i < start + distance; i++)
	{
		if ((array[i] > array[i + distance]) == direction)
		{

			int swap = array[i];

			array[i] = array[i + distance];
			array[i + distance] = swap;

			print_array(array, size);
		}
	}
}

/**
 * bitonic_merge - Recursively merges bitonic sequences into a sorted sequence.
 * @array: Array to be sorted.
 * @start: Starting index of the subarray.
 * @size: Size of the subarray.
 * @direction: 1 for Ascending, 0 for Descending.
 */
void bitonic_merge(int *array, int start,  int size,  int direction)
{
	if (size > 1)
	{
		int mid = size / 2;

		bitonic_merge(array, start, mid, 1);
		bitonic_merge(array, start + mid, mid, 0);
		bitonic_compare(array, start, size, direction);
	}
}

/**
 * bitonic_sort_rec - Recursive helper function for Bitonic Sort.
 * @array: Array to be sorted.
 * @start: Starting index of the subarray.
 * @size: Size of the subarray.
 * @direction: 1 for Ascending, 0 for Descending.
 */
void bitonic_sort_rec(int *array, int start, int size, int direction)
{
	if (size > 1)

	{
		int mid = size / 2;

		bitonic_sort_rec(array, start, mid, 1);
		bitonic_sort_rec(array, start + mid, mid, 0);
		bitonic_merge(array, start, size, direction);
	}
}

/**
 * bitonic_sort -  Sorts an array using the Bitonic Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_rec(array, 0, size, 1);
}

