class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), i = 0, ele = 0, cnt = 0;
        while(i < n){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
            else if(ele == nums[i]) cnt++;
            else cnt--;
            i++;
        }
        return ele;
    }
};