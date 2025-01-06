class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int s = 0, e = arr.size()-1, idx = 0;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[s] <= arr[e]){
                if(arr[idx] > arr[s]) idx = s;
                break;
            }
            else if(arr[mid] <= arr[e]){
                if(arr[idx] > arr[mid]) idx = mid;
                e = mid - 1;
            }
            else{
                if(arr[idx] > arr[mid]) idx = mid;
                s = mid + 1;
            }
        }
        return idx;
    }
};