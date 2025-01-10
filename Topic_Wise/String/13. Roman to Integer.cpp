class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int ans = 0, n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(i < n-1 && val[s[i+1]] > val[s[i]]) ans -= val[s[i]];
            else ans += val[s[i]];
        }
        return ans;
    }
};