class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, n = s.size();
        vector<int> pos(3, -1);
        for(int i = 0; i < n; i++){
            pos[s[i] - 'a'] = i;
            if(pos[0] != -1 && pos[1] != -1 && pos[2] != -1){
                cnt += (1 + min({pos[0], pos[1], pos[2]}));
            }
        }
        return cnt;
    }
};