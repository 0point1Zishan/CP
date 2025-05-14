class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
            }
        }

        long long curSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                curSum += grid[i][j];
            }
            long long rem = sum - curSum;
            if(i < n-1 && rem == curSum) return true;
        }

        curSum = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                curSum += grid[i][j];
            }
            long long rem = abs(sum - curSum);
            if(j < m-1 && rem == curSum) return true;
        }
        return false;
    }
};