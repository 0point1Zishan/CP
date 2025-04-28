class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans = 0, sum = 0;
            int n = nums.size(), cnt = 0, i = 0, j = 0;
            
            while(i < n){
                bool isT = false;
                cnt++;
                sum += nums[i];
                if((sum * cnt) < k) ans += cnt;
                else isT = true;
    
                while(cnt && (sum * cnt) >= k){
                    cnt--;
                    sum -= nums[j];
                    j++;
                }
                if(isT && (sum * cnt) < k) ans += cnt;
                i++;
            }
            return ans;
        }
    };