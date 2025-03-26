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
    public:
      vector<int> search(string& pat, string& txt) {
          // code here
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
  };