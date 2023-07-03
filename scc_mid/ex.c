#include <stdio.h>
#include <stdlib.h>

void invertArray(int *arr, int arr_count) {
    int start = 0;
    int end = arr_count - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int selectionSort(int* arr, int arr_count) {
    
    int swapCount = 0;

    for (int i = 0; i < arr_count - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < arr_count; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        if (minIndex != i) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            
            swapCount++;
        }
    }

    return swapCount;
}

int main() {
    int arr[] = {2,5,3,1};
    int arr_count = sizeof(arr) / sizeof(arr[0]);

    int frontswap = selectionSort(arr, arr_count);

    invertArray(arr, arr_count);

    int backswap = selectionSort(arr, arr_count);
    
    printf("Sorted array: ");
    for (int i = 0; i < arr_count; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nNumber of front swaps: %d\n", frontswap);

    printf("Number of back swaps: %d\n", backswap);
    
    return 0;
}
