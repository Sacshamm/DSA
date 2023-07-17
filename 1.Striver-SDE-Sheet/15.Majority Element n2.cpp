class Solution {
public:
    ////Moor's voting algo
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;

        for(int i=0;i<nums.size();i++){
            //if new ele then store it and increment
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
            ////if same ele then increment
            else if(ele == nums[i]){
                cnt++;
            }
            ////if not same then decrement to cancel out
            else{
                cnt--;
            }
        }
        return ele;
    }
};



// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mp;

//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }

//         int ans = 0;
//         for(auto i:mp){
//             if(i.second>(n/2)) ans = i.first;
//         }
//         return ans;
//     }
// };
