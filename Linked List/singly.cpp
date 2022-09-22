// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    //destructor
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void insert_at_pos(Node* &tail, Node* &head, int pos, int data){

    if(pos==1){// if we want to insert at start
        insertAtHead(head, data);
        return;
    }

    Node* n= new Node(data);
    Node *temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next=n;  

    if(temp->next==NULL){
        insertAtTail(tail , data);
        return;
    }
    
}

void delete_at_pos(Node* &head, int pos){
    if(pos==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;//free space with the help of destructor
    }
    else{
        Node*prev =NULL;
        Node*current =head;
        int count=1;
        while(count<pos){
            prev=current;
           current=current->next;
           count++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
    }
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    // Write C++ code here
   //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    print(head);
    
    cout<<"Inserted 12 at start"<<"----";
    insertAtHead(head, 12);
    print(head);
    cout<<endl;
    
    cout<<"Inserted 15 at end"<<"----";
    insertAtTail(tail, 15);
    print(head);
    cout<<endl;

    cout<<"Inserted 100 at start"<<"----";
    insert_at_pos(tail, head, 1, 100);
    print(head);
    cout<<endl;

    cout<<"Inserted 101 at 3rd"<<"----";
    insert_at_pos(tail ,head, 3, 101);
    print(head);
    cout<<endl;

    cout<<"Inserted 102 at 6th"<<"----";
    insert_at_pos(tail, head, 6, 102);
    print(head);
    cout<<endl;

    cout<<"Deleted  at 3rd"<<"----";
    delete_at_pos(head, 3);
    print(head);
    cout<<endl;

    return 0;
}