class Solution {
public:
    string frequencySort(string s) {
        vector<int> fre(128, 0);
        int n = s.size();
        for(char c: s)  fre[c]++;

        vector<pair<int, int>> pr;
        for(int i = 0; i < 128; i++){
            if(fre[i] > 0) pr.push_back({fre[i], i});
        }
        sort(pr.begin(), pr.end(), greater<>());

        string ans = "";
        for(auto p: pr){
            string t(p.first, p.second);
            ans += t;
        }
        return ans;
    }
};