/*Question: Write the code for Linear Search in C? [ Array has zero-based indexing]

Input:

Size N followed by N integers
Integer to be searched

Output:

(The index of integer) or (-1 if integer not found)

Example 1:

Input:
5 5 1 4 3 2
4

Output:
2

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    scanf("%d", &n);
    int *arr;
    arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int f;
    scanf("%d", &f);
    int result=-1;
    for(int i=0;i<n;i++){
        if(f==arr[i]){
            result=i;
        }
    }
    printf("%d", result);
    return 0;
}