class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,ans,nums);
        return ans;
    }
};













class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int>freq, vector<int> &nums){
        //if at any time both are equal means that whole permutation is generated
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            //condition for pick and non pick
            if(freq[i] == 0){//if not picked yet 
                temp.push_back(nums[i]);//then add to DS.
                freq[i]=1;// marked picked

                solve(ans,temp,freq,nums);
                freq[i]=0;//mark not picked 
                temp.pop_back();//remove that element for further recursive calls
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
    
        vector<vector<int>> ans;
        vector<int>temp;
        vector<int>freq(nums.size(),0);

        solve(ans,temp,freq,nums);
        return ans;
    }
};
