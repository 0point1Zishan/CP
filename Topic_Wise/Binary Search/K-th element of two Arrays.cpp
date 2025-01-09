class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
        int s = max(0, k - m), e = min(k, n);
        while(s <= e){
            int mid1 = s + (e - s) / 2;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 > 0) l1 = a[mid1-1];
            if(mid2 > 0) l2 = b[mid2-1];
            if(mid1 < n) r1 = a[mid1];
            if(mid2 < m) r2 = b[mid2];
            
            if(l1 > r2) e = mid1 - 1;
            else if(l2 > r1) s = mid1 + 1;
            else{
                if(mid1 < k && l2 == INT_MIN) s = mid1 + 1;
                else return max(l1, l2);
            }
        }
        return -1;
    }
};