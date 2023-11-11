#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct node{
	int value;
	struct Node *fii[N];
}Node;

Node *create() {
    int x;
    Node *newnode = (Node *)malloc(sizeof(Node));

    if (newnode == NULL) {
        printf("Eroare la alocarea de memorie.\n");
        exit(1);
    }

    if (x == -1)
        return NULL;

    printf("Enter value: ");
    scanf("%d", &x);


    newnode->value = x;
    for (int i = 0; i < N; i++) {
        if (x == -1)
            return NULL;
        printf("Child %d of %d: \n", i+1, x);
        newnode->fii[i] = create();
    }

    return newnode;
}

int cautare(Node *node, int key) {
    if (node == NULL)
        return 0;

    if (node->value == key) {
        printf("\nCheia %d a fost gasita!\n", key);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (cautare(node->fii[i], key))
            return 1;
    }

    return 0;
}

Node *actualizare(Node *node, int key, int new) {
    if (node == NULL)
        return NULL;

    if (node->value == key) {
        node->value = new;
        return node;
    }

    for (int i = 0; i < N; i++) {
        if (actualizare(node->fii[i], key, new))
            return node;
    }

    return node;
}

Node *suprimare(Node *node, int key) {
    if (node == NULL)
        return node;

    for (int i = 0; i < N; i++) {
        node->fii[i] = suprimare(node->fii[i], key);
    }

    if (node->value == key) {
        free(node);
        return NULL;
    }

    return node;
}

void printPreorder(Node *node) {
    if (node == NULL)
        return;

    printf("%d ", node->value);

    for (int i = 0; i < N; i++) {
        printPreorder(node->fii[i]);
    }
}

void printInorder(Node *node) {
    if (node == NULL)
        return;


    for (int i = 0; i < N; i++) {
        printPreorder(node->fii[i]);
    }
    printf("%d ", node->value);
}

int main(){

	Node *root = NULL;
    int gasit = 0;
	root = create();
    printPreorder(root);
    //printInorder(root);
    gasit = cautare(root, 6);
    root = suprimare(root, 3);
    printf("\n");
    root = actualizare(root, 1, 99);
    printPreorder(root);

	return 0;
}