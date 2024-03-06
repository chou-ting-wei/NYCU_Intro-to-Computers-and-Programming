#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <stdlib.h>

void insSort(int* arr, int size);
void printArr(int* arr, int size);

int main() {
    int arr[SIZE], i;
    printf("Input number:\n");
    for (i = 0; i < SIZE; ++i) { scanf("%d", &arr[i]); }
    insSort(arr, SIZE);
    system("pause");
    return 0;
}

void printArr(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { printf("%d ", *(arr + i)); }
    printf("\n");
}

void insSort(int* arr, int size) {
    int i, j, k, tmp;
    for (i = 1; i < size; ++i) {
        for (j = i, k = i - 1; k >= 0; j--, k--) {
            if (arr[j] < arr[k]) {
                int tmp = arr[j];
                arr[j] = arr[k];
                arr[k] = tmp;
            }
        }
        printf("Pass %d\n", i);
        printArr(arr, size);
    }
}