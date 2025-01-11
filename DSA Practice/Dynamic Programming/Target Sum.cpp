#include <bits/stdc++.h> 
int way(int i, int n, int target, vector<int>&arr, map<pair<int,int>, int> &dp){
    if(i == n){
        if(target == 0) return 1;
        else            return 0;
    }
    if(dp.find({i, target}) != dp.end()) return dp[{i, target}];

    int op1 = way(i+1, n, target - arr[i], arr, dp);
    int op2 = way(i+1, n, target + arr[i], arr, dp);
    return dp[{i, target}] = op1 + op2;
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    map<pair<int,int>, int> dp;
    return way(0, n, target, arr, dp);
}