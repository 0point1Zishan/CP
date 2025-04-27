class Solution {
    private:
        void constructLps(string& pat, vector<int>& lps){
            int len = 0, i = 1, n = pat.size();
            
            while(i < n){
                if(pat[i] == pat[len]){
                    len++;
                    lps[i] = len;
                    i++;
                }
                else{
                    if(len == 0){
                        lps[i] = 0; i++;   
                    }
                    else len = lps[len - 1];
                }
            }
        }
        vector<int> search(string& pat, string& txt) {
            int n = txt.size(), m = pat.size(), i = 0, j = 0;
            vector<int> lps(m, 0), res;
            constructLps(pat, lps);
            
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                    if(j == m){
                        res.push_back(i - m);
                        j = lps[j - 1];
                    }
                }
                else{
                    if(j != 0) j = lps[j-1];
                    else i++;
                }
            }
            return res;
        }
    
    public:
        int countCells(vector<vector<char>>& grid, string pattern) {
            int pSz = pattern.size();
            int n = grid.size(), m = grid[0].size();
            string ver = "";
            string hor = "";
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    ver += grid[i][j];
                }
            }
            for(int j = 0; j < m; j++){
                for(int i = 0; i < n; i++){
                    hor += grid[i][j];
                }
            }
            vector<int> verVec = search(pattern, ver);
            vector<int> horVec = search(pattern, hor);
    
            vector<int> verMark(n * m + 1 , 0), horMark(n * m + 1, 0);
            int i = 0;
            while(i < verVec.size()){
                int idx = verVec[i];
                verMark[idx] ++;
                verMark[idx + pSz]--;
                i++;
            }
            i = 0;
            while(i < horVec.size()){
                int idx = horVec[i];
                horMark[idx]++;
                horMark[idx + pSz]--;
                i++;
            }
    
            for(int i = 1; i < n*m; i++){
                verMark[i] += verMark[i-1];
                horMark[i] += horMark[i-1];
            }
    
            int cnt = 0;
            for(int i = 0; i < horMark.size(); i++){
                if(horMark[i] > 0){
                    int row = i / n;
                    int col = i % n;
    
                    int idx = (col * m) + row;
                    if(verMark[idx]) cnt++;
                }
            }
            return cnt;
        }
    };