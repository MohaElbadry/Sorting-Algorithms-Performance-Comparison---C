#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Bubble_Sort.c"
#include "Selection_Sort.c"
#include "Insertion_Sort.c"
#include "Merge_Sort.c"
#include "Quick_Sort.c"

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr_size = 100000;
    // Allocate memory for the array
    int *arr = (int*)malloc(arr_size * sizeof(int));

    // Initialize the array with random data
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand();
    }
    clock_t start, end;
    double cpu_time_used;
    printf("Original array: \n");
    // To avoid printing the entire array, we'll print a subset of it


    // Test Bubble Sort
    int *arr_bubble = (int*)malloc(arr_size * sizeof(int));
    memcpy(arr_bubble, arr, arr_size * sizeof(int));
    printf("Start - Bubble Sort: \n");
    cpu_time_used=0;
    start = clock();
    bubble_sort(arr_bubble, arr_size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);
    printf("Sorted array using Bubble Sort: \n\n");

    // Test Selection Sort
    int *arr_selection = (int*)malloc(arr_size * sizeof(int));
    memcpy(arr_selection, arr, arr_size * sizeof(int));    
    printf("Start - Selection Sort: \n");
    cpu_time_used=0;
    start = clock();
    selection_sort(arr_selection, arr_size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);
    printf("Sorted array using Selection Sort: \n\n\n");


    // Test Insertion Sort
    int *arr_insertion = (int*)malloc(arr_size * sizeof(int));
    memcpy(arr_insertion, arr, arr_size * sizeof(int));
    printf("Start - Insertion Sort: \n");
    cpu_time_used=0;
    start = clock();
    insertion_sort(arr_insertion, arr_size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Insertion Sort: %f seconds\n", cpu_time_used);
    printf("Sorted array using Insertion Sort: \n\n\n");


    // Test Merge Sort
    int *arr_merge = (int*)malloc(arr_size * sizeof(int));
    memcpy(arr_merge, arr, arr_size * sizeof(int));
    printf("Start - Merge Sort: \n");
    cpu_time_used=0;
    start = clock();
    merge_sort(arr_merge, 0, arr_size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort: %f seconds\n", cpu_time_used);
    printf("Sorted array using Merge Sort: \n\n\n");


    // Test Quick Sort
    int *arr_quick = (int*)malloc(arr_size * sizeof(int));
    memcpy(arr_quick, arr, arr_size * sizeof(int));
    printf("Start - Quick Sort: \n");
    cpu_time_used=0;
    start = clock();
    quick_sort(arr_quick, 0, arr_size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort: %f seconds\n", cpu_time_used);
    printf("Sorted array using Quick Sort: \n\n\n");

    // Remember to free the allocated memory
    free(arr);
    free(arr_bubble);
    free(arr_selection);
    free(arr_insertion);
    free(arr_merge);
    free(arr_quick);
    return 0;
}

