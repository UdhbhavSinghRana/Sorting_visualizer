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

void selectionSort(int arr[], SDL_Renderer *renderer) {
    for (int i = 0 ; i < NUM_BARS - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < NUM_BARS; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = i;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        drawBars(renderer, arr);
        SDL_Delay(30);
    }
}
