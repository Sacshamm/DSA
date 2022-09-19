class Solution {
public:
    string removeOuterParentheses(string s) {
    //     stack<char>st;
    //     string ans;
    //     for(auto i:s){
    //         if(i=='('){
    //             if(st.size()>0){
    //                 ans+='(';
    //             }
    //             st.push(i);
    //         }
    //         else{
    //             if(st.size()>1){
    //                 ans+=')';
    //             }
    //             st.pop();
    //         }
    //     }
    //     return ans;
    // }
        
        string ans;
        int count=0;
        for(auto i:s){
            if(i=='('){
                if(count>0){
                    ans+='(';
                }
                count++;
            }
            else{
                if(count>1){
                    ans+=')';
                }
                count--;
            }
        }
        return ans;
    }
};
