int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int, int> mp;  mp[0] = 1;
    int n = a.size(), cnt = 0, xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 ^= a[i];
        int xor2 = b ^ xor1;
        cnt += mp[xor2];
        mp[xor1]++;
    }
    return cnt;
}