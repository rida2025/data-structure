#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node* parent;
    struct node* right;
    struct node* left;
}node;

node* createnode(int value){
    node* tree = malloc(sizeof(node));
    tree->value = value;
    tree->parent = NULL;
    tree->right = NULL;
    tree->left = NULL;
    return (tree);
}

void insert(node* tree, int value){
    if(value > tree->value){
        if(tree->right == NULL){
            tree->right = createnode(value);
            tree->right->parent = tree;
        }
        else (insert(tree->right, value));
    }
    else{
        if(tree->left == NULL){
            tree->left = createnode(value);
            tree->left->parent = tree;
        }
        else (insert(tree->left, value));
    }
    
}

void delete(node* tree, int value){
    if(tree == NULL){
        printf("\nvalue does not exist");
    }
    else if(value == tree->value){
        if(tree->right == NULL && tree->left == NULL){
            node* tmp = tree;
            if(value > tree->parent->value){
                tmp->parent->right = NULL;
                free(tmp);
            }
            else{
                tmp->parent->left = NULL;
                free(tmp);
            }
            printf("\n1 it was freed\n");
            return;
        }
        else if(tree->right != NULL){
            node* tmp = tree;
            tmp->right->parent = tmp->parent;
            tmp->parent->right = tmp->right;
            free(tmp);
            printf("\n2 it was freed\n");
            return;
        }
        else if(tree->left != NULL){
            node* tmp = tree;
            tmp->left->parent = tmp->parent;
            tmp->parent->left = tmp->left;
            free(tmp);
            printf("\n3 it was freed\n");
            return;
        }
        else if(tree->left != NULL && tree->right != NULL){
            //this for the case of 2 children 
        }
    }
    else if(value > tree->value){
        delete(tree->right, value);
        
    }
    else if(value < tree->value){
        delete(tree->left, value);
    }
}
    
void showtree(node* tree){
    if (tree != NULL) {
        printf("%d ", tree->value);
        showtree(tree->left);
        showtree(tree->right);
    }
}

void searchtree(node* tree, int value){
    if (tree == NULL) {
        printf("Value does not exist in the tree\n");
        return;
    }

    if (tree->value == value) {
        printf("Value %d exists in the tree\n", tree->value);
    } else if (value > tree->value) {
        searchtree(tree->right, value);
    } else {
        searchtree(tree->left, value);
    }
}

void freetree(node* tree){
    free(tree);
    printf("\nthe tree was deAlloceted from memory");
}
    
int main(void) {
    node* binarytree = createnode(25);
    insert(binarytree, 20);
    insert(binarytree, 75);
    insert(binarytree, 18);
    searchtree(binarytree, 75);
    showtree(binarytree);
    delete(binarytree, 75);
    showtree(binarytree);
    freetree(binarytree);
    return 0;
}