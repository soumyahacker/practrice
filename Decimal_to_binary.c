#include<stdio.h>
int main()
{
    int n = 0,i = 0,remainder;
    int a[100];
    printf("Enter a decimal number : \n");
    scanf("%d",&n);

    while (n)
    {
        /* code */
        remainder = n%2;
        n = n/2;
        a[i] = remainder;
        i++;
    }
    for(int j = i-1; j>=0;j--)
    {
        printf("%d",a[j]);
    }
    
    return 0;
}