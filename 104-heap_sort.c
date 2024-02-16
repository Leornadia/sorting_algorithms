#include "sort.h"

/**
 * sift_down_recursive - Recursive implementation of sift-down for Heap Sort.
 * @array: Array representing the heap.
 * @n: Size of the heap.
 * @root: Index of the current root.
 * @size: Original size of the array (for boundary checks).
 */
void sift_down_recursive(int *array, size_t n, int root, size_t size)
{
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;

	if ((size_t)l < n && array[l] > array[largest])
		largest = l;

	if ((size_t)r < n && array[r] > array[largest])
		largest = r;

	if (largest != root)
	{
		int swap = array[root];

		array[root] = array[largest];
		array[largest] = swap;

		print_array(array, size);
		sift_down_recursive(array, n, largest, size);
	}
}

/**
 * heap_sort_recursive - Recursive Heap Sort implementation.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort_recursive(int *array, size_t size)
{
	int i = size / 2 - 1;

	while (i >= 0)
	{
		sift_down_recursive(array, size, i, size);
		i--;
	}


	i = size - 1;
	while (i > 0)
	{
		int swap = array[0];

		array[0] = array[i];
		array[i] = swap;
		print_array(array, size);
		sift_down_recursive(array, i, 0, size);
		i--;
	}
}

/**
 * heap_sort - Wrapper function to call the recursive implementation.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	heap_sort_recursive(array, size);
}
