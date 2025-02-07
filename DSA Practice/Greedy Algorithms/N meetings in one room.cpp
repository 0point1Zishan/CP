class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        
        sort(v.begin(), v.end(), [&](int& a, int& b){
            return max(start[a], end[a]) < max(start[b], end[b]);
        });
        
        int cnt = 1, last = 0;
        for(int i = 1; i < n; i++){
            if(start[v[i]] > end[v[last]]){
                cnt++;
                last = i;
            }
        }
        return cnt;
    }
};