class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> a = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= a[1]) a[1] = max(a[1], intervals[i][1]);
            else{
                ans.push_back(a);
                a[0] = intervals[i][0];
                a[1] = intervals[i][1];
            }
        }
        ans.push_back(a);
        return ans;
    }
};