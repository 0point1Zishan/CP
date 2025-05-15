class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> fre(26, 0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            fre[s[i] - 'a']++;
        }

        int mxV = 0, mxC = 1;
        for(int i = 0; i < 26; i++){
            char ch = (char)(i + 'a');
            bool isV = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
            if(isV){
                if(fre[i] > fre[mxV]) mxV = i;
            }
            else{
                if(fre[i] > fre[mxC]) mxC = i;
            }
        }
        return fre[mxV] + fre[mxC];
    }
};