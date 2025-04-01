class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            int pre = 1;
            vector<int> ans = {1};
            for(int i = 1; i <= rowIndex; i++){
                int cur =  (1LL * pre * ((rowIndex + 1) - i)) / i;
                pre = cur;
                ans.push_back(cur);
            }
            return ans;
        }
    };