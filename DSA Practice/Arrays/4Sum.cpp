#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < n; j++){
            int k = j+1, l = n-1;
            while(k < l){
                int rem = target - (nums[i] + nums[j] + nums[k] + nums[l]);
                if(rem < 0) l--;
                else if(rem > 0) k++;
                else{
                    vector<int> a = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(a);
                    l--;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}