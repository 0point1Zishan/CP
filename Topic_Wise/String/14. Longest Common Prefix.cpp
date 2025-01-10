class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mn = INT_MAX, n = strs.size();
        for(int i = 0; i < n; i++){
            if(strs[i].size() < mn) mn = strs[i].size();
        }
        int e = mn-1, ans = -1, s = 0;
        while(s <= e){
            for(int i = 1; i < n; i++){
                if(strs[i][s] != strs[0][s]){
                    return strs[0].substr(0, s);
                }
            }
            s++;
        }
        return strs[0].substr(0, s);
    }
};