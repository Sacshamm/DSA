#include <bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	stack<int>st;
	vector<int>nge(n,-1);
	for(int i=n-1;i>=0;i--){
		//make stack increasing
		while(!st.empty() && st.top()<=arr[i]){
			st.pop();
		}

		if(i<n && !st.empty()) nge[i] = st.top();

		st.push(arr[i]);
	}
	return nge;
}
