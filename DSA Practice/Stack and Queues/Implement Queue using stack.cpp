#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MyQueue2{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(!s2.empty()) s2.pop();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
                s2.pop();
            }
        }
    }
    int top(){
        if(!s2.empty()) return s2.top();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()) return s2.top();
            else return -1;
        }
    }
    int size(){ 
        return s1.size() + s2.size();
    }
};

class MyQueue{
    public:
    stack<int> st;
    stack<int> temp;
    void push(int x){
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    void pop(){
        if(st.size()) st.pop();
    }
    int top(){
        if(st.size()) return st.top();
        return -1;
    }
    int size(){
        return st.size();
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
    a->pop();       // 15 20

    cout << a->size() << "\n";      // 2
    cout << a->top() << "\n";       // 15

    a->pop();                   // 20
    a->pop();                   // 

    cout << a->size() << "\n";          // 0
    cout << a->top() << "\n";           // -1


    a->push(100);
    a->push(101);
    a->push(102);
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