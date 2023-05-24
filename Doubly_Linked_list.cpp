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
// Insert at Any position //
void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    // insert at start
    if(position==1){
        return;
    }

    Node* temp = head;
    int cnt =1;
    if(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    // Insert at last psoition//
    if(temp->next == NULL){
        insertAtTail(tail ,22);
        return;
    }
    // Creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev= nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev= temp;


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
    insertAtPosition(tail,head,2 ,22);
    print(head);

}
