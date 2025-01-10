class Solution {
  public:
    long long cnt(string& s, int n, int k){
        long long ans = 0;
        vector<int> fre(26, 0);
        
        int j = 0, d = 0;
        for(int i = 0; i < n; i++){
            
            while(j < n && d < k){
                int c = s[j] - 'a';
                fre[c]++;
                if(fre[c] == 1) d++;
                j++;
            }
            if(d >= k) ans += (n - j + 1);
            int c = s[i] - 'a';
            fre[c]--;
            if(fre[c] == 0) d--;
        }
        return ans;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        int n = s.size();
        long long ans = cnt(s, n, k) - cnt(s, n, k+1);
        return ans;
    }
};