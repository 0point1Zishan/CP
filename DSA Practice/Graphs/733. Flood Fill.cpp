class Solution {
    public:
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m, n, parColor, transColor;
        void dfs(vector<vector<int>>& image, int sr, int sc){
            for(auto it: dir){
                int x = sr + it.first;
                int y = sc + it.second;
                if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == parColor){
                    image[x][y] = transColor;
                    dfs(image, x, y);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            m = image.size(), n = image[0].size();
            parColor = image[sr][sc], transColor = color;
            if(transColor != image[sr][sc]){
                dfs(image, sr, sc);
                image[sr][sc] = transColor;
            }
        
            return image;
        }
    };