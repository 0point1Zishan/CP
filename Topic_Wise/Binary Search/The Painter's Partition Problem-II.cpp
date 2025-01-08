class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        int n = arr.size();
        long long s = *max_element(arr.begin(), arr.end()),
        e = accumulate(arr.begin(), arr.end(), 0LL);
        
        auto count = [&](int d){
            int cnt = 1, sum = 0;
            for(int i = 0; i < n; i++){
                if(sum + arr[i] > d){
                    cnt++;
                    sum = arr[i];
                }
                else sum += arr[i];
            }return cnt;
        };
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            int cnt = count(mid);
            if(cnt <= k) e = mid - 1;
            else         s = mid + 1;
        }return s;
    }
};