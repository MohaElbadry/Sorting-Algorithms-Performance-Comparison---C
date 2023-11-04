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
    FILE *dataFile;
    char *title="";
    char *nameFile="";
    // int j=0;
    int arr_size = 5000;
    // Allocate memory for the array
    int *arr = (int*)malloc(arr_size * sizeof(int));
    int *arr_bubble = (int*)malloc(arr_size * sizeof(int));
    int *arr_selection = (int*)malloc(arr_size * sizeof(int));
    int *arr_insertion = (int*)malloc(arr_size * sizeof(int));
    int *arr_merge = (int*)malloc(arr_size * sizeof(int));
    int *arr_quick = (int*)malloc(arr_size * sizeof(int));

for(int j=0;j<3;j++){
    // Initialize the array with random data
    if (j==0)
    {
        title = "Random";
        nameFile="sorting_data(rand).dat";
        for (int i = 0; i < arr_size; i++) {
        arr[i] = rand();
    }
    }
    if (j==1)
    {
        title = "Ordred";
        nameFile="sorting_data(ord).dat";
        for (int i = 0; i < arr_size; i++) {
        arr[i] = i;
    }}
    if (j==2)
     {
        title = "Reversed";
        nameFile="sorting_data(rev).dat";
        for (int i = arr_size; i > 0; i--) {
        arr[i] = i;
    }}
    

    
    clock_t start, end;
    double cpu_time_used;
    printf("Original array: \n");
    // To avoid printing the entire array, we'll print a subset of it

    
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

    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1? fopen("sorting_data(ord).dat", "a"): fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile, "BubbleSort %f\n", cpu_time_used);
    fclose(dataFile);


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

    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1? fopen("sorting_data(ord).dat", "a"): fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile, "SelectionSort %f\n", cpu_time_used);
    fclose(dataFile);


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

    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1? fopen("sorting_data(ord).dat", "a"): fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile, "InsertionSort %f\n", cpu_time_used);
    fclose(dataFile);


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

    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1? fopen("sorting_data(ord).dat", "a"): fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile, "MergSort %f\n", cpu_time_used);
    fclose(dataFile);


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

    // dataFile = fopen("sorting_data.dat", "a");
    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1?fopen("sorting_data(ord).dat", "a"):fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile, "QuickSort %f\n", cpu_time_used);
    fclose(dataFile);

    dataFile = j==0?fopen("sorting_data(rand).dat", "a"):j==1?fopen("sorting_data(ord).dat", "a"):fopen("sorting_data(rev).dat", "a");
    fprintf(dataFile,"%d s %d\n",arr_size,0);
    fclose(dataFile);

    // GNU plot printing Data
    dataFile = popen("gnuplot -persistent", "w");
    fprintf(dataFile,"set title 'Performance des Algorithmes de Tri (%s Data)'\n",title);
    fprintf(dataFile,"set xlabel 'Algorithme de Tri'\n");
    fprintf(dataFile,"set ylabel 'Temps d exécution (secondes)'\n");
    fprintf(dataFile,"set style data linespoints\n");
    fprintf(dataFile,"set xtics rotate by -45\n");
    fprintf(dataFile,"set grid\n");
    fprintf(dataFile,"plot '%s' using 2:xtic(1) with linespoints title 'Temps d exécution'\n",nameFile);
}
    // system("gnuplot plot_script.gnu");
    // Remember to free the allocated memory
    free(arr);
    free(arr_bubble);
    free(arr_selection);
    free(arr_insertion);
    free(arr_merge);
    free(arr_quick);
    
    return 0;
}