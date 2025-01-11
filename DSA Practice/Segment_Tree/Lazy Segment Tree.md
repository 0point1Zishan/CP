# Segment Tree Lazy

### Code:
```cpp
const int N = 1e5 + 5;
int v[N], tr[4*N], lazy[4*N];

void push_(int n, int l, int r){
    if(lazy[n] == 0)  return;
    tr[n] += (1LL * (r - l + 1)) * lazy[n];
    if(r != l)   lazy[2*n] += lazy[n],     lazy[2*n+1] += lazy[n];
    lazy[n] = 0;
}

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

void update(int n, int l, int r, int i, int j, int num){

    push_(n, l, r);
    if(r < i || j < l) return;

    if(l >= i && r <= j){
        lazy[n] = num;
        push_(n, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(2*n, l, mid, i, j, num);
    update(2*n+1, mid+1, r, i, j, num);
    tr[n] = tr[2*n] + tr[2*n+1];
}

int sum(int n, int l, int r, int a, int b){
    push_(n, l, r);
    if(l > b || r < a) return 0;
    if(l >= a && r <= b) return tr[n];
    int mid = l + (r - l) / 2;
    return sum(2*n, l, mid, a, b) + sum(2*n+1, mid+1, r, a, b);
}
```