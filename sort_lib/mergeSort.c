#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define NUM_BARS 50
#define BAR_WIDTH (SCREEN_WIDTH / NUM_BARS)

void drawBars(SDL_Renderer *renderer, int arr[]) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < NUM_BARS; i++) {
        SDL_Rect bar = {i * BAR_WIDTH, SCREEN_HEIGHT - arr[i], BAR_WIDTH, arr[i]};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &bar);
    }

    SDL_RenderPresent(renderer);
}
void merge(int arr[], int left, int mid, int right, SDL_Renderer *renderer) {
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

        drawBars(renderer, arr);
        SDL_Delay(30);
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;

        drawBars(renderer, arr);
        SDL_Delay(30);
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;

        drawBars(renderer, arr);
        SDL_Delay(30);
    }
}

void mergeSort(int arr[], int left, int right, SDL_Renderer *renderer) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, renderer);
        mergeSort(arr, mid + 1, right, renderer);

        merge(arr, left, mid, right, renderer);
    }
}
