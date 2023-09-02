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

void bubbleSort(int arr[], SDL_Renderer *renderer) {
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

void insertionSort(int arr[], SDL_Renderer *renderer) {
    for (int i = 1; i < NUM_BARS; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            drawBars(renderer, arr);
            SDL_Delay(30);
            j--;
        }
    }
}

void selectionSort(int arr[], SDL_Renderer *renderer) {
    for (int i = 0 ; i < NUM_BARS - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < NUM_BARS; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        drawBars(renderer, arr);
        SDL_Delay(30);
    }
}

int showSortingOptions() {
    int choice;
    printf("Select a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    // Add more options for other sorting algorithms here

    printf("Enter the number of your choice: ");
    scanf("%d", &choice);

    return choice;
}

void chooseSortingAlgorithm(int arr[], SDL_Renderer *renderer, int algorithm) {
    switch (algorithm) {
        case 1:
            bubbleSort(arr, renderer);
            break;
        case 2:
            insertionSort(arr, renderer);
            break;
        case 3:
            selectionSort(arr, renderer);
            break;
        // Add more cases for other sorting algorithms as needed
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

    int arr[NUM_BARS];
    srand(time(NULL));
    for (int i = 0; i < NUM_BARS; i++) {
        arr[i] = rand() % (SCREEN_HEIGHT - 50) + 50;
    }
    int choice = showSortingOptions();
    chooseSortingAlgorithm(arr, renderer, choice); 

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

