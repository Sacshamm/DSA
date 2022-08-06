class Solution {
public:
    string removeDuplicates(string s) {
//         stack<char>st;
        
//         for(int i=0;i<s.length();i++){
//           if(st.empty()){
//             st.push(s[i]);
//           }
//           else if(st.top()==s[i]){
//              st.pop(); 
//           }  
//           else{
//               st.push(s[i]);
//           }  
//       }
//         string ans;
//         while(!st.empty()){
//         ans+=st.top(),st.pop();
//         }
//          reverse(ans.begin(),ans.end());
//         return ans;
        string ans;
        for(auto i:s)
        {
            if(!ans.empty() and ans.back()==i)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        return ans;
    
    }
};
