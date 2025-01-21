class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
    }
    
    void push(int val) {
        long long x = val;
        if(st.empty()){
            mn = x;
            st.push(mn);
        }
        else{
            if(x < mn){
                st.push(2 * x * 1LL - mn);
                mn = x;
            }
            else st.push(x);
        }
    }
    
    void pop() {
        long long popVal = st.top();
        st.pop();
        if(popVal < mn) mn = 2*mn - popVal;
    }
    
    int top() {
        if(st.top() < mn) return mn;
        return st.top();
    }
    
    int getMin() {
        return mn;
    }
};