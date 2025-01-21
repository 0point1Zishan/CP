#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MyStack{
    public:
    int idx = -1;
    int arr[50000];

    void push(int x){
        if(idx < 50000-1){
            idx++;
            arr[idx] = x;
        }
    }
    int top(){
        if(idx == -1) return -1;
        return arr[idx];
    }
    void pop(){
        if(idx != -1) idx--;
    }
    int size(){
        return idx+1;
    }
};

void solve(){
    MyStack *a = new MyStack();
    a->push(5);
    a->push(10);
    a->push(15);
    a->push(20);

    cout << a->size() << "\n";
    cout << a->top() << "\n";

    a->pop();
    a->pop();
    a->pop();

    cout << a->top() << "\n";

    a->pop();
    cout << a->size() << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}