#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define NUM_POINTS 50

void drawChart(SDL_Renderer *renderer, SDL_Point points[]) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < NUM_POINTS; i++) {
        SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
    }

    SDL_RenderPresent(renderer);
}

void bubbleSort(SDL_Point points[], SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_POINTS - 1; i++) {
        for (int j = 0; j < NUM_POINTS - i - 1; j++) {
            if (points[j].y > points[j + 1].y) {
                SDL_Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;

                drawChart(renderer, points);
                SDL_Delay(50);
            }
        }
    }
}
