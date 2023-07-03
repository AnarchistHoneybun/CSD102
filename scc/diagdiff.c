//todo write a function that returns the absolute difference between the sum of diagonals of a matrix

#include <stdio.h>
#include <stdlib.h>

int diagdiff(int arr_rows, int arr_columns, int arr[3][3]){
    int i, j, sum1 = 0, sum2 = 0;
    for(i=0;i<arr_rows;i++)
    {
        for(j=0;j<arr_columns;j++)
        {
            if(i == j)
            {
                sum1 += arr[i][j];
            }
            if(i+j == arr_rows-1)
            {
                sum2 += arr[i][j];
            }
        }
    }
    return abs(sum1-sum2);
}

int main(){

    int arr_rows, arr_columns;
    arr_rows = arr_columns = 3;
    int arr[3][3] = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};

    return 0;
}