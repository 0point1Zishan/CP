class Solution {
    public:
        long long minTime(vector<int>& skill, vector<int>& mana) {
            int n = skill.size(), m = mana.size();
    
            vector<long long> pre(n), cur(n);
            pre[0] = mana[0] * skill[0];
            for(int i = 1; i < n; i++)  pre[i] = pre[i-1] + mana[0] * skill[i];
    
            for(int i = 1; i < m; i++){
    
                cur[0] = pre[0] + mana[i] * skill[0];
                for(int j = 1; j < n; j++){
                    cur[j] = max(pre[j], cur[j-1]) + mana[i] * skill[j];
                }
    
                long long time = cur[n-1];
                for(int j = n-2; j >= 0; j--){
                    int t = mana[i] * skill[j+1];
                    time -= t;
                    cur[j] = time;
                }
                pre = cur;
            }
            return pre[n-1];
        }
    };