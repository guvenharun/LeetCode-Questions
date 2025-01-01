#include <stdio.h>
#include <stdlib.h>
#define Max 100

void percolateDown(int* array, int size, int hole) {
    int child;
    int temp = array[hole];

    for (; hole * 2 + 1 < size; hole = child) {
        child = hole * 2 + 1;
        if (child + 1 < size && array[child + 1] > array[child]) {
            child++;
        }
        if (temp < array[child]) {
            array[hole] = array[child];
        } else {
            break;
        }
    }
    array[hole] = temp;
}

void buildHeap(int* array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        percolateDown(array, size, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    buildHeap(nums, numsSize);
    for (int i = numsSize - 1; i >= numsSize - k + 1; i--) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        percolateDown(nums, i, 0);
    }
    return nums[0];
}

void print(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3,2,3,1,2,4,5,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print(arr, size);

    buildHeap(arr, size);
    printf("Heapified array:\n");
    print(arr, size);

    int k = 5;
    int kthLargest = findKthLargest(arr, size, k);
    printf("%dth largest element: %d\n", k, kthLargest);

    return 0;
}
