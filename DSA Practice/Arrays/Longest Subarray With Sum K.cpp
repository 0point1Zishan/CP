int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int cnt = 0, i = 0, j = 0, n = a.size();
    long long sum = 0;
    while(i < n){
        sum += a[i];
        if(sum == k) cnt = max(cnt, i - j + 1);
        while(sum > k && j <= i){
            sum -= a[j++];
        }if(sum == k)  cnt = max(cnt, i-j+1);
        i++;
    }
    return cnt;
}