#include <stdio.h>
#include <stdlib.h>
void move(int,char,char,char);
int main()
{
   int n;
   printf("Enter the number of rings\n");
   scanf("%d",&n);
   move(n,'A','B','C');
   return 0;
}
void move(int n,char source,char temp,char dest)
{
    if(n==1)
        printf("Move from %c to %c\n",source,dest);
    else
    {
        move(n-1,source,dest,temp);
        move(1,source,temp,dest);
        move(n-1,temp,source,dest);
    }
}
