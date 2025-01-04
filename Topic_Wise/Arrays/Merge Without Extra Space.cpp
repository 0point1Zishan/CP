class Solution {
  public:
    void swapVal(vector<int>&a, vector<int>&b, int x, int y){
        if(a[x] > b[y]) swap(a[x], b[y]);
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size(), gap = (n + m + 1) / 2;
        while(gap > 0){
            int l = 0, r = l + gap;
            while(r < m + n){
                if(l < n && r >= n){
                    swapVal(a, b, l, r - n);
                }
                else if(l >= n){
                    swapVal(b, b, l-n, r - n);
                }
                else{
                    swapVal(a, a, l, r);
                }
                l++, r++;
            }
            if(gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};