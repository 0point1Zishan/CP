class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> fre;
        int n = arr.size(), l = 0, r = 0, cnt = 2, mx = 0;
        
        while(r < n){
            
            if(fre[arr[r]] == 0) cnt--;
            fre[arr[r]]++;
            
            if(cnt < 0){
                fre[arr[l]]--;
                if(fre[arr[l]] == 0){
                    cnt++;
                    fre.erase(fre[arr[l]]);
                }
                l++;
            }
            if(cnt >= 0)  mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};