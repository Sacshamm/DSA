class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
       vector<int>v1(26,0);// for s1
        vector<int>v2(26,0);//for s2
       //push in v1
       for(auto i:s1) v1[i-'a']++;

       int left=0;
       int right=0;

       while(right<s2.size()){
           //push in v2 also
           v2[s2[right]-'a']++;

           //here r-l+1 is the window
           if(right-left+1 == s1.size()){
               if(areVectorsEqual(v1,v2)==true) return true;
           }
           //if size is small then there is a need to increment formward pointer i.e; right 
           if(right-left+1 < s1.size()) right++;

           //if not equal and size is also equal 
           //then we have to remove one to add another 
           else{
               v2[s2[left]-'a']--;//remove previous one first bcz it is already checked
               //increment both pointers
               left++;
               right++;
           }
       }
       return false;
    }
};




