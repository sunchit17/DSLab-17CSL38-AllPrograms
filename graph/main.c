#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,i,j,source;
int visited[10];
void creategraph()
{
    printf("Enter the number of vertex\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
}
void bfs()
{
    int q[10],u,front=0,rear=-1;
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
    printf("\n");
}
int main()
{
    int i,ch;
    while(1)
    {
        printf("1.Create Graph\t2.BFS\t3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:creategraph();
                    break;
            case 2:bfs();
                    for(i=1;i<=n;i++)
                    {
                        if(visited[i]==0)
                            printf("%d is not reachable\n",i);
                    }
                    break;
            case 3:exit(0);
        }
    }
    return 0;
}
