class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxi= INT_MIN;
        
        while(left<=right){
            if(height[left]<=height[right]){
                maxi=max(height[left]*(right-left),maxi);
                left++;
            }
            if(height[left]>=height[right]){
                maxi=max(height[right]*(right-left),maxi);
                right--;
            }
        }
        return maxi;
    }
};
