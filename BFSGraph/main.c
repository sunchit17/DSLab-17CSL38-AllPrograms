#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,i,j,source;
int visited[10];
void create()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
}
void bfs()
{
    int q[10],u,rear=-1,front=0;
    printf("Enter source vertex to find reachability\n");
    scanf("%d",&source);
    q[++rear]=source;
    visited[source]=1;
    printf("Reachable nodes are:\n");
    while(front<=rear)
    {
        u=q[front++];
        for(i=1;i<=n;i++)
        {
            if(a[u][i]==1&&visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
                printf("%d\t",i);
            }
        }
    }

}
int main()
{
    int ch;
    while(1)
    {
     printf("\n1.Create Graph\n2.BFS\n3.Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:create();break;
         case 2:bfs();
                for(i=1;i<=n;i++){
                    if(visited[i]==0)
                    printf("\n%d vertex is not reachable",i);}
                break;
        default:exit(0);
     }
    }

    return 0;
}
