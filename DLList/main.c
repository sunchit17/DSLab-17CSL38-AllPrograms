#include <stdio.h>
#include <stdlib.h>
struct node
{
    char name[10];
    struct node *llink;
    struct node *rlink;
};
struct node *head=NULL;
struct node * createnode()
{
        struct node *temp;
        temp=malloc(sizeof(struct node));
        fflush(stdin);
        printf("Name?\n");
        gets(temp->name);
        temp->llink=temp->rlink=NULL;
        return temp;
}
void insertfront()
{
    struct node *dll;
    dll=createnode();
    if(head!=NULL)
    {
        dll->rlink=head;
        head->llink=dll;
    }
    head=dll;
}
void delfront()
{
    struct node *dll=head;
    printf("Name:%s",dll->name);
    head=dll->rlink;
    head->llink=NULL;
    free(dll);
}
void insertend()
{
    struct node *dll,*temp=head;
    dll=createnode();
    if(head==NULL)
    {
        head=dll;
    }
    else
    {
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        temp->rlink=dll;
        dll->llink=temp;
    }
}
void delend()
{
    struct node *temp=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        while(temp->rlink!=NULL)
           {
               temp=temp->rlink;
           }
        printf("Name :%s\n",temp->name);
        temp->llink->rlink=NULL;
        free(temp);
    }
}
void create()
{
    int i,n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insertend();
}
void display()
{
    int c;
    c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("NAME:\n");
        printf("%s\n",temp->name);
        temp=temp->rlink;
        c++;
    }
}
int main()
{
    int ch,ch1,ch2;
    while(1)
    {
        printf("1.Create\t2.Front Op\t3.End Op\t4.Display\t5.Exit\n");
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
                    scanf("%d",&ch1);
                    if(ch1==1)
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
