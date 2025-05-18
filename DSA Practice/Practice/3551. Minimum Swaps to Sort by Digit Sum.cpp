class Solution {
private:
    int digitSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> par;
        for(int i = 0; i < n; i++){
            int sum = digitSum(nums[i]);
            par.push_back({sum, nums[i]});
        }
        sort(par.begin(), par.end(), [&](pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[par[i].second] = i;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i == mp[nums[i]]) continue;
            else{
                swap(nums[mp[nums[i]]], nums[i]);
                cnt++;
                i--;
            }
        }
        return cnt;
    }
};