#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MyStack{
    public:
    queue<int> a;

    void push(int x){
        int sz = a.size();
        a.push(x);
        while(sz--){
            a.push(a.front());
            a.pop();
        }
    }

    void pop(){
        if(!a.empty()) a.pop();
    }

    int top(){
        if(!a.empty()) return a.front();
        return -1;
    }

    int size(){
        return a.size();
    }
};

void solve(){
    MyStack *a = new MyStack();

    a->push(5);
    a->push(10);
    a->push(15);
    a->push(20);

    cout << a->top() << "\n";
    cout << a->size() << "\n";

    a->pop();
    a->pop();
    a->pop();

    cout << a->top() << "\n";
    cout << a->size() << "\n";

    a->pop();
    a->pop();
    a->pop();

    cout << a->top() << "\n";
    cout << a->size() << "\n";

    a->push(100);
    a->push(101);
    a->push(102);

    cout << a->top() << "\n";
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