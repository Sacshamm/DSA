class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
         if(s.size() < p.size()) return {};
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        //insert first window
        for(int i=0;i<p_len;i++){
            v1[p[i]-'a']++;
            v2[s[i]-'a']++;
        }
        
        vector<int> ans;
        //if first window is same then add 0 as startin index
        if(v1 == v2) ans.push_back(0);
        
        //start from next window size upto total length
        for(int i=p_len;i<s_len;i++){
            v2[s[i-p_len] - 'a']--;//remove first added eleemnt 3-3 = 0 so 0th ele will be removed
            v2[s[i] - 'a']++;//add next ele i.e 3rd ele
            
            if(v1 == v2) 
                 ans.push_back(i-p_len+1);
                 //keep a note that i is the next/forward index 
                 //when i is at c then index = 8 so, 8-3+1 = 6 
                 // ans = [0,6]
        }
        
        return ans;
    }
};
