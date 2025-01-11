class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        unordered_set<int>st;
        for(int i = 0; i < n; i++) st.insert(nums[i]);

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt = 1, num = it;
                while(st.find(num+1) != st.end()){
                    num++;
                    cnt++;
                }
                mx = max(mx, cnt);
            }
        }return mx;
    }
};