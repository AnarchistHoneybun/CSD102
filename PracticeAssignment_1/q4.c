// bubble sort

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size){
    int i, j, temp;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){

    int arr[5] = {5, 4, 3, 2, 1};
    int i;

    bubble_sort(arr, 5);

    for(i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}