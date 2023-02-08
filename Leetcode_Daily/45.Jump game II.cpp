class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int cmax = 0;
        int nmax = 0;
        int jumps = 0;

        for(int i=0;i<n-1;i++){
            //look for next max element
            nmax = max(nmax,nums[i]+i);
            //if at any point i==curmax then there is a need to jump
            //after jumping update cmax
            if(i==cmax){
                jumps++;
                cmax = nmax;
            }
            //if cmax can reachable to last index 
            //break and return no. of jumps
            if(cmax >= n-1) break;
        }
        return jumps;
    }
};




// class Solution {
// public:
//     int jump(vector<int>& nums) {
        
//         if(nums.size()==2 && nums[0]>0) return 1;
//         int n = nums.size()-1;
//         int last = n;
//         int  cnt=0;
//         for(int i=n-1;i>=0;i--){
//             if(i+nums[i]>last) {
//                 cnt++;
//                 last=i;
//             }
//             if(i+nums[i]>=last) last=i;
//         }
//         return cnt;
//     }
// };
