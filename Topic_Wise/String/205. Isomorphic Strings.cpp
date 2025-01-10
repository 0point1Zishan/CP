class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sMap(256, -1);
        vector<int> tMap(256, -1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            int sC = s[i], tC = t[i];

            if(sMap[sC] == -1) sMap[sC] = tC;
            else if(sMap[sC] != tC) return false;

            if(tMap[tC] == -1) tMap[tC] = sC;
            else if(tMap[tC] != sC) return false;
            
        }return true;
    }
};