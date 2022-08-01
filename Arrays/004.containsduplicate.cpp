// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//          sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i++){
//             if(nums[i-1]==nums[i]){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return set<int>(nums.begin(), nums.end()).size() != nums.size();
       //return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
};
