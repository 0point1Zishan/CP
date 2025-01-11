int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    long long sum = (N * (N + 1)) / 2;
    return sum - accumulate(a.begin(), a.end(), 0LL);
}