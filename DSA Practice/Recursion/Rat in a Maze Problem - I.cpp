class Solution {
  private:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    string dirC = "DULR";
    
    bool isValid(int x, int y, vector<vector<int>> &mat){
        int n = mat.size();
        return (x < n && y < n && x >= 0 && y >= 0 && mat[x][y] == 1);
    }
    
    void sol(int x, int y, int n, string& s, vector<string>& ans, vector<vector<int>> &mat){
        
        if(x == n-1 && y == n-1){
            ans.push_back(s);
            return;
        }
        if(!isValid(x, y, mat)) return;
        
        
        mat[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i].first;
            int yy = y + dir[i].second;
            s += dirC[i];
            sol(xx, yy, n, s, ans, mat);
            s.pop_back();
        }
        mat[x][y] = 1;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        string s = "";
        vector<string> ans;
        sol(0, 0, n, s, ans, mat);
        return ans;
    }
};