int cnt = 0;
void merge(vector<int>&skill, int l, int mid, int r){
    vector<int>v;
    int s = l, e = mid+1;

    while(s <= mid && e <= r){
        if(skill[s] > (skill[e] * 2)){
            cnt += (mid + 1 - s);
            e++;
        }
        else s++;
    }

    s = l, e = mid+1;
    while(s <= mid && e <= r){
        if(skill[s] <= skill[e]){
            v.push_back(skill[s++]);
        }
        else v.push_back(skill[e++]);
    }
    while(s <= mid) v.push_back(skill[s++]);
    while(e <= r)   v.push_back(skill[e++]);

    for(int i = l; i <= r; i++) skill[i] = v[i-l];
}
void mergeSort(vector<int>&skill, int l, int r){
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(skill, l, mid);
    mergeSort(skill, mid+1, r);
    merge(skill, l, mid, r);
}

int team(vector <int> & skill, int n)
{
    // Write your code here.
    mergeSort(skill, 0, n-1);
    return cnt;
}