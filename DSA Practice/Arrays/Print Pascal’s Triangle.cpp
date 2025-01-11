vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> a(1, 1);
    ans.push_back(a);
    for(int i = 1; i < N; i++){
        vector<int> a(i+1);
        a[0] = 1; a[i] = 1;
        
        for(int j = 1; j < i; j++){
            a[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        
        ans.push_back(a);
    }
    return ans;
}