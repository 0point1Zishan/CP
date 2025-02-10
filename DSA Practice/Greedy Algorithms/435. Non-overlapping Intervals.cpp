class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });
    
            int cnt = 1, i = 1, n = intervals.size(), last = intervals[0][1];
            while(i < n){
                if(intervals[i][0] >= last){
                    cnt++;
                    last = intervals[i][1];
                }
                i++;
            }
            return n - cnt;
        }
    };