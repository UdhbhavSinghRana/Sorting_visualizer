#include <SDL2/SDL.h>
#include "sort_lib/SortingAlgo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void drawBars(SDL_Renderer *renderer, int arr[], int size) {
    int BAR_WIDTH = SCREEN_WIDTH / size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < size; i++) {
        SDL_Rect bar = {i * BAR_WIDTH, SCREEN_HEIGHT - arr[i], BAR_WIDTH, arr[i]};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &bar);
    }

    SDL_RenderPresent(renderer);
}

int showSortingOptions() {
    int choice;
    printf("Select a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort \n");
    printf("5. Quick Sort \n");

    printf("Enter the ber of your choice: ");
    scanf("%d", &choice);

    return choice;
}
int chooseSize() {
    int size;
    printf("Choose size of array: ");
    scanf("%d", &size);
    
    return size;
}
int chooseSpeed() {
    int speed;
    printf("Select speed of algo: \n");
    printf("1. Slow\n");
    printf("2. Medium\n");
    printf("3. Fast\n");
    printf("4. Very Fast\n");
    
    printf("Enter the ber of your choice: ");
    scanf("%d", &speed);

    switch (speed) {
        case 1:
            speed = 50;
            break;
        case 2:
            speed = 20;
            break;
        case 3:
            speed = 10;
            break;
        case 4:
            speed = 2;
            break;
    } 

    return speed;
}

void chooseSortingAlgorithm(int arr[], SDL_Renderer *renderer, int algorithm, int speed, int size) {
    switch (algorithm) {
        case 1:
            insertionSort(arr, renderer, speed, size);
            break;
        case 2:
            insertionSort(arr, renderer, speed, size);
            break;
        case 3:
            selectionSort(arr, renderer, speed, size);
            break;
        case 4:
            mergeSort(arr, 0, size - 1, renderer, speed, size);
            break;
        case 5:
            quickSort(arr, 0, size - 1, renderer, speed, size);
            break;
        default:
            printf("Invalid algorithm choice.\n");
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

    
    int size = chooseSize();
    int arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (SCREEN_HEIGHT - 50) + 50;
    }
    int choice = showSortingOptions();
    int speed = chooseSpeed();
    chooseSortingAlgorithm(arr, renderer, choice, speed, size); 

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

