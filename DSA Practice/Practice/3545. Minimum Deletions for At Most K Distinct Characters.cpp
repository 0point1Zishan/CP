class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();
        vector<int> v(26, 0);
        for(int i = 0; i < n; i++){
            v[s[i] - 'a']++;
        }
        vector<int> ch;
        for(int i = 0; i < 26; i++){
            if(v[i] > 0){
                ch.push_back(v[i]);
            }
        }
        sort(ch.begin(), ch.end());
        int ans = 0, i = 0;
         n = ch.size();
        while(n > k){
            ans += ch[i];
            n--;
            i++;
        }
        return ans;
    }
};