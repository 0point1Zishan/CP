#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class Node{
    public:
    int val;
    Node* next = NULL;

    Node(int x){
        this->val = x;
        this->next = NULL;
    }
};

class MyStack{
    public:
    int sz = 0;
    Node *head = NULL;

    void push(int x){
        Node* a = new Node(x);
        a->next = head;
        head = a;
        sz++;
    }
    void pop(){
        if(head != NULL){
            Node *temp = head;
            head = head->next;
            delete temp;
            sz--;
        }
    }
    int top(){
        if(head != NULL) return head->val;
        else return -1;
    }
    int size(){ return sz;}
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