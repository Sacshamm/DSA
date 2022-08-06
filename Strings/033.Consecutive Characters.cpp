class Solution {
public:
    int maxPower(string s) {
        int count =1;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                count+=1;
            }
                else{
                maxi=max(maxi,count);
                    count=1;// re assigning count to 1
                }
            }
        
        return maxi;
    }
};
