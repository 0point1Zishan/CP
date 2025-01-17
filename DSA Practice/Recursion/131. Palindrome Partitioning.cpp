class Solution {
private:
    bool isPalindrome(string& s, int l, int r){
        
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;   r--;
        }
        return true;
    }
    void sol(string s, vector<string>& v, vector<vector<string>>& ans, int i, int n){
        if(i == n){
            ans.push_back(v);
            return;
        }
        
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)){
                v.push_back(s.substr(i, j - i + 1));
                sol(s, v, ans, j+1, n);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int n = s.size();
        sol(s, v, ans, 0, n);
        return ans;
    }
};