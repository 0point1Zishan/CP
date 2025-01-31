#include <bits/stdc++.h> 
void heapfy(vector<int> &v, int i){
    int idx = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if(l < v.size() && v[l] < v[idx]) idx = l;
    if(r < v.size() && v[r] < v[idx]) idx = r;

    if(i != idx){
        swap(v[i], v[idx]);
        heapfy(v, idx);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    for(int i = arr.size()/2 - 1; i >= 0; i--){
        heapfy(arr, i);
    }
    return arr;
}