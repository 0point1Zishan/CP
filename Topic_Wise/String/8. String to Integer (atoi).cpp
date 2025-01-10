class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        bool NumStarted = false, isStarted = false, neg = false;

        int i = 0;
        while(i < n && s[i] == ' ') i++;
        while(i < n){
            if(!NumStarted && !isStarted && (s[i] == '-' || s[i] == '+')){
                isStarted = true;
                if(s[i] == '-') neg = true;
            }
            else if(s[i] >= '0' && s[i] <= '9'){

                long long val = (ans * 10) + (s[i] - '0');

                if(neg && val <= (1LL << 31) )   ans = val;
                else if(neg) return INT_MIN;
                else if(val <= ((1LL << 31) - 1)) ans = val;
                else return INT_MAX;

                NumStarted = true;
            }
            else break;
            i++;
        }
        if(neg) ans *= -1;
        return ans;
    }
};