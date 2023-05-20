#include<bits/stdc++.h>
using namespace std;

//Linked list Node
struct Node
{
    int data;//data
    struct Node *next;//pointer
};

//This function prints contents of linked list
// starting from the given node
void printList(Node *node){
    while(node !=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}
//insert at beginning//
void push(struct Node** head_ref,int new_data){
    
    //allocate node//
    Node* new_node = new Node;

    //put in the data//
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;

}
void insertAfter(Node  *prev_node,int item){
    if(prev_node==NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    Node* new_node = new Node;

    new_node->data= item;

    new_node->next=prev_node->next;

    prev_node->next= new_node;

}
void append(struct Node** head_ref,int new_data){
    Node* new_node = new Node;

    struct Node* last = *head_ref;//used in step 5//
     
    new_node->data =  new_data;
    new_node->next = NULL;

//if the linked list is empty, then make the new node as head//

    if(*head_ref== NULL){
        *head_ref = new_node;
        return;
    }
    //else traverse till  the last node// 
    while(last->next != NULL)
    {
        last=last->next;

        //change the next of last node//
        last->next= new_node;
    }
}

//program to create a simple linked// 
// lit with 3 nodes//
int main(){
    
    Node* head = NULL;
    append(&head,10);
    
    push(&head,20);
    
    push(&head,30);
    
    push(&head,40);
    
    cout<<"Created Linked List :";
    printList(head);
    
    return 0;
}
