class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if(intervals.size()<=1) return intervals;
        
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        vector<int>current=intervals[0];
        
        for(int i=1;i<intervals.size();i++){
        if(current[1]<intervals[i][0]){
           res.push_back(current);
            current=intervals[i];
        }
            else{
                current[1]=max(current[1],intervals[i][1]);
            }
      }
        res.push_back(current);
        return res;
    }
};
