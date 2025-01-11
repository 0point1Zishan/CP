#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n = arr.size();
	vector<int> sec(n-1, 0);
	priority_queue<pair<long double, int>> q;
	for(int i = 0; i < n-1; i++){
		long double diff = arr[i+1] - arr[i];
		q.push({diff, i});
	}
	
	for(int i = 1; i <= k; i++){
		auto pr = q.top();
		q.pop();
		int idx = pr.second;
		sec[pr.second]++;
		long double diff = (arr[idx+1] - arr[idx]) / (long double)(sec[idx] + 1);
		q.push({diff, idx});
	}
	return (double)q.top().first;
}
