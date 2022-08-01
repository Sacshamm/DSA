//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
    int start=0;
    int end=n-1;
   // vector<pair<int,int>> ans;
   int count=0;
    
    while(start<end){
        if(arr[start]+arr[end]==sum){
            start++;end--;
           // ans.push_back(make_pair(arr[start],arr[end]));
           count++;
        }
         if(arr[start]+arr[end]>sum){// if sum is greater it means we dont need larger element bcz we can try more combinations with smaller element, so thats why neglecting larger
            end--;
        }
         if(arr[start]+arr[end]<sum) start++;// if sum is smaller it means we can try more with larger element so neglecting smalller one
    }
    
        if(count!=0)return count;
        else return -1;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
