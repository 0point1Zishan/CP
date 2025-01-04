#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	unordered_map<int, int> mp;
	mp[0] = 0;
	int sum = 0, n = arr.size(), mx = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
		int rem = -(sum);
		if(mp.find(rem) != mp.end()){
			mx = max(mx, i - mp[rem] + 1);
		}
		if(mp.find(rem) == mp.end()) mp[rem] = i + 1;
	}
	if(sum == 0) mx = n;
	return mx;
	
}