#include <stdio.h>
#include <stdlib.h>

int recursivePower(int num, int pow){
    if(pow == 0){
        return 1;
    }
    else{
        return num * recursivePower(num, pow - 1);
    }
}

int main(){
    int num;
    int pow;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a power: ");
    scanf("%d", &pow);

    printf("%d to the power of %d is %d", num, pow, recursivePower(num, pow));

    //* 2^16 is 65536

    return 0;

}