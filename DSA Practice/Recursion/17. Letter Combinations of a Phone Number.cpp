class Solution {
private:
    void sol(int i, int& n, string& digit, string& s, vector<string>& ans, vector<string>& key){
        if(i == n){
            ans.push_back(s);
            return;
        }

        for(int j = 0; j < key[digit[i] - '0'].size(); j++){
            s.push_back(key[digit[i] - '0'][j]);
            sol(i+1, n, digit, s, ans, key);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(!n)  return ans;

        string s = "";
        vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        sol(0, n, digits, s, ans, key);
        return ans;
    }
};