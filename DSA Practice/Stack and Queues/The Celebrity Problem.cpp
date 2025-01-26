class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), s = 0, e = n-1;
        while(s < e){
            if(mat[s][e] == 1) s++;
            else if(mat[e][s] == 1) e--;
            else   s++,   e--;
        }
        if(s > e) return -1;
        for(int i = 0; i < n; i++){
            if(i != s && (mat[s][i] == 1 || mat[i][s] == 0)) return -1;
        }
        return s;
    }
};