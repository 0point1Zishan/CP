class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            for(int i = 0; i < n; i++){
                vector<int> v;
                int k = 0;
                for(int j = i; j < n; j++){
                    v.push_back(grid[j][k++]);
                }
                sort(v.begin(), v.end(), greater<>());
                k = 0;
                int l = 0;
                for(int j = i; j < n; j++){
                    grid[j][k++] = v[l++];
                }
            }
            for(int i = 1; i < n; i++){
                vector<int> v;
                int k = 0;
                for(int j = i; j < n; j++){
                    v.push_back(grid[k++][j]);
                }
                sort(v.begin(), v.end());
                k = 0;
                int l = 0;
                for(int j = i; j < n; j++){
                    grid[k][j] = v[l];
                    k++;
                    l++;
                }
            }
            return grid;
        }
    };