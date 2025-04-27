class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            int n = responses.size(), m = responses[0].size();
            unordered_map<string, int> mp;
    
            for(int i = 0; i < n; i++){
                set<string> st;
                for(auto &it: responses[i]){
                    st.insert(it);
                }
                for(auto &it: st){
                    mp[it]++;
                }
            }
            int mx = 0;
            string ans = "";
            for(auto &[i, cnt]: mp){
                if(cnt > mx){
                    mx = cnt;
                    ans = i;
                }
                else if(cnt == mx){
                    ans = min(ans, i);
                }
            }
            return ans;
        }
    };