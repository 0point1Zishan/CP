#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size(), m = b.size();
	int i = n-1, j = 0;
	while(i >= 0 && j < m){
		if(a[i] > b[j]) swap(a[i--], b[j++]);
		else break;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}