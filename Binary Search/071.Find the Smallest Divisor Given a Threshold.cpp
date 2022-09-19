class Solution {
public:
    bool check_threshold(vector<int>& nums, int threshold, int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            //if a divisior divides nums[i]completely then no need to add 1 
            if(nums[i]%mid==0) 
                sum+=nums[i]/mid;
            else
                //need to add 1 bcz 2/5=0.4---- so adding 1 to integer value 0+1makes it 1
                sum+=nums[i]/mid+1;
        }
        return sum<=threshold;//if sum is less it means it may be a candidate
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=INT_MAX;
        int ans=0;
        
        while(s<=e){
            int mid= s+(e-s)/2;
            if(check_threshold(nums,threshold,mid)){
                ans=mid;//if sum is less than th. then it may be a ans.But we have to find smallest divisor.
                e=mid-1;//Checking for more smaller divisor in left part
            }
            else
                s=mid+1;//if sum is too big in that case we increse value of divisior
        }
        return ans;
    }
};
