// program to find median of two sorted arrays

#include <stdio.h>
#include <stdlib.h>

// // TODO modify median finder to take average of two middle elements if size*2 is even
// TODO modify median_finder to account for dissimilar array sizes


float median_finder(float arr1[], float arr2[], int size){

    int i = 0;
    int j = 0;
    int k = 0;
    float arr3[size*2];

    while(i < size && j < size){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size){
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size){
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    if(size*2 % 2 == 0){
        //printf("%d %d %d", arr3[size], arr3[size - 1], size);
        return (arr3[size] + arr3[size - 1]) / 2;
    }
    else{
        return arr3[size];
    }
}

int main(){

    float arr1[5] = {1, 2, 3, 4, 5};
    float arr2[5] = {6, 7, 8, 9, 10};

    printf("Median is %f", median_finder(arr1, arr2, 5));

    return 0;
}