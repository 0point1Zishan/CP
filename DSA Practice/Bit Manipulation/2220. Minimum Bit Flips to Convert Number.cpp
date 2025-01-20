class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_ = start ^ goal;
        int cnt = 0;
        while(xor_){
            if(xor_ & 1) cnt++;
            xor_ = xor_ >> 1;
        }
        return cnt;
    }
};