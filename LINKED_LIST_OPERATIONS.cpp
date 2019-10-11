#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node* next;

};

node* newNode(int val){
    node* new_node = new node();
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

void print_list(node* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void insert_at_start(node** head, int val){
    node* new_node =  newNode(val);
    new_node->next = *head;
    *head = new_node;
}

void insert_after_node(node* ptr_node, int val){
    node* new_node = newNode(val);
    new_node->next = ptr_node->next;
    ptr_node->next = new_node;
}

void insert_at_end(node** head, int val){
    node* new_node = newNode(val);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    node* head_node = *head;
    while(head_node->next != NULL){
        head_node = head_node->next;
    }
    head_node->next = new_node;
}

void delete_from_list(node** head, int val){
    node* head_node = *head;
    node* prev_node;
    if(head_node != NULL and head_node->val == val){
        *head = head_node->next;
        delete head_node;
        return;
    }

    while(head_node != NULL and head_node->val != val){
        prev_node = head_node;
        head_node = head_node->next;
    }
    if(head_node != NULL){
        prev_node->next = head_node->next;
        delete head_node;
    }
}

void delete_at_pos(node** head, int pos){
    node* head_node = *head;
    node* prev_node;
    if(pos == 0){
        if(head_node == NULL){
            return;
        }
        *head = head_node->next;
        delete head_node;
    }else{
        while(pos and head_node != NULL and head_node->next != NULL){
            pos--;
            prev_node = head_node;
            head_node = head_node->next;
        }
        if(pos == 0){
            prev_node->next = head_node->next;
            delete head_node;
        }
    }
}

int main(){

    node* linked_list = NULL;

    insert_at_start(&linked_list, 3);
    insert_at_start(&linked_list, 4);
    insert_at_start(&linked_list, 5);
    insert_after_node(linked_list->next, 10);
    insert_at_end(&linked_list, 20);
    print_list(linked_list);
    delete_from_list(&linked_list, 20);
    print_list(linked_list);
    delete_at_pos(&linked_list, 3);
    print_list(linked_list);

    return 0;
}