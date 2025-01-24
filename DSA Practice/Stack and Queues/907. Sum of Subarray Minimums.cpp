class Solution {
private:
    vector<int> findNse(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            v[i] = (st.empty()  ?  n   :   st.top());
            st.push(i);
        }
        return v;
    }
    vector<int> findPsee(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            v[i] = (st.empty()  ?  -1   :   st.top());
            st.push(i);
        }
        return v;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNse(arr, n);
        vector<int> psee = findPsee(arr, n);

        int ans = 0, MOD = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            ans = (ans + ( (left * right * 1LL) % MOD * arr[i] * 1LL) % MOD ) % MOD;
        }
        return ans;
    }
};