#include "sort.h"

/**
 * merge - Combines two sorted parts of the array into one sorted part.
 * @array: The main array that we are sorting.
 * @buff: A temporary array to help with merging.
 * @left_start: The starting index of the left part.
 * @mid: The middle index where the array is divided.
 * @right_end: The ending index of the right part.
 */
void merge(int *array, int *buff, size_t left_start, size_t mid, size_t right_end)
{
    size_t i = left_start, j = mid, k = left_start;

    while (i < mid && j < right_end) {
        if (array[i] < array[j])
            buff[k++] = array[i++];
        else
            buff[k++] = array[j++];
    }

    while (i < mid)
        buff[k++] = array[i++];
    while (j < right_end)
        buff[k++] = array[j++];

    for (i = left_start; i < right_end; i++)
        array[i] = buff[i];
}

/**
 * merge_sort_recursive - Recursively divides the array and sorts it.
 * @array: The main array that we are sorting.
 * @buff: A temporary array to help with merging.
 * @left_start: The starting index of the part of the array to sort.
 * @right_end: The ending index of the part of the array to sort.
 */
void merge_sort_recursive(int *array, int *buff, size_t left_start, size_t right_end)
{
    size_t mid;

    if (right_end - left_start <= 1)
        return;

    mid = (left_start + right_end) / 2;

    merge_sort_recursive(array, buff, left_start, mid);
    merge_sort_recursive(array, buff, mid, right_end);
    merge(array, buff, left_start, mid, right_end);
}

/**
 * merge_sort - Sorts an array of integers using merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (size < 2)
        return;

    buff = malloc(size * sizeof(int));
    if (!buff)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}
