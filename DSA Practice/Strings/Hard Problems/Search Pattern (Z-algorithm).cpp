class Solution
{
    private:
        void constructZArray(string& s, vector<int>& z){
            int n = s.size(), l = 0, r = 0, k;
            
            for(int i = 1; i < n; i++){
                if(i > r){
                    l = r = i;
                    while(r < n && s[r - l] == s[r]) r++;
                    z[i] = r - l;
                    r--;
                }
                else{
                    k = i - l;
                    if(z[k] < r - i + 1) z[i] = z[k];
                    else{
                        l = i;
                        while(r < n && s[r - l] == s[r]) r++;
                        z[i] = r - l;
                        r--;
                    }
                }
            }
        }
        
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string concat = pat + '$' + txt;
            int n = concat.size();
            
            vector<int> z(n);
            constructZArray(concat, z);
            
            vector<int> ans;
            for(int i = 0; i < n; i++){
                if(z[i] == pat.size()) ans.push_back(i - pat.size());
            }
            return ans;
        }
     
};