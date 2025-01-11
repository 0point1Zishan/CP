#include<bits/stdc++.h>
int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int n = a.size();
    long long s = *max_element(a.begin(), a.end()),
    e = accumulate(a.begin(), a.end(), 0LL);

    auto count = [&](int mid){
        int cnt = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + a[i] > mid){
                cnt++;
                sum = a[i];
            }
            else sum += a[i];
        }return cnt;
    };

    while(s <= e){
        int mid = s + (e - s) / 2;
        int cnt = count(mid);
        if(cnt <= k) e = mid - 1;
        else         s = mid + 1;
    }return s;
}