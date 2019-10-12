#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node *left, *right;
};

node* newNode(int val){
    node* new_node = new node();
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
}

void insert(node** root, int val){
    node* root_node = *root;
    if(root_node == NULL){
        *root = newNode(val);
    }else{
        if(root_node->val > val){
            insert(&root_node->left, val);            
        }else if(root_node->val < val){
            insert(&root_node->right, val);
        }
    }
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

node* search(node* root, int val){
    if(root == NULL || root->val == val){
        return root;
    }else if(root->val > val){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

node* min_val_node(node* root){
    while(root != NULL and root->left != NULL){
        root = root->left;
    }

    return root;
}

node* delete_node(node* root, int val){
    if(root == NULL)
        return root;

    if(val > root->val){
        root->right = delete_node(root->right, val);
    }else if(val < root->val){
        root->left = delete_node(root->left, val);
    }else{
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }else{
            node* temp = min_val_node(root->right);

            root->val = temp->val;
            root->right = delete_node(root->right, temp->val);
        }
    }
    return root;
}

int main(){

    node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    inorder_traversal(root);
    cout<<endl;
    preorder_traversal(root);
    cout<<endl;
    node* search_result = search(root, 20);
    if(search_result == NULL){
        cout<<"Not found!"<<endl;
    }else{
        cout<<"found "<<search_result->val<<endl;
    }
    root = delete_node(root, 50);
    inorder_traversal(root);
    return 0;
}