class Solution {
public:
    
    void rev(vector<char>& s, int l , int r){
        if(l>=r) return;
        swap(s[l++],s[r--]);
        rev(s, l, r);
    }
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        rev(s,0,n);
    }
};
