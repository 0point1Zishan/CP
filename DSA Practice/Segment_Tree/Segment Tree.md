# Segment Tree

### code:
```cpp
void build(int n, int l, int r){
    if(l == r){
        tr[n] = v[l];
        return; 
    }
    int mid = l + (r - l) / 2;
    build(2*n, l, mid);
    build(2*n+1, mid+1, r);
    tr[n] = tr[2*n] + tr[2*n+1];
}

void update(int n, int l, int r, int idx, int num){
    if(idx > r || idx < l) return;
    if(l == r){
        tr[n] = num;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2*n, l, mid, idx, num);
    update(2*n+1, mid+1, r, idx, num);
    tr[n] = tr[2*n] + tr[2*n+1];
}

int cnt(int n, int l, int r, int a, int b){
    if(l > b || r < a) return 0;
    if(l >= a && r <= b) return tr[n];
    int mid = l + (r - l) / 2;
    return cnt(2*n, l, mid, a, b) + cnt(2*n+1, mid+1, r, a, b);
}
```