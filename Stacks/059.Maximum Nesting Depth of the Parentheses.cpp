class Solution {
public:
    int maxDepth(string s) {
    stack<char>st;
        int maxi=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int count=st.size();
                maxi=max(maxi,count);
                st.pop();//pop bcz of closing bracket 
            }
        }
        return maxi;
    }
        
    //        int maxi=0; int curr=1;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]=='('){
    //             maxi=max(maxi,curr++);
    //         }
    //         else if(s[i]==')'){
    //            curr--;
    //         }
    //     }
    //     return maxi;
    // }
};
