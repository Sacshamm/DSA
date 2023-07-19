////O(n)time and space for set O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int longest=1;
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            //find the starting ele of consecutive sequence
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x = it;

                //now find all the other consecutive elements
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};

////Better O(nlogn) for sorting
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0) return 0;
//         sort(nums.begin(),nums.end());
//         int longest = 1;//global count
//         int cnt=1;//stores count locally
//         int lastSmaller=INT_MIN;

//         for(int i=0;i<nums.size();i++){
//             //check if stored element is just less than curr element
//             if(nums[i]-1 == lastSmaller) {
//                 cnt++;
//                 lastSmaller = nums[i];//update stored element with current
//             }
//             //if equal to current ele then continue loop

//             //if its a totally new one then reset count and store element
//             else if(nums[i]!=lastSmaller){
//                 cnt=1;
//                 lastSmaller = nums[i];
//             }   
//             longest = max(longest,cnt);   
//         }
//         return longest;
//     }
// };



///brute taking O(n^2)
// class Solution {
// public:
//     bool find(vector<int>&nums,int ele){
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==ele) return true;
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& nums) {
//         int longest = 1;
//         for(int i=0;i<nums.size();i++){
//             int x = nums[i];
//             int cnt = 1;

//             while(find(nums,x+1)==true){
//                 cnt++;
//                 x++;
//             }
//             longest = max(cnt,longest);
//         }
//         return longest;
//     }
// };
