class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int missing = arr.back() - n;
        if(k > missing){
            return arr.back() + (k - missing);
        }
        int mx = *max_element(arr.begin(), arr.end());
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int missing = arr[mid] - mid - 1;
            if(missing < k) s = mid + 1;
            else{
                if(mid == 0) return k;
                else if(arr[mid-1] - mid < k){
                    int diff = k - (arr[mid-1] - mid);
                    return arr[mid-1] + diff;
                }
                else e = mid - 1;
            }
        }
        return -1;
    }
};