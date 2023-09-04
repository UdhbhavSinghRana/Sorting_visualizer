#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <SDL2/SDL.h>

// Bubble Sort
void bubbleSort(int arr[], SDL_Renderer *renderer, int speed);

// Insertion Sort
void insertionSort(int arr[], SDL_Renderer *renderer, int speed);

//Selection Sort
void selectionSort(int arr[], SDL_Renderer *renderer, int speed);
// Quick Sort
void quickSort(int arr[], int low, int high, SDL_Renderer *renderer, int speed);

// Merge Sort
void mergeSort(int arr[], int left, int right, SDL_Renderer *renderer, int speed);


#endif
