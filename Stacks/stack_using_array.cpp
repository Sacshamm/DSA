#include <iostream>
using namespace std;

class Stack {
    //propeberties
    public:
     int size;
     int *arr;
     int top;

     //constructor
     Stack(int size){
        this->size=size;
         arr = new int[size];
         top=-1;
     }

     void push(int element){
        if(size-top>1){ 
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow";
        }
     }

     void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow";
        }
     }

     int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty";
            return -1;
        }
     }

     bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
     }
};


int main(){

 Stack st(4);
 st.push(1);
 st.push(2);
 st.push(5);

 st.pop();
 cout<<st.peek();

 cout<<endl;
 st.pop();
 cout<<st.peek();

 cout<<endl;
 st.pop();
 cout<<st.peek();

 cout<<endl;
 if(st.isempty()){
    cout<<"Empty";
 }
 else{
    cout<<"Not Empty";
 }
 

return 0;
}