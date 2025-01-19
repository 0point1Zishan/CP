class Solution {
private:
    void solve(int i, int n, long long prev, long long curr, int target, string s, string& num, vector<string>& ans){
        if(i == n){
            if(curr == target) ans.push_back(s);
            return;
        }
        string str = "";
        long long val = 0;
        for(int j = i; j < n; j++){
            if(j > i && num[i] == '0') break;

            str += num[j];
            val = val * 10 + (num[j] - '0');

            if(i == 0) solve(j+1, n, val, val, target, str, num, ans);
            else{
                solve(j+1, n, val, curr + val, target, s + "+" + str, num, ans);
                solve(j+1, n, -val, curr - val, target, s + "-" + str, num, ans);
                solve(j+1, n, val * prev, curr - prev + (prev * val), target, s + "*" + str, num, ans);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num.size(), 0, 0, target, "", num, ans);
        return ans;
    }
};