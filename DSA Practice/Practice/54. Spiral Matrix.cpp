class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
            vector<int> ans;
            int n = matrix.size(), m = matrix[0].size();
            int rs = 0, re = n-1, cs = 0, ce = m-1;
    
            while(rs <= re && cs <= ce){
                
                for(int j = cs; j <= ce; j++){
                    ans.push_back(matrix[rs][j]);
                }
                rs++;
    
                for(int i = rs; i <= re; i++){
                    ans.push_back(matrix[i][ce]);
                }
                ce--;
    
                if(rs <= re){
                    for(int j = ce; j >= cs; j--){
                        ans.push_back(matrix[re][j]);
                    }
                    re--;
                }
                
                if(cs <= ce){
                    for(int i = re; i >= rs; i--){
                        ans.push_back(matrix[i][cs]);
                    }
                    cs++;
                }
            }
            
            return ans;
        }
    };