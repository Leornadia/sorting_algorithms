#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The array to be sorted
 * @left: Start index of the left subarray
 * @middle: End index of the left subarray (also start of right subarray)
 * @right: End index of the right subarray
 */
void merge(int *array, int left, int middle, int right)
{
	int i, j, k;
	int left_size = middle - left + 1;
	int right_size =  right - middle;
	int *left_array = malloc(sizeof(int) * left_size);
	int *right_array = malloc(sizeof(int) * right_size);

	for (i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < right_size; j++)
		right_array[j] = array[middle + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}


	while (i < left_size)
		array[k++] = left_array[i++];
	while (j < right_size)
		array[k++] = right_array[j++];

	free(left_array);
	free(right_array);
}

/**
 * merge_sort - Top-down implementation of Merge Sort.
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int middle;

	if (size < 2)
		return;

	middle = size / 2;

	merge_sort(array, middle);
	merge_sort(array + middle, size - middle);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);
	merge(array, 0, middle - 1, size - 1);
	printf("[Done]: ");
	print_array(array, size);

}

