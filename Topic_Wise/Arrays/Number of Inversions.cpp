int cnt = 0;
void merge(vector<int>&a, int l, int mid, int r){
    vector<int> v;
    int s = l, e = mid + 1;
    while(s <= mid && e <= r){
        if(a[e] < a[s]){
            cnt += (mid - s + 1);
            v.push_back(a[e++]);
        }
        else v.push_back(a[s++]);
    }
    while(s <= mid) v.push_back(a[s++]);
    while(e <= r)   v.push_back(a[e++]);

    for(int i = 0; i < v.size(); i++)   a[l++] = v[i];
    
}

void mergeSort(vector<int>&a, int l, int r){
    if(l >= r) return;
    long long mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    merge(a, l, mid, r);
    
}
int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    mergeSort(a, 0, n-1);
    return cnt;
}