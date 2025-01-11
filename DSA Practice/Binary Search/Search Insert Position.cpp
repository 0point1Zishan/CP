int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.
	int e = arr.size()-1, s = 0, idx = 0;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] < m){
			idx = mid + 1;
			s = mid + 1;
		}
		else e = mid - 1;
	}return idx;
}