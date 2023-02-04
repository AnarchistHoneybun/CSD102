/*Q: Write a C program to multiply two matrices of size NxN.

Input:
Size N
N*N elements from Matrix 1
N*N elements from Matrix 2

Output:
N*N elements from (Matrix 1 x Matrix 2)

Example:

Input:
3
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 0 1 2

Output:
18 24 30 51 66 81 84 108 132

*/

#include <stdio.h>
#include <stdlib.h>

void multiply(int **a, int **b, int **result, int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result[i][j] = 0;
            for (k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int **a = (int**) malloc(N * sizeof(int*));
    int **b = (int**) malloc(N * sizeof(int*));
    int **result = (int**) malloc(N * sizeof(int*));
    int i, j;
    for (i = 0; i < N; i++) {
        a[i] = (int*) malloc(N * sizeof(int));
        b[i] = (int*) malloc(N * sizeof(int));
        result[i] = (int*) malloc(N * sizeof(int));
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    multiply(a, b, result, N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
    }

    return 0;
}


