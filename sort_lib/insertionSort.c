#include "SortingAlgo.h"
#include<unist.h>

void printVerticalBars(int arr[], int size) {
    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    for (int level = max_value; level > 0; level--) {
        for (int i = 0; i < size; i++) {
            if (arr[i] >= level) {
                printf("| ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void insertionSort(int arr[], int size) {
         
}
