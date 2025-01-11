#include<bits/stdc++.h>
int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int mx = *max_element(arr.begin(), arr.end());
	int s = 1, e = mx + 1;
	int day = e, n = arr.size();
	auto isPos = [&](int d){
		int cnt = 0, cnt_bouquets = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] > d){
				cnt_bouquets += (cnt / k);
				cnt = 0;
			}
			else cnt++;
		}
		cnt_bouquets += (cnt / k);
		return cnt_bouquets >= m;
	};
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(isPos(mid)){
			day = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return (day == mx + 1 ? -1 : day);
}