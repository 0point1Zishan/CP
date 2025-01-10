class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> fre(26, 0);
        int n = s.size();
        for(char c: s)  fre[c - 'a']++;
        for(char c: t)  fre[c - 'a']--;

        for(auto c: fre){
            if(c != 0) return false;
        }return true;
    }
};