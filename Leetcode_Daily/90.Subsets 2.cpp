class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums){
        ans.push_back(temp);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,ans,temp,nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,ans,temp,nums);
        
        return ans;
    }
};





////works fine but not optimal
// class Solution {
// public:
//     void solve(int ind, set<vector<int>> &st, vector<int> &temp, vector<int> &nums){
//         if(ind == nums.size()){
//             st.insert(temp);
//             return;
//         }
//         temp.push_back(nums[ind]);
//         solve(ind+1,st,temp,nums);

//         temp.pop_back();
//         solve(ind+1,st,temp,nums);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         set<vector<int>> st;
//         vector<int>temp;
//         solve(0,st,temp,nums);
//         vector<vector<int>>ans;

//         for(auto &it:st) ans.push_back(it);
//         return ans;
//     }
// };
