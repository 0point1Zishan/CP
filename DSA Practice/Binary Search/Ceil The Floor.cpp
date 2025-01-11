pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int s = 0, e = n-1, floor_ = -1, ceil_ = -1;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(a[mid] <= x){
			floor_ = a[mid];
			s = mid + 1;
		}
		else e = mid -1;
	}
	s = 0, e = n-1;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(a[mid] >= x){
			ceil_ = a[mid];
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return {floor_, ceil_};
}