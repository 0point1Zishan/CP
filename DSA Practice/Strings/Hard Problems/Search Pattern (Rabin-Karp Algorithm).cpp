class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> res;
            int n = text.size(), m = pattern.size();
            int patVal = 0, txtVal = 0;
            int h = 1, d = 26;
            int mod = 107;
            
            for(int i = 0; i < m-1; i++){
                h = (h * d) % mod;
            }
            
            for(int i = 0; i < m; i++){
                patVal = (d * patVal + pattern[i]) % mod;
                txtVal = (d * txtVal + text[i]) % mod;
            }
            
            for(int i = 0; i <= n - m; i++){
                if(patVal == txtVal){
                    int j = 0;
                    for(; j < m; j++){
                        if(text[i+j] != pattern[j]) break;
                    }
                    
                    if(j == m){
                        res.push_back(i+1);
                    }
                }
                if(i < n - m){
                    txtVal = (d * (txtVal - text[i] * h) + text[i + m]) % mod;
                }
                if(txtVal < 0) txtVal += mod;
            }
            return res;
        }
     
};