#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void merge(int arr[], int left, int mid, int right, SDL_Renderer *renderer, int speed, int size) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;

        drawBars(renderer, arr, size);
        SDL_Delay(speed);
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;

        drawBars(renderer, arr, size);
        SDL_Delay(speed);
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;

        drawBars(renderer, arr, size);
        SDL_Delay(speed);
    }
}

void mergeSort(int arr[], int left, int right, SDL_Renderer *renderer, int speed, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, renderer, speed, size);
        mergeSort(arr, mid + 1, right, renderer, speed, size);

        merge(arr, left, mid, right, renderer, speed, size);
    }
}
