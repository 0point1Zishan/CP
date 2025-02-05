class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for(int i = 0; i < N; i++)  pq.push({arr[i], i});
        
        vector<int> ans(N);
        int rank = 1;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            ans[top.second] = rank;
            if(!pq.empty() && top.first != pq.top().first) rank++;
        }
        return ans;
    }
};