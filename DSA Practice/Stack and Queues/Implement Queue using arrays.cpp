#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MyQueue{
    public:
    int sz = 0;
    int front = 0;
    int rear = -1;
    int arr[50000];

    void push(int x){
        if(sz == 0) front = 0, rear = -1;
        rear = (rear + 1) % 50000;
        if(sz < 50000){
            arr[rear] = x;
            sz++;
        }
    }
    int top(){
        if(sz) return arr[front];
        return -1;
    }
    void pop(){
        if(sz){
            front = (front + 1) % 50000;
            sz--;
        }
    }
    int size(){
        return sz;
    }
};

void solve(){
    MyQueue *a = new MyQueue;
    a->push(5);     // 5
    a->push(10);    // 5 10
    a->push(15);    // 5 10 15
    a->push(20);    // 5 10 15 20

    cout << a->size() << "\n";      // 4
    cout << a->top() << "\n";       // 5

    a->pop();       // 10 15 20
    a->pop();       // 15 25

    cout << a->size() << "\n";      // 2
    cout << a->top() << "\n";       // 15

    a->pop();                   // 25
    a->pop();                   // 

    cout << a->size() << "\n";          // 0
    cout << a->top() << "\n";           // -1


    a->push(100);
    cout << a->size() << "\n";      // 1
    cout << a->top() << "\n";       // 100
}   

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}