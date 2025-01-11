#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* newHead(Node* head, int x){

    Node* newH = new Node(x);
    newH->next = head;
    return newH;
}

void solve(){
    // Node* head = new Node(5);
    // head->next = new Node(10);
    // head->next->next = new Node(15);
    // head->next->next->next = new Node(20);

    Node* head = NULL;
    int x = 100;
    head = newHead(head, x);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << "\n";
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}