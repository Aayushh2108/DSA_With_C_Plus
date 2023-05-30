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
    ~Node(){
       int val = this ->data;
        if(next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data"<< val <<endl;
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
void insertAtHead(Node* &tail,Node* &head,int d){
    // Empty list//
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp ->next = head;
    head ->prev =temp;
    head = temp;
    }
}
// Insert at Tail//
void insertAtTail(Node* &tail,Node* &head,int d) {
    if(head == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
   
    
}
// Insert at Any position //
void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    // insert at start
    if(position==1){
        insertAtHead(tail,head,d);
        return ;
    }

    Node* temp = head;
    int cnt =1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    // Insert at last psoition//
    if(temp->next == NULL){
        insertAtTail(tail,head,d);
        return;
    }
    // Creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev= nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev= temp;


}
void deleteNode(int position, Node* &head){
   
//    deleting first or start node
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head = temp ->next;
        temp->next= NULL;
        delete temp;
    }
    else{
        // Deleting mid or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt <= position-1){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev =NULL;
        prev->next = curr->next;
        curr->next=NULL;
        delete curr;

    }
}
int main(){

    Node* head = NULL;
    Node* tail = NULL;   
  
//   cout<< getLength(head)<<endl;
    insertAtHead(tail,head, 11);
    print(head);
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

    insertAtHead(tail,head, 12);
    print(head);
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

    insertAtTail(tail,head,25);
    print(head);
    
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

    insertAtPosition(tail,head,2 ,22);
    print(head);
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

    
    insertAtPosition(tail , head,4,5);
    print(head);
    
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

    deleteNode(2,head);
    cout<<"head"<<head->data<< endl;
    cout<< "tail"<< tail->data<< endl;

}
