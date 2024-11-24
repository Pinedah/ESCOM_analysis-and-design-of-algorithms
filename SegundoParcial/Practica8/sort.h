#include <stdio.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size) {
    char* p1 = (char*)a;
    char* p2 = (char*)b;

    for (size_t i = 0; i < size; i++) {
        char temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}

int partition(void* base, int low, int high, size_t size, int (*compare)(const void*, const void*)) {
    char* array = (char*)base;
    void* pivot = array + high * size; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(array + j * size, pivot) < 0) {
            i++;
            swap(array + i * size, array + j * size, size);
        }
    }
    swap(array + (i + 1) * size, array + high * size, size);
    return i + 1;
}

// Función recursiva de quicksort
void quicksort(void* base, int low, int high, size_t size, int (*compare)(const void*, const void*)) {
    if (low < high) {
        int pi = partition(base, low, high, size, compare);

        quicksort(base, low, pi - 1, size, compare);
        quicksort(base, pi + 1, high, size, compare); 
    }
}

void sort(void* base, size_t num_elements, size_t size, int (*compare)(const void*, const void*)) {
    if (num_elements > 1) {
        quicksort(base, 0, num_elements-1, size, compare);
    }
}
