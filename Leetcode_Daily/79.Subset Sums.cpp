
class Solution
{
public:
    void solve(int ind, int sum, vector<int> &ans, vector<int> arr, int N){
        if(ind == N) {
        ans.push_back(sum);
        return;
        }
        //take the element
        solve(ind+1,sum+arr[ind],ans,arr,N);
        //not take the element, also sum is not incremented sum
        solve(ind+1,sum,ans,arr,N);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        solve(0,0,ans,arr,N);
        return ans;
    }
};
