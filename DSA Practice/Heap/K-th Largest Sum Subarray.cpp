#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int, vector<int>, greater<int>> pq;
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(pq.size() >= k && pq.top() < sum)  pq.pop();
			pq.push(sum);
		}
	}
	while(pq.size() > k) pq.pop();
	return pq.top();
}