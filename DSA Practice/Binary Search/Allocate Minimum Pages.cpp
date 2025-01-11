class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        long long s = *max_element(arr.begin(), arr.end()), 
        e = accumulate(arr.begin(), arr.end(), 0LL);
        
        auto stuPage = [&](int page){
            long long cnt = 1, sum = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] + sum > page){
                    cnt++;
                    sum = arr[i];
                }
                else sum += arr[i];
            }
            return cnt;
        };
        
        while(s <= e){
            long long mid = s + (e - s) / 2;
            int cnt = stuPage(mid);
            if(cnt > k) s = mid + 1;
            else e = mid - 1;
        }
        return s;
    }
};