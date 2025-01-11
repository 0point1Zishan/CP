class Solution {
  public:
    int median(vector<vector<int>> &a) {
        // code here
        int n = a.size(), m = a[0].size();
        int s = INT_MAX, e = INT_MIN;
        for(int i = 0; i < n; i++) s = min(a[i][0], s);
        for(int i = 0; i < n; i++) e = max(a[i][n-1], e);
    
        auto count = [&](int target, int row){
            int s = 0, e = m-1, ans = m;
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(a[row][mid] <= target)  s = mid + 1;
                else e = mid - 1, ans = mid;
            }return ans;
        };
    
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            int cnt = 0;
            for(int i = 0; i < n; i++)  cnt += count(mid, i);
            
            int req = (n * m) / 2;
            if(cnt > req)  e = mid - 1;
            else   s = mid + 1;
    
        }
        return s;
    }
};