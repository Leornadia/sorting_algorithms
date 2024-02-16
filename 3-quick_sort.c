#include "sort.h"
/**
 * swap - Swap two elements in an array
 * @a: First element
 * @b: Second element
 * @array: The array
 */
void swap(int *a, int *b, int *array)
{
int temp = *a;
*a = *b;
*b = temp;
print_array(array, 10);
}
/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * Return: Index of partition
 */
int lomuto_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j;
for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
swap(&array[i], &array[j], array);
}
}
swap(&array[i + 1], &array[high], array);
return (i + 1);
}
/**
 * quick_sort - Sort array using quicksort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
lomuto_partition(array, 0, size - 1);
}
