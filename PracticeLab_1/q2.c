/*Question: Write a RECURSIVE program which computes the sum of the series m2 + (m+1)2 + . . . . . . . .+n2 and prints the sum.

Input:

N M

Output:

The sum of series

Example 1:

Input:
6 2

Output:
90

*/

#include <stdio.h>
#include <stdlib.h>

int addup(int n, int m, int sum);

int main(){
    
    int n,m,sum,result;
    scanf("%d %d", &n,&m);
    sum=0;
    result=addup(n,m,sum);
    printf("%d",result);
    
    return 0;
}

int addup(int n, int m, int sum){
    if(m<n){
        sum+=(m*m)+(n*n);
        m++;
        n--;
        addup(n,m,sum);
    }else if(m==n){
        sum+=m*m;
        return sum;
    }else{
        return sum;
    }
}
