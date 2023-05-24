#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
// Traversing the Linked List
void print(Node* head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout << endl;
}
// gives length of Linked List
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp= temp->next;   
    }
    return len;
}
// Insert at Head//
void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp ->next = head;
    head ->prev =temp;
    head = temp;
}
// Insert at Tail//
void insertAtTail(Node* &tail,int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    temp->next = tail;
    tail = temp;
    temp->next = NULL;
}
int main(){
    Node* Node1 = new Node(10);
    Node* head = Node1;
    Node* tail = Node1;   
    print(head);
//   cout<< getLength(head)<<endl;
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtTail(tail,25);
    print(head);

}
