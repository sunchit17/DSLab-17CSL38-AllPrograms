#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int Stack[20];
int top;
void push(int);
int pop();
void eval(char[]);
int main()
{
    char post[20];
    int top=-1;
    printf("Enter the postfix expression\n");
    fflush(stdin);
    gets(post);
    eval(post);
    printf("Evaluated answer is %d\n",pop());
    return 0;
}
void push(int ele)
{
    Stack[++top]=ele;
}
int pop()
{
    return Stack[top--];
}
void eval(char post[20])
{
    int i,a,b;
    char ch;
    for(i=0;post[i];i++)
    {
        ch=post[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            b=pop();
            a=pop();
            switch(ch)
            {
                case '+':push(a+b);
                            break;
                case '-':push(a-b);
                            break;
                case '*':push(a*b);
                            break;
                case '%':push(a%b);
                            break;
                case '^':push(pow(a,b));
                            break;
                case '/':if(b==0)
                            {
                            printf("Divide by Zero Error\n");
                            exit(0);
                            }
                            else
                                push(a/b);
                            break;
                default:printf("Invalid Operation\n");
                        exit(0);
            }

        }
    }
}
