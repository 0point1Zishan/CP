class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> ans;
            int ele1 = 0, cnt1 = 0, ele2 = 0, cnt2 = 0, n = nums.size();
            for(int i = 0; i < n; i++){
    
                if(!cnt1 && (!cnt2 || (cnt2 && ele2 != nums[i])) ){
                    cnt1 = 1;
                    ele1 = nums[i];
                }
                else if(!cnt2 && (!cnt1 || (cnt1 && ele1 != nums[i]))){
                    cnt2 = 1;
                    ele2 = nums[i];
                }
                else if(nums[i] == ele1) cnt1++;
                else if(nums[i] == ele2) cnt2++;
                else{
                    cnt1--;
                    cnt2--;
                }
            }
            if(ele1 > ele2) swap(ele1, ele2);
    
            int occ1 = 0, occ2 = 0;
            for(int i= 0; i < n; i++){
                if(nums[i] == ele1) occ1++;
                if(nums[i] == ele2) occ2++;
            }
            if(occ1 >= (n/3)+1) ans.push_back(ele1);
            if(ele1 == ele2) return ans;
            if(occ2 >= (n/3)+1) ans.push_back(ele2);
            return ans;
        }
    };