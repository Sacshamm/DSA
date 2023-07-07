#include <bits/stdc++.h>


pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int rep=-1, miss=-1;
	int hash[n+1] = {0};
        for (int i = 0; i < n; i++) {
          hash[arr[i]]++;
        }

        for(int i=1;i<=n;i++){
			if(hash[i]==2) rep = i;
			if(hash[i]==0) miss = i;
		}
	
	return {miss,rep};
}



////O(N^2)
// pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
// 	// Write your code here 
// 	int rep=-1, miss=-1;

// 	for(int i=1;i<=n;i++){
// 		int  cnt = 0;
// 		for(int j=0;j<n;j++){
// 			if(arr[j]==i) cnt++;
// 		}
// 		if(cnt == 2) rep = i;
// 		if(cnt == 0) miss = i;

// 		if(miss!=-1 && rep!=-1) break;
// 	}
// 	return {miss,rep};
// }
