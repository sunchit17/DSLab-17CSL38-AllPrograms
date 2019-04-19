#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int size;
    int *item;
    int top;
}Stack;
//function prototype declarations
void push(Stack *,int);
int pop(Stack *);
void init(Stack *,int);
void display(Stack *);
void deallocate(Stack *);
int getsize(Stack *);

int getsize(Stack *sp)
{
    return sp->size;
}

void push(Stack *sp,int value)
{
    if(sp->top==(sp->size-1))
    {
        int *temp;
        temp = (int *)malloc(sizeof(int)*sp->size *2);
        if(temp==NULL)
        {
            printf("Stack Overflow\n");
            return;
        }
        int i;
        for(i=0;i<sp->top;i++)
            temp[i]=sp->item[i];
        free(sp->item);
        sp->item=temp;
        sp->size *=2;
    }
    sp->top++;
    sp->item[sp->top]=value;
}
int pop(Stack *sp)
{
    if(sp->top==-1){
        printf("Underflow ho giya\n");
        return -999;
    }
     int value;
     value=sp->item[sp->top];
     sp->top--;
     return value;
}
void init(Stack *sp,int size)
{
    sp->top=-1;
    sp->item=(int *)malloc(sizeof(int)*size);
    if(sp->item==NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    sp->size=size;
}
void deallocate(Stack *sp)
{
    if(sp->item!=NULL)
        free(sp->item);
}

void display(Stack *sp)
{ int i;
    for(i=0;i<=sp->top;i++)
    {
        printf("%d\t",sp->item[i]);
    }
    printf("\n");
}
int main()
{   Stack s1,s2;
    init(&s1,1);
    int schoice,choice,value;
    init(&s2,3);
    while(1)
    {
        printf("Choose your stack 1 or 2\n");
        scanf("%d",&schoice);
        if(schoice==1)
        {   printf("Size of Stack is %d\n",getsize(&s1));
            printf("Press 1.Push 2.Pop 3.Display 4.Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:printf("Enter a value\n");
                       scanf("%d",&value);
                       push(&s1,value);
                       break;
                case 2:value = pop(&s1);
                       if(value!=-999)
                       {
                            printf("Value popped is%d",value);
                       }
                       break;
                case 3:display(&s1);
                       break;
                case 4:deallocate(&s1);
                        exit(0);
             }
        }
        if(schoice==2)
        {    printf("Size of Stack is %d\n",getsize(&s2));
            printf("Press 1.Push 2.Pop 3.Display 4.Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:printf("Enter a value\n");
                       scanf("%d",&value);
                       push(&s2,value);
                       break;
                case 2:value = pop(&s2);
                       if(value!=-999)
                       {
                            printf("Value popped is%d\n",value);
                       }
                       break;
                case 3:display(&s2);
                       break;
                case 4:deallocate(&s2);
                        exit(0);
             }
        }
    }
    return 0;
}

