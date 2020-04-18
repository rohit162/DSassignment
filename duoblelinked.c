#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
}*head=NULL;
void createnode();
void traverse();


int main()
{    int n;
	printf("enter no. of nodes you want\n");
    	scanf("%d",&n);
    createnode(n);	
    traverse();
	return 0;
}

  
void createnode(int n)
{
int x;  struct node *temp;
struct node *newnode;
head=(struct node*)malloc(sizeof(struct node));
if (head==NULL)
{
	printf("no space is allocated\n");
}
printf("enter first node data\n");
scanf("%d",&x);
temp=head;
head->data=x;
head->prev=NULL;
head->next=NULL;
for (int i = 2; i <=n ; i++)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter node data\n");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=temp;
	temp->next=newnode;
	temp=temp->next;
}
printf("list created successfully\n");
}
void traverse()
{
  struct node *temp=head;
  while(temp!=NULL)
  {

printf("your node data is %d\n",temp->data);
 temp=temp->next;
  }	
}