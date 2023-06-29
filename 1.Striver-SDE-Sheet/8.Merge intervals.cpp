class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());//sort
        vector<vector<int>> ans;
        //store first index for comparison
        vector<int> current = intervals[0];

        for(int i=1;i<n;i++){
            //if it can not be merged then add it to ans
            if(current[1] < intervals[i][0]){
                ans.push_back(current);
                //after adding update to new index
                current = intervals[i];
            }
            //if it can be merged then look for max element at 2nd place
            else
            current[1] = max(current[1],intervals[i][1]);
        }
        //push rest 
        ans.push_back(current);
        return ans;
    }
};
