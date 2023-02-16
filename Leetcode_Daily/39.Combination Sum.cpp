class Solution {
    private:
    void solve(int ind, vector<int>& temp, vector<vector<int>>& ans, vector<int>& arr, int target){
        if(ind == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }

        //take
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            solve(ind,temp,ans,arr,target-arr[ind]);//reducing target
            temp.pop_back();//remove before jumping to not take
        }
        //not take
        solve(ind+1,temp,ans,arr,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(0,temp,ans,candidates,target);
        return ans;
    }
};
