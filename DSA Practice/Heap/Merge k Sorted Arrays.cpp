class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pq.push(arr[i][j]);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};