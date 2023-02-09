class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        //to store unique ones 
        unordered_set<string> set(ideas.begin(),ideas.end());

        //to store changing char and contsant char and occurence
        unordered_map<char,unordered_map<char,int>>m;

        for(auto& str:set){
            string s = str;
            char first_letter = s[0];

            for(char i='a';i<='z';i++){
                s[0] = i;
                if(set.find(s)==set.end())
                  m[i][first_letter]++;
            }
        }

        long long ans = 0;
         for(auto& str:set){
            string s = str;
            char first_letter = s[0];

            for(char i='a';i<='z';i++){
                s[0] = i;
                if(set.find(s)==set.end())
                 ans += m[first_letter][i];
            }
        }
        return ans;
    }
};




////nahi hua
 //int n=ideas.size();
        // map<string,int>mp;
        // int cnt=0;
        // for(auto i:ideas) mp[i]++;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         string idea1 = ideas[i];
        //         string idea2 = ideas[j];
        //         swap(idea1[0],idea2[0]);
        //         if(mp.find(idea1)==mp.end()) cnt++;
        //         if(mp.find(idea2)==mp.end()) cnt++;
        //     }
        // }
        // return cnt;

        // vector<char>v1(n);
        // for(int i=0;i<n;i++){
        //     v1.push_back(ideas[i][0]);
        // }
        
        // unordered_map<string,int>mp;
        // for(auto i:ideas) mp[i]++;
        // int cnt=0;
        // int  j=0;
        // for(int i=0;i<n;i++){
        //     if(v1[i]==ideas[j][0]) continue;
        //     string temp = ideas[j];
        //     swap(temp[0],v1[i]);
        //     if(mp.find(temp)==mp.end()) cnt++;
            
        // }
        // return cnt;
