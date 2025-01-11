int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int idx = -1, mx = -1;    
    for(int i = 0; i < n; i++){
        int idxPoint = lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin();
        if(idxPoint == m) idxPoint++;
        int one = m - idxPoint;
        if(mx < one){
            idx = i;
            mx = one;
        }
    }
    return idx;
}