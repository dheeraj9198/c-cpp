#include <stdio.h>
#include <malloc.h>
#include <iostream>
void insert(struct node **root,int value);
void traverse(struct node * root);
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
	traverse(root);
}

void traverse(struct node * root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ",root->value);
	traverse(root->left);
	traverse(root->right);
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


	struct node * x = *root;
	while(x != NULL)
	{
		if(x->value > value)
		{
			x=x->right;		
		}else{
			x=x->left;	
		}
	}
	*x =  newNode;
	
	

}