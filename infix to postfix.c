#include <stdio.h>
#include <ctype.h>
#define max 20
char postfix[max],a[max];
int j=0,top=-1;
void push(char ch)
{
    a[++top]=ch;
}
char pop()
{
    return a[top--];
}
int priority(char ch)
{
    if (ch=='^')
        return 3;
    else if (ch=='*'||ch=='%'||ch=='/')
        return 2;
    else if (ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}
void precedence(char ch)
{
    while(priority(ch)<=priority(a[top]))
    {
        postfix[j++]=pop();
    }
}
int main()
{
    char infix[max],x,ch;
    int i;
    printf("Enter infix\n");
    scanf("%s",infix);
    printf("Hi");
    printf("%s",infix);
    i=0;
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if (isalpha(ch)!=0||isdigit(ch)!=0)
        {
            postfix[j++]=ch;
        }
        else
        {
            switch(ch)
            {
                case '(':push(ch);
                         break;
                case '^':precedence(ch);
                         push(ch);
                         break;
                case '*':precedence(ch);
                         push(ch);
                         break;
                case '%':precedence(ch);
                         push(ch);
                         break;
                case '/':precedence(ch);
                         push(ch);
                         break;
                case '+':precedence(ch);
                         push(ch);
                         break;
                case '-':precedence(ch);
                         push(ch);
                         break;
                case ')':x=pop();
                         while(ch!='(')
                         {
                             postfix[j++]=x;
                             x=pop();
                         }
                         break;
            }
        }
        i++;
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix for given infix is %s",postfix);
    return 0;
}






