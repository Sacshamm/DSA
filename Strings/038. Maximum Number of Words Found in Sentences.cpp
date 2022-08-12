class Solution {
public:
    int mostWordsFound(vector<string>& s) {
         int n=s.size();
        int maxi=INT_MIN;
        //traverse the vector of string 
        for(int i=0;i<n;i++){
            string insider =s[i];//set to 0th index
            int cnt=0;
            for(int j=0;j<insider.length();j++){//traversal inside 0th index
              //count the spaces
                if(insider[j]==' '){
                    cnt++;
                }
            }
           //set the maximum
            maxi=max(maxi,cnt+1);
        }
        return maxi;

    }
};
