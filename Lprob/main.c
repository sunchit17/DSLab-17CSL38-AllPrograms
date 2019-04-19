#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int create(int num)
{
    int key;
    key=num%100;
    return key;
}
void linear_prob(int a[MAX],int key,int num)
{
    int i,flag,count;
    count=10;
    flag=0;
    if(a[key]==-1)
        a[key]=num;
    else
    {
       for(i=10;i<MAX;i++)
            if(a[i]!=-1)
            count++;
       if(count==MAX)
       {
           printf("Hash table is full\n");
           display(a);
           exit(1);
       }
       for(i=key+1;i<MAX;i++)
       {
           if(a[i]==-1)
           {
               a[i]=num;
               flag=1;
               break;
           }
       }
       for(i=10;i<key&&flag==0;i++)
       {
           if(a[i]==-1)
           {
               a[i]=num;
               flag=1;
               break;
           }
       }
    }
}
void display(int a[MAX])
{
    int i;
    printf("\nKEY\tID NO.\n");
    for(i=10;i<MAX;i++)
        printf("%d\t%d\n",i,a[i]);
}
int main()
{
    int a[MAX];
    int i,key,ele,ans;
    for(i=10;i<MAX;i++)
        a[i]=-1;
    printf("Collision handling by linear probing\n");
    do
    {
        printf("Enter four digit ID no.\n");
        scanf("%d",&ele);
        key=create(ele);
        linear_prob(a,key,ele);
        printf("Press 1 to continue\n");
        scanf("%d",&ans);
         }while(ans==1);

         display(a);

    return 0;
}
