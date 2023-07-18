class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        //element and index
        map<int,int>mp;
    
        for(int i=0;i<n;i++){
            int cur = nums[i];
            int required = target - cur;
            // if found in map then return
            if(mp.find(required)!=mp.end()) return {mp[required],i};
            //store in map
            mp[cur] = i;
        }
     return {-1,-1};
    }
};
