class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {

        // Your code here
        int s = 0, e = arr.size()-1, idx = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid] <= k){
                idx = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return idx;
    }
};