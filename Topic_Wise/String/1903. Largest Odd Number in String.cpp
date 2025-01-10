class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int e = n-1;
        while(e >= 0 && ((num[e] - '0') & 1) == 0) e--;
        return (e < 0) ? "" : num.substr(0, e + 1);
    }
};