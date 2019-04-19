#include <stdio.h>
#include <stdlib.h>
struct node
{
    char usn[10];
    char name[10];
    struct node *link;
};
struct node *head=NULL;
struct node * createnode()
{
        struct node *temp;
        temp=malloc(sizeof(struct node));
        printf("Enter the USN\n");
        fflush(stdin);
        gets(temp->usn);
        printf("Enter the Name\n");
        gets(temp->name);
        temp->link=NULL;
        return temp;
}
void insertfront()
{
    struct node *SLL=NULL;
    SLL=createnode();
    if(head!=NULL)
        SLL->link=head;
    head=SLL;
}
void delfront()
{
    struct node *SLL=head;
    printf("NAME:\t%s",SLL->name);
    printf("USN:\t%s",SLL->usn);
    head=SLL->link;
    free(SLL);
}
void insertend()
{
    struct node *SLL,*temp=head;
    SLL=createnode();
    if(head==NULL)
        head=SLL;
    else
    {
        while(temp->link=NULL)
            temp=temp->link;
        temp->link=SLL;
    }
}
void delend()
{
    struct node *temp=head;
    struct node *t;
    if(head==NULL)
    {
        printf("nothing to delete\n");
    }
    else
    {
        while(temp->link!=NULL)
        {
            t=temp;
            temp=temp->link;
        }
        printf("NAME:\t%s",temp->name);
        printf("USN:\t%s",temp->usn);
        free(temp);
        t->link=NULL;
    }

}
void create()
{
    int i,n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insertfront();
}
void display()
{
    int c;
    c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        fflush(stdout);
        printf("NAME\tUSN\n");
        printf("%s\t%s\n",temp->name,temp->usn);
        temp=temp->link;
        c++;
    }
    printf("Number of nodes:%d\n",c);
}
int main()
{
    int ch,ch1,ch2;
    while(1)
    {
            printf("1.Create\t2.Front\t3.End\t4.Display\t5.Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:create();
                        break;
                case 2:printf("1.Insert\t2.Delete\n");
                        scanf("%d",&ch1);
                        if(ch1==1)
                            insertfront();
                        else
                            delfront();
                        break;
                case 3:printf("1.Insert\t2.Delete\n");
                        scanf("%d",&ch2);
                        if(ch2==1)
                            insertend();
                        else
                            delend();
                        break;
                case 4:display();
                        break;
                case 5:exit(0);
            }
    }

    return 0;
}
