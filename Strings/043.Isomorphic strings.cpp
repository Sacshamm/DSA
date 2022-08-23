class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a= s.length();
        int b= t.length();
        
        if(a!=b) return false;
        
        int mps[256]={0};//making map array
        int mpt[256]={0};
        
        for(int i=0;i<a;i++){
           if(mps[s[i]]!=mpt[t[i]]) return false;
           mps[s[i]]=i+1;//storing a value with char in map array  e.g s=foo t=bar
           mpt[t[i]]=i+1;
        }
        return true;
    }
};
//we have to map each char of s with t and check
//map array mps........ f=1,o=2
//mpt...................b=1,a=2
//but last o=2 and r=0 it doesnt match so false
