# Prefix Sum

### Code:
```cpp
int n, m;       cin >> n >> m;
vector<vector<int>> v(n+1, vector<int>(m+1));
vector<vector<int>> pf(n+1, vector<int>(m+1));

for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){ 
        cin >> v[i][j];
        pf[i][j] = v[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
    }
}

int q;  cin >> q;
while(q--){
    int a, b, c, d;  cin >> a >> b >> c >> d;
    cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << "\n";
}
```
#### TC: O(max((n*m), q)). 