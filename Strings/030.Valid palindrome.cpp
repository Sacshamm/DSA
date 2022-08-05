class Solution {
public:
    bool isPalindrome(string s) {
         int l=0,r=s.size()-1;
        while(l<r)
        {
            if(!isalnum(s[l]))// checks if l is digit/lower/upper case
                l++;
            else if(!isalnum(s[r]))// same for r
                r--;
            else if(tolower(s[l])!=tolower(s[r]))
                return false;
            else if(tolower(s[l])==tolower(s[r]))
            {
                l++;
                r--;
            }
        }
        return true;
    }
};
