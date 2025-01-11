int singleNonDuplicate(vector<int>& arr)
{	
	int n = arr.size();
	if(arr[0] != arr[1] || n == 1) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];
	int s = 0, e = n-1, single = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
		if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])) s = mid + 1;
		else e = mid-1;
	}
	return -1;
}