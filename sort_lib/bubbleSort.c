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


void bubbleSortVisual(int arr[], SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_BARS - 1; i++) {
        for (int j = 0; j < NUM_BARS - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                drawBars(renderer, arr);
                SDL_Delay(30);
            }
        }
    }
}
