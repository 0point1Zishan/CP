class Solution {
    public:
        long long maxScore(vector<int>& points, int m) {
    
            long long l = 0, r = m * 1e6, n = points.size();
    
            auto isPos = [&](long long mn){
                vector<long long> req(n+1);
                for(int i = 0; i < n; i++)   req[i] = (mn + points[i] - 1) /points[i];
    
                long long total = n, ans = 0;
                for(int i = 0; i < n && total > 0; i++){
    
                    ans++; req[i]--;
                    if(req[i] >= 0) total--;
                    
                    if(req[i] > 0){
                        ans += req[i] * 2;
                        req[i+1] = max(0ll, req[i+1] - req[i]);
    
                        if(!req[i+1])  total--;
                    }
                }
                return ans > m;
            };
    
            while(l < r){
                long long mid = l + (r - l) / 2 + 1;
                if(isPos(mid))  r = mid - 1;
                else l = mid;
            }
            return l;
        }
    };