#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n = mid - left + 1, m = right - mid;

    int l[n + 1], r[m + 1];

    // Use sentinel values
    l[n] = 999999;
    r[m] = 999999;

    for (int i = 0; i < n; i++) l[i] = arr[left + i];
    for (int i = 0; i < m; i++) r[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (l[i] <= r[j])
            arr[k] = l[i++];
        else
            arr[k] = r[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[10] = {5, 4, 3, 2, 6, 1, 7, 8, 9, 0};

    mergeSort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
