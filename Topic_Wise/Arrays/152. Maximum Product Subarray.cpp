class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int pre = 1, suff = 1;
        int ans = INT_MIN, n = arr.size();
        for(int i = 0; i < n; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= arr[i];
            suff *= arr[n-1-i];
            ans = max({ans, pre, suff});
        }
        return ans;
    }
};