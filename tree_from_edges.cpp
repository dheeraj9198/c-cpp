#include <stdio.h>
#include <iostream>
#include <queue>
#include <malloc.h>
#include <cstdlib>
using namespace std;
void preorder(struct node * myNode);
struct node {
	int value;
	struct node * left;
	struct node * right;
};

class ParentChild {
public:
	int parent;
	int child;
	ParentChild(int p, int c) {
		parent = p;
		child = c;
	}

	ParentChild(){

	}
};

struct node * getNewNode(int value) {
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = value;
	return newNode;
}

struct node * insertM(struct node * root, int p, int c) {
	//preorder(root);exit(10);
	struct node * left;
	struct node * right;
	if (root->value == p) {
		cout << "value = p" << endl;
		if (root->left == NULL) {
			root->left = getNewNode(c);
		} else if (root->right == NULL) {
			root->right = getNewNode(c);
		} else {
			cout << "more than two parents ";
			std::exit(10);
		}
		return root;
	} else if (root->value == c) {
		struct node * n = getNewNode(p);
		n->left = root;
		return n;
	} else {
		if (root->left != NULL) {
			left = insertM(root->left, p, c);
			if (left != NULL) {
				return root;
			}

		} else if (root->right != NULL) {
			right = insertM(root->right, p, c);
			if (right != NULL) {
				return root;
			}

		}
		return NULL;
	}
}

int main() {
	//ParentChild temp;
	queue<ParentChild> myq;
	myq.push(ParentChild(2, 4));
	myq.push(ParentChild(4, 5));
	myq.push(ParentChild(1, 3));
	myq.push(ParentChild(1, 2));

	struct node * root = NULL;
	struct node * temp;
	ParentChild t;
	while (!myq.empty()) {
		cout << " inserting parent->" << myq.front().parent << " child->"
				<< myq.front().child << endl;
		if (root == NULL) {
			root = getNewNode(myq.front().parent);
			root->left = getNewNode(myq.front().child);
			myq.pop();
			continue;
		} else {
			temp = insertM(root, myq.front().parent, myq.front().child);
			if (temp == NULL) {
				cout << "NULL Returned"<<endl;
				t = myq.front();
				myq.pop();
				myq.push(t);
			} else {
				root = temp;
				myq.pop();
			}
		}
	}
	preorder(root);
}

void preorder(struct node * myNode) {
	if (myNode == NULL) {
		return;
	}
	cout << myNode->value << " ";
	preorder(myNode->left);
	preorder(myNode->right);
}

