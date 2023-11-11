//TREE CREATION AND TRAVERSAL

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *left, *right;
}Node;

Node *create(){
	int x;
	Node *newnode;
	newnode = (Node*)malloc(sizeof(Node));

	printf("Enter value(-1 for no node): \n");
	scanf("%d", &x);
	if(x == -1)
		return NULL;
	
	newnode->value = x;
	printf("Left child of %d:\n", x);
	newnode->left = create();
	printf("Right child of %d\n",x);
	newnode->right = create();

	return newnode;
}


void inorder(Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->value);
	inorder(root->right);
}

void preorder(Node *root){
	if(root == NULL)
		return;
	printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->value);
}

int main(){

	Node *root = NULL;
	root = create();
	printf("Inorder Traversal\n");
	inorder(root);

	printf("\nPreorder Traversal\n");
	preorder(root);

	printf("\nPostorder Traversal\n");
	postorder(root);

	return 0;
}