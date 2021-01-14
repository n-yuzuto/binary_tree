#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binarytree.h"

Node *create_tree(char *label, Node *left, Node *right){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        printf("fail to secure area");
        return NULL;
    }
    else if(new_node != NULL){
        new_node -> label = label;
        new_node -> left = left;
        new_node -> right = right;
    }
    return new_node;
}

void preorder(Node *n){
    if(n == NULL)return;
    printf("%s ",n -> label);
    preorder(n -> left);
    preorder(n -> right);
}

void inorder(Node *n){
    if(n == NULL)return;
    inorder(n -> left);
    printf("%s ",n -> label);
    inorder(n -> right);
}

void postorder(Node *n){
    if(n == NULL)return;
    postorder(n -> left);
    postorder(n -> right);
    printf("%s ",n -> label);
}

void display(Node *n) {
    if (n == NULL) {
        printf("null");
    }
    else {
        printf("%s(", n -> label);
        display(n -> left);
        printf(",");
        display(n -> right);
        printf(")");
    }
}

void breadth_first_search(Node *n){
    int size = 1;
    int h = height(n);
    while (h != 0) {
        size = size * 2;
        h--;
    }
    size = size - 1;

    typedef struct queue {
        Node *buffer;
        int length;
        int front;
        int rear;
        int count;
    } Queue;
    
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q -> buffer = malloc(sizeof(int)*size);
    q -> length = size;
    q -> front = 0;
    q -> rear = 0;
    q -> count = 0;

    Node node;
    q -> buffer[q -> rear] = *n;
    q -> rear++;
    q -> count++;
    while (q -> count > 0) {
        node = q -> buffer[q -> front];
        q -> front++;
        q -> count--;
        printf("%s ", node.label);
        if (node.left != NULL) {
            q -> buffer[q -> rear] = *node.left;
            q -> rear++;
            q -> count++;
        }
        if (node.right != NULL) {
            q -> buffer[q -> rear] = *node.right;
            q -> rear++;
            q -> count++;
        }
    }
    free(q);
}

int height(Node *n){
    int h = 0;
    if(n == NULL){
        return h;
    }
    int l = height(n -> left);
    int r = height(n -> right);
    return (l >= r) ? (l + 1) : (r + 1);
}

void delete_tree(Node *n){
    if(n != NULL){
        delete_tree(n -> left);
        delete_tree(n -> right);
        free(n);
    }
}

void tree_print(Node *p)
{
    static int  depth = 0;

    if(p->right != NULL){
        ++depth;
        tree_print(p->right);
        --depth;
    }
    printf("%*c%s\n", 5 * depth, ' ', p->label);
    if(p->left != NULL){
        ++depth;
        tree_print(p->left);
        --depth;
    }
}