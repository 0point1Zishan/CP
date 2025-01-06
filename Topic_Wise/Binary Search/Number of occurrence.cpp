#include<bits/stdc++.h>
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int u = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

	if(l == n || u == 0) return 0;
	return (u - l);
}