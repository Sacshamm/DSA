class Solution {
public:
//     bool isValid(string s) {
//         stack<char>st;
        
//         for(auto i:s){
//             if(i=='(' || i=='{' || i=='[') st.push(i);// pushing openeing into stack
            
//             //checking if opening in stack matches with closing in string throgh i.
//             //also checking if st is empty or not if empty means no char present
//             else if( st.empty() ||st.top()=='(' && i!=')' || st.top()=='{' && i!='}' || st.top()=='[' && i!=']' ) return false;
//             //meanwhile poping the matched open brackets
//             else st.pop();
//         }
//         //after poping matched char whole stack will be empty.
//         return st.empty();
//     }
    
    bool isValid(string s) {
        stack<int>st;
        
        for(int i=0;i<s.size();i++){
            char a=s[i];
            if(a=='(' || a=='[' || a=='{') st.push(a);
            
          else if( st.empty()||
                  st.top()=='('  && a!=')' ||
                  st.top()=='{'  && a!='}' || 
                  st.top()=='['  && a!=']' ) return false;
              else
                  st.pop();
            
        }
             return st.empty();
    }
};
