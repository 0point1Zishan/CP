class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v(202);
        for(int i = 0; i < nums.size(); i++){
            v[nums[i] + 100]++;
        }
        int cnt = 0;
        int j = 0;
        for(int i = 0; i < 202; i++){
            if(v[i]){
                nums[j++] = i - 100;
                cnt++;
            }
        }return cnt;
    }
};