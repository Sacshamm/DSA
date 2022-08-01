
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
       long long ans = INT_MAX, first = 0, last = m-1;
       while(last<n){
           ans = min(ans,a[last++]-a[first++]);
       }
       return ans;
    }   
};

//firstly sorting is done and after that we take a window upto m-1...... and checking minimum difference in that window

