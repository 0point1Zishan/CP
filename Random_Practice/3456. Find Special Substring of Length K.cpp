class Solution {
    private:
        bool isPos(int& idx, vector<int>& fre, int& k, int& n, string& s){
            char ch = '*';
            for(int i = 0; i < 26; i++){
                if(fre[i] == k) ch = char(i + 'a');
            }
            if(ch == '*') return false;
            if(idx-k >= 0 && ch == s[idx-k]) return false;
            if(idx+1< n && ch == s[idx+1]) return false;
            return true;
        }
    public:
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            vector<int> fre(26, 0);
            int i = 0;
            for(; i < k; i++){
                fre[s[i] - 'a']++;
            }
            int j = i-1;
            if(isPos(j, fre, k, n, s)) return true;
            
            while(i < n){
                fre[s[i-k] - 'a']--;
                fre[s[i] - 'a']++;
                if(isPos(i, fre, k, n, s)) return true;
                i++;
            }
            return false;
        }
    };