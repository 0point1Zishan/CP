int kDistinctChars(int k, string &str)
{
    // Write your code here
    int n = str.size(), l = 0, r = 0, mx = 0;
    vector<int> fre(26, 0);
    while(r < n){
        fre[str[r]-'a']++;
        if(fre[str[r] - 'a'] == 1) k--;

        while(l <= r && k < 0){
            fre[str[l] - 'a']--;
            if(fre[str[l] - 'a'] == 0) k++;
            l++;
        }
        mx = max(mx, r - l + 1);
        r++;
    }
    return mx;
}