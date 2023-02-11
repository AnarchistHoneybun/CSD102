/*Question: Write a program to check if a palindromic string has been rotated or not. 

Input:
String

Output:
YES
Palindrome before rotation (unique answer)
OR
NO

Example:

Input:
AABCDDCB

Output:
YES
ABCDDCBA
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pal_check(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int rot_pal_check(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        if (pal_check(str))
            return 1;
        char temp = str[0];
        int j;
        for (j = 0; j < len - 1; j++)
            str[j] = str[j + 1];
        str[j] = temp;
    }
    return 0;
}

int main()
{
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    if ( len != 1 && pal_check(str)){
        printf("NO");
        return 0;
    }
    if (rot_pal_check(str))
        printf("YES\n%s", str);
    else
        printf("NO");
    return 0;
}
