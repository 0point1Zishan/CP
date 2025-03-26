class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1) return "1";
            string ans = "1";
            for(int i = 2; i <= n; i++){
    
                int j = 0;
                string cur = "";
                while(j < ans.size()){
                    int cnt = 0;
                    int k = j;
                    while(k < ans.size() && ans[j] == ans[k]){
                        cnt++;
                        k++;
                    }
                    cur += to_string(cnt);
                    cur += ans[j];
                    j = k;
                }
                ans = cur;
            }
            return ans;
        }
    };