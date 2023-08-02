#include <bits/stdc++.h> 

void insert(stack<int>&st, int num){
	if(st.empty() || st.top()<=num){
		st.push(num);
		return;
	}

	int n  = st.top();
	st.pop();
	insert(st,num);
	st.push(n);
}

void sortStack(stack<int> &st)
{
	if(st.empty()){
		return;
	}

	int num = st.top();
	st.pop();
	sortStack(st);
	insert(st,num);
}
