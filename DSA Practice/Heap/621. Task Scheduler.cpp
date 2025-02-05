class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fre(26, 0);
        int mx = 0;
        for(auto &c: tasks){
            fre[c-'A']++;
            mx = max(mx, fre[c-'A']);
        }

        int ans = (mx - 1) * (n + 1);
        for(auto cnt: fre){
            if(cnt == mx) ans++;
        }
        return max(ans, (int)tasks.size());
    }
};