#include <stdio.h>
#include <stdlib.h>
#define Max 100

void insert(int* array, int* size, int value) {
    int hole;

    if (*size == Max) {
        printf("there is not enough place\n");
        return;
    }

    hole = ++(*size); // make hole equal to size after that add 1 to size
    for (; value < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }
    array[hole] = value;
}

void percolateDown(int* array, int size, int hole) {
    int child;
    int temp = array[hole];

    for (; hole * 2 <= size; hole = child) {
        child = hole * 2;
        if (child != size && array[child + 1] < array[child]) {
            child++;
        }
        if (temp > array[child]) {
            array[hole] = array[child];
        } else {
            break;
        }
    }
    array[hole] = temp;
}

void deleteMin(int* array, int* size) {
    if (*size <= 0) {
        return;
    } else {
        array[1] = array[(*size)--];
        percolateDown(array, *size, 1);
    }
}

void buildHead(int* array, int *size){
    if(*size <=0){
        return;
    }else{
        for(int i = (*size)/2; i> 0; i--){
            percolateDown(array,*size,i);
        }
    }
}

void print(int* array, int size) {
    for (int i = 0; i <= size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    int size2 = 10;
    int arr[Max] = {0, 13, 21, 16, 24, 31, 19, 68, 65, 26, 32};
    int arr2[Max] = {0, 32, 21, 16, 93, 19, 31, 68, 26, 11, 13};

    print(arr, size);

    insert(arr, &size, 14);
    print(arr, size);

    deleteMin(arr, &size);
    print(arr, size);

    print(arr2, size2);
    buildHead(arr2, &size2);
    print(arr2, size2);

    return 0;
}
