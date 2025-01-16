class Solution{
public:
    void insertAtBottom(stack<int>& St, int ele){
        if(St.empty()){
            St.push(ele);
            return;
        }
        int x = St.top();
        St.pop();
        insertAtBottom(St, ele);
        St.push(x);
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        
        int x = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, x);
    }
};