#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* FirstNode()  //Creates first node
{
	char data;
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	if(temp==NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
	printf("\nEnter data for root node : ");
	scanf("%c",&data);
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
return temp;
}

Node* Insertion(Node *temp,char ch)              //Insert more nodes  
{
	if(temp!=NULL && (temp->data)>ch)
		temp->left=Insertion(temp->left,ch);
	else if(temp!=NULL && (temp->data)<=ch)
		temp->right=Insertion(temp->right,ch);
	else
	{
		temp=(Node*)malloc(sizeof(Node));
		if(temp==NULL)
	    {
	        printf("Memory not allocated");
	        return NULL;
	    }
		temp->data=ch;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
}

void preorder(Node *temp) //Traverses in preorder
{
	if(temp)
	{
		printf("%c ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(Node *temp) //Traverses in inorder
{
	if(temp)
	{
		inorder(temp->left);
		printf("%c ",temp->data);
		inorder(temp->right);
	}
}

void postorder(Node *temp) //Traverses in postorder
{
	if(temp)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%c ",temp->data);
	}
}

int main() //Driver Function
{
	char ch;
	int res=0;
	Node *root=FirstNode();
    while(1)
    {
        printf("\nPress \n'1' to insert a character\n'2' to traverse preorder\n'3' to traverse inorder\n'4' to traverse postorder\n'5' if you wanna exit\n");
        scanf("%d",&res);
        fflush(stdin);
        switch(res)
        {
            case 1 : printf("\nEnter character : ");
            		 scanf("%c",&ch);
            		 Insertion(root,ch);
                     break;

            case 2 : preorder(root);
                     break;

            case 3 : inorder(root);
                     break;

            case 4 : postorder(root);
                     break;

            case 5 : exit(1);

            default : printf("\nYou entered wrong choice !!!!!!!!!!!!");
                      break;
        }           
    }
} 