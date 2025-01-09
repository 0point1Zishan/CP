class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        auto isPre = [&](int row){
            int s = 0, e = m-1;
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(matrix[row][mid] == target) return true;
                else if(matrix[row][mid] > target) e = mid - 1;
                else s = mid + 1;
            }
            return false;
        };

        for(int i = 0; i < n; i++){
            if(isPre(i)) return true;
        }return false;
    }
};
