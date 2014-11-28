#include <stdio.h>
#include <malloc.h>
#include <iostream>
void insert(struct node **root,int value);
struct node
{
	struct node * left;
	struct node * right;
	struct node * parent;
	char color;
	int value;	
};

int main()
{
	
	int array[] = {5,3,7,2,4,6,8,11};
	int length = 8;
	struct node * root = NULL;
	for(int x= 0;x< length;x++)
	{
		insert(&root,array[x]);
	}
	printf("%d\n", root->value);
}

void insert(struct node **root,int value)
{

	 struct node * newNode = (struct node *)malloc(sizeof(struct node));
	 newNode->value = value;
	 newNode->color = 'R';
	 newNode->parent = NULL;
	 newNode->left = NULL;
	 newNode->right = NULL;
	
	if((*root) == NULL)
	{
		newNode->color = 'B';
		*root = newNode;
		return;		
	}

	if(value > root->value)
	{
		root->right = newNode;
	}
	if(value < root->value)
	{
		root->left = newNode;
	}

}