class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int n = arr.size();
        int mx = arr[0] + arr[1], sum = mx;
        for(int i = 2; i < n; i++){
            sum -= arr[i-2];
            sum += arr[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};