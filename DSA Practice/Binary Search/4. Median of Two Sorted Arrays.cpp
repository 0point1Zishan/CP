class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int tn = n + m, half = (n + m + 1) / 2;
        int s = 0, e = n;

        while(s <= e){
            int mid1 = s + (e - s) / 2;
            int mid2 = half - mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(mid1 < n)      r1 = nums1[mid1];
            if(mid2 < m)      r2 = nums2[mid2];

            if(l1 > r2) e = mid1 - 1;
            else if(l2 > r1) s = mid1 + 1;
            else{
                if(tn % 2 == 0) return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                else return max(l1, l2);
            } 
        }
        return -1;
    }
};