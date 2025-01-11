class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, num = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                num = nums[i];
            }
            else if(num == nums[i]) cnt++;
            else  cnt--;
        }
        return num;
    }
};