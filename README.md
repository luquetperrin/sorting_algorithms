Sorting Algorithms & Big O Notation
This repository contains implementations of various sorting algorithms in C, along with analyses of their time complexities using Big O notation.

Overview
The project includes the following sorting algorithms:

Bubble Sort
Insertion Sort
Selection Sort
Quick Sort
Shell Sort
Cocktail Shaker Sort
Counting Sort
Merge Sort
Heap Sort
Radix Sort
Bitonic Sort
Quick Sort (Hoare Partition Scheme)
Each algorithm is implemented to sort an array or a linked list of integers in ascending order, and the repository also provides detailed time complexity analyses for different cases (best, average, and worst).

Features
Stable Sorting Algorithms: Explore which sorting algorithms maintain the relative order of equal elements.
Big O Notation: Understand the time complexity of each algorithm in different scenarios.
Doubly Linked List Sorting: Some algorithms are implemented to sort doubly linked lists, with examples provided.
Array Sorting: Most algorithms are implemented for array sorting, with the array printed after each significant operation.
Usage
Each algorithm is provided as a C function. For example, to use the Bubble Sort implementation, you can include the sort.h header and call the bubble_sort function in your code.

#include "sort.h"

int main(void)
{
    int array[] = {19, 22, 3, 25, 18};
    size_t size = sizeof(array) / sizeof(array[0]);

    bubble_sort(array, size);

    return 0;
}

Time Complexity
The repository also includes files documenting the time complexities of each sorting algorithm:

0-O for Bubble Sort
1-O for Insertion Sort
2-O for Selection Sort
3-O for Quick Sort
... and more.
Each file lists the time complexity for the best, average, and worst-case scenarios.
