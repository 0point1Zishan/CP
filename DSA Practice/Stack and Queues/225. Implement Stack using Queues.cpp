class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!q.empty()){
            int temp = q.front();
            q.pop();
            return temp;
        }
        return -1;
    }
    
    int top() {
        if(!q.empty()) return q.front();
        return -1;
    }
    
    bool empty() {
        return q.empty();
    }
};