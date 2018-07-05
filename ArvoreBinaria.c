#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct node {
    int data;
    struct node *left;
    struct node *right;
};

Tree* create_binary_tree() {
    Tree* root = (Tree*) malloc(sizeof(Tree));

    if(root != NULL) {
        *root = NULL;
    }

    return root;
}

Tree* insert_binary_tree(Tree* t, int data) {
    struct node* new_node =  (struct node*)malloc(sizeof(struct node));

    if(t == NULL || new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*t == NULL) {
        *t = new_node;
    } else {
        struct node* current = *t;
        struct node* previous = NULL;
        while(current != NULL) {
            previous = current;
            if(data == current->data) {
                free(new_node);
                return NULL;
            }
            if(data > current->data) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        if(data > previous->data) {
            previous->right = new_node;
        } else {
            previous->left = new_node;
        }
    }

    return t;

}

void free_node(struct node* n) {
    if(n == NULL) {
        return;
    }
    free_node(n->left);
    free_node(n->right);
    free(n);
    n = NULL;
}

void free_tree(Tree* t) {
    if(t == NULL) {
        return;
    }
    free_node(*t);
    free(t);
}



