class Solution {
  public:
    // Function to count inversions in the array.
    int cnt = 0;
    void merge(vector<int>&arr, int l, int mid, int r){
        vector<int> v;
        int s = l, e = mid+1;
        while(s <= mid && e <= r){
            if(arr[e] < arr[s]){
                cnt += (mid+1-s);
                v.push_back(arr[e++]);
            }
            else v.push_back(arr[s++]);
        }
        while(s <= mid) v.push_back(arr[s++]);
        while(e <= r)   v.push_back(arr[e++]);
        for(int i = l; i <= r; i++) arr[i] = v[i-l];
    }
    
    void mergeSort(vector<int>&arr, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        return cnt;
    }
};