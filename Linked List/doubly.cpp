#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
     this->data=data;
     this->prev=NULL;
     this->next=NULL;
    }
     ~Node(){
       if(this->next!=NULL){
            delete next;
            this->next=NULL;
     }
    }
  
};

int getlength(Node* &head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void print(Node* & head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insert_at_head(Node* &head,int data){
    Node*temp= new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insert_at_tail( Node* &tail, int data){
    Node*temp= new Node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}

void insert_at_pos (Node* &tail, Node* &head,int pos, int data){
    if(pos==1){
        insert_at_head(head,data);
        return;
    }
    else{
         Node*temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
        insert_at_tail(tail, data); 
           return;
        }
        Node*inst_node= new Node(data);
        inst_node->prev=temp;
        inst_node->next=temp->next;
        temp->next=inst_node;
        inst_node->next->prev=inst_node;

    }
}

void del_at_pos( Node* &tail, Node* &head,int pos){
    if(pos==1){
        Node*temp=head;
        temp->next->prev=NULL;
        temp->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }  
    else{
        Node*previous =NULL;
        Node*current =head;
        int count=1;
        while(count<pos){
            previous=current;
           current=current->next;
           count++;
        }
        if(current->next==NULL){
            previous->next=NULL;
            tail=previous;
            current->prev=NULL;
            current->next=NULL;
            delete current;
        }

       previous->next=current->next;
       current->next=NULL;
       current->prev=NULL;
       delete current;
    }

}

int main(){
   Node*n =new Node(10);
   //node declarations
   Node*head=n;
   Node*tail=n;

   print(head);

   cout<<"Length --------"<<getlength(head)<<endl;

   cout<<"Inserted 9 at start"<<"----";
   insert_at_head(head, 9);
   print(head);
   cout<<endl;

   cout<<"Inserted 11 at end"<<"----";
   insert_at_tail(tail,11);
   print(head);
   cout<<"Length --------"<<getlength(head)<<endl;
   cout<<endl;


   cout<<"Inserted 100 at 2nd"<<"----";
   insert_at_pos(tail,head,2,100);
   print(head);
   cout<<endl;

   cout<<"Inserted 101 at 3rd"<<"----";
   insert_at_pos(tail,head,3,101);
   print(head);
   cout<<endl;

   cout<<"Deleted  at 1st"<<"----";
   del_at_pos(tail,head,1);
   print(head);
   cout<<"Length --------"<<getlength(head)<<endl;
   cout<<endl;

   cout<<"Deleted  at 3rd"<<"----";
   del_at_pos(tail,head,3);
   print(head);
   cout<<endl;

   cout<<"Deleted  at 3rd"<<"----"; 
   del_at_pos(tail,head,3);
   print(head);
   cout<<"Length --------"<<getlength(head)<<endl;
   cout<<endl;

return 0;
}