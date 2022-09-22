#include <iostream>
#include <stack>
using namespace std;
int main(){

stack <int> s;
s.push(1);
s.push(2);
s.push(6);
s.push(4);

s.pop();
cout<<s.top()<<endl;
if(s.empty()) cout<<"empty";
else cout<<"not empty"<<endl;

cout<<s.size();
return 0;
}