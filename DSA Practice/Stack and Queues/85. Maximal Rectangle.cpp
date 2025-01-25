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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mx = 0;
        vector<int> pf(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') pf[j]++;
                else pf[j] = 0;
            }
            vector<int> pse =  findPse(pf, m);
            vector<int> nse = findNse(pf, m);

            for(int j = 0; j < m; j++){
                mx = max(mx, (nse[j] - pse[j] + 1) * pf[j]);
            }
        }
        return mx;
    }
};