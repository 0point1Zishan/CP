class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt = 0;
            for(int i = low; i <= high; i++){
                vector<int> v;
                int n = i;
                while(n){
                    v.push_back(n%10);
                    n /= 10;
                }
                int sz = v.size();
                if(sz & 1) continue;
                int left = accumulate(v.begin(), v.begin()+(sz/2), 0);
                int right = accumulate(v.begin()+(sz/2), v.end(), 0);
                if(left == right) cnt++;
            }
            return cnt;
        }
    };