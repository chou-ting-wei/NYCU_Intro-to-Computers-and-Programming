#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <stdlib.h>

void selSort(int* arr, int size);
void printArr(int* arr, int size);

int main() {
    int arr[SIZE], i;
    printf("Input number:\n");
    for (i = 0; i < SIZE; ++i) { scanf("%d", &arr[i]); }
    selSort(arr, SIZE);
    system("pause");
    return 0;
}

void printArr(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { printf("%d ", *(arr + i)); }
    printf("\n");
}

void selSort(int* arr, int size) {
    int i, j, tmp;
    for (i = 0; i < size - 1; ++i) {
        int minn = arr[i], idx = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < minn) {
                minn = arr[j];
                idx = j;
            }
        }
        if (idx != i) {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
        printf("Pass %d\n", i + 1);
        printArr(arr, size);
    }
}