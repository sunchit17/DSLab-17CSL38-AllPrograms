#include <stdio.h>
#include <stdlib.h>
int ack(int m,int n)
{
    if(m==0)
        return n+1;
    else if (m>0&&n==0)
        return ack(m-1,1);
    else if(m>0&&n>0)
        return ack(m-1,ack(m,n-1));
}
int main()
{
    int m,n;
    int r;
    printf("Enter m and n\n");
    scanf("%d",&m);
    scanf("%d",&n);
    r = ack(m,n);
    printf("Value returned is %d",r);
    return 0;
}
