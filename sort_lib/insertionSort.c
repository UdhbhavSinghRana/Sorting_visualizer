#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void insertionSort(int arr[], SDL_Renderer *renderer, int speed, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            drawBars(renderer, arr, size);
            SDL_Delay(40);
            j--;
        }
    }
}

