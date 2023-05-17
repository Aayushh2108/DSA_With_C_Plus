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

//program to create a simple linked 
// lit with 3 nodes
int main(){
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;
    
    //allocate 3 nodes in the heap

    head = new Node;
    second = new Node;
    third = new Node;

    head->data =1;//assign data in first node

    //link firest node with the second node

    head->next= second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);
    return 0;
}
