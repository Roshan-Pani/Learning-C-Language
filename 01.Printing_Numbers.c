#include<stdio.h>
int main ()
{
    int i,m,n;
    printf("enter the value of m: "); // take input of range
    scanf("%d",&m);
    printf("enter the value of n: ");
    scanf("%d",&n);
    {
        for(i=m;i<=n;i++) // This is a for loop
        printf("%d ",i);  // print the value of i in each iteration
    }
    return 0;
}