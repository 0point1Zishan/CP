class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < arr.size(); i++) pq.push(arr[i]);
        
        int totalCost = 0;
        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            
            totalCost += (a + b);
            pq.push(a + b);
        }
        return totalCost;
    }
};