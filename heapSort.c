#include <stdio.h>
#define max 100

int heapsize = 0; // Will be initialized in main

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}
int parent(int i) {
    return (i-1)/2;
}

void maxHeapify(int arr[], int i) {
    int l = left(i), r = right(i), largest = i;

    if (l < heapsize && arr[l] > arr[largest]) largest = l;
    if (r < heapsize && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(int arr[]) {
    for (int i = (heapsize / 2) - 1; i >= 0; i--)
        maxHeapify(arr, i);
}

void heapSort(int arr[]) {
    buildMaxHeap(arr);

    for (int i = heapsize - 1; i > 0; i--) {
        // Swap max element with the last element in heap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapsize--; // Reduce heap size
        maxHeapify(arr, 0); // Heapify the root
    }
}

int main() {
    int arr[10] = {5, 4, 3, 2, 6, 1, 7, 8, 9, 0};
    heapsize = 10;

    heapSort(arr);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
