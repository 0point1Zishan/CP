class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int t = s2.top();
            s2.pop();
            return t;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
                int t = s2.top();
                s2.pop();
                return t;
            }
            else return -1;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
                return s2.top();
            }
            else return -1;
        }
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};