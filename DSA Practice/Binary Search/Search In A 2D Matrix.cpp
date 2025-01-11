bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int s = 0, e = n-1;

    auto searchArray = [&](int idx){
        int l = 0, r = m-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mat[idx][mid] == target) return true;
            if(mat[idx][mid] > target) r = mid - 1;
            else  l = mid + 1;
        }
        return false;
    };
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(mat[mid][0] > target)    e = mid - 1;
        else if(mat[mid][m-1] < target) s = mid + 1;
        else{
            return searchArray(mid);
        }
    }
    return false;
}