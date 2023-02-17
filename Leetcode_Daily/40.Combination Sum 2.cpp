class Solution {
    private:
    void solve(int ind, vector<int>& temp, vector<vector<int>>& ans, vector<int>& arr, int target){
         if(target == 0){
            ans.push_back(temp);
            return;
        }

        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            solve(i+1,temp,ans,arr,target-arr[i]);
            temp.pop_back();
      }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
    
        solve(0,temp,ans,candidates,target);
        return ans;
    }
};







////TLE T.C->O(2^n*k*logn)

// class Solution {
//     private:
//     void solve(int ind, vector<int>& temp, set<vector<int>>& ans, vector<int>& arr, int target){
//         if(ind == arr.size()){
//             if(target == 0) ans.insert(temp);
//             return;
//         }

//         //take
//         if(arr[ind] <= target){
//             temp.push_back(arr[ind]);
//             solve(ind+1,temp,ans,arr,target-arr[ind]);//reducing target
//             temp.pop_back();//remove before jumping to not take
//         }
//         //not take
//         solve(ind+1,temp,ans,arr,target);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> ans;
//         vector<int>temp;
//         sort(candidates.begin(),candidates.end());
//         solve(0,temp,ans,candidates,target);
//         vector<vector<int>> result;
//         for(auto &i:ans){
//             result.push_back(i);
//         }
//         return result;
//     }
// };
