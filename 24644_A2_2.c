#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Part (i): Dynamic Input
int* input_array(int *size, int max_size) {
    int *arr = (int *)malloc(max_size * sizeof(int));
    int x, i = 0;

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter elements (negative number to stop):\n");

    while (i < max_size) {
        scanf("%d", &x);
        if (x < 0) break;

        *(arr + i) = x;
        i++;
    }

    *size = i;
    return arr;
}

// Part (ii): In-place Reverse
void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// Part (iii): Check Uniqueness
int check_unique_array(int *arr, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(arr + i) == *(arr + j)) {
                return 0; // Duplicate found
            }
        }
    }
    return 1; // All unique
}

// Main Function
int main() {
    int size = 0;
    int *array;
    int unique, i;

    printf("Max size of array: %d\n", MAX);

    array = input_array(&size, MAX);

    printf("\nOriginal Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }

    reverse_array(array, size);

    printf("\nReversed Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }

    unique = check_unique_array(array, size);

    if (unique)
        printf("\nAll elements are unique\n");
    else
        printf("\nDuplicates found\n");

    free(array);

    return 0;
}
