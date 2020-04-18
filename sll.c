#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link; 
}*head;
void createnode(int);
void travernode();

void createnode(int n)
{
  int x;
  struct node *temp;
  struct node *newnode;
  head=(struct node*)malloc(sizeof(struct node));
  printf("enter node1 data");
  scanf("%d;&x");
  head->data=x;
  head->link=NULL;
  temp=head;
  
  for (int i = 2; i <=n; i++)
  {
  	/* code */
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter node data\n");
  scanf("%d",x);
  newnode->data=x;
  newnode->link=NULL;
  temp->link=newnode;
  temp=temp->link;  
  }
}
void travernode()
{
  struct node *temp=head;
  while(temp!=NULL)
  {

printf("your node data is %d\n",temp->data);
 temp=temp->link;
  }	
}
int main()
{
	/* code */
	int n;
	printf("entr num of nodes\n");
	scanf("%d,&n");
	createnode(n);
	travernode();
	return 0;
}