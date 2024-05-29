#include<stdio.h>
int main()
{
    int n,sum= 0;
    int result;
    printf("Enter number: \n");
    scanf("%d",&n);
    //O(n)
    for(int i = 1; i<=n;i++)
    {
        sum = sum+i;
    }

    // O(1)
    result = (n*n+n)/2;
    printf("The better result is: %d\n",result);

    printf("The sum is %d\n",sum);
    return 0;
}