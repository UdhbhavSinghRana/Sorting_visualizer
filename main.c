#include <SDL2/SDL.h>
#include "SortingAlgo.h"
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

int partition(int arr[], int low, int high, SDL_Renderer *renderer) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            drawBars(renderer, arr);
            SDL_Delay(30);
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    drawBars(renderer, arr);
    SDL_Delay(30);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, SDL_Renderer *renderer) {
    if (low < high) {
        int pi = partition(arr, low, high, renderer);
        quickSort(arr, low, pi - 1, renderer);
        quickSort(arr, pi + 1, high, renderer);
    }
}
int showSortingOptions() {
    int choice;
    printf("Select a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort \n");
    printf("5. Quick Sort \n");
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
        case 4:
            mergeSort(arr, 0, NUM_BARS - 1, renderer);
            break;
        case 5:
            quickSort(arr, 0, NUM_BARS - 1, renderer);
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

