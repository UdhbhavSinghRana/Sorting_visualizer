#include "SortingAlgo.h"
#include<unistd.h>
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

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j +1];
                arr[j + 1] = temp;
            }

            printVerticalBars(arr, size);
            
            sleep(1);
        }
    }    
}
