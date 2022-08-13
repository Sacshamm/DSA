class Solution {
public:
    int firstUniqChar(string s) {
         int alp[26] = {};
        
        // set total every letter
        for(char c : s) alp[c-'a']++;
        
        // search letter with total 1
        for(int i = 0; i < s.length(); i++)
            if(alp[s[i]-'a'] == 1)
                return i;

        return -1;
    }
};
