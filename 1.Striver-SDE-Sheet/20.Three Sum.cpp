class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        //keep i fixed
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;//ensuring duplicates should not considered
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;k--;         //if equal then move both 
                    
                    //ensuring duplicates should not considered
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};



////O(n2*logm) but sc O(3n)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<nums.size();i++){
//             set<int>hashset;//stores rest of ele b/w i and j

//             for(int j=i+1;j<n;j++){
//                 int third = -(nums[i]+nums[j]);//calculte third
//                 //if third present in set then make triplet
//                 if(hashset.find(third)!=hashset.end()){
//                     vector<int>temp = {nums[i],nums[j],third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 //insert rest of ele b/w i and j
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
