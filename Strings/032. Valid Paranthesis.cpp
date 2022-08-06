class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[') st.push(i);// pushing openeing into stack
            
            //checking if opening in stack matches with closing in string throgh i.
            //also checking if st is empty or not if empty means no char present
            else if( st.empty() ||st.top()=='(' && i!=')' || st.top()=='{' && i!='}' || st.top()=='[' && i!=']' ) return false;
            //meanwhile poping the matched open brackets
            else st.pop();
        }
        //after poping matched char whole stack will be empty.
        return st.empty();
    }
};
