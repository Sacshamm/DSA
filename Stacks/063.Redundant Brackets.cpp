#include <stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char a= s[i];
        if(a=='('||a=='/'||a=='*'||a=='+'||a=='-') st.push(a);// if '(' or operator then  push 
        
        else{
            if(a==')'){
                bool isRedudant=true;
            while(st.top()!='('){ //run until ')' is found)    
            int top=st.top();
            if(top=='/'||top=='*'||top=='+'||top=='-')
                isRedudant=false;//operator in btween brackets then not redudant
             st.pop();//pop tht operator
        }
                if(isRedudant==true) return true;
                st.pop();//pop that opening brace which is next to operator
      }
     }
    }
    return false;
}
