class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";

        for(int i = 0; i < n; i++){
            while(!ans.empty() && k && ans.back() > num[i])     ans.pop_back(), k--;

            if((ans.empty() && num[i] > '0') || !ans.empty()) ans.push_back(num[i]);
        }
        while(k && !ans.empty()) ans.pop_back(), k--;
        if(ans.empty()) ans.push_back('0');
        return ans;
    }
};