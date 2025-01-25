class Solution {
private:
    vector<int> findPse(vector<int>& h, int n){
        vector<int> v(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] >= h[i])   st.pop();
            if(!st.empty())  v[i] = st.top() + 1;
            st.push(i);
        }
        return v;
    }
    vector<int> findNse(vector<int>& h, int n){
        vector<int> v(n, n-1);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && h[st.top()] >= h[i])   st.pop();
            if(!st.empty())  v[i] = st.top() - 1;
            st.push(i);
        }
        return v;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse =  findPse(heights, n);
        vector<int> nse = findNse(heights, n);

        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, (nse[i] - pse[i] + 1) * heights[i]);
        }
        return mx;
    }
};