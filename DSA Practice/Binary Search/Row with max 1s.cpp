class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int idx = -1, mx = -1;
        int n = arr.size(), m = arr[0].size();
        
        auto lower = [&](int i){
            int s = 0, e = m-1, idxP = m+1;
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(arr[i][mid] == 0) s = mid + 1;
                else{
                    idxP = mid;
                    e = mid - 1;
                }
            }
            return idxP;
        };
        
        for(int i = 0; i < n; i++){
            int idxPoint = lower(i);
            int one = m - idxPoint;
            if(mx < one){
                idx = i;
                mx = one;
            }
        }
        return idx;
    }
};