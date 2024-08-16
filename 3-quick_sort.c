#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition the array using Lomuto scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int above, below;

	pivot = array + right;
	above = left;

	for (below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Recursive quicksort using Lomuto partitioning.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (left < right)
	{
		partition_index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, right);
	}
}

/**
 * quick_sort - Sort an array using the quicksort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Calls the recursive Lomuto sort function.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, (int)size - 1);
}

