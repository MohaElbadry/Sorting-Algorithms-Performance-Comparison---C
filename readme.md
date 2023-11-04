
# Sorting Algorithms Performance Comparison

This C program is designed to compare the performance of five different sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, and Quick Sort. 

## Description

The program begins by creating an array of a specified size (`arr_size`) and filling it with random numbers. For each sorting algorithm, the program creates a copy of the original array (since sorting is done in-place, which modifies the array), records the start time, sorts the array using the appropriate sorting function, records the end time, and then calculates and prints the time taken for the sorting process. After all sorting algorithms have been tested, the program frees the memory allocated for all arrays.

## Usage

To run the program, compile it with a C compiler and then execute the resulting binary. The program will print the time taken for each sorting algorithm to sort the array.

## Output

The output of the program is the time taken for each sorting algorithm to sort the array. The program does not print the sorted arrays due to their large size.

## Note

This program is useful for comparing the performance of different sorting algorithms. If you want to print the sorted arrays, you can call the `printArray` function after each sorting process.