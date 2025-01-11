class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0) continue;
                int mn = INT_MAX;
                if(j < i) mn = min(mn, triangle[i-1][j]);
                if(j > 0) mn = min(mn, triangle[i-1][j-1]);
                triangle[i][j] += mn;
            }
        }
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) mn = min(mn, triangle[n-1][i]);
        return mn;
    }
};