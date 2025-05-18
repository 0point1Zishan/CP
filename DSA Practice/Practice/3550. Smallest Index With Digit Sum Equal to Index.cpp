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
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = digitSum(nums[i]);
            if(sum == i) return i;
        }
        return -1;
    }
};