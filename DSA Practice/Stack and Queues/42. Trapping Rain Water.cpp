class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lMx = 0, rMx = 0, ans = 0;

        while(l <= r){
            if(height[l] <= height[r]){
                if(lMx < height[l]) lMx = height[l];
                else ans += lMx - height[l];
                l++;
            }
            else{
                if(rMx < height[r]) rMx = height[r];
                else  ans += rMx - height[r];
                r--;
            }
        }
        return ans;
    }
};