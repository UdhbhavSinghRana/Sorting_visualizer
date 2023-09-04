#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void selectionSort(int arr[], SDL_Renderer *renderer, int speed, int size) {
    for (int i = 0 ; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        drawBars(renderer, arr, size);
        SDL_Delay(speed);
    }
}
