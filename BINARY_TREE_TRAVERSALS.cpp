#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node* left;
        node* right;
};

node* newNode(int val){
    node* new_node = new node();
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void inorder_traversal(node* root){
    if(root != NULL){
        inorder_traversal(root->left);
        cout<<root->val<<" ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(node* root){
    if(root != NULL){
        cout<<root->val<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(node* root){
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->val<<" ";
    }
}

int main(){

    node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(6);

    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);

    return 0;
}