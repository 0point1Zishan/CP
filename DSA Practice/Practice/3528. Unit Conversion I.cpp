class Solution {
    int mod = 1e9 + 7;
    public:
        vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
            int n = conversions.size();
            vector<int> point(n+1, 1);
            
            for(auto &it: conversions){
                point[it[1]] = (1LL * point[it[0]] * it[2]) % mod;
            }
            return point;
        }
    };