class Solution {
public:
    void allPerenthesis(int left, int right, string s, vector<string>& ans){
        if(!left && !right){
            ans.push_back(s);
            return;
        }

        if(left){
            s += '(';
            allPerenthesis(left-1, right, s, ans);
            s.pop_back();
        }
        if(right && left < right){
            s += ')';
            allPerenthesis(left, right-1, s, ans);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        allPerenthesis(n-1, n, "(", ans);
        return ans;
    }
};