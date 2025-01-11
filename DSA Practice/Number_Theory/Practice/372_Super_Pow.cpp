class Solution {
public:
    int binExp(int a, int b, int m = 1337){
        a %= m;
        int ans = 1;
        while(b){
            if(b & 1) ans = (ans * 1LL * a) % m;
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int bPow = 0;
        for(int i = 0; i < b.size(); i++){
            bPow = (bPow * 10 + b[i]) % 1140;
        }
        if(bPow == 0) bPow = 1440;
        return binExp(a, bPow);
    }
};