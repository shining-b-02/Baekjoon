#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct {
    
    char leftchild;
    char rightchild;
}Tree;

Tree tree[100];

void preorder(char node) {

    if (node == '.')
        return;
    else {
        printf("%c", node);
        preorder(tree[node].leftchild);
        preorder(tree[node].rightchild);
    }
}

void inorder(char node) {
    if (node == '.')
        return;
    else {
        inorder(tree[node].leftchild);
        printf("%c", node);
        inorder(tree[node].rightchild);
    }
}

void postorder(char node) {

    if (node == '.')
        return;
    else {
        postorder(tree[node].leftchild);
        postorder(tree[node].rightchild);
        printf("%c", node);
    }
}

int main() {
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char node, a, b;
        scanf(" %c %c %c", &node, &a, &b);
        
        tree[node].leftchild = a;
        tree[node].rightchild = b;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");

    return 0;
}