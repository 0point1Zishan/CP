class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, cnt = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            sum += arr[i];
            int rem = sum - k;
            
            cnt += mp[rem];
            
            mp[sum]++;
        }
        return cnt;
    }
};