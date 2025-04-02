class Solution {
    public:
        int tribonacci(int n) {
            if(n == 0) return 0;
            int pre3 = 0, pre2 = 1, pre1 = 1;
            for(int i = 3; i <= n; i++){
                int cur = pre3 + pre2 + pre1;
                pre3 = pre2;
                pre2 = pre1;
                pre1 = cur;
            }
            return pre1;
        }
    };