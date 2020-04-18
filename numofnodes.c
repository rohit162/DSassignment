#include<stdio.h>
#include<stdlib.h>

struct trees
{
	int data;
	struct trees *left;
	struct trees *right;
};
typedef struct trees Node;

Node* create() //Creates a Binary Tree
{
	Node *temp;
	int data;
	temp=(Node*)malloc(sizeof(Node*));
	printf("\nEnter data (-1 for NULL): ");
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	temp->data=data;
	printf("Enter data in left part : ");
	temp->left=create();
	printf("Enter data in right part : ");
	temp->right=create();
return temp;
}

int countnodes(Node *temp) //Counts the number of Nodes 
{
	if(temp)
		return countnodes(temp->left) + countnodes(temp->right) + 1;
	else
		return 0;
}

int main() //Driver Function
{
	Node* root=create();
	Node* t=root;
	printf("\nTotal number of nodes : %d",countnodes(t));
} 
