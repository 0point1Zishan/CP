class Solution {
private:
int cnt(vector<int>&fre){
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < 26; i++){
        if(fre[i] != 0){
            mn = min(mn, fre[i]);
            mx = max(mx, fre[i]);
        }
    }
    if(mn == INT_MAX) return 0;
    return mx - mn;
}
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> fre(26, 0);

            for(int j = i; j < n; j++){
                fre[s[j]-'a']++;
                ans += cnt(fre);
            }            
        }
        return ans;
    }
};