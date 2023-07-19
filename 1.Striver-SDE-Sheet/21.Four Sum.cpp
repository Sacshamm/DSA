class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        //keep first and second fixed and move third and fourth accordingly
        for(int first=0;first<n;first++){
            if(first>0 && nums[first]==nums[first-1]) continue;//ignore repeating

            for(int second=first+1;second<n;second++){
                if(second>first+1 && nums[second]==nums[second-1]) continue;//ignore repeating

                int third = second+1;
                int fourth = n-1;

                while(third<fourth){
                    //calculate required sum
                    long long totalSum = nums[first]+nums[second];
                    totalSum+=nums[third];
                    totalSum+=nums[fourth];

                    //if less then  increment
                    if(totalSum<target){
                        third++;
                    }
                    //decrement if large
                    else if(totalSum>target){
                        fourth--;
                    }
                    else{
                        vector<int>temp = {nums[first],nums[second],nums[third],nums[fourth]};
                        ans.push_back(temp);
                        third++;
                        fourth--;

                        //ignore repeating
                        while(third<fourth && nums[third]==nums[third-1]) third++;
                        while(third<fourth && nums[fourth]==nums[fourth+1]) fourth--;
                    }
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){

//                 set<long long>hashset;
//                 for(int k=j+1;k<n;k++){
//                     long long threeSum = (nums[i]+nums[j]);
//                     threeSum += nums[k]; 
//                     long long fourth = target - threeSum;

//                     if(hashset.find(fourth)!=hashset.end()){
//                         vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
