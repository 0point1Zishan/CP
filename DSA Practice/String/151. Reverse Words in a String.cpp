class Solution {
public:
    void reverse(string &s, int l, int r){
        while (l < r)  swap(s[l++], s[r--]);
    }

    string reverseWords(string s) {
        
        int n = s.size();
        int i = 0, j = 0;
        while(j < n){
            if(s[j] != ' ' || (i > 0 && s[i - 1] != ' '))    s[i++] = s[j];
            j++;
        }

        if(i > 0 && s[i - 1] == ' ') i--;
        s.resize(i);

        reverse(s, 0, i - 1);
        int l = 0;
        for(int r = 0; r <= i; r++){
            if(r == i || s[r] == ' '){
                reverse(s, l, r - 1);
                l = r + 1;
            }
        }
        return s;
    }
};