class Solution {
public:
    void solve(int ind, set<vector<int>> &st,vector<int> &temp,vector<int> &nums){
        if(ind == nums.size()) {
        st.insert(temp);
        return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,st,temp,nums);
        temp.pop_back();
        solve(ind+1,st,temp,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        solve(0,st,temp,nums);
        vector<vector<int>>ans;
        for(auto i:st) ans.push_back(i);
        return ans;
    }
};
