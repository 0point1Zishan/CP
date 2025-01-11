class Solution {
public:
    int cnt = 0;
    void merge(vector<int>&nums, int l, int mid, int r){
        long long s = l, e = mid+1;
        while(s <= mid && e <= r){
            if(nums[s] > (nums[e]*2LL)){
                cnt += (mid - s + 1);
                e++;
            }
            else s++;
        }

        vector<int> v;
        s = l, e = mid+1;
        while(s <= mid && e <= r){
            if(nums[s] <= nums[e]){
                v.push_back(nums[s++]);
            }
            else v.push_back(nums[e++]);
        }
        while(s <= mid) v.push_back(nums[s++]);
        while(e <= r)  v.push_back(nums[e++]);
        for(int i = l; i <= r; i++) nums[i] = v[i-l];
    }
    void mergeSort(vector<int>&nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return cnt;
    }
};