#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int containsAll(const char *str, const char *charlist)
{
    int result = 0;
    while(*str)
    {
        if(!strchr(charlist, *str++))
        {
            result = -1;
            break;
        }
    }
    return result;
}

int main()
{
    int m, n;

    printf("Enter the length of the first string: ");
    scanf("%d", &m);
    getchar();

    printf("Enter the first string: ");
    char* mString = (char*)malloc((m + 1) * sizeof(char));
    fgets(mString, m + 1, stdin);
    mString[strcspn(mString, "\n")] = '\0';

    printf("Enter the length of the second string: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the second string: ");
    char* nString = (char*)malloc((n + 1) * sizeof(char));
    fgets(nString, n + 1, stdin);
    nString[strcspn(nString, "\n")] = '\0';

    

    if (!containsAll(mString, nString))
    {
        puts("Is a subset");
    }
    else
    {
        puts("Is not a subset");
    }
    return 0;
}