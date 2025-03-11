int lcs(string &s, string &t){
    // Write your code here.
    int n = s.size(), m = t.size();
    vector<int> pre(m+1, 0), cur(m+1, 0);
    int mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + pre[j-1];
                mx = max(mx, cur[j]);
            }
            else cur[j] = 0;
        }
        pre = cur;
    }
    return mx;
}