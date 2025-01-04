#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	vector<int> a = arr[0];

	int n = arr.size();
	for(int i = 1; i < n; i++){
		if((a[1] <= arr[i][1] || a[1] >= arr[i][1]) && (a[1] >= arr[i][0])){
			a[1] = max(a[1], arr[i][1]);
		}
		else{
			ans.push_back(a);
			a[0] = arr[i][0];
			a[1] = arr[i][1];
		}
	}

	ans.push_back(a);
	return ans;
	
}