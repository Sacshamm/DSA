class Solution {
public:
    //recursion
    // void rev(vector<char>& s, int l , int r){
    //     if(l>=r) return;
    //     swap(s[l++],s[r--]);
    //     rev(s, l, r);
    // }
    // void reverseString(vector<char>& s) {
    //     int n = s.size()-1;
    //     rev(s,0,n);
    // }
    
    //stack
     void reverseString(vector<char>& s){
         stack<char>st;
         for(int i=0;i<s.size();i++){
             char ch = s[i];
             st.push(ch);
         }
         
         int i=0;
         
         while(!st.empty()){
             s[i] = st.top();
             st.pop();
             i++;
         }
     }
};
