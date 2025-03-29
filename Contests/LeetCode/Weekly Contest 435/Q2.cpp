int maxDistance(string str, int k) {
    int n = 0, s = 0, e = 0, w = 0, ans = 0, extraDisPos = 0;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'N') n++;
        else if(str[i] == 'S') s++;
        else if(str[i] == 'E') e++;
        else w++;

        int mn = min(n, s); mn += min(e, w);
        int mx = max(n, s); mx += max(e, w);

        extraDisPos = min(k, mn);
        ans = max(ans, mx + extraDisPos - (mn - extraDisPos));
    }return ans;
}