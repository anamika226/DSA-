#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Assume the current position is the minimum
        int min_idx = i;

        // Iterate through the unsorted portion to find the actual minimum
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

      
        if (min_idx != i) {
            swap(&array[min_idx], &array[i]);
        }
    }
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: \n");
    printArray(data, size);

    selectionSort(data, size);

    printf("Sorted array in Ascending Order: \n");
    printArray(data, size);
    
    return 0;
}
