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
    FILE *dataFile,*bubblefile,*selectionfile,*insertionfile,*mergefile,*quickfile;
    int arr_size;

    // Open a data file for storing performance data
    // dataFile = fopen("sorting_data.txt", "w");


for (arr_size=1000; arr_size <= 10000; arr_size =arr_size + 1000) {
        // Allocate memory for the array
        int *arr = (int *)malloc(arr_size * sizeof(int));
        int *arr_bubble = (int *)malloc(arr_size * sizeof(int));
        int *arr_selection = (int *)malloc(arr_size * sizeof(int));
        int *arr_insertion = (int *)malloc(arr_size * sizeof(int));
        int *arr_merge = (int *)malloc(arr_size * sizeof(int));
        int *arr_quick = (int *)malloc(arr_size * sizeof(int));

       
    for(int j=0;j<3;j++){
    // Initialize the array with random data
        if (j==0)
        {
            for (int i = 0; i < arr_size; i++) {
            arr[i] = rand();
        }
        }
        if (j==1)
        {
            for (int i = 0; i < arr_size; i++) {
            arr[i] = i;
        }}
        if (j==2)
        {
            for (int i = arr_size; i > 0; i--) {
            arr[i] = i;
        }}

        clock_t start, end;
        double cpu_time_used;
            // Test Bubble Sort
        
        memcpy(arr_bubble, arr, arr_size * sizeof(int));
        printf("Start - Bubble Sort: \n");
        cpu_time_used=0;
        start = clock();
        bubble_sort(arr_bubble, arr_size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);
        printf("Sorted array using Bubble Sort: \n\n");
            // Store performance data in the data file
        bubblefile = j==0?fopen("bubbledata(rand).txt", "a"):j==1?fopen("bubbledata(ord).txt", "a"):fopen("bubbledata(rev).txt", "a");
        fprintf(bubblefile, "BubbleSort %d %f \n", arr_size, cpu_time_used);
        fclose(bubblefile);
            // You can do the same for other sorting algorithms
        // Test Selection Sort
        memcpy(arr_selection, arr, arr_size * sizeof(int));    
        printf("Start - Selection Sort: \n");
        cpu_time_used=0;
        start = clock();
        selection_sort(arr_selection, arr_size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);
        printf("Sorted array using Selection Sort: \n\n\n");

        selectionfile = j==0?fopen("selectiondata(rand).txt", "a"):j==1?fopen("selectiondata(ord).txt", "a"):fopen("selectiondata(rev).txt", "a");
        fprintf(selectionfile, "SelectionSort %d %f \n", arr_size, cpu_time_used);
        fclose(selectionfile);

        // Test Insertion Sort
        memcpy(arr_insertion, arr, arr_size * sizeof(int));
        printf("Start - Insertion Sort: \n");
        cpu_time_used=0;
        start = clock();
        insertion_sort(arr_insertion, arr_size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Insertion Sort: %f seconds\n", cpu_time_used);
        printf("Sorted array using Insertion Sort: \n\n\n");

        insertionfile = j==0?fopen("insertiondata(rand).txt", "a"):j==1?fopen("insertiondata(ord).txt", "a"):fopen("insertiondata(rev).txt", "a");
        fprintf(insertionfile, "InsertionSort %d %f \n", arr_size, cpu_time_used);
        fclose(insertionfile);

        // Test Merge Sort
        memcpy(arr_merge, arr, arr_size * sizeof(int));
        printf("Start - Merge Sort: \n");
        cpu_time_used=0;
        start = clock();
        merge_sort(arr_merge, 0, arr_size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Merge Sort: %f seconds\n", cpu_time_used);
        printf("Sorted array using Merge Sort: \n\n\n");

        mergefile = j==0?fopen("mergedata(rand).txt", "a"):j==1?fopen("mergedata(ord).txt", "a"):fopen("mergedata(rev).txt", "a");
        fprintf(mergefile, "MergeSort %d %f \n", arr_size, cpu_time_used);
        fclose(mergefile);

        // Test Quick Sort
        memcpy(arr_quick, arr, arr_size * sizeof(int));
        printf("Start - Quick Sort: \n");
        cpu_time_used=0;
        start = clock();
        quick_sort(arr_quick, 0, arr_size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Quick Sort: %f seconds\n", cpu_time_used);
        printf("Sorted array using Quick Sort: \n\n\n");

        quickfile = j==0?fopen("quickdata(rand).txt", "a"):j==1?fopen("quickdata(ord).txt", "a"):fopen("quickdata(rev).txt", "a");
        fprintf(quickfile, "QuickSort %d %f \n", arr_size, cpu_time_used);
        fclose(quickfile);
    }   // Remember to free the allocated memory
        free(arr);
        free(arr_bubble);
        free(arr_selection);
        free(arr_insertion);
        free(arr_merge);
        free(arr_quick);
}

    //*****************************random data*******************************************
    dataFile = popen("gnuplot -persistent", "w");
    fprintf(dataFile, "set title 'Performance des Algorithmes de Tri (Random DATA)'\n");
    fprintf(dataFile, "set xlabel 'Array Size'\n");
    fprintf(dataFile, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(dataFile, "set key top left\n");

    fprintf(dataFile,"set style data linespoints\n");
    fprintf(dataFile,"set style line 1 lc rgb 'red' lw 1\n");
    fprintf(dataFile,"set style line 2 lc rgb 'blue' lw 1\n");
    fprintf(dataFile,"set style line 3 lc rgb 'green' lw 1\n");
    fprintf(dataFile,"set style line 4 lc rgb 'purple' lw 1\n");
    fprintf(dataFile,"set style line 5 lc rgb 'orange' lw 1\n");

    fprintf(dataFile, "plot 'bubbledata(rand).txt' using 2:3 with linespoints ls 1 title 'Bubble Sort', \\\n");
    fprintf(dataFile, "     'selectiondata(rand).txt' using 2:3 with linespoints ls 2 title 'Selection Sort', \\\n");
    fprintf(dataFile, "     'insertiondata(rand).txt' using 2:3 with linespoints ls 3 title 'Insertion Sort', \\\n");
    fprintf(dataFile, "     'mergedata(rand).txt' using 2:3 with linespoints ls 4 title 'Merge Sort', \\\n");
    fprintf(dataFile, "     'quickdata(rand).txt' using 2:3 with linespoints ls 5 title 'Quick Sort'\n");

    fclose(dataFile);

    //*****************************ordered data*******************************************
    dataFile = popen("gnuplot -persistent", "w");
    fprintf(dataFile, "set title 'Performance des Algorithmes de Tri (Ordered DATA)'\n");
    fprintf(dataFile, "set xlabel 'Array Size'\n");
    fprintf(dataFile, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(dataFile, "set key top left\n");

    fprintf(dataFile,"set style data linespoints\n");
    fprintf(dataFile,"set style line 1 lc rgb 'red' lw 1\n");
    fprintf(dataFile,"set style line 2 lc rgb 'blue' lw 1\n");
    fprintf(dataFile,"set style line 3 lc rgb 'green' lw 1\n");
    fprintf(dataFile,"set style line 4 lc rgb 'purple' lw 1\n");
    fprintf(dataFile,"set style line 5 lc rgb 'orange' lw 1\n");

    fprintf(dataFile, "plot 'bubbledata(ord).txt' using 2:3 with linespoints ls 1 title 'Bubble Sort', \\\n");
    fprintf(dataFile, "     'selectiondata(ord).txt' using 2:3 with linespoints ls 2 title 'Selection Sort', \\\n");
    fprintf(dataFile, "     'insertiondata(ord).txt' using 2:3 with linespoints ls 3 title 'Insertion Sort', \\\n");
    fprintf(dataFile, "     'mergedata(ord).txt' using 2:3 with linespoints ls 4 title 'Merge Sort', \\\n");
    fprintf(dataFile, "     'quickdata(ord).txt' using 2:3 with linespoints ls 5 title 'Quick Sort'\n");

    fclose(dataFile);
    //*****************************ordered data*******************************************
    dataFile = popen("gnuplot -persistent", "w");
    fprintf(dataFile, "set title 'Performance des Algorithmes de Tri (Reversed DATA)'\n");
    fprintf(dataFile, "set xlabel 'Array Size'\n");
    fprintf(dataFile, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(dataFile, "set key top left\n");

    fprintf(dataFile,"set style data linespoints\n");
    fprintf(dataFile,"set style line 1 lc rgb 'red' lw 1\n");
    fprintf(dataFile,"set style line 2 lc rgb 'blue' lw 1\n");
    fprintf(dataFile,"set style line 3 lc rgb 'green' lw 1\n");
    fprintf(dataFile,"set style line 4 lc rgb 'purple' lw 1\n");
    fprintf(dataFile,"set style line 5 lc rgb 'orange' lw 1\n");

    fprintf(dataFile, "plot 'bubbledata(rev).txt' using 2:3 with linespoints ls 1 title 'Bubble Sort', \\\n");
    fprintf(dataFile, "     'selectiondata(rev).txt' using 2:3 with linespoints ls 2 title 'Selection Sort', \\\n");
    fprintf(dataFile, "     'insertiondata(rev).txt' using 2:3 with linespoints ls 3 title 'Insertion Sort', \\\n");
    fprintf(dataFile, "     'mergedata(rev).txt' using 2:3 with linespoints ls 4 title 'Merge Sort', \\\n");
    fprintf(dataFile, "     'quickdata(rev).txt' using 2:3 with linespoints ls 5 title 'Quick Sort'\n");

    fclose(dataFile);
    
    return 0;
}
