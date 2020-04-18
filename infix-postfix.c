#include<stdio.h>
#include<string.h>
int stack[50];
char postfix[50];
int top=-1,j=0;

void push2(char ch) //Pushes in postfix expression
{
	postfix[j]=ch;
	j++;
}

int precedence(char ch) //Assign precedence value
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/')
		return 2;
	if(ch=='^')
		return 3;
	if(ch=='(')
		return 0;
}

void pop() //Pops from the stack
{
	push2(stack[top]);
	top--;
}

void push1(char ch) //Pushes into the stack
{
	int pre,pre1;
	pre=precedence(ch);
	if(top==-1)
	{
		top++;
		stack[top]=ch;
		return;
	}
	pre1=precedence(stack[top]);
	if(pre>pre1)
	{			
		top++;
		stack[top]=ch;
	}
	else
	{
		pop();
		top++;
		stack[top]=ch;
	}
return;
}

void inftopost(char *str)
{
	char ch;
	for(int i=0;i<strlen(str);i++)
	{
		ch=str[i];    
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
			push1(ch);
		else if(ch=='(')
		{
			top++;
			stack[top]=ch;
		}
		else if(ch==')')
		{
			while(stack[top]!='(')
				pop();
			if(stack[top]=='(')
				top--;
		}
		else
			push2(ch);
	}
}

int main() //Driver Function
{
	char str[20];
	printf("Enter the string : ");
	scanf("%s",&str);
	inftopost(str);	
	while(top!=-1)
		pop();
	postfix[j]=='\0';
	printf("\n");
	for(int i=0; postfix[i]!='\0' ;i++)
		printf("%c",postfix[i]);
return 0;
} 
 