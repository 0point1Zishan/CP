void merge(vector<int>&arr, int l, int mid, int r){
    vector<int> v;
    int i = l, j = mid+1;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            v.push_back(arr[i++]);
        }
        else v.push_back(arr[j++]);
    }
    while(i <= mid) v.push_back(arr[i++]);
    while(j <= r)   v.push_back(arr[j++]);
    
    j = 0;
    for(int i = l; i <= r; i++) arr[i] = v[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    // code here
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}