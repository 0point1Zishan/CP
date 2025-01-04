#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        set<int> present;
        for(int j = i+1; j < n; j++){
            int k = -(arr[i] + arr[j]);
            if(present.find(k) != present.end()){
                vector<int>a = {k, arr[i], arr[j]};
                sort(a.begin(), a.end());
                st.insert(a);
            }
            present.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}