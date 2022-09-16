#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

//binary tree node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//function to create a new node
struct node *newNode(int data){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//function to print the tree
void printTree(struct node *root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

//function to print the tree in reverse
void printTreeReverse(struct node *root){
    if(root == NULL){
        return;
    }
    printTreeReverse(root->right);
    cout << root->data << " ";
    printTreeReverse(root->left);
}

//function to print the tree in level order
void printTreeLevelOrder(struct node *root){
    if(root == NULL){
        return;
    }
    vector<struct node *> v;
    v.push_back(root);
    while(!v.empty()){
        struct node *temp = v[0];
        cout << temp->data << " ";
        if(temp->left != NULL){
            v.push_back(temp->left);
        }
        if(temp->right != NULL){
            v.push_back(temp->right);
        }
        v.erase(v.begin());
    }
}

//function to print the tree vertically
void printTreeVertical(struct node *root, int level){
    if(root == NULL){
        return;
    }
    printTreeVertical(root->left, level - 1);
    if(level == 0){
        cout << root->data << " ";
    }
    printTreeVertical(root->right, level + 1);


}
//main function
int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    cout << "Tree: ";
    printTree(root);
    cout << endl;
    cout << "Tree in reverse: ";
    printTreeReverse(root);
    cout << endl;
    cout << "Tree in level order: ";
    printTreeLevelOrder(root);
    cout << endl;
    //print the tree vertically
    cout << "Tree vertically: ";
    for (int i = -3; i <= 3; i++){
        printTreeVertical(root, i);
        cout << endl;
    }



    return 0;
}
