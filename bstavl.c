#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	int height;
	struct node* left;
	struct node* right;
};
typedef struct node Node;
Node* root = NULL;

int HeightofNode(Node* temp)
{
	int hleft = 0, hright = 0;
	if (temp && temp->left)
		hleft = (temp->left->height);
	if (temp && temp->right)
		hright = (temp->right->height);
	return hleft > hright ? hleft + 1 : hright + 1;
}

int balancefactor(Node* temp)
{
	int hleft = 0, hright = 0;
	if (temp && temp->left)
		hleft = (temp->left->height);
	if (temp && temp->right)
		hright = (temp->right->height);
	return hleft - hright;
}

Node* LLRotation(Node* temp)
{
	Node* templ = temp->left;
	Node* templr = templ->right;
	temp->left = templr;
	templ->right = temp;
	temp->height = HeightofNode(temp);
	templ->height = HeightofNode(templ);

	if (temp == root)
		root = templ;
	return templ;
}

Node* LRRotation(Node* temp)
{
	Node* templ = temp->left;
	Node* templr = templ->right;
	temp->left = templr->right;
	templ->right = templr->left;
	templr->right = temp;
	templr->left = templ;
	temp->height = HeightofNode(temp);
	templ->height = HeightofNode(templ);
	templr->height = HeightofNode(templr);

	if (temp == root)
		root = templr;
	return templr;
}

Node* RRRotation(Node* temp)
{
	Node* tempr = temp->right;
	Node* temprl = tempr->left;
	temp->right = temprl;
	tempr->left = temp;
	temp->height = HeightofNode(temp);
	tempr->height = HeightofNode(tempr);

	if (temp == root)
		root = tempr;
	return tempr;
}

Node* RLRotation(Node* temp)
{
	Node* tempr = temp->right;
	Node* temprl = tempr->left;
	temp->right = temprl->left;
	tempr->left = temprl->right;
	temprl->left = temp;
	temprl->right = tempr;
	temp->height = HeightofNode(temp);
	tempr->height = HeightofNode(tempr);
	temprl->height = HeightofNode(temprl);

	if (temp == root)
		root = temprl;
	return temprl;
}

Node* Insertion(Node* temp, int ch)              //Insert more nodes  
{

	if (temp == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("Memory not allocated");
			return NULL;
		}
		temp->data = ch;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if ((temp->data) > ch)
		temp->left = Insertion(temp->left, ch);
	else if ((temp->data) < ch)
		temp->right = Insertion(temp->right, ch);

	temp->height = HeightofNode(temp);

	if (balancefactor(temp) == -2 && balancefactor(temp->right) == -1)
		return RRRotation(temp);
	else if (balancefactor(temp) == -2 && balancefactor(temp->left) == 1)
		return RLRotation(temp);
	else if (balancefactor(temp) == 2 && balancefactor(temp->left) == 1)
		return LLRotation(temp);
	else if (balancefactor(temp) == 2 && balancefactor(temp->right) == -1)
		return LRRotation(temp);
}

int main() //Driver Function
{
	int ch;
	root = Insertion(root, 6);
	printf("\nHeight : %d", HeightofNode(root));
	Insertion(root, 5);
	printf("\nHeight : %d", HeightofNode(root));
	Insertion(root, 4);
	printf("\nHeight : %d", HeightofNode(root));
	Insertion(root, 3);
	printf("\nHeight : %d", HeightofNode(root));
	Insertion(root, 2);
	printf("\nHeight : %d", HeightofNode(root));
	Insertion(root, 1);
	printf("\nHeight");
