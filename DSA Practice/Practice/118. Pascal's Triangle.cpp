class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            for(int i = 1; i <= numRows; i++){
                vector<int> v{1};
                int res = 1;
                for(int j = 1; j < i; j++){
                    res *= (i - j);
                    res /= j;
                    v.push_back(res);
                }
                ans.push_back(v);
            }
            return ans;
        }
    };