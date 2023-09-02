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

void bubbleSortVisual(SDL_Point points[], SDL_Renderer *renderer) {
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

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "Sorting Visualization",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Point points[NUM_POINTS];
    srand(time(NULL));
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i] = (SDL_Point){i * (SCREEN_WIDTH / NUM_POINTS), SCREEN_HEIGHT - (rand() % (SCREEN_HEIGHT - 50) + 50)};
    }

    bubbleSortVisual(points, renderer);

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
