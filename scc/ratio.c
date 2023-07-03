//todo write a function that prints the ratio of elements that are positive negative and zero in the array
// ratio should be printed till 6 decimal places

#include <stdio.h>
#include <stdlib.h>

int ratio(int arr[], int n){
    int i, pos = 0, neg = 0, zero = 0;
    for(i=0;i<n;i++)
    {
        if(arr[i] > 0)
        {
            pos++;
        }
        else if(arr[i] < 0)
        {
            neg++;
        }
        else
        {
            zero++;
        }
    }
    
    //6 decimal places in the ratio
    printf("%f\n", (float)pos/n);
    printf("%f\n", (float)neg/n);
    printf("%f\n", (float)zero/n);

    return 0;
}

int main(){

    int arr[] = {-6, 5, 8, -4, 1, -7, 9, 3, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    ratio(arr, n);
    return 0;
}