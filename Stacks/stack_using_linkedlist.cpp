#include <iostream>
using namespace std;

class Stack{
    public:
    int data;
    Stack *next;
    Stack *top=NULL;

    Stack(int data){
        this->data=data;
        this->next=NULL;
    }

    void push(int val){
       Stack* newnode = new Stack(val);
       newnode->next=top;
       top=newnode;      
     }

     void pop(){
        if(top!=NULL){
            top=top->next;
        }
        else{
            cout<<"Stack underflow";
        }
     }

     int peek(){
        if(top!=0){
            return top->data;
        }
        else{
            cout<<"stack is empty";
            return -1;
        }
     }

     bool isempty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
     }
        

    
};


int main(){

    Stack st(0);
    st.push(1);
    st.push(2);

    cout<<st.peek();
    
    cout<<endl;
    st.pop();
    cout<<st.peek();

    cout<<endl;
    st.pop();
    cout<<st.peek();

     st.push(12);
     st.push(222);

     cout<<endl;
   if(st.isempty()){
    cout<<"Empty";
 }
 else{
    cout<<"Not Empty";
 }


 cout<<endl<<st.peek();
     
return 0;
}