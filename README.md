

# C Sorting Algorithms

This project implements different sorting algorithms in C including sorts on arrays and linked lists.

## Sorting Algorithms

The following sorting algorithms are implemented:

- Bubble Sort - basic sorting algorithm that repeatedly steps through an array, compares adjacent elements and swaps them if in the wrong order
- Insertion Sort - algorithm that sorts elements of an array by shifting elements and inserting them in their correct position
- Quicksort - efficient divide and conquer algorithm that picks a pivot element and partitions the array iteratively
- Merge Sort - divide and conquer algorithm that divides the array into subarrays, sorts them and merges subarrays

### Data Structures

- Arrays - the basic C array data structure is used
- Linked Lists - doubly linked list (see definition in sort.h)

## Files

| File | Description |
|-------|--------------|
| sort.h | Header file with data structures, prototypes |   
| print_*.c | Print functions for testing |
| *.c | Implementation files for sorting algorithms |
| README.md | This file |

## Usage 

The print functions can be used to test out the sorting algorithms on arrays and linked lists. Pass different data structures to the sort functions to check output.

Compile with:

```
gcc *.c -o sort
```

## Authors

Leornadia
