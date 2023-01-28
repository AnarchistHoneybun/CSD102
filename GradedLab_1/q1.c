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


